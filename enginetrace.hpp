
enum masksray
{
	mask_shot = 0x46004009
};

struct raytrace
{
	raytrace(const vector& src, const vector& dest) : start(src), delta(dest - src) { isswept = delta.x || delta.y || delta.z; }
	vector start{ };
	float pad{ };
	vector delta{ };
	byte pad2[40]{ };
	bool isray{ true };
	bool isswept{ };
};

struct tracefitlers
{
	tracefitlers(const entities* entity) : skip{ entity } { }
	virtual bool shouldhitentity(entities* entity, int) { return entity != skip; }
	virtual int gettracetype() const { return 0; }
	const void* skip;
};

struct traceclass
{
	byte  ppad[44];
	float fraction;
	byte  xpad[25];
	entities* entity;
	byte  bpad[4];
};

struct enginetrace
{
	void traceray(const raytrace &ray, tracefitlers *ptracefilter, traceclass *ptrace)
	{
		using original_fn = void (__thiscall*)(enginetrace*, const raytrace &, unsigned int, tracefitlers *, traceclass *);
		return (*(original_fn * *)this)[5](this, ray, mask_shot, ptracefilter, ptrace);
	}
};

