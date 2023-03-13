#pragma once
#include "mem.h"
#include "../console/console.hpp"
#include <windows.h>
#include <vector>

#define P1 true
#define P2 true

namespace Mem
{
	class Address
	{
	public:
		MemHelper* mem = new MemHelper("Cemu.exe");

		uintptr_t BaseModule = (uintptr_t)GetModuleHandle("Cemu.exe");
		uintptr_t RootAddr = mem->ReadMemory<uintptr_t>(BaseModule + 0x1306438, false);

#if P1
		uintptr_t Base_P1;
		uintptr_t Infos_P1;
#endif

#if P2
		uintptr_t Base_P2;
		uintptr_t Infos_P2;
#endif

		void calcAddresses();

		class Player
		{
		public:
			uintptr_t Stamina;	

			class Infos
			{
			public:
				uintptr_t Health;
			};
		};
	};
};

extern Mem::Address* addr;

#if P1
extern Mem::Address::Player* cP1;
extern Mem::Address::Player::Infos* cInfos_P1;
#endif

#if P2
extern Mem::Address::Player* cP2;
extern Mem::Address::Player::Infos* cInfos_P2;
#endif