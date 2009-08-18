/***************************************************************************
    NWNXICE.cpp - Implementation of the CNWNXICE class.
    (c) 2008 virusman (virusman@virusman.ru)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <signal.h>

#include "NWNXICE.h"
#include "FunctionHooks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXICE::CNWNXICE()
{
	confKey = "ICE";
	bHooked = 1;
}

CNWNXICE::~CNWNXICE()
{
}


bool CNWNXICE::OnCreate(gline *config, const char *LogDir)
{
	char log[128];
	struct stat statbuf;
	int i = 0;
	sprintf (log, "%s/nwnx_ice.txt", LogDir);

	// call the base class function
	if (!CNWNXBase::OnCreate(config,log))
		return false;

	Log(0,"NWNX ICE\n");

	if (HookFunctions())
	{
		bHooked=1;
		Log(0,"* Module loaded successfully.\n");
	}
	else
	{
		bHooked=0;
		Log(0,"* Module loaded successfully.\n");
		Log(0,"* Signature recognition failed. Some functions will be disabled.\n");
		return false;
	}

	// mutex.lock();

	while (true) {
		// Set up the client
		try {

			Ice::InitializationData initData;
			initData.stringConverter = new Ice::IconvStringConverter<char>("WINDOWS-1250");
			icClient = Ice::initialize(initData);


			Ice::ObjectPrx base = icClient->stringToProxy( "Client:default -p 5223" /*  (*nwnxConfig)[confKey]["client"].c_str() */ );
			if (!base)
				throw "Could not create proxy.";

			prx_client = NWN::ClientPrx::checkedCast(base);
			if (!prx_client)
				throw "Invalid proxy.";

			break;

		} catch (const Ice::ConnectFailedException &e) {
			cerr << e << endl;
			IceUtil::ThreadControl::sleep(IceUtil::Time::seconds(2));

		} catch (const Ice::Exception &ee) {
			cerr << ee << endl;
			exit(1);

		} catch (const char* msg) {
			cerr << msg << endl;
			exit(1);
		}
	}

	// Set up the server ..
	try {
		Ice::InitializationData initData;
		initData.stringConverter = new Ice::IconvStringConverter<char>("WINDOWS-1250");
		icServer = Ice::initialize(initData);
		adapter =
			icServer->createObjectAdapterWithEndpoints(
				"NWScriptAdapter", "default -p 5222" /* (*nwnxConfig)[confKey]["server"].c_str() */ );
		
		nwscriptI = new NWScriptI;
		Ice::ObjectPtr object = nwscriptI;
		// nwscriptI->lock("first lock");

		nwscript_proxy = NWN::NWScriptPrx::checkedCast(
			adapter->add(object, icServer->stringToIdentity("NWScript"))
		);
		adapter->activate();

	} catch (const Ice::Exception &e) {
		cerr << e << endl;
		throw;
	}

    return true;
}

char* CNWNXICE::OnRequest (char *gameObject, char* request, char* parameters)
{
	Log(0, "(S) Request: \"%s\"\n", request);
	Log(0, "(S) Params:  \"%s\"\n", parameters);

	bool ret;

	timeval t1; gettimeofday(&t1, NULL);


	char* oid_c = strtok(parameters, " ");
	char* event  = strtok(NULL, " ");

	if (NULL == event) {
		printf("Usage error, need format: ObjectToString(OBJECT_SELF) event_name");
		return false;
	}

	dword oid = strtol(oid_c, 0, 16);
	NWN::NWObject nwobj_self;
	nwobj_self.id = oid;

	nwscriptI->inContext = true;
	// nwscriptI->unlock(request);
	while (true) {
		try {
			if (strcmp(request, "EVENT") == 0)
				ret = prx_client->event(nwscript_proxy, nwobj_self, event);
			if (strcmp(request, "TOKEN") == 0)
				prx_client->token(nwscript_proxy, nwobj_self, event);
			break;

		} catch (const Ice::CommunicatorDestroyedException&) {
			throw;

		} catch (const Ice::LocalException& e) {
			printf("%8x %s: Connection lost, retrying in 2.\n", oid, event);
			cerr << e << endl;
			IceUtil::ThreadControl::sleep(IceUtil::Time::seconds(2));
		}
	}
	// nwscriptI->lock(request);
	nwscriptI->inContext = false;

	unsigned long calls = nwscriptI->callCounter;
	nwscriptI->callCounter = 0;

	timeval t2; gettimeofday(&t2, NULL);
	long usec = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
	long se = usec / 1000000;
	long ms = usec % 1000000;
	if (strcmp(request, "EVENT") == 0)
		printf("e %0.8x %-20s %6d s %8d u %12d calls\n", oid, event, se, ms, calls);
	if (strcmp(request, "TOKEN") == 0)
		printf("t %0.8x %-20s %6d s %8d u %12d calls\n", oid, event, se, ms, calls);

	nwscriptI->resetPerEventMappings();

	// do something with ret.

	return NULL;
}
