#include <boost/format.hpp>
#include <boost/static_assert.hpp>
#include <boost/foreach.hpp>
#include "stdhdrs.h"

#include "gameserver_config.h"
#include "Log.h"
#include "Server.h"
#include "Cmd.h"
#include "CmdMsg.h"
#include "../ShareLib/DBCmd.h"
#include "doFunc.h"
#include "WearInvenManager.h"
#include "../ShareLib/packetType/ptype_server_to_server.h"

#include "DominationEvent.h"

#ifdef DOMINATION_EVENT_SYSTEM

#define MAX_FLAG 3

DominationEvent::DominationEvent()
{
    m_zone = -1;
    m_extra = 0;
    m_state = DOMIN_CLOSED;
    m_timePoint = 0;
    m_minMembers = 0;
    m_maxPoints = 0;
    m_timeStart = 0;
}

DominationEvent::~DominationEvent()
{
}

bool DominationEvent::Load()
{
    std::string query = "SELECT * FROM t_domination_config";
	CDBCmd cmd;
	cmd.Init(&gserver->m_dbdata);
	cmd.SetQuery(query.c_str());
	if (!cmd.Open() || !cmd.MoveFirst())
        return false;
    
    cmd.GetRec("a_zone", m_zone);
    cmd.GetRec("a_extra", m_extra);
    cmd.GetRec("a_time_point", m_timePoint);
    cmd.GetRec("a_min_members", m_minMembers);
    cmd.GetRec("a_max_points", m_maxPoints);
    cmd.GetRec("a_time_start", m_timeStart);

    return true;
}

void DominationEvent::Open()
{
    time(&m_tmStart);
    m_state = DOMIN_OPEN;

    gserver->addActiveEvent(A_EVENT_DOMINATION_PVP);

    SendUpdateInfoAll();
}

void DominationEvent::CheckStart()
{
    if (m_state != DOMIN_OPEN)
        return;
    
    if (m_players.size() < m_minMembers)
        return;
    
    if (m_players.size() % 2 != 0)
        return;
    
    time_t tmNow;
    time(&tmNow);
    
    if (tmNow - m_tmStart > m_timeStart * TIME_ONE_MIN)
    {
        SplitTeam();

        for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
            m_teams[i].MoveTeam(m_zone, m_extra);

        time(&m_tmPoint);
        m_state = DOMIN_RUNNING;
    }
}

void DominationEvent::SplitTeam()
{
    LOG_INFO("DOM_EVENT: TOTAL PLAYERS %d", m_players.size() );

    int teamSize = m_players.size() / 2;
    int i, pos;
    for (i = 0; i < teamSize; i++)
    {
        pos = GetRandom(0, m_players.size() - 1);
        
        if (m_players[pos])
            m_teams[DominationTeam::TEAM_A].AddMember(m_players[pos]);
        
        m_players.erase(m_players.begin() + pos);
    }
    
    for (i = 0; i < m_players.size(); i++)
    {
        m_teams[DominationTeam::TEAM_B].AddMember(m_players[i]);
    }

    LOG_INFO("DOM_EVENT: TEAM A %d",  m_teams[DominationTeam::TEAM_A].GetCountMembers());
    LOG_INFO("DOM_EVENT: TEAM B %d",  m_teams[DominationTeam::TEAM_B].GetCountMembers());

    m_players.clear();
}

void DominationEvent::Stop()
{
    m_state = DOMIN_CLOSED;

    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
    {
        m_teams[i].MoveTeam(0, 0);
        m_teams[i].Clear();
    }

    m_players.clear();
    m_flagsAttack.clear();

    gserver->removeActiveEvent(A_EVENT_DOMINATION_PVP);

    SendUpdateInfoAll();
}

void DominationEvent::CheckEnd()
{
    bool IsWin = false;

    time_t tmNow;
    time(&tmNow);

    if (tmNow - m_tmPoint > m_timePoint)
    {
        AddPoint();
        m_tmPoint = tmNow;
    }
    

    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
    {
        if (m_teams[i].GetPoints() > m_maxPoints)
            IsWin = true;
    }

    if (IsWin)
    {
        Stop();
    }
}

void DominationEvent::CheckRespond(CPC * ch)
{
    if (!IsRegisteredTeam(ch))
        return;

	if (ch->IsSetPlayerState(PLAYER_CRISTAL_RESPOND) == true)
	{
		if (ch->m_pZone != NULL && ch->m_pZone->m_index == m_zone)
		{
            CNetMsg::SP rmsg(new CNetMsg);
            CastleCristalRespondFailMsg(rmsg, ch);
            ch->m_pArea->SendToCell(rmsg, ch, true);
        }

        ch->ResetPlayerState(PLAYER_CRISTAL_RESPOND);
        ch->SetRespondTime(0);

        for (int i = 0; i < m_flagsAttack.size(); i++)
        {
            if (m_flagsAttack[i].charIndex == ch->m_index) {
                m_flagsAttack.erase(m_flagsAttack.begin() + i);
                break;
            }
        }

        SendUpdateInfoAll();
	}
}

void DominationEvent::AddAttackFlag(CPC* pc, int npcIndex)
{
    FlagAttack flag;
    flag.charIndex = pc->m_index;
    flag.npcIndex = npcIndex;
    m_flagsAttack.push_back(flag);

    SendUpdateInfoAll();
}

bool DominationEvent::Register(CPC* pc)
{
    if (IsRegisteredPlayer(pc))
        return false;
    
    if (m_state == DOMIN_OPEN)
    {
        m_players.push_back(pc->m_index);
        return true;
    }

    return false;
}

bool DominationEvent::IsRegisteredPlayer(CPC* pc)
{
    for (int i = 0; i < m_players.size(); i++)
    {
        if (m_players[i] == pc->m_index)
            return true;
    }

    return false;
}

bool DominationEvent::IsRegisteredTeam(CPC* pc)
{
    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
    {
        if (m_teams[i].IsMember(pc->m_index))
            return true;
    }

    return false;
}

void DominationEvent::AddPoint()
{
    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
    {
        m_teams[i].AddPoint();
    }

    SendUpdateInfoAll();
}

void DominationEvent::MsgUpdateInfo(CNetMsg::SP& msg, int status)
{
    int flags[MAX_FLAG] = { 1773, 1774, 1775 };

    msg->Init(MSG_DOMINATION_EVENT);
    RefMsg(msg) << (unsigned char) MSG_DOMINATION_EVENT_UPDATE_POINT;
    RefMsg(msg) << m_teams[DominationTeam::TEAM_A].GetPoints();
    RefMsg(msg) << m_teams[DominationTeam::TEAM_B].GetPoints();
    RefMsg(msg) << m_state;
    RefMsg(msg) << status;
    RefMsg(msg) << m_zone;
    for (int i = 0; i < MAX_FLAG; i++)
    {
        RefMsg(msg) << GetStatusFlag(flags[i]);
    }
}

void DominationEvent::SendUpdateInfo(CPC* ch)
{
    if (IsClosed())
    {
        CNetMsg::SP rmsg(new CNetMsg);
        MsgUpdateInfo(rmsg, 0);
        SEND_Q(rmsg, ch->m_desc);
    }
    else if (IsRegisteredPlayer(ch) || IsRegisteredTeam(ch))
    {
        CNetMsg::SP rmsg(new CNetMsg);
        MsgUpdateInfo(rmsg, 1);
        SEND_Q(rmsg, ch->m_desc);
    }
}

void DominationEvent::SendUpdateInfoAll()
{
    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++) {
         for (int j = 0; j < m_teams[i].GetCountMembers(); j++) {
            CPC* pc = m_teams[i].GetMember(j);
            if (pc) 
            {
                CNetMsg::SP rmsg(new CNetMsg);
                MsgUpdateInfo(rmsg, 1);
                SEND_Q(rmsg, pc->m_desc);
            }
        }
    }
}

int DominationEvent::GetStatusFlag(int npcIndex)
{
    int status = DominationEvent::FLAG_EMPTY;

    if (m_teams[DominationTeam::TEAM_A].HaveFlag(npcIndex))
        status = DominationEvent::FLAG_TEAM_A;
    else if (m_teams[DominationTeam::TEAM_B].HaveFlag(npcIndex))
        status = DominationEvent::FLAG_TEAM_B;
    
    for (int i = 0; i < m_flagsAttack.size(); i++) {
        if (m_flagsAttack[i].npcIndex == npcIndex && status != DominationEvent::FLAG_EMPTY)
            return DominationEvent::FLAG_ATTACK;
    }

    return status;
}

void DominationEvent::AddFlag(CPC* pc, int npcIndex)
{
    m_teams[DominationTeam::TEAM_A].RemoveFlag(npcIndex);
    m_teams[DominationTeam::TEAM_B].RemoveFlag(npcIndex);

    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
    {
        if (m_teams[i].IsMember(pc->m_index))
        {
            pc->ResetPlayerState(PLAYER_CRISTAL_RESPOND);
            pc->SetRespondTime(0);
            pc->CalcStatus(true);

            m_teams[i].AddFlag(npcIndex);

            std::string chatMsg;
            if (i == DominationTeam::TEAM_A)
                chatMsg = boost::str(boost::format("%s captured a new flag for Team: A") % pc->m_nick.getBuffer());
            else
                chatMsg = boost::str(boost::format("%s captured a new flag for Team: B") % pc->m_nick.getBuffer());
            
            {
                
                CNetMsg::SP rmsg(new CNetMsg);
                MsgrNoticeMsg(rmsg, -1, -1, -1, -1, chatMsg.c_str());
                SEND_Q(rmsg, gserver->m_messenger);
            }

            return;
        }
    }
}

bool DominationEvent::IsWaitTime(CPC* pc)
{
    if (!IsRunning())
        return false;

    if (!IsRegisteredTeam(pc))
        return false;
    
    if (pc->m_pZone->m_index != m_zone)
        return false;
    
    return true;
}

bool DominationEvent::CanCollect(int npcIndex)
{
    for (int i = 0; i < DominationTeam::MAX_TEAMS; i++)
        if (m_teams[i].HaveFlag(npcIndex))
            return false;
    return true;
}

DominationTeam::DominationTeam()
{
    m_points = 0;
}

DominationTeam::~DominationTeam()
{

}

CPC* DominationTeam::GetMember(int index)
{
    return PCManager::instance()->getPlayerByCharIndex(m_members[index]);
};

void DominationTeam::MoveTeam(int zone, int extra)
{
    CZone* pZone = gserver->FindZone(zone);
    if (pZone == NULL)
    {
        LOG_INFO("START: ZONE NOT FOUND: %d", zone);
        return;
    }

    for (int i = 0; i < m_members.size(); i++)
    {
        CPC* pc = PCManager::instance()->getPlayerByCharIndex(m_members[i]);

        unsigned short old_map_attr = pc->GetMapAttr();
        int old_extra = pc->m_pZone->GetExtra(GET_X(pc), GET_Z(pc));

        bool old_war_zone = pc->isWarZone();

        GoZone(pc, zone, pZone->m_zonePos[extra][0],
        GetRandom(pZone->m_zonePos[extra][1], pZone->m_zonePos[extra][3]) / 2.0f,
        GetRandom(pZone->m_zonePos[extra][2], pZone->m_zonePos[extra][4]) / 2.0f);

        unsigned short new_map_attr = pc->GetMapAttr();
        int new_extra = pc->m_pZone->GetExtra(GET_X(pc), GET_Z(pc));

        bool new_war_zone = pc->isWarZone();

        if (old_war_zone != new_war_zone)
        {
            pc->CalcStatus(true);
        }

        if (old_map_attr != new_map_attr)
        {
            pc->m_bChangeStatus = true;
        }
    }
}

bool DominationTeam::AddMember(int charIndex)
{
    for (int i = 0; i < m_members.size(); i++)
    {
        if (m_members[i] == charIndex)
            return false;
    }

    m_members.push_back(charIndex);

    return true;
}

bool DominationTeam::RemoveMember(int charIndex)
{
    int pos = -1;
    for (int i = 0; i < m_members.size(); i++)
    {
        if (m_members[i] == charIndex)
            pos = i;
    }

    if (pos == -1)
        return false;
    
    m_members.erase(m_members.begin() + pos);

    return true;
}

bool DominationTeam::IsMember(int charIndex)
{
    for (int i = 0; i < m_members.size(); i++)
    {
        if (m_members[i] == charIndex)
            return true;
    }
    
    return false;
}

bool DominationTeam::Clear()
{
    m_members.clear();
    m_flags.clear();
    m_points = 0;

    return true;
}

void DominationTeam::AddPoint()
{ 
    if (m_flags.size() == 1)
        m_points += 1;
    else if (m_flags.size() == 2)
        m_points += 2;
    else if (m_flags.size() == 3)
        m_points += 3;
}

void DominationTeam::AddFlag(int npcIndex)
{
    m_flags.push_back(npcIndex);  
}

void DominationTeam::RemoveFlag(int npcIndex)
{
    if (m_flags.size() == 0)
        return;
    
    int i = 0, delIdx = -1;
    for (; i < m_flags.size(); i++) {
        if (m_flags[i] == npcIndex) {
            delIdx = i;
            break;
        }
    }

    if (delIdx >= 0)
        m_flags.erase(m_flags.begin() + i);
}

bool DominationTeam::HaveFlag(int npcIndex)
{
    for (int i = 0; i < m_flags.size(); i++)
        if (m_flags[i] == npcIndex)
            return true;
    
    return false;
}
#endif