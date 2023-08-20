#include "stdhdrs.h"

#include "Server.h"
#include "CmdMsg.h"
#include "Log.h"
#include "../ShareLib/packetType/ptype_old_do_battle_pass.h"

#ifdef BATTLE_PASS_SYSTEM

#define MAX_BATTLE_PASS_REWARD 1
#define MAX_BATTLE_PASS_PAGE_LIMIT 10

bool do_BattlePassReq(CPC* pc, CNetMsg::SP& msg);
bool do_BattlePassListReq(CPC* pc, CNetMsg::SP& msg);
bool do_BattlePassInfoReq(CPC* pc, CNetMsg::SP& msg);

void do_BattlePass(CPC* pc, CNetMsg::SP& msg)
{
	pTypeBase* pBase = reinterpret_cast<pTypeBase*>(msg->m_buf);

	switch (pBase->subType)
	{
	case MSG_BATTLE_PASS_REQ:
		{
			if (do_BattlePassReq(pc, msg) == false)
				return;
		}
		break;
	case MSG_BATTLE_PASS_INFO_REQ:
		{
			if (do_BattlePassInfoReq(pc, msg) == false)
				return;
		}
		break;
	default:
		{
			LOG_ERROR("HACKING : invalid subtype[%d]. charIndex[%d]", pBase->subType, pc->m_index);
			pc->m_desc->Close("invalid subtype");
			return;
		}
	}

}

bool do_BattlePassReq(CPC* pc, CNetMsg::SP& msg)
{
	RequestClient::battlePass* packet = reinterpret_cast<RequestClient::battlePass*>(msg->m_buf);

#ifdef ENABLE_NPC_BATTLE_PASS
	if (pc->m_pArea->FindCharInCell(pc, packet->npcIndex, MSG_CHAR_NPC, false) == NULL)
	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePassError(rmsg, MSG_BATTLE_PASS_ERROR_NOT_EXIST_NPC);
		SEND_Q(rmsg, pc->m_desc);
		return false;
	}
#endif

	// Check if already have max battle pass
	if (pc->m_battlePassLevel == MAX_BATTLE_PASS_LEVEL) 
	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePassError(rmsg, MSG_BATTLE_PASS_ERROR_LIMIT);
		SEND_Q(rmsg, pc->m_desc);
		return false;
	}

	// Get the next battlePass free
	CBattlePass * battlePassFree = gserver->FindBattlePassByLevel(pc->m_battlePassLevel + 1);
	if (battlePassFree == NULL)
		return false;

	// Check if have empty slot for reward
	std::vector<CItem*> rewardItemsFree = battlePassFree->getItemsReward();
	std::vector<CItem*> rewardItemsPremium = battlePassFree->getPremiumItemsReward();
	
	int totalRewards = rewardItemsFree.size();
	if (pc->m_battlePassPremium)
		totalRewards += rewardItemsPremium.size();

	if (totalRewards > pc->m_inventory.getEmptyCount())
	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePassError(rmsg, MSG_BATTLE_PASS_ERROR_EMPTY_SLOT);
		SEND_Q(rmsg, pc->m_desc);
		return false;	
	}

	// Check if have points for next battle pass
	if (pc->m_battlePassPoints < battlePassFree->m_points)
	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePassError(rmsg, MSG_BATTLE_PASS_ERROR_EXP_NEEDED);
		SEND_Q(rmsg, pc->m_desc);
		return false;	
	}

	// Check if have level for next battlePass
	if (pc->m_level < battlePassFree->m_level)
	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePassError(rmsg, MSG_BATTLE_PASS_ERROR_NOCONDITION_LEVEL);
		SEND_Q(rmsg, pc->m_desc);
		return false;	
	}

	pc->m_battlePassLevel += 1; // increase battlePass
	pc->m_battlePassPoints -= battlePassFree->m_points; // decrease points

	// Give all rewards if have
	for (int i = 0; i < rewardItemsFree.size(); i++) 
	{
		CItem* newitem = gserver->m_itemProtoList.CreateItem(rewardItemsFree[i]->getDBIndex(), -1, 
				rewardItemsFree[i]->getPlus(), rewardItemsFree[i]->getFlag(), rewardItemsFree[i]->Count());
		if (newitem)
			pc->m_inventory.addItem(newitem);
	}

	if (pc->m_battlePassPremium)
	{
		for (int i = 0; i < rewardItemsPremium.size(); i++) 
		{
			CItem* newitem = gserver->m_itemProtoList.CreateItem(rewardItemsPremium[i]->getDBIndex(), -1, 
				rewardItemsPremium[i]->getPlus(), rewardItemsPremium[i]->getFlag(), rewardItemsPremium[i]->Count());
			if (newitem)
				pc->m_inventory.addItem(newitem);
		}
	}

	pc->CalcStatus(true);

	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePass(rmsg, MSG_BATTLE_PASS_REP, pc->m_index, 0, pc->m_battlePassLevel);
		SEND_Q( rmsg, pc->m_desc );
	}

	return true;
}

bool do_BattlePassInfoReq(CPC* pc, CNetMsg::SP& msg)
{
	RequestClient::battlePass* packet = reinterpret_cast<RequestClient::battlePass*>(msg->m_buf);

#ifdef ENABLE_NPC_BATTLE_PASS
	if (pc->m_pArea->FindCharInCell(pc, packet->npcIndex, MSG_CHAR_NPC, false) == NULL)
	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::makeBattlePassError(rmsg, MSG_BATTLE_PASS_ERROR_NOT_EXIST_NPC);
		SEND_Q(rmsg, pc->m_desc);
		return false;
	}
#endif

	int pageLimit = packet->page * MAX_BATTLE_PASS_PAGE_LIMIT;
	if (pageLimit > gserver->m_listBattlePass.size())
		return false;

	LOG_INFO("BATTLE_PASS: PAGE %d %d %d", packet->page, pageLimit, gserver->m_listBattlePass.size());

	{
		CNetMsg::SP rmsg(new CNetMsg);
		ResponseClient::battlePassInfo *packetInfo = reinterpret_cast<ResponseClient::battlePassInfo *>(rmsg->m_buf);
		packetInfo->type = MSG_BATTLE_PASS;
		packetInfo->subType = MSG_BATTLE_PASS_INFO_REP;
		packetInfo->level = pc->m_battlePassLevel;
		packetInfo->premium = pc->m_battlePassPremium;
		packetInfo->page = packet->page;
		packetInfo->total = 0;
		packetInfo->next = pageLimit >= gserver->m_listBattlePass.size();

		// Check if already have max battle pass
		if (pc->m_battlePassLevel == MAX_BATTLE_PASS_LEVEL+1) {
			packetInfo->progress = 0;
		} else {		
			CBattlePass * battlePassFree = gserver->FindBattlePassByLevel(pc->m_battlePassLevel);
			CBattlePass * battlePassFreeNext = gserver->FindBattlePassByLevel(pc->m_battlePassLevel + 1);
			if (battlePassFree == NULL)
				return false;

			packetInfo->points = battlePassFreeNext->m_points;
			packetInfo->progress = pc->m_battlePassPoints;
			packetInfo->season = battlePassFree->m_season;//Cloud add Season
			
			//LOG_INFO("MSG_BATTLE_PASS: Progress: %d", packetInfo->progress);

			int i = 0;
			int index;
			map_battle_pass_t::iterator it = gserver->m_listBattlePass.begin();
			map_battle_pass_t::iterator endit = gserver->m_listBattlePass.end();
			for(; it != endit; ++it)
			{
				index = (*it).first;
				if (index <= pageLimit && index > pageLimit - MAX_BATTLE_PASS_PAGE_LIMIT)
				{
					CBattlePass * battlePass = (*it).second;
					if (battlePass == NULL)
						return false;

					const std::vector<CItem*> rewardItems = battlePass->getItemsReward();
					if (rewardItems.size() == 0)
						continue;

					packetInfo->list[i].level = battlePass->m_level;
					packetInfo->list[i].points = battlePass->m_points;
					
					strncpy(packetInfo->list[i].name, battlePass->m_name.c_str(), 50);

					packetInfo->list[i].item_index = rewardItems[0]->getDBIndex();
					packetInfo->list[i].item_count = rewardItems[0]->Count();

					const std::vector<CItem*> premiumRewardItems = battlePass->getPremiumItemsReward();
					if (premiumRewardItems.size() == 0)
						continue;

					packetInfo->list[i].premium_item_index = premiumRewardItems[0]->getDBIndex();
					packetInfo->list[i].premium_item_count = premiumRewardItems[0]->Count();

					i++;
				}
			}

			packetInfo->total = i;
			LOG_INFO("MSG_BATTLE_PASS: Total: %d", packetInfo->total);
		}

		//LOG_INFO("MSG_BATTLE_PASS: SIZE MSG: %d", sizeof(ResponseClient::battlePassInfo) + ( sizeof(ResponseClient::battlePassItem) * packetInfo->total));
		rmsg->setSize( sizeof(ResponseClient::battlePassInfo) + ( sizeof(ResponseClient::battlePassItem) * packetInfo->total));
		SEND_Q(rmsg, pc->m_desc);
	}

	return true;
}

#endif