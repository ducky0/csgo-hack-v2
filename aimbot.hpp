

class aimbot
{
public:
	void main(entities*);
	void main_rcs(entities*);
private:
	bool isvisible(vector&, vector&, entities*, entities*);
	bool gethitboxpos(entities*, entities*, vector&);

	void reset()
	{
		itarget = -1;
		fbesttarget = 99999.9f;
		vtarget.zero();
		vfinal.zero();
	}

	void resetrcs()
	{
		ircstarget = -1;
		fbestrcstarget = 99999.9f;
		vrcstarget.zero();
		vrcsfinal.zero();
	}

	bool hastarget()
	{
		return (itarget != -1);
	}

	bool hastargetrcs()
	{
		return (ircstarget != -1);
	}

	int itarget;
	int ircstarget;

	float fbesttarget;
	float fbestrcstarget;

	vector vtarget;
	vector vrcstarget;

	vector vfinal;
	vector vrcsfinal;

	vector veyepos;
	vector viewangel;
};

inline aimbot g_aimbot;