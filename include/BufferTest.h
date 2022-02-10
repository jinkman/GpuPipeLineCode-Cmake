#pragma once


enum TestFunc
{
	eAlways,	// always passes	
	eNever,		// never passes
	eLess,		// passes if the fragment^s value is less than the stored value	<
	eEqual,		// passes if the fragment^s value is equal to the stored value	=
	eLEqual,	// passes if the fragment^s value is less than or equal to the stored value	<=
	eGReater,	// passes if the fragment^s value is greater than the stored value	>
	eNotEqual,	// passes if the fragment^s value is note equal to the stored value	!= 
	eGEqual		// passes if the fragment^s value is greater than or equal to the stored value	>=
};

// depth buffer  stencil buffer test
template <class TData>
class BufferTest
{

public:
	BufferTest()
		: mPBufferData(nullptr)
		, mSizeX(0)
		, mSizeY(0)
	{

	}

	~BufferTest()
	{
		if (mPBufferData)
		{
			delete[] mPBufferData;
			mPBufferData = nullptr;
		}
	}

	void InitBuffer(int x, int y)
	{
		if (mPBufferData)
		{
			delete mPBufferData;
			mPBufferData = nullptr;
		}
		mPBufferData = new TData[x * y];
		mSizeX = x;
		mSizeY = y;
	}


	void ClearBuffer(const TData& t)
	{
		memset(mPBufferData, 0, sizeof(t) * mSizeX * mSizeY);
	}

	void SetTestFunc(const TestFunc& f)
	{
		mBufferTestFunc = f;
	}

	virtual bool Test(int x, int y, const TData& t) = 0;

protected:

	TData* mPBufferData;
	TestFunc mBufferTestFunc;
	int mSizeX;
	int mSizeY;
};