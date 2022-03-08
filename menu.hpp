
enum
{
	fl_disabledrag = (1 << 1)
};

enum
{
	onoff,
	dropdown,
	inputint,
	keybind,
	button,
	adder
};

typedef struct dropdown_s
{
	int x, y;
	int icount;
	int *fvalues;
	int *cvar;
	char **ppsznames;
} dropdown_t;

class cmenusection
{
public:
	void draw(int,int,int,int);

	void addelement(int,int,int,const char*,int*,int min = 0,int max = 1);

	void drawalldropdowns();

	void postsection()
	{
		drawalldropdowns();
	}

	void clearsection()
	{
		vecdropdowns.clear();

		restartsection();
	}

	void restartsection()
	{
		isection = 0;
	}

	void postelement()
	{
		isection += 1;
	}
	
	void setsectionpos(int x, int y)
	{
		s_x = x;
		s_y = y;
	}

	void setvaluenames(char **szarrayarray, int *farray, int icount)
	{
		ppszvaluenames = szarrayarray;
		fvaluelist = farray;
		ivaluecount = icount;
	}

	void clearallelementspecifics()
	{
		setvaluenames(0,0,0);
	}

	bool ishandlingitem()
	{
		return (imenuflags & fl_disabledrag);
	}

	void addmenuflag(int iflag)
	{
		imenuflags |= iflag;
	}

	void removemenuflag(int iflag)
	{
		imenuflags &= ~iflag;
	}

	int itabindex;
private:
	void adddropdowntodrawlist(dropdown_t ddnew)
	{
		vecdropdowns.push_back(ddnew);
	}

	int isection;
	int s_x, s_y;
	int imenuflags;
	int *fvaluelist;
	char **ppszvaluenames;
	int ivaluecount;
	bool bactivedropdown[50];
	std::vector<dropdown_t> vecdropdowns;
};

inline cmenusection g_menusec;

class cskinmenu
{
public:
	cskinmenu(int, int, int, int);

	void initskinelements();

	void setskinmenupos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	int m_x, m_y, m_w, m_h;
};

inline cskinmenu g_skinmenu(600, 600, 168, 143);

class ccolormenu
{
public:
	ccolormenu(int, int, int, int);

	void initcolorelements();

	void setcolormenupos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	int m_x, m_y, m_w, m_h;
};

inline ccolormenu g_colormenu(700, 700, 168, 123);


class caimmenu
{
public:
	caimmenu(int, int, int, int);

	void initaimelements();

	void setaimmenupos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	int m_x, m_y, m_w, m_h;
};

inline caimmenu g_aimmenu(700, 700, 168, 143);

class cespmenu
{
public:
	cespmenu(int, int, int, int);

	void initespelements();

	void setespmenupos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	int m_x, m_y, m_w, m_h;
};

inline cespmenu g_espmenu(150, 150, 149, 123);

class cmainmenu
{
public:
	cmainmenu(int, int, int, int);

	void initmainelements();

	void setmainmenupos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void getmainmenupos(int &out_x, int &out_y)
	{
		out_x = m_x;
		out_y = m_y;
	}

	void getmainmenusize(int &out_w, int &out_h)
	{
		out_w = m_w;
		out_h = m_h;
	}

	int m_x, m_y, m_w, m_h;
};

inline cmainmenu g_mainmenu(150, 150, 159, 160);