#pragma once

#include <vector>
#include "scene/Geometry.h"

class Scene
{
public:

	std::vector<Geometry*> GetGeometryArray() const;

protected:
	mutable std::vector<Geometry*> mVecGeo;
};

