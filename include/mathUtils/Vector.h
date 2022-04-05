#pragma once

class Vec2
{
public:
	Vec2(const float& x, const float& y)
		: x(x)
		, y(y)
	{
	}
	Vec2() 
		: x(0.0f)
		, y(0.0f)
	{
	}

public:
	float x;
	float y;
};

class Vec3 : public Vec2
{
public:
	Vec3(const float& x, const float& y, const float& z);
	Vec3();
	~Vec3();

	// operation
	bool operator ==(const Vec3& other);
	bool operator !=(const Vec3& other);
	Vec3 operator +(const Vec3& other);
	Vec3 operator -(const Vec3& other);
	Vec3 operator +=(const Vec3& other);
	Vec3 operator -=(const Vec3& other);

	//dot product
	Vec3 operator *=(const Vec3& other);
	Vec3 operator *(const Vec3& other);

	//cross product
	Vec3 cross(const Vec3& other);

public:
	float z;
};