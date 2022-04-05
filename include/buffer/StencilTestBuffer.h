#pragma once
#include "BufferTest.h"


enum StencilOPFunc
{
	eKeep,		// 保持当前储存的模板值	
	eZero,		// 将模板值设置为0
	eReplace,	// 将模板值设置为glStencilFunc函数设置的ref值
	eIncr,		// 如果模板值小于最大值则将模板值加1
	eIncr_Warp,	// 与GL_INCR一样，但如果模板值超过了最大值则归零
	eDecr,		// 如果模板值大于最小值则将模板值减1
	eDecr_Warp,	// 与GL_DECR一样，但如果模板值小于0则将其设置为最大值
	eInvert		// 按位翻转当前的模板缓冲值
};

class StencilTestBuffer : public BufferTest<unsigned char>
{
public:
	StencilTestBuffer();
	~StencilTestBuffer();

	bool Test(int x, int y, const unsigned char& t) override;

	//	wirte enable
	bool& IsWriteEnable();

	void SetTestFunc(const TestFunc& f);

	void SetStencilOPFunc(const StencilOPFunc& f);

	void SetStencilMaskValue(const unsigned char& v);
	
private:
	// mask
	unsigned char mMaskValue;
	StencilOPFunc mOPFunc;
	TestFunc meBufferTestFunc;
	bool mbWrite;
};

