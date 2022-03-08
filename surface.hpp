


struct panel
{
	void setkeyboardinput(unsigned int panel_id, bool state)
	{
		using original_fn = void(__thiscall*)(panel*, unsigned int, bool);
		return (*(original_fn**)this)[31](this, panel_id, state);
	}

	void setmouseinput(unsigned int panel_id, bool state)
	{
		using original_fn = void(__thiscall*)(panel*, unsigned int, bool);
		return (*(original_fn**)this)[32](this, panel_id, state);
	}

	const char* getname(unsigned int panel_id)
	{
		using original_fn = const char* (__thiscall*)(panel*, unsigned int);
		return (*(original_fn * *)this)[36](this, panel_id);
	}
};

struct surface
{
	void drawsetcolor(int r, int g, int b, int a)
	{
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[15](this, r, g, b, a);
	}

	void drawfilledrect(int x, int y, int w, int h)
	{
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[16](this, x,y,w,h);
	}

	void drawoutlinewdrect(int x, int y, int x1, int y1)
	{
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn**)this)[18](this, x, y, x1, y1);
	}

	void drawline(int x1, int y1, int x2, int y2)
	{
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn**)this)[19](this, x1, y1, x2, y2);
	}

	void surfacegetcursorpos(int& x, int& y)
	{
		using original_fn = void(__thiscall*)(surface*, int&, int&);
		return (*(original_fn * *)this)[100](this, x, y);
	}
};