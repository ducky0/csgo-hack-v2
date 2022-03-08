#include "include.hpp"

DWORD dwwait;

#define color2 85, 85, 85, 255
#define color3 0, 0, 0, 255
#define color4 35, 35, 35, 255
#define color5 50, 50, 50, 255
#define color10 255, 255, 255, 255
#define color9 25,25,25,255

#define element_seperation 20

#define checkbox_seperation_from_text 95
#define checkbox_size 13

#define dropdown_width 56
#define dropdown_height 15

#define keybind_width 30
#define keybind_height 15

#define adder_sizex 12
#define adder_sizey 13

#define button_width 120
#define button_height 15

#define adder_seperate_from_boxes 44 

cskinmenu::cskinmenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

ccolormenu::ccolormenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

caimmenu::caimmenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

cespmenu::cespmenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

cmainmenu::cmainmenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

char *firstglovename[] = { "none","charred","bronze","guerila","snake" };
int firstglovevalue[] = { 0,10006,10008,10039,10007 };

char *secondglovename[] = { "none","purple","green","omega","sling" };
int secondglovevalue[] = { 0,10037,10038,10047,10073 };

char *thirdglovename[] = { "none","snow","tie","lunar","racing" };
int thirdglovevalue[] = { 0,10070,10072,10013,10044 };

char *fourthglovename[] = { "none","tape","leather","desert","cobalt" };
int fourthglovevalue[] = { 0,10055,10009,10081,10053 };

char *fifthglovename[] = { "none","boom","mint","polygon","turtle" };
int fifthglovevalue[] = { 0,10027,10026,10052,10050 };

char *sixthglovename[] = { "none","orange","crimson","mogul","emerald" };
int sixthglovevalue[] = { 0,10035,10033,10064,10034 };

char *gaycolorname[] = { "esp","glow","chams" };
int gaycolorvalue[] = { 0,1,2 };

void cmainmenu::initmainelements()
{
	static cmenusection mstrash;

	draw::fillrgba(m_x + 2, m_y - 12, m_w - 3, m_h + 12, 30, 30, 30, 255);
	draw::outlinedrectangle(m_x + 1, m_y - 12, m_w - 2, m_h + 12, 0, 0, 0, 255);
	draw::fillrgba(m_x + 6, m_y + 7, m_w - 12, m_h - 12, color3);
	draw::fillrgba(m_x + 7, m_y + 8, m_w - 14, m_h - 14, 185, 185, 185, 255);
	font::drawstring(m_x + 9, m_y - 8, 255, 255, 255, 255, false, "main menu");

	font::drawstring(m_x + 144, m_y - 8, 255, 255, 255, 255, false, "x");

	if (g_mouse.oneleftclick(m_x + 142, m_y - 5, 8, 8))
	{
		gcvars.tabnum = 0;
	}

	int iusualx = m_x + 10;

	mstrash.clearsection();

	mstrash.draw(m_x + 9, (m_y + 13) - 2, m_w - 19, m_h - 23);

	mstrash.addelement(button, 0, -2, "aimbot", &gcvars.aimtab);
	mstrash.addelement(button, 0, -2, "visuals", &gcvars.visualtab);
	mstrash.addelement(button, 0, -2, "skins", &gcvars.skintab);
	mstrash.addelement(button, 0, -2, "colors", &gcvars.coltab);

	mstrash.addelement(button, 0, -2, "save", &gcvars.savebutt);
	mstrash.addelement(button, 0, -2, "load", &gcvars.loadbutt);

	if (gcvars.aimtab)
	{
		gcvars.tabnum = 1;

		gcvars.aimtab = false;
	}

	if (gcvars.visualtab)
	{
		gcvars.tabnum = 2;

		gcvars.visualtab = false;
	}

	if (gcvars.skintab)
	{
		gcvars.tabnum = 3;

		gcvars.skintab = false;
	}

	if (gcvars.coltab)
	{
		gcvars.tabnum = 4;

		gcvars.coltab = false;
	}
}

void cespmenu::initespelements()
{
	static cmenusection msesp;

	draw::fillrgba(m_x + 2, m_y - 12, m_w - 3, m_h + 12, 30, 30, 30, 255);
	draw::outlinedrectangle(m_x + 1, m_y - 12, m_w - 2, m_h + 12, 0, 0, 0, 255);
	draw::fillrgba(m_x + 6, m_y + 7, m_w - 12, m_h - 12, color3);
	draw::fillrgba(m_x + 7, m_y + 8, m_w - 14, m_h - 14, 185, 185, 185, 255);
	font::drawstring(m_x + 9, m_y - 8, 255, 255, 255, 255, false, "visual");

	int iusualx = m_x + 10;

	msesp.clearsection();

	msesp.draw(m_x + 9, (m_y + 13) - 2, m_w - 19, m_h - 23);

	msesp.addelement(onoff, 0, 0, "box esp", &gcvars.espbox);
	msesp.addelement(onoff, 0, 0, "health esp", &gcvars.healthbar);
	msesp.addelement(onoff, 0, 0, "glow", &gcvars.glowers);
	msesp.addelement(onoff, 0, 0, "chams", &gcvars.chamers);
}

void caimmenu::initaimelements()
{
	static cmenusection mslegitbot;

	draw::fillrgba(m_x + 2, m_y - 12, m_w - 3, m_h + 12, 30, 30, 30, 255);
	draw::outlinedrectangle(m_x + 1, m_y - 12, m_w - 2, m_h + 12, 0, 0, 0, 255);
	draw::fillrgba(m_x + 6, m_y + 7, m_w - 12, m_h - 12, color3);
	draw::fillrgba(m_x + 7, m_y + 8, m_w - 14, m_h - 14, 185, 185, 185, 255);
	font::drawstring(m_x + 9, m_y - 8, 255, 255, 255, 255, false, "aimbot");

	int iusualx = m_x + 10;

	mslegitbot.clearsection();

	mslegitbot.draw(m_x + 9, (m_y + 13) - 2, m_w - 19, m_h - 23);

	mslegitbot.addelement(keybind, 0, 0, "key bind", &gcvars.inattack);
	mslegitbot.addelement(adder, 0, 0, "aim bone", &gcvars.aimspot, 0, 8);
	mslegitbot.addelement(onoff, 0, 0, "rcs assist", &gcvars.rcsassist);

	if ((isrecoilwep(g_weaponid) && gcvars.rcsassist))
	{
		mslegitbot.addelement(adder, 0, 0, "rcs fov", &gcvars.rcsfov, 0, 20);
		mslegitbot.addelement(adder, 0, 0, "rcs smooth", &gcvars.rcssmooth, 0, 50);
	}
	else
	{
		mslegitbot.addelement(adder, 0, 0, "aim fov", &gcvars.aimfov, 0, 20);
		mslegitbot.addelement(adder, 0, 0, "aim smooth", &gcvars.aimsmooth, 0, 50);
	}
}

void ccolormenu::initcolorelements()
{
	static cmenusection colortabslide;

	draw::fillrgba(m_x + 2, m_y - 12, m_w - 3, m_h + 12, 30, 30, 30, 255);
	draw::outlinedrectangle(m_x + 1, m_y - 12, m_w - 2, m_h + 12, 0, 0, 0, 255);
	draw::fillrgba(m_x + 6, m_y + 7, m_w - 12, m_h - 12, color3);
	draw::fillrgba(m_x + 7, m_y + 8, m_w - 14, m_h - 14, 185, 185, 185, 255);
	font::drawstring(m_x + 9, m_y - 8, 255, 255, 255, 255, false, "colors");

	int iusualx = m_x + 10;

	colortabslide.clearsection();

	colortabslide.draw(m_x + 9, (m_y + 13) - 2, m_w - 19, m_h - 23);

	colortabslide.setvaluenames(gaycolorname, gaycolorvalue, 3);
	colortabslide.addelement(dropdown, 0, 0, "color", &gcvars.gayvaluete);

	if (gcvars.gayvaluete == 0)
	{
		colortabslide.addelement(adder, 0, 0, "red", &gcvars.colorsredtwo, 0, 255);
		colortabslide.addelement(adder, 0, 0, "green", &gcvars.colorsgreentwo, 0, 255);
		colortabslide.addelement(adder, 0, 0, "blue", &gcvars.colorsbluetwo, 0, 255);
	}

	if (gcvars.gayvaluete == 1)
	{
		colortabslide.addelement(adder, 0, 0, "red", &gcvars.colorsredfour, 0, 255);
		colortabslide.addelement(adder, 0, 0, "green", &gcvars.colorsgreenfour, 0, 255);
		colortabslide.addelement(adder, 0, 0, "blue", &gcvars.colorsbluefour, 0, 255);
	}

	if (gcvars.gayvaluete == 2)
	{
		colortabslide.addelement(adder, 0, 0, "red", &gcvars.colorsredfive, 0, 255);
		colortabslide.addelement(adder, 0, 0, "green", &gcvars.colorsgreenfive, 0, 255);
		colortabslide.addelement(adder, 0, 0, "blue", &gcvars.colorsbluefive, 0, 255);
	}

	colortabslide.postsection();
}

void cskinmenu::initskinelements()
{
	static cmenusection trashniggers;

	trashniggers.clearsection();

	draw::fillrgba(m_x + 2, m_y - 12, m_w - 3, m_h + 12, 30, 30, 30, 255);
	draw::outlinedrectangle(m_x + 1, m_y - 12, m_w - 2, m_h + 12, 0, 0, 0, 255);
	draw::fillrgba(m_x + 6, m_y + 7, m_w - 12, m_h - 12, color3);
	draw::fillrgba(m_x + 7, m_y + 8, m_w - 14, m_h - 14, 185, 185, 185, 255);
	font::drawstring(m_x + 9, m_y -8, 255, 255, 255, 255, false, "skins");

	trashniggers.draw(m_x+ 9, (m_y + 13) -2, m_w - 19, m_h - 23);

	trashniggers.addelement(onoff, 0, 0, "enable", &gcvars.skinchanger);
	trashniggers.addelement(adder, 0, 0, "knife", &gcvars.knife, 0, 5);
	trashniggers.addelement(adder, 0, 0, "glove", &gcvars.gloves, 0, 5);

	if (gcvars.gloves == 0)
	{
		trashniggers.setvaluenames(firstglovename, firstglovevalue, 5);
		trashniggers.addelement(dropdown, 0, 0, "glove kit", &gcvars.glovekit1);
	}
	else if (gcvars.gloves == 1)
	{
		trashniggers.setvaluenames(secondglovename, secondglovevalue, 5);
		trashniggers.addelement(dropdown, 0, 0, "glove kit", &gcvars.glovekit2);
	}
	else if (gcvars.gloves == 2)
	{
		trashniggers.setvaluenames(thirdglovename, thirdglovevalue, 5);
		trashniggers.addelement(dropdown, 0, 0, "glove kit", &gcvars.glovekit3);
	}
	else if (gcvars.gloves == 3)
	{
		trashniggers.setvaluenames(fourthglovename, fourthglovevalue, 5);
		trashniggers.addelement(dropdown, 0, 0, "glove kit", &gcvars.glovekit4);
	}
	else if (gcvars.gloves == 4)
	{
		trashniggers.setvaluenames(fifthglovename, fifthglovevalue, 5);
		trashniggers.addelement(dropdown, 0, 0, "glove kit", &gcvars.glovekit5);
	}
	else if (gcvars.gloves == 5)
	{
		trashniggers.setvaluenames(sixthglovename, sixthglovevalue, 5);
		trashniggers.addelement(dropdown, 0, 0, "glove kit", &gcvars.glovekit6);
	}

	if (isrecoilwep(g_weaponid) || isaimwep(g_weaponid))
	{
		trashniggers.addelement(inputint, 0, 0, "paint kit", &gcvars.w[g_weaponid].skiner);
	}
	else if ((isweaponknife(g_weaponid)))
	{
		trashniggers.addelement(inputint, 0, 0, "paint kit", &gcvars.knifeskin);
	}
	else
	{
		trashniggers.addelement(inputint, 0, 0, "paint kit", &gcvars.placeholder);
	}


	trashniggers.postsection();
}

void cmenusection::draw(int x, int y, int w, int h)
{
	draw::outlinedrectangle(x,y,w,h,color9);

	setsectionpos(x,y);
}

void cmenusection::drawalldropdowns()
{
	int inumofdropdowns = vecdropdowns.size();

	int iwhich = -1;

	for (int i2 = (inumofdropdowns - 1); i2 >= 0; i2--)
	{
		bool bisactive = bactivedropdown[i2];

		if (bisactive)
		{
			iwhich = i2;

			dwwait = GetTickCount() + 700;
			break;
		}
	}

	for (int i = (inumofdropdowns - 1); i >= 0; i--)
	{
		int e_x = vecdropdowns[i].x;
		int e_y = vecdropdowns[i].y;
		int icount = vecdropdowns[i].icount;

		bool bisactive = bactivedropdown[i];

		char **ppsznames = vecdropdowns[i].ppsznames;
		int *fvalues = vecdropdowns[i].fvalues;
		int *cvar = vecdropdowns[i].cvar;

		int gayfag = e_x - 1;

		if (bisactive)
		{
			int string_x = gayfag + (dropdown_width * 0.5);

			for (int ax = 0; ax < icount; ax++)
			{
				if (g_mouse.isover(gayfag, e_y + (ax * dropdown_height), dropdown_width, dropdown_height))
				{
					if (!ishandlingitem())
						addmenuflag(fl_disabledrag);

					draw::fillrgba(gayfag + 1, e_y + 1 + (ax * dropdown_height), dropdown_width - 1, dropdown_height - (ax == (icount - 1) ? 1 : 0), color5);

					if (g_mouse.hasmouseonejustbeenreleased())
					{
						*cvar = fvalues[ax];

						bactivedropdown[i] = false;
					}
				}
				else
				{
					draw::fillrgba(gayfag + 1, e_y + 1 + (ax * dropdown_height), dropdown_width - 1, dropdown_height - (ax == (icount - 1) ? 1 : 0), color4);

					if (g_mouse.hasmouseonejustbeenreleased())
					{
						bactivedropdown[i] = false;
					}
				}

				if (ax == (icount - 1))
					draw::outlinedrectangle(gayfag, e_y, dropdown_width, (ax + 1) * dropdown_height, color3);

				if (*cvar == fvalues[ax])
				{
					font::drawstring(string_x, e_y + (ax * dropdown_height) + 2, color10, true, ppsznames[ax]);
				}
				else
				{
					font::drawstring(string_x, e_y + (ax * dropdown_height) + 2, color10, true, ppsznames[ax]);
				}
			}
		}
		else
		{
			if (g_mouse.isover(gayfag, e_y, dropdown_width, dropdown_height))
			{
				if (!ishandlingitem())
					addmenuflag(fl_disabledrag);

				draw::fillrgba(gayfag + 1, e_y + 1, dropdown_width - 1, dropdown_height - 1, color5);

				if (g_mouse.hasmouseonejustbeenreleased() && (dwwait < GetTickCount() || iwhich == -1))
				{
					bactivedropdown[i] = true;
				}
			}
			else
				draw::fillrgba(gayfag + 1, e_y + 1, dropdown_width - 1, dropdown_height - 1, color4);

			draw::outlinedrectangle(gayfag, e_y, dropdown_width, dropdown_height, color3);

			int string_x = gayfag + (dropdown_width * 0.5);
			int string_y = e_y;

			for (int ax = 0; ax < icount; ax++)
			{
				if (*cvar == fvalues[ax])
				{
					font::drawstring(string_x, string_y + 2, color10, true, ppsznames[ax]);
					break;
				}
			}
		}
	}

	clearallelementspecifics();
}

int getpressedkey()
{
	for (int i = 1; i < 256; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
			return i;
	}
	return -1;
}

const char* explainkey(int vk)
{
	static char explaination[16] = { 0 };

    #define	denyvk(_key) if (vk == _key) return explaination

	denyvk(VK_INSERT);

	if (char exp = MapVirtualKey(vk, MAPVK_VK_TO_CHAR) & 255)
	{
		if (exp == 32)
			return "space";
		else if (exp == '\t')
			return "tab";
		else if (exp == '\b')
			return "backspace";
		else if (exp == '\n' || exp == '\r')
			return "enter";
		else
			sprintf(explaination, "%c", exp);
	}
	else
	{
		switch (vk)
		{
		case VK_LBUTTON:	return "lmb";
		case VK_RBUTTON:	return "rmb";
		case VK_MBUTTON:	return "wheel";
		case VK_XBUTTON1:	return "x1";
		case VK_XBUTTON2:	return "x2";
		case VK_INSERT:		return "ins";
		case VK_DELETE:		return "del";
		case VK_LSHIFT:		return "l shift";
		case VK_RSHIFT:		return "r shift";
		case VK_LMENU:		return "l alt";
		case VK_RMENU:		return "r alt";
		case VK_LCONTROL:	return "l ctrl";
		case VK_RCONTROL:	return "r ctrl";
		}
	}

	return explaination;
}

void cmenusection::addelement(int itype, int add_to_x, int add_to_y, const char *pszelementname, int *cvar, int min, int max)
{
	int e_x = s_x + 10 + add_to_x;
	int e_y = s_y + 15 + (isection * element_seperation) + add_to_y;

	bool bdropdownactive = false;

	for (int i2 = 0; i2 < 50; i2++)
	{
		bdropdownactive = bactivedropdown[i2];

		if (bdropdownactive)
			break;
	}

	if (itype == onoff)
	{
		font::drawstring(e_x, e_y, color10, false, pszelementname);

		e_x += checkbox_seperation_from_text;

		if (g_mouse.oneleftclick(e_x - 3, e_y - 3, checkbox_size + 5, checkbox_size + 5) && !bdropdownactive)
			*cvar = !*cvar;

		e_y += 1;

		draw::fillrgba(e_x+1, e_y + 1, checkbox_size-2, checkbox_size - 1, color4);

		if (g_mouse.isover(e_x, e_y, checkbox_size - 1, checkbox_size))
		{
			draw::fillrgba(e_x + 1, e_y + 1, checkbox_size - 2, checkbox_size - 1, color5);

			draw::outlinedrectangle(e_x, e_y, checkbox_size - 1, checkbox_size, color9);

			if (!ishandlingitem())
				addmenuflag(fl_disabledrag);
		}
		else
			draw::outlinedrectangle(e_x, e_y, checkbox_size-1, checkbox_size, color9);

		if (*cvar)
		{
			for (int i = 0; i < 3; i++)
				draw::fillrgba(e_x + i + 3, e_y + i + 6, 1, 2, 255,255,255,255);

			for (int i = 0; i < 5; i++)
				draw::fillrgba(e_x + i + 5, e_y - i + 8, 1, 2, 255,255,255,255);
		}
	}
	else if (itype == dropdown)
	{
		font::drawstring(e_x, e_y, color10, false, pszelementname);

		e_y += 1;

		dropdown_t ddnew;

		ddnew.x = e_x + checkbox_seperation_from_text - 20;
		ddnew.y = e_y - 2;
		ddnew.fvalues = fvaluelist;
		ddnew.cvar = cvar;
		ddnew.ppsznames = ppszvaluenames;
		ddnew.icount = ivaluecount;

		adddropdowntodrawlist(ddnew);
	}
	else if (itype == adder)
	{
		int gayfag = e_x - 1;

		font::drawstring(e_x, e_y, color10, false, pszelementname);

		e_y += 1;

		gayfag += (checkbox_seperation_from_text - 20);

		draw::fillrgba(gayfag+1, e_y + 1, adder_sizex - 1, adder_sizey - 1, color4);

		if (g_mouse.isover(gayfag, e_y, adder_sizex, adder_sizey))
		{
			draw::outlinedrectangle(gayfag, e_y, adder_sizex, adder_sizey, color9);

			if (g_mouse.hasmouseonejustbeenreleased() && !bdropdownactive)
				*cvar -= 1;

			if (g_mouse.ismousetwobeingheld() && !bdropdownactive)
				*cvar -= 1;
		}
		else
			draw::outlinedrectangle(gayfag, e_y, adder_sizex, adder_sizey, color4);

		draw::renderline((gayfag + adder_sizex / 2) - 3, (e_y + 6), (gayfag + adder_sizex / 2) + 4, (e_y + 6), 255, 255, 255, 255);

		font::drawstring(gayfag - 7 + adder_sizex + adder_seperate_from_boxes * 0.5, e_y, color10, true, "%0i", *cvar);

		gayfag += adder_seperate_from_boxes;

		draw::fillrgba(gayfag+1, e_y + 1, adder_sizex-1, adder_sizey - 1, color4);

		if (g_mouse.isover(gayfag, e_y, adder_sizex, adder_sizey))
		{
			draw::outlinedrectangle(gayfag, e_y, adder_sizex, adder_sizey, color9);

			if (g_mouse.hasmouseonejustbeenreleased() && !bdropdownactive)
				*cvar += 1;

			if (g_mouse.ismousetwobeingheld() && !bdropdownactive)
				*cvar += 1;
		}
		else
			draw::outlinedrectangle(gayfag, e_y, adder_sizex, adder_sizey, color4);

		draw::renderline((gayfag + adder_sizex / 2) - 3, (e_y + 6), (gayfag + adder_sizex / 2) + 4, (e_y + 6), 255, 255, 255, 255);
		draw::renderline((gayfag + adder_sizex / 2), (e_y + 6) - 3, (gayfag + adder_sizex / 2), (e_y + 6) + 4, 255, 255, 255, 255);

		if (*cvar < min)
			*cvar = max;

		if (*cvar > max)
			*cvar = min;
	}
	else if (itype == inputint)
	{
	    font::drawstring(e_x, e_y, color10, false, pszelementname);

		static std::string szinput;
		static int ipos;

		int gayfag = e_x + checkbox_seperation_from_text - 21;

		int  var_b = *cvar;

		if (!g_mouse.isover(gayfag, e_y - 2, dropdown_width, dropdown_height))
		{
			szinput = std::to_string(var_b);
		}

		bool inshit = g_mouse.isover(gayfag, e_y - 2, dropdown_width, dropdown_height);

		if (GetAsyncKeyState(VK_RETURN) & 1 && inshit)
		{
			pclientstate->m_ndeltatick = -1;
		}

		if (var_b > 9999)
			szinput.erase(szinput.end() - 1);

		if (GetAsyncKeyState(0x30) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '0');

		if (GetAsyncKeyState(0x31) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '1');

		if (GetAsyncKeyState(0x32) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '2');

		if (GetAsyncKeyState(0x33) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '3');

		if (GetAsyncKeyState(0x34) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '4');

		if (GetAsyncKeyState(0x35) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '5');

		if (GetAsyncKeyState(0x36) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '6');

		if (GetAsyncKeyState(0x37) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '7');

		if (GetAsyncKeyState(0x38) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '8');

		if (GetAsyncKeyState(0x39) & 1 && inshit)
			szinput.insert(szinput.end() - ipos, '9');

		if (GetAsyncKeyState(VK_BACK) & 1 && inshit && ipos < szinput.length() && szinput.length() > 0)
			szinput.erase(szinput.end() - ipos - 1);

		if (g_mouse.isover(gayfag, e_y - 2, dropdown_width, dropdown_height))
		{
			if (!ishandlingitem())
				addmenuflag(fl_disabledrag);

			draw::fillrgba(gayfag + 1, e_y - 1, dropdown_width - 1, dropdown_height - 1, color5);
		}
		else
			draw::fillrgba(gayfag + 1, e_y - 1, dropdown_width - 1, dropdown_height - 1, color4);

		draw::outlinedrectangle(gayfag, e_y - 2, dropdown_width, dropdown_height, color3);

		int string_x = gayfag + (dropdown_width * 0.5);
		int string_y = e_y - 2;

		*cvar = atof(szinput.data());

		font::drawstring(string_x, string_y + 2, color10, true, szinput.data());

	}
	else if (itype == button)
	{
		bool bleftclick = g_mouse.leftclick(e_x, e_y, button_width, button_height);

		if (*cvar)
			draw::fillrgba(e_x + 1, e_y, button_width - 1, button_height, 140, 140, 140, 255);
		else
		{
			if (bleftclick)
				draw::fillrgba(e_x + 1, e_y, button_width - 1, button_height, 25, 25, 25, 255);
			else
				draw::fillrgba(e_x + 1, e_y, button_width - 1, button_height, 35, 35, 35, 255);
		}

		font::drawstring(e_x + button_width / 2, e_y + 2, 255, 255, 255, 255, true, pszelementname);

		if (g_mouse.isover(e_x, e_y, button_width, button_height))
		{
			if (!bleftclick)
				draw::outlinedrectangle(e_x, e_y, button_width, button_height, color9);
			else
				draw::outlinedrectangle(e_x, e_y, button_width, button_height, color3);

			if (g_mouse.hasmouseonejustbeenreleased() && !bdropdownactive)
			{
				*cvar = !*cvar;
			}
		}
		else
			draw::outlinedrectangle(e_x, e_y, button_width, button_height, color3);
	}
	else if (itype == keybind)
	{
	    font::drawstring(e_x, e_y, color10, false, pszelementname);

		int gayfag = e_x + checkbox_seperation_from_text - 9;

		int pressedkey;

		if (g_mouse.isover(gayfag, e_y - 2, keybind_width, keybind_height))
		{
			pressedkey = getpressedkey();

			if (pressedkey > 0 &&
				pressedkey != 0x57 && //a
				pressedkey != 0x53 && //w
				pressedkey != 0x44 && //s
				pressedkey != 0x41 && //d
				pressedkey != VK_SPACE &&
				pressedkey != VK_SHIFT &&
				pressedkey != VK_LSHIFT &&
				pressedkey != VK_RSHIFT &&
				pressedkey != VK_CONTROL &&
				pressedkey != VK_LCONTROL &&
				pressedkey != VK_RCONTROL &&
				pressedkey != VK_BACK &&
				pressedkey != VK_RETURN &&
				pressedkey != VK_END &&
				pressedkey != VK_INSERT)

				*cvar = pressedkey;
		}

		if (g_mouse.isover(gayfag, e_y - 2, keybind_width, keybind_height))
		{
			if (!ishandlingitem())
				addmenuflag(fl_disabledrag);

			draw::fillrgba(gayfag + 1, e_y - 1, keybind_width - 1, keybind_height - 1, color5);
		}
		else
			draw::fillrgba(gayfag + 1, e_y - 1, keybind_width - 1, keybind_height - 1, color4);

		draw::outlinedrectangle(gayfag, e_y - 2, keybind_width, keybind_height, color3);

		int string_x = gayfag + (keybind_width * 0.5);
		int string_y = e_y - 2;

		if (*cvar == VK_ESCAPE)
		{
			font::drawstring(string_x, string_y + 2, color10, true, "off");
		}
		else
		{
			font::drawstring(string_x, string_y+2, color10, true, explainkey(*cvar));
		}
	}

	postelement();
}

