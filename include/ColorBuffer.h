#pragma once
#include "BufferTest.h"

class Colour
{
public:
	Colour(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a = 255);
	Colour();
	~Colour();

	// operation
	bool operator ==(const Colour& other);
	bool operator !=(const Colour& other);
	Colour operator +(const Colour& other);
	Colour operator -(const Colour& other);
	Colour operator +=(const Colour& other);
	Colour operator -=(const Colour& other);

private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};


class ColorBuffer :	public BufferTest<Colour>
{
public:

	ColorBuffer();
	~ColorBuffer();

	bool Test(int x, int y, const Colour& t) override;
};

