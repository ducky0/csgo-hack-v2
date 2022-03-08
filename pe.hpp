


struct peb_ldr_data
{
	uint32_t		length;
	uint8_t			initialized;
	uintptr_t		sshandle;
	LIST_ENTRY		inloadordermodulelist;
	LIST_ENTRY		inmemoryordermodulelist;
	LIST_ENTRY		ininitializationordermodulelist;
	uintptr_t		entryinprogress;
	uint8_t			shutdowninprogress;
	uintptr_t		shutdownthreadid;
};

struct unicode_string
{
	uint16_t	length;
	uint16_t	maximumlength;
	wchar_t		*buffer;
};

struct string
{
	uint16_t	length;
	uint16_t	maximumlength;
	char		*buffer;
};

struct curdir
{
	unicode_string	dospath;
	uintptr_t		handle;
};

struct rtl_drive_letter_curdir
{
	uint16_t	flags;
	uint16_t	length;
	uint32_t	timestamp;
	string		dospath;
};

struct rtl_user_process_parameters
{
	uint32_t					maximumlength;
	uint32_t					length;
	uint32_t					flags;
	uint32_t					debugflags;
	uintptr_t					consolehandle;
	uint32_t					consoleflags;
	uintptr_t					standardinput;
	uintptr_t					standardoutput;
	uintptr_t					standarderror;
	curdir						currentdirectory;
	unicode_string				dllpath;
	unicode_string				imagepathname;
	unicode_string				commandline;
	uintptr_t					environment;
	uint32_t					startingx;
	uint32_t					startingy;
	uint32_t					countx;
	uint32_t					county;
	uint32_t					countcharsx;
	uint32_t					countcharsy;
	uint32_t					fillattribute;
	uint32_t					windowflags;
	uint32_t					showwindowflags;
	unicode_string				windowtitle;
	unicode_string				desktopinfo;
	unicode_string				shellinfo;
	unicode_string				runtimedata;
	rtl_drive_letter_curdir		currentdirectores[32];
	uintptr_t					environmentsize;
	uintptr_t					environmentversion;
	uintptr_t					packagedependencydata;
	uint32_t					processgroupid;
	uint32_t					loaderthreads;
};

struct rtl_balanced_node
{
	rtl_balanced_node	*children[2];
	rtl_balanced_node	*left;
	rtl_balanced_node	*right;
	uintptr_t			parentvalue;
};

struct _peb
{
	uint8_t							inheritedaddressspace;
	uint8_t							readimagefileexecoptions;
	uint8_t							beingdebugged;
	uint8_t							bitfield;
	uintptr_t						mutant;
	uintptr_t						imagebaseaddress;
	peb_ldr_data					*ldr;
	rtl_user_process_parameters		*processparameters;
	uintptr_t						subsystemdata;
	uintptr_t						processheap;
	RTL_CRITICAL_SECTION			*fastpeblock;
	uintptr_t						atlthunkslistptr;
	uintptr_t						ifeokey;
	uint32_t						crossprocessflags;
	uint8_t							padding1[4];
	uintptr_t						kernelcallbacktable;
	uintptr_t						usersharedinfoptr;
	uint32_t						systemreserved[1];
	uint32_t						atlthunkslistptr32;
	uintptr_t						apisetmap;
	uint32_t						tlsexpansioncounter;
	uint8_t							padding2[4];
	uintptr_t						tlsbitmap;
	uint32_t						tlsbitmapbits[2];
	uintptr_t						readonlysharedmemorybase;
	uintptr_t						sparepvoid0;
	uintptr_t						readonlystaticserverdata;
	uintptr_t						ansicodepagedata;
	uintptr_t						oemcodepagedata;
	uintptr_t						unicodecasetabledata;
	uint32_t						numberofprocessors;
	uint32_t						ntglobalflag;
	LARGE_INTEGER					criticalsectiontimeout;
	uintptr_t						heapsegmentreserve;
	uintptr_t						heapsegmentcommit;
	uintptr_t						heapdecommittotalfreethreshold;
	uintptr_t						heapdecommitfreeblockthreshold;
	uint32_t						numberofheaps;
	uint32_t						maximumnumberofheaps;
	uintptr_t						processheaps;
	uintptr_t						gdisharedhandletable;
	uintptr_t						processstarterhelper;
	uint32_t						gdidcattributelist;
	uint8_t							padding3[4];
	RTL_CRITICAL_SECTION			*loaderlock;
	uint32_t						osmajorversion;
	uint32_t						osminorversion;
	uint16_t						osbuildnumber;
	uint16_t						oscsdversion;
	uint32_t						osplatformid;
	uint32_t						imagesubsystem;
	uint32_t						imagesubsystemmajorversion;
	uint32_t						imagesubsystemminorversion;
	uint8_t							padding4[4];
	uintptr_t						activeprocessaffinitymask;
	uint32_t						gdihandlebuffer[34];
	uintptr_t						postprocessinitroutine;
	uintptr_t						tlsexpansionbitmap;
	uint32_t						tlsexpansionbitmapbits[32];
	uint32_t						sessionid;
	uint8_t							padding5[4];
	ULARGE_INTEGER					appcompatflags;
	ULARGE_INTEGER					appcompatflagsuser;
	uintptr_t						pshimdata;
	uintptr_t						appcompatinfo;
	unicode_string					csdversion;
	uintptr_t						activationcontextdata;
	uintptr_t						processassemblystoragemap;
	uintptr_t						systemdefaultactivationcontextdata;
	uintptr_t						systemassemblystoragemap;
	uintptr_t						minimumstackcommit;
	uintptr_t						flscallback;
	LIST_ENTRY						flslisthead;
	uintptr_t						flsbitmap;
	uint32_t						flsbitmapbits[4];
	uint32_t						flshighindex;
	uintptr_t						werregistrationdata;
	uintptr_t						wershipassertptr;
	uintptr_t						punused;
	uintptr_t						pimageheaderhash;
	uint32_t						tracingflags;
	uint8_t							padding6[4];
	uint64_t						csrserverreadonlysharedmemorybase;
	uintptr_t						tppworkerplistlock;
	LIST_ENTRY						tppworkerplist;
	uintptr_t						waitonaddresshashtable[128];
};

struct LDR_DATA_TABLE_ENTRY
{
	LIST_ENTRY				inloadorderlinks;
	LIST_ENTRY				inmemoryorderlinks;
	LIST_ENTRY				ininitializationorderlinks;
	uintptr_t				dllbase;
	uintptr_t				entrypoint;
	uint32_t				SizeOfImage;
	unicode_string			fulldllname;
	unicode_string			BaseDllName;
	uint8_t					flaggroup[4];
	uint32_t				flags;
	uint16_t				obsoleteloadcount;
	uint16_t				tlsindex;
	LIST_ENTRY				hashlinks;
	uint32_t				timedatestamp;
	uintptr_t				entrypointactivationcontext;
	uintptr_t				lock;
	uintptr_t				ddagnode;
	LIST_ENTRY				nodemodulelink;
	uintptr_t				loadcontext;
	uintptr_t				parentdllbase;
	uintptr_t				switchbackcontext;
	rtl_balanced_node		baseaddressindexnode;
	rtl_balanced_node		mappinginfoindexnode;
	uintptr_t				originalbase;
	LARGE_INTEGER			loadtime;
	uint32_t				basenamehashvalue;
	uint32_t				loadreason;
	uint32_t				implicitpathoptions;
	uint32_t				referencecount;
};