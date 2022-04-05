// GPUPipeLineCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <graphics.h>

#include "GlobalConfig.h"


void InputProcess()
{
	ExMessage m;
	while (peekmessage(&m, EM_MOUSE | EM_KEY))
	{
		switch (m.message)
		{
			//mouse message
		case WM_MOUSEMOVE:
			std::cout << "Mouse move pos: <" << m.x << ", " << m.y << ">" << std::endl;
			break;
		case WM_LBUTTONDOWN:
			std::cout << "Left Button Down!" << m.message << std::endl;
			break;
		case WM_LBUTTONUP:
			std::cout << "Left Button Up!" << std::endl;
			break;
		case WM_RBUTTONDOWN:
			std::cout << "Right Button Down!" << std::endl;
			break;
		case WM_RBUTTONUP:
			std::cout << "Right Button Up!" << std::endl;
			break;

			//	key message
		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
			{
				GlobalConfig::GetInstance().IsWindowShouldClose() = true;
				std::cout << "Should Close Window!" << std::endl;
			}
			break;

		default:
			break;
		}
	}
}

int main()
{
	// 初始化图形模式
	initgraph(SCR_WIDTH, SCR_HEIGHT, HAS_CMD);
	auto& mGpuPipeline = GlobalConfig::GetInstance().GetGpuBufferPipeline();
	mGpuPipeline.InitBufferSize(SCR_WIDTH, SCR_HEIGHT);

	//	construction scene
	Scene scene;
		
	//	render loop
	while (!GlobalConfig::GetInstance().IsWindowShouldClose())
	{
		// input
		InputProcess();

		mGpuPipeline.SetClearMask(COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT | STENCIL_BUFFER_BIT);
		mGpuPipeline.SetClearColor(Colour(0.2f, 0.3f, 0.3f, 1.0f));

		{
			//	render scene
			mGpuPipeline.DrawScene(scene);
		}

	}

	// 关闭图形模式
	closegraph();
	return 0;
}