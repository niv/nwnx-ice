CXX = g++
LIBS = -lIce -lIceUtil -I.
LFLAGS = -w -fPIC -shared -W -Wall
DEFS = -DHAVE_CONFIG_H
INC = -I.

# TODO: snarf from configure somehow
# the user should be able to specify NWNXDIR
# if NWNXDIR is not specified, configure should
# probe (.. ../linnwnx2) and die if not found.
# NWNXDIR = @NWNXDIR@
NWNXDIR = ../..

# CFLAGS = -mtune=i386 -pipe -g -O2 -I$(NWNXDIR)
# CXXFLAGS= -g -O2 $(CFLAGS)
CPPFLAGS = -pipe -DPGSQL_SUPPORT=1 -DNWNX_EVENTS_ELVEN=1 -DLOCK_DISABLE -I$(NWNXDIR) $(INC)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o

all: NWScriptI.h NWScriptI.cpp NWScript.h NWScript.cpp Client.h Client.cpp nwnx_ice.so client

NWScript.cpp: NWScript.ice
	slice2cpp -I. -I/usr/share/slice NWScript.ice

NWScript.h: NWScript.ice
	slice2cpp -I. -I/usr/share/slice NWScript.ice

Client.cpp: Client.ice
	slice2cpp -I. -I/usr/share/slice Client.ice

Client.h: Client.ice
	slice2cpp -I. -I/usr/share/slice Client.ice

nwnx_ice.so: FunctionHooks.o NWNXICE.o NWScript.o NWScriptI.o NWScriptIState.o Client.o plugin-ice.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS) $(DEFS)

.PHONY: client
client: NWScript.ice Client.ice
	slice2java --checksum NWN.NWScriptChk --tie -I. -I/usr/share/slice --output-dir java/ NWScript.ice Client.ice

.PHONY: doc
doc:
	slice2html -I. -I/usr/share/slice --output-dir doc/ NWScript.ice Client.ice

clean:
	/bin/rm -f *.o *.so *~ plugin-t NWScript.h NWScript.cpp Client.h Client.cpp

distclean: clean
	/bin/rm -f Makefile
