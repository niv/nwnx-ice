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
	confKey = strdup("ICE");
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

	Ice::PropertiesPtr props = Ice::createProperties();
	props->setProperty("Ice.ThreadPool.Client.Size", (*nwnxConfig)[confKey]["threadPoolClientSize"].c_str());
	props->setProperty("Ice.ThreadPool.Client.SizeMax", (*nwnxConfig)[confKey]["threadPoolClientSizeMax"].c_str());
	props->setProperty("Ice.ThreadPool.Server.Size", (*nwnxConfig)[confKey]["threadPoolServerSize"].c_str());
	props->setProperty("Ice.ThreadPool.Server.SizeMax", (*nwnxConfig)[confKey]["threadPoolServerSizeMax"].c_str());
	Ice::InitializationData initData;
	const char* charset = (*nwnxConfig)[confKey]["charset"].c_str();
	initData.stringConverter = new Ice::IconvStringConverter<char>(charset);
	initData.properties = props;
	ic = Ice::initialize(initData);

	while (true) {
		// Set up the client
		try {
			Ice::ObjectPrx base = ic->stringToProxy( (*nwnxConfig)[confKey]["client"].c_str() );
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
		adapter =
			ic->createObjectAdapterWithEndpoints(
				"NWScriptAdapter", (*nwnxConfig)[confKey]["server"].c_str() );
		
		nwscriptI = new NWScriptI;
		Ice::ObjectPtr object = nwscriptI;

		nwscript_proxy = NWN::NWScriptPrx::checkedCast(
			adapter->add(object, ic->stringToIdentity("NWScript"))
		);
		adapter->activate();

	} catch (const Ice::Exception &e) {
		cerr << e << endl;
		throw;
	}

	nwscriptI->printEvents = atoi((*nwnxConfig)[confKey]["printEvents"].c_str()) == 1 ? true : false;

    return true;
}

char* CNWNXICE::OnRequest (char *gameObject, char* request, char* parameters)
{
	Log(0, "(S) Request: \"%s\"\n", request);
	Log(0, "(S) Params:  \"%s\"\n", parameters);

	int ret = NWN::Continue;

	timeval t1; gettimeofday(&t1, NULL);


	char* oid_c = strtok(parameters, " ");
	char* event  = strtok(NULL, " ");

	if (NULL == event) {
		printf("Usage error, need format: ObjectToString(OBJECT_SELF) event_name\n");
		sprintf(parameters, "%d", NWN::Error);
		return NULL;
	}

	dword oid = strtol(oid_c, 0, 16);
	NWN::NWObject nwobj_self;
	nwobj_self.id = oid;

	unsigned long previousCallCounter = nwscriptI->callCounter;

	/* // comment this in to see pre-call printfs - helps debugging somewhat
	if (strcmp(request, "EVENT") == 0)
		printf("e %0.8x %-20s ..\n", oid, event);
	if (strcmp(request, "TOKEN") == 0)
		printf("t %0.8x %-20s ..\n", oid, event);
	*/

	nwscriptI->contextDepth += 1;

	std::string lastException = "";
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
			if (e.ice_name() != lastException) {
				cerr << e << endl;
				printf("%8x %s: will retry (quietly) in 2s intervals (%d calls so far).\n", oid, event, (nwscriptI->callCounter - previousCallCounter));
				lastException = e.ice_name();
			}
			IceUtil::ThreadControl::sleep(IceUtil::Time::seconds(2));
		} catch (...) {
			exit(1);
		}
	}
	if (lastException != "") {
		printf(".. it's back, continuing.\n");
		lastException = "";
	}

	nwscriptI->contextDepth -= 1;

	unsigned long calls = nwscriptI->callCounter - previousCallCounter;
	nwscriptI->callCounter = previousCallCounter;

	timeval t2; gettimeofday(&t2, NULL);
	long usec = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
	long se = usec / 1000000;
	long ms = usec % 1000000;

	if (nwscriptI->contextDepth == 0)
		nwscriptI->resetPerEventMappings();

	if (nwscriptI->printEvents) {
		if (strcmp(request, "EVENT") == 0)
			printf("e %0.8x %-20s %6d s %8d u %12d calls\n", oid, event, se, ms, calls);
		if (strcmp(request, "TOKEN") == 0)
			printf("t %0.8x %-20s %6d s %8d u %12d calls\n", oid, event, se, ms, calls);
	}

	sprintf(parameters, "%d", ret);
	return NULL;
}
