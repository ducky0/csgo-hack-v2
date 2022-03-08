

inline int iscreenheight;
inline int iscreenwidth;

namespace draw
{
	inline void fillrgba(int x, int y, int w, int h, int r, int g, int b, int a)
	{
		psurface->drawsetcolor(r, g, b, a);
		psurface->drawfilledrect(x, y, x + w, y + h);
	}

	inline void outlinedrectangle(int x, int y, int w, int h, int r, int g, int b, int a)
	{
		fillrgba(x + 2, y, w - 3, 1, r, g, b, a);
		fillrgba(x + 1, y + 1, 1, 1, r, g, b, a);
		fillrgba(x, y + 2, 1, h - 3, r, g, b, a);
		fillrgba(x + 1, y + h - 1, 1, 1, r, g, b, a);
		fillrgba(x + w, y + 2, 1, h - 3, r, g, b, a);
		fillrgba(x + w - 1, y + 1, 1, 1, r, g, b, a);
		fillrgba(x + 2, y + h, w - 3, 1, r, g, b, a);
		fillrgba(x + w - 1, y + h - 1, 1, 1, r, g, b, a);
	}

	inline void renderline(int x, int y, int w, int h, int r, int g, int b, int a)
	{
		psurface->drawsetcolor(r, g, b, a);
		psurface->drawline(x, y, w, h);
	}

	inline void outlinedrgba(int x, int y, int w, int h, int r, int g, int b, int a)
	{
		psurface->drawsetcolor(r, g, b, a);
		psurface->drawoutlinewdrect(x, y, x + w, y + h);
	}

	inline void drawheader(int x, int y, int w, int width, int r, int g, int b, int a)
	{
		int i = 0;
		int xcoord = x;
		int ycoord = y;

		for (i = 0; i < 5; i++)
		{
			fillrgba(x - i, y + i, w, 1, 0, 0, 0, a);
			fillrgba(x - i, y + i, width + 2, 1, r, g, b, a);

			fillrgba(x - 3, y + 3, width + 2, 1, (int)(r / 1.5f),
				(int)(g / 1.5f), (int)(b / 1.5f), a);

			fillrgba(x - 4, y + 4, width + 2, 1, (int)(r / 1.5f),
				(int)(g / 1.5f), (int)(b / 1.5f), a);
		}

		fillrgba(x, y, w, 1, 255, 255, 255, a);

		fillrgba((x + 1) - 5, y + 5, w, 1, 255, 255, 255, a);

		for (i = 0; i < 5; i++)
		{
			fillrgba(x, y, 1, 1, 255, 255, 255, a);
			x--;
			y++;
		}

		x = xcoord;
		y = ycoord;

		for (i = 0; i < 5; i++)
		{
			if (i != 0)
				fillrgba(x + w, y, 1, 1, 255, 255, 255, a);

			x--;
			y++;
		}
	}

	inline static bool screen_transform(const vector& in, vector& out)
	{
		static auto& w2smatrix = pengine->worldtoscreenmatrix();

		out.x = w2smatrix.m[0][0] * in.x + w2smatrix.m[0][1] * in.y + w2smatrix.m[0][2] * in.z + w2smatrix.m[0][3];
		out.y = w2smatrix.m[1][0] * in.x + w2smatrix.m[1][1] * in.y + w2smatrix.m[1][2] * in.z + w2smatrix.m[1][3];
		out.z = 0.0f;

		float w = w2smatrix.m[3][0] * in.x + w2smatrix.m[3][1] * in.y + w2smatrix.m[3][2] * in.z + w2smatrix.m[3][3];

		if (w < 0.001f)
		{
			out.x *= 100000;
			out.y *= 100000;
			return false;
		}

		out.x /= w;
		out.y /= w;

		return true;
	}

	inline bool worldtoscreen(const vector& in, vector& out)
	{
		if (screen_transform(in, out))
		{
			out.x = (iscreenwidth / 2.0f) + (out.x * iscreenwidth) / 2.0f;
			out.y = (iscreenheight / 2.0f) - (out.y * iscreenheight) / 2.0f;

			return true;
		}
		return false;
	}
}