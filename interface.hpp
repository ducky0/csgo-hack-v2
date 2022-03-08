

inline engineclient* pengine;
inline entitylist* pentlist;
inline modelinfo* pmodel;
inline client* pclient;
inline enginetrace* penginetrace;
inline clientstate* pclientstate;
inline panel* ppanel;
inline surface* psurface;
inline servergame* pserver;
inline glowobj* pglowobj;
inline void* pkeyvalues;
inline UINT keyvaluesallocengine;
inline UINT keyvaluesallocclient;
inline UINT steamhook;

struct InterfaceNode
{
	void* (*fnGet)();
	const char* szName;
	InterfaceNode* pNext;
};

inline void* GetInterface(pe::module szModule, const char* szObject)
{
	uintptr_t ci = pe::getexport(szModule, ("CreateInterface"));

	const auto dwShortJmp = ci + 5;
	const auto dwJmp = (dwShortJmp + *reinterpret_cast<DWORD *>(dwShortJmp)) + 4;

	auto pList = **reinterpret_cast<InterfaceNode ***>(dwJmp + 6);

	while (pList)
	{
		if ((strstr(pList->szName, szObject)
			&& (strlen(pList->szName) - strlen(szObject)) < 5))
			return pList->fnGet();

		pList = pList->pNext;
	}

	return nullptr;
}

inline void initialiseinterfaces()
{
	pe::module m_client_dll = pe::getmodule("client.dll");
	pe::module m_engine_dll = pe::getmodule("engine.dll");
	pe::module m_overlay_dll = pe::getmodule("gameoverlayrenderer.dll");
	pe::module m_surface_dll = pe::getmodule("vguimatsurface.dll");
	pe::module m_vgui_dll = pe::getmodule("vgui2.dll");
	pe::module m_server_dll = pe::getmodule("server.dll");

	pserver = (servergame*)(GetInterface(m_server_dll, "ServerGameDLL"));
	pmodel = (modelinfo*)(GetInterface(m_engine_dll, "VModelInfoClient"));
	penginetrace = (enginetrace*)(GetInterface(m_engine_dll, "EngineTraceClient"));
	ppanel = (panel*)(GetInterface(m_vgui_dll, "VGUI_Panel"));
	pclient = (client*)(GetInterface(m_client_dll, "VClient"));
	pengine = (engineclient*)(GetInterface(m_engine_dll, "VEngineClient"));
	pentlist = (entitylist*)(GetInterface(m_client_dll, "VClientEntityList"));
	psurface = (surface*)(GetInterface(m_surface_dll, "VGUI_Surface"));

	pclientstate = **(clientstate***)((*(DWORD**)pengine)[20] + 1);

	pkeyvalues = reinterpret_cast<void* (__stdcall*)()>(pe::getexport(pe::getmodule("vstdlib.dll"),"KeyValuesSystem"))();

	pglowobj = *reinterpret_cast<glowobj**>(util::findpattern(m_client_dll, "\x0F\x11\x05????\x83\xC8\x01") + 3);
	keyvaluesallocengine = util::findpattern(m_engine_dll, "\xFF\x52\x04\x85\xC0\x74\x0C\x56") + 3;
	keyvaluesallocclient = util::findpattern(m_client_dll, "\xFF\x52\x04\x85\xC0\x74\x0C\x56") + 3;
	steamhook = util::findpattern(m_overlay_dll, "\x55\x8B\xEC\x51\x8B\x45\x10\xC7");
}
