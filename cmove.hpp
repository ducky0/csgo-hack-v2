

inline void dostuff(entities* plocal)
{
	if (!plocal)
		return;

	if (!plocal->isalive())
		return;

	entities* pweapon = (entities*)pentlist->getcliententityfromhandle(plocal->getactiveweapon());

	if (!pweapon)
		return;

	g_weaponid = *pweapon->getitemdefinitionindex();

	if (gcvars.inattack == VK_ESCAPE)
		return;

	if (!pweapon->hasammo())
		return;

	if (pweapon->isreloading())
		return;

	if (!isaimwep(g_weaponid) && !isrecoilwep(g_weaponid))
		return;

	if (!gcvars.rcsassist)
	{
		g_aimbot.main(plocal);
	}

	if (gcvars.rcsassist)
	{
		if (isrecoilwep(g_weaponid))
		{
			g_aimbot.main_rcs(plocal);
		}

		if (isaimwep(g_weaponid))
		{
			g_aimbot.main(plocal);
		}
	}
}