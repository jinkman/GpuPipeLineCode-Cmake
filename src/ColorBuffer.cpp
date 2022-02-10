#include "ColorBuffer.h"

Colour::Colour(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a/* = 255*/)
	: red(r)
	, green(g)
	, blue(b)
	, alpha(a)
{
}

Colour::Colour()
	: red(255)
	, green(255)
	, blue(255)
	, alpha(255)
{

}

Colour::~Colour()
{

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


ColorBuffer::ColorBuffer()
{

}

ColorBuffer::~ColorBuffer()
{

}

bool ColorBuffer::Test(int x, int y, const Colour& t)
{
	return true;
}

