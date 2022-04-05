#include "buffer/StencilTestBuffer.h"

StencilTestBuffer::StencilTestBuffer()
	:mMaskValue(0xff)// keep value
	, mbWrite(true)
{
	//	for default: close stencil test
	State() = false;
}

StencilTestBuffer::~StencilTestBuffer()
{

}

bool StencilTestBuffer::Test(int x, int y, const unsigned char& t)
{
	//	TODO: Stencil Test
	bool bTest = true;

	if (State())
	{
		unsigned char ori = GetBufferValue(x, y);
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
			if (t != ori)
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
			if (t == ori)
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

	// update func
	if (bTest)
	{
		auto ReverseBits = [](unsigned char ch)->unsigned char
		{
			ch = (ch & 0x55) << 1 | (ch >> 1) & 0x55;
			ch = (ch & 0x33) << 2 | (ch >> 2) & 0x33;
			ch = (ch & 0x0F) << 4 | (ch >> 4) & 0x0F;
			return ch;
		};

		unsigned char ori = GetBufferValue(x, y);
		switch (mOPFunc)
		{
		case eKeep:
			break;
		case eZero:
			ori = 0;
			break;
		case eReplace:
			ori = t;
			break;
		case eIncr:
			if (ori < 255)
				ori++;
			break;
		case eIncr_Warp:
			if (ori < 255)
				ori++;
			else
				ori = 0;
			break;
		case eDecr:
			if (ori > 0)
				ori--;
			break;
		case eDecr_Warp:
			if (ori > 0)
				ori--;
			else
				ori = 255;
			break;
		case eInvert:
			ori = ReverseBits(ori);
			break;
		default:
			break;
		}
		UpdateBufferValue(x, y, ori && mMaskValue);
	}
	return bTest;
}

bool & StencilTestBuffer::IsWriteEnable()
{
	return mbWrite;
}

void StencilTestBuffer::SetTestFunc(const TestFunc& f)
{
	meBufferTestFunc = f;
}

void StencilTestBuffer::SetStencilMaskValue(const unsigned char& v)
{
	mMaskValue = v;
}
