#include "rendering/StateSet.h"

StateSet::StateSet()
	: mpShader(nullptr)
{

}

StateSet::~StateSet()
{

}

auto StateSet::GetOrCreateProgram() -> ShaderProgram *
{
	if (!mpShader)
	{
		mpShader = std::make_shared<ShaderProgram>();
	}
	return mpShader.get();
}

auto StateSet::SetProgram(ShaderProgram *pro)
{
	mpShader = std::shared_ptr<ShaderProgram>(pro);
}
