#include "include.hpp"


bool aimbot::isvisible(vector& vecstart, vector& vecend, entities* plocal, entities* target)
{
	if (!plocal || !target)
		return false;

	raytrace r(vecstart, vecend);
	traceclass tr;
	tracefitlers skip = plocal;

	penginetrace->traceray(r,&skip,&tr);

	if (tr.fraction == 1.0f)
	{
		return true;
	}

	if (tr.entity && target)
	{
		if (tr.entity == target)
		{
			return true;
		}
	}

	return false;
}

bool aimbot::gethitboxpos(entities* plocal, entities* entitiy, vector &vpos)
{
	if (!plocal || !entitiy)
		return false;

	vpos = entitiy->getbonepos(gcvars.aimspot);

	if (vpos.iszero())
		return false;

	if (isvisible(veyepos, vpos, plocal, entitiy))
		return true;

	return false;
}

void aimbot::main(entities* plocal)
{
	if (gcvars.bmenu)
		return;

	if (!GetAsyncKeyState(gcvars.inattack))
		return;

	int imyteam = plocal->getteamnum();

	veyepos = plocal->geteyeposition();

	static vector vclientviewangles;
	pengine->getviewangles(vclientviewangles);

	static vector vangle;
	math::anglevectors(vclientviewangles,vangle);

	reset();

	for (int ax = 1; ax <= pengine->getmaxclients(); ax++)
	{
		entities* entity = pentlist->getcliententity(ax);

		if (!entity)
			continue;

		if (entity == plocal)
			continue;

		if (!entity->isalive())
			continue;

		if (entity->isdormant())
			continue;

		if (entity->getteamnum() == imyteam)
			continue;

		if (!gethitboxpos(plocal,entity, vtarget))
			continue;

		float fcurrfov = math::getfov(veyepos,vtarget,vangle);

		if(fcurrfov > (float)gcvars.aimfov)
			continue;

		fcurrfov = (vector(vtarget - veyepos).length());

		if(fbesttarget < fcurrfov)
			continue;

		fbesttarget = fcurrfov;

		vfinal = vtarget;

		itarget = ax;
	}

	if(hastarget())
	{
		math::calcangle(veyepos,vfinal, viewangel);

		if (gcvars.aimsmooth > 0)
		{
			vclientviewangles.x = math::anglenormalize(vclientviewangles.x);
			vclientviewangles.y = math::anglenormalize(vclientviewangles.y);

			vector qdelta = viewangel - vclientviewangles;

			qdelta.x = math::anglenormalize(qdelta.x);
			qdelta.y = math::anglenormalize(qdelta.y);

			viewangel.x = vclientviewangles.x + qdelta.x / (float)gcvars.aimsmooth;
			viewangel.y = vclientviewangles.y + qdelta.y / (float)gcvars.aimsmooth;

			viewangel.x = math::anglenormalize(viewangel.x);
			viewangel.y = math::anglenormalize(viewangel.y);
		}

		math::clampangles(viewangel);

		pengine->setviewangles(viewangel);
	}
}


void aimbot::main_rcs(entities* plocal)
{
	if (gcvars.bmenu)
		return;

	if (!GetAsyncKeyState(gcvars.inattack))
		return;

	int imyteam = plocal->getteamnum();

	veyepos = plocal->geteyeposition();

	static vector vclientviewangles;
	pengine->getviewangles(vclientviewangles);

	static vector vangle;
	math::anglevectors(vclientviewangles, vangle);

	resetrcs();

	for (int ax = 1; ax <= pengine->getmaxclients(); ax++)
	{
		entities* entity = pentlist->getcliententity(ax);

		if (!entity)
			continue;

		if (entity == plocal)
			continue;

		if (!entity->isalive())
			continue;

		if (entity->isdormant())
			continue;

		if (entity->getteamnum() == imyteam)
			continue;

		if (!gethitboxpos(plocal,entity, vrcstarget))
			continue;

		float fcurrfov = math::getfov(veyepos, vrcstarget, vangle);

		if (fbestrcstarget < fcurrfov)
			continue;

		fbestrcstarget = fcurrfov;

		vrcsfinal = vrcstarget;

		ircstarget = ax;
	}

	if (hastargetrcs())
	{
		float flen = vector(vrcsfinal - veyepos).length();

		vector qangle;

		math::calcangle(veyepos, vrcsfinal, qangle);

		vector qpunchangle = plocal->getaimpunchangle();

		qangle.x -= qpunchangle.x * 2;
		qangle.y -= qpunchangle.y * 2;

		qangle.x = math::anglenormalize(qangle.x);
		qangle.y = math::anglenormalize(qangle.y);

		static vector vforward;
		math::anglevectors(qangle, vforward);

		vforward = (vforward * flen) + veyepos;

		if (math::getfov(veyepos, vforward, vangle) <= (float)gcvars.rcsfov)
		{
			viewangel = qangle;

			if (gcvars.rcssmooth > 0)
			{
				vclientviewangles.x = math::anglenormalize(vclientviewangles.x);
				vclientviewangles.y = math::anglenormalize(vclientviewangles.y);

				vector qdelta = viewangel - vclientviewangles;

				qdelta.x = math::anglenormalize(qdelta.x);
				qdelta.y = math::anglenormalize(qdelta.y);

				viewangel.x = vclientviewangles.x + qdelta.x / (float)gcvars.rcssmooth;
				viewangel.y = vclientviewangles.y + qdelta.y / (float)gcvars.rcssmooth;

				viewangel.x = math::anglenormalize(viewangel.x);
				viewangel.y = math::anglenormalize(viewangel.y);
			}

			viewangel.z = 0.0f;

			math::clampangles(viewangel);

			pengine->setviewangles(viewangel);
		}
	}
}
