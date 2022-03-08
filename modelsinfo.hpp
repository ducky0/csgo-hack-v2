

struct modelinfo
{
	int getmodelindex(const char* filename)
	{
		using original_fn = int(__thiscall*)(modelinfo*, const char*);
		return (*(original_fn * *)this)[2](this, filename);
	}
};

template <typename t>
class utlvector
{
public:
	constexpr t& operator[](int i) noexcept
	{
		return memory[i];
	}

	constexpr const t& operator[](int i) const noexcept
	{
		return memory[i];
	}

	t* memory;
	int allocationcount;
	int growsize;
	int size;
	t* elements;
};

struct glowdefinition
{
	int nextfreeslot;
	entities* entity;
	vector glowcolor;
	float glowalpha;
	bool glowalphacappedbyrenderalpha;
	float glowalphafunctionofmaxvelocity;
	float glowalphamax;
	float glowpulseoverdrive;
	bool renderwhenoccluded;
	bool renderwhenunoccluded;
	bool fullbloomrender;
	int fullbloomstenciltestvalue;
	int glowstyle;
	int splitscreenslot;

	constexpr bool isunused() const noexcept { return nextfreeslot != entry_in_use; }

	static constexpr int end_of_free_list = -1;
	static constexpr int entry_in_use = -2;
};

struct glowobj
{
	utlvector<glowdefinition> glowobjectdefinitions;
};
