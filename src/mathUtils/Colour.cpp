#include "mathUtils/colour.h"

Colour::Colour(const float& r, const float& g, const float& b, const float& a/* = 1.0f*/)
	: red(r)
	, green(g)
	, blue(b)
	, alpha(a)
{
}

Colour::Colour()
	: red(0.0f)
	, green(0.0f)
	, blue(0.0f)
	, alpha(0.0f)
{

}

Colour::Colour(const float& v)
	: red(v)
	, green(v)
	, blue(v)
	, alpha(v)
{

}

Colour::~Colour()
{

}

Colour Colour::operator*(const Colour& other)
{
	red *= other.red;
	green *= other.green;
	blue *= other.blue;
	alpha *= other.alpha;
	return *this;
}

Colour Colour::operator-=(const Colour& other)
{
	red -= other.red;
	green -= other.green;
	blue -= other.blue;
	alpha -= other.alpha;
	return *this;
}

Colour Colour::operator+=(const Colour& other)
{
	red += other.red;
	green += other.green;
	blue += other.blue;
	alpha += other.alpha;
	return *this;
}

Colour Colour::operator-(const Colour& other)
{
	return Colour(red - other.red, green - other.blue, blue - other.blue, alpha - other.alpha);
}

Colour Colour::operator+(const Colour& other)
{
	return Colour(red + other.red, green + other.blue, blue + other.blue, alpha + other.alpha);
}

bool Colour::operator!=(const Colour& other)
{
	return !(*this == other);
}

bool Colour::operator==(const Colour& other)
{
	return red == other.red && green == other.green && blue == other.blue && alpha == other.alpha;
}