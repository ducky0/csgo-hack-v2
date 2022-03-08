

inline void runglow(entities* local)
{
	if (!gcvars.glowers)
		return;

	if (pglowobj && local)
	{
		for (int i = 0; i < pglowobj->glowobjectdefinitions.size; i++)
		{
			glowdefinition& glowobject = pglowobj->glowobjectdefinitions[i];

			auto entity = glowobject.entity;

			if (glowobject.isunused())
				continue;

			if (!entity)
				continue;

			if (entity->isdormant())
				continue;

			if (!entity->getclientclass())
				continue;

			if (entity->getclientclass()->getclassid == classid.ccsplayer)
			{
				if (!gcvars.chamteam && entity->getteamnum() == local->getteamnum())
					continue;

				glowobject.renderwhenoccluded = true;

				glowobject.glowalpha = 1.f;
				glowobject.glowstyle = 1;
				glowobject.glowalphamax = 0.9f;

				glowobject.glowcolor = 
				{ 
				   ((float)gcvars.colorsredfour) / 255,
				   ((float)gcvars.colorsgreenfour) / 255,
				   ((float)gcvars.colorsbluefour) / 255
				};
			}
		}
	}
}