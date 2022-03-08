

class cmouse
{
public:
	void update(int,int);
	bool leftclick(int,int,int,int);
	bool oneleftclick(int,int,int,int);
	bool isover(int,int,int,int);

	void drag(bool&,bool,bool,int&,int&,int&,int&);

	void getmouseposition(int &posx, int &posy)
	{
		posx = mouse_x;
		posy = mouse_y;
	}

	bool hasmouseonejustbeenreleased()
	{
		return mouse1released;
	}

	bool ismousetwobeingheld()
	{
		return mouse2pressed;
	}

	bool bdragged[3];
	int idiffx[3];
	int idiffy[3];

	int mouse_x, mouse_y;
private:
	bool mouse1pressed;
	bool mouse1released;
	bool mouse2pressed;
	bool mouse2released;
};

inline cmouse g_mouse;
