


namespace steam_hooker
{
	inline UINT setuphook(PVOID _class, UINT index)
	{
		return static_cast<UINT>((*reinterpret_cast<int**>(_class))[index]);
	}

	inline PVOID hookfunc(PVOID func, PVOID hook, PVOID org)
	{
		typedef PVOID(__cdecl* proxy_function)(PVOID, PVOID, PVOID, int);
		proxy_function do_hook_fn = (proxy_function)steamhook;

		return do_hook_fn(func,hook,org,0);
	}
}