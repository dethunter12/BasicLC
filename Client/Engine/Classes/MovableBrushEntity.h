/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _Classes_MovableBrushEntity_INCLUDED
#define _Classes_MovableBrushEntity_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CMovableBrushEntity_DLLClass;
class DECL_DLL  CMovableBrushEntity : public CMovableEntity {
public:
	 virtual void SetDefaultProperties(void);
   void DoMoving(void);
   void Read_t(CTStream * istr,BOOL bNetwork);
   void Write_t(CTStream * ostr,BOOL bNetwork);
#define  STATE_CMovableBrushEntity_Dummy 0x00030000
	BOOL 
#line 46 "C:/Users/djcyb/Desktop/BAckups/Reco_Csrc/Engine/Classes/MovableBrushEntity.es"
Dummy(const CEntityEvent &__eeInput);
};
#endif // _Classes_MovableBrushEntity_INCLUDED
