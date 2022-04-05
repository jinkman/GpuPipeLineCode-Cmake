#pragma once

#include <vector>
#include <memory>
#include "rendering/StateSet.h"
#include "scene/Primitive.h"


class Geometry
{
public:

	auto GetOrCreateStateSet()->StateSet*;

	auto SetStateSet(StateSet* ss)->void;

	auto GetPrimitiveArray()->std::vector<Primitive*>;

private:

	//	only data
	std::vector<Primitive*> mVecPrimitive;

	//	only render states
	std::shared_ptr<StateSet> mPSs;
};

