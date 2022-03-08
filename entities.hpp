
enum teamid
{
	team_none,
	team_spec,
	team_tt,
	team_ct,
};

struct entities
{
	void* getnetworkable()
	{
		using original_fn = void * (__thiscall*)(void*);
		return (*(original_fn * *)this)[4](this);
	}

	void predataupdate(int type)
	{
		auto pnet = getnetworkable();
		using original_fn = void(__thiscall*)(void*, int);
		return (*(original_fn**)pnet)[6](pnet, type);
	}

	clientclass* getclientclass()
	{
		auto pnet = getnetworkable();
		using original_fn = clientclass * (__thiscall*)(void*);
		return (*(original_fn**)pnet)[2](pnet);
	}

	bool isdormant()
	{
		return *(bool*)((DWORD)this + xoffsets.dt_baseentity.m_feffects - 3);
	}

	vector getmaxs()
	{
		return *(vector*)((uintptr_t)this + xoffsets.dt_baseentity.m_vecmaxs);
	}

	void* getviewmodel()
	{
		return *(void**)((uintptr_t)this + xoffsets.dt_baseplayer.m_hviewmodel);
	}

	int gethealth()
	{
		return *(int*)((uintptr_t)this + xoffsets.dt_baseplayer.m_ihealth);
	}

	unsigned char getlifestate()
	{
		return *(unsigned char*)((uintptr_t)this + xoffsets.dt_baseplayer.m_lifestate);
	}

	int getteamnum()
	{
		return *(int*)((uintptr_t)this + xoffsets.dt_baseentity.m_iteamnum);
	}

	vector getaimpunchangle()
	{
		return *(vector*)((uintptr_t)this + xoffsets.dt_baseplayer.m_aimpunchangle);
	}

	vector getvecviewoffset()
	{
		return *(vector*)((uintptr_t)this + xoffsets.dt_baseplayer.m_vecviewoffset);
	}

	vector geteyeposition()
	{
		return absorigin() + getvecviewoffset();
	}

	void* getactiveweapon()
	{
		return *(void**)((uintptr_t)this + xoffsets.dt_basecombatcharacter.m_hactiveweapon);
	}

	bool isalive()
	{
		return (getlifestate() == 0 && gethealth() > 0);
	}

	bool iscontrollingbot()
	{
		return *(bool*)((DWORD)this + xoffsets.dt_csplayer.m_biscontrollingbot);
	}

	bool isreloading()
	{
		return *(bool*)((DWORD)this + xoffsets.dt_basecombatweapon.m_flnextprimaryattack + 109);
	}

	UINT* getweapons()
	{
		return (UINT*)((DWORD)this + xoffsets.dt_basecombatcharacter.m_hmyweapons);
	}

	UINT* getwearables()
	{
		return (UINT*)((DWORD)this + xoffsets.dt_basecombatcharacter.m_hmywearables);
	}

	bool hasammo()
	{
		return ((*(PINT)((DWORD)this + xoffsets.dt_basecombatweapon.m_iclip1)) > 0);
	}

	short* getitemdefinitionindex()
	{
		return (short*)((uintptr_t)this + xoffsets.dt_baseattributableitem.m_iitemdefinitionindex);
	}

	void setmodelindex(int index)
	{
		*(int*)((DWORD)this + xoffsets.dt_baseviewmodel.m_nmodelindex) = index;
	}

	int* modelindex()
	{
		return (int*)((uintptr_t)this + xoffsets.dt_baseviewmodel.m_nmodelindex);
	}

	int* itemidhigh()
	{
		return (int*)((uintptr_t)this + xoffsets.dt_baseattributableitem.m_iitemidhigh);
	}

	int* fallbackpaintkit()
	{
		return (int*)((uintptr_t)this + xoffsets.dt_baseattributableitem.m_nfallbackpaintkit);
	}

	vector absorigin()
	{
		return *(vector*)((DWORD)this + xoffsets.dt_baseentity.m_cellz + 28);
	}

	vector& getbonepos(int bone)
	{
		static vector v;

		DWORD bonematrix = *(DWORD*)(this + xoffsets.dt_baseanimating.m_nforcebone + 28);

		v.x = *(float*)(bonematrix + (bone * 48 + 12));
		v.y = *(float*)(bonematrix + (bone * 48 + 28));
		v.z = *(float*)(bonematrix + (bone * 48 + 44));

		return v;
	}
};
