/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

CDLLEntityEvent *CMovableModelEntity_events[] = {NULL};
#define CMovableModelEntity_eventsct 0
#define ENTITYCLASS CMovableModelEntity

CEntityProperty CMovableModelEntity_properties[] = {
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000002<<8)+1, offsetof(CMovableModelEntity, en_iCollisionBox), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000002<<8)+2, offsetof(CMovableModelEntity, en_iWantedCollisionBox), "", 0, 0, 0),
};
#define CMovableModelEntity_propertiesct ARRAYCOUNT(CMovableModelEntity_properties)

CEntityComponent CMovableModelEntity_components[] = {
	CEntityComponent()
};
#define CMovableModelEntity_componentsct 0


CEventHandlerEntry CMovableModelEntity_handlers[] = {
 {0x00020000, -1, CEntity::pEventHandler(&CMovableModelEntity::
#line 158 "C:/Users/djcyb/Desktop/BAckups/Reco_Csrc/Engine/Classes/MovableModelEntity.es"
Dummy),DEBUGSTRING("CMovableModelEntity::Dummy")},
 {0x00020001, -1, CEntity::pEventHandler(&CMovableModelEntity::
#line 161 "C:/Users/djcyb/Desktop/BAckups/Reco_Csrc/Engine/Classes/MovableModelEntity.es"
WaitUntilScheduledAnimStarts),DEBUGSTRING("CMovableModelEntity::WaitUntilScheduledAnimStarts")},
 {0x00020002, -1, CEntity::pEventHandler(&CMovableModelEntity::H0x00020002_WaitUntilScheduledAnimStarts_01), DEBUGSTRING("CMovableModelEntity::H0x00020002_WaitUntilScheduledAnimStarts_01")},
 {0x00020003, -1, CEntity::pEventHandler(&CMovableModelEntity::H0x00020003_WaitUntilScheduledAnimStarts_02), DEBUGSTRING("CMovableModelEntity::H0x00020003_WaitUntilScheduledAnimStarts_02")},
 {0x00020004, -1, CEntity::pEventHandler(&CMovableModelEntity::H0x00020004_WaitUntilScheduledAnimStarts_03), DEBUGSTRING("CMovableModelEntity::H0x00020004_WaitUntilScheduledAnimStarts_03")},
};
#define CMovableModelEntity_handlersct ARRAYCOUNT(CMovableModelEntity_handlers)

CEntity *CMovableModelEntity_New(void) { return new CMovableModelEntity; };
void CMovableModelEntity_OnInitClass(void) {};
void CMovableModelEntity_OnEndClass(void) {};
void CMovableModelEntity_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CMovableModelEntity_OnWorldEnd(CWorld *pwo) {};
void CMovableModelEntity_OnWorldInit(CWorld *pwo) {};
void CMovableModelEntity_OnWorldTick(CWorld *pwo) {};
void CMovableModelEntity_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CMovableModelEntity, CMovableEntity, "MovableModelEntity", "", 0x00000002);
DECLARE_CTFILENAME(_fnmCMovableModelEntity_tbn, "");
