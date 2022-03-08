

#include "include.hpp"

#include "allocmemory.hpp"
#include "framestage.hpp"
#include "paintraverse.hpp"

bool __stdcall DllMain(void*, bool r, void*)
{
	if (r)
	{
		initialiseinterfaces();

		auto k_target = reinterpret_cast<void*>(steam_hooker::setuphook(pkeyvalues, 1));
		steam_hooker::hookfunc(k_target, hkallocmemory, &org_allocmemory);

		classid.initialize();
		offsets::getoffsets();

		auto p_target = reinterpret_cast<void*>(steam_hooker::setuphook(ppanel, 41));
		steam_hooker::hookfunc(p_target, hkpainttraverse, &org_paintraverse);

		auto f_target = reinterpret_cast<void*>(steam_hooker::setuphook(pclient, 37));
		steam_hooker::hookfunc(f_target, hkframestage, &org_framestage);
	}

	return true;
}

