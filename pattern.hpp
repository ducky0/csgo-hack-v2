


namespace util
{
	inline bool datacompare(const char* base, const char* pattern)
	{
		for (; *pattern; ++base, ++pattern)
			if (*pattern != '?' && *base != *pattern)
				return 0;

		return *pattern == 0;
	}

	inline unsigned long findpattern(unsigned long address, unsigned long size, const char* pattern)
	{
		for (unsigned long i = 0; i < size; ++i, ++address)
			if (datacompare((const char*)address, pattern))
				return address;

		return 0;
	}

	inline unsigned long findpattern(const pe::module &module, const char* pattern)
	{
		return findpattern(module.getbase(), module.getimagesize(), pattern);
	}
}