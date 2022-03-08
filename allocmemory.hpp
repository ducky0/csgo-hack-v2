

typedef void*(__fastcall *allocmemoryfn)(void*, void*, int);
allocmemoryfn org_allocmemory;

void* __fastcall hkallocmemory(void* ecx, void* edx, int size)
{
	if ((UINT)(_ReturnAddress()) == keyvaluesallocengine)
	{
		return nullptr;
	}

	if ((UINT)(_ReturnAddress()) == keyvaluesallocclient)
	{
		return nullptr;
	}

	return org_allocmemory(ecx, edx, size);
}
