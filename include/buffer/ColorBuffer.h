#pragma once
#include "BufferTest.h"
#include "mathUtils/Colour.h"

enum BlendFunc
{
	GL_ZERO,						//	Factor is equal to 0
	GL_ONE,							//	Factor is equal to 1
	GL_SRC_COLOR,					//	因子等于源颜色向量C¯source
	GL_ONE_MINUS_SRC_COLOR,			//	因子等于1−C¯source
	GL_DST_COLOR,					//	因子等于目标颜色向量C¯destination
	GL_ONE_MINUS_DST_COLOR,			//	因子等于1−C¯destination
	GL_SRC_ALPHA,					//	因子等于C¯source的alpha分量
	GL_ONE_MINUS_SRC_ALPHA,			//	因子等于1− C¯source的alpha分量
	GL_DST_ALPHA,					//	因子等于C¯destination的alpha分量
	GL_ONE_MINUS_DST_ALPHA,			//	因子等于1− C¯destination的alpha分量
	GL_CONSTANT_COLOR,				//	因子等于常数颜色向量C¯constant
	GL_ONE_MINUS_CONSTANT_COLOR,	//	因子等于1−C¯constant
	GL_CONSTANT_ALPHA,				//	因子等于C¯constant的alpha分量
	GL_ONE_MINUS_CONSTANT_ALPHA		//	因子等于1− C¯constant的alpha分量
};
enum BlendEquation
{
	GL_FUNC_ADD,
	GL_FUNC_SUBTRACT,
	GL_FUNC_REVERSE_SUBTRACT
};


class ColorBuffer :	public BufferTest<Colour>
{
public:

	ColorBuffer();
	~ColorBuffer();

	bool Test(int x, int y, const Colour& t) override;

	//	wirte enable
	bool& IsBlendEnable();

	void SetBlendEquation(const BlendEquation& v);

	void SetBlendFunc(const BlendFunc& sBlendFunc, const BlendFunc& dBlendFunc);

	void SetConstanceColour(const Colour& col);

private:
	bool bBlend;
	BlendEquation mBlendEquation;
	BlendFunc msBlendFunc;
	BlendFunc mdBlendFunc;
	Colour mConstanceCol;
};

