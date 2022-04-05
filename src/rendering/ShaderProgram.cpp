#include "rendering/ShaderProgram.h"

ShaderProgram::ShaderProgram()
{

}

ShaderProgram::~ShaderProgram()
{

}

void ShaderProgram::SetVertShader(VertShaderFunc func)
{
	vertFunc = func;
}

void ShaderProgram::SetTesslationShader(TessShaderFunc func)
{
	tessFunc = func;
}

void ShaderProgram::SetGeometryShader(GeomShaderFunc func)
{
	geomFunc = func;
}

void ShaderProgram::SetFragmentShader(FragShaderFunc func)
{
	fragFunc = func;
}

VertShaderFunc ShaderProgram::GetVertShader()
{
	if (!vertFunc)
	{
		auto defaultFunc = [] (float* data)
		{
			
		};
		return defaultFunc;
	}
	return vertFunc;
}

TessShaderFunc ShaderProgram::GetTesslationShader()
{
	if (!tessFunc)
	{
		auto defaultFunc = [](float* data)
		{

		};
		return defaultFunc;
	}
	return vertFunc;
}

GeomShaderFunc ShaderProgram::GetGeometryShader()
{
	if (!geomFunc)
	{
		auto defaultFunc = [](float* data)
		{

		};
		return defaultFunc;
	}
	return geomFunc;
}

FragShaderFunc ShaderProgram::GetFragmentShader()
{
	if (!fragFunc)
	{
		auto defaultFunc = [](float* data)
		{

		};
		return defaultFunc;
	}
	return fragFunc;
}
