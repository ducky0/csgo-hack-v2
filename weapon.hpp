
inline int g_weaponid;

enum weaponindx
{
	weapon_deagle = 1,
	weapon_duals = 2,
	weapon_five7 = 3,
	weapon_glock = 4,
	weapon_ak47 = 7,
	weapon_aug = 8,
	weapon_awp = 9,
	weapon_famas = 10,
	weapon_g3sg1 = 11,
	weapon_galil = 13,
	weapon_m249 = 14,
	weapon_m4a1 = 16,
	weapon_mac10 = 17,
	weapon_p90 = 19,
	weapon_mp5sd = 23,
	weapon_ump45 = 24,
	weapon_xm1014 = 25,
	weapon_bizon = 26,
	weapon_mag7 = 27,
	weapon_negev = 28,
	weapon_sawedoff = 29,
	weapon_tec9 = 30,
	weapon_p2000 = 32,
	weapon_mp7 = 33,
	weapon_mp9 = 34,
	weapon_nova = 35,
	weapon_p250 = 36,
	weapon_scar20 = 38,
	weapon_sg553 = 39,
	weapon_scout = 40,
	weapon_knife_t = 42,
	weapon_knife_ct = 59,
	weapon_m4a1s = 60,
	weapon_usps = 61,
	weapon_cz75 = 63,
	weapon_revolver = 64,
	weapon_bayonet = 500,
	weapon_knife_flip = 505,
	weapon_knife_gut = 506,
	weapon_knife_karambit = 507,
	weapon_knife_m9bayonet = 508,
	glove_studded_bloodhound = 5027,
	glove_sporty = 5030,
	glove_slick = 5031,
	glove_leather_wrap = 5032,
	glove_motorcycle = 5033,
	glove_specialist = 5034
};

inline bool isrecoilwep(int iwpnid)
{
	return (iwpnid == weapon_ak47
		|| iwpnid == weapon_aug
		|| iwpnid == weapon_famas
		|| iwpnid == weapon_galil
		|| iwpnid == weapon_m249
		|| iwpnid == weapon_cz75
		|| iwpnid == weapon_m4a1
		|| iwpnid == weapon_mac10
		|| iwpnid == weapon_p90
		|| iwpnid == weapon_mp5sd
		|| iwpnid == weapon_ump45
		|| iwpnid == weapon_bizon
		|| iwpnid == weapon_negev
		|| iwpnid == weapon_mp7
		|| iwpnid == weapon_mp9
		|| iwpnid == weapon_sg553
		|| iwpnid == weapon_duals
		|| iwpnid == weapon_m4a1s);
}

inline bool isaimwep(int iwpnid)
{
	return (iwpnid == weapon_deagle
		|| iwpnid == weapon_five7
		|| iwpnid == weapon_glock
		|| iwpnid == weapon_awp
		|| iwpnid == weapon_g3sg1
		|| iwpnid == weapon_mag7
		|| iwpnid == weapon_sawedoff
		|| iwpnid == weapon_xm1014
		|| iwpnid == weapon_tec9
		|| iwpnid == weapon_p2000
		|| iwpnid == weapon_nova
		|| iwpnid == weapon_p250
		|| iwpnid == weapon_scar20
		|| iwpnid == weapon_scout
		|| iwpnid == weapon_usps
		|| iwpnid == weapon_revolver);
}

inline bool isweaponknife(int iwpnid)
{
	if (iwpnid == weapon_knife_t || iwpnid == weapon_knife_ct)
		return true;

	if (iwpnid == weapon_bayonet || iwpnid == weapon_knife_flip)
		return true;

	if (iwpnid == weapon_knife_gut || iwpnid == weapon_knife_karambit)
		return true;

	if (iwpnid == weapon_knife_m9bayonet)
		return true;

	return false;
}

inline char * getweaponname(int id)
{
	switch (id)
	{
	case weapon_deagle:
		return "deagle";
	case weapon_duals:
		return "berettas";
	case weapon_five7:
		return "five-seven";
	case weapon_glock:
		return "glock-18";
	case weapon_ak47:
		return "ak-47";
	case weapon_aug:
		return "aug";
	case weapon_awp:
		return "awp";
	case weapon_famas:
		return "famas";
	case weapon_g3sg1:
		return "g3sg1";
	case weapon_galil:
		return "galil";
	case weapon_m249:
		return "m249";
	case weapon_m4a1:
		return "m4a1";
	case weapon_mac10:
		return "mac-10";
	case weapon_p90:
		return "p90";
	case weapon_ump45:
		return "ump-45";
	case weapon_xm1014:
		return "xm1014";
	case weapon_bizon:
		return "pp-bizon";
	case weapon_mag7:
		return "mag-7";
	case weapon_negev:
		return "negev";
	case weapon_sawedoff:
		return "sawed-off";
	case weapon_tec9:
		return "tec-9";
	case weapon_p2000:
		return "p2000";
	case weapon_mp7:
		return "mp7";
	case weapon_mp9:
		return "mp9";
	case weapon_nova:
		return "nova";
	case weapon_p250:
		return "p250";
	case weapon_scar20:
		return "scar-20";
	case weapon_sg553:
		return "sg 553";
	case weapon_scout:
		return "ssg 08";
	case weapon_knife_ct:
		return "knife";
	case weapon_knife_t:
		return "knife";
	case weapon_m4a1s:
		return "m4a1-s";
	case weapon_usps:
		return "usp-s";
	case weapon_cz75:
		return "cz75-auto";
	case weapon_revolver:
		return "r8 revolver";
	case weapon_mp5sd:
		return "mp5-sd";
	default:
		return "knife";
	}

	return "";
}