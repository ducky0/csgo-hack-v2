

struct cglobalvariables
{
	bool    bmenu = false;
	int 	rcsassist = 1;
	int 	aimfov = 1;
	int 	aimspot = 8;
	int 	inattack = VK_ESCAPE;
	int     gloves = 5;
	int     knife = 4;
	int 	knifeskin = 12;
	int 	skinchanger;
	int 	espbox;
	int 	healthbar;
	int     glovekit1 = 10008;
	int 	glovekit2 = 10038;
	int 	glovekit3 = 10044;
	int 	glovekit4 = 10009;
	int 	glovekit5 = 10027;
	int 	glovekit6 = 10035;
	int     rcsfov = 3;
	int     rcssmooth = 12;
	int 	colorsredtwo = 255;
	int 	colorsgreentwo = 255;
	int 	colorsbluetwo = 255;
	int 	colorsredfour = 159;
	int 	colorsgreenfour = 255;
	int     colorsbluefour = 0;
	int 	colorsredfive = 0;
	int     colorsgreenfive = 164;
	int 	colorsbluefive = 255;
	int 	chamteam = 0;
	int     fullupdate;
	int 	gayvaluete;
	int 	placeholder = 420;
	int 	aimsmooth = 15;
	int 	aimtab = 0;
	int 	visualtab = 0;
	int 	skintab = 0;
	int 	coltab = 0;
	int 	savebutt = 0;
	int 	loadbutt = 0;
	int 	chamers = 0;
	int 	glowers = 0;
	int 	tabnum = 0;

	struct
	{
		int skiner = 0;
	} w[weapon_revolver];
};

inline  cglobalvariables gcvars;

namespace cfgsystem
{
	inline void loadcfg()
	{
		auto path = pengine->getdirectory();

		std::string folder, file;

		char szcmd[256];
		sprintf(szcmd, "\\inso\\config.ini");

		folder = std::string(path) + "\\inso\\";
		file = std::string(path) + szcmd;

		CreateDirectoryA(folder.c_str(), 0);

		ciniwriter writer(file.c_str());

		gcvars.rcsassist = writer.readinteger("rcsassist");
		gcvars.aimfov = writer.readinteger("aimfov");
		gcvars.aimspot = writer.readinteger("aimspot");
		gcvars.inattack = writer.readinteger("inattack");
		gcvars.gloves = writer.readinteger("gloves");
		gcvars.knife = writer.readinteger("knifeye");
		gcvars.knifeskin = writer.readinteger("knifeskin");
		gcvars.skinchanger = writer.readinteger("skinchanger");
		gcvars.espbox = writer.readinteger("espbox");
		gcvars.healthbar = writer.readinteger("healthbar");
		gcvars.glovekit1 = writer.readinteger("glovekit1");
		gcvars.glovekit2 = writer.readinteger("glovekit2");
		gcvars.glovekit3 = writer.readinteger("glovekit3");
		gcvars.glovekit4 = writer.readinteger("glovekit4");
		gcvars.glovekit5 = writer.readinteger("glovekit5");
		gcvars.glovekit6 = writer.readinteger("glovekit6");
		gcvars.rcsfov = writer.readinteger("rcsfov");
		gcvars.rcssmooth = writer.readinteger("rcssmooth");
		gcvars.colorsredtwo = writer.readinteger("colorsredtwo");
		gcvars.colorsgreentwo = writer.readinteger("colorsgreentwo");
		gcvars.colorsbluetwo = writer.readinteger("colorsbluetwo");
		gcvars.colorsredfour = writer.readinteger("colorsredfour");
		gcvars.colorsgreenfour = writer.readinteger("colorsgreenfour");
		gcvars.colorsbluefour = writer.readinteger("colorsbluefour");
		gcvars.colorsredfive = writer.readinteger("colorsredfive");
		gcvars.colorsgreenfive = writer.readinteger("colorsgreenfive");
		gcvars.colorsbluefive = writer.readinteger("colorsbluefive");
		gcvars.chamteam = writer.readinteger("chamteam");
		gcvars.aimsmooth = writer.readinteger("aimsmooth");
		g_skinmenu.m_x = writer.readinteger("skinmenu.m_x");
		g_skinmenu.m_y = writer.readinteger("skinmenu.m_y");
		g_colormenu.m_x = writer.readinteger("colormenu.m_x");
		g_colormenu.m_y = writer.readinteger("colormenu.m_y");
		g_aimmenu.m_x = writer.readinteger("aimmenu.m_x");
		g_aimmenu.m_y = writer.readinteger("aimmenu.m_y");
		g_espmenu.m_x = writer.readinteger("espmenu.m_x");
		g_espmenu.m_y = writer.readinteger("espmenu.m_y");
		gcvars.aimtab = writer.readinteger("aimtab");
		gcvars.visualtab = writer.readinteger("visualtab");
		gcvars.skintab = writer.readinteger("skintab");
		gcvars.coltab = writer.readinteger("coltab");
		gcvars.chamers = writer.readinteger("chamers");
		gcvars.glowers = writer.readinteger("glowers");

		for (int weaponid = weapon_deagle; weaponid < weapon_revolver; weaponid++)
		{
			char* section = getweaponname(weaponid);

			if (strcmp(section, "") == 0)
				continue;

			gcvars.w[weaponid].skiner = writer.readinteger(section);
		}
	}

	inline void savecfg()
	{
		auto path = pengine->getdirectory();

		std::string folder, file;

		char szcmd[256];
		sprintf(szcmd, "\\inso\\config.ini");

		folder = std::string(path) + "\\inso\\";
		file = std::string(path) + szcmd;

		CreateDirectoryA(folder.c_str(), 0);

		ciniwriter writer(file.c_str());

		writer.writeinteger("rcsassist", gcvars.rcsassist);
		writer.writeinteger("aimfov", gcvars.aimfov);
		writer.writeinteger("aimspot", gcvars.aimspot);
		writer.writeinteger("inattack", gcvars.inattack);
		writer.writeinteger("gloves", gcvars.gloves);
		writer.writeinteger("knifeye", gcvars.knife);
		writer.writeinteger("knifeskin", gcvars.knifeskin);
		writer.writeinteger("skinchanger", gcvars.skinchanger);
		writer.writeinteger("espbox", gcvars.espbox);
		writer.writeinteger("healthbar", gcvars.healthbar);
		writer.writeinteger("glovekit1", gcvars.glovekit1);
		writer.writeinteger("glovekit2", gcvars.glovekit2);
		writer.writeinteger("glovekit3", gcvars.glovekit3);
		writer.writeinteger("glovekit4", gcvars.glovekit4);
		writer.writeinteger("glovekit5", gcvars.glovekit5);
		writer.writeinteger("glovekit6", gcvars.glovekit6);
		writer.writeinteger("rcsfov", gcvars.rcsfov);
		writer.writeinteger("rcssmooth", gcvars.rcssmooth);
		writer.writeinteger("colorsredtwo", gcvars.colorsredtwo);
		writer.writeinteger("colorsgreentwo", gcvars.colorsgreentwo);
		writer.writeinteger("colorsbluetwo", gcvars.colorsbluetwo);
		writer.writeinteger("colorsredfour", gcvars.colorsredfour);
		writer.writeinteger("colorsgreenfour", gcvars.colorsgreenfour);
		writer.writeinteger("colorsbluefour", gcvars.colorsbluefour);
		writer.writeinteger("colorsredfive", gcvars.colorsredfive);
		writer.writeinteger("colorsgreenfive", gcvars.colorsgreenfive);
		writer.writeinteger("colorsbluefive", gcvars.colorsbluefive);
		writer.writeinteger("chamteam", gcvars.chamteam);
		writer.writeinteger("aimsmooth", gcvars.aimsmooth);
		writer.writeinteger("skinmenu.m_x", g_skinmenu.m_x);
		writer.writeinteger("skinmenu.m_y", g_skinmenu.m_y);
		writer.writeinteger("colormenu.m_x", g_colormenu.m_x);
		writer.writeinteger("colormenu.m_y", g_colormenu.m_y);
		writer.writeinteger("aimmenu.m_x", g_aimmenu.m_x);
		writer.writeinteger("aimmenu.m_y", g_aimmenu.m_y);
		writer.writeinteger("espmenu.m_x", g_espmenu.m_x);
		writer.writeinteger("espmenu.m_y", g_espmenu.m_y);
		writer.writeinteger("aimtab", gcvars.aimtab);
		writer.writeinteger("visualtab", gcvars.visualtab);
		writer.writeinteger("skintab", gcvars.skintab);
		writer.writeinteger("coltab", gcvars.coltab);
		writer.writeinteger("chamers", gcvars.chamers);
		writer.writeinteger("glowers", gcvars.glowers);

		for (int weaponid = weapon_deagle; weaponid < weapon_revolver; weaponid++)
		{
			char* section = getweaponname(weaponid);

			if (strcmp(section, "") == 0)
				continue;

			writer.writeinteger(section, gcvars.w[weaponid].skiner);
		}
	}
}
