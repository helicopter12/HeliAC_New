#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "WorldSession.h"


class vendor_t1 : public CreatureScript
{
public:
	vendor_t1() : CreatureScript("vendor_t1") { }

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		switch (action)
		{

		case GOSSIP_ACTION_INFO_DEF + 1: //Warrior DPS
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100001);
			break;

		case GOSSIP_ACTION_INFO_DEF + 2: //Warrior Tank
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100002);
			break;

		case GOSSIP_ACTION_INFO_DEF + 3: //Pally DPS
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100003);
			break;

		case GOSSIP_ACTION_INFO_DEF + 4: //Pally Tank
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100004);
			break;

		case GOSSIP_ACTION_INFO_DEF + 5: //Pally Heal
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100005);
			break;

		case GOSSIP_ACTION_INFO_DEF + 6: //Druid DPS
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100006);
			break;

		case GOSSIP_ACTION_INFO_DEF + 7: //Druid Healer
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100007);
			break;

		case GOSSIP_ACTION_INFO_DEF + 8: //Shaman DPS
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100008);
			break;

		case GOSSIP_ACTION_INFO_DEF + 9: //Shaman Healer
			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100009);
			break;


		default:
			player->CLOSE_GOSSIP_MENU();
			break;
		}

		return true;
	}

	bool OnGossipHello(Player* player, Creature* creature)
	{

		if (player->getClass() == CLASS_WARRIOR) {
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "DPS Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tank Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->SEND_GOSSIP_MENU(100200, creature->GetGUID());

		} else if (player->getClass() == CLASS_PALADIN) {

			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "DPS Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tank Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Healer Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
			player->SEND_GOSSIP_MENU(100200, creature->GetGUID());


		} else if (player->getClass() == CLASS_DRUID) {

			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "DPS Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Healer Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
			player->SEND_GOSSIP_MENU(100200, creature->GetGUID());

		} else if (player->getClass() == CLASS_WARLOCK) {

			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100010);


		} else if (player->getClass() == CLASS_MAGE) {
			player->AddItem(102, 1);

			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100011);

		} else if (player->getClass() == CLASS_PRIEST) {

			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100012);

		} else if (player->getClass() == CLASS_ROGUE) {

			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100013);

		} else if (player->getClass() == CLASS_SHAMAN) {

			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "DPS Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Healer Gear", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
			player->SEND_GOSSIP_MENU(100200, creature->GetGUID());

		} else if (player->getClass() == CLASS_HUNTER) {

			player->GetSession()->SendListInventoryT1(creature->GetGUID(), 100014);

		}

		
		return true;
	}
};

void AddSC_vendor_t1()
{
	new vendor_t1;
}



/*
NOTES:

Player->GetSession()->SendListInventoryT1(guid);

(guid = The ID in npc_vendor)

So you fill in vendor data to npc_vendor and you *might* (not sure) need to create a dummy npc with that id aswell, cba to check. Anyways! Calling this code and insert a npc_vendor id into the (guid) bracket should give you the output you expect

*/