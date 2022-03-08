

class classids
{
public:
	int getclassid(const char* classname)
	{
		serverclass * serverclass = pserver->getallserverclasses();

		int id = 0;

		while (serverclass)
		{
			if (!strcmp(serverclass->m_pnetworkname, classname))
				return id;
			serverclass = serverclass->m_pnext, id++;
		}

		return -1;
	}

	void initialize()
	{
		ceconwearable = getclassid("CEconWearable");
		ccsplayer = getclassid("CCSPlayer");
	}

public:
	int ceconwearable = -1;
	int ccsplayer = -1;
};

inline classids classid;