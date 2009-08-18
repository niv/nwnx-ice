
#include <Ice/Identity.ice>
#include <NWScript.ice>

module NWN {

  enum ClientResult { Stop, Suppress, Continue, Error };

  interface Client {
    ClientResult event(NWScript* proxy, NWObject self, string evt);
    idempotent void token(NWScript* proxy, NWObject self, string tok);
  };
};
