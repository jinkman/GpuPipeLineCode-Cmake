#include "rendering/GPUBufferDataPipeline.h"

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
		auto mSs = mGeo->GetOrCreateStateSet();
		for (auto& mPri : mPrimitiveArray)
		{
			// draw call

			// render pipeline use mSs

			//	GPU Pipeline

			// step1: Organization primitive

			auto vertFunc = mSs->GetOrCreateProgram()->GetVertShader();
			vertFunc(nullptr);
			
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

void GPUBufferDataPipeline::SetClearMask(int flag)
{
	mClearMask = flag;
}

void GPUBufferDataPipeline::SwapBuffer()
{
	// TODO: draw piexl to eazyx

	BeginBatchDraw();

	for (auto wid = 0; wid<SCR_WIDTH; wid++)
	{
		for (auto hei = 0; hei<SCR_HEIGHT; hei++)
		{
			auto color = mGpuColorBuffer.GetBufferValue(wid, hei);
			auto color2COLORREF = [](Colour col)->COLORREF
			{
				return int(col.blue * 255) << 16 | int(col.green * 255) << 8 | int(col.red * 255);
			};
			auto a = color2COLORREF(color);

			putpixel(wid, hei, color2COLORREF(color));
		}
	}
	EndBatchDraw();
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
