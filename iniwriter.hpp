

class ciniwriter
{
public:
	ciniwriter(const char* szfilename, ...)
	{
		memset(m_szfilename, 0x00, 255);
		memcpy(m_szfilename, szfilename, strlen(szfilename));
	}
	void writeinteger(char* szkey, int ivalue)
	{
		char szvalue[255];
		sprintf(szvalue, "%d", ivalue);
		WritePrivateProfileStringA("i",szkey,szvalue,m_szfilename);
	}
	int readinteger(char* szkey)
	{
		int iresult = GetPrivateProfileIntA("i", szkey, 0, m_szfilename);
		return iresult;
	}
private:
	char m_szfilename[255];
};