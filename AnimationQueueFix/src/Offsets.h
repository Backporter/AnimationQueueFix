#pragma once

typedef void(*tAnimationFileManagerSingleton_UpdateQueue)(void* a_this);

static void** g_animationFileManager = (void**)REL::Relocation<uintptr_t>(0x31AEDC0).address();  // 2F51EC0, 2FECA40, 30A9F50

static REL::Relocation<tAnimationFileManagerSingleton_UpdateQueue> AnimationFileManagerSingleton_UpdateQueue(0xB911D0);  // B0ACD0, B2F650, B45AB0
