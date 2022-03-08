#include "include.hpp"


void cmouse::drag(bool& bdrag, bool bcheck, bool bdragcheck,int& x, int& y, int& xdif, int& ydif)
{
	if(bcheck)								  
	{					
		if(bdragcheck || (mouse1pressed && bdrag))		  
		{
			if(!bdrag)					  
				bdrag = true;

			if(xdif == -1 || ydif == -1)	  
			{							
				xdif = mouse_x - x;	  
				ydif = mouse_y - y;	  
			}

			x += mouse_x - (xdif + x); 
			y += mouse_y - (ydif + y); 
		}									  
		else								  
		{			
			if(bdrag)
				bdrag = false;

			xdif = -1;						  
			ydif = -1;						  
		}									  
	}
}

bool cmouse::leftclick(int x,int y,int w,int h)
{
	return (mouse1pressed && isover(x,y,w,h));
}

bool cmouse::oneleftclick(int x,int y,int w,int h)
{
	return (mouse1released && isover(x,y,w,h));
}

bool cmouse::isover(int x,int y,int w,int h)
{
	return (mouse_x > x  && w+x > mouse_x && mouse_y > y  && h+y > mouse_y);
}

void cmouse::update(int width, int height)
{
	psurface->surfacegetcursorpos(mouse_x, mouse_y);

	if (mouse_x > width)
		mouse_x = width;

	if (mouse_x < 0)
		mouse_x = 0;

	if (mouse_y > height)
		mouse_y = height;

	if (mouse_y < 0)
		mouse_y = 0;

	if (GetAsyncKeyState(VK_LBUTTON))
		mouse1pressed = true;

	else if (!GetAsyncKeyState(VK_LBUTTON))
	{
		if (mouse1pressed)
			mouse1released = true;
		else
			mouse1released = false;

		mouse1pressed = false;
	}

	if (GetAsyncKeyState(VK_RBUTTON))
		mouse2pressed = true;
	else if (!GetAsyncKeyState(VK_RBUTTON))
	{
		if (mouse2pressed)
			mouse2released = true;
		else
			mouse2released = false;

		mouse2pressed = false;
	}
}