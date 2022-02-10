#include "GPUBufferDataPipeline.h"

#include <graphics.h>
#include <string>

#include "GlobalConfig.h"

GPUBufferDataPipeline::GPUBufferDataPipeline()
	: mClearMask(0)
	, mClearColor(0, 0, 0, 0)
	, mClearDepth(1.0f)
	, mClearStencil(0)
{

}

GPUBufferDataPipeline::~GPUBufferDataPipeline()
{

}

void GPUBufferDataPipeline::InitBufferSize(int x, int y)
{
	mGpuColorBuffer.InitBuffer(x, y);
	mGpuDepthBuffer.InitBuffer(x, y);
	mGpuStencilBuffer.InitBuffer(x, y);
}

void GPUBufferDataPipeline::DrawScene(const Scene& scene)
{
	PreRender();
	// TODO: Draw all geometry in scene

	auto mGeoArray = scene.GetGeometryArray();
	for (auto& mGeo : mGeoArray)
	{
		// call draw call for all primitive sets
		auto mPrimitiveArray = mGeo->GetPrimitiveArray();
		auto mSs = mGeo->GetStateSet();
		for (auto& mPri : mPrimitiveArray)
		{
			// draw call

			// render pipeline use mSs
			
		}
	}


	// End Draw
	AfterRender();
}

void GPUBufferDataPipeline::SetClearColor(const Colour& c)
{
	mClearColor = c;
}

void GPUBufferDataPipeline::SetClearDepth(const float& d)
{
	mClearDepth = d;
}

void GPUBufferDataPipeline::SetClearStencil(const unsigned char& sten)
{
	mClearStencil = sten;
}

void GPUBufferDataPipeline::SetClearMask(int& flag)
{
	mClearMask = flag;
}

void GPUBufferDataPipeline::SwapBuffer()
{
	// TODO: draw piexl to eazyx

	static int frame = 0;
	frame++;

	/*LPTSTR szBuffer = new TCHAR[1024];
	wsprintf(szBuffer, L"Hello World!	Frame is: %d", frame);

	auto halfWidth = textwidth(szBuffer) / 2;
	auto halfHeight = textheight(szBuffer) / 2;
	outtextxy(SCR_WIDTH / 2 - halfWidth, SCR_HEIGHT / 2 + halfHeight, szBuffer);*/
}

void GPUBufferDataPipeline::PreRender()
{
	//	clear buffer
	if (mClearMask & COLOR_BUFFER_BIT)
	{
		mGpuColorBuffer.ClearBuffer(mClearColor);
	}

	if (mClearMask & DEPTH_BUFFER_BIT)
	{
		mGpuDepthBuffer.ClearBuffer(mClearDepth);
	}

	if (mClearMask & STENCIL_BUFFER_BIT)
	{
		mGpuStencilBuffer.ClearBuffer(mClearStencil);
	}
}

void GPUBufferDataPipeline::AfterRender()
{
	// swap buffer
	SwapBuffer(); 
}
