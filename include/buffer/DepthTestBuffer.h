#pragma once
#include "BufferTest.h"
#include <cmath>



class DepthTestBuffer :	public BufferTest<float>
{
public:

	DepthTestBuffer();
	~DepthTestBuffer();

	bool Test(int x, int y, const float& t) override;

	//	wirte enable
	bool& IsWriteEnable();

	void SetTestFunc(const TestFunc& f);
	

private:

	bool mbWrite;
	TestFunc meBufferTestFunc;

};

