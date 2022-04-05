#include "buffer/ColorBuffer.h"


ColorBuffer::ColorBuffer()
	: bBlend(false)
	, msBlendFunc(GL_SRC_ALPHA)
	, mdBlendFunc(GL_ONE_MINUS_SRC_ALPHA)
	, mConstanceCol(1.0f, 1.0f, 1.0f, 1.0f)
{

}

ColorBuffer::~ColorBuffer()
{

}

bool ColorBuffer::Test(int x, int y, const Colour& t)
{
	// TODO color blend

	Colour res = t;
	if (State())	//blend is open
	{

		Colour ori = GetBufferValue(x, y);
		Colour des = t;
		
		auto GetFactor = [this](const BlendFunc& func, const Colour& sCol, const Colour& dCol)->Colour {
			float sAlpha = sCol.alpha;
			float dAlpha = dCol.alpha;
			Colour res(1.0f);
			switch (func)
			{
			case GL_ZERO:
				res = Colour(0.0f);
				break;
			case GL_ONE:
				res = Colour(1.0f);
				break;
			case GL_SRC_COLOR:
				res = sCol;
				break;
			case GL_ONE_MINUS_SRC_COLOR:
				res = Colour(1.0f) - sCol;
				break;
			case GL_DST_COLOR:
				res = dCol;
				break;
			case GL_ONE_MINUS_DST_COLOR:
				res = Colour(1.0f) - dCol;
				break;
			case GL_SRC_ALPHA:
				res = Colour(sAlpha);
				break;
			case GL_ONE_MINUS_SRC_ALPHA:
				res = Colour(1.0f);
				break;
			case GL_DST_ALPHA:
				res = Colour(dAlpha);
				break;
			case GL_ONE_MINUS_DST_ALPHA:
				res = Colour(1.0f - dAlpha);
				break;
			case GL_CONSTANT_COLOR:
				res = mConstanceCol;
				break;
			case GL_ONE_MINUS_CONSTANT_COLOR:
				res = Colour(1.0f) - mConstanceCol;
				break;
			case GL_CONSTANT_ALPHA:
				res = Colour(mConstanceCol.alpha);
				break;
			case GL_ONE_MINUS_CONSTANT_ALPHA:
				res = Colour(1.0f - mConstanceCol.alpha);
				break;
			default:
				break;
			}
			return res;
		};

		Colour sourceCol = ori * GetFactor(msBlendFunc, ori, t);
		Colour destinationCol = des * GetFactor(mdBlendFunc, ori, t);
		//	blend
		switch (mBlendEquation)
		{
		case GL_FUNC_ADD:
			res = sourceCol + destinationCol;
			break;
		case GL_FUNC_SUBTRACT:
			res = sourceCol - destinationCol;
			break;
		case GL_FUNC_REVERSE_SUBTRACT:
			res = destinationCol - sourceCol;
			break;
		default:
			break;
		}
	}
	
	UpdateBufferValue(x, y, res);

	return true;
}

bool& ColorBuffer::IsBlendEnable()
{
	return bBlend;
}

void ColorBuffer::SetBlendEquation(const BlendEquation& v)
{
	mBlendEquation = v;
}

void ColorBuffer::SetBlendFunc(const BlendFunc& sBlendFunc, const BlendFunc& dBlendFunc)
{
	msBlendFunc = sBlendFunc;
	mdBlendFunc = dBlendFunc;
}

void ColorBuffer::SetConstanceColour(const Colour& col)
{
	mConstanceCol = col;
}

