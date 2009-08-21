/***************************************************************************
    NWNXICE.h - Interface for the CNWNXICE class.
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

#ifndef NWNXICE_h_
#define NWNXICE_h_

#include "NWNXBase.h"
#include "typedefs.h"
#include "NWNStructures.h"
#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <Ice/IconvStringConverter.h>
#include "Client.h"
#include "NWScriptI.h"

class CNWNXICE : public CNWNXBase
{
public:
	CNWNXICE();
	virtual ~CNWNXICE();

	bool OnCreate(gline *nwnxConfig, const char *LogDir=NULL);
	char* OnRequest (char* gameObject, char* Request, char* Parameters);
//	unsigned long OnRequestObject (char *gameObject, char* Request);
	void ExecuteCommand(char *value);

	bool bHooked;
	int nError;

private:
	Ice::CommunicatorPtr ic;
	Ice::ObjectAdapterPtr adapter;

	NWN::ClientPrx prx_client;

	NWN::NWScriptPrx  nwscript_proxy;

	NWScriptI* nwscriptI;

};

#endif
