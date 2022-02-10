#pragma once
#include <vector>

#include "ColorBuffer.h"
#include "DepthTestBuffer.h"
#include "StencilTestBuffer.h"

#include "Scene.h"

#define COLOR_BUFFER_BIT 1
#define DEPTH_BUFFER_BIT 2
#define STENCIL_BUFFER_BIT 4


class GPUBufferDataPipeline
{
public:
	GPUBufferDataPipeline();

	~GPUBufferDataPipeline();

	void InitBufferSize(int x, int y);



	void DrawScene(const Scene& scene);	//Scene




	void SetClearMask(int& flag);

	void SetClearColor(const Colour& c);
	void SetClearDepth(const float& d);
	void SetClearStencil(const unsigned char& sten);
	
private:
	void SwapBuffer();

	void PreRender();

	void AfterRender();

	//	GPU Pipeline
	
	void VertexPipeline(float* vertData, int nSize) {}

	void TesslationPipeline(float* vertData, int nSize) {}

	void GeometryPipeline(float* vertData, int nSize) {}

	void FragmentPipeline(float* vertData, int nSize) {}



protected:

	ColorBuffer mGpuColorBuffer;
	DepthTestBuffer mGpuDepthBuffer;
	StencilTestBuffer mGpuStencilBuffer;

	//	mask
	int mClearMask;
	Colour mClearColor;
	float mClearDepth;
	unsigned char mClearStencil;
};

