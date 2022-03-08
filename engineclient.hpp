


struct clientstate
{
	byte  pad[372];
	uint32_t m_ndeltatick;
};

struct engineclient
{
	void getscreensize(int& width, int& height)
	{
		using original_fn = void(__thiscall*)(engineclient*, int&, int&);
		return (*(original_fn * *)this)[5](this, width, height);
	}

	int getlocalplayer()
	{
		using original_fn = int(__thiscall*)(engineclient*);
		return (*(original_fn * *)this)[12](this);
	}

	void getviewangles(vector& vangles)
	{
		using original_fn = void(__thiscall*)(engineclient*, vector&);
		return (*(original_fn**)this)[18](this, vangles);
	}

	void setviewangles(vector& angles)
	{
		using original_fn = void(__thiscall*)(engineclient*, vector&);
		return (*(original_fn**)this)[19](this, angles);
	}

	int getmaxclients()
	{
		using original_fn = int(__thiscall*)(engineclient*);
		return (*(original_fn * *)this)[20](this);
	}

	bool isingame()
	{
		using original_fn = bool(__thiscall*)(engineclient*);
		return (*(original_fn**)this)[26](this);
	}

	const char* getdirectory()
	{
		using original_fn = const char*(__thiscall*)(engineclient*);
		return (*(original_fn * *)this)[36](this);
	}

	matrix4x4& worldtoscreenmatrix()
	{
		using original_fn = matrix4x4 & (__thiscall*)(engineclient*);
		return (*(original_fn * *)this)[37](this);
	}
};

struct entitylist
{
	entities* getcliententity(int index)
	{
		using original_fn = entities * (__thiscall*)(entitylist*, int);
		return (*(original_fn * *)this)[3](this, index);
	}
	entities* getcliententityfromhandle(void* handle)
	{
		using original_fn = entities * (__thiscall*)(entitylist*,void*);
		return (*(original_fn * *)this)[4](this, handle);
	}
	int gethighestentityindex()
	{
		using original_fn = int(__thiscall*)(entitylist*);
		return (*(original_fn * *)this)[6](this);
	}
};

struct client
{
	clientclass* getallclasses()
	{
		using original_fn = clientclass * (__thiscall*)(client*);
		return (*(original_fn * *)this)[8](this);
	}
};
