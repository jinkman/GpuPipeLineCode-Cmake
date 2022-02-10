#pragma once

#include <vector>

#include "StateSet.h"
#include "Primitive.h"


class Geometry
{
public:

	auto GetStateSet()->StateSet*;

	auto GetPrimitiveArray()->std::vector<Primitive*>;

private:

	//	only data
	std::vector<Primitive*> mVecPrimitive;

	//	only render states
	StateSet* mPSs;
};

