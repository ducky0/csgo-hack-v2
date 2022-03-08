


void skinchanger(entities* plocal)
{
	UINT* hweapons = plocal->getweapons();

	if (!hweapons)
		return;

	entities* pweaponactive = (entities*)pentlist->getcliententityfromhandle(plocal->getactiveweapon());

	if (!pweaponactive)
		return;

	int activeweaponid = *pweaponactive->getitemdefinitionindex();

	if (activeweaponid == 0)
		return;

	for (size_t i = 0; hweapons[i] != 0xffffffff; i++)
	{
		entities* pweapon = (entities*)pentlist->getcliententity(hweapons[i] & 0xfff);

		if (!pweapon)
			continue;

		int weapon = *pweapon->getitemdefinitionindex();

		if (gcvars.w[weapon].skiner != 0)
		{
			*pweapon->fallbackpaintkit() = gcvars.w[weapon].skiner;
		}

		if (gcvars.knife == 1)
		{
			if (isweaponknife(weapon))
			{
				*pweapon->modelindex() = pmodel->getmodelindex("models/weapons/v_knife_bayonet.mdl");
				*pweapon->getitemdefinitionindex() = weapon_bayonet;
				*pweapon->fallbackpaintkit() = gcvars.knifeskin;

				if (isweaponknife(activeweaponid))
				{
					entities *viewmodel = (entities *)pentlist->getcliententityfromhandle(plocal->getviewmodel());

					if (viewmodel && viewmodel != nullptr)
					{
						((entities*)viewmodel)->setmodelindex(pmodel->getmodelindex("models/weapons/v_knife_bayonet.mdl"));
					}
				}
			}
		}
		else if (gcvars.knife == 2)
		{
			if (isweaponknife(weapon))
			{
				*pweapon->modelindex() = pmodel->getmodelindex("models/weapons/v_knife_flip.mdl");
				*pweapon->getitemdefinitionindex() = weapon_knife_flip;
				*pweapon->fallbackpaintkit() = gcvars.knifeskin;

				if (isweaponknife(activeweaponid))
				{
					entities *viewmodel = (entities *)pentlist->getcliententityfromhandle(plocal->getviewmodel());

					if (viewmodel && viewmodel != nullptr)
					{
						((entities*)viewmodel)->setmodelindex(pmodel->getmodelindex("models/weapons/v_knife_flip.mdl"));
					}
				}
			}

		}
		else if (gcvars.knife == 3)
		{
			if (isweaponknife(weapon))
			{
				*pweapon->modelindex() = pmodel->getmodelindex("models/weapons/v_knife_gut.mdl");
				*pweapon->getitemdefinitionindex() = weapon_knife_gut;
				*pweapon->fallbackpaintkit() = gcvars.knifeskin;

				if (isweaponknife(activeweaponid))
				{
					entities *viewmodel = (entities *)pentlist->getcliententityfromhandle(plocal->getviewmodel());

					if (viewmodel && viewmodel != nullptr)
					{
						((entities*)viewmodel)->setmodelindex(pmodel->getmodelindex("models/weapons/v_knife_gut.mdl"));
					}
				}
			}
		}
		else if (gcvars.knife == 4)
		{
			if (isweaponknife(weapon))
			{
				*pweapon->modelindex() = pmodel->getmodelindex("models/weapons/v_knife_karam.mdl");
				*pweapon->getitemdefinitionindex() = weapon_knife_karambit;
				*pweapon->fallbackpaintkit() = gcvars.knifeskin;

				if (isweaponknife(activeweaponid))
				{
					entities *viewmodel = (entities *)pentlist->getcliententityfromhandle(plocal->getviewmodel());

					if (viewmodel && viewmodel != nullptr)
					{
						((entities*)viewmodel)->setmodelindex(pmodel->getmodelindex("models/weapons/v_knife_karam.mdl"));
					}
				}
			}
		}
		else if (gcvars.knife == 5)
		{
			if (isweaponknife(weapon))
			{
				*pweapon->modelindex() = pmodel->getmodelindex("models/weapons/v_knife_m9_bay.mdl");
				*pweapon->getitemdefinitionindex() = weapon_knife_m9bayonet;
				*pweapon->fallbackpaintkit() = gcvars.knifeskin;

				if (isweaponknife(activeweaponid))
				{
					entities *viewmodel = (entities *)pentlist->getcliententityfromhandle(plocal->getviewmodel());

					if (viewmodel && viewmodel != nullptr)
					{
						((entities*)viewmodel)->setmodelindex(pmodel->getmodelindex("models/weapons/v_knife_m9_bay.mdl"));
					}
				}
			}
		}

		*pweapon->itemidhigh() = -1;
	}
}
