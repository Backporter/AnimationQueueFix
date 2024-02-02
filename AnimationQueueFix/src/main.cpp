#include "../../../OrbisUtil/include/RelocationManager.h"
#include "../../../OrbisUtil/include/Logger.h"
#include "../../../OrbisUtil/include/FileSystem.h"

#include "Hooks.h"

extern "C" __declspec (dllexport) int module_start(size_t argc, const void* argv) { xUtilty::RelocationManager(); return 0; }
extern "C" __declspec (dllexport) int module_stop(size_t argc, const void* argv) { return 0; }

namespace
{
	void InitializeLog()
	{
		xUtilty::Log::GetSingleton()->OpenRelitive(xUtilty::FileSystem::Download, "OSEL/Plugins/AnimationQueueFix/AnimationQueueFix.log");
	}
}

extern "C" DLLEXPORT bool Query(const Interface::QueryInterface* a_skse, PluginInfo* a_info)
{
	a_info->SetPluginName("AnimationQueueFix");
	a_info->SetPluginVersion(1);

	return true;
}

extern "C" DLLEXPORT bool Load(const Interface::QueryInterface* a_skse)
{
	InitializeLog();

	API::Init(a_skse);

	Hooks::Install();

	return true;
}

extern "C" DLLEXPORT bool Revert() { return true; }