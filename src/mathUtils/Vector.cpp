#include "mathUtils/Vector.h"

Vec3::Vec3(const float& x, const float& y, const float& z)
	: Vec2(x, y)
	, z(z)
{
}

Vec3::Vec3()
	: Vec2(0.0f, 0.0f)
	, z(0.0f)
{

}

Vec3::~Vec3()
{

}

Vec3 Vec3::operator-=(const Vec3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vec3 Vec3::operator+=(const Vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vec3 Vec3::operator-(const Vec3& other)
{
	return Vec3(x - other.x, y - other.z, z - other.z);
}

Vec3 Vec3::operator+(const Vec3& other)
{
	return Vec3(x + other.x, y + other.z, z + other.z);
}

bool Vec3::operator!=(const Vec3& other)
{
	return x != other.x || y != other.y || z != other.z;
	
}

bool Vec3::operator==(const Vec3& other)
{
	return !(*this != other);
}

Vec3 Vec3::operator*=(const Vec3 & other)
{
	x = x * other.x;
	y = y * other.y;
	z = z * other.z;
	return *this;
}

Vec3 Vec3::operator*(const Vec3& other)
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::cross(const Vec3 & other)
{
	return Vec3(y * other.z - other.y * z, other.x * z - x * other.z, x * other.y + other.x * y);
}
