/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _Classes_PlayerEntity_INCLUDED
#define _Classes_PlayerEntity_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CPlayerEntity_DLLClass;
class DECL_DLL  CPlayerEntity : public CMovableModelEntity {
public:
	 virtual void SetDefaultProperties(void);
	FLOAT en_tmPing;
CPlayerCharacter en_pcCharacter;
CPlacement3D en_plViewpoint;
CPlacement3D en_plLastViewpoint;
   
#line 27 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
void InitializePlayer(ULONG ulWeaponsID,ULONG ulAnimatorID);
  
#line 38 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetWeaponAndAnimator();
  
#line 41 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsPlayer();
  
#line 44 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void DumpToConsole();
  
#line 55 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_Mob(int index,CNetworkMessage * istr);
  
#line 56 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_Character(int type,int sub_type,CNetworkMessage * istr);
  
#line 57 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_Pet(int index,CNetworkMessage * istr);
  
#line 58 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_WildPet(int index,CNetworkMessage * istr);
  
#line 59 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_Summon(int index,CNetworkMessage * istr);
  
#line 60 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_Damage_Character(CNetworkMessage * istr);
  
#line 61 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_Damage(SBYTE sbType,CNetworkMessage * istr);
  
#line 62 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_DissappearEffect(CNetworkMessage * istr);
  
#line 63 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_StatusPC(CNetworkMessage * istr);
  
#line 64 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_StatusNPC(CNetworkMessage * istr);
  
#line 65 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_StatusPet(CNetworkMessage * istr);
  
#line 66 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Read_net_StatusElemental(CNetworkMessage * istr);
  
#line 67 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ProcessProduce(SBYTE sbChaType,SLONG slChaIndex,SBYTE sbTargetType,SLONG slTargetIndex,SLONG slTargetHP);
  
#line 69 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void StandDown(BOOL bStand);
  
#line 70 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void OpenGate(int iGateNumber,BOOL bOpenGate);
  
#line 71 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetMobData(CEntity * penEntity,SLONG hp,SLONG maxHp,int level,BOOL bNpc,int mobIdx);
  
#line 72 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetChaData(int index,int type,ULONG hp,ULONG maxHp,SBYTE hairstyle,SBYTE facestyle,CTString & strName,UWORD state,SBYTE pkTitle,SLONG pkstate);
  
#line 73 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetPetData(CEntity * penEntity,SLONG hp,SLONG maxHP);
  
#line 74 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetWildPetData(CEntity * penEntity,SLONG hp,SLONG maxHP);
  
#line 75 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetElementalData(CEntity * penEntity,SLONG hp,SLONG maxHP);
  
#line 76 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetElementalStatus(CEntity * penEntity,SBYTE sbAttackSpeed,SBYTE sbMagicSpeed,LONG lSkillSpeed,FLOAT fWalkSpeed,FLOAT fRunSpeed,FLOAT fAttackRange);
  
#line 77 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetShopData(INDEX index,SBYTE sbShopType);
  
#line 80 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetImportantValues(FLOAT fWalkspeed,FLOAT fRunspeed,FLOAT fRunspeedfix,FLOAT fAttackrange,SBYTE sbAttackspeed,SBYTE sbAttackspeedfix,SBYTE sbMagicspeed,SBYTE sbSkillspeed);
  
#line 81 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual FLOAT GetWalkspeed();
  
#line 82 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual FLOAT GetRunspeed();
  
#line 83 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual FLOAT GetAttackrange();
  
#line 84 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual SBYTE GetAttackspeed();
  
#line 85 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual SBYTE GetMagicspeed();
  
#line 86 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual FLOAT SouthLC_01();
  
#line 87 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual SBYTE SouthLC_03();
  
#line 88 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual FLOAT SouthLC_04();
  
#line 90 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetSkillCancel(BOOL bCanSkillCancel);
  
#line 92 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void StartCamera(CEntity * pTarget,BOOL bRestart);
  
#line 93 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetWideScreen(CEntity * pTarget,BOOL bWide,FLOAT fFov);
  
#line 94 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void GetProjection(CAnyProjection3D & apr);
  
#line 96 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void LostTarget();
  
#line 97 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void UseSkill(int skillIndex);
  
#line 98 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void UsePetPickItem();
  
#line 99 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void UsePetSkill(int skillIndex);
  
#line 100 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void UseSlaveSkill(CEntity * pEntity,int skillIndex);
  
#line 101 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void UseWildSkill(CEntity * pEntity,int skillIndex);
  
#line 103 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void CancelSkill(BOOL bLostTarget,BOOL bAutoAttack,BOOL bSkillError);
  
#line 104 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void LoadSkillAnimID();
  
#line 105 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void UseAction(int ActionIndex);
  
#line 106 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void StopMove();
  
#line 107 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ClearMove();
  
#line 110 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetProduct(SLONG slChaIndex,SBYTE slProductType);
  
#line 111 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetConsensus(SLONG slChaIndex);
  
#line 112 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void WarpTeleport(FLOAT fX,FLOAT fZ,FLOAT fH,FLOAT fR,SBYTE sbLayer);
  
#line 114 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SingleModeOn();
  
#line 115 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void FieldModeOn();
  
#line 117 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetLegit(UBYTE sbType,SLONG chaindex);
  
#line 118 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetRepairLegit(SLONG chaindex,CCharacterTarget * Ct);
  
#line 119 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsLegit();
  
#line 120 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ClearMultiTargets();
  
#line 122 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void RidingPet(CEntity * pCharacter,INDEX iPetType);
  
#line 123 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void LeavingPet(CEntity * pCharacter);
  
#line 124 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsRidePet(CEntity * pCharacter);
  
#line 126 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void RidingWildPet(CEntity * pCharacter,CEntity * pWildPet,CTString strFileName);
  
#line 127 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void LeavingWildPet(CEntity * pCharacter);
  
#line 130 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsMoving();
  
#line 131 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsActionSitting();
  
#line 132 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsIdle();
  
#line 134 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual const BOOL IsTransform()const;
  
#line 136 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ClearTargetInfo(CEntity * penEntity);
  
#line 138 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetCharacterHairChange(INDEX nSIdx,SBYTE sbType,BOOL IsMe);
  
#line 139 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetCharacterAppearance(CModelInstance * pMI,int iJob,SBYTE sbHairStyle,SBYTE sbFaceStyle);
  
#line 140 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ChangeFaceMesh(CModelInstance * pMI,int iJob,SBYTE sbType);
  
#line 141 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ChangeHairMesh(CModelInstance * pMI,int iJob,SBYTE sbType);
  
#line 144 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void CancelProduct();
  
#line 145 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void DeleteWearingWeapon(BOOL bException,BOOL bMode);
  
#line 146 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void AppearWearingWeapon(BOOL bSkillEnd);
  
#line 149 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void DeleteDefaultArmor(int type);
  
#line 150 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void WearingDefaultArmor(int type);
  
#line 151 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void DeleteCurrentArmor(int weartype);
  
#line 152 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetChaWearing(class CCharacterTarget * pTarget,CEntity * penEntity,CNetworkMessage * istr);
  
#line 153 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetCharCostumeWearing(class CCharacterTarget * pTarget,CEntity * penEntity,CNetworkMessage * istr);
  
#line 154 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void WearingCostumeArmor(CNetworkMessage * istr);
  
#line 155 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void WearingCostumeArmorOneSuit(CNetworkMessage * istr);
  
#line 156 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsHelmet(INDEX iCharIndex);
  
#line 157 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void Rebirth();
  
#line 158 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void DeathYou();
  
#line 159 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayerInit(bool bDeath);
  
#line 160 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsAlreadyDie();
  
#line 161 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetDie();
  
#line 162 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetTarget(CEntity * penEntity);
  
#line 163 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetTarget(SLONG targetID,SBYTE targetType);
  
#line 164 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsSameTarget(CEntity * penEntity);
  
#line 166 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetTargetMe();
  
#line 167 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayItemSound(BOOL bPick,BOOL bMoney);
  
#line 168 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayButtonSound();
  
#line 169 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayJewelDullSound();
  
#line 170 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayJewelRefinementSound();
  
#line 171 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayJewelShinySound();
  
#line 172 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayPetStashEffectSound();
  
#line 173 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayPetStashCardSelSound();
  
#line 174 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayHolyWaterSound();
  
#line 176 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void CommandAttack();
  
#line 177 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL CommandAction();
  
#line 179 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayBGM(CTFileName fnFileName);
  
#line 181 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SearchNearItem();
  
#line 182 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetCharacterState(CEntity * cha_Entity,INDEX ch_state);
  
#line 184 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsSkilling();
  
#line 185 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsSitting();
  
#line 186 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsAttacking();
  
#line 187 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsPetActing();
  
#line 188 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsProduct();
  
#line 189 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetSpeedUp(BOOL bMe,INDEX index,BOOL bSpeedup);
  
#line 191 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL CheckEscKey(void);
  
#line 192 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlayItemEffect(SLONG itemindex,SBYTE effecttype);
  
#line 193 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsSocialActing();
  
#line 194 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsPolymophing();
  
#line 195 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsTransforming();
  
#line 196 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsChanging();
  
#line 197 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void AppearChaPolymoph(CEntity * pentity,INDEX mobindex);
  
#line 198 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void TransfromPet(CEntity * pentity,INDEX mobIndex,INDEX mobSize);
  
#line 199 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ReturnTransformPet(CEntity * pentity);
  
#line 201 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void TransformSorcerer(int iType);
  
#line 202 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ReturnSorcerer();
  
#line 203 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void AppearChaTransform(CEntity * pEntity,INDEX iTransformType);
  
#line 206 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void PlAddAccessoryEffect(CEntity * penEntity,CCharacterTarget * pTarget);
  
#line 208 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void EnemyTargetSelected_InputTab();
  
#line 211 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void EvocationStart(LONG lIndex,int nSkillIndex);
  
#line 212 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void EvocationStop(LONG lIndex);
  
#line 213 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL CheckChangeCondition(INDEX level,INDEX zone);
  
#line 214 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetSummonCommand(CEntity * pEntity,INDEX iCommand);
  
#line 216 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL CheckNormalAttack(CEntity * pEntity,FLOAT fDist);
  
#line 217 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual CModelInstance * GetPlayerModelInstance(CEntity * pEntity);
  
#line 218 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL CheckAttackTarget(INDEX iSkillIndex,CEntity * pEntity,FLOAT fDist);
  
#line 219 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL CheckEntityOfTarget(CEntity * pEntity,CEntity * pTarget);
  
#line 221 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ReturnChange(BOOL bAppear);
  
#line 225 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void AddDeathItem(CEntity * penEnemy,FLOAT3D pos,class CItemTarget * pItemTarget,class CItemData * pItemData);
  
#line 228 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ReceiveTriggerEvent(INDEX iIn,INDEX iOut,INDEX iContinued,CNetworkMessage * iStr);
  
#line 229 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void ReceiveRaidScene(CNetworkMessage * istr);
  
#line 230 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SendTriggerEvent(INDEX iTarget,INDEX eetEventType);
  
#line 231 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual CEntity * GetClickObject(void);
  
#line 233 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void DropDeathItem(CEntity * penEnemy);
  
#line 235 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_DrawModel(CDrawPort * pdp,FLOAT fMinX,FLOAT fMinY,FLOAT fMaxX,FLOAT fMaxY,INDEX iType,FLOAT fDistance,FLOAT fHeight);
  
#line 236 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual FLOAT GetAnimationTime();
  
#line 237 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_SetCharModelData(INDEX iJob,INDEX iHairStyle,INDEX iFaceStyle);
  
#line 238 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_SetModelData(INDEX iType,INDEX iIndex,INDEX iUIType);
  
#line 239 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_WearingModel(INDEX iType,INDEX iJob,INDEX iItem,BOOL bLogin);
  
#line 240 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_ChangeHairMesh(INDEX iJob,INDEX iHairStyle);
  
#line 241 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_ChangeFaceMesh(INDEX iJob,INDEX iFaceStyle);
  
#line 242 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_PlayAnimation(INDEX iJob,INDEX AnimID);
  
#line 243 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_PlayAnimation(CTString strAniName);
  
#line 244 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_SetModelColor(const COLOR ModelColor);
  
#line 245 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void HUD_SetTitleEffect(CTString strEffectName);
  
#line 246 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual BOOL IsHudModel_Used();
  
#line 247 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetHudModel_Use(BOOL bUse);
  
#line 248 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetDecoModeCamera(FLOAT fDistance,FLOAT fHeight);
  
#line 249 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
virtual void SetAppearanceData(int inde,SBYTE hairstyle,SBYTE facestyle);
   CTString GetPlayerName(void);
   const CTString & GetName(void)const;
   INDEX GetMyPlayerIndex(void);
   void DoMoving(void);
   void Copy(CEntity & enOther,ULONG ulFlags);
   void Read_t(CTStream * istr,BOOL bNetwork);
   void Write_t(CTStream * ostr,BOOL bNetwork);
  virtual void ApplyAction(const CPlayerAction & pa,FLOAT tmLatency);
  virtual void Disconnect(void);
  virtual void CharacterChanged(const CPlayerCharacter & pcNew);
#define  STATE_CPlayerEntity_Dummy 0x00040000
	BOOL 
#line 328 "C:/Src/Defualt/Client/Engine/Classes/PlayerEntity.es"
Dummy(const CEntityEvent &__eeInput);
};
#endif // _Classes_PlayerEntity_INCLUDED
