#include "stdhdrs.h"

#include "Server.h"
#include "CmdMsg.h"
#include "Log.h"

#ifdef DOMINATION_EVENT_SYSTEM

bool do_DominationJoinReq(CPC* pc, CNetMsg::SP& msg);
bool do_DominationAddFlag(CPC* pc, CNetMsg::SP& msg);
bool do_DominationCollectStart(CPC* ch, CNetMsg::SP& msg);

void do_DominationEvent(CPC* pc, CNetMsg::SP& msg)
{
	unsigned char subtype;

	msg->MoveFirst();

	RefMsg(msg) >> subtype;

	switch (subtype)
	{
	case MSG_DOMINATION_EVENT_REGISTER_REQ:
		{
			if (do_DominationJoinReq(pc, msg) == false)
				return;
		}
		break;
	case MSG_DOMINATION_EVENT_ADD_FLAG:
		{
			if (do_DominationAddFlag(pc, msg) == false)
				return;
		}
		break;
	case MSG_DOMINATION_EVENT_COLLECT_START:
		{
			if (do_DominationCollectStart(pc, msg) == false)
				return;
		}
		break;
	default:
		{
			LOG_ERROR("HACKING : invalid subtype[%d]. charIndex[%d]", subtype, pc->m_index);
			pc->m_desc->Close("invalid subtype");
			return;
		}
	}

}

bool do_DominationJoinReq(CPC* ch, CNetMsg::SP& msg)
{

	if (gserver->m_dominationEvent.IsRunning() ||
		gserver->m_dominationEvent.IsClosed())
	{
		CNetMsg::SP rmsg(new CNetMsg);
		rmsg->Init(MSG_DOMINATION_EVENT);
		RefMsg(rmsg) << (unsigned char) MSG_DOMINATION_EVENT_REGISTER_REP;
		RefMsg(rmsg) << (int)0;
		SEND_Q(rmsg, ch->m_desc);
		return false;
	}
	
	if (gserver->m_dominationEvent.IsRegisteredPlayer(ch))
	{
		CNetMsg::SP rmsg(new CNetMsg);
		rmsg->Init(MSG_DOMINATION_EVENT);
		RefMsg(rmsg) << (unsigned char) MSG_DOMINATION_EVENT_REGISTER_REP;
		RefMsg(rmsg) << (int)1;
		SEND_Q(rmsg, ch->m_desc);
		return false;
	}

	gserver->m_dominationEvent.Register(ch);

	{
		CNetMsg::SP rmsg(new CNetMsg);
		rmsg->Init(MSG_DOMINATION_EVENT);
		RefMsg(rmsg) << (unsigned char) MSG_DOMINATION_EVENT_REGISTER_REP;
		RefMsg(rmsg) << (int)2;
		SEND_Q(rmsg, ch->m_desc);
	}

	gserver->m_dominationEvent.SendUpdateInfo(ch);

	return true;
}

bool do_DominationAddFlag(CPC* ch, CNetMsg::SP& msg)
{
	int npcIndex;
	RefMsg(msg) >> npcIndex;

	if (gserver->m_dominationEvent.IsRunning() &&
		gserver->m_dominationEvent.IsRegisteredTeam(ch))
	{
		gserver->m_dominationEvent.AddFlag(ch, npcIndex);

		{
			CNetMsg::SP rmsg(new CNetMsg);
			CastleCristalRespondEndMsg(rmsg, ch);
			ch->m_pArea->SendToAllClient(rmsg);
		}
	}

	return true;
}

bool do_DominationCollectStart(CPC* ch, CNetMsg::SP& msg)
{
	int npcIndex;
	RefMsg(msg) >> npcIndex;

	if (gserver->m_dominationEvent.IsRunning() &&
		gserver->m_dominationEvent.IsRegisteredTeam(ch))
	{

		if (!gserver->m_dominationEvent.CanCollect(npcIndex))
			return false;
		
		ch->SetPlayerState(PLAYER_CRISTAL_RESPOND);

		time_t curTime;
		time(&curTime);

		ch->SetRespondTime(curTime);

		gserver->m_dominationEvent.AddAttackFlag(ch, npcIndex);

		{
			CNetMsg::SP rmsg(new CNetMsg);
			CastleCristalRespondStartMsg(rmsg, ch);
			ch->m_pArea->SendToCell(rmsg, ch, true);
		}
	}

	return true;
}
#endif