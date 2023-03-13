#pragma once
#include <vector>

namespace Mem
{
	class Offset
	{
	public:
		class Player
		{
		public:
			std::vector<unsigned int> Stamina { 0x68 };

			class Infos
			{
			public:
				std::vector<unsigned int> Health { 0x540 };
			};
		};
	};
};

extern Mem::Offset* offset;
extern Mem::Offset::Player* cOffset_Player;;
extern Mem::Offset::Player::Infos* cInfosOffset_Player;