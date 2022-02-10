#include "GlobalConfig.h"



auto GlobalConfig::GetInstance() ->GlobalConfig&
{
	static GlobalConfig globalConfig;
	return globalConfig;
}

auto GlobalConfig::IsWindowShouldClose() ->bool&
{
	return mbWindowShouldClose;
}

auto GlobalConfig::GetGpuBufferPipeline() ->GPUBufferDataPipeline&
{
	return mGpuPipeline;
}

GlobalConfig::GlobalConfig()
	:mbWindowShouldClose(false)
{

}

GlobalConfig::~GlobalConfig()
{

}
