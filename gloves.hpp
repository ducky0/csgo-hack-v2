
void glovechanger(entities* plocal)
{
	UINT* pwareables = plocal->getwearables();

	if (!pwareables)
		return;

	plocal->setmodelindex(pmodel->getmodelindex("models/player/custom_player/legacy/tm_jungle_raider_variante.mdl"));

	if (!pentlist->getcliententityfromhandle((void*)pwareables[0]))
	{
		for (clientclass* pclass = pclient->getallclasses(); pclass; pclass = pclass->nextclass)
		{
			if (pclass->getclassid == classid.ceconwearable)
			{
				int ientry = pentlist->gethighestentityindex() + 1;
				int iserial = rand() % 0x1000;

				if (pclass->m_pcreatefn(ientry, iserial))
				{
					pwareables[0] = ientry | (iserial << 16);
					break;
				}
			}
		}

		if (!pwareables[0])
			return;

		entities* glove = (entities*)pentlist->getcliententityfromhandle((void*)pwareables[0]);

		if (!glove)
			return;

		if (gcvars.gloves == 0)
		{
			if (*glove->getitemdefinitionindex() != glove_studded_bloodhound || *glove->fallbackpaintkit() != gcvars.glovekit1)
			{
				glove->setmodelindex(pmodel->getmodelindex("models/weapons/v_models/arms/glove_bloodhound/v_glove_bloodhound.mdl"));
				*glove->getitemdefinitionindex() = glove_studded_bloodhound;
				*glove->fallbackpaintkit() = gcvars.glovekit1;
				*glove->itemidhigh() = -1;
				glove->predataupdate(0);
			}
		}
		if (gcvars.gloves == 1)
		{
			if (*glove->getitemdefinitionindex() != glove_sporty || *glove->fallbackpaintkit() != gcvars.glovekit2)
			{
				glove->setmodelindex(pmodel->getmodelindex("models/weapons/v_models/arms/glove_sporty/v_glove_sporty.mdl"));
				*glove->getitemdefinitionindex() = glove_sporty;
				*glove->fallbackpaintkit() = gcvars.glovekit2;
				*glove->itemidhigh() = -1;
				glove->predataupdate(0);
			}
		}
		if (gcvars.gloves == 2)
		{
			if (*glove->getitemdefinitionindex() != glove_slick || *glove->fallbackpaintkit() != gcvars.glovekit3)
			{
				glove->setmodelindex(pmodel->getmodelindex("models/weapons/v_models/arms/glove_slick/v_glove_slick.mdl"));
				*glove->getitemdefinitionindex() = glove_slick;
				*glove->fallbackpaintkit() = gcvars.glovekit3;
				*glove->itemidhigh() = -1;
				glove->predataupdate(0);
			}
		}
		if (gcvars.gloves == 3)
		{
			if (*glove->getitemdefinitionindex() != glove_leather_wrap || *glove->fallbackpaintkit() != gcvars.glovekit4)
			{
				glove->setmodelindex(pmodel->getmodelindex("models/weapons/v_models/arms/glove_handwrap_leathery/v_glove_handwrap_leathery.mdl"));
				*glove->getitemdefinitionindex() = glove_leather_wrap;
				*glove->fallbackpaintkit() = gcvars.glovekit4;
				*glove->itemidhigh() = -1;
				glove->predataupdate(0);
			}
		}
		if (gcvars.gloves == 4)
		{
			if (*glove->getitemdefinitionindex() != glove_motorcycle || *glove->fallbackpaintkit() != gcvars.glovekit5)
			{
				glove->setmodelindex(pmodel->getmodelindex("models/weapons/v_models/arms/glove_motorcycle/v_glove_motorcycle.mdl"));
				*glove->getitemdefinitionindex() = glove_motorcycle;
				*glove->fallbackpaintkit() = gcvars.glovekit5;
				*glove->itemidhigh() = -1;
				glove->predataupdate(0);
			}
		}
		if (gcvars.gloves == 5)
		{
			if (*glove->getitemdefinitionindex() != glove_specialist || *glove->fallbackpaintkit() != gcvars.glovekit6)
			{
				glove->setmodelindex(pmodel->getmodelindex("models/weapons/v_models/arms/glove_specialist/v_glove_specialist.mdl"));
				*glove->getitemdefinitionindex() = glove_specialist;
				*glove->fallbackpaintkit() = gcvars.glovekit6;
				*glove->itemidhigh() = -1;
				glove->predataupdate(0);
			}
		}
	}
}
