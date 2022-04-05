#pragma once
#include <memory>
#include "rendering/ShaderProgram.h"
class StateSet
{
public:
	StateSet();
	~StateSet();

	auto GetOrCreateProgram()->ShaderProgram*;

	auto SetProgram(ShaderProgram* );

private:
	bool depth_test = true;
	bool stencil_test = false;
	bool blend = false;
	std::shared_ptr<ShaderProgram> mpShader;
};