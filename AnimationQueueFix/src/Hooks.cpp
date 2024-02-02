#include "Hooks.h"
#include "Offsets.h"

namespace Hooks
{
	void Install()
	{
		xUtilty::Log::GetSingleton()->Write(xUtilty::Log::logLevel::kNone, "Hooking...");

		QueueFixHook::Hook();

		xUtilty::Log::GetSingleton()->Write(xUtilty::Log::logLevel::kNone, "...success");
	}

	void QueueFixHook::LoadAnim(void* a1, void* a2)
	{
		_LoadAnim(a1, a2);

		void* animationFileManager = *g_animationFileManager;

		ConsoleRE::BSSpinLock* lock = (ConsoleRE::BSSpinLock*)((uintptr_t)animationFileManager + 0x18);
		ConsoleRE::BSSpinLockGuard locker(*lock);

		AnimationFileManagerSingleton_UpdateQueue(animationFileManager);
	}

}
