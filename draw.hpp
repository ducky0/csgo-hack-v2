

inline void drawmenu(unsigned int vguipanel)
{
	if (GetAsyncKeyState(VK_END) & 1)
	{
		gcvars.bmenu = !gcvars.bmenu;
	}

	ppanel->setmouseinput(vguipanel, gcvars.bmenu);
	ppanel->setkeyboardinput(vguipanel, gcvars.bmenu);

	if (gcvars.bmenu)
	{
		g_mouse.update(iscreenwidth, iscreenheight);

		int copy_x, copy_y;
		int copy_w, copy_h;

		g_mainmenu.getmainmenupos(copy_x, copy_y);
		g_mainmenu.getmainmenusize(copy_w, copy_h);

		g_mouse.drag(g_mouse.bdragged[0], !g_menusec.ishandlingitem()
			, g_mouse.leftclick(copy_x, copy_y, copy_w, copy_h), copy_x,
			copy_y, g_mouse.idiffx[0], g_mouse.idiffy[0]);

		g_mainmenu.setmainmenupos(copy_x, copy_y);

		g_mainmenu.initmainelements();

		if (gcvars.tabnum == 3)
		{
			g_skinmenu.setskinmenupos(copy_x + 160, copy_y);

			g_skinmenu.initskinelements();
		}

		if (gcvars.tabnum == 4)
		{
			g_colormenu.setcolormenupos(copy_x + 160, copy_y);

			g_colormenu.initcolorelements();
		}

		if (gcvars.tabnum == 1)
		{
			g_aimmenu.setaimmenupos(copy_x + 160, copy_y);

			g_aimmenu.initaimelements();
		}

		if (gcvars.tabnum == 2)
		{
			g_espmenu.setespmenupos(copy_x + 160, copy_y);

			g_espmenu.initespelements();
		}

		if (g_menusec.ishandlingitem())
		{
			g_menusec.removemenuflag(fl_disabledrag);
		}

		if (gcvars.savebutt)
		{
			cfgsystem::savecfg();
			pclientstate->m_ndeltatick = -1;
			gcvars.savebutt = 0;
		}

		if (gcvars.loadbutt)
		{
			cfgsystem::loadcfg();
			pclientstate->m_ndeltatick = -1;
			gcvars.loadbutt = 0;
		}
	}
}

inline void drawvisuals(entities* plocal)
{
	if (!plocal)
		return;

	if (gcvars.chamers)
	{
		esp::charms(plocal);
	}

	if (gcvars.espbox || gcvars.healthbar)
	{
		esp::draw(plocal);
	}
}
