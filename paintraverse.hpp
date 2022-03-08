

typedef void(__fastcall *paintraversefn)(void*, void*, unsigned int, bool, bool);
paintraversefn org_paintraverse;

void __fastcall hkpainttraverse(void* ecx, void* edx, unsigned int vguipanel, bool forcerepaint, bool allowforce)
{
	org_paintraverse(ecx, edx, vguipanel, forcerepaint, allowforce);

	static unsigned int focusoverlaypanel = 0;

	static bool foundpanel = false;

	if (!foundpanel)
	{
		PCHAR szpanelname = (PCHAR)ppanel->getname(vguipanel);

		if (strstr(szpanelname, "FocusOverlayPanel"))
		{
			focusoverlaypanel = vguipanel;

			foundpanel = true;
		}
	}
	else if (focusoverlaypanel == vguipanel)
	{
		static bool bskip = false;
		bskip = !bskip;

		if (bskip)
			return;

		pengine->getscreensize(iscreenwidth, iscreenheight);

		if (iscreenwidth == 0 || iscreenheight == 0)
			return;

		if (pengine->isingame())
		{
			entities* plocal = pentlist->getcliententity(pengine->getlocalplayer());

			runglow(plocal);
			dostuff(plocal);
			drawvisuals(plocal);
		}

		drawmenu(vguipanel);
	}
}
