#include "include.hpp"

std::vector<recvtable*> netvarmanager::gettables()
{
	std::vector<recvtable*> tables;

	clientclass* clientclass = pclient->getallclasses();
	if (!clientclass)
		return std::vector<recvtable*>();

	while (clientclass)
	{
		recvtable* recvtable = clientclass->gettable;
		tables.push_back(recvtable);

		clientclass = clientclass->nextclass;
	}

	return tables;
}

recvtable* netvarmanager::gettable(std::vector<recvtable*> tables, const char* tablename)
{
	if (tables.empty())
		return 0;

	for (unsigned long i = 0; i < tables.size(); i++)
	{
		recvtable* table = tables[i];

		if (!table)
			continue;

		if (strcmp(table->m_pnettablename, tablename) == 0)
			return table;
	}

	return 0;
}

int netvarmanager::getoffset(std::vector<recvtable*> tables, const char* tablename, const char* propname)
{
	int offset = get_prop(tables, tablename, propname);
	if (!offset)
		return 0;

	return offset;
}

int netvarmanager::get_prop(std::vector<recvtable*> tables, const char* tablename, const char* propname, recvprop** prop)
{
	recvtable* recvtable = gettable(tables, tablename);
	if (!recvtable)
		return 0;

	int offset = get_prop(tables, recvtable, propname, prop);
	if (!offset)
		return 0;

	return offset;
}

int netvarmanager::get_prop(std::vector<recvtable*> tables, recvtable* rrecvtable, const char* propname, recvprop** prop)
{
	int extraoffset = 0;

	for (int i = 0; i < rrecvtable->m_nprops; ++i) {
		recvprop* recvprop = &rrecvtable->m_pprops[i];
		recvtable* child = recvprop->m_pdatatable;

		if (child && (child->m_nprops > 0))
		{
			int tmp = get_prop(tables, child, propname, prop);
			if (tmp)
				extraoffset += (recvprop->m_offset + tmp);
		}

		if (strcmp(recvprop->m_pvarname, propname))
			continue;

		if (prop)
			*prop = recvprop;

		return (recvprop->m_offset + extraoffset);
	}

	return extraoffset;
}
