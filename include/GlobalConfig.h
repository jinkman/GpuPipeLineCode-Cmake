#pragma once
#include "GPUBufferDataPipeline.h"


#define SCR_WIDTH 800
#define SCR_HEIGHT 600  
#define HAS_CMD 1

class GlobalConfig
{

public:
	static auto GetInstance()->GlobalConfig&;

	auto IsWindowShouldClose()->bool&;

	auto GetGpuBufferPipeline() ->GPUBufferDataPipeline&;

	~GlobalConfig();
protected:

	GlobalConfig();

private:
	GlobalConfig& operator=(const GlobalConfig&) = delete;
	GlobalConfig(const GlobalConfig&) = delete;

private:
	bool mbWindowShouldClose;
	GPUBufferDataPipeline mGpuPipeline;
};

