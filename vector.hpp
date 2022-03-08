
struct matrix4x4
{
	float m[4][4];
};

struct vector
{
	vector();
	vector(float x, float y, float z);

	vector&	operator *=(const float);

	float&	operator [](int index);

	vector	operator+(const vector& v) const;
	vector	operator-(const vector& v) const;
	vector	operator*(float fl) const;

	bool	iszero(float tolerance = FLT_EPSILON);
	void    zero();
	float	length2d();
	float	length();
	float	normalize();
	float	normalizeinplace();
	float	dot(const vector&);

	float	x;
	float	y;
	float	z;
};

inline bool vector::iszero(float tolerance)
{
	return (x > -tolerance && x < tolerance && y > -tolerance && y < tolerance && z > -tolerance && z < tolerance);
}

inline vector& vector::operator *= (const float in)
{
	x *= in;
	y *= in;
	z *= in;

	return *this;
}

inline float& vector::operator [] (int index)
{
	return ((&x)[index]);
}

inline vector vector::operator+(const vector& v) const
{
	vector res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

inline vector vector::operator-(const vector& v) const
{
	vector res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}

inline vector vector::operator*(float fl) const
{
	vector res;
	res.x = x * fl;
	res.y = y * fl;
	res.z = z * fl;
	return res;
}

inline vector::vector()
{
	x = y = z = 0.f;
}

inline void vector::zero()
{
	x = y = z = 0.f;
}

inline vector::vector(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

inline float vector::length2d()
{
	float root = 0.f;
	float sqst = x * x + y * y;

	__asm
	{
		sqrtss xmm0, sqst
		movss root, xmm0
	}

	return root;
}

inline float vector::dot(const vector &in)
{
	return (x * in.x + y * in.y + z * in.z);
}

inline float vector::length()
{
	float root = 0.f;
	float sqsr = x * x + y * y + z * z;

	__asm
	{
		sqrtss xmm0, sqsr
		movss root, xmm0
	}

	return root;
}

inline float vector::normalize()
{
	float fllength = length();
	float fllengthnormal = 1.f / (FLT_EPSILON + fllength);

	x = x * fllengthnormal;
	y = y * fllengthnormal;
	z = z * fllengthnormal;

	return fllength;
}

inline float vector::normalizeinplace()
{
	return normalize();
}
