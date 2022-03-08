


struct recvprop;

struct recvtable
{
	recvprop		*m_pprops;
	int				m_nprops;
	byte            pad[4];
	char			*m_pnettablename;
};

struct recvprop
{
	char	  *m_pvarname;
	byte      ppad[36];
	recvtable *m_pdatatable;
	int		  m_offset;
	byte      pad[12];
};

struct clientclass
{
	using create_fn = void*(*)(int, int);

	create_fn     m_pcreatefn;
	byte          pad[8];
	recvtable*	  gettable;
	clientclass*  nextclass;
	int           getclassid;
};

struct serverclass
{
	const char		*m_pnetworkname;
	void*			*m_ptable;
	serverclass		*m_pnext;
};

struct servergame
{
	serverclass* getallserverclasses()
	{
		using original_fn = serverclass * (__thiscall*)(servergame*);
		return (*(original_fn * *)this)[10](this);
	}
};