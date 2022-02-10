#include "Geometry.h"

auto Geometry::GetStateSet() ->StateSet*
{
	return mPSs;
}

auto Geometry::GetPrimitiveArray() ->std::vector<Primitive*>
{
	return mVecPrimitive;
}
