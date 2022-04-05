#pragma once
#include <functional> 

typedef std::function<void(float *)> VertShaderFunc;
typedef std::function<void(float *)> TessShaderFunc;
typedef std::function<void(float *)> GeomShaderFunc;
typedef std::function<void(float *)> FragShaderFunc;

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	void SetVertShader(VertShaderFunc func);

	void SetTesslationShader(TessShaderFunc func);

	void SetGeometryShader(GeomShaderFunc func);

	void SetFragmentShader(FragShaderFunc func);

	VertShaderFunc GetVertShader();

	TessShaderFunc GetTesslationShader();

	GeomShaderFunc GetGeometryShader();

	FragShaderFunc GetFragmentShader();

private:
	// vert shader

	// frag shader

	VertShaderFunc vertFunc;
	TessShaderFunc tessFunc;
	GeomShaderFunc geomFunc;
	FragShaderFunc fragFunc;
};