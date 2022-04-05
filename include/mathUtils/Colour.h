#pragma once

class Colour
{
public:
	Colour(const float& r, const float& g, const float& b, const float& a = 1.0f);
	Colour(const float& v);
	Colour();
	~Colour();

	// operation
	bool operator ==(const Colour& other);
	bool operator !=(const Colour& other);
	Colour operator +(const Colour& other);
	Colour operator -(const Colour& other);
	Colour operator +=(const Colour& other);
	Colour operator -=(const Colour& other);

	Colour operator *(const Colour& other);

public:
	float red;
	float green;
	float blue;
	float alpha;
};
