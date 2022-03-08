
#include "skins.hpp"
#include "gloves.hpp"

void shitchanger()
{
	entities *local = pentlist->getcliententity(pengine->getlocalplayer());

	if (!local)
		return;

	if (!local->isalive())
		return;

	if (local->iscontrollingbot())
		return;

	if (!gcvars.skinchanger)
		return;

	glovechanger(local);
	skinchanger(local);
}

typedef void(__fastcall *framestagefn)(void*, void*, int);
framestagefn org_framestage;

void __fastcall hkframestage(void* ecx, void* edx, int stage)
{
	org_framestage(ecx, edx, stage);

	if (stage == 2)
	{
		shitchanger();
	}
}