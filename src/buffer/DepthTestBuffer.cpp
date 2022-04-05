#include "buffer/DepthTestBuffer.h"



DepthTestBuffer::DepthTestBuffer()
	: mbWrite(true)
{
	//	for default: open depth test
	State() = true;

}

DepthTestBuffer::~DepthTestBuffer()
{

}

bool DepthTestBuffer::Test(int x, int y, const float& t)
{
	//	TODO  Z-Buffer

	bool bTest = true;

	if (State())
	{
		float ori = GetBufferValue(x, y);
		// test func
		switch (meBufferTestFunc)
		{
		case eAlways:
			break;
		case eNever:
			bTest = false;
			break;
		case eLess:
			if (t >= ori)
				bTest = false;
			break;
		case eEqual:
			if (std::fabs(t - ori) >= 1e-6)
				bTest = false;
			break;
		case eLEqual:
			if (t > ori)
				bTest = false;
			break;
		case eGReater:
			if (t <= ori)
				bTest = false;
			break;
		case eNotEqual:
			if (std::fabs(t - ori) < 1e-6)
				bTest = false;
			break;
		case eGEqual:
			if (t < ori)
				bTest = false;
			break;
		default:
			break;
		}
	}

	if (IsWriteEnable() && bTest)
	{
		UpdateBufferValue(x, y, t);
	}
	return bTest;
}

bool & DepthTestBuffer::IsWriteEnable()
{
	return mbWrite;
}

void DepthTestBuffer::SetTestFunc(const TestFunc& f)
{
	meBufferTestFunc = f;
}