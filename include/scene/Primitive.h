#pragma once
#include <vector>
#include "mathUtils/Vector.h"
#include "mathUtils/Colour.h"

enum EPrimitiveMode
{
	GL_POINTS			= 0,
	GL_LINES			= 1,
	GL_LINE_LOOP		= 2,
	GL_LINE_STRIP		= 3,
	GL_TRIANGLES		= 4,
	GL_TRIANGLE_STRIP	= 5,
	GL_TRIANGLE_FAN		= 6,
	GL_QUADS			= 7,
	GL_QUAD_STRIP		= 8,
	GL_POLYGON			= 9
};

//图元组织方式

class Primitive
{

	Primitive();
public:
	EPrimitiveMode &PrimitiveMode();

	std::vector<Vec3>& VertArray();

	std::vector<Colour>& VertColor();

	std::vector<Vec3>& NormalArray();

	std::vector<Vec2>& TexCoordArray();

	std::vector<unsigned int>& IndexArray();

private:
	// vert norm texCoord ……
	std::vector<Vec3>			mVertArray;
	std::vector<Colour>			mVertColor;
	std::vector<Vec3>			mNormalArray;
	std::vector<Vec2>			mTexCoordArray;
	std::vector<unsigned int>	mIndexArray;

	EPrimitiveMode				drawMode;
};

