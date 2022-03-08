
namespace pe
{
	class module 
	{
	private:
		LDR_DATA_TABLE_ENTRY *m_ldr_entry;
		IMAGE_DOS_HEADER     *m_dos;
		IMAGE_NT_HEADERS     *m_nt;

	public:
		module() :
			m_ldr_entry{ nullptr }, m_dos{ nullptr }, m_nt{ nullptr } {}

		module(LDR_DATA_TABLE_ENTRY *ldr_entry, IMAGE_DOS_HEADER *dos, IMAGE_NT_HEADERS *nt) :
			m_ldr_entry{ ldr_entry }, m_dos{ dos }, m_nt{ nt } {}

		uintptr_t getbase() const
		{
			return (m_ldr_entry) ? uintptr_t(m_ldr_entry->dllbase) : uintptr_t{};
		}

		operator bool() const 
		{
			return getbase();
		}

		bool operator !() const 
		{
			return !getbase();
		}

		operator uintptr_t() const
		{
			return (m_ldr_entry) ? uintptr_t(m_ldr_entry->dllbase) : uintptr_t{};
		}

		IMAGE_DOS_HEADER *getdos() const 
		{
			return (m_dos) ? m_dos : nullptr;
		}

		IMAGE_NT_HEADERS *getnt() const 
		{
			return (m_nt) ? m_nt : nullptr;
		}

		size_t getcodesize() const 
		{
			return (m_nt) ? (size_t)m_nt->OptionalHeader.SizeOfCode : 0u;
		}

		size_t getimagesize() const 
		{
			return (m_nt) ? (size_t)m_nt->OptionalHeader.SizeOfImage : 0u;
		}

		std::string getname() const 
		{
			std::string     out;
			std::wstring    wide_name;

			if (!m_ldr_entry)
				return {};

			wide_name = std::wstring(m_ldr_entry->BaseDllName.buffer, m_ldr_entry->BaseDllName.length >> 1);

			out = std::string(wide_name.begin(), wide_name.end());

			std::transform(out.begin(), out.end(), out.begin(), ::tolower);

			return out;
		}
	};

	using modules_t = std::vector< module >;

	inline bool getfileheaders(uintptr_t base, PIMAGE_DOS_HEADER &out_dos, PIMAGE_NT_HEADERS &out_nt)
	{
		auto dos = (IMAGE_DOS_HEADER*)base;

		if (!dos || dos->e_magic != IMAGE_DOS_SIGNATURE)
			return false;

		auto nt = (IMAGE_NT_HEADERS *)((uintptr_t)dos + dos->e_lfanew);

		if (!nt || nt->Signature != IMAGE_NT_SIGNATURE)
			return false;

		out_dos = dos;
		out_nt = nt;

		return true;
	}

	static bool getallmodules(modules_t &out) 
	{
		_peb                 *peb;
		LIST_ENTRY           *list;
		LDR_DATA_TABLE_ENTRY *ldr_entry;
		IMAGE_DOS_HEADER     *dos{ nullptr };
		IMAGE_NT_HEADERS     *nt{ nullptr };

		peb = (_peb *)__readfsdword(0x30);
		if (!peb)
			return false;

		list = &peb->ldr->inmemoryordermodulelist;

		for (auto it = list->Flink; it != list; it = it->Flink) 
		{
			ldr_entry = CONTAINING_RECORD(it, LDR_DATA_TABLE_ENTRY, inmemoryorderlinks);
			if (!ldr_entry)
				continue;

			if (!getfileheaders(ldr_entry->dllbase, dos, nt))
				continue;

			out.push_back({ ldr_entry, dos, nt });
		}

		return !out.empty();
	}

	static module getmodule(std::string name) 
	{
		modules_t modules;

		if (!getallmodules(modules))
			return {};

		std::transform(name.begin(), name.end(), name.begin(), ::tolower);

		for (const auto &m : modules) 
		{
			if (m.getname() == name)
				return m;
		}

		return {};
	}

	static uintptr_t getexport(const module &module, const std::string &name)
	{
		uintptr_t     export_ptr, fwd_export_ptr;
		size_t      delim;
		std::string export_name, fwd_str, fwd_module, fwd_export;

		if (!module)
			return {};

		auto nt = module.getnt();
		auto base = module.getbase();

		auto data_dir = &nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
		if (!data_dir->VirtualAddress)
			return {};

		auto dir = (IMAGE_EXPORT_DIRECTORY*)((uintptr_t)base + data_dir->VirtualAddress);

		if (!dir)
			return {};

		auto names = (uint32_t*)((uintptr_t)base + dir->AddressOfNames);
		auto funcs = (uint32_t*)((uintptr_t)base + dir->AddressOfFunctions);
		auto ords = (uint16_t*)((uintptr_t)base + dir->AddressOfNameOrdinals);

		if (!names || !funcs || !ords)
			return {};

		for (size_t i{ 0u }; i < dir->NumberOfNames; ++i)
		{
			export_name = (const char*)((DWORD)base + names[i]);

			if (export_name.empty())
				continue;

			if (export_name == name)
			{
				export_ptr = ((uintptr_t)base + funcs[ords[i]]);

				if (export_ptr >= (uintptr_t)dir && export_ptr < ((uintptr_t)dir + data_dir->Size)) 
				{
					fwd_str = (const char*)export_ptr;

					delim = fwd_str.find_last_of('.') + 1;

					if (delim == std::string::npos)
						return {};

					fwd_module = fwd_str.substr(0, delim);

					fwd_module += 'd';
					fwd_module += 'l';
					fwd_module += 'l';

					fwd_export = fwd_str.substr(delim);

					fwd_export_ptr = getexport(getmodule(fwd_module), fwd_export);

					if (!fwd_export_ptr)
						return {};

					return fwd_export_ptr;
				}

				return export_ptr;
			}
		}

		return {};
	}
}