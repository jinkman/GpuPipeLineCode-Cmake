#include "scene/Geometry.h"

auto Geometry::GetOrCreateStateSet() ->StateSet*
{
	if (!mPSs)
	{
		mPSs = std::make_shared<StateSet>();
	}
	return mPSs.get();
}

auto Geometry::SetStateSet(StateSet* ss) ->void
{
	mPSs = std::shared_ptr<StateSet>(ss);
}

auto Geometry::GetPrimitiveArray() ->std::vector<Primitive*>
{
	return mVecPrimitive;
}
