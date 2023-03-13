#include "mem.h"
#include "address.h"
#include "offset.h"
#include "../console/console.hpp"

using namespace Mem;

#define Root addr->RootAddr

#define G_Base_P1 addr->Base_P1
#define G_Infos_P1 addr->Infos_P1

#define G_Base_P2 addr->Base_P2
#define G_Infos_P2 addr->Infos_P2

void Mem::Address::calcAddresses()
{
#if P1
	addr->Base_P1 = mem->FindDMAAddy(Root, Root, { 0x10463F38, 0x0 });
	addr->Infos_P1 = mem->FindDMAAddy(G_Base_P1, Root, { 0x30, 0x0 });

	cP1->Stamina = mem->FindDMAAddy(G_Base_P1, Root, cOffset_Player->Stamina);
	cInfos_P1->Health = mem->FindDMAAddy(G_Infos_P1, Root, cInfosOffset_Player->Health);
#endif

#if P2
	addr->Base_P2 = mem->FindDMAAddy(Root, Root, { 0x01805014, 0x0 });
	addr->Infos_P2 = mem->FindDMAAddy(G_Base_P2, Root, { 0x30, 0x0 });

	cP2->Stamina = mem->FindDMAAddy(G_Base_P2, Root, cOffset_Player->Stamina);
	cInfos_P2->Health = mem->FindDMAAddy(G_Infos_P2, Root, cInfosOffset_Player->Health);
#endif
}

Address* addr = new Address();

#if P1
Address::Player* cP1 = new Address::Player();
Address::Player::Infos* cInfos_P1 = new Address::Player::Infos();
#endif

#if P2
Address::Player* cP2 = new Address::Player();
Address::Player::Infos* cInfos_P2 = new Address::Player::Infos();
#endif