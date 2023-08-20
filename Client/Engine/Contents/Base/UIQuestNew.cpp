#include "stdh.h"

// Çì´õ Á¤¸®. [12/2/2009 rumist]
#include <vector>
#include <Engine/Interface/UIInternalClasses.h>
#include <Engine/Contents/Base/UIQuestNew.h>
#include <Engine/Interface/UISelectWord.h>
#include <Engine/Interface/UIShop.h>
#include <Engine/LocalDefine.h>
#include <Engine/Interface/UISiegeWarfareDoc.h>
#include <Engine/Contents/Base/UINoticeNew.h>
#include <Engine/Help/ItemHelp.h>
#include <Common/Packet/ptype_old_do_event.h>
#include <Engine/Interface/UIInventory.h>
#include <Engine/Interface/UISkillLearn.h>
#include <Engine/Interface/UIHelp.h>
#include <Engine/Interface/UIMinigame.h>
#include <Engine/Interface/UISiegeWarfareNew.h>
#include <Engine/Contents/Base/UIAuctionNew.h>
#include <Engine/Interface/UIFlowerTree.h>
#include <Engine/Interface/UIProduct.h>
#include <Engine/GameDataManager/GameDataManager.h>
#include <Engine/Contents/Base/Syndicate.h>
#include <Engine/Object/ActorMgr.h>
#include <Engine/Contents/Base/UITrade.h>
#include <Engine/Contents/Base/Quest.h>
#include <Engine/Contents/Base/UIQuestBookNew.h>
#include <Engine/Contents/Base/UIQuestAccept.h>
#include <Engine/Contents/Base/UIQuestComplete.h>
#include <Engine/Info/MyInfo.h>

#ifdef BATTLE_PASS_SYSTEM
#include <Engine/Interface/UIBattlePass.h>
#endif


extern INDEX g_iCountry;
extern INDEX g_iTempFlag;

// [KH_07044] 3Â÷ µµ¿ò¸» °ü·Ã Ãß°¡
extern INDEX g_iShowHelp1Icon;

ENGINE_API extern CUISiegeWarfareDoc* _pUISWDoc;

///////////////////////////////////////////////////////////////////////////////////////
//
// g_iTempflag :	< 0x0000**** - ZONE FLAG >				
//	(ps.dta)				
//					0x00000001 - ¾ÆÀÚÄ«Çù°î				0x00000002 - Â÷¿øÀÇ ¹® on/off
//					
//					< 0x****0000 - EVENT FLAG >
//
//					0x00010000 - WEAPONCHANGE_EVENT		0x00020000 - TREASURE_BOX_EVENT
//					0x00040000 - QUEST_HARVEST_MOON_DAY -> Replace Open Event(temporary) 
//					0x00080000 - Christmas Event	
//					0x00100000 - Newyear Event
//					0x00200000 - Coupon Event (JAPAN)
//					0x00400000 - Connect Event (JAPAN)	
//					0x80000000 - EVENT on/off
//
///////////////////////////////////////////////////////////////////////////////////////

//#define WEAPONCHANGE_EVENT		// ¹«±â ±³È¯ ÀÌº¥Æ®
#define TREASURE_BOX_EVENT			// º¸¹°»óÀÚ ÀÌº¥Æ®
//#define QUEST_HARVEST_MOON_DAY		// Ãß¼® ÀÌº¥Æ® 
//#define RENUAL_EVENT			// 2P4P Renual Event  10/6 Update
//#define PLATINUM_EVENT
//#define WORLDCUP_ITEM
//#define WORLDCUP_GOLDENBALL
#define XMAS_EVENT_2006				// 2006 X-MAS Event [12/11/2006 Theodoric]

// ¿ùµåÄÅÀÌº¥Æ®
#define WORLDCUP_MAX_GROUP 4

// ºÒ±³ ÃÐºÒ ÀÌº¥Æ®
//#define BUDDHISM_EVENT

//#define EVENT_REQUITALM //[ttos_2009_4_13]:¼­¹ö ¿À·ù º¸»óÀÌº¥Æ®

#define DEF_REGISTER_MERCHANT_NEED_SP	2000
#define DEF_REGISTER_MERCHANT_NEED_NAS	100000000

int	iSelCountry =-1;
int iSelGroup =-1;
int iGroup[WORLDCUP_MAX_GROUP+1] ={ 0, 5, 14, 23, 32 };


enum eWeaponChangeSelection
{
	EVENT_CHANGEWEAPON,
};

enum eGateOfDimensionSelection
{
	GOD_ENTER,						// Â÷¿øÀÇ ¹® ÀÔÀå
	GOD_RANKING,					// Â÷¿øÀÇ ¹® ¼øÀ§ È®ÀÎ
	GOD_PRIZE,						// º¸»ó
};

enum eClothesExchangeSelection
{
	COAT_PANTS,
	GLOVE_FOOTWEAR,
	HELMET,
};

enum ePlatiumExchangeSelection
{
	PLATINUM_STONE_EXCHANGE1,
	PLATINUM_STONE_EXCHANGE2,
	PLATINUM_STONE_EXCHANGE3
};

enum eWorldCupExchangeSelection
{
	WORLDCUP_EVENT1_EXCHANGE,
	WORLDCUP_EVENT1_RECEIVE,
	WORLDCUP_EVENT1_EXCHANGE100,
	WORLDCUP_EVENT1_EXCHANGE75,
	WORLDCUP_EVENT1_EXCHANGE50,
	WORLDCUP_EVENT1_EXCHANGE25,
	WORLDCUP_EVENT1_REWARD1,
	WORLDCUP_EVENT1_REWARD2,
	WORLDCUP_EVENT1_REWARD3,
	WORLDCUP_EVENT1_REWARD4,
};

// Date : 2005-03-07,   By Lee Ki-hwan
static int	_iMaxMsgStringChar = 0;

// WSS_GUILDMASTER 070416 ------------------------------------->>
BOOL CheckGuildMasterEvent()
{
	CUIManager* pUIManager = CUIManager::getSingleton();

	CTString	strMessage;
	CUIMsgBox_Info	MsgBoxInfo;	
	pUIManager->DoesMessageBoxExist(MSGCMD_NULL);
	
	if( pUIManager->GetInventory()->GetItemCount(2331) <= 0 ) // 2331 »¡°£ Ä«³×ÀÌ¼Ç
	{
		MsgBoxInfo.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®" ), UMBS_OK, UI_NONE, MSGCMD_NULL);		
		strMessage.PrintF( _S(2236,"ÀÌº¥Æ® ¾ÆÀÌÅÛÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.") );
		MsgBoxInfo.AddString( strMessage );
		pUIManager->CreateMessageBox( MsgBoxInfo );
		return FALSE;
	}
	
	return TRUE;
}
// ------------------------------------------------------------<<


// ----------------------------------------------------------------------------
// Name : CUIQuest()
// Desc : Constructor
// ----------------------------------------------------------------------------
CUIQuest::CUIQuest()
{
	m_iNpcIndex			= -1;
	m_iNpcVirIdx		= -1;
	m_iCurQuestIndex	= -1;

	for(int i=0 ; i< WORLDCUP_MAX_COUNTRY ;i++)
		m_strCountry[i] = _S(i+2858,"2006 ¿ùµåÄÅ º»¼± ÁøÃâ±¹");
/*
	"ºê¶óÁú","µ¶ÀÏ","ÀÌÅ»¸®¾Æ","¿µ±¹","¾Æ¸£ÇîÆ¼³ª",
	"ÇÁ¶û½º","³×´ú¶õµå","½ºÆäÀÎ","Æ÷¸£Åõ°¥","Ã¼ÄÚ",
	"½º¿þµ§","¸ß½ÃÄÚ","¿ìÅ©¶óÀÌ³ª","Å©·Î¾ÆÆ¼¾Æ","¹Ì±¹",
	"½ºÀ§½º","ÄÚÆ®µðºÎ¾Æ¸£","¼¼¸£ºñ¾Æ-¸óÅ×³×±×·Î","Æú¶õµå","ÆÄ¶ó°úÀÌ",
	"´ëÇÑ¹Î±¹","È£ÁÖ","ÀÏº»","°¡³ª","Æ¢´ÏÁö",
	"¿¡Äâµµ¸£","Åä°í","¾Ó°ñ¶ó","ÀÌ¶õ","»ç¿ìµð¾Æ¶óºñ¾Æ",
	"ÄÚ½ºÅ¸¸®Ä«","Æ®¸®´Ï´Ùµå Åä¹Ù°í",
	*/
	
	// ($E_WC2010) [100517: selo] ±¹±â ¾ÆÀÌÅÛ ¸®½ºÆ® ¸¸µé±â
	InitNationFlag();	
}

// ----------------------------------------------------------------------------
// Name : ~CUIQuest()
// Desc : Destructor
// ----------------------------------------------------------------------------
CUIQuest::~CUIQuest()
{
}

// -----------------------------------------------------------------------------
//  [5/17/2010 selo0530] ($E_WC2010)
//	Name : InitNationFlag
//	Desc : ±¹±â ¾ÆÀÌÅÛ ¸®½ºÆ® ¸¸µé±â
// -----------------------------------------------------------------------------
void CUIQuest::InitNationFlag()
{
	m_mapNationFlag.insert(std::make_pair(1485, 0));	// ºê¶óÁú
	m_mapNationFlag.insert(std::make_pair(1486, 0));	// µ¶ÀÏ
	m_mapNationFlag.insert(std::make_pair(1487, 0));	// ÀÌÅ»¸®¾Æ
	m_mapNationFlag.insert(std::make_pair(1488, 0));	// ¿µ±¹	
	m_mapNationFlag.insert(std::make_pair(1489, 0));	// ¾Æ¸£ÇîÆ¼³ª
	m_mapNationFlag.insert(std::make_pair(1490, 0));	// ÇÁ¶û½º
	m_mapNationFlag.insert(std::make_pair(1491, 0));	// ³×´ú¶õµå
	m_mapNationFlag.insert(std::make_pair(1492, 0));	// ½ºÆäÀÎ
	m_mapNationFlag.insert(std::make_pair(1493, 0));	// Æ÷¸£Åõ°¥
	m_mapNationFlag.insert(std::make_pair(1494, 0));	// Ã¼ÄÚ
	m_mapNationFlag.insert(std::make_pair(1495, 0));	// ½º¿þµ§
	m_mapNationFlag.insert(std::make_pair(1496, 0));	// ¸ß½ÃÄÚ
	m_mapNationFlag.insert(std::make_pair(1497, 0));	// ¿ìÅ©¶óÀÌ³ª
	m_mapNationFlag.insert(std::make_pair(1498, 0));	// Å©·Î¾ÆÆ¼¾Æ
	m_mapNationFlag.insert(std::make_pair(1499, 0));	// ¹Ì±¹
	m_mapNationFlag.insert(std::make_pair(1500, 0));	// ½ºÀ§½º
	m_mapNationFlag.insert(std::make_pair(1501, 0));	// ÄÚÆ®µðºÎ¾Æ¸£	
	m_mapNationFlag.insert(std::make_pair(1502, 0));	// ¼¼¸£ºñ¾Æ¸óÅ×³×±×·Î
	m_mapNationFlag.insert(std::make_pair(1503, 0));	// Æú¶õµå
	m_mapNationFlag.insert(std::make_pair(1504, 0));	// ÆÄ¶ó°úÀÌ
	m_mapNationFlag.insert(std::make_pair(1505, 0));	// ´ëÇÑ¹Î±¹
	m_mapNationFlag.insert(std::make_pair(1506, 0));	// È£ÁÖ
	m_mapNationFlag.insert(std::make_pair(1507, 0));	// ÀÏº»
	m_mapNationFlag.insert(std::make_pair(1508, 0));	// °¡³ª
	m_mapNationFlag.insert(std::make_pair(1509, 0));	// Æ¢´ÏÁö
	m_mapNationFlag.insert(std::make_pair(1510, 0));	// ¿¡Äâµµ¸£
	m_mapNationFlag.insert(std::make_pair(1511, 0));	// Åä°í
	m_mapNationFlag.insert(std::make_pair(1512, 0));	// ¾Ó°ñ¶ó
	m_mapNationFlag.insert(std::make_pair(1513, 0));	// ÀÌ¶õ
	m_mapNationFlag.insert(std::make_pair(1514, 0));	// »ç¿ìµð¾Æ¶óºñ¾Æ
	m_mapNationFlag.insert(std::make_pair(1515, 0));	// ÄÚ½ºÅ¸¸®Ä«
	m_mapNationFlag.insert(std::make_pair(1516, 0));	// Æ®¸®´Ï´ÙµåÅä¹Ù°í
	m_mapNationFlag.insert(std::make_pair(5331, 0));	// ³²¾ÆÇÁ¸®Ä«°øÈ­±¹
	m_mapNationFlag.insert(std::make_pair(5332, 0));	// ¿ì·ç°úÀÌ
	m_mapNationFlag.insert(std::make_pair(5333, 0));	// ³ªÀÌÁö¸®¾Æ
	m_mapNationFlag.insert(std::make_pair(5334, 0));	// ±×¸®½º
	m_mapNationFlag.insert(std::make_pair(5335, 0));	// ½½·Îº£´Ï¾Æ
	m_mapNationFlag.insert(std::make_pair(5336, 0));	// ¼¼¸£ºñ¾Æ
	m_mapNationFlag.insert(std::make_pair(5337, 0));	// µ§¸¶Å©
	m_mapNationFlag.insert(std::make_pair(5338, 0));	// Ä«¸Þ·é
	m_mapNationFlag.insert(std::make_pair(5339, 0));	// ´ºÁú·£µå
	m_mapNationFlag.insert(std::make_pair(5340, 0));	// ½½·Î¹ÙÅ°¾Æ
	m_mapNationFlag.insert(std::make_pair(5341, 0));	// ºÏÇÑ
	m_mapNationFlag.insert(std::make_pair(5342, 0));	// ¿ÂµÎ¶ó½º
	m_mapNationFlag.insert(std::make_pair(5343, 0));	// Ä¥·¹
	m_mapNationFlag.insert(std::make_pair(5344, 0));	// ¾ËÁ¦¸®
}

// ----------------------------------------------------------------------------
// Name : Create()
// Desc :
// ----------------------------------------------------------------------------
void CUIQuest::Create( CUIWindow *pParentWnd, int nX, int nY, int nWidth, int nHeight )
{
	int diff = SKILLLEARN_HEIGHT - QUEST_HEIGHT;

	CUIWindow::Create(pParentWnd, nX, nY, nWidth, nHeight);
	
	_iMaxMsgStringChar = QUESTINFO_CHAR_WIDTH / ( _pUIFontTexMgr->GetFontWidth() + _pUIFontTexMgr->GetFontSpacing() );

	m_strTeamA = CTString( " " );
	m_strTeamB = CTString( " " );
	m_bGoldenBallEntry = FALSE;
	m_bGoldenBallRequital = FALSE;
	m_bStartGoldenBall = FALSE;

	// [2011/02/09 : Sora]	Äù½ºÆ®¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â
	m_restoreQuestIndex = -1;
	m_restoreQuestItemIndex = -1;
}

static BOOL g_bHasQuest = FALSE;
static BOOL g_bHasEvent = FALSE;
// ----------------------------------------------------------------------------
// Name : OpenQuest()
// Desc : 
// ----------------------------------------------------------------------------
void CUIQuest::OpenQuest( int iMobIndex, int iMobVirIdx, BOOL bHasQuest, FLOAT fX, FLOAT fZ )
{
	CUIManager* pUIManager = CUIManager::getSingleton();

	// If this is already exist
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_QUEST_REQ ) || IsVisible() ) 		return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_RENUAL_EVENT ) || IsVisible() )		return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_HARVEST_MOON_DAY1 ) || IsVisible() )	return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_HARVEST_MOON_DAY2 ) || IsVisible() )	return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT ) || IsVisible() )				return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_GATE_OF_DIMENSION ) || IsVisible() )	return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_CHANGEWEAPON_EVENT_REQ ) || IsVisible() )	return;
	if( pUIManager->DoesMessageBoxLExist( MSGLCMD_TREASUREBOX_EVENT ) || IsVisible() )	return;
	if (pUIManager->DoesMessageBoxLExist(MSGLCMD_EVENT_MINIGAME) || IsVisible()) return;
	
	if( pUIManager->GetSelectWord()->IsVisible() ) return;

	// Set position of target npc
	m_fNpcX = fX;
	m_fNpcZ = fZ;

	CMobData* MD = CMobData::getData(iMobIndex);

	// NOTE : ´øÁ¯ ¸¶½ºÅÍÀÇ °æ¿ì.
	if( iMobIndex == 71 )
	{
		// Äù½ºÆ® º¸»ó È®ÀÎ.
		if(GAMEDATAMGR()->GetQuest()->GetCompleteQuestCount())
		{
			int nQuestIdx = GAMEDATAMGR()->GetQuest()->GetCompleteQuestIndex(0);
			pUIManager->GetQuestBookComplete()->open(nQuestIdx);
			pUIManager->GetQuestBookComplete()->SetTargetIndex( pUIManager->GetQuestBookList()->GetTargetIndex() );
			pUIManager->GetQuestBookList()->SetTargetIndex(-1);
			pUIManager->GetQuestAccept()->SetTargetIndex(-1);

			// [090528: selo] ÀÌÀü ¹öÆ°À» »ç¿ëÇÏ±â À§ÇØ NPC ÀÎµ¦½º¸¦ ÇÑ¹ø´õ ÀúÀåÇÏ´Â ±â´É
			pUIManager->GetQuestBookComplete()->SetPrevNpcIdx(71);
			pUIManager->GetQuestBookComplete()->SetPrevNpcUIType(UI_QUEST);
		}
		else
		{
			// [KH_07044] 3Â÷ µµ¿ò¸» °ü·Ã Ãß°¡
			if(g_iShowHelp1Icon)
			{
				pUIManager->GetHelp3()->ClearHelpString();
				pUIManager->GetHelp3()->AddHelpString(_S(3294, "ÆÛ½º³Î ´øÀüÀº È¥ÀÚ¼­¸¸ µé¾î°¡´Â ´øÀüÀ¸·Î °¢ ´øÀü¸¶´Ù Á¤ÇØÁø ÀÓ¹«¸¦ ¼öÇàÇÏ´Â °ÍÀÌ ¸ñÀûÀÔ´Ï´Ù. ¼öÇàÇÏ°íÀÚ ÇÏ´Â ÀÓ¹«ÀÇ ¸ñ·ÏÀ» ¼±ÅÃÇÏ¸é ÀÓ¹«ÀÇ ³»¿ë°ú º¸»ó & ¼öÇàÁ¶°ÇÀ» È®ÀÎÇÒ ¼ö ÀÖÀ¸¸ç ¼ö¶ôÀ» Å¬¸¯ÇÏ¸é ÀÚµ¿À¸·Î ÇØ´ç ÆÛ½º³Î ´øÀüÀ¸·Î ÀÌµ¿µË´Ï´Ù."));
				pUIManager->GetHelp3()->AddHelpString(_S(3295, "¡Ø ÆÛ½º³Î ´øÀü¿¡ µé¾î°¡±â À§ÇØ¼­´Â ÀûÁ¤·¹º§°ú ÀÔÀå±ÇÀÌ ÇÊ¿äÇÒ ¼ö ÀÖ½À´Ï´Ù."));
				pUIManager->GetHelp3()->AddHelpString(_S(3296, "¡Ø ÆÛ½º³Î ´øÀü¿¡¼­´Â ¸ðµç ÀÏ¹Ý°ø°ÝÀÌ ¹üÀ§°ø°ÝÀ¸·Î Àû¿ëµÇ¸ç ÆÛ½º³Î ´øÀü Àü¿ë ½ºÅ³À» »ç¿ëÇÒ ¼ö ÀÖ½À´Ï´Ù."));
				pUIManager->GetHelp3()->AddHelpString(_S(3297, "¡Ø ÀÓ¹«¸¦ ¿Ï¼ö ÇÏ¸é ÀÚµ¿À¸·Î ¸¶À»·Î ±ÍÈ¯µÇ¸ç, ´øÀü ¸¶½ºÅÍ¿¡°Ô º¸»óÀ» ¹ÞÀ» ¼ö ÀÖ½À´Ï´Ù."));
				pUIManager->GetHelp3()->OpenHelp(this);
			}
			// Create quest message box
			pUIManager->CreateMessageBoxL( _S( 99,"Äù½ºÆ®" ), UI_QUEST, MSGLCMD_QUEST_REQ );		
			
			CTString	strNpcName = CMobData::getData(iMobIndex)->GetName();
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF );
			
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, TRUE, _S( 581, "Àú¿¡°Ô ¾î¶² º¼ÀÏÀÌ ÀÖÀ¸½Å°¡¿ä?" ), -1, 0xA3A1A3FF );			

// 			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1683, "¹ß·Ï °ÝÆÄ" ), QUEST_KILL_BOSS );			
// 			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1684, "°øÁÖ ±¸Ãâ" ), QUEST_SAVE_PRINCESS );		
// 			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1685, "¾ÆÀÚÄ« Çù°î" ), QUEST_AZAKA_RAVINE );	
//			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1686, "Â÷¿øÀÇ ¹®" ), QUEST_GATE_OF_DIMENSION );
			CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1686, "Â÷¿øÀÇ ¹® º¸»ó" ), QUEST_GATE_OF_DIMENSION );
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."  ) );
		}
	}
 	else if(iMobIndex == 336 )  	// 2006 X-Mas event Snowman [12/11/2006 Theodoric]
 	{
 		pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  strNpcName,-1,0xE18600FF);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3175,"¸Þ¸® Å©¸®½º¸¶½º!! ¸ðµç ´ë·ú¿¡ ÆòÈ­¸¦!!"),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3176,"ÆòÈ­¸¦ ¼öÈ£ÇÏ´Â ÇüÁ¦¿© ¹«½¼ ÀÏ·Î Àú¸¦ Ã£¾Æ ¿À¼Ì½À´Ï±î?"),-1,0xa3a1a3ff);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3177,"Á¦°¡ µµ¿Í µå¸± ¼ö ÀÖ´Â ÀÏÀÌ¶ó¸é, Å©¸®½º¸¶½º Á¤½ÅÀ¸·Î ¹«¾ùÀÌµç µµ¿Í µå¸®°Ú½À´Ï´Ù."),-1,0xa3a1a3ff);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  CTString(" "));		
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3169, "Å©¸®½ºÆ®¸¶½º ÀÌº¥Æ®" ), EVENT_XMAS_2006 );	
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."  ) );	
 	}
	// WSS_MINIGAME 070420 -------------------------------------------------------------->>
	else if(iMobIndex == 340 )  	// 2006 X-Mas event Snowman [12/11/2006 Theodoric]
 	{
		// [100518: selo] °¡À§¹ÙÀ§º¸ ÁßÀÌ¸é ¸Þ½ÃÁö ¹Ú½º¸¦ ¿­Áö ¾Ê´Â´Ù.
		if( pUIManager->GetMinigame()->IsVisible() == FALSE )
		{
			pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_QUEST_REQ);
			CTString strNpcName = CMobData::getData(iMobIndex)->GetName();
			if (IS_EVENT_ON(TEVENT_GOMDOLI))
			{
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  strNpcName,-1,0xE18600FF);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3420, "¾È³çÇÏ¼¼¿ä. Àú´Â »ç·Î¾á! ´ëÇöÀÚ '½ºÅ¸´Ï½½¶ó³ª'ÀÇ Ãæ½ÇÇÑ Á¾ÀÔ´Ï´Ù."),-1,0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3421, "³»°¡ ¸ð½Ã´Â ÁÖÀÎ´ÔÀº Çö¸íÇÏ±â·Î µûÁö¸é ¾ÆÀÌ¸®½º ´ë·ú¿¡¼­ ´Ù¼¸ ¼Õ°¡¶ô¿¡ µé°í ¸¶À½Àº ¼Ò³àÃ³·³ ¸¼Áö¿ä."),-1,0xa3a1a3ff); 		
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3422, "½ÇÀº ¿ì¸® ÁÖÀÎ´ÔÀÌ ÁÁ¾ÆÇÏ´Â ±Í¿©¿î ¾î¸°ÀÌ¸¦ À§ÇØ À¢µð¶ó´Â °õµ¹ÀÌ ÀÎÇüÀ» ¸¸µå½Ã´Ù°¡ ±×¸¸ Å« ¹®Á¦°¡ »ý°Ü¹ö·È½À´Ï´Ù."),-1,0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3423, "ÁÖÀÎ´Ô²²¼­´Â '³ªÀÇ ¼÷ÀûÀÌÀÚ »ç¾ÇÇÑ ¸¶µµ»çÀÎ ÇÁ¶ó¿ì·ÐÀÌ Èæ¸¶¹ýÀ» »ç¿ëÇØ ¿Ï¼ºµÈ À¢µð¸¦ Á¶°¢ ³»¾î ¼û°Ü ³õÀº °Í °°´Ù. "),-1,0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3424, "¾ÆÀÌ¸®½º ´ë·úÀÇ ¿ë»ç´Ôµé²² Á¶°¢³­ À¢µð¸¦ Ã£¾Æ´Þ¶ó°í ºÎÅ¹ÇÏ·Á¹«³ª' ¶ó°í Àú¿¡°Ô ¸»¾¸ÇÏ¼Ì½À´Ï´Ù. "),-1,0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3425, "±×·¡¼­ Àú´Â ÁÖÀÎ´ÔÀÇ °õÀÎÇü À¢µð¸¦ Ã£¾ÆÁÖ½Ç ¿ë»ç´ÔÀ» ¸¸³ª·¯ ¾ÆÀÌ¸®½º ´ë·ú ¸ðµç ¸¶À»À» µ¿ºÐ¼­ÁÖÇÏ°í ÀÖ½À´Ï´Ù."),-1,0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3426, "°õÀÎÇüÀ» ¸ðµÎ Ã£À¸¸é ±Í¿©¿î ¾î¸°ÀÌµé¿¡°Ô ¼±¹°ÇØ ÁÙ ¼ö ÀÖÀ»ÅÙµ¥¡¦µµ¿ÍÁÖ½Ã°Ú½À´Ï±î?"),-1,0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3427, "ÀÌº¥Æ® Âü¿©ÇÏ±â" ), EVENT_MINIGAME );	
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."  ) );
			}
			else if (IS_EVENT_ON(TEVENT_XMAS_2007))
			{
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  strNpcName, -1, 0xE18600FF);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3420, "¾È³çÇÏ¼¼¿ä. Àú´Â »ç·Î¾á! ´ëÇöÀÚ '½ºÅ¸´Ï½½¶ó³ª'ÀÇ Ãæ½ÇÇÑ Á¾ÀÔ´Ï´Ù."), -1, 0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3421, "³»°¡ ¸ð½Ã´Â ÁÖÀÎ´ÔÀº Çö¸íÇÏ±â·Î µûÁö¸é ¾ÆÀÌ¸®½º ´ë·ú¿¡¼­ ´Ù¼¸ ¼Õ°¡¶ô¿¡ µé°í ¸¶À½Àº ¼Ò³àÃ³·³ ¸¼Áö¿ä."), -1, 0xa3a1a3ff); 		
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(5801, "½ÇÀº ¿ì¸® ÁÖÀÎ´ÔÀÌ ÁÁ¾ÆÇÏ´Â ±Í¿©¿î ¾î¸°ÀÌ¸¦ À§ÇØ »êÅ¸Å¬·Î½º ÀÎÇüÀ» ¸¸µå½Ã´Ù°¡ ±×¸¸ Å« ¹®Á¦°¡ »ý°Ü¹ö·È½À´Ï´Ù."), -1, 0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(5802, "ÁÖÀÎ´Ô²²¼­´Â '³ªÀÇ ¼÷ÀûÀÌÀÚ »ç¾ÇÇÑ ¸¶µµ»çÀÎ ÇÁ¶ó¿ì·ÐÀÌ Èæ¸¶¹ýÀ» »ç¿ëÇØ ¿Ï¼ºµÈ »êÅ¸Å¬·Î½ºÀÇ ÀÎÇüÀ» Á¶°¢ ³»¾î ¼û°Ü ³õÀº °Í °°´Ù."), -1, 0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(5803, "¾ÆÀÌ¸®½º ´ë·úÀÇ ¿ë»ç´Ôµé²² Á¶°¢³­ »êÅ¸ÀÎÇüÀ» Ã£¾Æ´Þ¶ó°í ºÎÅ¹ÇÏ·Á¹«³ª' ¶ó°í Àú¿¡°Ô ¸»¾¸ÇÏ¼Ì½À´Ï´Ù."), -1, 0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(5804, "±×·¡¼­ Àú´Â ÁÖÀÎ´ÔÀÇ »êÅ¸Å¬·Î½º ÀÎÇüÀ» Ã£¾ÆÁÖ½Ç ¿ë»ç´ÔÀ» ¸¸³ª·¯ ¾ÆÀÌ¸®½º ´ë·ú ¸ðµç ¸¶À»À» µ¿ºÐ¼­ÁÖÇÏ°í ÀÖ½À´Ï´Ù."), -1, 0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S(3426, "ÀÎÇü Á¶°¢À» ¸ðµÎ Ã£À¸¸é ±Í¿©¿î ¾ÆÀÌµé¿¡°Ô ¼±¹°ÇØ ÁÙ ¼ö ÀÖÀ»ÅÙµ¥.. µµ¿ÍÁÖ½Ã°Ú½À´Ï±î?"), -1, 0xa3a1a3ff);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3427, "ÀÌº¥Æ® Âü¿©ÇÏ±â"), EVENT_MINIGAME);
				pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."));
			}
		}
 	}
	// -----------------------------------------------------------------------------------<<
	else if (iMobIndex == 341) // eons ²É³îÀÌ ÀÌº¥Æ®(Á¤¿ø»ç)
	{
		pUIManager->CreateMessageBoxL(_S(100, "ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();

		/**********************************************************************************************/
		// 2008³â
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3489, "Àú´Â ²É³ª¹«¸¦ °ü¸®ÇÏ´Â Á¤¿ø»çÀÔ´Ï´Ù. "), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4110, "²ÉÀÌ ¸¸°³ÇÏ¿© ¿¹»Ú°Ô ÇÇ¿© ÀÖÁÒ? ÀÌ°ÍÀÌ ´Ù ÀÛ³â¿¡ Àú¸¦ µµ¿ÍÁÖ½Å ´öºÐÀÌÁÒ. ±×·¡¼­ ¸»ÀÎµ¥¿ä."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4111, "ÀÌ ²É³ª¹«¸¦ °ü¸®ÇÏ´Âµ¥ Åðºñ°¡ ¸¹ÀÌ µé¾î°¡´Âµ¥ Àú¿¡°Ô Åðºñ¸¦ Á» °¡Á®´Ù ÁÖ¼¼¿ä. ±×·³ Á¦°¡ ÀÛÀº ¼±¹°À» µå¸±²²¿ä."), -1, 0xa3a1a3ff);

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4112, "Åðºñ¸¦ °Ç³×ÁØ´Ù."), EVENT_SAKURA_2008);
		// 2008³â
		/*********************************************************************************************/

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."));
	}
	else if (iMobIndex == 342)
	{
		// empty : ²É³ª¹«¸¦ °è¼Ó µµ´Â ¹®Á¦·Î
	}
	else if (iMobIndex == 484 || iMobIndex == 1304) // Å©¸®½º¸¶½º Æ®¸® (2007)
	{
		pUIManager->CreateMessageBoxL(_S(100, "ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3947, "°Ü¿ïÀÌ µÇ¸é ´Ùµé Ãä´Ù°íµé ÇÏÁö¸¸ ¿¬¸» ¿¬½Ã µûµíÇÑ ¼Ò½ÄÀÌ µé·Á¿Í ÃäÁö¸¸Àº ¾Ê½À´Ï´Ù."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3948, "ÇÏ¾á ´«À» ¸ÂÀ¸¸ç ¼Ò¿øÀ» ºô¸é ÀÌ·ç¾îÁú °Í °°Áö ¾Ê³ª¿ä?"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3949, "¿ÃÇØ´Â ¿©·¯ºÐ ¸ðµÎ¿¡°Ô Çàº¹ÇÏ°í µû¶æÇÑ Å©¸®½º¸¶½º µÇ±æ ¹Ù¶ø´Ï´Ù."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3950, "Merry Christmas"), -1, 0xa3a1a3ff);

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3951, "Å©¸®½º¸¶½º Æ®¸® Àå½ÄÇÏ±â"), EVENT_XMAS2007_DECO);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3952, "Å©¸®½º¸¶½º Ãàº¹¹Þ±â"), EVENT_XMAS2007_BLESSEDNESS);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1268, "Ãë¼ÒÇÏ±â"));
	}
	else if (iMobIndex == 455)
	{
		pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, (CTString)MD->GetName(), -1, 0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,
			_S(3775, "³ª´Â Á×Àº ÀÚµéÀÇ ±¤´ë!! ¿À´ÃÀº ¿ì¸®µéÀÇ ÃàÁ¦!! Àç¹ÌÀÖ°Ô Áñ±âÁö ¾ÊÀ¸¸é Áö¿ÁÀ» ±¸°æ½ÃÄÑ ÁÖ°Ú´Ù!!"),-1, 0xa3a1a3ff);
		
		if (IS_EVENT_ON(A_EVENT_HOLLOWEEN))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3776, "¾Ç¸¶³¯°³ ¸Ó¸®¶ì Áö±Þ¹Þ±â"), EVENT_HALLOWEEN2007_DEVILHAIR);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3777, "»çÅÁ¹Ù±¸´Ï¿¡ »çÅÁ¹Þ±â"), EVENT_HALLOWEEN2007_CANDYBASKET);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3778, "È£¹Ú¸Ó¸® Å» ±³È¯¹Þ±â"), EVENT_HALLOWEEN2007_PUMKINHEAD);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(5108, "ÇÒ·ÎÀ© ½ºÅ©¸² °¡¸é ¹Þ±â"), EVENT_HALLOWEEN2007_WITCHHAT);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3780, "È£¹Ú±³È¯ ¹Þ±â"), EVENT_HALLOWEEN2007_PUMKIN);
		}
		
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."));
	}
	else  if(iMobIndex == 254 )
	{	// »ó½Ã ÀÌº¥Æ® NPC ·£µð....wooss 051031
		// Create Event Message Box
		pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, strNpcName,-1,0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _S(2204,"¹«½¼ ÀÏ·Î Àú¸¦ Ã£¾Æ ¿À¼Ì³ª¿ä?"),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _S(2205,"Á¦°¡ µµ¿Í µå¸± ¼ö ÀÖ´Â ÀÏÀÌ ÀÖ´Ù¸é µµ¿Í µå¸®°Ú½À´Ï´Ù."),-1,0xa3a1a3ff);
		
		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
		
		//WSS_GUILD_MASTER 070411 ----------------------->>
		if( IS_EVENT_ON(TEVENT_PARENTS_2007)||IS_EVENT_ON(TEVENT_CHILDREN_2007)||IS_EVENT_ON(TEVENT_TEACHER_2007) )
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3395, "°¡Á¤ÀÇ ´Þ ÀÌº¥Æ®" ), EVENT_MAY );	 		
		}
		// ----------------------------------------------<<
		if( IS_EVENT_ON(TEVENT_OX_QUIZ) )
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(2616, "O.X ÀÌº¥Æ® Á¸ ÀÔÀå" ), EVENT_OX_GOZONE );
		}
#ifdef NETCAFE_CAMPAIGN
		if( _pNetwork->MyCharacterInfo.lLocation == BILL_LOCATION_PCBANG )
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,FALSE,_S(2744, "NetCafe Ä·ÆäÀÎ" ),EVENT_NETCAFE_BOX);			
		}
#endif

		// ---------- WORLDCUP EVENT wooss 060530 ------------------------------------------------>>
#ifdef WORLDCUP_ITEM
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 2795, "¿ì½Â±¹°¡ ¸ÂÃß±â ÀÌº¥Æ®" ), WIN_SELECT );
#endif
		// ---------- WORLDCUP EVENT wooss 060530 ------------------------------------------------<<

		if( IS_EVENT_ON(TEVENT_RAIN) )	//070621 ttos: ÀÏº»ÀÇ ºø¹æ¿ï ÀÌº¥Æ® , ÅÂ±¹ÀÇ ¾î¸Ó´Ï³¯ ÀÌº¥Æ® ¼öÁ¤
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,FALSE,_S(2753, "ºø¹æ¿ï ÀÌº¥Æ®" ),EVENT_RAINYDAY);			
		}

#ifdef WORLDCUP_GOLDENBALL
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 2796, "°ñµç º¼ ÀÌº¥Æ®" ), EVENT_GOLDENBALL );
#endif		

		if( IS_EVENT_ON(TEVENT_BUDDHIST) )
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 2918, "ºÒ±³ ÃÐºÒ ÃàÁ¦ ÀÌº¥Æ® Âü¿©" ), EVENT_BUDDHISM );
		}

		if (IS_EVENT_ON(TEVENT_CHUSEOK_2006))
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1860, "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®" ), QUEST_HARVEST_MOON_DAY_EVENT2 );
		}

		if (IS_EVENT_ON(TEVENT_LUNARNEWYEAR_2008))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _s("2008 ¼³³¯ ÀÌº¥Æ®"), EVENT_LOVE_LOVE);		
		}

		if (IS_EVENT_ON(A_EVENT_VALENTINE_DAY))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3203, "·¯ºê·¯ºê ÀÌº¥Æ®"), EVENT_LOVE_LOVE);
		}

		if (IS_EVENT_ON(TEVENT_LOI_KRATHONG_TLD))	// [11/10/18 trylord] ÅÂ±¹ Å©¶óÅë ÀÌº¥Æ®
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(5600, "Å©¶óÅëÀ¸·Î ±³È¯ ¹Þ±â"), EVENT_LOI_KRATHONG);
		}

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(5017, "Ãâ¼® ÇöÈ² º¸±â"), ATTENDANT_DATE_REQ);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );			
	}

	//Class Change NPC Dethunter12
	else if (iMobIndex == 1664) 
	{
		pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST, MSGLCMD_QUEST_REQ);

		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, TRUE, _S(100054, "Change class description" ), -1, 0xa3a1a3ff );

		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100055, "Transform to Healer" ), MSGLCMD_EXCHANGE_HEALER );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100056, "Transform to Knight" ), MSGLCMD_EXCHANGE_KNIGHT );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100057, "Transform to Mage" ), MSGLCMD_EXCHANGE_MAGE );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100058, "Transform to NightShadow" ), MSGLCMD_EXCHANGE_NIGHTSHADOW );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100059, "Transform to Rogue" ), MSGLCMD_EXCHANGE_ROGUE );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100060, "Transform to Sorcerer" ), MSGLCMD_EXCHANGE_SORCERER );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100061, "Transform to Titan" ), MSGLCMD_EXCHANGE_TITAN );

		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(139, "Cancel" ));
	}
	else if (MD->IsMultiExchange()) {
	pUIManager->CreateMessageBoxL(_S(100, "�̺�Ʈ"), UI_QUEST, MSGLCMD_QUEST_REQ);
	CTString strNpcName = CMobData::getData(iMobIndex)->GetName();

	if (IS_EVENT_ON(TEVENT_SONGKRAN))
	{
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(7032, "�±��� ���� ��ũ���� �����Ͽ� ������ ��ȯ �̺�Ʈ�� ���� �˴ϴ�..."), -1, 0xA3A1A3FF);
	}

	CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);

	if (IS_EVENT_ON(TEVENT_SONGKRAN))
	{
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3275, "��ũ�� ���� �̺�Ʈ"), EVENT_SONGKRAN);
	}

	pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "����Ѵ�."));
	}
	#ifdef DOMINATION_EVENT_SYSTEM
	else if (iMobIndex == DOMINATION_NPC_INDEX) {
		pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST, MSGLCMD_QUEST_REQ);

		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(100535, "Registration" ), MSGLCMD_DOMINATION_EVENT_REG, 0x00e700ff );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(139, "Cancel" ));
	}
	#endif
	else if (iMobIndex == 408) // ÀÌº¥Æ® ÁøÇà¿ä¿ø
	{
		pUIManager->CreateMessageBoxL(_S(100, "ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();

		if (IS_EVENT_ON(TEVENT_SONGKRAN))
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, TRUE, _S( 7023, "ÅÂ±¹ÀÇ ¸íÀý ¼ÛÅ©¶õÀ» ¸ÂÀÌÇÏ¿© ¾ÆÀÌÅÛ ±³È¯ ÀÌº¥Æ®°¡ ÁøÇà µË´Ï´Ù..." ), -1, 0xA3A1A3FF );
		}
		else
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3613, "¾È³çÇÏ¼¼¿ä. Àú´Â ·ç³ª½Ã½º °ø½Ä À¯¶û´Ü¿¡¼­ ÆÄ°ßµÈ ÀÌº¥Æ® ÁøÇà¿ä¿øÀÔ´Ï´Ù."), -1, 0xa3a1a3ff);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3614, "·ç³ª½Ã½º´Â ¸¶¹ý°ú ³îÀÌÀÇ ´ë·úÀ¸·Î ¿ø·¡´Â ÀÎ°£º¸´Ù ¶Ù¾î³­ µÎ³ú¿Í À°Ã¼¸¦ Áö´Ñ ÃµÀÎµéÀÌ »ì°í ÀÖ¾ú´Ù°íµµ ÀüÇØÁö´Â Ã¢Á¶½Å¿¡ ÀÇÇØ ¸¸µé¾îÁø Àü¼³ÀÇ ºÎÀ¯´ë·úÀÌ¿¡¿ä."), -1, 0xa3a1a3ff);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3615, "Æ¯¼º»ó À§Ä¡°¡ ÇÑÁ¤µÇ¾î ÀÖÁö ¾ÊÁö¸¸ ÀÏÁ¤ ÁÖ±â·Î ¾ÆÀÌ¸®½ºÀÇ ³²ÂÊÀÌ³ª ¿¡°ÔÇÏÀÇ ¼­ÂÊ¿¡¼­ À°¾ÈÀ¸·Î È®ÀÎÇÒ ¼ö ÀÖ´Â À§Ä¡±îÁö Á¢±ÙÇÏ±âµµ ÇÕ´Ï´Ù."), -1, 0xa3a1a3ff);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, CTString(" "));
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(3616, "±×·±µ¥, ÀÌ¹ø¿£ ¹«½¼ÀÏ·Î Àú¸¦ Ã£¾Æ¿À¼Ì³ª¿ä?"), -1, 0xa3a1a3ff);
		}

		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
		
		if(IS_EVENT_ON(TEVENT_SONGKRAN))
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 3275, "¼ÛÅ©¶õ ¸íÀý ÀÌº¥Æ®" ), EVENT_SONGKRAN );
		}

		// [100416: selo] ·¯½Ã¾Æ´Â ·Î·¹ÀÎÀÌ ÀÌº¥Æ® ÁøÇàÇÑ´Ù.
		if (g_iCountry != RUSSIA)
		{
			if(MD->IsEvent())
			{
				g_bHasEvent = TRUE;
				pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 100, "ÀÌº¥Æ®" ), QUEST_EVENT );				
			}
		}

		if (IS_EVENT_ON(TEVENT_BJMONO_2007))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _s("SK BJ MONO ÀÀ¸ð±Ç ¹Þ±â"), EVENT_BJMONO_2007_REQ);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _s("SK BJ MONO ÀÀ¸ð±Ç ±³È¯"), EVENT_BJMONO_2007_CHANGE_REQ);
		}
		if (IS_EVENT_ON(TEVENT_TG2007_1000DAYS))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3828, "¶ó½ºÆ®Ä«¿À½º 1000ÀÏ ±â³ä¸ðÀÚ ¹Þ±â"), EVENT_TG2007_1000DAYS_CAP);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3829, "±â³ä¸ðÀÚ ¾÷±×·¹ÀÌµå"), EVENT_TG2007_1000DAYS_CAP_UPGRADE);
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(3830, "ÆøÁ× ¹Þ±â ÀÌº¥Æ®"), EVENT_TG2007_1000DAYS_FIRECRACKER);
		}

		if (IS_EVENT_ON(TEVENT_TG2007_SCREENSHOT)) // WSS_TG2007 2007/09/14
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _s("¼ÛÆí¹Þ±â ÀÌº¥Æ®"), EVENT_TG2007_SCREENSHOT);			
		}

		if (IS_EVENT_ON(TEVENT_CHAOSBALL)) // WSS_TG2007 2007/09/14
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4118, "¾ÆÀÌ¸®½º »óÁ¡ ÀÌº¥Æ® [Ä«¿À½º º¼À» ¿­¾î¶ó!]"), EVENT_CHAOSBALL);			
		}

		if (IS_EVENT_ON(TEVENT_ADD_UP_AFRON_2009))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4773, "¹öÀüÅëÇÕ ±â³äÇ° ¹Þ±â"), EVENT_ADD_UP_NEW_AFRON);
		}

		// ($E_WC2010) [100514: selo] 2010 ³²¾Æ°ø ¿ùµåÄÅ ¸Þ´º
		if (IS_EVENT_ON(TEVNET_WORLDCUP_2010_TOTO))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4900, "¿ì½Â±¹ ¿¹»óÇÏ±â ÀÌº¥Æ® ¾È³»"), EVENT_WOLRDCUP_2010_EVENT2);
		}
		if (IS_EVENT_ON(TEVNET_WORLDCUP_2010_TOTO_STATUS))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4900, "¿ì½Â±¹ ¿¹»óÇÏ±â ÀÌº¥Æ® ¾È³»"), EVENT_WOLRDCUP_2010_EVENT2_STATUS);
		}
		if (IS_EVENT_ON(TEVNET_WORLDCUP_2010_TOTO_GIFT))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4900, "¿ì½Â±¹ ¿¹»óÇÏ±â ÀÌº¥Æ® ¾È³»"), EVENT_WOLRDCUP_2010_EVENT2_GIFT);
		}
		if (IS_EVENT_ON(TEVNET_WORLDCUP_2010_ATTENDANCE))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4901, "ÀÀ¿ø ÀÌº¥Æ® ¾È³»"), EVENT_WOLRDCUP_2010_EVENT3);
		}
		if (IS_EVENT_ON(TEVENT_PROMOTION2))
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(2404, "ÄíÆù ÀÌº¥Æ®"), EVENT_PROMOTION2);
		}

		// [2011/01/18 : Sora] Ãâ¼® ÀÌº¥Æ®
		if( pUIManager->GetNotice()->IsAttendanceEventOn() )
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(5345, "°³ÀÎ Ãâ¼®ÀÌº¥Æ® º¸»ó¹Þ±â"), EVENT_ATTENDANCE_2011); 

		// [2/17/2011 kiny8216] ÈÞ¸é °èÁ¤ º¸»ó ÀÌº¥Æ®
		if ( IS_EVENT_ON(TEVENT_COMEBACK) )
		{
			if(!(g_iCountry == GERMANY && _pNetwork->m_iServerGroup == 8))
			{
				pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 5353, "ÈÞ¸éÀ¯Àú º¹±Í ¼±¹°¹Þ±â" ), EVENT_COMEBACK );
			}
		}
		// [2/17/2011 kiny8216] »ýÀÏ ÀÌº¥Æ®
		if ( IS_EVENT_ON(TEVENT_BIRTHDAY) )
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 5354, "»ýÀÏ ¼±¹° ¹Þ±â" ), EVENT_BIRTHDAY_GIFT );
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 5355, "»ýÀÏ È®ÀÎÇÏ±â" ), EVENT_BIRTHDAY_INFO );
		}

		// [2011/11/14 : Sora] ÅÂ±¹ ±¹¿Õ Åº»ýÀÏ ÀÌº¥Æ®
		if( IS_EVENT_ON( TEVENT_TLD_KING_BIRTHDAY ) )
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 5602, "±¹¿ÕÅº»ýÀÏ ¼±¹°»óÀÚ ±³È¯¹Þ±â" ), EVENT_KB_EXCHAGE_HEART );
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 5603, "±¹¿ÕÅº»ýÀÏ ÀÌº¥Æ®ÀÇ»ó ±³È¯¹Þ±â" ), EVENT_KB_EXCHAGE_FLAG );
		}

		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(5522, "[³ª¹«]º¸¹° ¿­¼è ±³È¯ÇÏ±â" ), EVENT_TREASURE_MAP );
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."));
	}
	else if( iMobIndex == 834 ) // ÇÇ´Ð½º Å¬·´ ¸¶½ºÅÍ
	{
		pUIManager->CreateMessageBoxL(_S(100, "ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4225, "¾î¼­¿À¼¼¿ä. ÇÇ´Ð½º Å¬·´¿¡ ¿À½Å °ÍÀ» È¯¿µÇÕ´Ï´Ù"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _s(" "));
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4226, "¾ÆÀÌ¸®½º ´ë·ú¿¡¼­ ¸ðÇèÀ» ½ÃÀÛÇÏ°í ¸¹Àº °æÇèÀ» ½×¾Æ 100·¹º§ ÀÌ»óÀÌ µÇ¾ú´Ù¸é »õ·Î¿î Ä³¸¯ÅÍ¸¦ »ý¼ºÇÏ¿© ÇÇ´Ð½º°¡ µÉ ¼ö ÀÖ½À´Ï´Ù."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4227, "ÇÇ´Ð½º°¡ µÇ¸é ¾Æ·¡¿Í °°Àº ÇýÅÃÀ» ÅëÇØ º¸ÅëÀÇ Å¬·¡½ºµéº¸´Ù Á» ´õ ½±°Ô ¸ðÇèÀ» ÇÒ ¼ö ÀÖ°Ô µË´Ï´Ù."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _s(" "));
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4228, "ÇÇ´Ð½º °¡ÀÔÁ¶°Ç"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4229, "1. 100·¹º§ ÀÌ»óÀÇ Ä³¸¯ÅÍ¸¦ º¸À¯ÇÑ ¼­¹ö¿¡ »õ·Ó°Ô »ý¼ºÇÑ ½Å±Ô Ä³¸¯ÅÍ"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4249, "2. ÇÇ´Ð½º Å¬·´ °¡ÀÔ±ÇÀ» º¸À¯ÇÑ Ä³¸¯ÅÍ"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _s(" "));
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4230, "ÇÇ´Ð½º ÇýÅÃ"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4231, "1. ÇÇ´Ð½ºÀÇ Àç´É"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4250, "Ä³¸¯ÅÍ ·¹º§ÀÌ 35·Î »ó½Â(±âº» ¼ºÀåÆ÷ÀÎÆ® Æ÷ÇÔ)"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4251, "¼÷·Ãµµ, ÇÇ´Ð½º º¸³Ê½º ¼ºÀåÆ÷ÀÎÆ® 30°³ Ãß°¡ Áö±Þ"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4232, "2. ÇÇ´Ð½ºÀÇ Ãàº¹"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4252, "¹°¸®&¸¶¹ý °ø°Ý·Â/¹°¸® ¹æ¾î·Â5%»ó½Â(100·¹º§ ÀÌÀü±îÁö Àû¿ë)"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4253, "3. ÇÇ´Ð½ºÀÇ ºÎÈ°"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4254, "»ç¸Á ½Ã Á¦ÀÚ¸®¿¡¼­ ºÎÈ°ÀÌ °¡´ÉÇÑ ¾ÆÀÌÅÛ Á¦°ø"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4233, "4. ÇÇ´Ð½ºÀÇ ³¯°³"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4255, "ÇÇ´Ð½º Àü¿ë Åõ±¸(±â°£ ¹«Á¦ÇÑ, ÄÚ½ºÆ¬ Åõ±¸·Î °áÇÕÁÖ¹®¼­ »ç¿ë°¡´É) Á¦°ø"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4256, "ÇÇ´Ð½º Àü¿ë Àåºñ ¼¼Æ® Á¦°ø"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4257, "Æê ½ÃÁð 1¿ë ÇÇ´Ð½ºÀÇ ¿°»ö¾à [ÇÇ´Ð½ºÀÇ °áÁ¤] Á¦°ø"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _s(" "));
		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4234, "ÇÇ´Ð½º·Î µî·ÏÇÑ´Ù."), EVENT_PHOENIX_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1268, "Ãë¼ÒÇÏ±â"));
	}
	else if( iMobIndex == 899 || iMobIndex == 900 || iMobIndex == 1048) //°æ¸Å´ëÇà npc
	{
		pUIManager->GetAuction()->OpenAuction(iMobIndex, m_fNpcX, m_fNpcZ);
	}
// [070807: Su-won] EVENT_ADULT_OPEN
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// WSS_DRATAN_SIEGEWARFARE 070730 ----------------------------------------------->>
	else if( iMobIndex == 351)	// µå¶óÅº °ø¼º ¸¶½ºÅÍ Å¸¿ö
	{	
		// Create Event Message Box
		pUIManager->CreateMessageBoxL(_S( 3671,"¸¶½ºÅÍ Å¸¿ö ¸ÞÀÎ ¸Þ´º"),UI_QUEST,MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, strNpcName,-1,0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _S( 3672,"¾È³çÇÏ¼¼¿ä. ¼ºÁÖ´Ô"),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _S( 3673,"ÀÌ°÷¿¡¼­´Â ¼ºÀ» ¼öÈ£ÇÏ±â À§ÇÑ °¢Á¾ Å¸¿ö¸¦ ¼³Ä¡ÇÏ°í °­È­, ¼ö¸®ÇÏ°Å³ª ¼º¹®À» °­È­ÇÒ ¼ö ÀÖ½À´Ï´Ù."),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _S( 3674,"ÇÊ¿äÇÑ ±â´ÉÀ» ¼±ÅÃÇÏ½Ã±â ¹Ù¶ø´Ï´Ù."),-1,0xa3a1a3ff);
		
		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 3675, "Å¸¿ö °¡µ¿ÇÏ±â" ), SIEGEWARFARE_MASTERTOWER1 );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 3676, "Å¸¿ö °­È­ÇÏ±â" ), SIEGEWARFARE_MASTERTOWER2 );			
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 3677, "¼º¹® °­È­ÇÏ±â" ), SIEGEWARFARE_MASTERTOWER3 );			
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 3678, "¸¶½ºÅÍ Å¸¿ö ¼ö¸®ÇÏ±â" ), SIEGEWARFARE_MASTERTOWER4 );			
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );		
	}
	//----------------------------------------------
	//071129 ttos: ÆÇ¸Å ´ëÇà NPC È¸Àå
	else if(iMobIndex == 470)
	{
		// Create Event Message Box
		pUIManager->CreateMessageBoxL(_s( "¾ÆÀÌÅÛ ÆÇ¸Å ´ëÇàÇùÈ¸ È¸Àå"),UI_QUEST,MSGLCMD_QUEST_REQ);
//		CTString strNpcName = _pNetwork->GetMobName(iMobIndex);
//		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, strNpcName,-1,0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _s( "¾È³çÇÏ¼¼¿ä. Àú´Â ¾ÆÀÌÅÛ ÆÇ¸Å ´ëÇàÇùÈ¸ È¸ÀåÀÔ´Ï´Ù."),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _s( "ÀúÈñ ¾ÆÀÌÅÛ ÆÇ¸Å ´ëÇàÇùÈ¸¿¡¼­´Â °í°´´ÔÀÇ ¼ÒÁßÇÑ ¾ÆÀÌÅÛÀ» ¾ÈÀüÇÏ°Ô ÆÇ¸Å ´ëÇàÀ» ÇÏ°í ÀÖ½À´Ï´Ù."),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ,TRUE, _s( "ÀúÈñ¸¦ ¹Ï°í ¹°Ç°À» ¸Ã°Ü¸¸ ÁÖ½Ã¸é ¾ÈÀüÇÏ°Ô ÆÇ¸Å¸¦ ÇØµå¸®°Ú½À´Ï´Ù."),-1,0xa3a1a3ff);
		
		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _s( "¾ÆÀÌÅÛ ÆÇ¸Å ´ëÇà Á¾·á" ), CASH_PERSONSHOP_CLOSE );
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _s( "º¸°üµÈ ¹°Ç° È¸¼ö" ), CASH_PERSONSHOP_ITEM );			
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _s( "º¸°üµÈ ³ª½º È¸¼ö" ), CASH_PERSONSHOP_NAS );			
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );		
	}
	// ------------------------------------------------------------------------------<<
	else if( iMobIndex == 893 ) //[ttos_2009_3_18]: ÇÏ³ªÆ÷½º ¹× SKºê·Îµå¹êµå °¡ÀÔÀÚ ÀÌº¥Æ®
	{
		pUIManager->CreateMessageBoxL(_S(4449, "ÃÊº¸ Áö¿ø»ç"), UI_QUEST, MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();

		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4450, "¾ÆÀÌ¸®½º´ë·ú¿¡¼­µµ °¡Àå ¹øÈ­ÇÑ µµ½Ã ¶õµ¹¿¡ ¿À½Å°ÍÀ» È¯¿µÇÕ´Ï´Ù!"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4451, "Àú´Â ¶õµ¹ ±â»ç´Ü¿¡¼­ ÆÄ°ßµÈ ÃÊº¸Áö¿ø»ç·Î ÀÌ°÷¿¡ Ã³À½ ¿À½Å ¿©·¯ºÐµé¿¡°Ô"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4452, "¾ÕÀ¸·Î °Þ°ÔµÉ ¸ðÇè°ú ³­°üÀ» ÇìÃÄ³ª°¡´Âµ¥ µµ¿òÀÌ µÉ ¸¶¹ýÀ» °É¾îµå¸®°í ÀÖ¾î¿ä!"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4453, "ÀÌ ¸¶¹ýÀ» ¹ÞÀ¸¸é ÃÊº¸ÀÚ ¿©·¯ºÐµéÀÇ °ø°Ý·ÂÀÌ Çâ»óµÇ°í °æÇèÄ¡¿Í ¼÷·Ãµµ¸¦ ´õ ¸¹ÀÌ ¹ÞÀ» ¼ö ÀÖÀ»°Ì´Ï´Ù."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4454, "´Ü, Á¢¼ÓÀ» Á¾·áÇÏ¸é ¸¶¹ýÀº »ç¶óÁö°Ô µÇ¸ç, 60·¹º§±îÁö´Â ¸¶¹ýÀÌ Ç®·Áµµ ´Ù½Ã ¸¶¹ýÀ» ¹ÞÀ» ¼ö ÀÖ½À´Ï´Ù. "), -1, 0xa3a1a3ff);

		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
	
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4455, "ÃÊº¸ Áö¿ø ¸¶¹ý ¹Þ±â"), EVENT_HANAPOS_SK_EVENT);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1748, "NPC ¾È³»" ), NPC_HELP);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );	
	}
	else if (iMobIndex == 1107) // Áß Àú·¹º§ Áö¿ø»ç
	{
		pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST, MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4948, "º¸ÀÌÁö ¾Ê´Â ÀÌ²ø¸²¿¡ ÀÇÇØ ÀÌ°÷À¸·Î ¹ß±æÀ» ÇâÇÑ ¿©ÇàÀÚ¿©!"), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4949, "Àú´Â ¼ö ¸¹Àº ¸ðÇè°ú Èûµç ¿©Á¤À¸·Î ÁöÄ£ ´ç½Å¿¡°Ô ¸ÚÁø ¸¶¹ýÀ» ¼±¹°ÇÏ±â À§ÇØ ¿À·£ ½Ã°£ ´ç½ÅÀ» ±â´Ù¸®°í ÀÖ¾ú¾î¿ä."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4950, "Á¦ ¸¶¹ýÀ» ¹ÞÀ¸¸é ¹°¸®, ¸¶¹ý °ø°Ý·Â°ú ¹æ¾î·ÂÀÌ 20% »ó½ÂµÈ´ä´Ï´Ù."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4951, "´Ü Á¢¼ÓÀ» Á¾·áÇÏ¸é ¸¶¹ýÀº »ç¶óÁö°Ô µÇ¸ç, 90·¹º§±îÁö´Â ¸¶¹ýÀÌ Ç®·Áµµ ´Ù½Ã ¸¶¹ýÀ» ¹ÞÀ» ¼ö ÀÖÀ¸´Ï Àú¸¦ Ã£¾Æ ¿À¼¼¿ä."), -1, 0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(4952, "´ç½ÅÀÇ ³²Àº ¿©Çà¿¡ ½ÅÀÇ Ãàº¹ÀÌ ÇÔ²² ÇÏ±æ!"), -1, 0xa3a1a3ff);
		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(4953, "ÁßÀú·¹º§ Áö¿ø ¸¶¹ý ¹Þ±â"), MIDLEVEL_SUPPORT_REQ);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1748, "NPC ¾È³»" ), NPC_HELP);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
	}
	else if (iMobIndex == 1749) // Áß Àú·¹º§ Áö¿ø»ç
	{
	pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST, MSGLCMD_QUEST_REQ);
	pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S(100068, "º¸ÀÌÁö ¾Ê´Â ÀÌ²ø¸²¿¡ ÀÇÇØ ÀÌ°÷À¸·Î ¹ß±æÀ» ÇâÇÑ ¿©ÇàÀÚ¿©!"), -1, 0xa3a1a3ff);
	CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);
	pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(100067, "ÁßÀú·¹º§ Áö¿ø ¸¶¹ý ¹Þ±â"), ARENA_HEAL_REQ);
	pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1748, "NPC ¾È³»"), NPC_HELP);
	pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1220, "Ãë¼ÒÇÑ´Ù."));
	}
 	else if(iMobIndex == 1136 )	// [2010/08/25 : Sora] ADD_SUBJOB ¸¶½ºÅÍ »óÀÎ
 	{
		if(_pNetwork->IsMySubJob(SUBJOB_MERCHANT))
		{
			CUIMsgBox_Info MsgInfo;
			MsgInfo.SetMsgBoxInfo( _S( 1748, "¾È³»" ), UMBS_OK, UI_NONE, MSGCMD_NULL );
			MsgInfo.AddString( _S( 5052, "ÀÌ¹Ì »óÀÎÀ¸·Î µî·ÏµÇ¾î ÀÖ½À´Ï´Ù.") );
			pUIManager->CreateMessageBox( MsgInfo );	
			return;
		}

 		pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST,MSGLCMD_QUEST_REQ);
		CTString strNpcName = CMobData::getData(iMobIndex)->GetName();
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  strNpcName,-1,0xE18600FF);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S( 5053, "³ª¿Í °°ÀÌ »óÀÎÀÇ ±æÀ» °ÈÁö ¾Ê°Ú³ª?"),-1,0xa3a1a3ff);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S( 5054, "ÀÚ, »óÀÎÀº ºÎ¿Í ¸í¿¹¸¦ ¼Õ½±°Ô ¾òÀ» ¼ö ÀÖ´Â ¸Å·ÂÀûÀÎ Á÷¾÷ ÀÌ¶ó³×!"),-1,0xa3a1a3ff);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  _S( 5055, "¾ðÁ¦¶óµµ »óÀÎÀÌ µÇ°í ½Í´Ù¸é ³ª¸¦ Ã£¾Æ¿À°Ô³ª"),-1,0xa3a1a3ff);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  CTString(" "));
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S( 5056, "»óÀÎÀ¸·Î µî·Ï"), REGISTER_MERCHANT );
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S( 1748, "NPC ¾È³»" ), NPC_HELP);
 		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."  ) );	
 	}
	else if (iMobIndex == 1137)
	{
		pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST, MSGLCMD_QUEST_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S( 581, "Àú¿¡°Ô ¾î¶² º¼ÀÏÀÌ ÀÖÀ¸½Å°¡¿ä?" ), -1, 0xA3A1A3FF );
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S( 5362, "¾ÆÄ­ »ç¿ø Normal"), DUNGEON_DIFFICULTY_NORMAL);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S( 5363, "¾ÆÄ­ »ç¿ø Hard"), DUNGEON_DIFFICULTY_HARD);
		pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, FALSE, _S(1220, "Ãë¼ÒÇÑ´Ù."));
	}	
	else if (iMobIndex == 1574 || iMobIndex == 1575)
	{	// 1574 : Ä«ÀÌ·è½º º¸¼® ¿¬±¸¿ø, 1575 µô¶ó¹® º¸¼® ¿¬±¸¿ø.
		if( pUIManager->DoesMessageBoxExist( MSGLCMD_SYNDICATE_JEWEL_GIVE ) ) 
			pUIManager->CloseMessageBox(MSGLCMD_SYNDICATE_JEWEL_GIVE);

		GameDataManager* pGameData = GameDataManager::getSingleton();

		if (pGameData == NULL)
			return;

		CSyndicate* pSyndicateData = pGameData->GetSyndicate();

		if (pSyndicateData == NULL)
			return;

		CTString strSyndicateName = pSyndicateData->GetSyndicateName(_pNetwork->MyCharacterInfo.iSyndicateType);
		CTString strTmp;

		strTmp.PrintF(_S(6113, "Ã¢Á¶ÀÇ º¸¼®À» ¹ß°ßÇÏ¼Ì³ª¿ä? [%s] °á»ç´ë¸¦ À§ÇØ ±âºÎÇØ ÁÖ½Ã¸é À¯¿ëÇÏ°Ô »ç¿ëÇÏ°Ú½À´Ï´Ù."), strSyndicateName);

		pUIManager->CreateMessageBoxL(_S(6114, "Ã¢Á¶ÀÇ º¸¼® ±âºÎ"), UI_QUEST, MSGLCMD_SYNDICATE_JEWEL_GIVE);
		pUIManager->AddMessageBoxLString(MSGLCMD_SYNDICATE_JEWEL_GIVE, TRUE, strTmp, -1, 0xA3A1A3FF );
		pUIManager->AddMessageBoxLString(MSGLCMD_SYNDICATE_JEWEL_GIVE, FALSE, _S(6114, "Ã¢Á¶ÀÇ º¸¼® ±âºÎ"), SYNDICATE_JEWEL_GIVE);
		pUIManager->AddMessageBoxLString(MSGLCMD_SYNDICATE_JEWEL_GIVE, FALSE, _S(139, "Ãë¼Ò."));
	}
	else if (iMobIndex == 1543 || iMobIndex == 1544)
	{
		if( pUIManager->DoesMessageBoxExist( MSGLCMD_SYNDICATE_SECESSION_REQ ) ) 
			pUIManager->CloseMessageBox(MSGLCMD_SYNDICATE_SECESSION_REQ);

		pUIManager->CreateMessageBoxL(CTString(MD->GetName()), UI_QUEST, MSGLCMD_SYNDICATE_SECESSION_REQ);
		pUIManager->AddMessageBoxLString(MSGLCMD_SYNDICATE_SECESSION_REQ, TRUE, _S( 6122, "¾È³çÇÏ¼¼¿ä! °á»ç´ë »ç¹«¼Ò¸¦ Ã£¾ÆÁÖ¼Å¼­ °¨»çÇÕ´Ï´Ù. °á»ç´ë¿ø´ÔµéÀÇ ¿äÃ» »çÇ×À» ºü¸£°í Á¤È®ÇÏ°Ô Ã³¸®ÇÏ¿©µå¸®°Ú½À´Ï´Ù. ¾î¶² ¾÷¹«¸¦ µµ¿Íµå¸±±î¿ä?" ), -1, 0xA3A1A3FF );
		pUIManager->AddMessageBoxLString(MSGLCMD_SYNDICATE_SECESSION_REQ, FALSE, _S( 6123, "°á»ç´ë Å»Åð ¿äÃ»"), SYNDICATE_SECESSION);
		pUIManager->AddMessageBoxLString(MSGLCMD_SYNDICATE_SECESSION_REQ, FALSE, _S(139, "Ãë¼Ò"));
	}
	else 
	{
		// Create quest message box
		pUIManager->CreateMessageBoxL( _S( 99,"Äù½ºÆ®" ), UI_QUEST, MSGLCMD_QUEST_REQ );		
		
		CTString	strNpcName = CMobData::getData(iMobIndex)->GetName();
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, TRUE, strNpcName, -1, 0xE18600FF );
		
		if (iMobIndex == 1131) //[4/15/2011 ldy1978220] Juno Reform add NPC ÃÖÈÄÀÇ Æ®·£Æ®
		{
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S( 5382, "¿ì¸® Æ®·£Æ® Á¾Á·Àº ½Å¸ñÀÇ º¸»ìÇË ¼Ó¿¡ ÀÎ°£µéÀ» º¸È£ÇÏ´Â ÀÓ¹«¸¦ ¹Þ°í ÀÖ¾úÁö..." ), -1, 0xA3A1A3FF );
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S( 5383, "Çåµ¥ ¾î´À¼ø°£ºÎÅÍ ¾îµÒÀÇ ±â¿î¿¡ ÀÇÇØ ÇÏ³ªµÑ º¯ÇÏ±â ½ÃÀÛÇÏ¸é¼­ ÀÎ°£µé°ú ½Å¸ñÀ» °ø°ÝÇÏ±â ½ÃÀÛÇß´Ù³×..." ), -1, 0xA3A1A3FF );
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S( 5384, "³ª´Â ¾ÆÇÁ·Ð½ÅÀÇ Ãàº¹À» ¹ÞÀº ÁöÆÎÀÌ ´öºÐ¿¡ Àü¿°µÇÁö ¾Ê¾ÒÁö¸¸..." ), -1, 0xA3A1A3FF );
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE,  CTString(" "));
			pUIManager->AddMessageBoxLString(MSGLCMD_QUEST_REQ, TRUE, _S( 5385, "ÀÚ³× ³ª¸¦ µµ¿ÍÁÖÁö ¾Ê°Ú³ª?" ), -1, 0xA3A1A3FF );

		}
		else
		{
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, TRUE, _S( 581, "Àú¿¡°Ô ¾î¶² º¼ÀÏÀÌ ÀÖÀ¸½Å°¡¿ä?" ), -1, 0xA3A1A3FF );
		}	
		// 2009. 05. 27 ±èÁ¤·¡
		// ÀÌ¾ß±âÇÑ´Ù º¯°æ Ã³¸®
		CUIQuestBook::AddQuestListToMessageBoxL(MSGLCMD_QUEST_REQ);	
		
		if(MD->IsEvent())
		{
			g_bHasEvent = TRUE;
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 100, "ÀÌº¥Æ®" ), QUEST_EVENT );				
		}

		if( iMobIndex == 139 )		// ·Î·¹ÀÎ NPC ÀÏ°æ¿ì...
		{
#ifdef WEAPONCHANGE_EVENT
			pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1203, "¹«±â±³Ã¼ ÀÌº¥Æ®" ), QUEST_CHANGEWEAPON );			
#endif				
			if(IS_EVENT_ON(TEVENT_SAKURA))
			{
				pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 2536, "ÀüÅëÀÇ»ó ±³È¯" ), EVENT_CLOTHES_EXCHANGE );
			}

			if(IS_EVENT_ON(A_EVENT_COLLECT_BUG))
			{
				pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 2946, "¿©¸§ °ïÃæÃ¤Áý ÀÌº¥Æ®" ), EVENT_COLLECTBUGS );
			}
		}

		// [100208: selo] ´ëÁ·Àå ÁöÅ³ÀÇ °æ¿ì
		if( iMobIndex == 276 )
		{
			// 1. #248 Äù½ºÆ®¸¦ ¿Ï·áÇÑ »óÅÂÀÌ°í
			// 2. #4659 ¾ÆÀÌÅÛÀ» °¡Áö°í ÀÖÁö ¾ÊÀ¸¸é
			// ±×¸²ÀÚ ¹®ÀÇ ¿­¼è ¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â			
			if( CQuestSystem::QAT_DOING == CQuestSystem::Instance().GetQuestAllow(249) &&
				pUIManager->GetInventory() &&  
				pUIManager->GetInventory()->GetItemCount(4659) == 0 )
			{
				m_restoreQuestIndex = -1;
				m_restoreQuestItemIndex = -1;

				pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S(4818, "[±×¸²ÀÚ ¹®ÀÇ ¿­¼è] ¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â"), QUEST_RESTORE_ITEM );
			}
		}

		// [2011/02/09 : Sora] ¿¹¹è´ç Äù½ºÆ® ¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â
		if( iMobIndex == 1049 )
		{
			if( CQuestSystem::QAT_ALREADY_DONE == CQuestSystem::Instance().GetQuestAllow(262) )
			{
				CTString strMessage;

				m_restoreQuestIndex = 262;
				m_restoreQuestItemIndex = 4696;

				strMessage.PrintF(_S(5358, "[%s] ´Ù½Ã ¹Þ±â" ), _pNetwork->GetItemName( m_restoreQuestItemIndex ) );
				pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, strMessage, QUEST_RESTORE_ITEM );
			}
		}

		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1748, "NPC ¾È³»" ), NPC_HELP);
		pUIManager->AddMessageBoxLString( MSGLCMD_QUEST_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );			
	}
	
	m_iNpcIndex		= iMobIndex;
	m_iNpcVirIdx	= iMobVirIdx;
	g_bHasQuest		= bHasQuest;
}

// ----------------------------------------------------------------------------
// Name : MsgBoxLCommand()
// Desc :
// ----------------------------------------------------------------------------
void CUIQuest::MsgBoxLCommand( int nCommandCode, int nResult )
{
	CUIManager* pUIManager = CUIManager::getSingleton();
	CTString tv_str;

	switch( nCommandCode )
	{
	case MSGLCMD_RENUAL_EVENT:
		{
			if( nResult == QUEST_RENUAL_EVENT_OK )
			{
				pUIManager->GetSelectWord()->OpenSelectWord();						
				//!! ¼­¹ö¿¡ È®ÀÎ ¸Þ¼¼Áö º¸³»±â 
			}
		}
		break;
	case MSGLCMD_HARVEST_MOON_DAY1:
		{
			pUIManager->CloseMessageBox( MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE1 );
			pUIManager->CloseMessageBox( MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE2 );
			pUIManager->CloseMessageBox( MSGCND_MOON_DAY_EVENT_GIVE_ITEM );
				
			CTString strMessage;
			CUIMsgBox_Info	MsgBoxInfo;
				
			//strMessage = _S( 1859, "ÀÛ¹°À» ¾÷±×·¹ÀÌµå ÇÏ½Ã°Ú½À´Ï±î?" );	
			if( nResult == QUEST_HARVEST_MOON_DAY_EVENT_UPGRADE1 )
			{
				strMessage = _S(3131, "¼ÛÆíÀ» ¸¸µå½Ã°Ú½À´Ï±î?" );
				MsgBoxInfo.SetMsgBoxInfo( _S( 1860,  "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®" ) , UMBS_OKCANCEL,
				UI_QUEST, MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE1 );
			}
			else if( nResult == QUEST_HARVEST_MOON_DAY_EVENT_UPGRADE2 )
			{
				strMessage = _S(3132, "¿À»ö ¼ÛÆíÀ» ¸¸µå½Ã°Ú½À´Ï±î?" );
				MsgBoxInfo.SetMsgBoxInfo( _S( 1860,  "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®" ) , UMBS_OKCANCEL,
					UI_QUEST, MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE2 );
			}
			else
			{
				break;
			}
						
			MsgBoxInfo.AddString( strMessage );
			pUIManager->CreateMessageBox( MsgBoxInfo );
		}
		break;
	case MSGLCMD_HARVEST_MOON_DAY2:
		{
			if( nResult == MSGCND_MOON_DAY_EVENT_GIVE_ITEM )
			{
				pUIManager->CloseMessageBox( MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE1 );
				pUIManager->CloseMessageBox( MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE2 );
				pUIManager->CloseMessageBox( MSGCND_MOON_DAY_EVENT_GIVE_ITEM );
				CTString strMessage;
				CUIMsgBox_Info	MsgBoxInfo;
				
				strMessage = _S( 1861, "Ãß¼® ÀÌº¥Æ® º¸»óÇ°À» Áö±Þ ¹ÞÀ¸½Ã°Ú½À´Ï±î?" ); 
				MsgBoxInfo.SetMsgBoxInfo( _S( 1860,  "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®" ) , UMBS_OKCANCEL,
					UI_QUEST, MSGCND_MOON_DAY_EVENT_GIVE_ITEM );
				
				
				MsgBoxInfo.AddString( strMessage );
				pUIManager->CreateMessageBox( MsgBoxInfo );

			//	_pNetwork->SendChuseokExchange();
			}

		}
		break;
	case MSGLCMD_EVENT :
		{
			if( nResult == QUEST_RENUAL_EVENT )
			{
				CTString strMessage;
				pUIManager->CloseMessageBoxL( MSGLCMD_RENUAL_EVENT );

				strMessage = _S(2209, "³¹¸» ¸ÂÃß±â ÀÌº¥Æ®" );	 
				pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_RENUAL_EVENT );				
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, TRUE, strMessage, -1,0xE18600FF );				

				strMessage = _S(2210, "Á¶ÇÕÇÏ½Å ³¹¸»µéÀ» ÀÎº¥Åä¸®¿¡ ¼ÒÁö ÇÏ½ÅÃ¤·Î ¿¬°üµÈ °ÔÀÓ Å¸ÀÌÆ²À» ¼±ÅÃÇÏ½Ã¸é ¿Ï¼ºµÈ ³¹¸»¿¡ µû¶ó º¸»óÀÌ Áö±ÞµË´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = " ";
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S(2211, "´Ü ÀÌ¹Ì ÇÑ¹ø Áö±Þ¹ÞÀº »óÇ°¿¡ ´ëÇØ¼­´Â ´Ù½Ã Áö±ÞÀÌ ¾ÈµÇ¹Ç·Î ÁÖÀÇÇÏ½Ã±â ¹Ù¶ø´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = " ";
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );				
				
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, FALSE, _S(2212, "°ÔÀÓ Å¸ÀÌÆ² ¼±ÅÃ."  ), QUEST_RENUAL_EVENT_OK );		
				pUIManager->AddMessageBoxLString( MSGLCMD_RENUAL_EVENT, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù."  ) );			

			}
			else if( nResult == QUEST_TREASURE_BOX )
			{
				// ¼­¹ö·Î ¸Þ¼¼Áö º¸³»±â.
				_pNetwork->SendEventTreasureList();
			}
			else if (nResult == EVENT_OPENBETAITEMGIFT)
			{
				_pNetwork->SendUsaOpenBetaGift();
			}
			else if( nResult == QUEST_HARVEST_MOON_DAY_EVENT1 )
			{
				CTString strMessage;
				pUIManager->CloseMessageBoxL( MSGLCMD_HARVEST_MOON_DAY1 );

				strMessage = _S( 1860, "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®" );	 
				pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_HARVEST_MOON_DAY1 );				
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1,0xE18600FF );				

				strMessage = _S(3122, "¹ÎÁ·ÀÇ ¸íÀý Ãß¼®À» ¸Â¾Æ¼­ ¸ÀÀÕ´Â ¼ÛÆíÀ» ¸¸µé¾î º¸½Ã°Ú¾î¿ä?" );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S(3123, "´Ù¸¥ Àç·á´Â ÀúÇÑÅ× ´Ù ÀÖÀ¸´Ï ¿©·¯ºÐÀº ½Ò°¡·ç, ²Ü, ¼ÖÀÙÀ» °¡Á®¿Í ÁÖ¼¼¿ä." );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S(3124, "Àç·áµéÀº ÀÌº¥Æ® ±â°£ µ¿¾È ¸ó½ºÅÍ¸¦ »ç³ÉÇÏ¸é ¾òÀ» ¼ö ÀÖÀ¸¸ç °¢°¢ 1°³¾¿ ÃÑ 3°³¸¦ ¸ð¾Æ¿À½Ã¸é" );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S(3125, "ÀÌµ¿¼Óµµ¿Í °ø°Ý¼Óµµ°¡ Çâ»óµÇ´Â Æ¯º°ÇÑ ¼ÛÆíÀ» 1°³ ¸¸µé¾î µå¸®°Ú½À´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S(3126, "±×¸®°í ¼ÛÆí 10°³¸¦ ¸ð¾Æ¿À¸é ¿À»ö¼ÛÆíÀ¸·Î ¸¸µé ¼ö ÀÖ´Âµ¥," );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S(3127, "¿À»ö¼ÛÆíÀº ·£µð°¡ ¾ÆÁÖ ÁÁ¾ÆÇÏ´Â ¼ÛÆíÀ¸·Î °¡Á®´Ù ÁÖ¸é º¸»óÇ°À» ¹ÞÀ» ¼ö ÀÖ½À´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = " ";
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );	
				strMessage = _S(3128, "´Ü, ¼ÛÆíÀ» ¸¸µé´Ù°¡ ½ÇÆÐÇÏ¸é »ç¿ëÇÑ Àç·á°¡ ¸ðµÎ »ç¶óÁö°í, ¿À»ö¼ÛÆíÀ» ¸¸µé´Ù°¡ ½ÇÆÐÇÏ¸é ¼ÛÆí 2°³¸¸ ³²°Ô µË´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = " ";
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, TRUE, strMessage, -1, 0xA3A1A3FF );

				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, FALSE, _S(3129, "¼ÛÆíÀ» ¸¸µç´Ù."  ), QUEST_HARVEST_MOON_DAY_EVENT_UPGRADE1 );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, FALSE, _S(3130, "¿À»ö¼ÛÆíÀ» ¸¸µç´Ù."  ), QUEST_HARVEST_MOON_DAY_EVENT_UPGRADE2 );
				pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY1, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù."  ) );			
			}
			else if(nResult ==  EVENT_COUPON )
			{
				if(pUIManager->DoesMessageBoxExist( MSGCMD_EVENT_COUPON_SENDNUM )) break;
				if(pUIManager->DoesMessageBoxExist( MSGCMD_NULL)) break;
				
				int tv_all = (INVEN_SLOT_ROW_TOTAL*INVEN_SLOT_COL);
				if ( pUIManager->GetInventory()->GetItemAll() > tv_all-5) {
					CUIMsgBox_Info MsgBoxInfo;
					MsgBoxInfo.SetMsgBoxInfo(_S(169,"ÀÌº¥Æ®"),UMBS_OK,UI_NONE,MSGCMD_NULL);
					MsgBoxInfo.AddString(_S(116,"ÀÎº¥Åä¸® °ø°£ÀÌ ºÎÁ·ÇÏ¿© º¸»óÀ» ¹ÞÀ» ¼ö ¾ø½À´Ï´Ù."));
					pUIManager->CreateMessageBox(MsgBoxInfo);

				}
				else{
					CUIMsgBox_Info MsgBoxInfo;
					MsgBoxInfo.SetMsgBoxInfo(_S(169,"ÀÌº¥Æ®"),UMBS_YESNO|UMBS_INPUTBOX,UI_QUEST,MSGCMD_EVENT_COUPON_SENDNUM);
					MsgBoxInfo.AddString(_S(2402,"ÇØ´ç ÄíÆù ¹øÈ£¸¦ ÀÔ·ÂÇÏ¸é »õ·Î¿î ÀÇ»óÀ» ¾òÀ» ¼ö ÀÖ½À´Ï´Ù."));
					MsgBoxInfo.AddString(_S(2403,"ÄíÆù ¹øÈ£¸¦ ÀÔ·ÂÇØ ÁÖ½Ê½Ã¿À."));
					pUIManager->CreateMessageBox(MsgBoxInfo);
				}
			}
			else if( nResult == EVENT_CONNECT )
			{
				_pNetwork->SendConnectItemReq();								
			}
			else if(nResult ==  EVENT_PROMOPACK )
			{
				CTString strMessage;
				pUIManager->CloseMessageBoxL( MSGLCMD_EVENT_PROMOPACK );

				strMessage = _S(3145, "ÇÁ·Î¸ð ÆÐÅ°Áö »óÇ° ÀÌº¥Æ®" );	
				pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_EVENT_PROMOPACK );				
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, TRUE, strMessage, -1,0xE18600FF );				

				strMessage = _S(3146, "ÇÁ·Î¸ð ÆÐÅ°Áö »óÇ°À» ±¸ÀÔÇÑ À¯Àú°¡ ÆÐÅ°Áö¿¡ ÀûÈù ÀÎÁõ key¸¦ ÀÔ·ÂÇÏ¸é °ÔÀÓ¾ÆÀÌÅÛÀ» º¸»óÇ°À¸·Î ¹ÞÀ» ¼ö ÀÖ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = " ";
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, TRUE, strMessage, -1, 0xA3A1A3FF );				
				
				strMessage = _S(3147, "ÇÁ·Î¸ð ÆÐÅ°Áö ÀÌº¥Æ® º¸»óÇ°" );
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, TRUE, strMessage, -1, 0xA3A1A3FF );	

				strMessage = _S(3148, "1. ´ëÇü HP, MP È®ÀåÆ÷¼Ç 5°³¾¿" );
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, TRUE, strMessage, -1, 0xA3A1A3FF );	
				strMessage = _S(3149, "2. A~E µî±Þ ´É·ÂÄ¡¸¦ °¡Áø ¾Ç¼¼»ç¸® ¾ÆÀÌÅÛ Áß ÇÑ°³" );
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, TRUE, strMessage, -1, 0xA3A1A3FF );	

				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, FALSE, _S( 3150, "ÀÎÁõ Key ÀÔ·Â"  ), EVENT_PROMO_KEY_ENTER );
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_PROMOPACK, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù."  ) );
			}
			// wooss 070305 
			// kw : WSS_WHITEDAY_2007 ------------------------------------------------------------------------------------->>
			else if( nResult == EVENT_WHITEDAY_2007 )
			{
				CTString strMessage;
				pUIManager->CloseMessageBoxL( MSGLCMD_WHITEDAY_2007 );

				strMessage = _S( 3238, "È­ÀÌÆ®µ¥ÀÌ ÀÌº¥Æ®" );	 
				pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_WHITEDAY_2007 );				
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1,0xE18600FF );				

				strMessage = _S( 3239, "»çÅÁÀ» ÁÖ°í ¹ÞÀ¸¸ç »ç¶û°ú ¿ìÁ¤À» ³ª´©´Â È­ÀÌÆ®µ¥ÀÌ¸¦ ¸Â¾Æ¼­ ¸ó½ºÅÍµéÀÌ »çÅÁÀ» ÁØ´Ù°í ÇÕ´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S( 3240, "½Ã¿øÇÑ ÇÏ´Ã»ö »çÅÁ°ú ´ÞÄÞÇÑ ºÐÈ«»ö »çÅÁÀÌ ¸Ô°í ½ÍÀºµ¥ °¡Á®¿Í ÁÖ½Ã°Ú¾î¿ä?" );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S( 3241, "ÇÏ´Ã»ö »çÅÁ 5°³¿Í ºÐÈ«»ö 5°³¸¦ °¡Á®´Ù ÁÖ½Ã¸é °¨»çÀÇ Ç¥½Ã·Î ·¯ºê¸ÅÁ÷ ÁÖ¹® Áß 1°¡Áö¸¦ ¹«ÀÛÀ§·Î ¼±ÅÃÇØ¼­ °É¾îµå¸®°í," );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3242, "»çÅÁ 20°³¸¦ °¡Á®´Ù ÁÖ½Ã¸é »çÅÁ »ö»ó¿¡ ¸Â´Â ÆíÁöÁö¸¦ µå¸®°Ú½À´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S( 3243, "·¯ºê¸ÅÁ÷ ÁÖ¹®Àº ÀÏ½ÃÀûÀ¸·Î Ä³¸¯ÅÍÀÇ ´É·ÂÀ» ³ô¿©ÁÖ´Â ÁÖ¹®ÀÌ¸ç, ÆíÁöÁö´Â °ÔÀÓÀüÃ¼¿¡ °ø°³ÀûÀ¸·Î »ç¶ûÀÇ ¸Þ½ÃÁö¸¦ ÀüÇÒ ¼ö ÀÖ´Â ¾ÆÀÌÅÛÀÔ´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3244, "¡Ø ·¯ºê¸ÅÁ÷ ÁÖ¹® Á¾·ù" );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3245, "¹Ù¶÷ÀÇ ·¯ºê¸ÅÁ÷ - ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 10ºÐ°£ ÀÌµ¿¼Óµµ°¡ Çâ»óµÈ´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3246, "ÈûÀÇ ·¯ºê¸ÅÁ÷ - ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ÈûÀÌ 20 Áõ°¡µÈ´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3247, "¹ÎÃ¸ÀÇ ·¯ºê¸ÅÁ÷ - ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ¹ÎÃ¸ÀÌ 20 Áõ°¡µÈ´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3248, "ÁöÇýÀÇ ·¯ºê¸ÅÁ÷ - ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ÁöÇý°¡ 20 Áõ°¡µÈ´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3249, "Ã¼ÁúÀÇ ·¯ºê¸ÅÁ÷ - ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ Ã¼ÁúÀÌ 50 Áõ°¡µÈ´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3250, "·Î·¹ÀÎÀÇ ·¯ºê¸ÅÁ÷ - ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ¸ó½ºÅÍ °ø°Ý½Ã ÀÏÁ¤ È®·ü·Î º»ÀÎ Ä³¸¯ÅÍ µ¥¹ÌÁöÀÇ 10¹è¿¡ ÇØ´çÇÏ´Â µ¥¹ÌÁö¸¦ ÀÔÈù´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3251, "¡Ø ÀÌº¥Æ® ±â°£ : 2007³â 3¿ù 13ÀÏ ~ 3¿ù 27ÀÏ" );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S( 3252, "¡Ø ÀÌº¥Æ® ±â°£ Á¾·áÈÄ ³²¾ÆÀÖ´Â »çÅÁ ¹× ÆíÁöÁö´Â ¸ðµÎ »ç¶óÁý´Ï´Ù." );				
			
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, FALSE, _S( 3253, "·¯ºê¸ÅÁ÷ ÁÖ¹®À» ¹Þ´Â´Ù."  ), EVENT_REWARD_1 );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, FALSE, _S( 3254, "ÇÏ´Ã»ö ÆíÁöÁö·Î ±³È¯ÇÑ´Ù."  ), EVENT_REWARD_2 );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, FALSE, _S( 3255, "ºÐÈ«»ö ÆíÁöÁö·Î ±³È¯ÇÑ´Ù."  ), EVENT_REWARD_3 );
				pUIManager->AddMessageBoxLString( MSGLCMD_WHITEDAY_2007, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù."  ) );	
				
			}
			// --------------------------------------------------------------------------------------------------------------<<
			
			// [070705: Su-won] EVENT_SUMMER_2007
			else if( nResult == EVENT_SUMMER_2007 )
			{
				CTString strMessage;
				pUIManager->CloseMessageBoxL( MSGLCMD_SUMMER_2007 );

				strMessage = _S(3561, "Á¾ÀÌÁ¢±â ÀÌº¥Æ®" );	 
				pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_SUMMER_2007 );				
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, TRUE, strMessage, -1,0xE18600FF );				

				strMessage = _S(3566, "¿©¸§¹æÇÐµ¿¾È Ä£±¸µé°ú Á¾ÀÌÁ¢±â¸¦Çß´ø °æÇèÀ» ¶°¿Ã¸®¸ç ¾î¸° ½ÃÀý·Î µ¹¾Æ°¡º¸´Â °ÍÀº ¾î¶³±î¿ä?" );
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, TRUE, strMessage, -1, 0xA3A1A3FF );				
				strMessage = _S(3567, "»öÁ¾ÀÌ¸¦ °¡Áö°í ¿À½Ã¸é Àç¹ÌÀÖ´Â Á¾ÀÌ Á¢±â¸¦ °¡¸£ÃÄ µå¸®°Ú½À´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage.PrintF("¡Ø %s", _S(3565, "¡Ø ÀÌº¥Æ® ±â°£ : 2007³â 7¿ù 10ÀÏ(È­) ~ 8¿ù 24ÀÏ(È­)") );
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
				strMessage = _S(3568, "¡Ø »öÁ¾ÀÌ´Â Á¾ÀÌ Á¢±â ÈÄ ¼ÒºñµÇ¸ç, ÀÌº¥Æ®±â°£ Á¾·ù ÈÄ ÇÑ´Þ °£ »ç¿ë°¡´ÉÇÕ´Ï´Ù." );
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, TRUE, strMessage, -1, 0xA3A1A3FF );
			
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, FALSE, _S(3569, "Á¾ÀÌÁ¢±â"  ), EVENT_REWARD_1 );
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, FALSE, _S(3570, "»öÁ¾ÀÌÁ¶ÇÕ"  ), EVENT_REWARD_2 );
				pUIManager->AddMessageBoxLString( MSGLCMD_SUMMER_2007, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù."  ) );	
				
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// [070807: Su-won] EVENT_ADULT_OPEN
			else if( nResult == EVENT_ADULT_MAGICCARD)
			{
				if( pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT_ADULT_MAGICCARD ) ) break;
				
				CTString strMessage;

				pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_EVENT_ADULT_MAGICCARD);				

				strMessage = _S(3619, "Á¦°¡ ¾Æ³¢´Â Áß¿äÇÑ ³îÀÌµµ±¸ Áß ÇÏ³ªÀÎ ¸ÅÁ÷Ä«µå¿¡¼­ 2ÀåÀÌ ±×¸¸ ¹Ù¶÷¿¡ ³¯·Á¼­ ¾îµð·Ð°¡ »ç¶óÁ³¾î¿ä.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3620, "±× Ä«µå¿¡´Â ¸¶¹ýÀÌ °É·ÁÀÖ¾î¼­ Àß¸ø °Çµå¸®¸é À§ÇèÇÑ ÀÏÀÌ ¹ú¾îÁúÁöµµ ¸ð¸£´Âµ¥... Å«ÀÏÀÌ³×¿ä!");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3621, "È¤½Ã¶óµµ ½ºÆäÀÌ½º AÄ«µå¿Í ÇÏÆ® AÄ«µå¸¦ ¹ß°ßÇÏ½Ã¸é ²À ÀúÇÑÅ× °¡Á®´Ù ÁÖ¼¼¿ä! °¨»çÀÇ Ç¥½Ã·Î ·¯ºê¸ÅÁ÷ ¸¶¹ýÁÖ¹®À» °É¾î µå¸±²²¿ä.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE,  CTString(" "));


				strMessage = _S(3244, "¡Ø ·¯ºê¸ÅÁ÷ ÁÖ¹® Á¾·ù");
				pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xE18600FF );
				strMessage = _S(3245, "¹Ù¶÷ÀÇ ·¯ºê¸ÅÁ÷-ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 10ºÐ°£ ÀÌµ¿¼Óµµ°¡ Çâ»óµÈ´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3246, "ÈûÀÇ ·¯ºê¸ÅÁ÷-ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ÈûÀÌ 20 Áõ°¡µÈ´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3247, "¹ÎÃ¸ÀÇ ·¯ºê¸ÅÁ÷-ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ¹ÎÃ¸ÀÌ 20Áõ°¡µÈ´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3248, "ÁöÇýÀÇ ·¯ºê¸ÅÁ÷-ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ÁöÇýÀÌ 20Áõ°¡µÈ´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3249, "Ã¼ÁúÀÇ ·¯ºê¸ÅÁ÷-ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ Ã¼ÁúÀÌ 50Áõ°¡µÈ´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3250, "·Î·¹ÀÎÀÇ ·¯ºê¸ÅÁ÷-ÁÖ¹®¿¡ °É¸° ¼ø°£ºÎÅÍ 30ºÐ°£ ¸ó½ºÅÍ °ø°Ý½Ã ÀÏÁ¤ È®·ü·Î º»ÀÎ Ä³¸¯ÅÍ µ¥¹ÌÁöÀÇ 10¹è¿¡ ÇØ´çÇÏ´Â µ¥¹ÌÁö¸¦ ÀÔÈù´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, TRUE, strMessage, -1, 0xA3A1A3FF);
				
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, FALSE, _S(3622, "¸ÅÁ÷Ä«µå º¸»ó ¹Þ±â"), 0);
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_MAGICCARD, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));

			}
			else if( nResult == EVENT_ADULT_CHANGEJOB)
			{
				if( pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT_ADULT_CHANGEJOB ) ) break;

				CTString strMessage;

				pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_EVENT_ADULT_CHANGEJOB);				

				strMessage = _S(3623, "ÀüÁ÷ÀÌ¶ó´Â °ÍÀº ±×µ¿¾È ¸¹Àº °æÇèÀ» ½×À¸¼Ì´Ù´Â Áõ°Å±âµµ ÇÏÁö¸¸ ¾ÕÀ¸·ÎÀÇ ¸ðÇè¿¡¼­ ´õ ¾î·Á¿î ÀûÀ» ¸¸³ª°Ô µÈ´Ù´Â ¶æÀÌ±âµµ ÇÏÁö¿ä.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_CHANGEJOB, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3624, "±×·± ÀÇ¹Ì·Î ÀüÁ÷À» ÇÏ½Å ºÐµé²² Á¦°¡ Á¤¸» Èûµé°Ô Æ¯º°È÷ °ø¼öÇØ¿Â ·ç³ª½Ã½º ÃÖ°íÀÇ ÁÖ¼ú»ç°¡ ¸¸µç Àý¸ÁÀÇ ºÎÀûÀ» Æ¯º°È÷ µå¸®°Ú½À´Ï´Ù.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_CHANGEJOB, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3625, "ÀûÀ» °ø°ÝÇÏ±â Àü¿¡ ÀÌ°É ÇÑ¹ø ½áÁÖ¸é Àý¸Á¿¡ ºüÁö°Ô ÇØ¼­ ´ÙÀ½ °ø°ÝÀÌ ¾ÆÁÖ °­·ÂÇÏ°Ô ¸ÔÈ÷´Ï±î ²Ï ¾µ¸ð°¡ ÀÖÀ» °Å¿¡¿ä.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_CHANGEJOB, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3626, "´Ü! »óÇ°ÀÇ °³¼ö´Â ¸ÕÀú ¿À½Å ¼ø¼­´ë·Î ¸¹ÀÌ µå¸®´Ï Âü°íÇÏ¼¼¿ä.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_CHANGEJOB, TRUE, strMessage, -1, 0xA3A1A3FF);

				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_CHANGEJOB, FALSE, _S(3627, "ÀüÁ÷ ÃàÇÏ »óÇ° ¹Þ±â"), 0);
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_CHANGEJOB, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));
			}
			else if( nResult == EVENT_ADULT_ALCHEMIST)
			{
				if( pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT_ADULT_ALCHEMIST ) ) break;

				CTString strMessage;

				pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_EVENT_ADULT_ALCHEMIST);				

				strMessage = _S(3628, "Á¤¸» Å¹¿ùÇÑ ¼±ÅÃÀÌ½Ã¿À. »ç½Ç ³»°¡ ±×µ¿¾È ½ÉÇ÷À» ±â¿ï¿©¼­ ¿¬±¸ÇÑ °á°ú·Î ´ë´ÜÇÑ ¿¬±Ý¼úÀ» °³¹ßÇØ ³Â´Âµ¥...");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3629, "¹Ù·Î Çå Àåºñ¸¦ °¡Áö°í ¹Ù·Î À­´Ü°èÀÇ »õ Àåºñ·Î Á¶ÇÕÇØÁÖ´Â Æ¯º°ÇÑ ±â¼úÀÌÁö¿ä.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3630, "Á¶ÇÕÀÌ ÀßµÇ¸é Á¦·ÃµÈ »õ Àåºñ¸¦ ¾òÀ» ¼öµµ ÀÖÀ¸´Ï ÀÌ°Å Á¤¸» ´ë´ÜÇÏÁö ¾Ê¼Ò?");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3631, "³Ê¹« ±âºÐÀÌ ÁÁ¾Æ¼­ ±â³äÀ¸·Î ¹«·á·Î Àåºñ¸¦ Á¶ÇÕÇØÁÖ´Â ÀÌº¥Æ®¸¦ ÇØº¼±îÇÏ´Âµ¥, Âü¿©ÇØ º¸°Ú¼Ò?");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3632, "ÀÌº¥Æ® ±â°£µ¿¾È ¾²´ø Àåºñ¿Í Àç·á¸¸ °¡Áö°í ¿À¸é µÇ´Ï ºÎ´ã °¡Áú °Í ¾ø´Ù¿À, ÇÏÇÏ.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3633, "¾ÆÂü, Á¶ÇÕÀ» ½ÃµµÇÏ±â Àü¿¡ ÀÌ°Ç ¾Ë¾ÆµÎ½Ã¿À. ¾Æ~ÁÖ ¿îÀÌ ³ª»Ú¸é °¡²û ¿¬±Ý¼úÀÌ ½ÇÆÐ°¡ µÇ±âµµ ÇÏ´Âµ¥ ½ÇÆÐÇÏ¸é Àåºñ¸¦ Á¦¿ÜÇÑ »ç¿ëµÈ Àç·áµéÀÌ ¸ðµÎ »ç¶óÁ® ¹ö¸± ¼öµµ ÀÖ°í,");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				strMessage = _S(3634, "40·¹º§ ÀÌ»óÀÇ Àåºñ´Â ¸¸µé ¼ö ¾ø´Ù´Â °Íµµ ±â¾ïÇÏ¸é ÁÁ°Ú¼Ò.");
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE, strMessage, -1, 0xA3A1A3FF);
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, TRUE,  CTString(" "));
				
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, FALSE, _S(3427, "ÀÌº¥Æ® Âü¿©ÇÏ±â"), 0);
				pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_ADULT_ALCHEMIST, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));

			}			
			else if( nResult == EVENT_SHOOT )
			{
				pUIManager->CloseMessageBox( MSGCMD_EVENT_SHOOT );

				CTString strMessage;
				// Create message box of remission
				CUIMsgBox_Info	MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo( _S(3658, "°ÅÄ§¾øÀÌ ½ð´Ù!" ), UMBS_OKCANCEL, UI_QUEST, MSGCMD_EVENT_SHOOT );
				strMessage.PrintF( _S(3659, "°ÅÄ§¾øÀÌ ½ð´Ù! ÀÌº¥Æ®¿¡ Âü¿©ÇÏ½Ã°Ú½À´Ï±î?" ) );
				MsgBoxInfo.AddString( strMessage );
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
			// [070807: Su-won] EVENT_ADULT_OPEN
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if( nResult == EVENT_TG2007_FRUITFULL ) // WSS_TG2007 2007/09/14 Ç³³â ÀÌº¥Æ®
			{
				pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_TG2007_FRUITFULL);
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3761,"Ç³³âÀÌº¥Æ®"),0x6BD2FFFF);
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3766,"´Ü°èº°·Î ¶ó½ºÆ®Ä«¿À½º ¾¾¾ÑÀ» ´ÙÀ½ ´Ü°è·Î ¾÷±×·¹ÀÌµå¸¦ ÇÏ½Ã·Á¸é °ü½É¾ÆÀÌÅÛÀÌ ÇÊ¿äÇÕ´Ï´Ù.") );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3767,"´ÙÀ½´Ü°è·ÎÀÇ ¾÷±×·¹ÀÌµå´Â ÀÏÁ¤ È®·ù·Î ¾÷±×·¹ÀÌµå µÇ¸ç ½ÇÆÐÇÒ ¼öµµ ÀÖ½À´Ï´Ù.") );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3768,"¾÷±×·¹ÀÌµåµÈ ¶ó½ºÆ®Ä«¿À½º ¾¾¾ÑÀº º¸»óÇ°°ú ±³È¯ÇÏ°Å³ª ´ÙÀ½ ´Ü°è·Î ¾÷±×·¹ÀÌµå ÇÒ ¼ö ÀÖ½À´Ï´Ù.") );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3769,"º¸»óÇ°Àº °¢ ´Ü°èº°·Î ´Ù¸¥ È®·ü·Î È¹µæÇÒ ¼ö ÀÖ½À´Ï´Ù.") );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 1866,"º¸»óÇ°"),0xA3A1A3FF );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3770,"¹®½ºÅæ"),0xA3A1A3FF );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3771,"µå¶ø ÁõÆøÁ¦ 3°³"),0xA3A1A3FF );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3772,"°³ÀÎÃ¢°í 7ÀÏ È®ÀåÄ«µå"),0xA3A1A3FF );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3773,"Áö·ÂÀÇ ¹°¾à"),0xA3A1A3FF );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, TRUE, _S( 3774,"°Ç°­ÀÇ ¹°¾à"),0xA3A1A3FF );
 				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, FALSE, _S( 1872,"ÀÛ¹°À» ¾÷±×·¹ÀÌµå ÇÑ´Ù." ), EVENT_REWARD_1 );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, FALSE, _S( 1873,"º¸»óÇ°À» Áö±Þ¹Þ´Â´Ù." ), EVENT_REWARD_2 );
				pUIManager->AddMessageBoxLString(MSGLCMD_TG2007_FRUITFULL, FALSE, _S( 1874,"Ãë¼ÒÇÑ´Ù."));				
			}
			else if( nResult == EVENT_RED_TREASUREBOX )
			{
				int iTreasureBoxLevel =0;
				if( pUIManager->GetInventory()->GetItemCount(2660) )	//5Lv ºÓÀº»ö º¸¹°»óÀÚ
				{
					iTreasureBoxLevel =5;

					if( _pNetwork->MyCharacterInfo.level < 5 )
					{
						_pNetwork->ClientSystemMessage( _S( 1757, "·¹º§ÀÌ ºÎÁ·ÇÏ¿© º¸¹° »óÀÚ¸¦ ¿­¼ö ¾ø½À´Ï´Ù." ), SYSMSG_ERROR );
						return;
					}
				}
				else if( pUIManager->GetInventory()->GetItemCount(2661) )	//12Lv ºÓÀº»ö º¸¹°»óÀÚ
				{
					iTreasureBoxLevel =12;

					if( _pNetwork->MyCharacterInfo.level < 12 )
					{
						_pNetwork->ClientSystemMessage( _S( 1757, "·¹º§ÀÌ ºÎÁ·ÇÏ¿© º¸¹° »óÀÚ¸¦ ¿­¼ö ¾ø½À´Ï´Ù." ), SYSMSG_ERROR );
						return;
					}
				}
				else if( pUIManager->GetInventory()->GetItemCount(2662) )	//16Lv ºÓÀº»ö º¸¹°»óÀÚ
				{
					iTreasureBoxLevel =16;

					if( _pNetwork->MyCharacterInfo.level < 16 )
					{
						_pNetwork->ClientSystemMessage( _S( 1757, "·¹º§ÀÌ ºÎÁ·ÇÏ¿© º¸¹° »óÀÚ¸¦ ¿­¼ö ¾ø½À´Ï´Ù." ), SYSMSG_ERROR );
						return;
					}
				}
				else
				{
					_pNetwork->ClientSystemMessage( _S( 1758, "º¸¹° »óÀÚ°¡ ¾ø½À´Ï´Ù." ), SYSMSG_ERROR );
					return;
				}

				CTString strMessage, strCount;

				pUIManager->CloseMessageBoxL( MSGLCMD_RED_TREASUREBOX_EVENT );
					
				pUIManager->CreateMessageBoxL( _S(100,"ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_RED_TREASUREBOX_EVENT );			
				
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, _S(4010, "ºÓÀº»ö º¸¹°»óÀÚ ÀÌº¥Æ®" ), -1, 0xE18600FF );	
				strMessage.PrintF( _S(4018, "%d Lv ºÓÀº»ö º¸¹°»óÀÚ¸¦ ¿­¸é ¾Æ·¡ ¾ÆÀÌÅÛÀÌ Áö±ÞµË´Ï´Ù.  %d Lv ºÓÀº»ö º¸¹°»óÀÚ¸¦ ¿­¾îº¸½Ã°Ú½À´Ï±î?" ), iTreasureBoxLevel, iTreasureBoxLevel );	
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, CTString("  "), -1, 0xA3A1A3FF );
				strMessage.PrintF( _S(4019, "%d Lv ºÓÀº»ö º¸¹°»óÀÚ Áö±Þ Ç°¸ñ"), iTreasureBoxLevel);	
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, strMessage, -1, 0xE18600FF );			

				strCount = pUIManager->IntegerToCommaString(5);
				strMessage.PrintF( _S( 61, "%s %s°³" ), _pNetwork->GetItemName(2658), strCount);
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );

				strCount = pUIManager->IntegerToCommaString(5);
				strMessage.PrintF( _S( 61, "%s %s°³" ), _pNetwork->GetItemName(2659), strCount);
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );
				
				if( iTreasureBoxLevel == 12 )
				{
					strCount = pUIManager->IntegerToCommaString(10);
					strMessage.PrintF( _S( 61, "%s %s°³" ), _pNetwork->GetItemName(2860), strCount);
					pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, TRUE, strMessage, -1, 0xA3A1A3FF );
				}
				
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, FALSE, _S(4020, "ºÓÀº»ö º¸¹°»óÀÚ¸¦ ¿¬´Ù." ), 1 );
				pUIManager->AddMessageBoxLString( MSGLCMD_RED_TREASUREBOX_EVENT, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );	
			}
			else if (nResult == EVENT_REQUITAL_1)
			{
				_pNetwork->SendEventRequital(0);	
			}
			else if (nResult == EVENT_REQUITAL_2)
			{
				_pNetwork->SendEventRequital(1);
			}
		}
		break;
	case MSGLCMD_QUEST_REQ:
		{
			// 2009. 05. 27 ±èÁ¤·¡
			// È®ÀåÆÑ¿¡¼­ ÀÌ¾ß±â ÇÑ´Ù Ç×¸ñÀÌ ºüÁö°í NPC°¡ Á¦°øÇÏ´Â ¸ðµç Äù½ºÆ® Áß¿¡
			// À¯Àú°¡ ¼±ÅÃÇÑ Äù½ºÆ®¸¦ ¼±ÅÃÇÏ°Ô ÇÑ´Ù.
			if( ciQuestClassifier < nResult )
			{
				// ¼±ÅÃÇÑ Äù½ºÆ®¿¡ ´ëÇØ ¼ö¶ô ¶Ç´Â º¸»ó Ã¢À» ¿¬´Ù.
				CUIQuestBook::SelectQuestFromMessageBox( nResult );
			}
			else
			{
				switch(nResult)
				{
				case MSGLCMD_EXCHANGE_HEALER:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_HEALER );
						MsgBox.AddString( _S(100055, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case MSGLCMD_EXCHANGE_KNIGHT:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_KNIGHT );
						MsgBox.AddString( _S(100056, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case MSGLCMD_EXCHANGE_MAGE:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_MAGE );
						MsgBox.AddString( _S(100057, ""), 0xa3a1a3ff );
						//MsgBox.AddString( _S( 8535, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case MSGLCMD_EXCHANGE_NIGHTSHADOW:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_NIGHTSHADOW );
						MsgBox.AddString( _S(100058, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case MSGLCMD_EXCHANGE_ROGUE:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_ROGUE );
						MsgBox.AddString( _S(100059, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case MSGLCMD_EXCHANGE_SORCERER:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_SORCERER );
						MsgBox.AddString( _S(100060, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case MSGLCMD_EXCHANGE_TITAN:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S(100062, ""), UMBS_OKCANCEL, UI_QUEST, MSGLCMD_EXCHANGE_TITAN );
						MsgBox.AddString( _S(100061, ""), 0xa3a1a3ff );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case QUEST_TALK: // Quest (È®ÀåÆÑ¹öÀü ÀÌÈÄ¿£ »ç¿ëÇÏÁö ¾Ê´Â´Ù.
					{
						CUIQuestBook::TalkWithNPC();
					}
					break;
				#ifdef DOMINATION_EVENT_SYSTEM
					case MSGLCMD_DOMINATION_EVENT_REG:
					{
						CNetworkMessage nmReg( (UBYTE)MSG_DOMINATION_EVENT );	
						nmReg << (UBYTE)MSG_DOMINATION_EVENT_REGISTER_REQ;
						_pNetwork->SendToServerNew(nmReg);
					}
					break;
				#endif
				case QUEST_EVENT:
					{
						if (g_bHasEvent)
						{
							CTString strMessage;
							pUIManager->CloseMessageBoxL( MSGLCMD_EVENT );
							
							strMessage = _S( 1875, "ÀÌº¥Æ® ¼±ÅÃÃ¢" );
							pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_EVENT );				
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, TRUE, strMessage, -1,0xE18600FF );				
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, TRUE, _S( 1876, "ÁøÇàÇÒ ÀÌº¥Æ®¸¦ ¼±ÅÃÇÏ¿© ÁÖ½Ê½Ã¿À." ), -1, 0xA3A1A3FF );	

							// kw : WSS_WHITEDAY_2007 , WSS_EVENT_LOD 
							if( IS_EVENT_ON(TEVENT_TREASUREBOX)  )
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S( 1877, "º¸¹°»óÀÚ ÀÌº¥Æ®." ), QUEST_TREASURE_BOX );	
							if( IS_EVENT_ON(TEVENT_RED_TREASUREBOX)  )
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(4010, "ºÓÀº»ö º¸¹°»óÀÚ ÀÌº¥Æ®" ), EVENT_RED_TREASUREBOX );
							if (IS_EVENT_ON(TEVENT_CHUSEOK_2006))
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S( 1860, "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®." ), QUEST_HARVEST_MOON_DAY_EVENT1 );	

							#ifdef RENUAL_EVENT			// 2P4P Renual Event  10/6 Update
									pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(2213, "ÀÌÆÇ»çÆÇ ¿ÀÇÂ ÀÌº¥Æ®." ), QUEST_RENUAL_EVENT );	
							#endif

							if(g_iTempFlag&0x00200000)
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(2404, "ÄíÆù ÀÌº¥Æ®" ), EVENT_COUPON );
							if(g_iTempFlag&0x00400000)
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(2509, "Á¢¼Ó ÀÌº¥Æ® »óÇ° ¹Þ±â" ), EVENT_CONNECT );

							if (IsGamigo(g_iCountry) == TRUE || g_iCountry == USA)
							{
								if ( g_iCountry != FRANCE && g_iCountry != ITALY)
								{
									pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(3145, "ÇÁ·Î¸ð ÆÐÅ°Áö»óÇ° ÀÌº¥Æ®" ), EVENT_PROMOPACK );
								}
							}

							// wooss 070305 
							// kw : WSS_WHITEDAY_2007 , WSS_EVENT_LOD --------------------------------------------------------------------->>
							if( IS_EVENT_ON(A_EVENT_WHITE_DAY)  )
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(3238, "È­ÀÌÆ®µ¥ÀÌ ÀÌº¥Æ®" ), EVENT_WHITEDAY_2007 );
							// ------------------------------------------------------------------------------------------------------------<<
							// [070705: Su-won] EVENT_SUMMER_2007
							if( IS_EVENT_ON(TEVENT_SUMMER_2007)  )
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S(3561, "Á¾ÀÌ Á¢±â ÀÌº¥Æ®" ), EVENT_SUMMER_2007 );

							if (IS_EVENT_ON(TEVENT_SUMMER_2008))
							{
								pUIManager->AddMessageBoxLString(MSGLCMD_EVENT, FALSE, _S(3617, "[¸ÅÁ÷Ä«µå¸¦ Ã£¾Æ¶ó!] ÀÌº¥Æ® Âü¿©"), EVENT_ADULT_MAGICCARD);
							}

							if( IS_EVENT_ON(TEVENT_ADULT_OPEN) )
							{
								pUIManager->AddMessageBoxLString(MSGLCMD_EVENT, FALSE, _S(3658, "°ÅÄ§¾øÀÌ ½ð´Ù!"), EVENT_SHOOT);
								pUIManager->AddMessageBoxLString(MSGLCMD_EVENT, FALSE, _S(3617, "[¸ÅÁ÷Ä«µå¸¦ Ã£¾Æ¶ó!] ÀÌº¥Æ® Âü¿©"), EVENT_ADULT_MAGICCARD);
							}

							// WSS_TG2007 2007/09/17 Ç³³â ÀÌº¥Æ®
							if( IS_EVENT_ON(TEVENT_TG2007_FRUITFULL)  )
								pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S( 3761, "Ç³³â ÀÌº¥Æ®" ), EVENT_TG2007_FRUITFULL );

			#ifdef EVENT_REQUITALM //[ttos_2009_4_13]:¼­¹ö ¿À·ù º¸»óÀÌº¥Æ®				
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT, FALSE, _s("¼­¹ö ¿À·ù °ü·Ã º¸»óÇ° ¹Þ±â"), EVENT_REQUITAL_1); 
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT, FALSE, _s("Ãâ¼® Ã¼Å© º¸»óÇ° ¹Þ±â"), EVENT_REQUITAL_2); 
			#endif
							if (IS_EVENT_ON(TEVENT_ADD_UP_AFRON_2009))
							{
								pUIManager->AddMessageBoxLString(MSGLCMD_EVENT, FALSE, _s("Ãâ¼® Ã¼Å© º¸»óÇ° ¹Þ±â"), EVENT_REQUITAL_2); 
							}

							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù." ) );		
						}
					}
					break;
				case QUEST_CHANGEWEAPON:
					{
						pUIManager->CloseMessageBoxL( MSGLCMD_CHANGEWEAPON_EVENT_REQ );
						pUIManager->CreateMessageBoxL( _S( 1204, "¹«±â±³Ã¼ ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_CHANGEWEAPON_EVENT_REQ );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, _S( 1205, "ÀÌº¥Æ®·Î ¹«±â ±³Ã¼¸¦ ÇÒ °æ¿ì »ç¿ëÇÏ´ø ¹«±âÀÇ Á¦·Ã°ªÀÌ³ª, ºí·¯µå ¿É¼ÇÀº ±×´ë·Î ±³Ã¼ ¹«±â¿¡ ¿Å°ÜÁý´Ï´Ù." ), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, CTString("  "), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, _S( 1206, "±³Ã¼µÇ´Â ¹«±â´Â ÇØ´ç Å¬·¡½º°¡ »ç¿ëÇÏ´ø ¹«±âÀÇ »ó¹ÝµÈ ¹«±â¸¸ °¡´ÉÇÕ´Ï´Ù." ), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, _S( 1207, "(Ex > Å¸ÀÌÅº : ´ë°Ë <-> µµ³¢·Î¸¸ ±³Ã¼)" ), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, CTString("  "), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, _S( 1208, "±³Ã¼ °¡´É È¸¼ö´Â ÀÌº¥Æ® ±â°£¿¡ ÇÑÇØ¼­ Á¦ÇÑ ¾øÀÌ ÇÒ ¼ö ÀÖ½À´Ï´Ù." ), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, CTString("  "), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, TRUE, _S( 1209, "·Î±×¿Í Èú·¯ÀÇ °æ¿ì ¿É¼ÇÀÌ ±³Ã¼µÇ´Â ¹«±â¿¡ ÀûÇÕÇÏ°Ô º¯°æµÇ´Ï È¨ÆäÀÌÁö¸¦ Âü°íÇÏ½Ã±â ¹Ù¶ø´Ï´Ù." ), -1, 0xA3A1A3FF );				
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, FALSE, _S( 1210, "¹«±â¸¦ ±³Ã¼ÇÑ´Ù." ), EVENT_CHANGEWEAPON );		
						pUIManager->AddMessageBoxLString( MSGLCMD_CHANGEWEAPON_EVENT_REQ, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );					
					}
					break;
				case QUEST_KILL_BOSS:					// ¹ß·Ï °ÝÆÄ.
					{
						// FIXME : ½Ì±Û ´øÁ¯ ÀÔÀå ºÎºÐ...
						// FIXME : ÁË´Ù ÇÏµå ÄÚµù~~~!!!
						// FIXME : ÄÚµå Áßº¹µµ ½ÉÇÔ....
						// FIXME : Hardcoding ÀÎµ¦½º
						const int iQuestIndex = 13;
						if( CQuestSystem::Instance().CanIDoQuest( iQuestIndex ) )
						{
							if( CQuestSystem::Instance().GetDynamicDataByQuestIndex( iQuestIndex ) == NULL )
							{										
								pUIManager->GetQuestAccept()->open( iQuestIndex );
							}
							else
							{
								CTString strSysMessage;
								strSysMessage.PrintF( _S( 1687, "ÀÌ¹Ì ¼öÇàÁßÀÎ Äù½ºÆ®ÀÔ´Ï´Ù."  ) );		
								_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
							}
						}
						else
						{
							CTString strSysMessage;
							strSysMessage.PrintF( _S( 1688, "Á¶°ÇÀÌ ¸ÂÁö ¾Ê½À´Ï´Ù."  ) );		
							_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
						}
					}
					break;
				case QUEST_SAVE_PRINCESS:						// °øÁÖ ±¸Ãâ
					{
						// FIXME : Hardcoding ÀÎµ¦½º
						const int iQuestIndex = 14;
						if( CQuestSystem::Instance().CanIDoQuest( iQuestIndex ) )
						{
							if( CQuestSystem::Instance().GetDynamicDataByQuestIndex( iQuestIndex ) == NULL )
							{										
								pUIManager->GetQuestAccept()->open( iQuestIndex );
							}
							else
							{
								CTString strSysMessage;
								strSysMessage.PrintF( _S( 1687, "ÀÌ¹Ì ¼öÇàÁßÀÎ Äù½ºÆ®ÀÔ´Ï´Ù."  ) );		
								_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
							}
						}
						else
						{
							CTString strSysMessage;
							strSysMessage.PrintF( _S( 1688, "Á¶°ÇÀÌ ¸ÂÁö ¾Ê½À´Ï´Ù."  ) );		
							_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
						}
					}
					break;
				case QUEST_AZAKA_RAVINE:						// ¾ÆÀÚÄ« Çù°î
					{
						// FIXME : Hardcoding ÀÎµ¦½º
						const int iQuestIndex = 104;
						if( CQuestSystem::Instance().CanIDoQuest( iQuestIndex ) )
						{
							if( CQuestSystem::Instance().GetDynamicDataByQuestIndex( iQuestIndex ) == NULL )
							{										
								pUIManager->GetQuestAccept()->open( iQuestIndex );
							}
							else
							{
								CTString strSysMessage;
								strSysMessage.PrintF( _S( 1687, "ÀÌ¹Ì ¼öÇàÁßÀÎ Äù½ºÆ®ÀÔ´Ï´Ù."  ) );		
								_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
							}
						}
						else
						{
							CTString strSysMessage;
							strSysMessage.PrintF( _S( 1688, "Á¶°ÇÀÌ ¸ÂÁö ¾Ê½À´Ï´Ù."  ) );		
							_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
						}
					}
					break;
				case QUEST_GATE_OF_DIMENSION:				// Â÷¿øÀÇ ¹®
					{
						pUIManager->CloseMessageBoxL( MSGLCMD_GATE_OF_DIMENSION );
						pUIManager->CreateMessageBoxL( _S( 1686, "Â÷¿øÀÇ ¹®" ), UI_QUEST, MSGLCMD_GATE_OF_DIMENSION );				
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, TRUE, _S( 1689, "Àú¿¡°Ô ¾î¶² º¼ÀÏÀÌ ÀÖÀ¸½Å°¡¿ä?" ), -1, 0xA3A1A3FF );		
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, TRUE, _S( 1690, "Â÷¿øÀÇ ¹®Àº ¸¹Àº ¸ó½ºÅÍµéÀÌ Â÷¿øÀÇ ¹®À» ÅëÇØ ¾ÆÀÌ¸®½º ´ë·úÀ¸·Î ³Ñ¾î¿À±â ¶§¹®¿¡ À§ÇèÇÑ °÷ÀÔ´Ï´Ù." ), -1, 0xA3A1A3FF );	
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, TRUE, CTString( "  " ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, TRUE, _S( 1691, "Â÷¿ø¿¡ ¹®¿¡¼­ µ¹¾Æ ¿À½Ã¸é Àú¸¦ ´Ù½ÃÇÑ¹ø Ã£¾Æ ÁÖ¼¼¿ä ´ç½ÅÀÌ ¾ÆÀÌ¸®½º ´ë·ú¿¡ ±â¿©ÇÏ´Â Á¤µµ¸¦ È®ÀÎÇÏ½Ç ¼ö ÀÖÀ» °Ì´Ï´Ù." ), -1, 0xA3A1A3FF );	
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, TRUE, _S( 1692, "¹°·Ð ±× ±â¿©µµ¿¡ µû¶ó ¶õµ¹¼ºÁÖ°¡ ³»¸®´Â Æ÷»óµµ ¹ÞÀ¸½Ç ¼ö ÀÖÀ» °Ì´Ï´Ù." ), -1, 0xA3A1A3FF );		
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, FALSE, _S( 1694, "Â÷¿øÀÇ ¹® ¼øÀ§È®ÀÎ" ), GOD_RANKING );		
						pUIManager->AddMessageBoxLString( MSGLCMD_GATE_OF_DIMENSION, FALSE, _S( 1695, "º¸»ó"), GOD_PRIZE );		
					}
					break;
				case QUEST_EXCHANGE_MONEY:
					{
						pUIManager->CloseMessageBoxL( MSGLCMD_EVENT_2PAN4PAN_ONE );
						pUIManager->CreateMessageBoxL( _S( 1875, "ÀÌº¥Æ® ¼±ÅÃÃ¢" ), UI_QUEST, MSGLCMD_EVENT_2PAN4PAN_ONE );	
						pUIManager->AddMessageBoxLString( 
							MSGLCMD_EVENT_2PAN4PAN_ONE, 
							TRUE,
							_S(2214,"2pan4pan ¸Â°í Ä«µå¿Í 2pan4pan Æ÷Ä¿ Ä«µî´Â °ÔÀÓÆ÷ÅÐ »çÀÌÆ®ÀÎ 2pan4panÀÇ ¸Â°í, Æ÷Ä¿ °ÔÀÓ¿¡¼­ »ç¿ëÇÒ ¼ö ÀÖ´Â °ÔÀÓ ¸Ó´Ï·Î ±³È¯ÇÒ ¼ö ÀÖ½À´Ï´Ù." ),
							-1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_2PAN4PAN_ONE, TRUE, CTString("\n\n") , -1,0xA3A1A3FF );		
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_2PAN4PAN_ONE, TRUE, _S(2215, "2pan4pan ¸Â°íÄ«µå :          : ¸Â°í¸Ó´Ï" ), -1, 0xFFA41CFF );		
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_2PAN4PAN_ONE, TRUE, _S(2216, "2pan4pan Æ÷Ä¿Ä«µå :          : Æ÷Ä¿¸Ó´Ï" ), -1, 0xFFA41CFF );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_2PAN4PAN_ONE, FALSE, _S(2217,"2pan4pan ¸Â°íÄ«µå ±³È¯"),EXCH_FIVE);
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_2PAN4PAN_ONE, FALSE, _S(2218,"2pan4pan Æ÷Ä¿Ä«µå ±³È¯"),EXCH_FOUR);
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_2PAN4PAN_ONE, FALSE,_S( 1220, "Ãë¼ÒÇÑ´Ù." ));
					}
					break;
				case  QUEST_OPEN_TREASURE:
					{
						_pNetwork->SendEvent24(0,MSG_EVENT_2PAN4PAN_BOX_CHECK);
					}
					break;
				case QUEST_CHARACTER_CARD:
					{
						_pNetwork->SendEvent24(0,MSG_EVENT_2PAN4PAN_GOODS_CHECK);
					}
					break;
				case EVENT_NEWYEAR1:
					{
						if(pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT_NEWYEAR1 )) break;
						pUIManager->CreateMessageBoxL(_S (1875,"ÀÌº¥Æ® ¼±ÅÃÃ¢"), UI_QUEST,MSGLCMD_EVENT_NEWYEAR1);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR1, TRUE,	_S(2286,"2005 Å©¸®½º¸¶½º ÀÌº¥Æ®"),-1,0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR1, TRUE, 
							_S(2288,"²Þ°ú Èñ¸Á ¾ÆÀÌÅÛÀ» Á¶ÇÕÇÏ¿© º¸»óÀ» ¹ÞÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù.\nº¸»ó ¹°Ç°Àº È¨ÆäÀÌÁö¸¦ ÂüÁ¶ÇÏ¼¼¿ä."));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR1, TRUE,	_S(2305,"²Þ°ú Èñ¸Á ÀÌº¥Æ® º¸»ó Á¶°Ç"),-1,0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR1, TRUE,	
							_S(2289,"²Þ(4°³) + Èñ¸Á(1°³)\n²Þ(8°³) + Èñ¸Á(2°³)\n²Þ(16°³) + Èñ¸Á(4°³)\n²Þ(24°³) + Èñ¸Á(6°³)\
							\n²Þ(40°³) + Èñ¸Á(10°³)\n²Þ(56°³) + Èñ¸Á(14°³)\n²Þ(80°³) + Èñ¸Á(20°³)"));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR1, FALSE, _S(2290,"²Þ°ú Èñ¸Á º¸»óÇ°À» Áö±Þ ¹Þ´Â´Ù."),EVENT_NEWYEAR1_REWARD);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR1, FALSE, _S(1220,"Ãë¼ÒÇÑ´Ù."));
					}
					break;
				case EVENT_NEWYEAR2:
					{
						if(pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT_NEWYEAR2 )) break;
						pUIManager->CreateMessageBoxL(_S (1875,"ÀÌº¥Æ® ¼±ÅÃÃ¢"), UI_QUEST,MSGLCMD_EVENT_NEWYEAR2);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, TRUE,	_S(2287,"2006 ½Å³â ÀÎ³»ÀÇ ¿­¸Å ÀÌº¥Æ®"),-1,0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, TRUE, 
							_S(2291,"ÀÌº¥Æ® ±â°£µ¿¾È À¯ÀúµéÀº ÀÚ½ÅÀÇ Ä³¸¯ÅÍ »ç³É ½Ã°£¿¡ µû¸¥ º¸»óÇ°À» Áö±Þ ¹ÞÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù.\nº¸»óÇ°Àº ÀÌº¥Æ® ±â°£ÀÌ ³¡³­ ´ÙÀ½ºÎÅÍ Áö±ÞµË´Ï´Ù."));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, TRUE,	_S(2292,"ÀÎ³»ÀÇ ¿­¸Å ÀÌº¥Æ® º¸»óÇ°"),-1,0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, TRUE,	
							_S(2293,"10½Ã°£          100,000 Nas\n20½Ã°£          200,000 Nas\n30½Ã°£      °í±Þ Á¦·Ã¼® 1°³"));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, FALSE, _S(2294,"Á¢¼Ó½Ã°£ È®ÀÎ"),EVENT_NEWYEAR2_TIMECHECK);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, FALSE, _S(2295,"ÀÎ³»ÀÇ ¿­¸Å º¸»óÇ°À» Áö±Þ ¹Þ´Â´Ù."),EVENT_NEWYEAR2_REWARD);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_NEWYEAR2, FALSE, _S(1220,"Ãë¼ÒÇÑ´Ù."));
					}
					break;
				case EVENT_FIND_FRIEND:
					{
						if(pUIManager->DoesMessageBoxLExist( MSGLCMD_EVENT_FIND_FRIEND )) break;
						pUIManager->CreateMessageBoxL(_S (1875,"ÀÌº¥Æ® ¼±ÅÃÃ¢"), UI_QUEST,MSGLCMD_EVENT_FIND_FRIEND);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, TRUE,	_S( 2433, "Ä£±¸ Ã£±â ÀÌº¥Æ®"),-1,0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, TRUE, 	_S( 2480, "º¸°í ½ÍÀº Ä£±¸¸¦ µî·ÏÇÏ¼¼¿ä."));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, TRUE, 
							_S( 2481, "Ä£±¸°¡ ´Ù½Ã µ¹¾Æ¿Í °ÔÀÓÀ» ÇÏ¸é Ä£±¸´Â 60½Ã°£µ¿¾È »ç³ÉÁß¿¡ 2¹èÀÇ °æÇèÄ¡¸¦ ¾ò°Ô µÇ°í Ä£±¸°¡ ÀÏÁ¤½Ã°£ ÀüÅõ¸¦ ÇÏ¸é Ä£±¸¿Í ÇÔ²² º¸»óÀ» ¹ÞÀ» ¼ö ÀÖ´Â ÀÌº¥Æ® ÀÔ´Ï´Ù."));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, TRUE,	_S( 2482, "Ä£±¸ Ã£±â ÀÌº¥Æ® º¸»óÇ°"),-1,0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, TRUE,	
							_S( 2483,"Ä£±¸°¡ ´Ù½Ã µ¹¾Æ¿Í 30½Ã°£ ÀÌ»ó »ç³ÉÀ» ÇÏ°Ô µÇ¸é ÈÞ¸é Ä³¸¯Àº °í±Þ Á¦·Ã¼® 2°³°¡ Ä£±¸¸¦ µî·ÏÇÑ Ä³¸¯ÅÍÀº °í±ÞÁ¦·Ã¼® 1°³°¡ Áö±ÞµË´Ï´Ù."));
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, FALSE, _S( 2484, "Ä£±¸ µî·Ï"),EVENT_FF_REG);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, FALSE, _S( 2485, "ÈÞ¸éÄ³¸¯ »ç³É½Ã°£ È®ÀÎ"),EVENT_FF_TIMECHECK);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, FALSE, _S( 2486, "º¸»ó°¡´É È®ÀÎ ¹× Áö±Þ"),EVENT_FF_REWARD);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_FIND_FRIEND, FALSE, _S(1220,"Ãë¼ÒÇÑ´Ù."));
					}
					break;
				case EVENT_CLOTHES_EXCHANGE:		// 060322 eons
					{
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_CLOTHES_EXCHANGE ) ) break;
						pUIManager->CreateMessageBoxL( _S( 2537, "ÀüÅëÀÇ»ó ±³È¯ ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_CLOTHES_EXCHANGE );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, TRUE,
							_S( 2538, "ÀüÅëÀÇ»óÀ¸·Î ±³È¯ÇÏ±â À§ÇØ¼­´Â º¢²É ºÀ¿ì¸®°¡ ÇÊ¿äÇÕ´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, TRUE,
							_S( 2539, "»óÀÇ, ÇÏÀÇ : º¢²É ºÀ¿ì¸® 18°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, TRUE,
							_S( 2540, "Àå°©, ½Å¹ß : º¢²É ºÀ¿ì¸® 12°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, TRUE,
							_S( 2541, "Åõ±¸ : º¢²É ºÀ¿ì¸® 7°³" ), -1, 0xA3A1A3FF );

						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, FALSE, _S( 2542, "»óÀÇ, ÇÏÀÇ" ), COAT_PANTS );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, FALSE, _S( 2543, "Àå°©, ½Å¹ß" ), GLOVE_FOOTWEAR );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, FALSE, _S( 2544, "Åõ±¸" ), HELMET );
						pUIManager->AddMessageBoxLString( MSGLCMD_CLOTHES_EXCHANGE, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_OX_GOZONE:				// O.X ÀÌº¥Æ®
					{
						CTString strSysMessage;
						CUIMsgBox_Info	MsgBoxInfo;

						MsgBoxInfo.SetMsgBoxInfo( _S( 169, "ÀÌº¥Æ®" ), UMBS_USER_12, UI_QUEST, MSGLCMD_EVENT_OXQUIZ, MSGBOX_WIDTH + 20 );
						MsgBoxInfo.SetUserBtnName( _S( 191, "È®ÀÎ" ), _S( 139, "Ãë¼Ò" ) );

						strSysMessage.PrintF( _S(2617, "O.X ÀÌº¥Æ® Á¸À¸·Î ÀÔÀåÇÏ½Ã°Ú½À´Ï±î?" ) );
						MsgBoxInfo.AddString( strSysMessage);

						pUIManager->CreateMessageBox( MsgBoxInfo );
					}
					break;
#ifdef NETCAFE_CAMPAIGN
				case EVENT_NETCAFE_BOX:
					{// Date : 2006-04-27(¿ÀÈÄ 3:01:37), By eons
						_pNetwork->SendNetCafeOpenBox();
					}
					break;
#endif
				case WIN_SELECT:				// ¿ì½Â±¹ ¾Ë¾Æ ¸ÂÃß±â
					{
						if( pUIManager->DoesMessageBoxLExist( MSGCMD_WORLDCUP_EVENT1 ) ) break;
						pUIManager->CreateMessageBoxL(  _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGCMD_WORLDCUP_EVENT1 );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2797, "1. ¿ì½Â±¹°¡ ¸ÂÃß±â ÀÌº¥Æ®" ) , -1 , 0xFFE591FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2798, "¿ì½ÂÄÅÀ» ¸ð¾Æ Ãà±¸´ëÈ¸ º»¼± Âü°¡ 32°³±¹ Áß ¿ì½ÂÀÌ ¿¹»óµÇ´Â ±¹°¡ÀÇ ±¹±â¿Í ±³È¯ÇÏ¸é ´ëÈ¸°¡ ³¡³­ ÀÌÈÄ °á°ú¿¡ µû¶ó º¸»ó ¹ÞÀ» ¼ö ÀÖ½À´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2799, "¡Ø ¿ì½Â È®·ü¿¡ µû¶ó ÇÊ¿äÇÑ ¿ì½ÂÄÅÀÇ °³¼ö°¡ ´Ù¸¨´Ï´Ù." ), -1 , 0xFFE591FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2800, "¡Ø ±¹±â±³È¯±â°£ : 6¿ù9ÀÏ ~ 6¿ù 30ÀÏ" ), -1 , 0xFFE591FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE, CTString (""));
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2801, "[º¸»óÇ°]" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2802, "1À§ : °í±ÞÁ¦·Ã¼® 3°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2803, "2À§ : °í±ÞÁ¦·Ã¼® 1°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2804, "3À§ : 300,000³ª½º" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, TRUE,
							_S( 2805, "±×¿Ü : ¹®½ºÅæ 5°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, FALSE, _S( 2806, "¿ì½ÂÄÅÀ» ±¹±â·Î ±³È¯ÇÑ´Ù." ), WORLDCUP_EVENT1_EXCHANGE );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, FALSE, _S( 2807, "º¸»óÇ°À» Áö±Þ ¹Þ´Â´Ù" ), WORLDCUP_EVENT1_RECEIVE );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_GOLDENBALL:
					{
						if( pUIManager->DoesMessageBoxLExist( MSGCMD_WORLDCUP_GOLDENBALL ) ) break;
						
						if( !m_bStartGoldenBall && !m_bGoldenBallRequital )
						{
							_pNetwork->ClientSystemMessage( _S( 945, "Áö±ÝÀº ÀÌº¥Æ® ±â°£ÀÌ ¾Æ´Õ´Ï´Ù." ), SYSMSG_ERROR );
							return;
						}

						CTString strMessageA, strMessageB, strMessageC;
						strMessageA.PrintF( _S( 2808, "ÇöÀç °ñµçº¼ ÀÌº¥Æ®´Â %s VS %s ÀÇ Ãà±¸ °æ±â ÀÔ´Ï´Ù." ), m_strTeamA, m_strTeamB );
						strMessageB.PrintF( _S( 2809, "%s VS %s °ñµç º¼ ÀÀ¸ð" ), m_strTeamA, m_strTeamB );
						strMessageC.PrintF( _S( 2810, "%s VS %s °ñµç º¼ º¸»ó" ), m_strTeamA, m_strTeamB );

						pUIManager->CreateMessageBoxL( _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGCMD_WORLDCUP_GOLDENBALL );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, TRUE, strMessageA );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, TRUE,
							_S( 2811, "ÀÚ½ÅÀÌ ¿¹ÃøÇÑ °á°ú¿Í °æ±â °á°ú°¡ °°À» °æ¿ì »óÇ°À» Áö±ÞÇÕ´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, TRUE, CTString( " " ) );
						
						if( m_bGoldenBallRequital ) // °ñµçº¼ º¸»óÁßÀÌ¶ó¸é
						{// °æ±â°á°ú¸¦ Ç¥½Ã
							strMessageA.PrintF( _S( 2791, "%s VS %s Ãà±¸°æ±âÀÇ °á°ú´Â %d : %d ÀÔ´Ï´Ù." ),
								pUIManager->GetQuest()->GetStrTeamA(), pUIManager->GetQuest()->GetStrTeamB(),
								pUIManager->GetQuest()->GetScoreTeamA(), pUIManager->GetQuest()->GetScoreTeamB() );

							pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, TRUE, strMessageA, 0x6BD2FFFF );
						}

						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, FALSE, strMessageB, MSGCMD_WORLDCUP_GOLDENBALL_ENTRY );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, FALSE, strMessageC, MSGCMD_WORLDCUP_GOLDENBALL_REQUITAL );
						pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_GOLDENBALL, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_MOTHERDAY:
				case EVENT_RAINYDAY:
					{
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_MOTHERDAY ) ) break;
						pUIManager->CreateMessageBoxL( _S(2753, "¾î¸Ó´Ï³¯ ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_MOTHERDAY );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,
							_S(2754, "¾î¸Ó´Ï³¯À» ¸Â¾Æ Àð½º¹Î²É ÀÌº¥Æ®°¡ ÁøÇàµÇ°í ÀÖ½À´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,
							_S(2755, "¿©·¯ºÐÀÌ ½ÀµæÇÏ½Å Àð½º¹Î²ÉÀÌ³ª Àð½º¹Î²É ºê·ÎÄ¡¸¦ °¡Á® ¿À½Ã¸é º¸»ó¾ÆÀÌÅÛÇ°¸ñ Áß 1°³ Ç°¸ñ ÀÏÁ¤È®·ü·Î µå¸³´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,
							_S(2756, "Àð½º¹Î²É 10°³¸¦ °¡Á® ¿À½Ã¸é ÀÌº¥Æ® º¸»óÀ» ¹ÞÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù. " ));
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,
							_S(2757, "Àð½º¹Î²É ºê·ÎÄ¡ 1°³´Â Àð½º¹Î²É 5°³¿Í °°À¸¸ç, ±³È¯½Ã¿¡´Â Àð½º¹Î²É ºê·ÎÄ¡°¡ ¿ì¼±ÀûÀ¸·Î ±³È¯µÇ°í ÀÜ ¿©ºÐ¿¡ ´ëÇÏ¿© Àð½º¹Î²ÉÀÌ ±³È¯µË´Ï´Ù." ));

						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(2758,  "º¸»ó ¾ÆÀÌÅÛ" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S( 2759,"»çÅÁ 5°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(  2760,"Çª¸¥³Ù,ÄÉ¸£ ¼ÂÆ®" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(  2761,"ºÓÀº³Ù,ÄÉ¸£ ¼ÂÆ®" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(  2762,"´ëÇü È¸º¹Á¦ 5°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(  2763,"³ë·ÂÀÇ ½ºÅ©·Ñ 1°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(  2764,"Çà¿îÀÇ ½ºÅ©·Ñ 1°³" ), -1, 0xA3A1A3FF );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, TRUE,	_S(  2765,"°í±Þ Á¦·Ã¼® 1°³" ), -1, 0xA3A1A3FF );
						
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, FALSE, _S( 2766,"º¸»ó¹°Ç°À¸·Î ±³È¯ÇÑ´Ù." ), 1 );
						pUIManager->AddMessageBoxLString( MSGLCMD_MOTHERDAY, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_BUDDHISM:
					{
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_BUDDHISM_EVENT ) ) break;
						pUIManager->CreateMessageBoxL( _S( 2913, "ºÒ±³ ÃÐºÒ ÃàÁ¦ ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_BUDDHISM_EVENT );

						/********************************************/
						// 2007³â
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, TRUE,
							_S(3590, "°¢Á¾ »ö±òÀÇ ¸ð·¡°¡ µç ºÀÅõ¸¦ ¸ð¾Æ¿À¸é ¾ÆÀÌÅÛÀ» µå¸³´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, TRUE,
							_S(3591, "4°¡Áö »ö±òÀÇ ¸ð·¡ºÀÅõ¸¦ °¢°¢ 10°³¾¿ ¸ð¾Æ¿À¸é Çà¿îÀÇ °í±ÞÁ¦·Ã¼®À», °¢°¢ 7°³¾¿ ¸ð¾Æ¿À¸é °í±ÞÁ¦·Ã¼®À», °¢°¢ 5°³¾¿ ¸ð¾Æ¿À¸é ¼º¼öº´À», °¢°¢ 3°³¾¿ ¸ð¾Æ¿À¸é µå·ÓÀ² ÁõÆøÁ¦¸¦, °¢°¢ 2°³¾¿ ¸ð¾Æ¿À¸é ¾çÃÊ¸¦ µå¸®°í," ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, TRUE,
							_S(3592, "Àû»ö°ú È²»ö °¢°¢ 2°³¾¿À» ¸ð¾Æ¿À¸é ±¸¿øÀÇ ´«¹°À», ³ì»ö°ú ³²»öÀ» °¢°¢ 2°³¾¿ ¸ð¾Æ¿À¸é ¿ë¼­ÀÇ ´«¹°À» µå¸³´Ï´Ù." ) );

						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, TRUE,
							_S( 2923, "º¸»óÀ¸·Î ¾î¶²°É ¿øÇÏ´Â°¡?" ) );
						/*********************************************/
						
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, TRUE, CTString(" ") );

						/*************************************/
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(974)), 0);	//Çà¿îÀÇ °í±ÞÁ¦·Ã¼®
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(85)), 1);		//°í±ÞÁ¦·Ã¼®
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(1576)), 2);	//¼º¼öº´
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(884)), 3);	//µå·ÓÀ² ÁõÆøÁ¦
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(1575)), 4);	//¾çÃÊ
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(675)), 5);	//±¸¿øÀÇ ´«¹°
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, CTString(_pNetwork->GetItemName(676)), 6);	//¿ë¼­ÀÇ ´«¹°
						/*************************************/
						pUIManager->AddMessageBoxLString( MSGLCMD_BUDDHISM_EVENT, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_COLLECTBUGS:
					{
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_COLLECT_INSECT_EVENT ) ) break;
						
						pUIManager->CreateMessageBoxL( _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_COLLECT_INSECT_EVENT );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE, 
							_S( 2947, "¿©¸§¹æÇÐ ¼÷Á¦·Î °ïÃæÃ¤ÁýÀ» Çß´ø °æÇèÀ» ¶°¿Ã¸®¸ç ¾î¸°½ÃÀý·Î µ¹¾Æ°¡º¸´Â °ÍÀº ¾î¶³±î¿ä?" ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE,
							_S( 2948, "°ïÃæÃ¤Áý»óÀÚ¸¦ ±¸ÀÔÇÏ½Ã¸é ¸ó½ºÅÍ·ÎºÎÅÍ ¿©¸§ °ïÃæÀ» Ã¤ÁýÇÒ ¼ö ÀÖ½À´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE,
							_S( 2949, "¿©¸§°ïÃæÀº ÃÑ 10Á¾·ù·Î °¢°¢ 1~10 Æ÷ÀÎÆ®°¡ Á¤ÇØÁ® ÀÖ°í, Ã¤Áý»óÀÚ¿¡´Â 16¸¶¸®ÀÇ °ïÃæÀ» ¼öÁýÇÒ ¼ö ÀÖÀ¸´Ï ´Ù Ã¤¿öÁö¸é Àú¿¡°Ô °¡Á®¿À¼¼¿ä." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE,
							_S( 2950, "Ã¤Áý»óÀÚÀÇ ÃÑ Æ÷ÀÎÆ® ÇÕ°è¿¡ µû¶ó¼­ º¸»óÇ°À» µå¸³´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE, CTString(" ") );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE,
							_S( 2951, "¡Ø ÀÌº¥Æ® ±â°£: 2012³â 7¿ù 21ÀÏ ~ 8¿ù 29ÀÏ" ), -1, 0x6BD2FFFF );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE,
							_S( 2952, "¡Ø Ã¤Áý»óÀÚ´Â º¸»ó ÈÄ »ç¶óÁö³ª, ÀÌº¥Æ® ±â°£ µ¿¾È Àç ±¸ÀÔÀÌ °¡´ÉÇÏ¿© °è¼ÓÇØ¼­ ÀÌº¥Æ®¿¡ Âü¿©ÇÒ ¼ö ÀÖ½À´Ï´Ù." ), -1, 0x6BD2FFFF );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, TRUE, CTString(" ") );

						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, FALSE, _S( 2953, "°ïÃæ Ã¤Áý»óÀÚ ±¸ÀÔ(100 Nas)" ), 0 );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, FALSE,_S( 2954, "°ïÃæ Ã¤Áý»óÀÚ º¸»ó" ), 1 );
						pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_INSECT_EVENT, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case QUEST_HARVEST_MOON_DAY_EVENT2:
					{
						CTString strMessage;
						pUIManager->CloseMessageBoxL( MSGLCMD_HARVEST_MOON_DAY2 );

						strMessage = _S( 1860, "Ãß¼®¸ÂÀÌ ÀÌº¥Æ®" );	 
						pUIManager->CreateMessageBoxL( strMessage, UI_QUEST, MSGLCMD_HARVEST_MOON_DAY2 );				
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1,0xE18600FF );				

						strMessage = _S(3133, "Ãß¼®¿¡´Â ¿ª½Ã ¼ÛÆíÀÌ ºüÁú ¼ö ¾øÁÒ. ±× Áß¿¡¼­µµ Àú´Â Æ¯È÷ ¿À»ö¼ÛÆíÀ» Á¦ÀÏ ÁÁ¾ÆÇÑ´ä´Ï´Ù." );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );				
						strMessage = _S(3134, "Ãß¼®ÀÌº¥Æ® ±â°£ µ¿¾È ·Î·¹ÀÎ¿¡°Ô ½Ò°¡·ç¿Í ²Ü, ¼ÖÀÙÀ» ¸ð¾Æ¼­ °¡Á®°¡¸é ¼ÛÆíÀ» ¸¸µé¾îÁÖ´Âµ¥¿ä" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );				
						strMessage = _S(3135, "¼ÛÆí 10°³°¡ ÀÖÀ¸¸é ¸ÀÀÖ´Â ¿À»ö¼ÛÆíµµ ¸¸µé¾î ÁØ´ä´Ï´Ù." );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );
						strMessage = _S(3136, "È¤½Ã ¿À»ö¼ÛÆíÀÌ ÀÖÀ¸½Ã´Ù¸é ÀúÇÑÅ× ÁÖ½ÃÁö ¾ÊÀ¸½Ç·¡¿ä? ¾Æ·¡ÀÇ º¸»óÇ° Áß 1°³¸¦ µå¸®°Ú½À´Ï´Ù." );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );				
						strMessage = " ";
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );	

						strMessage = _S( 1866, "º¸»óÇ°" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1,0xE18600FF );	

						strMessage = _S( 1867, "10,000 Nas" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );	
						strMessage = _S( 1868, "50,000 Nas" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );	
						strMessage = _S( 1869, "200,000 Nas" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );	
						strMessage = _S( 1870, "500,000 Nas" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );	
						strMessage = _S( 1871, "°í±ÞÁ¦·Ã¼® 2°³" );
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, TRUE, strMessage, -1, 0xA3A1A3FF );	

						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, FALSE, _S(3137, "¿À»ö¼ÛÆíÀ» º¸»óÇ°À¸·Î ±³È¯ÇÑ´Ù."  ), MSGCND_MOON_DAY_EVENT_GIVE_ITEM );																														
						pUIManager->AddMessageBoxLString( MSGLCMD_HARVEST_MOON_DAY2, FALSE, _S( 1874, "Ãë¼ÒÇÑ´Ù."  ) );			
					}
					break;
				case EVENT_XMAS_2006:// 2006 X-Mas Event [12/12/2006 Theodoric]
					{
						pUIManager->CloseMessageBox(MSGLCMD_EVENT_XMAS_2006_CHANGE);
						CUIMsgBox_Info	MsgBoxInfo;
						CTString strTitle;
						CMobData* MD = CMobData::getData(336); // ´«»ç¶÷
						strTitle.PrintF("%s", MD->GetName());
						
						MsgBoxInfo.SetMsgBoxInfo( strTitle, UMBS_USER_12|UMBS_BUTTONEX , UI_NONE, MSGLCMD_EVENT_XMAS_2006_CHANGE );
						MsgBoxInfo.SetUserBtnName( _S(127, "±³È¯" ), _S( 139, "Ãë¼Ò" ) );
						MsgBoxInfo.SetBtnType( UBET_ITEM, CItemData::ITEM_POTION, CItemData::POTION_ETC );

						CTString strSysMessage = _S(3178, "¿ÀÈ£! ¸ÀÀÖ¾î º¸ÀÌ´Â ÄÉÀÌÅ©±º!!") ;
						MsgBoxInfo.AddString( strSysMessage );
						strSysMessage = _S(3179, "±× ÄÉÀÌÅ©¸¦ ³»°Ô ÁÖÁö ¾Ê°Ú³ª?");
						MsgBoxInfo.AddString( strSysMessage );
						strSysMessage = _S(3180, "ÄÉÀÌÅ© 3°³´ç Áø±ÍÇÑ ¾ÆÀÌÅÛÀ» ÇÏ³ª¾¿ ÁÖµµ·ÏÇÏÁö.");
						MsgBoxInfo.AddString( strSysMessage );				

						pUIManager->CreateMessageBox( MsgBoxInfo );
					}
					break;
				case EVENT_LOVE_LOVE:
					{
						pUIManager->CloseMessageBox(MSGLCMD_EVENT_LOVE_LOVE);
						
						CTString strMessage, strMessageA, strMessageB, strMessageC, strMessageD;

						if (IS_EVENT_ON(TEVENT_LUNARNEWYEAR_2008))
						{
							strMessage = _S(3996, "2008 ¼³³¯ º¹ÁÖ¸Ó´Ï ÀÌº¥Æ®");
							strMessageA = _S(4004, "2008³â »õÇØ º¹ ¸¹ÀÌ ¹ÞÀ¸½Ã°í ¼Ò¸Á ÀÌ·ç½Ã±â ¹Ù¶ø´Ï´Ù.");
							strMessageB = _S(4005, "°¡Áö°í °è½Å ¼Ò¸Á»óÀÚ¿¡ µé¾îÀÖ´Â º¹ÁÖ¸Ó´Ï°¡ °°ÀºÀº»ö±ò·Î ÁÙÀ» ÀÌ·ç°í ÀÖ´Ù¸é ¼Ò¸Á»óÀÚ¸¦ ±³È¯ ÇÒ ¼ö ÀÖ½À´Ï´Ù.");
							strMessageC = _S(4006, "¼Ò¸Á»óÀÚ ±³È¯");
							strMessageD = _S(4007, "º¹ÁÖ¸Ó´ÏÀÇ »ö»ó¿¡ µû¶ó ºù°í°¡ µÇ¾úÀ» ¶§ ÁÁÀº »óÇ°ÀÌ Áö±ÞµÇ´Â È®·üÀÌ ´Þ¶óÁý´Ï´Ù.");
						}
						else
						{
							strMessage = _S(3203, "·¯ºê·¯ºê ÀÌº¥Æ®");
							strMessageA = _S(3214, "ÃÊÄÚ»óÀÚ¿¡ µé¾î ÀÖ´Â ÃÊÄÚ·¿ÀÌ °°Àº Á¾·ù·Î ÁÙÀ» ÀÌ·ç°í ÀÖ´Ù¸é ÃÊÄÚ»óÀÚ¸¦ ±³È¯ÇÒ ¼ö ÀÖ½À´Ï´Ù.");
							strMessageB = _S(3215, "Ä«Ä«¿À 30, Ä«Ä«¿À 60, Ä«Ä«¿À 90 3Á¾·ùÀÇ ÃÊÄÚ·¿¿¡ µû¶ó ºù°í°¡ µÇ¾úÀ» ¶§ ÁÁÀº »óÇ°ÀÌ Áö±ÞµÇ´Â È®·üÀÌ ´Þ¶óÁý´Ï´Ù.");
							strMessageC = _S(3216, "ÃÊÄÚ»óÀÚ ±³È¯");
						}

						pUIManager->CreateMessageBoxL(strMessage, UI_QUEST, MSGLCMD_EVENT_LOVE_LOVE);				
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_LOVE_LOVE, TRUE, strMessage, -1,0xE18600FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_LOVE_LOVE, TRUE, strMessageA, -1, 0xA3A1A3FF);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_LOVE_LOVE, TRUE, strMessageB, -1, 0xA3A1A3FF);

						if (IS_EVENT_ON(TEVENT_LUNARNEWYEAR_2008))
						{
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_LOVE_LOVE, TRUE, strMessageD, -1, 0xA3A1A3FF);
						}

						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_LOVE_LOVE, FALSE, strMessageC, 0);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_LOVE_LOVE, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));
					}
					break;
				case NPC_HELP:
					{
						pUIManager->RearrangeOrder( UI_NPCHELP, TRUE );
					}
					break;
				case EVENT_MAY:
					{
						pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_EVENT_MAY);
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, TRUE, _S(3396, "¹Ý°©½À´Ï´Ù. 5¿ù °¡Á¤ÀÇ ´ÞÀ» ¸ÂÀÌÇÏ¿© ¶ó½ºÆ® Ä«¿À½º¿¡¼­ Áñ°Å¿î °¡Á¤ÀÇ ´Þ µÇ½Ã¶ó°í °ÔÀÓ³» 4°¡Áö ÀÌº¥Æ®¸¦ ÁØºñÇß½À´Ï´Ù.") );
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, TRUE, _S(3397, "Áñ°Ì°í Çàº¹ÇÑ 5¿ù °¡Á¤ÀÇ ´Þ º¸³»¼¼¿ä.") );
 						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, TRUE,  CTString(" "));
						if(IS_EVENT_ON(TEVENT_CHILDREN_2007))
 						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, FALSE, _S(3370, "Àú ·¹º§ Å»ÃâÀÛÀü" ), EVENT_MAY_CHILDREN );	
						if(IS_EVENT_ON(TEVENT_PARENTS_2007))
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, FALSE, _S(3362, "Ä«³×ÀÌ¼ÇÀ» ¸ð¾Æ¶ó~" ), EVENT_MAY_PARENTS );	
						if(IS_EVENT_ON(TEVENT_TEACHER_2007))
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, FALSE, _S(3379, "½º½ÂÀÇ ÀºÇý" ), EVENT_MAY_MASTER );	
						pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MAY, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));
					}
					break;
				case EVENT_MINIGAME:
					{
						if (IS_EVENT_ON(TEVENT_GOMDOLI))
						{
							// WSS_MINIGAME 070420 -------------------------------->>
							pUIManager->CloseMessageBoxL( MSGLCMD_EVENT_MINIGAME );
							pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_EVENT_MINIGAME);
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3428, "°õµ¹ÀÌ ÀÎÇü À¢µðÀÇ Á¶°¢ ¸ðÀ¸±â") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3429, "¸ó½ºÅÍ¸¦ »ç³ÉÇÏ¸é ÀÏÁ¤ È®·ü·Î [°õµ¹ÀÌ À¢µðÀÇ Á¶°¢]À» ¾òÀ» ¼ö ÀÖ½À´Ï´Ù.") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3430, "Á¶°¢³­ À¢µð´Â 1¹øºÎÅÍ 9¹ø±îÁö ¾ÆÈ© °³ÀÇ Á¶°¢À¸·Î µÇ¾îÀÖÀ¸¸ç Á¶°¢À» ¸ðµÎ ¸ð¾Æ Àú¿¡°Ô °¡Á®¿À½Ã¸é Àú¿Í °°ÀÌ °¡À§, ¹ÙÀ§, º¸ °ÔÀÓÀ» Áñ±â½Ç ¼ö ÀÖ¾î¿ä.") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3431, "°¡À§, ¹ÙÀ§, º¸ °ÔÀÓ¿¡¼­ Àú¿¡°Ô ½Â¸®ÇÏ¼ÌÀ» ¶§ ¸¶´Ù ´ÙÀ½ ´Ü°è¿¡ µµÀüÇÒÁö ±×³É ÇöÀçÀÇ »óÇ°À» ¹Þ°í ±×¸¸µÑÁö ¼±ÅÃÇÒ ¼ö ÀÖ´Âµ¥, ¿¬¼ÓÇØ¼­ ¸¹ÀÌ ÀÌ±æ¼ö·Ï ÁÁÀº »óÇ°À» ¹ÞÀ» ¼ö ÀÖ´ä´Ï´Ù.") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, CTString(" ") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3432, "º¸»óÇ° ¼Ò°³") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3433, "¡Ø°¡À§¹ÙÀ§º¸ °ÔÀÓ¿¡ Âü¿©ÇÏ½Å ÈÄ Ã¹ È¸¿¡ ÆÐ¹èÇÏ½Å °æ¿ì(0½Â) ´Ü ÇÑ¹ø¸¸ 'Ã¼Çè¿ë ±³º¹¼ÂÆ®'¸¦ µå¸®¸ç, Ã¹ 1½Â ½Ã¿¡´Â 'Ã¼Çè¿ë ¿±±â¹«±â' 1°³¸¦ µå¸³´Ï´Ù.") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3434, "°¡À§¹ÙÀ§º¸ 0½Â »óÇ°: ÁßÇü Äü HP È¸º¹ ¹°¾à 1°³") );
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3435, "°¡À§¹ÙÀ§º¸ 1½Â »óÇ°: ÁßÇü Äü MP È¸º¹ ¹°¾à 5°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3436, "°¡À§¹ÙÀ§º¸ 2½Â »óÇ°: ÁßÇü Äü HP È¸º¹ ¹°¾à 5°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3437, "°¡À§¹ÙÀ§º¸ 3½Â »óÇ°: ´ëÇü Äü µà¾ó È¸º¹ ¹°¾à 5°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3438, "°¡À§¹ÙÀ§º¸ 4½Â »óÇ°: °áÇÕÁÖ¹®¼­ 1°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3439, "°¡À§¹ÙÀ§º¸ 5½Â »óÇ°: °áÇÕÁÖ¹®¼­ 2°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3440, "°¡À§¹ÙÀ§º¸ 6½Â »óÇ°: °í±ÞÁ¦·Ã¼® 1°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3441, "°¡À§¹ÙÀ§º¸ 7½Â »óÇ°: °í±ÞÁ¦·Ã¼® 2°³"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  _S(3442, "°¡À§¹ÙÀ§º¸ 8½Â »óÇ°: °í±ÞÁ¦·Ã¼® 3°³"));
 							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  CTString(" "));		
 							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, FALSE, _S(3443, "°¡À§¹ÙÀ§º¸ °ÔÀÓÇÏ±â" ), EVENT_REWARD_1 );	
					//		Á¾·á ÁÖ¼®....
					//		ÇöÈ²¸¸ ¾È º¸ÀÌ°Ô Ã³¸®
					//		pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, FALSE, _S(3444, "°õµ¹ÀÌ ÀÎÇü À¢µð Ã£±â ÇöÈ²º¸±â" ), EVENT_REWARD_2 );	
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));
						}
						else if (IS_EVENT_ON(TEVENT_XMAS_2007))
						{
							pUIManager->CloseMessageBoxL(MSGLCMD_EVENT_MINIGAME);
							pUIManager->CreateMessageBoxL(_S(100, "ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_EVENT_MINIGAME);
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(5805, "»êÅ¸Å¬·Î½º ÀÎÇü Á¶°¢ ¸ðÀ¸±â!!"));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(5806, "¸ó½ºÅÍ¸¦ »ç³ÉÇÏ¸é ÀÏÁ¤ È®·ü·Î [»êÅ¸Å¬·Î½ºÀÇ Á¶°¢]À» ¾òÀ» ¼ö ÀÖ½À´Ï´Ù."));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(5807, "»êÅ¸Å¬·Î½ºÀÇ Á¶°¢Àº 1¹øºÎÅÍ 9¹ø±îÁö ¾ÆÈ© °³ÀÇ Á¶°¢À¸·Î µÇ¾îÀÖÀ¸¸ç ¸ðµÎ ¸ð¾Æ Àú¿¡°Ô °¡Á®¿À½Ã¸é Àú¿Í °°ÀÌ °¡À§, ¹ÙÀ§, º¸ °ÔÀÓÀ» Áñ±â½Ç ¼ö ÀÖ¾î¿ä."));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE, _S(3431, "°¡À§, ¹ÙÀ§, º¸ °ÔÀÓ¿¡¼­ Àú¿¡°Ô ½Â¸®ÇÏ¼ÌÀ» ¶§ ¸¶´Ù ´ÙÀ½ ´Ü°è¿¡ µµÀüÇÒÁö ±×³É ÇöÀçÀÇ »óÇ°À» ¹Þ°í ±×¸¸µÑÁö ¼±ÅÃÇÒ ¼ö ÀÖ´Âµ¥, ¿¬¼ÓÇØ¼­ ¸¹ÀÌ ÀÌ±æ¼ö·Ï ÁÁÀº »óÇ°À» ¹ÞÀ» ¼ö ÀÖ´ä´Ï´Ù."));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, TRUE,  CTString(" "));
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, FALSE, _S(3443, "°¡À§¹ÙÀ§º¸ °ÔÀÓÇÏ±â"), EVENT_REWARD_1);
							pUIManager->AddMessageBoxLString(MSGLCMD_EVENT_MINIGAME, FALSE, _S(1874, "Ãë¼ÒÇÑ´Ù."));
						}
					}
					break;
				case EVENT_FLOWERS_SUPPORT:
					{
						pUIManager->GetFlowerTree()->OpenFlowerTree();
					}
					break;
				case EVENT_SUPPORT_EXCHANGE:
					{
						if (!pUIManager->DoesMessageBoxExist(MSGCMD_FLOWERTREE_TICKET) )
							_pNetwork->SendFlowerTreeReq((UBYTE)MSG_EVENT_FLOWERTREE_2007_MY_POINT);
					}
					break;
				case SIEGEWARFARE_MASTERTOWER1:			// Å¸¿ö °¡µ¿ÇÏ±â
					{
						pUIManager->GetSiegeWarfareNew()->SendRequestTowerSet();
						//_pUISWDoc->SetUIState(SWS_APPLY_TOWER);
						//pUIManager->GetSiegeWarfareNew()->OpenCheckTower();
					}
					break;
				case SIEGEWARFARE_MASTERTOWER2:			// Å¸¿ö °­È­ÇÏ±â
					{
						pUIManager->CreateMessageBoxL(_S(100,"ÀÌº¥Æ®"),UI_QUEST,MSGLCMD_SIEGE_WARFARE_UPGRADE);
						pUIManager->AddMessageBoxLString(MSGLCMD_SIEGE_WARFARE_UPGRADE, TRUE, _S( 3679,"°¡µ¿½ÃÅ² ¼öÈ£Å¸¿ö¸¦ ¾÷±×·¹ÀÌµå ÇÒ ¼ö ÀÖ½À´Ï´Ù.") );
						pUIManager->AddMessageBoxLString(MSGLCMD_SIEGE_WARFARE_UPGRADE, TRUE, _S( 3680,"ºñ¿ëÀº Á¶±Ý µé°ÚÁö¸¸ ¼ºÀ» ¼öÈ£ÇÏ´Â ¼öÈ£Å¸¿ö¸¦ °­È­½ÃÅ°¸é ÇöÀçÀÇ Å¸¿ö ±â´É¿¡ ºñÇØ Å¹¿ùÇÑ È¿°ú¸¦ º¸½Ç ¼ö ÀÖÀ» °Ì´Ï´Ù.") );				
						pUIManager->AddMessageBoxLString(MSGLCMD_SIEGE_WARFARE_UPGRADE, TRUE, _S( 3681,"°­È­ÇÏ°íÀÚ ÇÏ´Â ¼öÈ£ Å¸¿ö¸¦ ¼±ÅÃÇØ ÁÖ¼¼¿ä.") );
 						pUIManager->AddMessageBoxLString(MSGLCMD_SIEGE_WARFARE_UPGRADE, FALSE, _S( 3682,"°ø°ÝÇü Å¸¿ö °­È­" ), EVENT_REWARD_1 );	
						pUIManager->AddMessageBoxLString(MSGLCMD_SIEGE_WARFARE_UPGRADE, FALSE, _S( 3683,"°¡µåÇü Å¸¿ö °­È­" ), EVENT_REWARD_2 );	
						pUIManager->AddMessageBoxLString(MSGLCMD_SIEGE_WARFARE_UPGRADE, FALSE, _S(1874,"Ãë¼ÒÇÑ´Ù."));
					}
					break;
				case SIEGEWARFARE_MASTERTOWER3:			// ¼º¹® °­È­ÇÏ±â
					{
						pUIManager->GetSiegeWarfareNew()->SetUpgradeType( SWUT_GATE );						
						pUIManager->GetSiegeWarfareNew()->SendTowerStateRequest(SWUT_GATE);	
					}
					break;
				case SIEGEWARFARE_MASTERTOWER4:			// ¸¶½ºÅÍ Å¸¿ö ¼ö¸®ÇÏ±â
					{
						pUIManager->GetSiegeWarfareNew()->SetRepairTowerIndex(m_iNpcIndex);
						pUIManager->GetSiegeWarfareNew()->SendTowerRepairStateRequest(m_iNpcIndex);
					}
					break;
				case EVENT_BJMONO_2007_REQ:
					{
						_pNetwork->SendBJMono2007Req(MSG_EVENT_BJMONO_2007_TICKET_REQ); // ÀÀ¸ð±Ç ¿äÃ»
					}
					break;
				case EVENT_BJMONO_2007_CHANGE_REQ:
					{
						pUIManager->CloseMessageBox(MSGCMD_BJMONO_2007_CHANGE_REQ);

						CMobData* MD = CMobData::getData(408); // ÀÌº¥Æ® ÁøÇà ¿ä¿ø
						CTString strMessage, strName;
						CUIMsgBox_Info MsgBoxInfo;
						strName = MD->GetName();

						MsgBoxInfo.SetMsgBoxInfo(strName, UMBS_OKCANCEL|UMBS_INPUTBOX, UI_QUEST, MSGCMD_BJMONO_2007_CHANGE_REQ);
						strMessage.PrintF(_s("¸î ÀåÀÇ ÀÀ¸ð±ÇÀ» ±³È¯ ÇÏ½Ã°Ú½À´Ï±î?"));
						MsgBoxInfo.AddString(strMessage);
						pUIManager->CreateMessageBox(MsgBoxInfo);
					}
					break;
				case EVENT_TG2007_SCREENSHOT:  // WSS_TG2007 2007/09/14 ½ºÅ©¸°¼¦ ÀÌº¥Æ®
					{
						_pNetwork->SendTG2007ScreenshotReq();
					}
					break;
				case EVENT_TG2007_1000DAYS_CAP:
					{
						// TODO :: ¶ó½ºÆ®Ä«¿À½º 1000ÀÏ ±â³ä¸ðÀÚ ¹Þ±â
						_pNetwork->SendLC1000DayTakeHatReq();
					}
					break;
				case EVENT_TG2007_1000DAYS_CAP_UPGRADE:
					{	// TODO :: ±â³ä¸ðÀÚ ¾÷µå·¹ÀÌµå
						CUIMsgBox_Info MsgBoxInfo;
						CTString strMessage;

						MsgBoxInfo.SetMsgBoxInfo(_S(3829, "±â³ä¸ðÀÚ ¾÷±×·¹ÀÌµå"), UMBS_YESNO | UMBS_BUTTONEX, UI_QUEST, MSGCMD_TG2007_1000DAYS_CAP_UPGRADE);
						MsgBoxInfo.SetBtnType(UBET_ITEM, CItemData::ITEM_SHIELD, CItemData::ITEM_SHIELD_HEAD);
						strMessage.PrintF(_S(3832, "¾÷±×·¹ÀÌµå ÇÒ ±â³ä¸ðÀÚ¸¦ ¿Ã·Á³ö ÁÖ½Ê½Ã¿ä"));
						MsgBoxInfo.AddString(strMessage);
						pUIManager->CreateMessageBox(MsgBoxInfo);
					}
					break;
				case EVENT_TG2007_1000DAYS_FIRECRACKER:
					{	//  TODO :: ÆøÁ× ¹Þ±â ÀÌº¥Æ®
						_pNetwork->SendTakeFireCracker();
					}
					break;
				case EVENT_HALLOWEEN2007_DEVILHAIR:
					{	// TODO :: ÇÒ·ÎÀ©ÀÌº¥Æ®2007, ¾Ç¸¶³¯°³ ¸Ó¸®¶ì Áö±Þ ¿äÃ»
						_pNetwork->SendHalloween2007Req(MSG_EVENT_TAKE_DEVILHEAIR);
					}
					break;
				case EVENT_HALLOWEEN2007_CANDYBASKET:
					{	// TODO :: ÇÒ·ÎÀ© ÀÌº¥Æ®2007, »çÅÁ¹Þ±â ¿äÃ»
						_pNetwork->SendHalloween2007Req(MSG_EVENT_CHANGE_CANDYBASKET);
					}
					break;
				case EVENT_HALLOWEEN2007_PUMKINHEAD:
					{	// TODO :: ÇÒ·ÎÀ© ÀÌº¥Æ®2007, È£¹Ú¸Ó¸® Å» ±³È¯¹Þ±â
						_pNetwork->SendHalloween2007Req(MSG_EVENT_CHANGE_PUMKINHEAD);
					}
					break;
				case EVENT_HALLOWEEN2007_WITCHHAT:
					{	// TODO :: ÇÒ·ÎÀ© ÀÌº¥Æ®2007, ¸¶³à¸ðÀÚ ±³È¯ ¿äÃ»
						_pNetwork->SendHalloween2007Req(MSG_EVENT_CHANGE_WITCHHAT);
					}
					break;
				case EVENT_HALLOWEEN2007_PUMKIN:
					{	// TODO :: ÇÒ·ÎÀ© ÀÌº¥Æ®2007, È£¹Ú ±³È¯ ¿äÃ»
						_pNetwork->SendHalloween2007Req(MSG_EVENT_CHANGE_PUMKIN);
					}
					break;
				case EVENT_XMAS2007_DECO:	// Å©¸®½º¸¶½º Àå½Ä 
					{
						CUIMsgBox_Info MsgBoxInfo;
						CTString strMessage;

						MsgBoxInfo.SetMsgBoxInfo(_S(169, "ÀÌº¥Æ®"), UMBS_YESNO, UI_QUEST, MSGCMD_EVENT_XMAS_2007_DECO);
						MsgBoxInfo.AddString(_S(3953, "Å©¸®½º¸¶½º Æ®¸®¸¦ Àå½ÄÇÏ¸é º¸À¯ÇÑ Å©¸®½º¸¶½º Æ®¸® Àå½ÄÀº ¸ðµÎ »ç¶óÁý´Ï´Ù"));
						pUIManager->CreateMessageBox(MsgBoxInfo);
					}
					break;
				case EVENT_XMAS2007_BLESSEDNESS:
					{	// Å©¸®½º¸¶½º Ãàº¹ ¿äÃ»
						_pNetwork->SendXMAS2007DecoReq(MSG_EVENT_XMASTREE_GET_BLESS);
					}
					break;
				case CASH_PERSONSHOP_CLOSE:	//071129 ttos : ÆÇ¸Å ´ëÇàÇùÈ¸ È¸Àå
					{	// TODO :: ÆÇ¸Å ´ëÇà Á¾·á
						_pNetwork->SendCashPersonShop(MSG_ALTERNATEMERCHANT_END);
					}
					break;
				case CASH_PERSONSHOP_ITEM:
					{	// TODO :: º¸°üµÈ ¾ÆÀÌÅÛ È¸¼ö
						_pNetwork->SendCashPersonShop(MSG_ALTERNATEMERCHANT_PRODUCT_RECOVERY);
					}
					break;
				case CASH_PERSONSHOP_NAS:
					{	// TODO :: º¸°üµÈ ³ª½º È¸¼ö
						_pNetwork->SendCashPersonShop( MSG_ALTERNATEMERCHANT_PRODUCT_NAS);
					}
					break;
				case EVENT_SAKURA_2008: //2008³â º¢²É ³îÀÌ ÀÌº¥Æ® º¸»ó ±³È¯ ¿äÃ»
					{
						if (pUIManager->DoesMessageBoxExist(MSGCMD_EVENT_SAKURA_2008))
							pUIManager->CloseMessageBox(MSGCMD_EVENT_SAKURA_2008);

						CUIMsgBox_Info MsgBoxInfo;
						MsgBoxInfo.SetMsgBoxInfo(_S(169, "ÀÌº¥Æ®"), UMBS_YESNO, UI_QUEST, MSGCMD_EVENT_SAKURA_2008);
						MsgBoxInfo.AddString(_S(4113, "°¡Áö°í ÀÖ´Â Åðºñ´Â ¸ðµÎ »ç¶óÁý´Ï´Ù. Åðºñ¸¦ °Ç³×ÁÖ°Ú½À´Ï±î?"));
						pUIManager->CreateMessageBox(MsgBoxInfo);
					}
					break;
				case EVENT_CHAOSBALL:	// [080422: Su-won] EVENT_CHAOSBALL
					{
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_CHAOSBALL_EVENT ) ) 
							break;

						pUIManager->CreateMessageBoxL( _S(100, "ÀÌº¥Æ®"), UI_QUEST, MSGLCMD_CHAOSBALL_EVENT );
						pUIManager->AddMessageBoxLString( MSGLCMD_CHAOSBALL_EVENT, TRUE, 
							_S(4128, "Ä«¿À½º º¼Àº °í´ëÀÇ ¸¶¹ý¹®¾çÀÌ »õ°ÜÁø ½ÅºñÇÑ °øÀÔ´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_CHAOSBALL_EVENT, TRUE,	
							_S(4129, "¾ÆÀÌ¸®½º ´ë·ú¿¡¼­´Â ÈçÈ÷ º¼ ¼ö ÀÖ´Â ¹°°ÇÀº ¾Æ´ÏÁö¸¸, ÀúÀÇ °íÇâ ·ç³ª½Ã½º¿¡¼­´Â Áø±ÍÇÑ º¸¹°ÀÌ³ª ±â¿îÀ» ´ã¾Æ³õ´Â »óÀÚ·Î ÀÌ¿ëÇÏ°ï ÇÑ´ä´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_CHAOSBALL_EVENT, TRUE,
							_S(4130, "ÁÖÀ§¸¦ ÀÏ··ÀÌ´Â ±â¿î°ú ´Ü´ÜÇÑ Ç¥¸é¶§¹®¿¡ Á¤½ÄÀ¸·Î ÇØÁ¦¸¦ ÇÏ±â Àü±îÁö´Â ¾È¿¡ ¹¹°¡ µé¾îÀÖ´ÂÁö, ¾î¶² ÈûÀÌ µé¾îÀÖ´ÂÁö °áÄÚ ¾Ë ¼ö ¾øÀ¸´Ï Áø±ÍÇÑ º¸¹°À» ¼û°ÜµÎ±â¿¡´Â ¾È¼º¸ÂÃãÀÌÁö¿ä." ));
						pUIManager->AddMessageBoxLString( MSGLCMD_CHAOSBALL_EVENT, TRUE,
							_S(4131, "ÃÖ±Ù¿¡ ¾ÆÀÌ¸®½º »óÁ¡¿¡¼­ ÆÇ¸ÅÇÏ´Â ¸î¸î ¹°°Ç¿¡ µé¾îÀÖ´Ù°í ÇÏ´Âµ¥, Ä«¿À½º º¼À» °¡Áö°í °è½Å´Ù¸é Àú¿¡°Ô °¡Á®´Ù ÁÖ¼¼¿ä. ºÀÀÎÀ» ÇØÁ¦ÇØ¼­ ¾È¿¡ µé¾îÀÖ´Â º¸¹°À» ²¨³» µå¸®°Ú½À´Ï´Ù." ));

						pUIManager->AddMessageBoxLString( MSGLCMD_CHAOSBALL_EVENT, FALSE, _S(4132, "Ä«¿À½º º¼ ºÀÀÎÇØÁ¦ÇÏ±â" ), 1 );
						pUIManager->AddMessageBoxLString( MSGLCMD_CHAOSBALL_EVENT, FALSE, _S(1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_REQUITAL_1:	// [090811: selo] 2009³â 7¿ù º¸»ó
					{
						_pNetwork->SendEventRequital(0);
					}
					break;
				case EVENT_PHOENIX_REQ:	//ÇÇ´Ð½º ÀÌº¥Æ®
					{
						_pNetwork->SendPhoenixCharacterCondition();
					}
					break;
				case EVENT_HANAPOS_SK_EVENT:	//[ttos_2009_3_18]: ÇÏ³ªÆ÷½º ¹× SKºê·Îµå¹êµå °¡ÀÔÀÚ ÀÌº¥Æ®
					{
						BOOL bOK = TRUE;

						if( bOK )
							_pNetwork->SendHanaposEvent(m_iNpcVirIdx);
					}
					break;
				case MIDLEVEL_SUPPORT_REQ: // ÁßÀú·¹º§ Áö¿ø»ç ¸¶¹ý ¿äÃ»
					{
						_pNetwork->SendSupportSkill((UBYTE)MSG_SKILL_MIDLEVEL_SUPPORT);
					}
					break;
				case EVENT_ADD_UP_NEW_AFRON:	// ¼­¹ö ÅëÇÕ ÀÌº¥Æ®(ºí¸®½º + ¾ÆÇÁ·Ð)
					{
						_pNetwork->SendEventMsg(static_cast<UBYTE>(MSG_EVENT_NEW_AFRON_2009));
					}
					break;				
				case QUEST_RESTORE_ITEM:		// [100208: selo] Äù½ºÆ® ¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â
					{
						pUIManager->CloseMessageBox(MSGCMD_QUEST_RESTORE_ITEM);

						CUIMsgBox_Info MsgBoxInfo;
						MsgBoxInfo.SetMsgBoxInfo(_S( 99, "Äù½ºÆ®" ), UMBS_YESNO, UI_QUEST, MSGCMD_QUEST_RESTORE_ITEM );						
						if( m_restoreQuestItemIndex != -1 )
						{
							CTString strMessage;
							strMessage.PrintF(_S( 5359, "[%s] ¾ÆÀÌÅÛÀ» ¹ÞÀ¸½Ã°Ú½À´Ï±î?" ), _pNetwork->GetItemName( m_restoreQuestItemIndex ) );
							MsgBoxInfo.AddString( strMessage );
						}
						else
						{
							MsgBoxInfo.AddString(_S(4819, "[±×¸²ÀÚ ¹®ÀÇ ¿­¼è] ¾ÆÀÌÅÛÀ» ¹ÞÀ¸½Ã°Ú½À´Ï±î?"));
						}
						pUIManager->CreateMessageBox(MsgBoxInfo);
					}
					break;

					// ($E_WC2010) [100514: selo] 2010 ³²¾Æ°ø ¿ùµåÄÅ ÀÌº¥Æ®2 ¿ì½Â ±¹°¡ ¿¹»óÇÏ±â
				case EVENT_WOLRDCUP_2010_EVENT2:
				case EVENT_WOLRDCUP_2010_EVENT2_STATUS:
				case EVENT_WOLRDCUP_2010_EVENT2_GIFT:
					{
						if( pUIManager->DoesMessageBoxLExist(MSGLCMD_EVENT_WORLDCUP_EVENT2))
							pUIManager->CloseMessageBoxL(MSGLCMD_EVENT_WORLDCUP_EVENT2);
						
						pUIManager->CreateMessageBoxL( _S(4900, "¿ì½Â±¹ ¿¹»óÇÏ±â ÀÌº¥Æ® ¾È³»"), UI_QUEST, MSGLCMD_EVENT_WORLDCUP_EVENT2 );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, TRUE, 
							_S(4902, "¹Ý°¡¿ö¿ä. ¿ì½Â±¹ ¿¹»óÇÏ±â ÀÌº¥Æ®¿¡ Âü¿©ÇÏ½Ã·Á¸é, °¢ ³ª¶óÀÇ ±¹±â ¾ÆÀÌÅÛÀÌ ÇÊ¿äÇØ¿ä" ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, TRUE, 
							_S(4903, "±¹±â ¾ÆÀÌÅÛÀº '¿ùµå ÃàÁ¦ »óÀÚ'¿¡¼­ È¹µæÇÒ ¼ö ÀÖ´ä´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, TRUE, 
							_S(4904, "ÀÀ¸ð ¹æ¹ýÀº ¿ì½ÂÀÌ ¿¹»óµÇ´Â ±¹°¡ÀÇ ±¹±â¸¦ °¡Áö°í ¿À½Ã¸é ÀÀ¸ðÇÒ ¼ö ÀÖ¾î¿ä. ÀÀ¸ð¿Í µ¿½Ã¿¡ ±¹±â ¾ÆÀÌÅÛÀº »ç¶óÁö°í, ´Ù½Ã µÇµ¹·Á ¹ÞÀ¸½Ç ¼ö ¾ø½À´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, TRUE, 
							_S(4905, "´Ü, ÀÀ¸ð ±â°£ µ¿¾È¿¡´Â ¾ðÁ¦µçÁö º¯°æ °¡´ÉÇÕ´Ï´Ù. ´Ù½Ã µî·ÏÇÏ·Á¸é ±¹±â ¾ÆÀÌÅÛÀÌ Ãß°¡·Î ÇÊ¿äÇÏÁö¿ä." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, TRUE, 
							_S(4906, "ÀÌº¥Æ® ´çÃ· º¸»óÀº ¿ùµåÄÅÀÌ Á¾·áµÈ ÈÄ¿¡ Áö±ÞµË´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, TRUE, 
							_S(4907, "ÀÚ... ¾î¶² ÀÀ¸ð ¹æ¹ýÀ» ¼±ÅÃÇÏ½Ã°Ú¾î¿ä?" ) );

						if( nResult == EVENT_WOLRDCUP_2010_EVENT2 )
						{						
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, FALSE, _S(4908, "¿ì½Â ±¹°¡ ÀÀ¸ð" ), EVENT_WORLDCUP_2010_EVENT2_SEL1);							
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, FALSE, _S(4911, "³» ÀÀ¸ð ÇöÈ²" ), EVENT_WORLDCUP_2010_EVENT2_SEL2);
						}
						else if( nResult == EVENT_WOLRDCUP_2010_EVENT2_STATUS )
						{
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, FALSE, _S(4911, "³» ÀÀ¸ð ÇöÈ²" ), EVENT_WORLDCUP_2010_EVENT2_SEL2);
						}
						else if( nResult == EVENT_WOLRDCUP_2010_EVENT2_GIFT )
						{	
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, FALSE, _S(4911, "³» ÀÀ¸ð ÇöÈ²" ), EVENT_WORLDCUP_2010_EVENT2_SEL2);
							pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT2, FALSE, _S(4912, "´çÃ· º¸»ó ¹Þ±â" ), EVENT_WORLDCUP_2010_EVENT2_SEL3);
						}
					}
					break;
					// ($E_WC2010) [100514: selo] 2010 ³²¾Æ°ø ¿ùµåÄÅ ÀÌº¥Æ®3 ¸ÅÀÏ ¸ÅÀÏ ÀÀ¿øÇÏ±â
				case EVENT_WOLRDCUP_2010_EVENT3:
					{
						if( pUIManager->DoesMessageBoxLExist(MSGLCMD_EVENT_WORLDCUP_EVENT3))
							pUIManager->CloseMessageBoxL(MSGLCMD_EVENT_WORLDCUP_EVENT3);
						
						pUIManager->CreateMessageBoxL( _S(4901, "ÀÀ¿ø ÀÌº¥Æ® ¾È³»"), UI_QUEST, MSGLCMD_EVENT_WORLDCUP_EVENT3 );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, TRUE, 
							_S(4932, "ÀÀ¿ø Ä«µå¸¦ ¹ÞÀ¸·¯ ¿À¼Ì±º¿ä. ÀÀ¿øÄ«µå ¹Þ±â ¹öÆ°À» ´©¸£½Ã¸é ÁöÃ¼ ¾øÀÌ µå¸³´Ï´Ù." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, TRUE, 
							_S(4933, "¾Æ¾Æ... ¹«¾ùÀ» ¹Ù¶ó°í µå¸®´Â °Ç ¾Æ´Ï´Ï±î °ÆÁ¤ ¸¶¼¼¿ä. ´Ü, ÇÏ·ç¿¡ 1Àå¸¸ µå¸± ¼ö ÀÖ¾î¿ä." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, TRUE, 
							_S(4934, "¸ÅÀÏ ÇÏ·ç¿¡ ÇÑ ¹ø ¸ðÀ¸´Â ÀÀ¿øÄ«µå¸¦ ¸¹ÀÌ ¸ðÀ» ¼ö·Ï ÁÁÀº ¹°°ÇÀ» ¹ÞÀ¸½Ç ¼ö ÀÖÀ» °Å¿¹¿ä." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, TRUE, 
							_S(4935, "¹°·Ð, ¿øÇÏ´Â ¹°°ÇÀÌ ÀÖ´Ù¸é Áß°£¿¡ ¹Ù²Ù½Ç ¼öµµ ÀÖ¾î¿ä." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, TRUE, 
							_S(4936, "°ÅµÎÀý¹ÌÇÏ°í, ÀÏ´Ü ÀÀ¿øÄ«µå ¸ÕÀú ¹Þ°í ½ÃÀÛÇÒ±î¿ä?" ) );	
						
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, FALSE, _S(4937, "ÀÀ¿øÄ«µå ¹Þ±â" ), EVENT_WORLDCUP_2010_EVENT3_SEL1);
						pUIManager->AddMessageBoxLString( MSGLCMD_EVENT_WORLDCUP_EVENT3, FALSE, _S(1721, "º¸»ó ¹Þ±â"), EVENT_WORLDCUP_2010_EVENT3_SEL2);
					}
					break;
				case ATTENDANT_DATE_REQ:
					{
						// ¼­¹ö¿¡ ´©ÀûÃâ¼®ÀÏ¼ö ¿äÃ»
						_pNetwork->SendAttendanceReq( 0 );
					}
					break;
				case DUNGEON_DIFFICULTY_NORMAL:
					{
						_pNetwork->RaidInzoneJoinReq(36, 0);
					}
					break;
				case DUNGEON_DIFFICULTY_HARD:
					{
						_pNetwork->RaidInzoneJoinReq(36, 1);
					}
					break;
				case EVENT_TEMP: // ´Ü¹ß¼º ÀÌº¥Æ® (100907 ÇöÀç ¾ÆÄ­»ç¿ø)
					{
						if (!pUIManager->DoesMessageBoxExist(MSGCMD_SOULOFSCALP_CONFIRM))
						{
							CUIMsgBox_Info MsgBox;
							MsgBox.SetMsgBoxInfo(_S(127, "±³È¯"), UMBS_OKCANCEL, UI_QUEST, MSGCMD_SOULOFSCALP_CONFIRM);
							MsgBox.AddString(_s("¿µÈ¥ÀÇ Â¡Ç¥¸¦ ±³È¯ ÇÏ½Ã°Ú½À´Ï±î? (º¸À¯ ¼ö·®¿¡ µû¶ó ÀÚµ¿À¸·Î º¸»óÀÌ Áö±ÞµË´Ï´Ù.)"));
							pUIManager->CreateMessageBox(MsgBox);
						}
					}
					break;
				case REGISTER_MERCHANT:	// [2010/08/25 : Sora] ADD_SUBJOB
					{
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_REGISTER_MERCHANT ) ) 
							break;

						CTString strSp, strNas, strTemp;
						strSp = pUIManager->IntegerToCommaString(DEF_REGISTER_MERCHANT_NEED_SP);
						strNas = pUIManager->IntegerToCommaString(DEF_REGISTER_MERCHANT_NEED_NAS);

						pUIManager->CreateMessageBoxL( _S(5057, "µî·Ï Á¤º¸"), UI_QUEST, MSGLCMD_REGISTER_MERCHANT );
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE, pUIManager->GetSubJobName(SUBJOB_MERCHANT), -1, 0xE18600FF);
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE,	_S(5058, "¼¼»óÀÇ ¸ðµç µ·À» ¾ò°íÀÚ ÇÏ´Â ÀÚ¿©, »óÀÎÀÌ µÇ¾î ´ë·ú ÃÖ°íÀÇ ºÎÀÚ°¡ µÇ¾î º¸Áö ¾Ê°Ú³ª?") );
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE, _S(5059, "(°æºñ°¡ »ï¾öÇØ¼­ ºÒ¹ýÀå»ç´Â ¾ÈµÈ´Ù³×!)" ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE, _S(5060, "ÇÊ¿ä ·¹º§ : 50Lv~55Lv" ), -1, 0xE18600FF);
						strTemp.PrintF(_S(5061, "ÇÊ¿ä SP : %s" ), strSp);
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE, strTemp, -1, 0xE18600FF);
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE, _S(5062, "¸í¼ºÄ¡ : 5" ), -1, 0xE18600FF);
						strTemp.PrintF(_S(5063, "³ª½º : %s" ), strNas);
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, TRUE, strTemp, -1, 0xE18600FF);
						strTemp.PrintF( _S( 5056, "»óÀÎÀ¸·Î µî·Ï"), pUIManager->GetSubJobName(SUBJOB_MERCHANT) );
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, FALSE, strTemp, 1 );
						pUIManager->AddMessageBoxLString( MSGLCMD_REGISTER_MERCHANT, FALSE, _S(1220, "Ãë¼ÒÇÑ´Ù." ) );
					}
					break;
				case EVENT_PROMOTION2:
					{
						CUIMsgBox_Info MsgBoxInfo;

						MsgBoxInfo.m_nInputMaxChar = 24;
						MsgBoxInfo.m_nInputWidth = 130;
						MsgBoxInfo.m_nInputPosX = 44;
						MsgBoxInfo.m_nInputPosY = 48;

						MsgBoxInfo.SetMsgBoxInfo(_S(3150, "ÀÎÁõKey ÀÔ·Â"),UMBS_OKCANCEL|UMBS_INPUTBOX,UI_QUEST,MSGCMD_PROMOTION2_REQ);
						pUIManager->CreateMessageBox(MsgBoxInfo);
					}
					break;
					
				case EVENT_ATTENDANCE_2011:	// [2011/01/18 : Sora] Ãâ¼® ÀÌº¥Æ®
					{
						_pNetwork->SendAttendanceRewardReq();
					}
					break;
				case EVENT_COMEBACK:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®"), UMBS_OKCANCEL, UI_QUEST, MSGCMD_COMEBACK_CONFIRM );
						MsgBox.AddString( _S( 586, "ÀÌº¥Æ® º¸»óÀ» ¿äÃ»ÇÏ½Ã°Ú½À´Ï±î?") );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case EVENT_BIRTHDAY_GIFT:
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®"), UMBS_OKCANCEL, UI_QUEST, MSGCMD_BIRTHDAY_CONFIRM );
						MsgBox.AddString( _S( 586, "ÀÌº¥Æ® º¸»óÀ» ¿äÃ»ÇÏ½Ã°Ú½À´Ï±î?") );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case EVENT_BIRTHDAY_INFO:
					{
						_pNetwork->SendBirthdayMessage( EVENT_BIRTHDAY_INFO );
					}
					break;
				case EVENT_TREASURE_MAP:
					{
						CNetworkMessage nmEvent( MSG_EXTEND );
						nmEvent << (ULONG)MSG_EX_TREASURE_MAP_SYSTEM_KEY_EXCHANGE;

						_pNetwork->SendToServerNew( nmEvent );
						
					}break;

				case EVENT_LOI_KRATHONG:
					{
						_pNetwork->SendEventKrathongReq();
					}
					break;

				case EVENT_KB_EXCHAGE_HEART:	// [2011/11/14 : Sora] ÅÂ±¹ ±¹¿Õ Åº»ýÀÏ ÀÌº¥Æ® ÇÏÆ®·Î »óÀÚ ±³È¯
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®"), UMBS_OKCANCEL, UI_QUEST, MSGCMD_KB_EXCHAGE_HEART );
						MsgBox.AddString( _S( 5604, "±³È¯À» ¹Þ°Ô µÇ¸é º¸À¯ÇÑ ÇÏÆ®°¡ ¸ðµÎ »ç¶óÁö°Ô µË´Ï´Ù. ±³È¯ ¹ÞÀ¸½Ã°Ú½À´Ï±î?") );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case EVENT_KB_EXCHAGE_FLAG:	// [2011/11/14 : Sora] ÅÂ±¹ ±¹¿Õ Åº»ýÀÏ ÀÌº¥Æ® ÇÃ·¡±×·Î ÀÇ»ó ±³È¯
					{
						CUIMsgBox_Info MsgBox;
						MsgBox.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®"), UMBS_OKCANCEL, UI_QUEST, MSGCMD_KB_EXCHAGE_FLAG );
						MsgBox.AddString( _S( 5605, "ÀüÅëÀÇ»óÀ¸·Î ±³È¯À» ¹Þ°Ô µÇ¸é Father Flag ¾ÆÀÌÅÛÀº »ç¶óÁö°Ô µË´Ï´Ù. ÁøÇà ÇÏ½Ã°Ú½À´Ï±î?") );
						pUIManager->CreateMessageBox( MsgBox );
					}
					break;
				case EVENT_SONGKRAN:
					{
						UIMGR()->GetTrade()->OpenUI(m_iNpcIndex);
					}
					break;
				case ARENA_HEAL_REQ: // ÁßÀú·¹º§ Áö¿ø»ç ¸¶¹ý ¿äÃ»
				{
					_pNetwork->SendSupportSkill((UBYTE)MSG_SKILL_ARENA_HEAL);
				}
				break;
			#ifdef BATTLE_PASS_SYSTEM
				case BATTLE_PASS:
				{
					_pNetwork->SendBattlePassInfoReq(m_iNpcVirIdx);
				}
				break;
			#endif
				}
			}
		}
		break;
	case MSGLCMD_GATE_OF_DIMENSION:
		{
			if( nResult == GOD_ENTER )				// Â÷¿øÀÇ ¹® ÀÔÀå
			{
				// FIXME : Hardcoding ÀÎµ¦½º
				const int iQuestIndex = 105;
				if( CQuestSystem::Instance().CanIDoQuest( iQuestIndex ) )
				{
					if( CQuestSystem::Instance().GetDynamicDataByQuestIndex( iQuestIndex ) == NULL )
					{										
						pUIManager->GetQuestAccept()->open( iQuestIndex );
					}
					else
					{
						CTString strSysMessage;
						strSysMessage.PrintF( _S( 1687, "ÀÌ¹Ì ¼öÇàÁßÀÎ Äù½ºÆ®ÀÔ´Ï´Ù."  ) );		
						_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
					}
				}
				else
				{
					CTString strSysMessage;
					strSysMessage.PrintF( _S( 1688, "Á¶°ÇÀÌ ¸ÂÁö ¾Ê½À´Ï´Ù."  ) );		
					_pNetwork->ClientSystemMessage( strSysMessage, SYSMSG_ERROR );
				}
			}
			else if( nResult == GOD_RANKING )		// Â÷¿øÀÇ ¹® ¼øÀ§È®ÀÎ
			{
				_pNetwork->Ranking_RequestList( _pNetwork->MyCharacterInfo.job );
			}
			else if( nResult == GOD_PRIZE )			// º¸»ó.
			{
				_pNetwork->Ranking_RequestPrizeList();
			}
		}
		break;

	case MSGLCMD_CHANGEWEAPON_EVENT_REQ:
		{
			if( nResult == EVENT_CHANGEWEAPON )
			{
				pUIManager->CloseMessageBox( MSGCMD_WEAPONCHANGE_EVENT );
				CTString strMessage;
				// Create message box of remission
				CUIMsgBox_Info	MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo( _S( 1204, "¹«±â ±³Ã¼ ÀÌº¥Æ®" ), UMBS_OKCANCEL,	
					UI_QUEST, MSGCMD_WEAPONCHANGE_EVENT );
				strMessage.PrintF( _S( 1213, "¹«±â¸¦ ±³Ã¼ÇÏ½Ã°Ú½À´Ï±î?" ) );				
				MsgBoxInfo.AddString( strMessage );
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
			else
			{
			}
		}
		break;
		
	case MSGLCMD_TREASUREBOX_EVENT:
		{
			if( nResult == 1 )
			{
				_pNetwork->SendEventOpenTreasure();
			}
		}
		break;

	case MSGLCMD_EVENT_2PAN4PAN_ONE:
		{
			if(nResult == EXCH_FIVE){
				CUIMsgBox_Info	MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®" ), UMBS_YESNO, UI_QUEST, MSGCMD_ASK_ONE_FIVE );
				MsgBoxInfo.AddString( _S(2219, "2pan4pan ¸Â°íÄ«µå¸¦ ¸Â°í¸Ó´Ï·Î ±³È¯ÇÏ½Ã°Ú½À´Ï±î?"));
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
			else if(nResult == EXCH_FOUR){
				CUIMsgBox_Info	MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®" ), UMBS_YESNO, UI_QUEST, MSGCMD_ASK_ONE_FOUR );			
				MsgBoxInfo.AddString( _S(2220, "2pan4pan Æ÷Ä¿Ä«µå¸¦ Æ÷Ä¿¸Ó´Ï·Î ±³È¯ÇÏ½Ã°Ú½À´Ï±î?"));
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}

		}
		break;
	case MSGLCMD_EVENT_2PAN4PAN_TWO:
		{
			if(nResult == OPEN_TREA ){
				_pNetwork->SendEvent24(0,MSG_EVENT_2PAN4PAN_BOX_REQ);

			}			
		}
		break;
		
	case MSGLCMD_EVENT_NEWYEAR1:
		{
			if(nResult == EVENT_NEWYEAR1_REWARD){
				CUIMsgBox_Info MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo(_S(169,"ÀÌº¥Æ®"),UMBS_YESNO,UI_QUEST,MSGCMD_ASK_NEWYEAR1);
				MsgBoxInfo.AddString(_S(2296,"º¸»óÇ°À» Áö±Þ ¹ÞÀ¸½Ã°Ú½À´Ï±î?"));
				pUIManager->CreateMessageBox(MsgBoxInfo);
			}
		}
		break;
	case MSGLCMD_EVENT_NEWYEAR2:
		{
			if(nResult == EVENT_NEWYEAR2_TIMECHECK){
				_pNetwork->SendEventNewyear(EVENT_NEWYEAR2_TIMECHECK);				
				
			}
			else if(nResult == EVENT_NEWYEAR2_REWARD){
				CUIMsgBox_Info MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo(_S(169,"ÀÌº¥Æ®"),UMBS_YESNO,UI_QUEST,MSGCMD_ASK_NEWYEAR2);
				MsgBoxInfo.AddString(_S(2296,"º¸»óÇ°À» Áö±Þ ¹ÞÀ¸½Ã°Ú½À´Ï±î?"));
				pUIManager->CreateMessageBox(MsgBoxInfo);

			}
		}
		break;

	case MSGLCMD_EVENT_FIND_FRIEND :
		{
			if( nResult == EVENT_FF_REG){
				CUIMsgBox_Info MsgBoxInfo;
				MsgBoxInfo.SetMsgBoxInfo(_S( 2433, "Ä£±¸ Ã£±â ÀÌº¥Æ®"),UMBS_OKCANCEL|UMBS_INPUTBOX,UI_QUEST,MSGCMD_INPUT_FRIEND);
				MsgBoxInfo.AddString(_S( 2487, "Ã£±â¸¦ ¿øÇÏ´Â Ä£±¸ÀÇ Ä³¸¯¸íÀ» ÀÔ·Â ÇÏ¼¼¿ä."));
				pUIManager->CreateMessageBox(MsgBoxInfo);

			} else if (nResult == EVENT_FF_TIMECHECK){
				// TODO : get TIME 
				_pNetwork->SendFindFriend(MSG_EVENT_SEARCHFRIEND_TIME_CHECK);
				
			} else if (nResult == EVENT_FF_REWARD){
				// TODO : send message to make friend list
				_pNetwork->SendFindFriend(MSG_EVENT_SEARCHFRIEND_LIST_GOODS);
			}

		}
		break;
	case MSGLCMD_CLOTHES_EXCHANGE:	// ÀÏº» ÀüÅë ÀÇ»ó ±³È¯ ÀÌº¥Æ® eons
		{
			_pNetwork->SendClothesExchange( nResult );
		}
		break;

	case MSGCMD_WORLDCUP_EVENT1 :
		{
			switch(nResult)
			{
				case WORLDCUP_EVENT1_EXCHANGE:
				{
					if( pUIManager->DoesMessageBoxLExist( MSGCMD_WORLDCUP_EVENT1_EXCHANGE ) ) break;
					pUIManager->CreateMessageBoxL(  _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGCMD_WORLDCUP_EVENT1_EXCHANGE );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, TRUE,
						_S( 2813, "Âü°¡±¹ º° ±¹±â ±³È¯¿¡ ÇÊ¿äÇÑ ¿ì½ÂÄÅ °³¼ö" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, TRUE,
						_S( 2814, "¡Ø 100°³ - ºê¶óÁú,µ¶ÀÏ,ÀÌÅ»¸®¾Æ,¿µ±¹,¾Æ¸£ÇîÆ¼³ª" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, TRUE,
						_S( 2815, "¡Ø 75°³ - ÇÁ¶û½º, ³×´ú¶õµå, ½ºÆäÀÎ, Æ÷¸£Åõ°¥, Ã¼ÄÚ, ½º¿þµ§, ¸ß½ÃÄÚ, ¿ìÅ©¶óÀÌ³ª, Å©·Î¾ÆÆ¼¾Æ" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, TRUE,
						_S( 2816, "¡Ø 50°³ - ¹Ì±¹, ½ºÀ§½º, ÄÚÆ®µðºÎ¾Æ¸£, ¼¼¸£ºñ¾Æ-¸óÅ×³×±×·Î, Æú¶õµå, ÆÄ¶ó°úÀÌ,ÇÑ±¹, È£ÁÖ, ÀÏº»" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, TRUE,
						_S( 2817, "¡Ø 25°³ - °¡³ª, Æ¢´ÏÁö, ¿¡Äâµµ¸£, Åä°í, ¾Ó°ñ¶ó, ÀÌ¶õ, »ç¿ìµð¾Æ¶óºñ¾Æ, ÄÚ½ºÅ¸¸®Ä«, Æ®¸®´Ï´Ùµå Åä¹Ù°í" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, FALSE, _S( 2818, "¿ì½ÂÄÅ 100°³ ±³È¯" ), WORLDCUP_EVENT1_EXCHANGE100 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, FALSE, _S( 2819, "¿ì½ÂÄÅ 75°³ ±³È¯" ), WORLDCUP_EVENT1_EXCHANGE75 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, FALSE, _S( 2820, "¿ì½ÂÄÅ 50°³ ±³È¯" ), WORLDCUP_EVENT1_EXCHANGE50 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, FALSE, _S( 2821, "¿ì½ÂÄÅ 30°³ ±³È¯" ), WORLDCUP_EVENT1_EXCHANGE25 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
				}
				break;
				
				case WORLDCUP_EVENT1_RECEIVE:
				{
					if( pUIManager->DoesMessageBoxLExist( MSGCMD_WORLDCUP_EVENT1_RECEIVE ) ) break;
					pUIManager->CreateMessageBoxL(  _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGCMD_WORLDCUP_EVENT1_RECEIVE );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, TRUE,
						_S( 2822, "Ãà±¸ ´ëÈ¸ °á°ú " ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, TRUE,
						_S( 2823, "1À§ ¹ÌÁ¤" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, TRUE,
						_S( 2824, "2À§ ¹ÌÁ¤" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, TRUE,
						_S( 2825, "3À§ ¹ÌÁ¤" ) );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, FALSE, _S( 2826, "1À§ º¸»ó" ), WORLDCUP_EVENT1_REWARD1 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, FALSE, _S( 2827, "2À§ º¸»ó" ), WORLDCUP_EVENT1_REWARD2 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, FALSE, _S( 2828, "3À§ º¸»ó" ), WORLDCUP_EVENT1_REWARD3 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, FALSE, _S( 2829, "±×¿Ü ¼øÀ§ º¸»ó" ), WORLDCUP_EVENT1_REWARD4 );
					pUIManager->AddMessageBoxLString( MSGCMD_WORLDCUP_EVENT1_RECEIVE, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
				}
				break;
			}
		}
		break;

	
	case MSGCMD_WORLDCUP_EVENT1_EXCHANGE :
		{
			nResult-=WORLDCUP_EVENT1_EXCHANGE100;

			if(nResult >= 0 && nResult < WORLDCUP_MAX_GROUP )
			{

				CUIMsgBox_Info MsgBoxInfo;
				CTString strMessage;
				strMessage.PrintF(_S( 2830, "¿ì½ÂÄÅÀ» ±³È¯ÇÒ Âü°¡±¹À» ¼±ÅÃÇØ ÁÖ¼¼¿ä."));
				
				MsgBoxInfo.SetMsgBoxInfo(_S(191,"È®ÀÎ"),UMBS_YESNO | UMBS_COMBOBOX ,UI_QUEST,MSGCMD_WORLDCUP_EVENT1_NUM);
				MsgBoxInfo.AddString(strMessage);
				pUIManager->CreateMessageBox(MsgBoxInfo);

				iSelGroup = nResult;
				pUIManager->GetMessageBox(MSGCMD_WORLDCUP_EVENT1_NUM)->GetComboBox().ResetStrings();
				for(int i=iGroup[iSelGroup] ; i<iGroup[iSelGroup+1]; i++  )
				{
					pUIManager->GetMessageBox(MSGCMD_WORLDCUP_EVENT1_NUM)->GetComboBox().AddString(m_strCountry[i]);
				}
			}
							
		}
		break;
	case MSGCMD_WORLDCUP_EVENT1_RECEIVE :
		{
			nResult-=WORLDCUP_EVENT1_REWARD1;

			if(nResult >= 0 && nResult < WORLDCUP_MAX_GROUP )
			{
				_pNetwork->SendWorldCupEvent(MSGCMD_WORLDCUP_EVENT1_RECEIVE,nResult+1);
			}
								
		}
		break;

	case MSGCMD_WORLDCUP_GOLDENBALL:
		{
			switch( nResult )
			{
			case MSGCMD_WORLDCUP_GOLDENBALL_ENTRY:
				{
					if( pUIManager->DoesMessageBoxExist( MSGCMD_GOLDENBALL_EVENT ) )
						return;

					if( !m_bGoldenBallEntry )
					{
						_pNetwork->ClientSystemMessage( _S( 2831, "ÇöÀç ÀÀ¸ð °¡´É ½Ã°£ÀÌ ¾Æ´Õ´Ï´Ù." ), SYSMSG_ERROR );
						return;
					}
					
					CTString strMessageA, strMessageB;
					strMessageA.PrintF( _S( 2832, "%s VS %s °æ±â\n\n½Â¸®±¹°¡¿Í Á¡¼ö¸¦ ¿¹»óÇÏ¿© ÀÔ·ÂÇØ ÁÖ¼¼¿ä\n\n" ), m_strTeamA, m_strTeamB );
					strMessageB.PrintF( _S( 2833, "%-5sÁ¡¼ö     %-5sÁ¡¼ö" ), m_strTeamA, m_strTeamB );

					strMessageA += strMessageB;

					CUIMsgBox_Info MsgBoxInfo;
					MsgBoxInfo.SetMsgBoxInfo( _S( 2834, "°ñµç º¼ ÀÌº¥Æ®" ), UMBS_OKCANCEL | UMBS_INPUTBOX | UMBS_SECOND_INPUTBOX,
																UI_NONE, MSGCMD_GOLDENBALL_EVENT );

					MsgBoxInfo.AddString( strMessageA, 0xF2F2F2FF, TEXT_CENTER );
					MsgBoxInfo.SetMaxRow( 8 );

					MsgBoxInfo.SetInputBox( 7, 6, 2, 30 );
					MsgBoxInfo.SetSEInputBox( 7, 12, 2, 30, 54 );

					pUIManager->CreateMessageBox( MsgBoxInfo );
				}
				break;
			case MSGCMD_WORLDCUP_GOLDENBALL_REQUITAL:
				{
					_pNetwork->SendWorldCupGoldenBallEvent( MSG_EVENT_GOLDENBALL_GIFT, 0, 0 );
				}
				break;
			}
		}		
		break;
	case MSGLCMD_RAINYDAY:	// ÀÏº» ºø¹æ¿ï ÀÌº¥Æ®
	case MSGLCMD_MOTHERDAY: // ÅÂ±¹ ¾î¸Ó´Ï³¯ ÀÌº¥Æ®
		{
			if( nResult == 1)
			{
				_pNetwork->SendRainyDayExchange();
			}
		}
		break;
	case MSGLCMD_BUDDHISM_EVENT:
		{
			if( nResult >= 0 && nResult <= 6 )
			{ _pNetwork->SendBuddhismEvent( (BYTE)nResult ); }
		}
		break;
	case MSGLCMD_COLLECT_INSECT_EVENT:
		{
			switch( nResult )
			{
			case 0:
				{// ±¸ÀÔ
					pUIManager->CloseMessageBox( MSGCMD_COLLECTBOX_BUY_REQ );

					CTString strMessage;
					CUIMsgBox_Info MsgBoxInfo;
					MsgBoxInfo.SetMsgBoxInfo( _S( 191, "È®ÀÎ" ), UMBS_YESNO, UI_QUEST, MSGCMD_COLLECTBOX_BUY_REQ );
					strMessage.PrintF( _S( 2955, "¿©¸§ ÀÌº¥Æ®¿ë °ïÃæ Ã¤Áý»óÀÚÀÇ °¡°ÝÀº 100³ª½º ÀÔ´Ï´Ù. ±¸ÀÔÇÏ½Ã°Ú½À´Ï±î?" ) );
					MsgBoxInfo.AddString( strMessage );
					pUIManager->CreateMessageBox( MsgBoxInfo );
				}
				break;
			case 1:
				{// º¸»ó
					if( pUIManager->DoesMessageBoxLExist( MSGLCMD_COLLECT_BOX_GIFT ) ) break;
					pUIManager->CreateMessageBoxL( _S( 2954, "°ïÃæ Ã¤Áý»óÀÚ º¸»ó" ), UI_QUEST, MSGLCMD_COLLECT_BOX_GIFT );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2956, "°ïÃæ Ã¤Áý»óÀÚ¸¦ ¸ðµÎ Ã¤¿ö ¿À¼Ì³ª¿ä?" ) );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE,
						_S( 2957, "Ã¤Áý»óÀÚ ¾È¿¡ ÀÖ´Â °ïÃæÀÇ Æ÷ÀÎÆ® ÇÕ°è¿¡ µû¶ó ¾Æ·¡ÀÇ º¸»óÇ°°ú ±³È¯ÇØ µå¸®°Ú½À´Ï´Ù." ) );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE,
						_S( 2958, "ÀÌº¥Æ®±â°£ µ¿¾ÈÀº º¸»ó ÈÄ ´Ù½Ã °ïÃæ Ã¤Áý»óÀÚ¸¦ ±¸ÀÔÇÏ¿© ÀÌº¥Æ®¸¦ °è¼Ó ÇÒ ¼ö ÀÖ½À´Ï´Ù." ) );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, CTString(" ") );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 1866, "º¸»óÇ°" ), -1, 0x6BD2FFFF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2959, "1~25 Æ÷ÀÎÆ®: 500³ª½º" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2960, "26~40 Æ÷ÀÎÆ®: ¸Þ¸ð¸® ½ºÅ©·Ñ 3°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2961, "41~55 Æ÷ÀÎÆ®: ´ëÇü ¸¶³ª È¸º¹Á¦ 5°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2962, "56~70 Æ÷ÀÎÆ®: ´ëÇü Ã¼·Â È¸º¹Á¦ 5°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2963, "71~85 Æ÷ÀÎÆ®: ¹®½ºÅæ 2°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2964, "86~100 Æ÷ÀÎÆ®: ¹®½ºÅæ 5°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2965, "101~115 Æ÷ÀÎÆ®: ´ÞÄÞÇÑ Âü¿Ü 2°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2966, "116~120 Æ÷ÀÎÆ®: »õÄÞÇÑ ÀÚµÎ 2°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2967, "121~125 Æ÷ÀÎÆ®: ÀßÀÍÀº ¼ö¹Ú 2°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2968, "126~130 Æ÷ÀÎÆ®: °í±Þ Á¦·Ã¼® 1°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2969, "131~159 Æ÷ÀÎÆ®: °í±Þ Á¦·Ã¼® 2°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, TRUE, _S( 2970, "160 Æ÷ÀÎÆ® ÀÌ»ó: °í±Þ Á¦·Ã¼® 3°³" ), -1, 0xA3A1A3FF );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, FALSE, _S( 2971, "°ïÃæ Ã¤Áý»óÀÚ º¸»ó ¹Þ±â" ), 0 );
					pUIManager->AddMessageBoxLString( MSGLCMD_COLLECT_BOX_GIFT, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
				}
				break;
			}
		}
		break;
	case MSGLCMD_COLLECT_BOX_GIFT:
		{
			if( nResult == 0 )
			{
				_pNetwork->SendGiftCollectBox();
			}
		}
		break;
	case MSGLCMD_EVENT_PROMOPACK:
		{
			if( nResult == EVENT_PROMO_KEY_ENTER )
			{
				CUIMsgBox_Info MsgBoxInfo;
				int tmpInputMaxChar = 12;

				MsgBoxInfo.m_nInputMaxChar = tmpInputMaxChar;
				MsgBoxInfo.m_nInputWidth = 78;
				MsgBoxInfo.m_nInputPosX = 70;
				MsgBoxInfo.m_nInputPosY = 48;

				if (IsGamigo(g_iCountry) == TRUE)
				{
					if ( g_iCountry != FRANCE )
					{
						MsgBoxInfo.m_nInputMaxChar = 20;
						MsgBoxInfo.m_nInputWidth = 130;
						MsgBoxInfo.m_nInputPosX = 44;
					}
				}

				MsgBoxInfo.SetMsgBoxInfo(_S(3150, "Serial Key Enter"),UMBS_OKCANCEL|UMBS_INPUTBOX,UI_QUEST,MSGCMD_EVENT_COUPON_SENDNUM);
				pUIManager->CreateMessageBox(MsgBoxInfo);
			}
		}
		break;
	case MSGLCMD_EVENT_LOVE_LOVE:
		{
			if (nResult == 0 )
			{
				if (pUIManager->DoesMessageBoxExist(MSGCMD_OK_EXCHANGE_CHOCOBOX) ||
					pUIManager->DoesMessageBoxExist(MSGCMD_OK_EXCHANGE_LUCKYBOX))
					return;

				CUIMsgBox_Info MsgBoxInfo;
				CTString strMessage, strTitle;
				int nCommand;

				if (IS_EVENT_ON(TEVENT_LUNARNEWYEAR_2008))
				{
					strMessage = _S(4008, "¼Ò¸Á»óÀÚ¸¦ ¿Ã¸° ÈÄ È®ÀÎ¹öÆ°À» Å¬¸¯ÇÏ¼¼¿ä");
					strTitle = _S(4006, "¼Ò¸Á»óÀÚ ±³È¯");
					nCommand = MSGCMD_OK_EXCHANGE_LUCKYBOX;
				}
				else
				{
					strMessage = _S(3217, "ÃÊÄÚ»óÀÚ¸¦ ¿Ã¸° ÈÄ È®ÀÎ¹öÆ°À» Å¬¸¯ÇÏ¼¼¿ä");
					strTitle = _S(3216, "ÃÊÄÚ»óÀÚ ±³È¯");
					nCommand = MSGCMD_OK_EXCHANGE_CHOCOBOX;
				}

				MsgBoxInfo.SetMsgBoxInfo(strTitle, UMBS_YESNO | UMBS_BUTTONEX, UI_QUEST, nCommand);
				MsgBoxInfo.SetBtnType(UBET_ITEM, CItemData::ITEM_ONCEUSE, CItemData::ITEM_SUB_BOX);
				MsgBoxInfo.AddString(strMessage);
				pUIManager->CreateMessageBox(MsgBoxInfo);
			}
		}
		break;
	
		// wooss 070305	------------------------------>>
		// kw : WSS_WHITEDAY_2007
	case  MSGLCMD_WHITEDAY_2007:
		{
			CTString tstr;
			switch(nResult)
			{
				case EVENT_REWARD_1:
					// TODO : ·¯ºê¸ÅÁ÷ ÁÖ¹®À» ¹Þ´Â´Ù.
				case EVENT_REWARD_2:
					// TODO : ÇÏ´Ã»ö ÆíÁöÁö·Î ±³È¯
				case EVENT_REWARD_3:
					// TODO : ºÐÈ«»ö ÆíÁöÁö·Î ±³È¯
					_pNetwork->SendWhiteday2007((UBYTE)(nResult - EVENT_REWARD_1));
					break;

			}

		} // MSGLCMD_WHITEDAY_2007
		break;	
		// ---------------------------------------------<<
	case MSGLCMD_EVENT_MAY:
		{
			switch(nResult)
			{
				case EVENT_MAY_PARENTS:
					{
						// TODO : ¾î¹öÀÌ³¯ ÀÌº¥Æ® 
						// WSS_GUILDMASTER 070411 -------------------------------------------------------------->>						
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_GUILDMASTER ) ) break;
						pUIManager->CreateMessageBoxL(  _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_GUILDMASTER );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, TRUE,CTString(""));
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, TRUE,_S(3445, "¾î¹öÀÌ³¯ ÀÌº¥Æ®´Â ¾î¹öÀÌ³¯À» ¸ÂÀÌÇÏ¿© »¡°£ Ä«³×ÀÌ¼ÇÀ» ±æµå¿øµéÀÌ ±æµå¸¶½ºÅÍ¿¡°Ô ¼±¹°À» ÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù."));
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, TRUE,_S(3446, "±æµå ¸¶½ºÅÍ´Â »¡°£ Ä«³×ÀÌ¼ÇÀ» ¼±¹°·Î ¹Þ°í ÀÌ¸¦ ±æµå Æ÷ÀÌÆ®·Î µî·ÏÇÏ¿© °¡Àå ³ôÀº Á¡¼ö¸¦ ³»´Â ±æµå¸¦ »Ì´Â ÀÌº¥Æ® ÀÔ´Ï´Ù."));
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, TRUE,CTString(""));
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, FALSE,_S(3447, "±æµå Æ÷ÀÎÆ®"), EVENT_REWARD_1 );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, FALSE,_S(3448, "±³È¯±Ç"), EVENT_REWARD_2 );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER, FALSE, _S( 1220, "Ãë¼ÒÇÑ´Ù." ) );
						// ---------------------------------------------------------------------------------------<<
					
					}
					break;
				case EVENT_MAY_MASTER:
					{
						// TODO : ½º½ÂÀÇ³¯ ÀÌº¥Æ®
// [KH_070413] ½º½ÂÀÇ³¯ ÀÌº¥Æ® °ü·Ã Ãß°¡
						if(!ItemHelp::HaveItem(MEDAL_OF_TEACHER) &&
							!ItemHelp::HaveItem(MEDAL_OF_DISCIPLE))
						{
							CUIMsgBox_Info MsgBoxInfo;
							MsgBoxInfo.SetMsgBoxInfo(_S(3344, "½º½ÂÀÇ ÀºÇý ÀÌº¥Æ®"), UMBS_OK, UI_NONE,MSGCMD_NULL);
							MsgBoxInfo.AddString(_S(3345, "½º½ÂÀÇ ÀºÇý ÀÌº¥Æ®¸¦ Âü°¡ÇÏ¿© º¸¼¼¿ä. ±×·³ ÁÁÀº ÀÏÀÌ ÀÖÀ» °Å¿¡¿ä."));
							pUIManager->CreateMessageBox(MsgBoxInfo);
						}
						else
							_pNetwork->SendEventMaster();
					}
					break;
			}
		}			
		break;
		// --------------------------------------------<<

	// WSS_GUILDMASTER 070411 -------------------------------------------------------------->>
	case MSGLCMD_GUILDMASTER:
		{
			switch(nResult)
			{
				case EVENT_REWARD_1:
					{
						pUIManager->CloseMessageBox(MSGCMD_GUILDMASTER_1);
						CUIMsgBox_Info	MsgBoxInfo;
						CTString strTitle =_S(169, "ÀÌº¥Æ®");
						MsgBoxInfo.SetMsgBoxInfo( strTitle, UMBS_LISTBOX|UMBS_USER_12 | UMBS_ALIGN_CENTER , UI_QUEST, MSGCMD_GUILDMASTER_1 );
						MsgBoxInfo.SetUserBtnName( _S(2489, "µî·Ï" ), _S(3449, "°»½Å") );
						MsgBoxInfo.SetListBoxPlacement(5,25,330,100,5,3);
						pUIManager->CreateMessageBox( MsgBoxInfo );
						CUIListBox* tBox = &pUIManager->GetMessageBox(MSGCMD_GUILDMASTER_1)->GetListBox();
						tBox->ResetAllStrings();
						tBox->AddString( 0, _S(1714, "¼øÀ§"),0xF2F2F2FF, FALSE );
						tBox->AddString( 1, _S(3450, "Æ÷ÀÎÆ®"),0xF2F2F2FF, FALSE );
						tBox->AddString( 2, _S(3451, "±æµå¸í"),0xF2F2F2FF, FALSE );						
						
						// Adjust column position of list box
						int tSpc = _pUIFontTexMgr->GetFontWidth();
						tBox->SetColumnPosX( 0, 5*tSpc, TEXT_CENTER );
						tBox->SetColumnPosX( 1, 25*tSpc, TEXT_RIGHT );
						tBox->SetColumnPosX( 2, 45*tSpc, TEXT_CENTER );						

						// ±æµå ¸®½ºÆ® ¿äÃ»...
						_pNetwork->SendRequestParentsday( MSG_EVENT_PARENTSDAY_2007_ACCUMULATEPOINT_RANKING_LIST);
					}
					break;					
				case EVENT_REWARD_2:
					{						
						if( pUIManager->DoesMessageBoxLExist( MSGLCMD_GUILDMASTER_2 ) ) break;
						pUIManager->CreateMessageBoxL(  _S( 169, "ÀÌº¥Æ®" ), UI_QUEST, MSGLCMD_GUILDMASTER_2 );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER_2, TRUE,	CTString(" "));
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER_2, TRUE,	_S(3466, "±æµå Æ÷ÀÎÆ® 100Æ÷ÀÎÆ®´ç ±³È¯±Ç 1ÀåÀ» ¹ÞÀ» ¼ö ÀÖ½À´Ï´Ù. Áö±Þ ¹ÞÀº ±³È¯±ÇÀ» »ç¿ëÇÏ¿© »óÇ°À» ¹Þ¾Æ ±æµå¿øµé°ú ÀÌº¥Æ®¸¦ Áñ°Ü º¸¼¼¿ä." ) );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER_2, FALSE, _S(3467, "±³È¯±Ç ¹Þ±â" ), EVENT_REWARD_1 );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER_2, FALSE, _S(3468, "±³È¯±Ç »ç¿ëÇÏ±â" ), EVENT_REWARD_2 );
						pUIManager->AddMessageBoxLString( MSGLCMD_GUILDMASTER_2, FALSE, _S(1220, "Ãë¼ÒÇÑ´Ù." ) );
						
					}
					break;			
			}
		}			
		break;
	case MSGLCMD_GUILDMASTER_2:
		{
			// TODO : ±³È¯±Ç
			switch(nResult)
			{
				case EVENT_REWARD_1:
					{
						// ±³È¯±Ç ¹Þ±â
						pUIManager->CloseMessageBox(MSGCMD_GUILDMASTER_2_1);
						CUIMsgBox_Info	MsgBoxInfo;
						CTString strMessage =_S(169, "ÀÌº¥Æ®");
						MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_OKCANCEL, UI_QUEST, MSGCMD_GUILDMASTER_2_1 );
						strMessage = _S(3452, "´©ÀûµÈ ±³È¯±ÇÀ» ¹ÞÀ¸½Ã°Ú½À´Ï±î?");
						MsgBoxInfo.AddString(strMessage);
						pUIManager->CreateMessageBox( MsgBoxInfo );
					}
					break;					
				case EVENT_REWARD_2:
					{	
						// ±³È¯±Ç »ç¿ëÇÏ±â
						_pNetwork->SendRequestParentsday( MSG_EVENT_PARENTSDAY_2007_EXCHANGE_ITEM);
						
					}
					break;			
			}

		}
		break; 
	// --------------------------------------------------------------------------------------<<

	// WSS_EVENT_MINIGAME 070420 ------------------------------------------------------------>>
	case MSGLCMD_EVENT_MINIGAME:
		{
			switch(nResult)
			{
				case EVENT_REWARD_1:
					{
						// TODO : °¡À§¹ÙÀ§º¸ °ÔÀÓÇÏ±â
						if (IS_EVENT_ON(TEVENT_GOMDOLI))
						{
							// Send MSG_EVENT_GOMDORI_2007_CHECKITEM 	
							_pNetwork->SendMinigameDefaultMessage(MSG_EVENT_GOMDORI_2007, MSG_EVENT_GOMDORI_2007_CHECKITEM);
						}
						else if (IS_EVENT_ON(TEVENT_XMAS_2007))
						{
							_pNetwork->SendMinigameDefaultMessage(MSG_EVENT_XMAS_2007, MSG_EVENT_XMAS_PUZZLE_CHECKITEM_REQ);
						}
					}
					break;					
				case EVENT_REWARD_2:
					{
						// TODO : °õµ¹ÀÌ ÀÎÇü À¢µð Ã£±â ÇöÈ²º¸±â
						if (IS_EVENT_ON(TEVENT_GOMDOLI))
							_pNetwork->SendMinigameDefaultMessage(MSG_EVENT_GOMDORI_2007, MSG_EVENT_GOMDORI_2007_VIEW_STATUS);					
					}
					break;				
			}
		}			
		break;

	case MSGLCMD_SIEGE_WARFARE_UPGRADE:
		{
			switch(nResult)
			{
				case EVENT_REWARD_1:  // °ø°ÝÇü °­È­
					{
						pUIManager->GetSiegeWarfareNew()->SetUpgradeType( SWUT_ATTACK );						
						pUIManager->GetSiegeWarfareNew()->SendTowerStateRequest(SWUT_ATTACK);				
						
					}
					break;					
				case EVENT_REWARD_2:  // °¡µåÇü °­È­
					{
						pUIManager->GetSiegeWarfareNew()->SetUpgradeType( SWUT_GUARD );						
						pUIManager->GetSiegeWarfareNew()->SendTowerStateRequest(SWUT_GUARD);
										
					}
					break;				
			}
		}			
		break;
	// -----------------------------------------------------------------------------------------<<
		
	// [070705: Su-won] EVENT_SUMMER_2007
	case MSGLCMD_SUMMER_2007:
		{
			switch(nResult)
			{
				case EVENT_REWARD_1:
					{
						//Á¾ÀÌ Á¢±â
						pUIManager->CloseMessageBox(MSGCMD_SUMMER2007_PAPERFOLDING);
						CUIMsgBox_Info	MsgBoxInfo;
						CTString strMessage =_S(3569, "Á¾ÀÌÁ¢±â");
						MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_OKCANCEL | UMBS_BUTTONEX, UI_QUEST, MSGCMD_SUMMER2007_PAPERFOLDING );
						MsgBoxInfo.SetBtnType( UBET_ITEM, CItemData::ITEM_ETC, CItemData::ITEM_ETC_MATERIAL, 3 );
						strMessage = _S(3571, "Á¾ÀÌÁ¢±â¸¦ ÇÒ »öÁ¾ÀÌ¸¦ ¿Ã·Á ³õÀ¸¼¼¿ä.");
						MsgBoxInfo.AddString(strMessage);
						strMessage = _S(3572, "Á¾ÀÌÁ¢±â¿¡´Â 100³ª½º°¡ ÇÊ¿äÇÕ´Ï´Ù.");
						MsgBoxInfo.AddString(strMessage);
						pUIManager->CreateMessageBox( MsgBoxInfo );
					}
					break;					
				case EVENT_REWARD_2:
					{
						//»öÁ¾ÀÌ Á¶ÇÕ
						pUIManager->CloseMessageBox(MSGCMD_SUMMER2007_PAPERBLENDING);
						CUIMsgBox_Info	MsgBoxInfo;
						CTString strMessage =_S(3570, "»öÁ¾ÀÌ Á¶ÇÕ");
						MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_OKCANCEL | UMBS_BUTTONEX, UI_QUEST, MSGCMD_SUMMER2007_PAPERBLENDING );
						MsgBoxInfo.SetBtnType( UBET_ITEM, CItemData::ITEM_ETC, CItemData::ITEM_ETC_MATERIAL);
						strMessage = _S(3573, "Á¶ÇÕÇÒ »öÁ¾ÀÌ¸¦ ¿Ã·Á ³õÀ¸¼¼¿ä.");
						MsgBoxInfo.AddString(strMessage);
						strMessage = _S(3574, "µ¿ÀÏÇÑ »öÁ¾ÀÌ 5ÀåÀ» Á¶ÇÕÇÏ¿© »óÀ§ »öÁ¾ÀÌ 1ÀåÀ» »ý¼ºÇÒ ¼ö ÀÖ½À´Ï´Ù.");
						MsgBoxInfo.AddString(strMessage);
						strMessage = _S(3575, "´Ü! ½ÇÆÐÇÒ ¼öµµ ÀÖÀ¸´Ï ÁÖÀÇÇÏ¼¼¿ä.");
						MsgBoxInfo.AddString(strMessage);
						pUIManager->CreateMessageBox( MsgBoxInfo );
					}
					break;				
			}
		}			
		break;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// [070807: Su-won] EVENT_ADULT_OPEN
	case MSGLCMD_EVENT_ADULT_MAGICCARD:
		{
			if( nResult ==0)
			{
				_pNetwork->SendAdultOpenEventReq(0);
			}
		}
		break;
	case MSGLCMD_EVENT_ADULT_CHANGEJOB:
		{
			if( nResult ==0)
			{
				_pNetwork->SendAdultOpenEventReq(1);
			}
		}
		break;
	case MSGLCMD_EVENT_ADULT_ALCHEMIST:
		{
			if( nResult ==0 )
			{
				pUIManager->CloseMessageBox(MSGCMD_ADULTEVENT_ALCHEMIST);

				CUIMsgBox_Info	MsgBoxInfo;
				CTString strMessage =_S(3635, "ÀåºñÁ¶ÇÕ ¿¬±Ý¼ú ÀÌº¥Æ®");
				MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_OKCANCEL | UMBS_BUTTONEX, UI_QUEST, MSGCMD_ADULTEVENT_ALCHEMIST );
				MsgBoxInfo.SetBtnType(UBET_ITEM, -1, -1);

				strMessage = _S(3636, "Á¶ÇÕÇÒ Àåºñ¸¦ ¿Ã·ÁÁÖ¼¼¿ä.");
				MsgBoxInfo.AddString(strMessage);
				MsgBoxInfo.AddString(CTString(" "));

				strMessage = _S(2462, "ÇÊ¿ä Àç·á");
				MsgBoxInfo.AddString(strMessage, 0xE18600FF);
				MsgBoxInfo.AddString(CTString(" "));
				MsgBoxInfo.AddString(CTString(" "));

				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
		}
		break;
		// [070807: Su-won] EVENT_ADULT_OPEN
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case MSGLCMD_TG2007_FRUITFULL: // WSS_TG2007 2007/09/14
		{
			switch(nResult)
			{
				case EVENT_REWARD_1:  // ´ÙÀ½ ´Ü°è·Î ¾÷±×·¹ÀÌµå ÇÑ´Ù.
					{
						// TODO ::  ¾÷±×·¹ÀÌµå ¿äÃ»
						_pNetwork->SendTG2007RichYearReq(MSG_EVENT_RICHYEAR_UPGRADE);
					}
					break;					
				case EVENT_REWARD_2:  // º¸»óÇ°À» Áö±Þ ¹Þ´Â´Ù.
					{
						// TODO ::  º¸»óÇ° Áö±Þ ¿äÃ»	
						_pNetwork->SendTG2007RichYearReq(MSG_EVENT_RICHYEAR_EXCHANGE);
					
					}
					break;				
			}
		}			
		break;

		// ºÓÀº»ö º¸¹° »óÀÚ ¿­±â
	case MSGLCMD_RED_TREASUREBOX_EVENT:
		{
			if( nResult == 1 )
			{
				CNetworkMessage nmEvent( MSG_EVENT );
				nmEvent << (UBYTE)MSG_EVENT_TREASUREBOX_RED;
				nmEvent << (UBYTE)MSG_EVENT_TREASUREBOX_RED_OPEN_REQ;
				nmEvent << _pNetwork->MyCharacterInfo.index;
				_pNetwork->SendToServerNew( nmEvent );
			}
		}
		break;

	// [080422: Su-won] EVENT_CHAOSBALL
	case MSGLCMD_CHAOSBALL_EVENT:
		{
			if( nResult == 1)
			{
				if (pUIManager->DoesMessageBoxExist(MSGCMD_EVENT_CHAOSBALL))
					pUIManager->CloseMessageBox(MSGCMD_EVENT_CHAOSBALL);

				CUIMsgBox_Info	MsgBoxInfo;
				CTString strMessage =_S(4132, "Ä«¿À½º º¼ ºÀÀÎÇØÁ¦ÇÏ±â");
				MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_OKCANCEL | UMBS_BUTTONEX, UI_QUEST, MSGCMD_EVENT_CHAOSBALL );
				MsgBoxInfo.SetBtnType( UBET_ITEM, CItemData::ITEM_ETC, CItemData::ITEM_ETC_MATERIAL, 1 );
				strMessage = _S(4133, "Ä«¿À½º º¼À» ¿Ã¸° ÈÄ È®ÀÎ ¹öÆ°À» Å¬¸¯ÇÏ¼¼¿ä.");
				MsgBoxInfo.AddString(strMessage);
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
		}
		break;

	// ($E_WC2010) [100514: selo] 2010 ³²¾Æ°ø ¿ùµåÄÅ ÀÌº¥Æ®2 ¿ì½Â ±¹°¡ ¿¹»óÇÏ±â
	case MSGLCMD_EVENT_WORLDCUP_EVENT2:
		{
			if( nResult == EVENT_WORLDCUP_2010_EVENT2_SEL1 )		// ¿ì½Â ±¹°¡ ÀÀ¸ð
			{
				_pNetwork->SendWorldCup2010_Event(MSG_EVENT_WORLDCUP2010_TOTO_STATUS_REQ, EVENT_WORLDCUP_2010_EVENT2_SEL1);
			}			
			else if( nResult == EVENT_WORLDCUP_2010_EVENT2_SEL2 )	// ³» ÀÀ¸ð ÇöÈ²
			{
				_pNetwork->SendWorldCup2010_Event(MSG_EVENT_WORLDCUP2010_TOTO_STATUS_REQ, EVENT_WORLDCUP_2010_EVENT2_SEL2);
			}
			else if( nResult == EVENT_WORLDCUP_2010_EVENT2_SEL3 )	// ´çÃ· º¸»ó ¹Þ±â
			{
				_pNetwork->SendWorldCup2010_Event(MSG_EVENT_WORLDCUP2010_TOTO_GIFT_REQ);
			}
		}
		break;
	// ($E_WC2010) [100514: selo] 2010 ³²¾Æ°ø ¿ùµåÄÅ ÀÌº¥Æ®3 ¸ÅÀÏ ¸ÅÀÏ ÀÀ¿øÇÏ±â
	case MSGLCMD_EVENT_WORLDCUP_EVENT3:
		{
			if( nResult == EVENT_WORLDCUP_2010_EVENT3_SEL1 )
			{
				_pNetwork->SendWorldCup2010_Event(MSG_EVENT_WORLDCUP2010_KOREA_REQ);
			}
		}
		break;
	case MSGLCMD_ATTENDANCE_SYSTEM:
		{	// Ãâ¼® ½Ã½ºÅÛ º¸»ó ½ÅÃ» (100ÀÏ, 200ÀÏ, 365ÀÏ ¿¬¼Ó Ãâ¼®ÀÏ °æ¿ì º¸»ó °¡´É)
			if ( nResult == 0)
			{
				_pNetwork->SendAttendanceReq( 1 );
			}
		}
		break;
	case MSGLCMD_REGISTER_MERCHANT:	// [2010/08/25 : Sora] ADD_SUBJOB
		{
			if( nResult == 1)
			{
				if (pUIManager->DoesMessageBoxExist(MSGCMD_REGISTER_MERCHANT))
					pUIManager->CloseMessageBox(MSGCMD_REGISTER_MERCHANT);

				CUIMsgBox_Info	MsgBoxInfo;
				CTString strMessage =_S( 2489,"µî·Ï");
				MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_OKCANCEL, UI_QUEST, MSGCMD_REGISTER_MERCHANT );
				strMessage = _S( 5064, "»óÀÎÀ¸·Î µî·Ï ÇÏ½Ã°Ú½À´Ï±î?");
				MsgBoxInfo.AddString(strMessage);
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
		}
		break;
	case MSGLCMD_SYNDICATE_JEWEL_GIVE:
		{
			if (nResult < 0)
				break;

			if( pUIManager->DoesMessageBoxExist( MSGLCMD_SYNDICATE_JEWEL_GIVE ) ) 
				return;

			CUIMsgBox_Info MsgBoxInfo;
			CTString strMessage;

			strMessage.PrintF(_S(6114, "Ã¢Á¶ÀÇ º¸¼® ±âºÎ" ));
			MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_YESNO | UMBS_BUTTONEX, UI_QUEST, MSGCMD_SYNDICATE_PUTON_JEWEL_REQ );
			strMessage.PrintF(_S(6115,  "¾Æ·¡ÀÇ ½½·Ô¿¡ ±âºÎÇÒ Ã¢Á¶ÀÇ º¸¼®À» ¿Ã·Á³õÀ¸½Å ÈÄ ±âºÎ ¹öÆ°À» ´­·¯ÁÖ¼¼¿ä." ));
			MsgBoxInfo.SetBtnType( UBET_ITEM, CItemData::ITEM_ETC, CItemData::ITEM_ETC_SYNDICATEJEWEL );	// ¾ÆÀÌÅÛ Å¸ÀÔ ¼³Á¤ ÇØ¾ßÇÔ.
			MsgBoxInfo.AddString( strMessage );
			pUIManager->CreateMessageBox( MsgBoxInfo );		
		}
		break;
	case MSGLCMD_SYNDICATE_SECESSION_REQ:
		{
			if (nResult < 0)
				break;

			if( pUIManager->DoesMessageBoxExist( MSGCMD_SYNDICATE_SECESSION_REQ ) ) 
				return;

			GameDataManager* pGameData = GameDataManager::getSingleton();

			if (pGameData == NULL)
				break;

			CSyndicate* pSyndicateData = pGameData->GetSyndicate();

			if (pSyndicateData == NULL)
				break;

			CTString strSyndicateName = pSyndicateData->GetSyndicateName(_pNetwork->MyCharacterInfo.iSyndicateType);

			CUIMsgBox_Info	MsgBoxInfo;
			CTString strMessage =_S( 6123,"°á»ç´ë Å»Åð ¿äÃ»");
			MsgBoxInfo.SetMsgBoxInfo( strMessage, UMBS_YESNO | UMBS_BUTTONEX, UI_QUEST, MSGCMD_SYNDICATE_SECESSION_REQ );
			
			strMessage.PrintF(_S( 6124,
				"°á»ç´ë¿¡¼­ Å»Åð ½Ã¿¡´Â ±× µ¿¾È ´©ÀûµÇ¾ú´ø ±â¿©µµ°¡ ¸ðµÎ ÃÊ±âÈ­µÇ¸ç ¾Æ·¡¿Í °°Àº À§¾à±ÝÀ» ÁöºÒ ÇÏ¼Å¾ß ÇÕ´Ï´Ù."));
			MsgBoxInfo.AddString( strMessage );

			CTString strTemp;
			strTemp.PrintF("%I64d", pSyndicateData->GetSecssionNas());
			pUIManager->InsertCommaToString(strTemp);
			strMessage.PrintF(_S( 6125, "À§¾à±Ý:%s ³ª½º"), strTemp);
			MsgBoxInfo.AddString( strMessage );

			strMessage.PrintF(_S( 6285,
				"´Ü, °á»ç´ë Å»Åð Æä³ÎÆ¼¸éÃ¥ ±ÇÀ» »ç¿ëÇÏ½Ã¸é ±â¿©µµ ÇÏ¶ô°ú À§¾à±Ý ¾øÀÌ Å»Åð°¡ °¡´ÉÇÕ´Ï´Ù."),
				pSyndicateData->GetSecssionNas());
			MsgBoxInfo.AddString( strMessage );

			MsgBoxInfo.SetBtnType( UBET_ITEM, CItemData::ITEM_ETC, CItemData::ITEM_ETC_MATERIAL );

			strMessage.PrintF(_S( 6126, "[%s] °á»ç´ë¸¦ Á¤¸»·Î Å»Åð ÇÏ½Ã°Ú½À´Ï±î?"), strSyndicateName);
			MsgBoxInfo.AddString( strMessage );
			pUIManager->CreateMessageBox( MsgBoxInfo );
			pUIManager->GetMessageBox(MSGCMD_SYNDICATE_SECESSION_REQ)->GetBtnOK().SetEnable(TRUE);

		}
		break;
	}
}

// ----------------------------------------------------------------------------
//  [5/17/2010 selo0530] ($E_WC2010)
//
//	Name : CreateMessageBox_WorldCup2010_Event2
//	Desc : 2010 ³²¾Æ°ø ¿ùµåÄÅ ¿ì½Â ±¹°¡ ¸ÂÃß±â ¸Þ½ÃÁö ¹Ú½º
//	Info : nType ÀÀ¸ð ¹æ½Ä
// ----------------------------------------------------------------------------
void CUIQuest::CreateMessageBox_WorldCup2010_Event2( INDEX nType )
{	
	CTString strTitle;
	CTString strDesc;
	int nCommand = -1;
	int nBtnCnt = 1;

	switch( nType )
	{
	case EVENT_WORLDCUP_2010_EVENT2_SEL1:
		{
			strTitle = _S(4908, "¿ì½Â ±¹°¡ ÀÀ¸ð");
			strDesc = _S(4913, "¿ì½ÂÀ» ¿¹»óÇÏ´Â ±¹°¡ÀÇ ±¹±â ¾ÆÀÌÅÛÀ» µî·ÏÇØ ÁÖ¼¼¿ä. ±¹±â ¾ÆÀÌÅÛÀº µî·Ï°ú µ¿½Ã¿¡ »èÁ¦ µÇ¿À´Ï, ½ÅÁßÇÏ°Ô °áÁ¤ÇØ ÁÖ¼¼¿ä.");
			nCommand = MSGCMD_EVENT_WORLDCUP_EVENT2_REQ;			
		}
		break;	
	default:	// ÇØ´ç »çÇ× ¾øÀ¸¸é ±×³É ¸®ÅÏÇÏ¿© ¸Þ½ÃÁö ¹Ú½º¸¦ ¸¸µéÁö ¾Ê´Â´Ù.
		return;
	}	


	CUIMsgBox_Info	MsgBoxInfo;	
	MsgBoxInfo.SetMsgBoxInfo( strTitle, UMBS_OKCANCEL | UMBS_BUTTONEX, UI_QUEST, nCommand );
	MsgBoxInfo.SetBtnType(UBET_ITEM, CItemData::ITEM_ETC, CItemData::ITEM_ETC_EVENT, nBtnCnt);
	MsgBoxInfo.AddString(strDesc);
	MsgBoxInfo.AddString(CTString(" "));
	
	CUIManager::getSingleton()->CreateMessageBox( MsgBoxInfo );
}

// ----------------------------------------------------------------------------
// Name : CloseQuest()
// Desc :
// ----------------------------------------------------------------------------
void CUIQuest::CloseQuest()
{
	CUIManager* pUIManager = CUIManager::getSingleton();

	// Close message box of remission
	pUIManager->CloseMessageBox( MSGCMD_QUEST_NOTIFY );
	pUIManager->CloseMessageBox( MSGCMD_QUEST_NEWQUEST );
		
	pUIManager->CloseMessageBoxL( MSGLCMD_QUEST_REQ); 
	pUIManager->CloseMessageBoxL( MSGLCMD_EVENT_2PAN4PAN_ONE); 
	pUIManager->CloseMessageBoxL( MSGLCMD_EVENT_2PAN4PAN_TWO); 

	pUIManager->CloseMessageBox( MSGCMD_ASK_ONE_FIVE );   
	pUIManager->CloseMessageBox( MSGCMD_ASK_ONE_FOUR );
	pUIManager->CloseMessageBox( MSGCMD_ASK_TWO_OPEN );   

	pUIManager->CloseMessageBox( MSGLCMD_EVENT_NEWYEAR1);
	pUIManager->CloseMessageBox( MSGLCMD_EVENT_NEWYEAR2);

	pUIManager->RearrangeOrder( UI_QUEST, FALSE );
}

// ----------------------------------------------------------------------------
// Name : Render()
// Desc :
// ----------------------------------------------------------------------------
void CUIQuest::Render()
{
	// Check distance
	FLOAT	fDiffX = _pNetwork->MyCharacterInfo.x - m_fNpcX;
	FLOAT	fDiffZ = _pNetwork->MyCharacterInfo.z - m_fNpcZ;
	if( fDiffX * fDiffX + fDiffZ * fDiffZ > UI_VALID_SQRDIST )
		CloseQuest();
}

// ----------------------------------------------------------------------------
// Name : MsgBoxCommand()
// Desc :
// ----------------------------------------------------------------------------
void CUIQuest::MsgBoxCommand( int nCommandCode, BOOL bOK, CTString &strInput )
{
	CUIManager* pUIManager = CUIManager::getSingleton();

	// WSS_GUILDMASTER 070416
	CTString	strMessage;
	CUIMsgBox_Info	MsgBoxInfo;	

	CMobData* MD = CMobData::getData(m_iNpcIndex);
	LONGLONG lNpcVIndex = 0;
	CEntity* pEntity = NULL;

	pEntity = INFO()->GetTargetEntity(eTARGET);
	
	if (pEntity != NULL)
		lNpcVIndex = pEntity->GetNetworkID();	// npc virtual index

	switch( nCommandCode )
	{
	case MSGLCMD_REMOVE_SELECTED_BUFF:
		if( bOK ) {
			_pNetwork->SendRemoveBuffReq(_pUIBuff->GetBuffSelectedItem(), _pUIBuff->GetBuffSelectedSkill());
		}
		break;
	case MSGLCMD_EXCHANGE_HEALER:
		if( bOK ) {
			_pNetwork->SendClassChange(HEALER, lNpcVIndex);
		}
		break;
	case MSGLCMD_EXCHANGE_KNIGHT:
		if( bOK ) {
			_pNetwork->SendClassChange(KNIGHT, lNpcVIndex);
		}
		break;
	case MSGLCMD_EXCHANGE_MAGE:
		if( bOK ) {
			_pNetwork->SendClassChange(MAGE, lNpcVIndex);
		}
		break;
	case MSGLCMD_EXCHANGE_NIGHTSHADOW:
		if( bOK ) {
			_pNetwork->SendClassChange(NIGHTSHADOW, lNpcVIndex);
		}
		break;
	case MSGLCMD_EXCHANGE_ROGUE:
		if( bOK ) {
			_pNetwork->SendClassChange(ROGUE, lNpcVIndex);
		}
		break;
	case MSGLCMD_EXCHANGE_SORCERER:
		if( bOK ) {
			_pNetwork->SendClassChange(SORCERER, lNpcVIndex);
		}
		break;
	case MSGLCMD_EXCHANGE_TITAN:
		if( bOK ) {
			_pNetwork->SendClassChange(TITAN, lNpcVIndex);
		}
		break;
	case MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE1:
		{
			//2006 Ãß¼® ÀÌº¥Æ®: ¼ÛÆíÀ» ¸¸µê
			if( bOK )
			{
				_pNetwork->Send2006ChuseokRicecakeMake();
			}
			else
			{
				// ÀÌÀüÃ¢À¸·Î µ¹¾Æ°¨
				MsgBoxLCommand( MSGLCMD_EVENT, QUEST_HARVEST_MOON_DAY_EVENT1 ); 
			}
		}
		break;
	case MSGCMD_HARVEST_MOON_DAY_EVENT_UPGRADE2:
		{
			//2006 Ãß¼® ÀÌº¥Æ®: ¿À»ö¼ÛÆíÀ» ¸¸µê
			if( bOK )
			{
				_pNetwork->Send2006ChuseokRainbowMake();
			}
			else
			{
				// ÀÌÀüÃ¢À¸·Î µ¹¾Æ°¨
				MsgBoxLCommand( MSGLCMD_EVENT, QUEST_HARVEST_MOON_DAY_EVENT1 ); 
			}
		}
		break;
	case MSGCND_MOON_DAY_EVENT_GIVE_ITEM:
		{
			//2006 Ãß¼® ÀÌº¥Æ®: ¿À»ö¼ÛÆíÀ» º¸»óÇ°°ú ±³È¯ÇÔ
			if( bOK )
			{
				_pNetwork->Send2006ChuseokExchange();
			}
			else
			{
				// ÀÌÀüÃ¢À¸·Î µ¹¾Æ°¨
				MsgBoxLCommand( MSGLCMD_EVENT, QUEST_HARVEST_MOON_DAY_EVENT2 );
			}

		}
		break;
	case MSGCMD_QUEST_FAIL:
		{
			CQuestDynamicData	*pQuestDD = CQuestSystem::Instance().GetDynamicDataByQuestIndex( m_iCurQuestIndex );
			if(pQuestDD && _pNetwork->m_bSingleMode)
			{
				INDEX startType = pQuestDD->GetStartType();
				INDEX startData = pQuestDD->GetStartData();
				INDEX prizeNPCIndex = pQuestDD->GetPrizeNPCIndex();
				if( pQuestDD->GetQuestType1() == QTYPE_KIND_SAVE || pQuestDD->GetQuestType1() == QTYPE_KIND_TUTORIAL || pQuestDD->GetQuestType1() == QTYPE_KIND_DEFEAT )			// ½Ì±Û´øÁ¯ Äù½ºÆ®ÀÇ °æ¿ì(±¸Ãâ Äù½ºÆ®ÀÇ °æ¿ì)
				{
					INDEX questIndex = m_iCurQuestIndex;
					BOOL isComplete = pQuestDD->IsQuestComplete();
					if( CQuestSystem::Instance().Remove( questIndex ) )
					{
						BOOL bDeleted = GAMEDATAMGR()->GetQuest()->DelQuestList(questIndex, isComplete);
						if(!bDeleted)//»¶³ª´Â°Å ¹æÁö¿ë
						{
							bDeleted = GAMEDATAMGR()->GetQuest()->DelQuestList(questIndex, !isComplete);
							ASSERTALWAYS("Somthing is wrong, client fail delete quest from list");
							if(!bDeleted)
							{
								ASSERTALWAYS("Somthing is wrong, unknown quest index");
							}
						}
					}
					pUIManager->GetQuestBookList()->RefreshQuestListNew();
					
					if(pUIManager->GetQuestBookComplete()->GetCurrIdx() == questIndex)
						pUIManager->GetQuestBookComplete()->close();
					CQuestSystem::Instance().SetQuestAllow(questIndex, CQuestSystem::QAT_ALLOW);
					
					if(startType == QSTART_NPC)
						ACTORMGR()->RefreshNPCQuestMark(startData);
					ACTORMGR()->RefreshNPCQuestMark(prizeNPCIndex);

					// FIXME : ÇÏµå ÄÚµùÇÑ ºÎºÐ.
					// Hardcoding
					_pNetwork->GoZone(0, 0);
				}			
			}			
		}
		break;
	case MSGCMD_QUEST_NOTIFY:
		break;
	case MSGCMD_QUEST_NEWQUEST:
		{
			CQuestDynamicData	*pQuestDD = CQuestSystem::Instance().GetDynamicDataByQuestIndex( m_iCurQuestIndex );
			if(pQuestDD)
			{
				if( pQuestDD->GetQuestType1() == QTYPE_KIND_SAVE || pQuestDD->GetQuestType1() == QTYPE_KIND_TUTORIAL || pQuestDD->GetQuestType1() == QTYPE_KIND_DEFEAT )			// ½Ì±Û´øÁ¯ Äù½ºÆ®ÀÇ °æ¿ì(±¸Ãâ Äù½ºÆ®ÀÇ °æ¿ì)
				{
					// ÀÏ´Ü ´øÁ¯À¸·Î ÀÌµ¿ ½ÃÅ°°í³ª¼­...
					// ¹«Á¶°Ç 0À¸·Î ÆÇ´ÜÇÔ.				
					const int iWorldNum = pQuestDD->GetConditionData(0, 0);						// ¿ùµå ¹øÈ£.
					const int iExtraNum = pQuestDD->GetConditionData(0, 1);						// Extra ¹øÈ£.
					//---- woos 060515 ------------------------------------->>
					FLOAT3D tv_pos = (m_fNpcX,0,m_fNpcZ);
					_pNetwork->GoZone(iWorldNum, iExtraNum,m_iNpcIndex);
					//------------------------------------------------------<<
					
				}				
			}
			m_iCurQuestIndex = -1;
		}
		break;

	case MSGCMD_WEAPONCHANGE_EVENT:		// ¹«±â ±³Ã¼ ÀÌº¥Æ®.
		if(bOK)
		{
			_pNetwork->SendChangeWeaponEvent();
		}
		break;

	case MSGCMD_ASK_ONE_FIVE:
		if(bOK){
		pUIManager->CloseMessageBox(MSGCMD_ASK_ONE_FIVE);
		_pNetwork->SendEvent24(1,MSG_EVENT_2PAN4PAN_MONEY_REQ);
		}
		break;
	case MSGCMD_ASK_ONE_FOUR:
		if(bOK){
		pUIManager->CloseMessageBox(MSGCMD_ASK_ONE_FOUR);
		_pNetwork->SendEvent24(2,MSG_EVENT_2PAN4PAN_MONEY_REQ);
		}
		break;
	case MSGCMD_ASK_TWO_OPEN:
		if(bOK){
		pUIManager->CloseMessageBox(MSGCMD_ASK_TWO_OPEN);
		_pNetwork->SendEvent24(0,MSG_EVENT_2PAN4PAN_GOODS_REQ);
		}
		break;
	case MSGCMD_ASK_NEWYEAR1:
		if(bOK)
		{			
			_pNetwork->SendEventNewyear(EVENT_NEWYEAR1_REWARD);
		}
		break;
	case MSGCMD_ASK_NEWYEAR2:
		if(bOK)
		{
			_pNetwork->SendEventNewyear(EVENT_NEWYEAR2_REWARD);
		}
		break;
	case MSGCMD_INPUT_FRIEND :
		if(bOK)
		{
			_pNetwork->SendFindFriend(MSG_EVENT_SEARCHFRIEND_ADD_CHECK,&strInput);

		}
		break;
	case MSGCMD_EVENT_COUPON_SENDNUM :
		if(bOK){
			_pNetwork->SendCouponItemReq(strInput);			
		}
		break;
	case MSGLCMD_EVENT_OXQUIZ:
		if(bOK)
		{
			_pNetwork->GoZone( 14, 0 ,254);
		}
		break;
	
	case MSGCMD_WORLDCUP_EVENT1_NUM:
		if(bOK)
		{				
			iSelCountry = iGroup[iSelGroup] + pUIManager->GetMessageBox(MSGCMD_WORLDCUP_EVENT1_NUM)->GetComboBox().GetCurSel();
			_pNetwork->SendWorldCupEvent( MSGCMD_WORLDCUP_EVENT1_EXCHANGE, iSelCountry );
		}
		break;
	case MSGCMD_COLLECTBOX_BUY_REQ:
		if(bOK)
		{
			_pNetwork->SendBuyCollectBox();
		}
		break;
	case MSGCMD_OK_EXCHANGE_CHOCOBOX:
	case MSGCMD_OK_EXCHANGE_LUCKYBOX:
		if (bOK)
		{
			CUIIcon* pIcon = pUIManager->GetMessageBox(nCommandCode)->GetBtnEx();

			if (pIcon != NULL)
			{
				_pNetwork->SendReqGiftChocoBox(pIcon->getIndex());
			}
		}
		break;
	case MSGCMD_GUILDMASTER_1:
		if(bOK) // µî·Ï
		{
			if(CheckGuildMasterEvent())
			{
				pUIManager->DoesMessageBoxExist(MSGCMD_GUILDMASTER_1_1);
				MsgBoxInfo.SetMsgBoxInfo( _S( 100, "ÀÌº¥Æ®" ), UMBS_OKCANCEL, UI_QUEST, MSGCMD_GUILDMASTER_1_1);
				strMessage.PrintF( _S(3469, "¼ÒÀ¯ÇÏ½Å »¡°£ Ä«³×ÀÌ¼ÇÀÌ »ç¶óÁö°í ±× °³¼ö¸¸Å­ ±æµå Æ÷ÀÎÆ®°¡ ¿Ã¶ó °©´Ï´Ù. ÁøÇàÇÏ½Ã°Ú½À´Ï±î?" ));
				MsgBoxInfo.AddString( strMessage );
				pUIManager->CreateMessageBox( MsgBoxInfo );
			}
			
		}
		else	// °»½Å	
		{
			_pNetwork->SendRequestParentsday( MSG_EVENT_PARENTSDAY_2007_ACCUMULATEPOINT_RANKING_LIST);
		}
		break;	
	case MSGCMD_GUILDMASTER_1_1:
		if(bOK)	// µî·Ï ¸Þ½ÃÁö
		{			
			_pNetwork->SendParentsdayAddPoint(_pNetwork->MyCharacterInfo.index);
		}		
		break;

	case MSGCMD_GUILDMASTER_2_1:
		if(bOK)
		{
			// ±³È¯±Ç ¹Þ±â
			_pNetwork->SendRequestParentsday( MSG_EVENT_PARENTSDAY_2007_EXCHANGE_TICKET);
		}
		break;

		///////////////////////////////////////////////////////////////////////////////////
		// [070705 :Su-won] EVENT_SUMMER_2007
	case MSGCMD_SUMMER2007_PAPERFOLDING:
		if(bOK)
		{
			CUIMessageBox* pMsgBox =pUIManager->GetMessageBox(MSGCMD_SUMMER2007_PAPERFOLDING);
			
			int nItemIndex0 = pMsgBox->GetBtnEx(0)->getIndex();
			int nItemIndex1 = pMsgBox->GetBtnEx(1)->getIndex();
			int nItemIndex2 = pMsgBox->GetBtnEx(2)->getIndex();

			_pNetwork->SendPaperFoldingReq( nItemIndex0, nItemIndex1, nItemIndex2);
		}
		else
			MsgBoxLCommand( MSGLCMD_EVENT, EVENT_SUMMER_2007 ); 

		break;
	case MSGCMD_SUMMER2007_PAPERBLENDING:
		if(bOK)
		{
			int nItemIndex =pUIManager->GetMessageBox(MSGCMD_SUMMER2007_PAPERBLENDING)->GetBtnEx(0)->getIndex();
			
			_pNetwork->SendPaperBlendingReq( nItemIndex );
		}
		else
			MsgBoxLCommand( MSGLCMD_EVENT, EVENT_SUMMER_2007 ); 
		break;
		// [070705 :Su-won] EVENT_SUMMER_2007
		///////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////
	// [070807: Su-won] EVENT_ADULT_OPEN
		//¼ºÀÎ¼­¹ö ¿ÀÇÂ ÀÌº¥Æ®: ¿¬±Ý¼ú ÀÌº¥Æ®
	case MSGCMD_ADULTEVENT_ALCHEMIST:
		{
			if(bOK)
			{			
				CUIIcon* pIcon = pUIManager->GetMessageBox(MSGCMD_ADULTEVENT_ALCHEMIST)->GetBtnEx();

				if (pIcon != NULL)
				{
					CItems* pItems = pIcon->getItems();

					if (pItems != NULL)
					{
						_pNetwork->SendAdultOpenEventReq(2, pItems->Item_Tab, pItems->InvenIndex);
					}
				}
			}
		}
		break;
		//'°ÅÄ§¾øÀÌ ½ð´Ù!' ÀÌº¥Æ®
	case MSGCMD_EVENT_SHOOT:
		{
			if(bOK)
			{
				CNetworkMessage nmMessage(MSG_EVENT);
				nmMessage << (UBYTE)MSG_EVENT_GIFT_2007;

				_pNetwork->SendToServerNew(nmMessage);
			}
		}
		break;
	// [070807: Su-won] EVENT_ADULT_OPEN
	///////////////////////////////////////////////////////
	case MSGCMD_BJMONO_2007_CHANGE_REQ:
		{
			if (bOK)
			{
				if (!(strInput.IsInteger()))
				{
					_pNetwork->ClientSystemMessage(_s("¼ýÀÚ¸¦ ÀÔ·ÂÇØ ÁÖ½Ã±â ¹Ù¶ø´Ï´Ù."));
					return;
				}

				const char* TempNum = strInput;
				int Num = atoi(TempNum);

				if (Num < 1 || Num > 6)
				{
					_pNetwork->ClientSystemMessage(_s("1~6ÀåÀÇ ÀÀ¸ð±Ç¸¸ ±³È¯ °¡´É ÇÕ´Ï´Ù."));
					return;
				}

				_pNetwork->SendBJMono2007Req(MSG_EVENT_BJMONO_2007_CHANGE_TICKET_REQ, Num);

				if ( pUIManager->DoesMessageBoxExist(MSGCMD_BJMONO_2007_CHANGE_REQ) )
					pUIManager->CloseMessageBox(MSGCMD_BJMONO_2007_CHANGE_REQ);
				
			}
		}
		break;
	case MSGCMD_TG2007_1000DAYS_CAP_UPGRADE:
		{
			if (bOK)
			{
				CUIIcon* pIcon = pUIManager->GetMessageBox(MSGCMD_TG2007_1000DAYS_CAP_UPGRADE)->GetBtnEx();

				if (pIcon != NULL)
				{
					CItems* pItems = pIcon->getItems();

					if (pItems != NULL)
					{
						_pNetwork->SendLC1000DayHatUpgradeReq((SWORD)pItems->InvenIndex, (LONG)pItems->Item_Index);
					}
				}
			}
		}
		break;
	case MSGCMD_EVENT_XMAS_2007_DECO:
		{
			if (bOK)
			{   // Å©¸®½º ¸¶½º Àå½Ä
				_pNetwork->SendXMAS2007DecoReq(MSG_EVENT_XMASTREE_ADD_POINT);
			}
		}
		break;
	case MSGCMD_EVENT_SAKURA_2008:
		{
			if(bOK)
			{
				if( pUIManager->GetInventory()->GetItemCount(2345) <=0 )
				{
					CUIMsgBox_Info MsgBoxInfo;
					MsgBoxInfo.SetMsgBoxInfo(_S(191, "È®ÀÎ"), UMBS_OK, UI_NONE, MSGCMD_NULL);

					MsgBoxInfo.AddString(_S(4114, "Åðºñ¸¦ °¡Áö°í ÀÖÁö ¾Ê½À´Ï´Ù."));
					pUIManager->CreateMessageBox(MsgBoxInfo);

					return;
				}

				CNetworkMessage nmMessage(MSG_EVENT);

				nmMessage << (UBYTE)MSG_EVENT_SAKURA_2008;
				nmMessage << (UBYTE)MSG_EVENT_SAKURAEVENT_2008;

				_pNetwork->SendToServerNew(nmMessage);
			}
		}
		break;
	// [080422: Su-won] EVENT_CHAOSBALL
	case MSGCMD_EVENT_CHAOSBALL:
		{
			if(bOK)
			{
				CUIIcon* pIcon = pUIManager->GetMessageBox(MSGCMD_EVENT_CHAOSBALL)->GetBtnEx();

				if (pIcon != NULL)
				{
					CItems* pItems = pIcon->getItems();

					if (pItems != NULL)
					{
						int tv_tab, tv_idx;

						tv_tab = pItems->Item_Tab;
						tv_idx = pItems->InvenIndex;
						int iUniIndex = pItems->Item_UniIndex;

						int nCheckIdx = _pNetwork->MySlotItem[tv_tab][tv_idx].Item_UniIndex;

						if (iUniIndex != pItems->Item_UniIndex)
						{
							pUIManager->GetMessageBox(MSGCMD_EVENT_CHAOSBALL)->GetBtnEx(0)->clearIconData();
							break;
						}

						CNetworkMessage nmMessage;
						RequestClient::doChaosBall* packet = reinterpret_cast<RequestClient::doChaosBall*>(nmMessage.nm_pubMessage);
						packet->type = MSG_EXTEND;
						packet->subType = htonl(MSG_EX_CHAOSBALL);
						packet->thirdType = 0;
						packet->tab = tv_tab;
						packet->invenIndex = tv_idx;
						nmMessage.setSize( sizeof(*packet) );

						_pNetwork->SendToServerNew(nmMessage);
					}
				}
			}
		}
		break;

		// [100208: selo] Äù½ºÆ® ¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â
	case MSGCMD_QUEST_RESTORE_ITEM:
		{
			if(bOK)
			{
				if( m_restoreQuestIndex != -1 )
				{
					_pNetwork->SendRestoreQuestItem( m_restoreQuestIndex );
				}
				else
				{
					_pNetwork->SendTakeAgainQuestItem();
				}
			}
		}
		break;
		// [100208: selo] Äù½ºÆ® ¾ÆÀÌÅÛ ´Ù½Ã ¹Þ±â °á°ú
	case MSGCMD_QUEST_RESTORE_ITEM_RESULT:
		break;

		// ($E_WC2010) [100518: selo] ¿ì½Â ±¹°¡ ÀçÀÀ¸ð ÇÏ±â
	case MSGCMD_EVENT_WORLDCUP_EVENT2_REREQ:
		{
			if(bOK)
			{
				CreateMessageBox_WorldCup2010_Event2(EVENT_WORLDCUP_2010_EVENT2_SEL1);
			}
		}
		break;

		// ($E_WC2010) [100518: selo] ¿ì½Â ±¹°¡ ÀÀ¸ð ÇÏ±â
	case MSGCMD_EVENT_WORLDCUP_EVENT2_REQ:
		{
			if(bOK)
			{
				CUIIcon* pIcon = pUIManager->GetMessageBox(MSGCMD_EVENT_WORLDCUP_EVENT2_REQ)->GetBtnEx();

				if (pIcon != NULL)
				{
					INDEX nItemIndex = pIcon->getIndex();
					_pNetwork->SendWorldCup2010_Event(MSG_EVENT_WORLDCUP2010_TOTO_REQ, nItemIndex);
				}
			}
		}
		break;
	case MSGCMD_REGISTER_MERCHANT:	// [2010/08/25 : Sora] ADD_SUBJOB
		{
			if(bOK)
			{
				_pNetwork->SendSubJobRegister( SUBJOB_MERCHANT );
			}
		}
		break;
	case MSGCMD_PROMOTION2_REQ :
		if(bOK){
			_pNetwork->SendPromotionEventReq(strInput);			
		}
		break;
	case MSGCMD_SOULOFSCALP_CONFIRM:
		{
			if (bOK)
			{
				_pNetwork->SendEventMsg(MSG_EVENT_AKAN_TEMPLE);
			}
		}
		break;
	case MSGCMD_COMEBACK_CONFIRM:
		{
			if (bOK)
			{
				_pNetwork->SendComebackMessage();
			}
		}
		break;
	case MSGCMD_BIRTHDAY_CONFIRM:
		{
			if (bOK)
			{
				_pNetwork->SendBirthdayMessage( EVENT_BIRTHDAY_GIFT );
			}
		}
		break;
	case MSGCMD_KB_EXCHAGE_HEART:	// [2011/11/14 : Sora] ÅÂ±¹ ±¹¿Õ Åº»ýÀÏ ÀÌº¥Æ®
		{
			if (bOK)
			{
				_pNetwork->SendKBRewardReq( 0 );
			}
		}
		break;
	case MSGCMD_KB_EXCHAGE_FLAG:	// [2011/11/14 : Sora] ÅÂ±¹ ±¹¿Õ Åº»ýÀÏ ÀÌº¥Æ®
		{
			if (bOK)
			{
				_pNetwork->SendKBRewardReq( 1 );
			}
		}
		break;
	case MSGCMD_SYNDICATE_PUTON_JEWEL_REQ:
		{
			if (pEntity == NULL ||
				pEntity->IsEnemy() == FALSE)
			{
				UIMGR()->GetChattingUI()->AddSysMessage(_S(6312, "NPC¿Í ´ëÈ­ÁßÀÌ ¾Æ´Õ´Ï´Ù."), SYSMSG_ERROR);			
				return;
			}

			if (bOK)
			{	// °á»ç´ë º¸¼® ±âºÎ ¸Þ½ÃÁö.
				GameDataManager* pGameData = GameDataManager::getSingleton();

				if (pGameData == NULL)
					break;

				CSyndicate* pSyndicateData = pGameData->GetSyndicate();

				if (pSyndicateData == NULL)
					break;

				CUIIcon* pIcon = pUIManager->GetMessageBox(MSGCMD_SYNDICATE_PUTON_JEWEL_REQ)->GetBtnEx();

				if (pIcon != NULL)
				{
					CItems* pItems = pIcon->getItems();

					if (pItems != NULL)
					{
						INDEX nItemUniIndex = pItems->Item_UniIndex;

						pSyndicateData->SendGiveJewel(lNpcVIndex, nItemUniIndex);
					}
				}
			}
		}
		break;
	case MSGCMD_SYNDICATE_SECESSION_REQ:
		{
			if (pEntity == NULL ||
				pEntity->IsEnemy() == FALSE)
			{
				UIMGR()->GetChattingUI()->AddSysMessage(_S(6312, "NPC¿Í ´ëÈ­ÁßÀÌ ¾Æ´Õ´Ï´Ù."), SYSMSG_ERROR);			
				return;
			}

			if (bOK)
			{
				GameDataManager* pGameData = GameDataManager::getSingleton();

				if (pGameData == NULL)
					break;

				CSyndicate* pSyndicateData = pGameData->GetSyndicate();

				if (pSyndicateData == NULL)
					break;

				int nTab = -1;
				int nInvenIndex = -1;

				CUIIcon* pIcon = pUIManager->GetMessageBox(MSGCMD_SYNDICATE_SECESSION_REQ)->GetBtnEx();

				if (pIcon != NULL)
				{
					CItems* pItems = pIcon->getItems();

					if (pItems != NULL)
					{
						nTab = pItems->Item_Tab;
						nInvenIndex = pItems->InvenIndex;
					}
				}

				pSyndicateData->SendSecession(lNpcVIndex, nTab, nInvenIndex);
			}
		}
		break;
	}
}

// ----------------------------------------------------------------------------
// Name : QuestError()
// Desc :
// ----------------------------------------------------------------------------
void CUIQuest::QuestError( UBYTE ubError )
{
	CUIManager* pUIManager = CUIManager::getSingleton();
	CTString	strMessage;
	
	switch(ubError)
	{
	case MSG_QUEST_ERR_START_ONCE:		// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : ÀÌ¹Ì ¼öÇàÇÑ 1È¸¿ë Äù½ºÆ®
		strMessage = _S( 590, "ÇØ´ç Äù½ºÆ®´Â ÀÌ¹Ì ¼öÇàÇÑ Äù½ºÆ®ÀÔ´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_START_ALREADY:	// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : ÀÌ¹Ì ¼öÇàÁßÀÓ
		strMessage = _S( 591, "ÀÌ¹Ì ¼öÇàÁßÀÎ Äù½ºÆ®ÀÔ´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_START_LEVEL:		// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : ·¹º§ Á¶°Ç ¾È¸ÂÀ½
		strMessage = _S( 592, "·¹º§ Á¶°ÇÀÌ ¸ÂÁö ¾Ê¾Æ¼­ Äù½ºÆ®¸¦ ½ÃÀÛÇÒ ¼ö ¾ø½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_START_JOB:		// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : Á÷¾÷ Á¶°Ç ¾È¸ÂÀ½
		strMessage = _S( 593, "Á÷¾÷ Á¶°ÇÀÌ ¸ÂÁö ¾Ê¾Æ¼­ Äù½ºÆ®¸¦ ½ÃÀÛÇÒ ¼ö ¾ø½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_START_ITEM:		// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : ¾ÆÀÌÅÛ Á¶°Ç ¾È¸ÂÀ½
		strMessage = _S( 594, "¾ÆÀÌÅÛ Á¶°ÇÀÌ ¸ÂÁö ¾Ê¾Æ¼­ Äù½ºÆ®¸¦ ½ÃÀÛÇÒ ¼ö ¾ø½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_START_MAX:		// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : ÃÖ´ë ¼öÇà °¡´É ¼ö ÃÊ°ú
		strMessage = _S( 595, "¼öÇà °¡´ÉÇÑ Äù½ºÆ® È½¼ö¸¦ ÃÊ°úÇß½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_START_FULL:		// Äù½ºÆ® ½ÃÀÛ½Ã ¿¡·¯ : ½Ì±Û´øÀüÀÇ °æ¿ì ½Ì±Û´øÀü ²ËÂü
		strMessage = _S( 596, "½Ì±Û´øÁ¯ÀÌ È¥ÀâÇÏ¿© Äù½ºÆ®¸¦ ½ÃÀÛÇÒ ¼ö ¾ø½À´Ï´Ù" );		
		break;
	case MSG_QUEST_ERR_DELIVERY_FULL:	// Àü´Þ Äù½ºÆ® ½Ã : ÀÎº¥Åä¸®°¡ ²ËÂ÷¼­ ¾ÆÀÌÅÛ Äù½ºÆ® ¿¡·¯
		strMessage = _S( 597, "ÀÎº¥Åä¸®°¡ ²Ë Â÷¼­ Äù½ºÆ®¸¦ ½ÃÀÛÇÒ ¼ö ¾ø½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_PRIZE_FULL:		// º¸»ó ¹ÞÀ»¶§ ÀÎº¥ ²Ë Â÷¼­ º¸»ó ½ÇÆÐ
		strMessage = _S( 598, "ÀÎº¥Åä¸®°¡ ²Ë Â÷¼­ º¸»óÀ» ¹ÞÀ» ¼ö ¾ø½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_PRZIE_ITEM:		// º¸»ó ¹ÞÀ»¶§ ¾ÆÀÌÅÛ ¶§¹®¿¡ ¿À·ù
		strMessage = _S( 599, "¾ÆÀÌÅÛ Á¶°ÇÀÌ ¸ÂÁö ¾Ê¾Æ º¸»óÀ» ¹ÞÀ» ¼ö ¾ø½À´Ï´Ù." );		
		break;
	case MSG_QUEST_ERR_PET_NOT_HAVE_ONEMORE:
		{
			strMessage = _S(2221,"ÆêÀ» ´õ ÀÌ»ó ¼ÒÀ¯ÇÒ ¼ö ¾ø½À´Ï´Ù.");
			pUIManager->GetQuestBookComplete()->close();
		}
		break;
	case MSG_QUEST_ERR_NOT_EXIST_ABANDON_QUEST:		// [100208: selo] Æ÷±â Äù½ºÆ® º¹±¸ ½ÇÆÐ
		strMessage = _S(4816,"ÇöÀç ·¹º§¿¡ ¸Â´Â Æ÷±âÇÑ Äù½ºÆ®°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù. ´Ù½Ã È®ÀÎ ÈÄ ½ÃµµÇÏ½Ã±â ¹Ù¶ø´Ï´Ù.");
		break;
	case MSG_QUEST_ERR_DONT_HAVE_NAS:				// [100208: selo] Æ÷±â Äù½ºÆ® º¹±¸ ½ÇÆÐ
		strMessage = _S(4817,"³ª½º°¡ ºÎÁ·ÇØ¼­ Æ÷±â Äù½ºÆ®¸¦ º¹±¸ÇÒ ¼ö ¾ø½À´Ï´Ù.");
		break;
	case MSG_QUEST_ERR_DONT_HAVE_SPACE:				// ALEX QUEST SPACE
		strMessage = _S(10071, "ÀÎº¥Åä¸®°¡ ²Ë Â÷¼­ º¸»óÀ» ¹ÞÀ» ¼ö ¾ø½À´Ï´Ù." );
		break;
	case MSG_QUEST_ERR_CHECK_DONE_ING:
		{
			pUIManager->SetCSFlagOff(CSF_TELEPORT);
			strMessage = _S(6311, "Äù½ºÆ® ¿Ï·á°¡ ¾Æ´Ï°Å³ª ÁøÇàÁßÀÌ ¾Æ´Õ´Ï´Ù.");
		}
		break;
	}

	// Close message box of remission
	pUIManager->CloseMessageBox( MSGCMD_QUEST_NOTIFY );
	pUIManager->CloseMessageBox( MSGCMD_QUEST_NEWQUEST );
		
	// Create message box of remission
	CUIMsgBox_Info	MsgBoxInfo;
	MsgBoxInfo.SetMsgBoxInfo( _S( 99, "Äù½ºÆ®" ), UMBS_OK,			
								UI_QUEST, MSGCMD_QUEST_NOTIFY );
	MsgBoxInfo.AddString( strMessage );
	pUIManager->CreateMessageBox( MsgBoxInfo );
}
