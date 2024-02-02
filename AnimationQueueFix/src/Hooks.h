#pragma once

#include "Offsets.h"

namespace Hooks
{
	class QueueFixHook
	{
	public:
		static void Hook()
		{
			REL::Relocation<uintptr_t> hook (0xBB1D10);  // AE9A70, B0DE90, B245D0   BSResource__EntryDB_BShkbHkxDB__DBTraits_::Func3
			
			API::AllocTrampoline(14);

			auto& trampoline = API::GetTrampoline();

			_LoadAnim = trampoline.write_call<5>(hook.address() + 0x3C, LoadAnim);
		}

	private:
		static void LoadAnim(void* a1, void* a2);

		static inline REL::Relocation<decltype(LoadAnim)> _LoadAnim;
	};

	void Install();
}
