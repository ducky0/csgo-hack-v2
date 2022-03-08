

namespace netvarmanager
{
	std::vector<recvtable*> gettables();
	recvtable* gettable(std::vector<recvtable*>,const char* );
	int getoffset(std::vector<recvtable*>,const char*,const char*);
	int get_prop(std::vector<recvtable*>,const char*,const char*,recvprop** prop = 0);
	int get_prop(std::vector<recvtable*>,recvtable*,const char*,recvprop** prop = 0);
}
