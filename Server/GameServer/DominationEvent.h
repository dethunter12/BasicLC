
#ifndef _DOMINATION_EVENT__
#define _DOMINATION_EVENT__

#include <vector>
#include "Zone.h"

#ifdef DOMINATION_EVENT_SYSTEM

typedef struct _FlagAttack {
    int charIndex;
    int npcIndex;
} FlagAttack;

class DominationTeam {

private:
    std::vector<int> m_members;
    int m_id;
    int m_points;
    std::vector<int> m_flags;

public:
    DominationTeam();
    ~DominationTeam();

    enum {
        TEAM_A = 0,
        TEAM_B,
        MAX_TEAMS
    };

    void MoveTeam(int zone, int extra);
    
    CPC* GetMember(int index);
    int GetCountMembers() { return m_members.size(); }
    bool AddMember(int charIndex);
    bool RemoveMember(int charIndex);
    bool IsMember(int charIndex);

    bool GetId() { return m_id; }
    bool Clear();
    int GetPoints() { return m_points; }
    void AddPoint();
    
    void AddFlag(int npcIndex);
    void RemoveFlag(int npcIndex);
    bool HaveFlag(int npcIndex);
};

class DominationEvent {

public:
    DominationEvent();
    ~DominationEvent();

    enum {
        DOMIN_OPEN = 0,
        DOMIN_RUNNING,
        DOMIN_CLOSED
    };

    enum {
        FLAG_EMPTY = 0,
        FLAG_ATTACK,
        FLAG_TEAM_A,
        FLAG_TEAM_B,
    };

    bool Load();

    void Open();
    void Stop();
    void CheckStart();
    void CheckEnd();
    void AddPoint();
    void AddFlag(CPC* pc, int npcIndex);
    void CheckRespond(CPC * ch);
    void AddAttackFlag(CPC* pc, int npcIndex);
    int GetStatusFlag(int npcIndex);
    bool CanCollect(int npcIndex);
    void MsgUpdateInfo(CNetMsg::SP& msg, int status);

    bool IsRunning() { return m_state == DOMIN_RUNNING; }
    bool IsClosed() { return m_state == DOMIN_CLOSED; }
    void SplitTeam();
    bool Register(CPC* pc);
    bool IsRegisteredTeam(CPC* pc);
    bool IsRegisteredPlayer(CPC* pc);
    bool IsWaitTime(CPC* pc);

    void SendUpdateInfoAll();
    void SendUpdateInfo(CPC* ch);

private:
    DominationTeam m_teams[DominationTeam::MAX_TEAMS];
    std::vector<int> m_players;
    std::vector<FlagAttack> m_flagsAttack;
    int m_state;
    time_t m_tmStart;
    time_t m_tmPoint;
    int m_zone;
    int m_extra;
    int m_timePoint;
    int m_minMembers;
    int m_maxPoints;
    int m_timeStart;
};

#endif

#endif