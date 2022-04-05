#include "scene/Primitive.h"

Primitive::Primitive()
	:drawMode(EPrimitiveMode::GL_TRIANGLES)
{

}

EPrimitiveMode & Primitive::PrimitiveMode()
{
	return drawMode;
}

std::vector<Vec3>& Primitive::VertArray()
{
	return mVertArray;
}

std::vector<Colour>& Primitive::VertColor()
{
	return mVertColor;
}

std::vector<Vec3>& Primitive::NormalArray()
{ 
	return mNormalArray;
}

std::vector<Vec2>& Primitive::TexCoordArray()
{
	return mTexCoordArray;
}

std::vector<unsigned int>& Primitive::IndexArray()
{
	return mIndexArray;
}
