
#define pi 3.14159265358979323846f
#define deg2rad( x ) ( ( float )( x ) * ( float )( ( float )( pi ) / 180.0f ) )
#define rad2deg( x ) ( ( float )( x ) * ( float )( 180.0f / ( float )( pi ) ) )

namespace math
{
	inline void vectorsubtract(const vector& a, const vector& b, vector& c)
	{
		c.x = a.x - b.x;
		c.y = a.y - b.y;
		c.z = a.z - b.z;
	}

	inline float getfov(vector vlocalorigin, vector vposition, vector vforward)
	{
		vector vlocal;

		math::vectorsubtract(vposition, vlocalorigin, vlocal);

		vlocal.normalizeinplace();

		float fvalue = vforward.dot(vlocal);

		if (fvalue < -1.0f)
			fvalue = -1.0f;

		if (fvalue > 1.0f)
			fvalue = 1.0f;

		return rad2deg(acos(fvalue));
	}

	inline void clampangles(vector& angle)
	{
		if (angle.x > 89.0f) angle.x = 89.0f;
		else if (angle.x < -89.0f) angle.x = -89.0f;

		if (angle.y > 180.0f) angle.y = 180.0f;
		else if (angle.y < -180.0f) angle.y = -180.0f;

		angle.z = 0;
	}

	inline float anglenormalize(float angle)
	{
		while (angle < -180)    angle += 360;
		while (angle > 180)    angle -= 360;

		return angle;
	}

	inline void calcangle(vector &vsource, vector &vdestination, vector &qangle)
	{
		vector vdelta = vsource - vdestination;

		float fhyp = (vdelta.x * vdelta.x) + (vdelta.y * vdelta.y);

		float froot;

		__asm
		{
			sqrtss xmm0, fhyp
			movss froot, xmm0
		}

		qangle.x = rad2deg(atan(vdelta.z / froot));
		qangle.y = rad2deg(atan(vdelta.y / vdelta.x));

		if (vdelta.x >= 0.0f)
			qangle.y += 180.0f;

		qangle.x = anglenormalize(qangle.x);
		qangle.y = anglenormalize(qangle.y);
	}

	inline void sincos(float radians, PFLOAT sine, PFLOAT cosine)
	{
		__asm
		{
			fld dword ptr[radians]
			fsincos
			mov edx, dword ptr[cosine]
			mov eax, dword ptr[sine]
			fstp dword ptr[edx]
			fstp dword ptr[eax]
		}
	}

	inline void anglevectors(vector angles, vector &f)
	{
		float sp, sy, sr, cp, cy, cr;

		sincos(deg2rad(angles[0]), &sp, &cp);
		sincos(deg2rad(angles[1]), &sy, &cy);
		sincos(deg2rad(angles[2]), &sr, &cr);

		f[0] = cp * cy;
		f[1] = cp * sy;
		f[2] = -sp;
	}
}
