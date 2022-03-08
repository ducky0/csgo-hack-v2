

namespace font
{
	inline void pixel(int x, int y, int w, int h, int r, int g, int b, int a)
	{
		draw::fillrgba(x, y, w, h, r, g, b, a);
	}

	inline int igetwidth(const char *pinput, ...)
	{
		char buf[256];
		va_list arguments;

		va_start(arguments, pinput);
		vsprintf(buf, pinput, arguments);
		va_end(arguments);

		int len = 0;

		for (int i = 0; i < sizeof(buf); i++)
		{
			if (buf[i] == '\0')
			{
				return len;
			}
			else if (buf[i] == 'a' || buf[i] == 'A' || buf[i] == 'b' || buf[i] == 'B' || buf[i] == '8' || buf[i] == 'c' || buf[i] == 'C' || buf[i] == 'd' || buf[i] == 'D' || buf[i] == 'e' || buf[i] == 'E' || buf[i] == 'f' || buf[i] == 'F' || buf[i] == 'g' || buf[i] == 'G' || buf[i] == 'h' || buf[i] == 'H' || buf[i] == 'j' || buf[i] == 'J' || buf[i] == 'k' || buf[i] == 'K' || buf[i] == 'l' || buf[i] == 'L' || buf[i] == 'n' || buf[i] == 'N' || buf[i] == 'o' || buf[i] == 'O' || buf[i] == '0' || buf[i] == 'p' || buf[i] == 'P' || buf[i] == 'r' || buf[i] == 'R' || buf[i] == 's' || buf[i] == 'S' || buf[i] == '5' || buf[i] == 'u' || buf[i] == 'U' || buf[i] == 'v' || buf[i] == 'V' || buf[i] == 'x' || buf[i] == 'X' || buf[i] == 'y' || buf[i] == 'Y' || buf[i] == 'z' || buf[i] == 'Z' || buf[i] == '2' || buf[i] == '3' || buf[i] == '4' || buf[i] == '6' || buf[i] == '7' || buf[i] == '9' || buf[i] == '-' || buf[i] == '_')
			{
				len += 6;
			}
			else if (buf[i] == 'm' || buf[i] == 'M' || buf[i] == 'q' || buf[i] == 'Q' || buf[i] == 'w' || buf[i] == 'W' || buf[i] == '+')
			{
				len += 7;
			}
			else if (buf[i] == 'i' || buf[i] == 'I' || buf[i] == '1' || buf[i] == 't' || buf[i] == 'T' || buf[i] == '' || buf[i] == '.' || buf[i] == ',' || buf[i] == ':' || buf[i] == ';' || buf[i] == '!' || buf[i] == '/' || buf[i] == '(' || buf[i] == ')' || buf[i] == '[' || buf[i] == ']')
			{
				len += 5;
			}
			else if (buf[i] == ' ')
			{
				len += 4;
			}
		}
		return len;
	}

	inline void drawstring(int x, int y, int r, int g, int b, int a, bool bcenter, const char *pinput, ...)
	{
		y = y + 2;

		char buf[256];
		va_list arguments;

		va_start(arguments, pinput);
		vsprintf(buf, pinput, arguments);
		va_end(arguments);

		if (bcenter)
		{
			int ilength;
			ilength = igetwidth(buf);
			x = x - ilength * 0.5;
		}

		int oldX = x;

		int bg_r, bg_g, bg_b;

		if (r == 0 && g == 0 && b == 0)
		{
			bg_r = 180;
			bg_g = 180;
			bg_b = 180;
		}
		else
		{
			bg_r = 0;
			bg_g = 0;
			bg_b = 0;
		}

		for (int i = 0; i < sizeof(buf); i++)
		{
			if (buf[i] == '\0')
				return;
			else if (buf[i] == ' ')
				x += 4;
			if (buf[i] == '\n') {
				y += 11;
				x = oldX;
			}
			else if (buf[i] == 'a' || buf[i] == 'A')
			{
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 4, y + 2, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '@') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, 190, 0, 0, 255);
				pixel(x + 2, y + 3, 2, 1, 190, 0, 0, 255);
				pixel(x + 1, y + 2, 1, 4, 190, 0, 0, 255);
				pixel(x + 4, y + 2, 1, 4, 190, 0, 0, 255);
				x += 6;
			}
			else if (buf[i] == 'b' || buf[i] == 'B' || buf[i] == '8') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'c' || buf[i] == 'C') {
				pixel(x, y, 6, 3, bg_r, bg_g, bg_b, a);
				pixel(x, y + 3, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 4, 6, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'd' || buf[i] == 'D') {
				pixel(x, y, 5, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 5, y + 1, 1, 5, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 1, r, g, b, a);
				pixel(x + 1, y + 5, 3, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'e' || buf[i] == 'E') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 3, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'f' || buf[i] == 'F') {
				pixel(x, y, 6, 5, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 3, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'g' || buf[i] == 'G') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 3, y + 3, 1, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				pixel(x + 4, y + 3, 1, 2, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'h' || buf[i] == 'H') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 5, r, g, b, a);
				pixel(x + 4, y + 1, 1, 5, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'i' || buf[i] == 'I') {
				pixel(x, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 3, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 4, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 1, r, g, b, a);
				pixel(x + 1, y + 5, 3, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 3, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '1') {
				pixel(x, y, 4, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 3, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 4, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 3, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 3, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '|') {
				pixel(x, y, 3, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 1, 5, r, g, b, a);
				x += 3;
			}
			else if (buf[i] == 'j' || buf[i] == 'J') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 4, 1, 1, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'k' || buf[i] == 'K') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 5, r, g, b, a);
				pixel(x + 4, y + 3, 1, 3, r, g, b, a);
				pixel(x + 4, y + 1, 1, 1, r, g, b, a);
				pixel(x + 3, y + 2, 1, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'l' || buf[i] == 'L') {
				pixel(x, y, 3, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 4, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 1, 4, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'm' || buf[i] == 'M') {
				pixel(x, y, 7, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 5, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 3, y + 2, 1, 4, r, g, b, a);
				pixel(x + 5, y + 2, 1, 4, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == 'n' || buf[i] == 'N') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 4, y + 2, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'o' || buf[i] == 'O' || buf[i] == '0') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'p' || buf[i] == 'P') {
				pixel(x, y, 3, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y, 3, 5, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 4, y + 2, 1, 2, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'q' || buf[i] == 'Q') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 6, y + 5, 1, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 4, y + 7, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				pixel(x + 3, y + 4, 1, 1, r, g, b, a);
				pixel(x + 5, y + 6, 1, 1, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == 'r' || buf[i] == 'R') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 4, y + 2, 1, 1, r, g, b, a);
				pixel(x + 3, y + 4, 2, 1, r, g, b, a);
				pixel(x + 4, y + 5, 1, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 's' || buf[i] == 'S' || buf[i] == '5') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 2, r, g, b, a);
				pixel(x + 4, y + 3, 1, 2, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 't' || buf[i] == 'T') {
				pixel(x, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 3, 3, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 4, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == 'u' || buf[i] == 'U') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 4, r, g, b, a);
				pixel(x + 4, y + 1, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'v' || buf[i] == 'V') {
				pixel(x, y, 6, 6, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 6, 4, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 5, 2, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 4, r, g, b, a);
				pixel(x + 4, y + 1, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'w' || buf[i] == 'W') {
				pixel(x, y, 7, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 5, 5, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 4, r, g, b, a);
				pixel(x + 3, y + 1, 1, 4, r, g, b, a);
				pixel(x + 5, y + 1, 1, 4, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == 'x' || buf[i] == 'X') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 2, r, g, b, a);
				pixel(x + 4, y + 1, 1, 2, r, g, b, a);
				pixel(x + 1, y + 4, 1, 2, r, g, b, a);
				pixel(x + 4, y + 4, 1, 2, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'y' || buf[i] == 'Y') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 3, r, g, b, a);
				pixel(x + 4, y + 1, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '2') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 3, 1, 2, r, g, b, a);
				pixel(x + 4, y + 2, 1, 2, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == 'z' || buf[i] == 'Z') {
				pixel(x, y, 6, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 2, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x, y + 4, 6, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 4, y + 2, 1, 1, r, g, b, a);
				pixel(x + 3, y + 3, 1, 1, r, g, b, a);
				pixel(x + 2, y + 4, 1, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '3') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 3, 3, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '&') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y - 1, 3, 9, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 1, y + 3, 3, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				pixel(x + 2, y, 1, 7, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '4') {
				pixel(x, y, 6, 5, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 3, r, g, b, a);
				pixel(x + 4, y + 1, 1, 5, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '6') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 3, r, g, b, a);
				pixel(x + 4, y + 3, 1, 2, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '7') {
				pixel(x, y, 6, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 3, 5, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 4, y + 2, 1, 4, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '9') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 2, r, g, b, a);
				pixel(x + 4, y + 2, 1, 3, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '.') {
				pixel(x + 1, y + 4, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 5, 1, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == ',') {
				pixel(x + 1, y + 4, 3, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 5, 1, 2, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == ':') {
				pixel(x + 1, y + 1, 3, 6, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 2, 1, 1, r, g, b, a);
				pixel(x + 2, y + 5, 1, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == ';') {
				pixel(x + 1, y + 1, 3, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 2, 1, 1, r, g, b, a);
				pixel(x + 2, y + 5, 1, 2, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '!') {
				pixel(x + 1, y, 3, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 1, 1, 3, r, g, b, a);
				pixel(x + 2, y + 5, 1, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '\\') {
				pixel(x, y, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 2, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 4, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 6, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 1, 2, r, g, b, a);
				pixel(x + 2, y + 3, 1, 2, r, g, b, a);
				pixel(x + 3, y + 5, 1, 2, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '/') {
				pixel(x + 2, y, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 2, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 4, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 6, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 1, 1, 2, r, g, b, a);
				pixel(x + 2, y + 3, 1, 2, r, g, b, a);
				pixel(x + 1, y + 5, 1, 2, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '(') {
				pixel(x + 1, y, 4, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 1, 5, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 5, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 7, 4, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 1, 2, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 2, y + 6, 2, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == ')') {
				pixel(x, y, 4, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 1, 5, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 5, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 7, 4, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 2, 1, r, g, b, a);
				pixel(x + 3, y + 2, 1, 4, r, g, b, a);
				pixel(x + 1, y + 6, 2, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '[') {
				pixel(x, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 4, r, g, b, a);
				pixel(x + 1, y + 6, 3, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == ']') {
				pixel(x, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 1, r, g, b, a);
				pixel(x + 3, y + 2, 1, 4, r, g, b, a);
				pixel(x + 1, y + 6, 3, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '{') {
				pixel(x + 1, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 5, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x, y + 2, 3, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 1, 3, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 4, r, g, b, a);
				pixel(x + 1, y + 3, 1, 2, r, g, b, a);
				pixel(x + 2, y + 6, 3, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '}') {
				pixel(x, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 2, 3, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 1, r, g, b, a);
				pixel(x + 3, y + 2, 1, 4, r, g, b, a);
				pixel(x + 4, y + 3, 1, 2, r, g, b, a);
				pixel(x + 1, y + 6, 3, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '-') {
				pixel(x + 1, y + 2, 4, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '>') {
				pixel(x, y, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 1, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 2, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 4, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 6, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 3, 1, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 1, r, g, b, a);
				pixel(x + 1, y + 1, 1, 1, r, g, b, a);
				pixel(x + 2, y + 4, 1, 1, r, g, b, a);
				pixel(x + 1, y + 5, 1, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '<') {
				pixel(x + 2, y, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 2, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 4, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 6, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 3, 1, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 1, r, g, b, a);
				pixel(x + 3, y + 1, 1, 1, r, g, b, a);
				pixel(x + 2, y + 4, 1, 1, r, g, b, a);
				pixel(x + 3, y + 5, 1, 1, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '^') {
				pixel(x + 2, y, 3, 1, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 5, 1, bg_r, bg_g, bg_b, a);
				pixel(x, y + 2, 7, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 4, y + 3, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 1, 1, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 1, r, g, b, a);
				pixel(x + 4, y + 2, 1, 1, r, g, b, a);
				pixel(x + 1, y + 3, 1, 1, r, g, b, a);
				pixel(x + 5, y + 3, 1, 1, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == '$') {
				pixel(x, y, 6, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y - 1, 3, 9, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 4, 1, r, g, b, a);
				pixel(x + 2, y + 3, 2, 1, r, g, b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				pixel(x + 1, y + 2, 1, 2, r, g, b, a);
				pixel(x + 4, y + 3, 1, 2, r, g, b, a);
				pixel(x + 2, y, 1, 7, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '=') {
				pixel(x, y + 1, 6, 5, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 2, 4, 1, r, g, b, a);
				pixel(x + 1, y + 4, 4, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '#') {
				pixel(x + 1, y + 1, 7, 5, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y, 5, 7, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 2, 5, 1, r, g, b, a);
				pixel(x + 2, y + 4, 5, 1, r, g, b, a);
				pixel(x + 3, y + 1, 1, 5, r, g, b, a);
				pixel(x + 5, y + 1, 1, 5, r, g, b, a);
				x += 8;
			}
			else if (buf[i] == '_') {
				pixel(x, y + 4, 6, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 5, 4, 1, r, g, b, a);
				x += 6;
			}
			else if (buf[i] == '+') {
				pixel(x + 2, y, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 2, 7, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 1, 1, 2, r, g, b, a);
				pixel(x + 1, y + 3, 5, 1, r, g, b, a);
				pixel(x + 3, y + 4, 1, 2, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == '\'') {
				pixel(x + 1, y, 3, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 1, 1, 2, r, g, b, a);
				x += 5;
			}
			else if (buf[i] == '"') {
				pixel(x + 1, y, 5, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 1, 1, 2, r, g, b, a);
				pixel(x + 4, y + 1, 1, 2, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == '*') {
				pixel(x + 2, y, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 1, 7, 5, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 5, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 3, y + 1, 1, 2, r, g, b, a);
				pixel(x + 2, y + 3, 3, 1, r, g, b, a);
				pixel(x + 3, y + 4, 1, 2, r, g, b, a);
				pixel(x + 1, y + 2, 1, 1, r, g, b, a);
				pixel(x + 1, y + 4, 1, 1, r, g, b, a);
				pixel(x + 5, y + 2, 1, 1, r, g, b, a);
				pixel(x + 5, y + 4, 1, 1, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == '`') {
				pixel(x, y, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 1, 1, 1, r, g, b, a);
				pixel(x + 2, y + 2, 1, 1, r, g, b, a);
				x += 4;
			}
			else if (buf[i] == '~') {
				pixel(x, y + 1, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 1, 5, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 5, y, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 2, 1, 1, r, g, b, a);
				pixel(x + 2, y + 1, 2, 1, r, g, b, a);
				pixel(x + 4, y + 2, 2, 1, r, g, b, a);
				pixel(x + 6, y + 1, 1, 1, r, g, b, a);
				x += 8;
			}
			else if (buf[i] == '%') {
				pixel(x + 3, y, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y + 2, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 4, 4, 2, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y + 6, 3, 2, bg_r, bg_g, bg_b, a);
				pixel(x, y + 1, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 4, y + 5, 3, 3, bg_r, bg_b, bg_b, a);
				pixel(x + 4, y + 1, 1, 2, r, g, b, a);
				pixel(x + 3, y + 3, 1, 2, r, g, b, a);
				pixel(x + 2, y + 5, 1, 2, r, g, b, a);
				pixel(x + 1, y + 2, 1, 1, r, g, b, a);
				pixel(x + 5, y + 6, 1, 1, r, g, b, a);
				x += 7;
			}
			else if (buf[i] == '?') {
				pixel(x + 1, y - 1, 3, 8, bg_r, bg_g, bg_b, a);
				pixel(x, y - 1, 3, 3, bg_r, bg_g, bg_b, a);
				pixel(x + 2, y, 3, 4, bg_r, bg_g, bg_b, a);
				pixel(x + 1, y, 2, 1, r, g, b, a);
				pixel(x + 3, y + 1, 1, 2, r, g, b, a);
				pixel(x + 2, y + 3, 1, 1, r, g, b, a);
				pixel(x + 2, y + 5, 1, 1, r, g, b, a);
				x += 5;
			}
		}
	}
};
