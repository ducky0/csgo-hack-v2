
struct coffsets
{
	struct
	{
		int m_aimpunchangle;
		int m_vecviewoffset;
		int m_ihealth;
		int m_lifestate;
		int m_hviewmodel;
	} dt_baseplayer;

	struct
	{
		int m_iteamnum;
		int m_vecmaxs;
		int m_cellz;
		int m_feffects;
		int m_clrrender;
	} dt_baseentity;

	struct
	{
		int m_hactiveweapon;
		int m_hmyweapons;
		int m_hmywearables;
	} dt_basecombatcharacter;

	struct
	{
		int m_biscontrollingbot;
	} dt_csplayer;

	struct
	{
		int m_iitemdefinitionindex;
		int m_iitemidhigh;
		int m_nfallbackpaintkit;
	} dt_baseattributableitem;

	struct
	{
		int m_nmodelindex;
	} dt_baseviewmodel;

	struct
	{
		int m_flnextprimaryattack;
		int m_iclip1;
	} dt_basecombatweapon;

	struct
	{
		int m_nforcebone;
	} dt_baseanimating;
};

namespace offsets
{
	void getoffsets();
}

inline coffsets xoffsets;
