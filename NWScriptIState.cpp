#include "NWScriptI.h"

bool NWScriptI::hasState(const std::string& key, const Ice::Current&) {
	std::map<const std::string, NWN::Persistable>::iterator iter = persistMap.find(key);
	return iter != persistMap.end();
};

NWN::Persistable NWScriptI::getState(const std::string& key, const Ice::Current& ice) {
	std::map<const std::string, NWN::Persistable>::iterator iter = persistMap.find(key);
	if (iter == persistMap.end())
		throw NWN::StateNotAvailableException();

	return persistMap[key];
};

void NWScriptI::putState(const std::string& key, const NWN::Persistable& p, const Ice::Current& ice) {
	persistMap[key] = p;
};

void NWScriptI::delState(const std::string& key, const Ice::Current& ice) {
	persistMap.erase(key);
};

void NWScriptI::clearState(const Ice::Current& ice) {
	persistMap.clear();
};
