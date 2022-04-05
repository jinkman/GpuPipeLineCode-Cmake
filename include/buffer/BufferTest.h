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
		, mbState(false)
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

	bool& State()
	{
		return mbState;
	}

	void ClearBuffer(const TData& t)
	{
		for (auto wid = 0; wid < mSizeX; wid++)
		{
			for (auto hei = 0; hei < mSizeY; hei++)
			{
				UpdateBufferValue(wid, hei, t);
			}
		}
	}


	virtual bool Test(int x, int y, const TData& t) = 0;

	void UpdateBufferValue(int x, int y, const TData& t)
	{
		mPBufferData[x * mSizeY + y] = t;
	}

	TData GetBufferValue(int x, int y)
	{
		return mPBufferData[x * mSizeY + y];
	}

protected:

	TData* mPBufferData;
	int mSizeX;
	int mSizeY;
	bool mbState;
};