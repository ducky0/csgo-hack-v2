


#include "include.hpp"

void offsets::getoffsets()
{
	std::vector<recvtable *> tables = netvarmanager::gettables();

	xoffsets.dt_baseplayer.m_aimpunchangle = netvarmanager::getoffset(tables, "DT_BasePlayer", "m_aimPunchAngle");
	xoffsets.dt_baseplayer.m_vecviewoffset = netvarmanager::getoffset(tables, "DT_BasePlayer", "m_vecViewOffset[0]");
	xoffsets.dt_baseplayer.m_ihealth = netvarmanager::getoffset(tables, "DT_BasePlayer", "m_iHealth");
	xoffsets.dt_baseplayer.m_lifestate = netvarmanager::getoffset(tables, "DT_BasePlayer", "m_lifeState");
	xoffsets.dt_baseentity.m_iteamnum = netvarmanager::getoffset(tables, "DT_BaseEntity", "m_iTeamNum");
	xoffsets.dt_basecombatcharacter.m_hactiveweapon = netvarmanager::getoffset(tables, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	xoffsets.dt_basecombatcharacter.m_hmyweapons = netvarmanager::getoffset(tables, "DT_BaseCombatCharacter", "m_hMyWeapons") / 2;
	xoffsets.dt_basecombatcharacter.m_hmywearables = netvarmanager::getoffset(tables, "DT_BaseCombatCharacter", "m_hMyWearables");
	xoffsets.dt_baseattributableitem.m_iitemdefinitionindex = netvarmanager::getoffset(tables, "DT_BaseAttributableItem", "m_iItemDefinitionIndex");
	xoffsets.dt_baseattributableitem.m_iitemidhigh = netvarmanager::getoffset(tables, "DT_BaseAttributableItem", "m_iItemIDHigh");
	xoffsets.dt_baseattributableitem.m_nfallbackpaintkit = netvarmanager::getoffset(tables, "DT_BaseAttributableItem", "m_nFallbackPaintKit");
	xoffsets.dt_baseviewmodel.m_nmodelindex = netvarmanager::getoffset(tables, "DT_BaseViewModel", "m_nModelIndex");
	xoffsets.dt_basecombatweapon.m_flnextprimaryattack = netvarmanager::getoffset(tables, "DT_BaseCombatWeapon", "m_flNextPrimaryAttack");
	xoffsets.dt_basecombatweapon.m_iclip1 = netvarmanager::getoffset(tables, "DT_BaseCombatWeapon", "m_iClip1");
	xoffsets.dt_baseanimating.m_nforcebone = netvarmanager::getoffset(tables, "DT_BaseAnimating", "m_nForceBone");
	xoffsets.dt_baseplayer.m_hviewmodel = netvarmanager::getoffset(tables, "DT_BasePlayer", "m_hViewModel[0]");
	xoffsets.dt_baseentity.m_vecmaxs = netvarmanager::getoffset(tables, "DT_BaseEntity", "m_vecMaxs");
	xoffsets.dt_csplayer.m_biscontrollingbot = netvarmanager::getoffset(tables, "DT_CSPlayer", "m_bIsControllingBot");
	xoffsets.dt_baseentity.m_cellz = netvarmanager::getoffset(tables, "DT_BaseEntity", "m_cellZ");
	xoffsets.dt_baseentity.m_feffects = netvarmanager::getoffset(tables, "DT_BaseEntity", "m_fEffects");
	xoffsets.dt_baseentity.m_clrrender = netvarmanager::getoffset(tables, "DT_BaseEntity", "m_clrRender");
}
