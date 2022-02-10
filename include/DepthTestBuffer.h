#pragma once
#include "BufferTest.h"



class DepthTestBuffer :	public BufferTest<float>
{
public:

	DepthTestBuffer();
	~DepthTestBuffer();

	bool Test(int x, int y, const float& t) override;
};

