#include "stdhdrs.h"
#include "Server.h"
#include "CmdMsg.h"
#include "Character.h" 
#include "CloudThings.h"

#include "DBManager.h"


#include "../ShareLib/packetType/ptype_old_do_move.h"


#define _snprintf snprintf //

#ifdef BATTLE_PASS_SYSTEM
void ResetBattlePass()
{
	GAMELOG << init("BATTLE PASS RELOAD") << "START" << end;
	gserver->LoadBattlePass();
	
	if(gserver->m_subno == 1)
	{
		std::string CharInfo ="";
		CharInfo = "UPDATE t_characters SET a_battle_pass_level = 0, a_battle_pass_points = 0, a_battle_pass_premium = 0";
		DBManager::instance()->pushQuery(0, CharInfo);
	}

	PCManager::map_t& playerMap			= PCManager::instance()->getPlayerMap();
	PCManager::map_t::iterator it		= playerMap.begin();
	PCManager::map_t::iterator endIt	= playerMap.end();

	for (; it != endIt; ++it)
	{
		CPC* pChar = (*it).pPlayer;
		if (pChar == NULL)
					continue;
		if (STATE(pChar->m_desc) == CON_PLAYING && PCManager::instance()->isPlaying(pChar))
		{

			pChar->m_battlePassPoints = 0;
			pChar->m_battlePassLevel = 0;
			pChar->m_battlePassPremium = 0;
			pChar->CalcStatus(true);

		}
	}//for

	int season = 0;//Cloud add Season
	CBattlePass * bp = gserver->FindBattlePassByLevel(1);
	if (bp)
	{
		season = bp->m_season;
	}

	{
		CNetMsg::SP rmsg(new CNetMsg);
		rmsg->Init(MSG_EXTEND);
		RefMsg(rmsg) << MSG_EX_STRING
			<< (unsigned char) MSG_EX_STRING_OUTPUT_SYS
			<< 100520//string idx
			<< 1//arg1
			<< 1//type int
			<< season;//int data1
		PCManager::instance()->sendToAll(rmsg);
	}

	GAMELOG << init("BATTLE PASS RELOAD") << "END" << end;
}
#endif
