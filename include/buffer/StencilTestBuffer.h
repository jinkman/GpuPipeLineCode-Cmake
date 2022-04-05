#pragma once
#include "BufferTest.h"


enum StencilOPFunc
{
	eKeep,		// ���ֵ�ǰ�����ģ��ֵ	
	eZero,		// ��ģ��ֵ����Ϊ0
	eReplace,	// ��ģ��ֵ����ΪglStencilFunc�������õ�refֵ
	eIncr,		// ���ģ��ֵС�����ֵ��ģ��ֵ��1
	eIncr_Warp,	// ��GL_INCRһ���������ģ��ֵ���������ֵ�����
	eDecr,		// ���ģ��ֵ������Сֵ��ģ��ֵ��1
	eDecr_Warp,	// ��GL_DECRһ���������ģ��ֵС��0��������Ϊ���ֵ
	eInvert		// ��λ��ת��ǰ��ģ�建��ֵ
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

