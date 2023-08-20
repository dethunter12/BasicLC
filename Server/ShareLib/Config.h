/************************************
  ????
  ??? ??: bs
  ???: 2004-11-19 ?? 8:02:59
  ??: ?? ?? ?? ??, ?? ?? - ?? ?? ??
 ************************************/

#ifndef __GAME_Config_H__
#define __GAME_Config_H__

// ??? ?? : MAKEFILE??
//#define LC_KOR		0	// ??
//#define LC_TLD			4	// ??
//#ifdef LC_TLD
//#endif // LC_TLD
//#define	LC_USA			9	// ??
//#define	LC_BRZ			10	// ???

//#define	LC_GER			13  // ??

#if defined (LC_KOR)
#define LC_LOCAL_STRING "KOR"
#define LC_LOCAL_CODE		LC_KOR
#elif defined (LC_TLD)
#define LC_LOCAL_STRING "TLD"
#define LC_LOCAL_CODE		LC_TLD
#elif defined (LC_USA)
#define LC_LOCAL_STRING "USA"
#define LC_LOCAL_CODE		LC_USA
#elif defined (LC_BRZ)
#define LC_LOCAL_STRING "BRZ"
#define LC_LOCAL_CODE		LC_BRZ
#elif defined (LC_GER)
#define LC_LOCAL_STRING "DE"
#define LC_LOCAL_CODE		LC_GER
#elif defined (LC_FRC)
#define LC_LOCAL_STRING "FR"
#define LC_LOCAL_CODE		LC_FRC
#elif defined (LC_PLD)
#define LC_LOCAL_STRING "PD"
#define LC_LOCAL_CODE		LC_PLD
#elif defined (LC_SPN)
#define LC_LOCAL_STRING "ES"
#define LC_LOCAL_CODE		LC_SPN
#elif defined (LC_RUS)
#define LC_LOCAL_STRING "RUS"
#define LC_LOCAL_CODE		LC_RUS
#elif defined (LC_TUR)
#define LC_LOCAL_STRING "TR"
#define LC_LOCAL_CODE		LC_TUR
#elif defined (LC_ITA)
#define LC_LOCAL_STRING "IT"
#define LC_LOCAL_CODE		LC_ITA
#elif defined (LC_MEX)
#define LC_LOCAL_STRING "MEX"
#define LC_LOCAL_CODE		LC_MEX
#elif defined (LC_UK)
#define LC_LOCAL_STRING "UK"
#define LC_LOCAL_CODE		LC_UK
#else
#error "Not Set Language"
#endif // #if defined (LC_KOR)
// --- ??? ??

//#define		BLOCK_PVP					// TODO : PVP ???? ?? ??

#define SERVER_VERSION			600		// ?? ?? ??
#define SERVER_MIN_VERSION		600		// ???, ????? ???? ?? ?? ??
#define SERVER_MAX_VERSION		700		// ???, ????? ???? ?? ?? ??
#define CONNECTOR_SERVER_NUM	888		// ??? ?? ??
#define LOGIN_SERVER_NUM		999		// ??? ?? ??
#define MESSENGER_SERVER_NUM	777		// ??? ?? ??
#define BILL_SERVER_VERSION		"BillCruxV40" // ???? ???? ??
#define		GAMEID				1		// ?? ?? ??? 1?

#define BILL_LOCATION_HOME		0		// ??
#define	BILL_LOCATION_PCBANG	1		// ??? pc?

#define PCBANG_LOGIN			10		// pc? ???
#define PCBANG_LOGOUT			11		// pc? ?? ??

#define LOGIN_SERVER_OPEN_CHECK_FILENAME	"login.open"		// ??? ?? ?? ?? ???

//#define		GAMEID				1 // ?? ???? ?? ??
#define		CPID				1
#define		ID_LENGTH			32
#define		MAX_PURCHASEITEM	16
#define		MAX_DEPOSITORY		25

#define	PLAYER_COUNT_NUM		9999	// ???? ?? ???? ??

#define NUM_RESERVED_DESCS		5		// ????? ??? ????? ?
#define MAX_PLAYING				50000	// ?? ?? ?
#define MAX_ZONES				46		// dethunter12 modifcation
#define MAX_NOTICE				5

#define PI       3.14159265358979323846f
#define PI_2     6.28318530717958623200f
#define PI_3_4	 2.35619449019234492884f	/* ((3 / 4) * PI) */
#define PI_HALF	 (PI / 2)

// ?? ??
#ifdef __GAME_SERVER__
#define OPT_USEC		100000				/* 10 passes per second */
#else
#define OPT_USEC		50000				/* 20 passes per second */
#endif
#define PASSES_PER_SEC	(1000000 / OPT_USEC)
#define RL_SEC			* PASSES_PER_SEC
#define RL_OCLOCK			3600				// ?? ??.
#define RL_24CLOCK			86400				// ?? 24?
// ?? ???? ??
#define PULSE_REAL_SEC				(1 RL_SEC)				// ?? 1?
#define PULSE_REAL_MIN				(60 RL_SEC)				// ?? 1?
#define PULSE_REAL_TENMIN			(600 RL_SEC)			// ?? 10?
#define PULSE_REAL_HALF				(1800 RL_SEC)			// ?? 30?
#define	PULSE_REAL_HOUR				(3600 RL_SEC)			// ?? 1??
#define PULSE_REAL_24HOUR			(86400 RL_SEC)

#define PULSE_PCROOM_COUNT			(3 * PULSE_REAL_MIN)	// ??? ??? ? ??? ??
#define PULSE_TOTAL_COUNT			PULSE_REAL_MIN			// ?? ?? ? ??? ??
#define PULSE_NPC_AI				2						// NPC ?? AI ?? ?? : 0.5?
#define	PULSE_NPC_REGEN				(15 RL_SEC)				// NPC ?? ?? ?? ?? : ?? 30?
#define PULSE_WARPDELAY				(5 * TIME_ONE_SECOND)	// ???? ??? : 10?
#define PULSE_BILLITEMREQ			(20 * TIME_ONE_SECOND)	// ????? ?? ?? ?? 20?  ???? ??? ?? ??.
#define PULSE_BILLITEMLISTREQ		(4 * PULSE_REAL_SEC)	// ????? ??? ?? ?? ?? ???? ??? ?? ??.
#define PULSE_WARPCOUNTDOWN			(5 * PULSE_REAL_SEC)	// ???? ??? ?? ?? : 5? ???
#define PULSE_ASSIST_CHECK			PULSE_REAL_SEC			// ???? ?? ?? ?? ???
#define PULSE_HACK_CHECK_TIMEOUT	(6 * PULSE_REAL_MIN)	// ?? ??? ???? 6?
#define PULSE_HACK_PULSE_REFRESH	PULSE_REAL_HOUR			// ? ?? ?? ?? ?? 1??
#define PULSE_HACK_PULSE_THRESHOLD	(15 * PULSE_REAL_SEC)	// ? ?? ?? ?? 15?
#define PULSE_HACK_CLIENT_THRESHOLD	(55 * PULSE_REAL_SEC)	// ? ?? ????? ?? ?? 55? ??? ?? ??? ??!
#define PULSE_PKMODE_DELAY			10		 				// PK???? ????? ??? ???
#define PULSE_HACK_ATTACK_THRESHOLD	2						// ?? ?? ?? ??
#define	PULSE_HACK_ATTACK_COUNT		5						// ?? ???? ??? ??
#define PULSE_ATTACKMODE_DELAY		(3 * PULSE_REAL_SEC)	// ?? ?? ??? ??? : ??? ???? ? ????? ?? ???
#define PULSE_POST_REGEN_DELAY		(3 * PULSE_REAL_SEC)	// ???? ???? ??? ???
#define PULSE_PRODUCE_DELAY			(2 * PULSE_REAL_SEC)	// ?? ???
#define PULSE_PET_SYMPATHY_INCREASE	(5 * PULSE_REAL_MIN)	// ? ??? ?? ???
#define PULSE_PET_SYMPATHY_DECREASE	(PULSE_REAL_HOUR)		// ? ??? ?? ???
#define PULSE_PET_HUNGRY_DECREASE	(5 * PULSE_REAL_MIN)	// ? ??? ???
#define PULSE_AUTO_SKILL_DECREASE	(10 * TIME_ONE_SECOND)	// ?? ?? ?? ??
#define PULSE_KEY_CHANGE_THRESHOLD	(10 * PULSE_REAL_SEC)	// ? ?? ?? ?? : 10 ?
#define PULSE_KEY_CHANGE			(20 * PULSE_REAL_SEC)	// ? ?? ?? : 20 ?
#define	PULSE_SERVER_ALIVE			(2 * PULSE_REAL_MIN)	// ?? ?? ???? ??? ??
#define	PULSE_PCBANG_ITEM			(PULSE_REAL_HOUR)		// ??? PC??? ??? ?? ??
#define PULSE_SAVECOUNT_NEW				5					// ???? ?? ???? ? ?? ??
#define PULSE_SAVEMAXCOUNT_NEW			2					// ???? ?? ?? ???? ? ?? ??
#define PULSE_TRIGGER_SYSTEM		(4 * PULSE_REAL_SEC)	// ??? proc ?? ??\
 
#define TIME_ONE_SECOND				1						// 1?
#define TIME_ONE_MIN				60						// 1?
#define TIME_ONE_HOUR				60 * 60					// 1??
#define TIME_ONE_DAY				TIME_ONE_HOUR * 24		// 1?
#define TIME_ONE_WEEK				TIME_ONE_DAY * 7		// 1??
#define TIME_ONE_MONTH				TIME_ONE_DAY * 30		// 30?

#define MAX_ID_NAME_LENGTH			64		// ???, ?? ??
#define MAX_PWD_LENGTH				32		// ?? ??
#define HOST_LENGTH					30		// ??? ?? ??? ??
#define MAX_CHAR_NAME_LENGTH		50		// ??? ?? ??
#define MAX_GUILD_NAME_LENGTH		50		// ?? ?? ??
#define MAX_ITEM_NAME_LENGTH		50		// ??? ????
#define FRIEND_MAX_MEMBER			100		// ?? ?? ?
#define	FRIEND_GROUP_MAX_NUMBER		10		// ?? ?
#define MAX_GROUP_NAME_LENGTH		20		// ?? ?? ??
#define BLOCK_MAX_MEMBER			20		// ?? ?? ???
#define	MAX_GIFT_MESSAGE_LENGTH		100		// ?? ??? ?? 100???

// ???? ???? ????, CServer? Run??? ??!!!
#define MAX_STRING_LENGTH		8192

// ?? ?? ??
#define CON_PLAYING						0		// ?? ?
#define CON_CLOSE						1		// ?? ??
#define CON_MOVESERVER					2		// ?? ???
#define CON_MOVESERVER_WAIT				3		// ?? ???
#define CON_WAIT_SCARD					4		// ?? ?? ?? ?
#define CON_MENU						10		// ????? ??
#define CON_DISCONNECT					17		// ??? ?? ??
#define CON_WAIT_USER_DB				19		// ??? ??? ???
#define CON_WAIT_NEW_CHAR_DB			20		// ??? ?? ???
#define CON_WAIT_DEL_CHAR_DB			21		// ??? ?? ???
#define CON_WAIT_PLAY_CHAR_DB			22		// ??? ?? ?? ???
#define CON_GET_LOGIN					23		// ??? ??
#define CON_PREPARE_PLAY				25		// ?? ?? ???
#define CON_PREPARE_PLAY_BEFORE			26		// ??? ?? ??
#define CON_WAIT_IDEN_MSG				30		// ?? ???
#define CON_GET_IDEN_MSG				31		// ?? ??
#define CON_GET_DUMMY					32		// ??? ???

#define STATE(d)			((d)->m_connected)
#define WAITTING_DB(d)		((d)->m_bwaitdb)
#define UPDATING_DB(d)		((d)->m_updatedb)
#define PLAYMODE(d)			((d)->m_playmode)

// ?? ?? ???, ???? ??, ????? ??
//??? class CUser? m_userFlag
#define NOVICE					( 1 << 0 )
#define	RECV_GIFT				( 1 << 1 )
#define ADULT					( 1 << 2 )
#define IS_CHARACTER			( 1 << 3 )
#define IS_NEWUSER_JPN_2007_03	( 1 << 4 )
#define IS_GM_CHAR				( 1 << 5 )

/////////////////////////////////////////////////////////////////////////////
// ??? ??
#include "Config_Localize.h"
// ---- ??? ??
/////////////////////////////////////////////////////////////////////////////

// ?????
#define MAX_SKILLPOINT		2000000000000

// ??? ??
#ifdef EX_ROGUE
#define JOBCOUNT			9
#else
#define JOBCOUNT			7
#endif // EX_ROGUE
#define JOB_TITAN			0
#define JOB_KNIGHT			1
#define JOB_HEALER			2
#define JOB_MAGE			3
#define JOB_ROGUE			4
#define JOB_SORCERER		5
#define JOB_NIGHTSHADOW		6
#ifdef EX_ROGUE
#define JOB_EX_ROGUE		7
#endif // EX_ROGUE
#ifdef EX_MAGE
#define JOB_EX_MAGE			8
#endif

#define JOB_PET				10
#define JOB_APET			11

#ifdef EX_ROGUE
#ifdef EX_MAGE
#define JOB2COUNT			17
#else
#define JOB2COUNT			15
#endif
#else
#define JOB2COUNT			13
#endif // EX_ROGUE

#define JOB_2ND_SPLIT_INDEX	2

#define JOB_2ND_HIGHLANDER			1		// ????
#define	JOB_2ND_WARMASTER			2		// ????

#define JOB_2ND_ROYALKNIGHT			1		// ?????
#define	JOB_2ND_TEMPLEKNIGHT		2		// ?????

#define JOB_2ND_ARCHER				1		// ??
#define	JOB_2ND_CLERIC				2		// ???

#define JOB_2ND_WIZARD				1		// ???
#define	JOB_2ND_WITCH				2		// ??

#define JOB_2ND_ASSASSIN			1		// ???
#define	JOB_2ND_RANGER				2		// ???

#define JOB_2ND_ELEMENTALLIST		1		// ???? ???
#define JOB_2ND_SPECIALLIST			2		// ??? ???

#define JOB_2ND_NIGHTSHADOW			1		// ??? ???
#define JOB_2ND_NIGHTSHADOW2		2		// Dummy ????

#define JOB_2ND_EX_ASSASSIN			1		// EX ???
#define JOB_2ND_EX_RANGER			2		// EX ???

#define JOB_2ND_EX_WIZARD			1		// EX ???
#define JOB_2ND_EX_WITCH			2		// EX ??

#define JOB_2ND_PET_HORSE			0	// ?
#define JOB_2ND_PET_DRAGON			1	// ?
#define JOB_2ND_PET_HORSE_MOUNT		2	// ? : ??
#define JOB_2ND_PET_DRAGON_MOUNT	3	// ? : ??

#define JOB_2ND_LEVEL			31		// ?? ??

#define JOB_SUB_TRADER			( 1 << 0 )		// ??? ??

// ??? flag
#define CHAT_FLAG_NO_SAY		(1 << 0)		// ?? ?? ??
#define CHAT_FLAG_NO_PARTY		(1 << 1)		// ?? ?? ??
#define CHAT_FLAG_NO_GUILD		(1 << 2)		// ?? ?? ??
#define CHAT_FLAG_NO_TRADE		(1 << 3)		// ?? ?? ??
#define CHAT_FLAG_NO_WHISPER	(1 << 4)		// ??? ??
#define CHAT_FLAG_NO_SHOUT		(1 << 5)		// ??? ??
#define CHAT_FLAG_NO_EXPED		(1 << 6)		// ??? ?? ??

#define CHAT_MESSAGE_MAX		(250)

// ?? ?? ??
#define HAIR_TITAN			5
#define HAIR_KNIGHT			5
#define HAIR_HEALER			5
#define HAIR_MAGE			5
#define HAIR_ROGUE			5
#define HAIR_SORCERER		5
#define HAIR_NIGHTSHADOW	5
#define HAIR_EX_LOG			5
#define HAIR_EX_MAGE		5

#define HAIR_RED_CAP		10			// ?? ?? ??
#define HAIR_GREEN_CAP		20			// ?? ?? ??

// ?? ?? ??
#define FACE_TITAN			5
#define FACE_KNIGHT			5
#define FACE_HEALER			5
#define FACE_MAGE			5
#define FACE_ROGUE			5
#define FACE_SORCERER		5
#define FACE_NIGHTSHADOW	5
#define FACE_EX_ROGUE		5
#define FACE_EX_MAGE		5

// ?????? ?? ??
#define DB_NOP					0		// DB No Operation...
#define DB_UPDATE				1		// Request DB Update...
#define DB_WAIT_SAVE			10		// Save Delay...
#define DB_END					11		// ?? ??? ???? ??

// ?? ??? ??
#define	MAX_CHAR_COUNT			8		// ?? ?? ?? ??? ?
#define MAX_SKILL				60		// ??? ? ?? ?? ??
#define MAX_ASSIST_HELP			44		// ???? ??? : ???? ??
#define MAX_ASSIST_CURSE		16		// ???? ??? : ???? ??
#define MAX_ASSIST_ABS			44		// ???? ?d? ???????
#define MAX_EXT_CHAR_COUNT		2		// ??????? ?? ?? ?? ???

///////
// ??
#define NO_CELL				(-100)		// ?? ?? ?? ??
#define EPSILON				(1.0e-5f)	// Tolerance for FLOATs
#define CELL_SIZE			12.0f		// ? ?? attr ?? (m ??)

#define CELL_EXT			5			// ?????? ??g?? ?? ????

#define MULTIPLE_HEIGHTMAP	100.0f		// ??? ???? ??
#define MAX_PLAYER_LIST		8192		// ?? ?? ??? ?
#define MAX_MEMPOS					50			//15->50
#define MAX_MEMPOS_NORMAL			25			//10->25

#define ATTACK_TYPE_NORMAL			0			// ????
#define ATTACK_TYPE_DOUBLE			2			// ???? ( ????? 2? ?? )
#define ATTACK_TYPE_INFINITY		10			// ???? ( ???? ?? )

///////////////////
// NPC ??
#define		MAX_NPC_SKILL			4
#define		MAX_NPC_DROPITEM		20
#define		MAX_NPC_PRODUCT			5
#define		MAX_NPC_DROPITEM_LOOP	4
#define		MAX_NPC_DROPJEWEL		20

// NPC FLAG --
#define		NPC_SHOPPER				(1 << 0)	// ???????
#define		NPC_FIRSTATTACK			(1 << 1)	// ?????
#define		NPC_ATTACK				(1 << 2)	// ?????
#define		NPC_MOVING				(1 << 3)	// ?????
#define		NPC_PEACEFUL			(1 << 4)	// ???? ?(????? ?? ? ???)
#define		NPC_ZONEMOVER			(1 << 5)	// ? ?????? NPC
#define		NPC_CASTLE_GUARD		(1 << 6)	// ???
#define		NPC_REFINER				(1 << 7)	// ???? NPC
#define		NPC_QUEST				(1 << 8)	// Quest NPC
#define		NPC_CASTLE_TOWER		(1 << 9)	// ??? ???
#define		NPC_MINERAL				(1 << 10)	// ???
#define		NPC_CROPS				(1 << 11)	// ???
#define		NPC_ENERGY				(1 << 12)	// ???
#define		NPC_ETERNAL				(1 << 13)	// ??
#define		NPC_LORD_SYMBOL			(1 << 14)	// ??? ??
#define		NPC_REMISSION			(1 << 15)	// ???
#define		NPC_EVENT				(1 << 16)	// ???
#define		NPC_GUARD				(1 << 17)	// ???
#define		NPC_KEEPER				(1 << 18)	// ??
#define		NPC_GUILD				(1 << 19)	// ??
#define		NPC_MBOSS				(1 << 20)	// ???
#define		NPC_BOSS				(1 << 21)	// ??
#define		NPC_RESETSTAT			(1 << 22)	// ?? ???
#define		NPC_CHANGEWEAPON		(1 << 23)	// ?? ??
#define		NPC_WARCASTLE			(1 << 24)	// ?? NPC
#define		NPC_DISPLAY_MAP			(1 << 25)	// ??? ????? ??
#define		NPC_QUEST_COLLECT		(1 << 26)	// ?? ????
#define		NPC_PARTY				(1 << 27)	// ??? ???
#define		NPC_RAID				(1 << 28)	// ??? ?
#define		NPC_SUBCITY				(1 << 29)	// ?? ?? NPC
#define		NPC_CHAOCITY			(1 << 30)	// ???? ?? ?? NPC
#define		NPC_HUNTERCITY			(1 << 31)	// ???? ?? ?? NPC

// NPC FLAG1(??) --
#define		NPC1_TRADEAGENT			(1 << 0)	// ????(??) ???
#define		XXX_NPC1_COLLSION			(1 << 1)	// ??? ???? ??? ??? NPC
#define		NPC1_FACTORY			(1 << 2)	// ?? ??? NPC
#define		NPC1_TRIGGER_CHOICE		(1 << 3)	// NPC? ???? ??? ??
#define		NPC1_TRIGGER_KILL		(1 << 4)	// NPC? ??? ??? ??
#define		NPC1_NOT_NPCPORTAL		(1 << 5)	// NPCPORTAL ??? ???? ???? ??? ??? ??
#define		NPC1_DONT_ATTACK		(1 << 6)	// ?? npc? ??? ?? ???.
#define		NPC1_AFFINITY			(1 << 7)	// ???
#define		NPC1_SHADOW				(1 << 8)	// ??? ?? ( ??? ???? ???? ?? )
#define		NPC1_CRAFTING			(1 << 9)	// ??2 ?? ??? npc
#define		NPC1_TOTEM_ITEM			(1 << 10)	// ????? ?? ?? ??

// NPC AI TYPE
#define		NPC_AI_NORMAL			0			// ?? NPC
#define		NPC_AI_TANKER			1			// ?? NPC
#define		NPC_AI_DAMAGEDEALER		2			// ?? NPC
#define		NPC_AI_HEALER			3			// ?? NPC

#define IS_NPC(ch)			(ch->m_type == MSG_CHAR_NPC)	// NPC ????
#define TO_NPC(ch)			((ch == NULL) ? NULL : (IS_NPC(ch) ? (CNPC*)ch : (CNPC*)NULL))		// NPC? ???
#define IS_PC(ch)			(ch->m_type == MSG_CHAR_PC)		// PC ????
#define TO_PC(ch)			((ch == NULL) ? NULL : (IS_PC(ch) ? (CPC*)ch : (CPC*)NULL))			// PC? ???
#define IS_PET(ch)			(ch->m_type == MSG_CHAR_PET)	// ???????
#define TO_PET(ch)			((ch == NULL) ? NULL : (IS_PET(ch) ? (CPet*)ch : (CPet*)NULL))		// Pet? ???

#define IS_APET(ch)			(ch->m_type == MSG_CHAR_APET)
#define TO_APET(ch)			((ch == NULL) ? NULL : (IS_APET(ch) ? (CAPet*)ch : (CAPet*)NULL))		// AttackPet? ???

#define IS_ELEMENTAL(ch)	(ch->m_type == MSG_CHAR_ELEMENTAL)	// ??? ???
#define TO_ELEMENTAL(ch)	((ch == NULL) ? NULL : (IS_ELEMENTAL(ch) ? (CElemental*)ch : (CElemental*)NULL)) // ???? ???
#define GET_CHAR_TYPE(ch)	((char)(ch->m_type))
#define DEAD(ch)			(ch->m_hp <= 0)					// ??? ?????
#define IS_IN_CELL(ch)		(ch->m_cellX >= 0)				// ???? ?? ??? ????

#define CMD_NUM 200						// ?? ??? ?? ?

#define GET_X(obj)			(obj->m_pos.m_x)
#define GET_Z(obj)			(obj->m_pos.m_z)
#define GET_H(obj)			((obj && obj->m_pArea) ? obj->m_pArea->GetHeight(GET_YLAYER(obj), GET_X(obj), GET_Z(obj)) : 0.0f)
#define GET_R(obj)			(obj->m_pos.m_r)
#define GET_YLAYER(obj)		(obj->m_pos.m_yLayer)

// ??? ??
#define	MATT_WALKABLE			0x0001
#define	MATT_PEACE				0x0002
#define	MATT_PRODUCT_PUBLIC		0x0004
#define	MATT_PRODUCT_PRIVATE	0x0008
#define	MATT_STAIR_UP			0x0010
#define	MATT_STAIR_DOWN			0x0020
#define	MATT_WAR				0x0040
#define	MATT_FREEPKZONE			0x0080

#define	MATT_UNWALKABLE			0x8000

///////////////////
// ??? ?? ??

// 050311 : bs : ??? ???? ??? ?? ?? ??
#define USING_STR		0
#define USING_DEX		1
#define USING_INT		2
// --- 050311 : bs : ??? ???? ??? ?? ?? ??
// ?? ??
// category
#define		CATEGORY_HOTNNEW							10000
#define		CATEGORY_PLATINUM							20000
#define		CATEGORY_DISPOSABLE							30000
#define		CATEGORY_COSTUME							40000
#define		CATEGORY_PET								50000
#define		CATEGORY_SERVICE							60000
#define		CATEGORY_PACKAGE							70000
// type
#define		TYPE_HOTNNEW_NONE							10000	//TYPE ???
#define		TYPE_HOTNNEW_NEW							10100
#define		TYPE_HOTNNEW_DISCOUNT						10200
#define		TYPE_HOTNNEW_HOT							10300
#define		TYPE_PLATINUM_NONE							20000
#define		TYPE_DISPOSABLE_NONE						30000
#define		TYPE_DISPOSABLE_CHARACTER_GROW				30100
#define		TYPE_DISPOSABLE_ABILITY_BUILDUP				30200
#define		TYPE_DISPOSABLE_POTION						30300
#define		TYPE_EQUIP_NONE								40000
#define		TYPE_EQUIP_EQUIPMENT						40100
#define		TYPE_EQUIP_BUILDUP							40200
#define		TYPE_EQUIP_COSTUME							40300
#define		TYPE_AVATAR_NONE							50000
#define		TYPE_AVATAR_PET								50100
#define		TYPE_AVATAR_MERCENARY						50200
#define		TYPE_SERVICE_NONE							60000
#define		TYPE_SERVICE_CONVENIENCE					60100
#define		TYPE_SERVICE_ETC							60200
#define		TYPE_PACKAGE_NONE							70000
//??? ?? ???
#define		TYPE_PACKAGE_BOOSTERS						70100
#define		TYPE_PACKAGE_ENHANCEMENTS					70200
#define		TYPE_PACKAGE_POTIONS						70300
#define		TYPE_PACKAGE_VANITY							70400
#define		TYPE_PACKAGE_UPGRADE						70500
#define		TYPE_PACKAGE_PETS							70600
#define		TYPE_PACKAGE_MERCENARY						70700
#define		TYPE_PACKAGE_CONVENIENCE					70800
#define		TYPE_PACKAGE_OTHERS							70900
//??? ?? ???
#define 	TYPE_OLD_GOODS								90000
#define		TYPE_LIST_START								0
#define		TYPE_MAX_COUNT								50
// subtype
#define		SUBTYPE_HOTNNEW_NONE_NONE					10000 // TYPE, SUBTYPE ???
#define		SUBTYPE_HOTNNEW_NEW_NONE					10100
#define		SUBTYPE_HOTNNEW_DISCOUNT_NONE				10200
#define		SUBTYPE_PLATINUM_NONE_NONE					20000
#define		SUBTYPE_DISPOSABLE_NONE_NONE				30000
#define		SUBTYPE_DISPOSABLE_CHARACTER_GROW_NONE		30100
#define		SUBTYPE_DISPOSABLE_CHARACTER_GROW_EXP		30101
#define		SUBTYPE_DISPOSABLE_CHARACTER_GROW_SP		30102
#define		SUBTYPE_DISPOSABLE_CHARACTER_GROW_DROP		30103
#define		SUBTYPE_DISPOSABLE_CHARACTER_GROW_MIX		30104
#define		SUBTYPE_DISPOSABLE_ABILITY_BUILDUP_NONE		30200
#define		SUBTYPE_DISPOSABLE_ABILITY_BUILDUP_HPEXT	30201
#define		SUBTYPE_DISPOSABLE_ABILITY_BUILDUP_MPEXT	30202
#define		SUBTYPE_DISPOSABLE_ABILITY_BUILDUP_VOL		30203	// VOL = Velocity of Light
#define		SUBTYPE_DISPOSABLE_POTION_NONE				30300
#define		SUBTYPE_DISPOSABLE_POTION_HPRECOVER			30301
#define		SUBTYPE_DISPOSABLE_POTION_MPRECOVER			30302
#define		SUBTYPE_DISPOSABLE_POTION_DUALRECOVER		30303
#define		SUBTYPE_EQUIP_NONE_NONE						40000
#define		SUBTYPE_EQUIP_EQUIPMENT_NONE				40100
#define		SUBTYPE_EQUIP_EQUIPMENT_WEAPON				40101
#define		SUBTYPE_EQUIP_EQUIPMENT_ARMOR				40102
#define		SUBTYPE_EQUIP_EQUIPMENT_ACCESSORY			40103
#define		SUBTYPE_EQUIP_BUILDUP_NONE					40200
#define		SUBTYPE_EQUIP_BUILDUP_MELDING				40201
#define		SUBTYPE_EQUIP_BUILDUP_SOCKET				40202
#define		SUBTYPE_EQUIP_BUILDUP_BLOOD					40203
#define 	SUBTYPE_EQUIP_BUILDUP_REFINE				40204
#define		SUBTYPE_EQUIP_COSTUME_NONE					40300
#define		SUBTYPE_EQUIP_COSTUME_TITAN					40301
#define		SUBTYPE_EQUIP_COSTUME_KNIGHT				40302
#define		SUBTYPE_EQUIP_COSTUME_HEALER				40303
#define		SUBTYPE_EQUIP_COSTUME_MAGE					40304
#define		SUBTYPE_EQUIP_COSTUME_ROGUE					40305
#define		SUBTYPE_EQUIP_COSTUME_SORCERER				40306
#define		SUBTYPE_EQUIP_COSTUME_NIGHTSHADOW			40307
#define		SUBTYPE_AVATAR_NONE_NONE					50000
#define		SUBTYPE_AVATAR_PET_NONE						50100
#define		SUBTYPE_AVATAR_PET_PET						50101
#define		SUBTYPE_AVATAR_PET_PETITEM					50102
#define		SUBTYPE_AVATAR_MERCENARY_NONE				50200
#define		SUBTYPE_AVATAR_MERCENARY_MONSTER			50201
#define		SUBTYPE_SERVICE_NONE_NONE					60000
#define		SUBTYPE_SERVICE_CONVENIENCE_NONE			60100
#define		SUBTYPE_SERVICE_CONVENIENCE_SCROLL			60101
#define		SUBTYPE_SERVICE_CONVENIENCE_CARD			60102
#define		SUBTYPE_SERVICE_CONVENIENCE_ETC_NONE		60200
#define		SUBTYPE_PACKAGE_NONE_NONE					70000
//??? ?? ???
#define		SUBTYPE_PACKAGE_BOOSTERS_NONE				70100
#define		SUBTYPE_PACKAGE_BOOSTERS_XP					70101
#define		SUBTYPE_PACKAGE_BOOSTERS_SP					70102
#define		SUBTYPE_PACKAGE_BOOSTERS_DROP				70103
#define		SUBTYPE_PACKAGE_BOOSTERS_MIXED				70104
#define		SUBTYPE_PACKAGE_ENHANCEMENTS_NONE			70200
#define		SUBTYPE_PACKAGE_ENHANCEMENTS_HPMP			70201
#define		SUBTYPE_PACKAGE_ENHANCEMENTS_MIXED			70202
#define		SUBTYPE_PACKAGE_POTIONS_NONE				70300
#define		SUBTYPE_PACKAGE_POTIONS_HPRECOVERY			70301
#define		SUBTYPE_PACKAGE_POTIONS_MPRECOVERY			70302
#define		SUBTYPE_PACKAGE_POTIONS_MIXED				70303
#define		SUBTYPE_PACKAGE_VANITY_NONE					70400
#define		SUBTYPE_PACKAGE_VANITY_TITAN				70401
#define		SUBTYPE_PACKAGE_VANITY_KNIGHT				70402
#define		SUBTYPE_PACKAGE_VANITY_HEALER				70403
#define		SUBTYPE_PACKAGE_VANITY_MAGE					70404
#define		SUBTYPE_PACKAGE_VANITY_ROGUE				70405
#define		SUBTYPE_PACKAGE_VANITY_SORCERER				70406
#define		SUBTYPE_PACKAGE_VANITY_NIGHTSHADOW			70407
#define		SUBTYPE_PACKAGE_UPGRADE_NONE				70500
#define		SUBTYPE_PACKAGE_UPGRADE_MELDING				70501
#define		SUBTYPE_PACKAGE_UPGRADE_STONENRUNES			70502
#define		SUBTYPE_PACKAGE_UPGRADE_SOCKETS				70503
#define		SUBTYPE_PACKAGE_PETS_NONE					70600
#define		SUBTYPE_PACKAGE_PETS_PETS					70601
#define		SUBTYPE_PACKAGE_PETS_PETSITEM				70602
#define		SUBTYPE_PACKAGE_MERCENARY_NONE				70700
#define		SUBTYPE_PACKAGE_CONVENIENCE_NONE			70800
#define		SUBTYPE_PACKAGE_CONVENIENCE_SCROLLS			70801
#define		SUBTYPE_PACKAGE_CONVENIENCE_CARDS			70802
#define		SUBTYPE_PACKAGE_OTHERS_NONE					70900
//??? ?? ???
#define		SUBTYPE_LIST_START							1
#define		SUBTYPE_MAX_COUNT							500
// ?? ???
#define		CATALOG_FLAG_NEW						(1 << 0)			// ???
#define		CATALOG_FLAG_POPULAR					(1 << 1)			// ????
#define		CATALOG_FLAG_DISCOUNT					(1 << 2)			// ????
#define		CATALOG_FLAG_RECOMM_1					(1 << 3)			// ?? ???1
#define		CATALOG_FLAG_RECOMM_2					(1 << 4)			// ?? ???2
#define		CATALOG_FLAG_RECOMM_3					(1 << 5)			// ?? ???3
#define		CATALOG_FLAG_RECOMM_4					(1 << 6)			// ?? ???4
#define		CATALOG_FLAG_RECOMM_5					(1 << 7)			// ?? ???5
#define		CATALOG_FLAG_NOGIFT						(1 << 8)			// ????
#define		CATALOG_FLAG_RESV2						(1 << 9)			// ?? ???
#define		CATALOG_FALG_TO_LIMIT(a, b)				(b = 0 | (a >> 10))	// ???? FLAG ??
#define		CATALOG_FALG_FROM_LIMIT(a, b)			(a = a | (b << 10))	// ???? FLAG ??
#define		CATALOG_FLAG_MAX_LIMIT					(2000000)			// ???? ??? LIMIT MAX

// Item Flag : ??? 1??? ?? ??!!!
// 6???? ??, ?, ?? ???? ???, ???? ???? ?? ???? ??? ??
#define		PLATINUM_MAX_PLUS				127
#define		FLAG_ITEM_PLATINUM_GET(a, b)	(b = a & PLATINUM_MAX_PLUS)
#define		FLAG_ITEM_PLATINUM_SET(a, b)	( (a &~ PLATINUM_MAX_PLUS) | b )
#define		FLAG_ITEM_OPTION_ENABLE			(1 << 7)	// ??? ???? ??? ?? ? ?? ??? ??, Bit ??
#define		FLAG_ITEM_SEALED				(1 << 8)	// ??? ??
#define		FLAG_ITEM_SUPER_STONE_USED		(1 << 9)	// ????? ????? ??..//0627
#define		FLAG_ITEM_BOOSTER_ADDED			(1 << 10)	// ??? ?? ??
#define		FLAG_ITEM_SILVERBOOSTER_ADDED	(1 << 11)	// ????? ?? ??
#define		FLAG_ITEM_GOLDBOOSTER_ADDED		(1 << 12)	// ????? ?? ??
#define		FLAG_ITEM_PLATINUMBOOSTER_ADDED	(1 << 13)	// ????? ?? ??
#define		FLAG_ITEM_COMPOSITION			(1 << 14)	// ??? ?? ??
#define		FLAG_ITEM_LENT					(1 << 15)	// ??? ???
#define		FLAG_ITEM_LEVELDOWN				(1 << 16)	// ?? ??? ???
#define		FLAG_ITEM_BELONG				(1 << 17)	// ?? ? ???
#define		FLAG_ITEM_SOCKET				(1 << 18)
#define		FLAG_ITEM_SUPER_RUNE_USED		(1 << 19)	// ???? ?? ??.
#define		FLAG_ITEM_PVP_RUNE_USED			(1 << 20)
#define		FLAG_ITEM_RESERVED				(1 << 31)	// ??? ? ???? ?? ??!

// Item Proto flag
#define		ITEM_FLAG_COUNT					((LONGLONG)1 << 0)	// ? ? ?? ?????
#define		ITEM_FLAG_DROP					((LONGLONG)1 << 1)	// ??  ?? ??????
#define		ITEM_FLAG_UPGRADE				((LONGLONG)1 << 2)	// ????? ??? ?????
#define		ITEM_FLAG_EXCHANGE				((LONGLONG)1 << 3)	// ?? ?? ??????
#define		ITEM_FLAG_TRADE					((LONGLONG)1 << 4)	// ?? ?? ??????
#define		ITEM_FLAG_BORKEN				((LONGLONG)1 << 5)	// ?? ?? ??????
#define		ITEM_FLAG_MADE					((LONGLONG)1 << 6)	// ?? ?? ??????
#define		ITEM_FLAG_MIX					((LONGLONG)1 << 7)	// ?? ??? : DB? ????
#define		ITEM_FLAG_CASH					((LONGLONG)1 << 8)	// ?? ???
#define		ITEM_FLAG_LORD					((LONGLONG)1 << 9)	// ?? ?? ???
#define		ITEM_FLAG_NO_STASH				((LONGLONG)1 << 10)	// ?? ?? ??? ???
#define		ITEM_FLAG_CHANGE				((LONGLONG)1 << 11)	// ?? ??? ????? ?? ?? ??
#define		ITEM_FLAG_COMPOSITE				((LONGLONG)1 << 12)	// ??? ?? ?? ??
#define		ITEM_FLAG_DUPLICATE				((LONGLONG)1 << 13)	// ?? ??
#define		ITEM_FLAG_LENT					((LONGLONG)1 << 14)	// ??? ??
#define		ITEM_FLAG_RARE					((LONGLONG)1 << 15)	// ?? ???
#define		ITEM_FLAG_ABS					((LONGLONG)1 << 16)	// ??? ???
#define		ITEM_FLAG_NOTREFORM				((LONGLONG)1 << 17)	// ?? ?? ???
#define		ITEM_FLAG_ZONEMOVE_DEL			((LONGLONG)1 << 18) // ??? ? ??? ??
#define     ITEM_FLAG_ORIGIN				((LONGLONG)1 << 19)	// ???? ??
#define     ITEM_FLAG_TRIGGER				((LONGLONG)1 << 20)	// ??? ???? ???? ???
#define     ITEM_FLAG_RAIDSPECIAL			((LONGLONG)1 << 21)	// ?? ?? ??(?? ?? ??? ??)
#define		ITEM_FLAG_QUEST					((LONGLONG)1 << 22) // ???
#define		ITEM_FLAG_BOX					((LONGLONG)1 << 23) //  ???????
#define		ITEM_FLAG_NOTTRADEAGENT			((LONGLONG)1 << 24)	// ?????? ??
#ifdef DURABILITY
#define     ITEM_FLAG_DURABILITY			((LONGLONG)1 << 25)	// ?? ???
#endif
#define		ITEM_FLAG_COSTUME2				((LONGLONG)1 << 26)
#define		ITEM_FLAG_SOCKET				((LONGLONG)1 << 27)		// ?? ?? ?? ???
#define		ITEM_FLAG_SELLER				((LONGLONG)1 << 28)		// ??? ???
#define		ITEM_FLAG_CASTLLAN				((LONGLONG)1 << 29)		// ??? ?? ??? ???
#define		ITEM_FLAG_LETSPARTY				((LONGLONG)1 << 30)		// ?????? ( ??? ??? ?? )
#define		ITEM_FLAG_NONRVR				((LONGLONG)1 << 31)		// RVR?? ??
#define		ITEM_FLAG_QUESTGIVE				((LONGLONG)1 << 32)		// ??? ?? ?? ???
#define		ITEM_FLAG_TOGGLE				((LONGLONG)1 << 33)		// ?? ???
#define		ITEM_FLAG_COMPOSE				((LONGLONG)1 << 34)		// ?? ?? ???
#define		ITEM_FLAG_NOTSINGLE				((LONGLONG)1 << 35)		// ???? ???? ???
#define		ITEM_FLAG_INVISIBLE_COSTUME		((LONGLONG)1 << 36)		// ?? ??? ???
#define   ITEM_FLAG_PICK_BOX					((LONGLONG)1 << 37) // Pick Box System
//?? ??? ??
#define		ITEM_NORMAL			0	//?? ?? ???
#define		ITEM_COSTUM			1	//?? ??? ???
#define		ITEM_COSTUM_SUIT	2	//??? ?? ???

// ??? ?? TYPE
#define		ITYPE_WEAPON			0		// ??
#define		ITYPE_WEAR				1		// ???
#define		ITYPE_ONCE				2		// ???
#define		ITYPE_SHOT				3		// ??
#define		ITYPE_ETC				4		// ??
#define		ITYPE_ACCESSORY			5		// ????
#define		ITYPE_POTION			6		// ??

// SUBTYPE : ??  --
#define		IWEAPON_NIGHT			0		// ???		???
#define		IWEAPON_CROSSBOW		1		// ??			??
#define		IWEAPON_STAFF			2		// ???		???
#define		IWEAPON_BIGSWORD		3		// ??			???
#define		IWEAPON_AXE				4		// ??			???
#define		IWEAPON_SHORTSTAFF		5		// ????		???
#define		IWEAPON_BOW				6		// ?			??
#define		IWEAPON_SHORTGUM		7		// ??			??
#define		IWEAPON_MINING			8		// ????		-
#define		IWEAPON_GATHERING		9		// ????		-
#define		IWEAPON_CHARGE			10		// ????		-
#define		IWEAPON_TWOSWORD		11		// ???		???
#define		IWEAPON_WAND			12		// ??			??
#define		IWEAPON_SCYTHE			13		// ???		???
#define		IWEAPON_POLEARM			14		// ??			???
#define		IWEAPON_SOUL			15		// ??(?)		??????

// SUBTYPE : ??? --
#define		IWEAR_HELMET			0		// ??
#define		IWEAR_ARMOR				1		// ??
#define		IWEAR_PANTS				2		// ??
#define		IWEAR_GLOVE				3		// ??
#define		IWEAR_SHOES				4		// ??
#define		IWEAR_SHIELD			5		// ??
#define		IWEAR_BACKWING			6		// ??
#define		IWEAR_SUIT				7		// ??

// SUBTYPE : ??? --
#define		IONCE_WARP				0		// ??
#define		IONCE_PROCESS_DOC		1		// ?? ??
#define		IONCE_MAKE_TYPE_DOC		2		// ????? ?? ??
#define		IONCE_BOX				3		// ??
#define		IONCE_MAKE_POTION_DOC	4		// ?? ?? ??
#define		IONCE_CHANGE_DOC		5		// ?? ???
#define		IONCE_QUEST_SCROLL		6		// ??? ??
#define		IONCE_CASH				7		// ?? ???
#define		IONCE_SUMMON			8		// ??? ???
#define		IONCE_ETC				9		// ?? ???? ??? ???
#define		IONCE_TARGET			10		// ??? ?????
#define		IONCE_TITLE				11		// ?? ???
#define		IONCE_REWARD_PACKAGE	12		// ?? ??? -> ??? ???? ?? : ? ??? ???? ???? ??? ??? ??? ????.
#define		IONCE_JUMPING_POTION	13		// ?? ?? : ???? ??? ??? ?? ??? ???? ???
#define		IONCE_EXTEND_CHARACTER_SLOT	14 // ??? ?? ?? ???
#define		IONCE_SERVER_TRANS		15		//?? ?? ???
#define		IONCE_REMOTE_EXPRESS	16		// ?? ?? ???
#define		IONCE_JEWEL_POCKET			17	// ?? ?? ???
#define		IONCE_CHAOS_JEWEL_POCKET	18	// ??? ?? ???
#define		IONCE_CASH_INVENTORY		19	// ?? ?? (?? ??)
#define		IONCE_PET_STASH				20	// ? ?? ???
#define		IONCE_GPS			21		//	gps ???
#define		IONCE_HOLY_WATER	22		//	?? ???
#define		IONCE_PROTECT_PVP	23		//PVP ??

// IONCE_WARP : ??
#define		IONCE_WARP_RETURN		0		// ?? ? ?? ??
#define		IONCE_WARP_MEMPOS		1		// ??? ??? ??
#define		IONCE_WARP_MARGADUM_PVP	2		// ??? pvp ??
#define		IONCE_WARP_PARTYRECALL	3		// 060227 : bs : ????
#define		IONCE_WARP_MEMPOSPLUS	4		// ?? ??? ??
#define		IONCE_WARP_NPC_PORTAL_SCROLL 30 // NpcPortalScroll ? ?? ?? ???? ???? ???.

// IONCE_BOX : ??
#define		IONCE_BOX_REMAKE		0		// ?????
#define		IONCE_BOX_ARCANE		1		// ?????
#define		IONCE_BOX_COLLECT_BUG	2		// ?? ?? ??

// SUBTYPE : ?? --
#define		ISHOT_ATKBULLET		0	// ????
#define		ISHOT_MPBULLET		1	// ????
#define		ISHOT_ARROW			2	// ??

// SUBTYPE : ?? --
#define		IETC_QUEST			0	// ????
#define		IETC_EVENT			1	// ????
#define		IETC_SKILLUP		2	// ?? ??
#define		IETC_UPGRADE		3	// ??
#define		IETC_MATERIAL		4	// ??
#define		IETC_MONEY			5	// ?
#define		IETC_PRODUCT		6	// ???
#define		IETC_PROCESS		7	// ???
#define		IETC_OPTION			8	// ??
#define		IETC_SAMPLE			9	// ??
#define		IETC_TEXTURE		10	// ??? For Client
#define		IETC_MIX_TYPE1		11	// ????1
#define		IETC_MIX_TYPE2		12	// ????2
#define		IETC_MIX_TYPE3		13	// ????3
#define		IETC_PET_AI			14	// ?
#define		IETC_QUEST_TRIGGER	15	// ??? ???
#define		IETC_JEWEL			16	// ??
#define		IETC_STABILIZER		17	// ???
#define		IETC_PROCESS_SCROLL	18	// ?? ???
#define		IETC_MONSTER_MERCENARY_CARD 19 // ??? ?? ??
#define		IETC_GUILD_MARK		20
#define		IETC_REFORMER		21
#define		IETC_CHAOSJEWEL		22	//??? ??
#define		IETC_FUNCTIONS		23	//???
#define		IETC_RVR_JEWEL		24	//??? ??

// IETC_PROCESS ??1
#define		IETC_PROCESS_STONE			0	// ?? ???
#define		IETC_PROCESS_PLANT			1	// ?? ???
#define		IETC_PROCESS_ELEMENT		2	// ?? ???

// IETC_PROCESS ??2
#define		IETC_PROCESS_STONE_0		0	// ?? ? ???
#define		IETC_PROCESS_STONE_1		1	// ?? ?? ???
#define		IETC_PROCESS_STONE_2		2	// ?? ?? ???
#define		IETC_PROCESS_STONE_3		3	// ?? ??? ???
#define		IETC_PROCESS_STONE_4		4	// ?? ??? ???

#define		IONCE_PROCESS_PLANT_0		0	// ??? ??? ???
#define		IONCE_PROCESS_PLANT_1		1	// ??? ?? ???
#define		IONCE_PROCESS_PLANT_2		2	// ??? ??? ???
#define		IONCE_PROCESS_PLANT_3		3	// ??? ?? ???
#define		IONCE_PROCESS_PLANT_4		4	// ??? ? ???

#define		IONCE_PROCESS_ELEMENT_0		0	// E?? ?? ???
#define		IONCE_PROCESS_ELEMENT_1		1	// D?? ?? ???
#define		IONCE_PROCESS_ELEMENT_2		2	// C?? ?? ???
#define		IONCE_PROCESS_ELEMENT_3		3	// B?? ?? ???
#define		IONCE_PROCESS_ELEMENT_4		4	// A?? ?? ???

// IETC_OPTION ??
#define		IETC_OPTION_TYPE_BLOOD	0	// ??? ?
#define		IETC_OPTION_TYPE_CLEAR	1	// ???

// IETC_UPGRADE ??
#define		IETC_UPGRADE_GENERAL		0	// ?????
#define		IETC_UPGRADE_SPECIAL		1	// ?????
#define		IETC_UPGRADE_SPECIAL_SUPER	2	// ???????//0627
#define		IETC_UPGRADE_BOOSTER		3	// ???
#define		IETC_UPGRADE_LUCKY			4	// ??? ?? ???
#define		IETC_UPGRADE_PLATINUM		5	// ???? ???
#define		IETC_UPGRADE_CHAOS			6	// ?? ???
#define		IETC_UPGRADE_PURITY_RUNE	7   // ??? ?
#define		IETC_UPGRADE_DEVIL_RUNE		8   // ??? ?
#define		IETC_UPGRADE_CHAOS_RUNE		9	// ??? ?
#define		IETC_UPGRADE_SUPER_RUNE		10	// ??? ?
#define		IETC_UPGRADE_LUCKY_RUNE		11	// ?? ?
#define		IETC_PVP_RUNE				12
// IETC_REFORMER ??
#define		IETC_REFORMER_MID_GRADE		0	// ?? ???
#define		IETC_REFORMER_HIGH_GRADE	1	// ?? ???
#define     IETC_MEGA_REFORMER_GRADE	2
// SUBTYPE : ????
#define		IACCESSORY_CHARM		0	// ??
#define		IACCESSORY_MAGICSTONE	1	// ???
#define		IACCESSORY_LIGHTSTONE	2	// ?????
#define		IACCESSORY_EARING		3	// ???
#define		IACCESSORY_RING			4	// ??
#define		IACCESSORY_NECKLACE		5	// ???
#define		IACCESSORY_PET			6	// ?
#define		IACCESSORY_ATTACK_PET	7	// ??? ?
#define		IACCESSORY_ARTIFACT		8	// ??

// SUBTYPE : ??
#define		IPOTION_STATE			0	// ????
#define		IPOTION_HP				1	// HP??
#define		IPOTION_MP				2	// MP??
#define		IPOTION_DUAL			3	// ????
#define		IPOTION_STAT			4	// Stat??
#define		IPOTION_ETC				5	// ?? (????)
#define		IPOTION_UP				6	// ????
#define		IPOTION_TEARS			7	// ??
#define		IPOTION_CRYSTAL			8	// ??
#define		IPOTION_NPC_PORTAL		9	// npc????? ?? (NHN ??? ???)
#define		IPOTION_HP_SPEEDUP		10	// hp??????
#define		IPOTION_MP_SPEEDUP		11  // mp??????
#define		IPOTION_PET_HP			12  // ?hp??
#define		IPOTION_PET_SPEEDUP		13  // ????
#define		IOPTION_TOTEM			14	
#define		IPOTION_PET_MP			15  // ?hp??

// IPOTION_TEARS ??
#define		IPOTION_TEARS_TYPE_SAFE		0	// ??? ??
#define		IPOTION_TEARS_TYPE_FORGIVE	1	// ??? ??

#define MAX_INVENTORY_SIZE			100							// ? ? ?? ??? ??
#define ITEMS_PER_ROW				5							// ? ?? ?? ??? ??
#define MAX_INVENTORY_ROWS			(MAX_INVENTORY_SIZE / ITEMS_PER_ROW)	// ??
#define MAX_SERIAL_LENGTH			20							// ??? ?? ??
#define MAX_ITEM_BUY				20							// ???? ?? ? ? ?? ??? ??? ?
#define MAX_ITEM_SELL				20							// ??? ?? ? ? ?? ??? ??? ?
#define	GROUND_ITEM_PULSE			(5 * PULSE_REAL_MIN)		// ?? ??? ???? ?? 60s
#define	ITEM_PREPERENCE_PULSE		(30 * PULSE_REAL_SEC)		// ??? ??? ?? ?? 10s

#define MAX_QUEST_INVENTORY_ROWS	(MAX_INVENTORY_SIZE / 20)
#define MAX_EVENT_INVENTORY_ROWS	(MAX_INVENTORY_SIZE / 20)

// ??? ????? ??
#define	ITEM_UPGRADE_RESULT_PLUS		0		// +1
#define	ITEM_UPGRADE_RESULT_MINUS		1		// -1
#define	ITEM_UPGRADE_RESULT_NOCHANGE	2		// 0
#define	ITEM_UPGRADE_RESULT_BROKEN		3		// ??
#define	ITEM_UPGRADE_PLATINUM_RESULT_PLUS 4		// ???? ???? ???
#define ITEM_UPGRADE_RUNE_PROTECTION_ITEM 5		// HIGH_RUNE_PROTECTION_ITEM ?? Rune item ??
#define ITEM_UPGRADE_RUNE_ENCHANTMENT	6		//Adding this for messages regarding the "enchantment runes"
#define ITEM_UPGRADE_PROB_PLUS_VALUE		12			// 12?? ?? ?? ??
#define ITEM_UPGRADE_PROB_PLUS_PENALTY_LEV	200			// ????? ??? ???? ??
#define ITEM_UPGRADE_PROB_PLUS_PENALTY_MAX	4000		// ????? ?? ???? ?? (40%) -> ?? ?? ?? ??? ?? ?
#define	ITEM_UPGRADE_PROB_GENERAL_PLUS		5000		// ?? ??? ?? 50%
#define ITEM_UPGRADE_PROB_SPECIAL_NOCHANGE	2000		// ?? ??? ?? ?? 20% (1 ~ 20)
#define ITEM_UPGRADE_PROB_SPECIAL_BROKEN	2700		// ?? ??? ?? ?? 7% (21 ~ 30)
#define ITEM_UPGRADE_PROB_SPECIAL_PLUS		7700		// ?? ??? ?? ?? ?? 50% (31 ~ 80)

#define ITEM_UPGRADE_PENALTY_BROKEN			3			// ???? -1 ?? ??? ??? ??

#define ITEM_UPGRADE_GENERAL_MINLEVEL		1			// ????? ?? 1?? ??
#define ITEM_UPGRADE_GENERAL_MAXLEVEL		146			// ?? ???? ?? ?? (??? ??? 146??? ??? ?????)

#define ITEM_REFINE_RESULT_TWO				0			// ?? ?? ??? 2?
#define ITEM_REFINE_RESULT_ONE				1			// ??? ?? ??? 1?
#define ITEM_REFINE_RESULT_SPECIAL			2			// ?? ??? 1?

// ?? ??
#define MAX_WEARING					28	// ??? ? ?? ?? ?? ? : ?? ?? ?? ?? ?? ?? ?? ??1 ??2 ??3 ???? ?
#define WEARING_NONE				-1	// ?? ??

#define WEARING_SHOW_START			0	// ??? ??? ?? ?? ?? ???
#define WEARING_SHOW_END			9	// ??? ??? ?? ?? ? ???

#define WEARING_HELMET				0	// ?? ?? ??
#define WEARING_ARMOR_UP			1
#define WEARING_WEAPON				2
#define WEARING_ARMOR_DOWN			3
#define WEARING_SHIELD				4
#define WEARING_GLOVE				5
#define WEARING_BOOTS				6
#define WEARING_ACCESSORY1			7
#define WEARING_ACCESSORY2			8
#define WEARING_ACCESSORY3			9
#define WEARING_PET					10

#define WEARING_BACKWING			11
#define WEARING_ACCESSORY4			12 // newslot - alanssoares
#define WEARING_SPECIAL_ACCESSORY1	13 // newslot - alanssoares
#define WEARING_SPECIAL_ACCESSORY2	14 // newslot - alanssoares
#define WEARING_SPECIAL_ACCESSORY3	15 // newslot - alanssoares
#define WEARING_SPECIAL_ACCESSORY4	16 // newslot - alanssoares
#define WEARING_SPECIAL_ACCESSORY5	17 // newslot - alanssoares

#define COSTUME2_WEARING_HELMET				20	// ?? ?? ??
#define COSTUME2_WEARING_ARMOR_UP			21
#define COSTUME2_WEARING_WEAPON				22
#define COSTUME2_WEARING_ARMOR_DOWN			23
#define COSTUME2_WEARING_SHIELD				24
#define COSTUME2_WEARING_GLOVE				25
#define COSTUME2_WEARING_BOOTS				26
#define COSTUME2_WEARING_BACK				27

#define COSTUME2_WEARING_SUIT				30

#define COSTUME2_WEARING_START				20 // COSTUME2 WEARING START NUMBER.
#define MAX_COSTUME_WEARING					8
#define DEFAULT_MAX_WEARING					18 // newslot - alanssoares

// [110207:selo] ? ? ??
#define COSTUME2_SUIT_MAX_WEARING			5	// ? ? ???? ??? ???? ??

/////////////////
// ?? ??? ??
#define MAX_SET_ITEM_OPTION			11			// ?? ???? ?? ?? ?? ??

#define SET_ITEM_OPTION_NONE		-1
#define SET_ITEM_OPTION				0			// ?? ???? ?? ??
#define SET_ITEM_SKILL				1			// ?? ???? ?? ??

/////////////////
// ?? ??? ??
#define		MAX_FACTORY_ITEM_STUFF	5			// ?? ??? ?? ?? ?
#define		MAX_SEAL_TYPE_SKILL		10			// ?? ?? ??

/////////////////
// ?? ?? ??

#define		MAX_EXCHANGE_ITEMS		10		// ?? ?? ??

//////////////////////////
// ?? ??

#define		HATE_DECREASE_UNIT		100						// HATE ?? ??
#define		HATE_FIRST_ATTACK		1500					// ??? HATE ??? 1/10000 ??
#define		NPC_DISABLE_TIME		(PULSE_REAL_SEC * 3)	// npc ?? ? ????? ???? ?? : 3 sec
#define		NPC_ACTIVITY_DELAY		10						// npc ?? ??? 10 : 1?
#define		MAX_PENALTY_EXP_LEVEL	(7.01f)					// ???? ?? ?? ??? ??? : 7??
#define		MAX_PENALTY_SP_LEVEL	10						// ???? ?? ?? ??? SP : 10??
#define		DOWN_LEVEL_EXP			10						// ?? ?? ??? ???? ??? ?? ?? %
#define		DOWN_LEVEL_SP			10						// ?? ?? ??? ???? SP ?? ?? %
#define		UP_LEVEL_SP				5						// ?? ?? ??? ???? SP ?? ?? %
#define		MONEY_DROP_PROB			8000					// pc -> npc npc??? ? ?? ??
#define		UNIT_CEHCK_BLOCK		0.5f					// ??? ??? ?? ?? ?? : 0.5m
#define		NPC_ATTACK_DELETE_PULSE	(PULSE_REAL_MIN * 3)	// ????Pulse ?????? ????? ? ??????? ??

#define		ACCESSORY_USED_ATTACK		10			// ?? ? ???? ??? 10 ??
#define		ACCESSORY_USED_DEFENSE		10			// ?? ? ???? ??? 10 ??
#define		ACCESSORY_USED_DEATH		200			// ?? ? ???? ??? 200 ??

// ??? ??? ???
#define		DEATH_PENALTY_EXP_1		((double)0.00)			// 1 ~ 10
#define		DEATH_PENALTY_EXP_2		((double)0.05)			// 11 ~ 20
#define		DEATH_PENALTY_EXP_3		((double)0.03)			// 21 ~ 35
#define		DEATH_PENALTY_EXP_4		((double)0.02)			// 36 ~

// ??? SP ???
#define		DEATH_PENALTY_SP_1		((double)0.00)			// 1 ~ 10
#define		DEATH_PENALTY_SP_2		((double)0.05)			// 11 ~ 20
#define		DEATH_PENALTY_SP_3		((double)0.03)			// 21 ~ 35
#define		DEATH_PENALTY_SP_4		((double)0.02)			// 36 ~

// ?? ???
#define		HITTYPE_MISS			(1 << 0)		// ??
#define		HITTYPE_WEAK			(1 << 1)		// ???
#define		HITTYPE_NORMAL			(1 << 2)		// ??
#define		HITTYPE_STRONG			(1 << 3)		// ???
#define		HITTYPE_HARD			(1 << 4)		// ?? ???
#define		HITTYPE_CRITICAL		(1 << 5)		// ????
#define		HITTYPE_DEADLY			(1 << 6)		// ??? ???

#define		HITTYPE_MAX_PROB_MISS		5000		// ??
#define		HITTYPE_MAX_PROB_WEAK		3000		// ??
#define		HITTYPE_MAX_PROB_STRONG		3000		// ???
#define		HITTYPE_MAX_PROB_HARD		2000		// ??
#define		HITTYPE_MAX_PROB_CRITICAL	1500		// ??
#define		HITTYPE_MAX_PROB_DEADLY		1000		// ???

// ?? ?? ??
#define		ATTACK_RANGE_TITAN				2.3f	// ???
#define		ATTACK_RANGE_KNIGHT				2.3f	// ???
#define		ATTACK_RANGE_HEALER				20.0f	// ??
#define		ATTACK_RANGE_MAGE				15.0f	// ???
#define		ATTACK_RANGE_ROGUE_1			2.3f	// ?? : ??
#define		ATTACK_RANGE_ROGUE_2			15.0f	// ?? : ??
#define		ATTACK_RANGE_SORCERER			3.0f	// ???
#define		ATTACK_RANGE_SORCERER_HELLOUND	15.0f	// ??? : ?? : ???
#define		ATTACK_RANGE_SORCERER_ELENEN	3.0f	// ??? : ?? : ???
#define		ATTACK_RANGE_NIGHTSHADOW		15.0f	// ??? ???

///////////////////////////
// ?? ??

#define		MAX_PARTY_MEMBER		8			// ?? ?? ??
#define		PARTY_PLUS_EXP			10			// ?? ??? ?? ??? : 10%
#define		PARTY_PLUS_SP			10			// ?? ??? ?? SP : 10%
#define		PARTY_PLUS_EXP_COUNT	5			// ?? ??? ?? ?? ??? : 5%
#define		PARTY_PLUS_SP_COUNT		5			// ?? ??? ?? ?? SP : 5%

// ?? ??? ???
#define		PARTY_EXP_DAMAGE		60			// ??? ?? ???
#define		PARTY_EXP_SAME			20			// ?? ?? ???
#define		PARTY_EXP_LEVEL			20			// ?? ?? ???
// ?? SP ???
#define		PARTY_SP_DAMAGE			60			// ??? ?? SP
#define		PARTY_SP_SAME			20			// ?? ?? SP
#define		PARTY_SP_LEVEL			20			// ?? ?? SP

/////////////////////////
// character ?? ??

#define		NPC_RECOVER_PULSE		(PULSE_REAL_SEC * 3)		// npc ?? ?? : 3?
#define		PC_RECOVER_PULSE		(PULSE_REAL_SEC * 3)		// pc ?? ?? : 3?

#define		ASSIST_TYPE_SKILL		0		// ?? ?? : ??
#define		ASSIST_TYPE_ITEM		1		// ?? ?? : ???

#define		PLAYER_STATE_RESET			(0 << 0)	// ???
#define		PLAYER_STATE_SITDOWN		(1 << 0)	// ??/??
#define		PLAYER_STATE_MOVING			(1 << 1)	// ??/??
#define		PLAYER_STATE_WARP			(1 << 2)	// ?? ?
#define		PLAYER_STATE_PKMODE			(1 << 3)	// PK ??				// ADULT_SERVER -> PK ???
#define		PLAYER_STATE_PKMODEDELAY	(1 << 4)	// PK ?? ?? ???	// ADULT_SERVER -> ????
#define		PLAYER_STATE_RAMODE			(1 << 5)	// ???? ??
#define		PLAYER_STATE_CHANGE			(1 << 6)	// ???
#define		PLAYER_STATE_BILLITEM		(1 << 7)	// ????? ???
#define		PLAYER_STATE_CASHITEM		(1 << 8)	// ????? ???
#define		PLAYER_STATE_SUPPORTER		(1 << 9)	// ?? ??? ??? : ?? ??? ??? ???
#define		PLAYER_STATE_OTHERZONE		(1 << 10)	// ?? ?? ?
#define		PLAYER_CRISTAL_RESPOND		(1 << 11)	// ?? ????? ???
#define		PLAYER_STATE_FLYING			(1 << 12)	// ????(??????)
#define		PLAYER_STATE_DARKNESS		(1 << 13)	// ????(??????)
#define		PLAYER_STATE_SKILL			(1 << 14)	// ??????(??????)
#define		PLAYER_STATE_CASH_ZONE_MOVE (1 << 15)	// ?????(??, ????, ????)
#define		PLAYER_STATE_INVINCIBILITY	(1 << 16)	// ?? ??

#define		RAMODE_USE_PULSE			(3 * TIME_ONE_MIN)	// ???? ?? ?? 3min

#define		RAMODE_DELAY_PULSE			(5 * TIME_ONE_MIN)	// ???? ?? ?? 5s
#define		RAMODE_MAX_TARGET			8			// ???? ?? ?? 8
#define		MAX_PK_COUNT				150			// ?? PK ?? ??
#define		PK_HUNTER_POINT_MAX			 32000		// ?? ?? ??
#define		PK_HUNTER_POINT_2			 19000		// ?? 2??
#define		PK_HUNTER_POINT_1			  6000		// ?? 1??
#define		PK_CHAOTIC_POINT_1			 -6000		// ?? 1??
#define		PK_CHAOTIC_POINT_2			-19000		// ?? 2??
#define		PK_CHAOTIC_POINT_MAX		-32000		// ?? ?? ??

#ifdef PKMODE_LIMIT_LEVEL
#else
#define		PKMODE_LIMIT_LEVEL			15			// ?? ?? PK ??
#endif

#define     PK_NAME_CHAOSLEGION         (-5)
#define     PK_NAME_NECROKNIGHT         (-4)
#define     PK_NAME_OUTLAW              (-3)
#define     PK_NAME_FEARCASTER          (-2)
#define     PK_NAME_MURDERER            (-1)
#define     PK_NAME_NORMAL              ( 0)
#define     PK_NAME_AVENGER             (+1)
#define     PK_NAME_LIGHTPORTER         (+2)
#define     PK_NAME_GUARDIAN            (+3)
#define     PK_NAME_SAINTKNIGHT         (+4)
#define     PK_NAME_DIVINEPROTECTOR     (+5)

/////////////////////////
// Quick Slot ??

#define		QUICKSLOT_PAGE_NUM		3		// 3???
#define		QUICKSLOT_MAXSLOT		12		// 10? ??? F1-F10

#define		QUICKSLOT_TYPE_EMPTY		-1		// ?? ???
#define		QUICKSLOT_TYPE_SKILL		0		// ????
#define		QUICKSLOT_TYPE_ACTION		1		// ????
#define		QUICKSLOT_TYPE_ITEM			2		// ?????
#define		QUICKSLOT_TYPE_ITEM_WEAR	3	    // ?? ??? ??

///////////////////////
// ??? ??? ???
#define SEND_Q(msg, desc)		{ if (desc != NULL) (desc)->WriteToOutput(msg); }

////////////////////////
// ??? ?? ?? ??
#define CONN_WAIT_IDEN			0			// ?? ??? ?? ??
#define CONN_PLAYING			1			// ????
#define CONN_CHANGE_SERVER		2			// ?? ?? ?

#define LOGIN_STATE_FAIL		-1
#define LOGIN_STATE_NOT			0
#define LOGIN_STATE_SUCCESS		1
#define LOGIN_STATE_NOPLAY		2

///////////////////////
// ??, ?? ?? ??
#define		MIN_HITRATE		1000		// ?? ?? 10%
#define		MAX_HITRATE		9500		// ?? ?? 95%
#define		MIN_CRITICAL	500			// ?? ???? 5%
#define		MAX_CRITICAL	6600		// ?? ???? 66%

// ?? ??? ??
#define	EFFECT_ETC_LEVELUP		0	// ??? ???
#define	EFFECT_ETC_GOZONE		1	// go_zone ???

// ?? ??
#define ACTION_GENERAL			0	// ??
#define ACTION_SOCIAL			1	// ??
#define ACTION_PARTY			2	// ??
#define ACTION_GUILD			3	// ??
#define ACTION_PET				4	// ?
#define ACTION_TITLE			5	// ?? ???

#define	AGT_SITDOWN				3	// ????
#define	AGT_PKMODE				23	// PK ??
#define AGT_PET_SITDOWN			37	// ? ??
#define AGT_THROW_WATER			42	// ????
#define AGT_FACTORY				46	// ??

///////////////////////
// ? ??
#define ZONE_START						0		// ?? ??
#define ZONE_DUNGEON1					1		// ?? 1
#define ZONE_SINGLE_DUNGEON1			2		// ?? ?? 1
#define ZONE_DUNGEON2					3		// ?? 2
#define ZONE_DRATAN						4		// ?? 2 ???
#define ZONE_SINGLE_DUNGEON2			5		// ?? ?? 2
#define	ZONE_SINGLE_DUNGEON_TUTORIAL	6		// ?? ?? 1 ?????
#define	ZONE_MERAC						7		// ???
#define	ZONE_GUILDROOM					8		// ???
#define	ZONE_DUNGEON3					9		// ?? 3
#define	ZONE_SINGLE_DUNGEON3			10		// ?? ?? 3
#define	ZONE_SINGLE_DUNGEON4			11		// ?? ?? 4
#define ZONE_DUNGEON4					12		// ?? 4: ???
#define ZONE_FREE_PK_DUNGEON			13		// PK ??
#define ZONE_OXQUIZROOM					14		// OX ???
#define ZONE_EGEHA						15		// ???
#define ZONE_EGEHA_PK					16		// ??? PK?
#define ZONE_EGEHA_DUNGEON_1			17		// ??? ?? 1F~7F
#define ZONE_EGEHA_DUNGEON_8			18		// ??? ?? 8F
#define ZONE_EGEHA_DUNGEON_9			19		// ??? ?? 9F
#define ZONE_EGEHA_DUNGEON_10			20		// ??? ?? 10F

#define ZONE_DRATAN_CASTLE_DUNGEON		21		// ??? ?? ?? ??
#define ZONE_COMBO_DUNGEON				22		// ??? ?? ??
#define ZONE_STREIANA					23		// ??????
#define ZONE_PK_TOURNAMENT				24		// ?????? ???
#define ZONE_EXTREME_CUBE				25		// ??
#define ZONE_SPRIT_CAVE					26		// ??? ??
#define ZONE_QUANIAN_CAVE				27		// ???? ??
#define ZONE_GOLEM_CAVE					28		// ??? ??
#define ZONE_EBONY_MINE					29		// ?????
#define ZONE_MISTY_CANYON				30		// ?????
#define ZONE_FLORAIM_CAVE				31		// ???? ??
#define ZONE_MONDSHINE					32		// ????
#define ZONE_CAPPELLA_1					33		// ??? 1?
#define ZONE_CAPPELLA_2					34		// ??? 2?
#define ZONE_ALTER_OF_DARK				35		// ??? ??
#define ZONE_AKAN_TEMPLE				36		// ???? ?
#define ZONE_TRIVIA_CANYON				37		// ????
#define ZONE_ROYAL_RUMBLE				38		// ???? ?
#define ZONE_TARIAN						39		// ???
#define ZONE_BLOODYMIR					40		// ?????
#define ZONE_TARIAN_DUNGEON				41		// ???? ???? - ??? ??
#define ZONE_RVR						42		// RVR Test ??
#define ZONE_GRASSLAND                  43 //grassland add
#define ZONE_SASILIE_TRIBAL_VILLAGE		44
#define ZONE_THE_GLADES					45
///////////////////////////////////////
// Quest ??

// ??? ??
#define		QTYPE_KIND_REPEAT				0		// ??? ???
#define		QTYPE_KIND_COLLECTION			1		// ??? ???
#define		QTYPE_KIND_DELIVERY				2		// ??? ???
#define		QTYPE_KIND_DEFEAT				3		// ?? ???(????1)
#define		QTYPE_KIND_SAVE					4		// ?? ???(????2)
#define		QTYPE_KIND_MINING_EXPERIENCE	5		// ?? ?? ???
#define		QTYPE_KIND_GATHERING_EXPERIENCE	6		// ?? ?? ???
#define		QTYPE_KIND_CHARGE_EXPERIENCE	7		// ?? ?? ???
#define		QTYPE_KIND_PROCESS_EXPERIENCE	8		// ?? ?? ???
#define		QTYPE_KIND_MAKE_EXPERIENCE		9		// ?? ?? ???
#define		QTYPE_KIND_TUTORIAL				10		// ???? ???
#define		QTYPE_KIND_PK					11		// PK ???
#define		QTYPE_KIND_SEARCH				12		// ?? ???

// ?????
#define		QTYPE_SCALE_PERSONAL		0
#define		QTYPE_SCALE_PARTY			1
#define     QTYPE_SCALE_BATTLEGROUP		2

// ??? ??
#define		QTYPE_REPEAT_ONCE			0		// 1?? ???
#define		QTYPE_REPEAT_UNLIMITED		1		// ?? ???
#define		QTYPE_REPEAT_DAY			2		// ?? ???
#define		QTYPE_REPEAT_WEEK			3 //dethunter12 add 3/30/23
// ?? ??
#define		QSTART_NPC					0		// NPC? ?? ??
#define		QSTART_ITEM					1		// ???? ?? ??
#define		QSTART_LEVEL				2		// ?? ?? ?? ??
#define		QSTART_AREA					3		// ????? ???? ??

// ??? ?? ??
#define		QCONDITION_NPC				0		// NPC
#define		QCONDITION_ITEM				1		// ???
#define		QCONDITION_ITEM_NORMAL		2		// ???(??)
#define		QCONDITION_PC				3		// PC (??? PK)
#define		QCONDITION_AREA				4
#define		QCONDITION_ITEM_USE			5		// ???(??)
#define		QCONDITION_TRIGGER			6		// ??? ??

// ??? ?? ??
#define		QPRIZE_ITEM					0		// ???
#define		QPRIZE_MONEY				1		// ??
#define		QPRIZE_EXP					2		// ???
#define		QPRIZE_SP					3		// ?????
#define		QPRIZE_SKILL				4		// ??
#define		QPRIZE_SSKILL				5		// ????
#define		QPRIZE_STATPOINT			6		// ?????
#define		QPRIZE_RVRPOINT				7		// RVR ???
#define		QPRIZE_EXP_RATE				8		

#define		QUEST_MAX_PC				30		// ??? ?? ??? 10? -> 16
#define		QUEST_MAX_NEED_ITEM			5		// ??? ? ????? ?? 5

#define		QUEST_MAX_CONDITION			3		// ??? ???? ?? 3
#define		QUEST_MAX_CONDITION_DATA	4		// ??? ???? ??? ?? ??? ?? 4
#define		QUEST_MAX_ITEM_DROP_MONSTER	3		// ?? ??? : ??? ?? ??? ?? 3

#define		QUEST_MAX_PRIZE				5		// ??? ?? ?? 5

#define		QUEST_MAX_OPTPRIZE			7

#define		QUEST_MAX_NPC				50		// npc ??? ?? ??? ?? ? 50
#define		QUEST_MAX_PC_COMPLETE		100		// pc? ??? 1?? ??? ?? ? 100

// ??? ?? ??
#define		QUEST_STATE_ALL				0		// ?? ??? ???
#define		QUEST_STATE_INIT			1		// ??? ?? ??
#define		QUEST_STATE_RUN				2		// ??? ?? ?
#define		QUEST_STATE_DONE			3		// ??? ?? ?? (?? ??)
#define		QUEST_STATE_ABANDON			4		// ??? ?? ??

#define		S2_TICKET_MOB_START			13		// ????2 ??? ?? (?????) ??? ??
#define		S2_TICKET_MOB_END			27		// ????2 ??? ?? (?????) ??? ?

#define		S2_TICKET_LEVEL_START		13		// ????2 ??? ?? (???) pc?? ??
#define		S2_TICKET_LEVEL_END			27		// ????2 ??? ?? (???) pc?? ?

#define		S2_TICKET_DROP_PROB			50		// ????2 ??? ?? ??

#define		S2_TICKET_QUEST_DONE		5		// 5? ??? ???? ??? ??

////////////////////////////
// ??? ?? ??
#define		DROP_PHOENIX_MEMBERS_TICKET		10		// ??? ??? ?? ??  0.1%

/////////////////////
// ??? ?? ???
// #define BETAEVENT						// ?? ???

/////////////////////
// ?? ?? ???
//
#define		OPTION_STR_UP				0		// ? ??
#define		OPTION_DEX_UP				1		// ?? ??
#define		OPTION_INT_UP				2		// ?? ??
#define		OPTION_CON_UP				3		// ?? ??
#define		OPTION_HP_UP				4		// ??? ??
#define		OPTION_MP_UP				5		// ?? ??

#define		OPTION_DAMAGE_UP			6		// ?? ??? ??
#define		OPTION_MELEE_DAMAGE_UP		7		// ?? ??? ??? ??
#define		OPTION_RANGE_DAMAGE_UP		8		// ?? ??? ??? ??
#define		OPTION_MELEE_HIT_UP			9		// ?? ?? ??? ??
#define		OPTION_RANGE_HIT_UP			10		// ?? ??? ??? ??

#define		OPTION_DEFENSE_UP			11		// ?? ??? ??
#define		OPTION_MELEE_DEFENSE_UP		12		// ?? ??? ??? ??
#define		OPTION_RANGE_DEFENSE_UP		13		// ?? ??? ??? ??
#define		OPTION_MELEE_AVOID_UP		14		// ?? ?? ??? ??
#define		OPTION_RANGE_AVOID_UP		15		// ?? ??? ??? ??

#define		OPTION_MAGIC_UP				16		// ?? ??? ??
#define		OPTION_MAGIC_HIT_UP			17		// ?? ??? ??
#define		OPTION_RESIST_UP			18		// ?? ??? ??
#define		OPTION_RESIST_AVOID_UP		19		// ?? ??? ??

#define		OPTION_ALL_DAMAGE_UP		20		// ?? ??? ?? (????, ????, ??)
#define		OPTION_ALL_HIT_UP			21		// ?? ??? ?? (????, ????, ??)

#define		OPTION_ALL_DEFENSE_UP		22		// ?? ??? ?? (????, ????, ??)
#define		OPTION_ALL_AVOID_UP			23		// ?? ??? ?? (????, ????, ??)

#define		OPTION_NOT_USED_24			24		// ?? ??
#define		OPTION_NOT_USED_25			25		// ?? ??

#define		OPTION_ATTR_FIRE			26
#define		OPTION_ATTR_WATER			27
#define		OPTION_ATTR_WIND			28
#define		OPTION_ATTR_EARTH			29
#define		OPTION_ATTR_DARK			30
#define		OPTION_ATTR_LIGHT			31

// ?? ?? ???? ??
#define		OPTION_MIX_STR				36		// ?
#define		OPTION_MIX_DEX				37		// ??
#define		OPTION_MIX_INT				38		// ??
#define		OPTION_MIX_CON				39		// ??

#define		OPTION_MIX_ATTACK			40		// ??
#define		OPTION_MIX_MAGIC			41		// ??
#define		OPTION_MIX_DEFENSE			42		// ??
#define		OPTION_MIX_RESIST			43		// ??

#define		OPTION_MIX_STURN			44		// ??
#define		OPTION_MIX_BLOOD			45		// ???
#define		OPTION_MIX_MOVE				46		// ??
#define		OPTION_MIX_POISON			47		// ???
#define		OPTION_MIX_SLOW				48		// ???
// -- ?? ?? ???? ??

// 2006 ??? ?? ??
#define		OPTION_DOWN_LIMITLEVEL		49		// ???? ?? ??
#define		OPTION_INCREASE_INVEN		50		// HP?? ??? (2013 07????? ??? ????)
#define		OPTION_STEAL_MP				51		// ?? ??
#define		OPTION_STEAL_HP				52		// ??? ??
#define		OPTION_ATTACK_BLIND			53		// ?? ??
#define		OPTION_ATTACK_POISON		54		// ? ??
#define		OPTION_ATTACK_CRITICAL		55		// ???? ?? ??
#define		OPTION_RECOVER_HP			56		// HP ??? ??
#define		OPTION_RECOVER_MP			57		// MP ??? ??
#define		OPTION_DECREASE_SKILL_DELAY	58		// ?? ??? ??
#define		OPTION_DECREASE_SKILL_MP	59		// MP ??? ??
#define		OPTION_RESIST_STONE			60		// ?? ?? ??
#define		OPTION_RESIST_STURN			61		// ?? ?? ??
#define		OPTION_RESIST_SILENT		62		// ?? ?? ??
#define		OPTION_BLOCKING				63		// ??? ??
#define		OPTION_MOVESPEED			64		// ?? ?? ??
// --- 2006 ??? ?? ??
#define		OPTION_FLYSPEED				65		// ?? ?? ??
#define     OPTION_ATTACK_DEADLY        66      // ??? ?? ??

#define		OPTION_STR_UP_RATE			67
#define		OPTION_DEX_UP_RATE			68
#define		OPTION_INT_UP_RATE			69
#define		OPTION_CON_UP_RATE			70
#define		OPTION_HP_UP_RATE			71
#define		OPTION_MP_UP_RATE			72
#define		OPTION_WEAPON_UP_RATE		73
#define		OPTION_ARMOR_UP_RATE		74
#define		OPTION_MELEE_HIT_UP_RATE	75
#define		OPTION_MAGIC_HIT_UP_RATE	76
#define		OPTION_MELEE_AVOID_RATE		77
#define		OPTION_MAGIC_AVOID_RATE		78
#define		OPTION_RECOVER_HP_RATE		79
#define		OPTION_RECOVER_MP_RATE		80
#define		OPTION_TEST_QUEST			81
#define		OPTION_EXP_UP_RATE			82
#define		OPTION_SP_UP_RATE			83
#define		OPTION_APET_TRANS_END		84
//?? ???? ????? ??? ??? ?? ??
#define		OPTION_APET_ELEMENT_HPUP	85
#define		OPTION_APET_ELEMENT_ATTUP	86
#define		OPTION_ATT_FIRE_UP			87		// ?? ?? ?? ?? ??
#define		OPTION_ATT_WATER_UP			88		// ?? ?? ?? ?? ??
#define		OPTION_ATT_WIND_UP			89		// ?? ?? ?? ?? ??
#define		OPTION_ATT_EARTH_UP			90		// ?? ?? ?? ?? ??
#define		OPTION_ATT_DARK_UP			91		// ?? ?? ?? ?? ??
#define		OPTION_ATT_LIGHT_UP			92		// ? ?? ?? ?? ??
#define		OPTION_DEF_FIRE_UP			93		// ?? ?? ?? ?? ??
#define		OPTION_DEF_WATER_UP			94		// ?? ?? ?? ?? ??
#define		OPTION_DEF_WIND_UP			95		// ?? ?? ?? ?? ??
#define		OPTION_DEF_EARTH_UP			96		// ?? ?? ?? ?? ??
#define		OPTION_DEF_DARK_UP			97		// ?? ?? ?? ?? ??
#define		OPTION_DEF_LIGHT_UP			98		// ? ?? ?? ?? ??
#define		OPTION_ALL_STAT_UP			99		// ?? ??(4?) ??
#define		OPTION_PVP_DAMAGE_ABSOLB	100		// PVP ??? ??(%)
#define		OPTION_DEBUF_DECR_TIME		101		// ??? ?? ??(%)
#define		OPTION_RECOVER_HP_NOTRATE	102		// HP?? ???
#define		OPTION_RECOVER_MP_NOTRATE	103		// MP?? ???
#define		OPTION_INCREASE_STRONG		104		// ??? ??
#define		OPTION_INCREASE_HARD		105		// ?? ??? ??
#define		OPTION_INCREASE_HP			106		// hp ??? ??
#define		OPTION_CLIENT_1				107		// ????? lod? ?? ???(??? ????????)
#define		OPTION_CLIENT_2				108		// ????? lod? ?? ???(??? ????????)
#define		OPTION_CLIENT_3				109		// ????? lod? ?? ???(??? ????????)
#define		OPTION_CLIENT_4				110		// ????? lod? ?? ???(??? ????????)
#define		OPTION_CLIENT_5				111		// ????? lod? ?? ???(??? ????????)
#define		OPTION_CLIENT_6				112		// ????? lod? ?? ???(??? ????????)
#define		OPTION_CASH_ONLINE_BONUS	113
#define		OPTION_DAMAGE_INCREASE_PVE	114
#define     OPTION_NAS_UP_RATE			115
#define		OPTION_DAMAGE_INCREASE_PVP	116 //dethunter12 ADD 3/9/2023
#define		MAX_NUM_OPTION				120

#define		OPTION_VALUE_SHIFT			8		// 2byte ?? ?? 1Byte ?? ?? ??? 1Byte ?? ??
#define		OPTION_MAX_LEVEL			7		// ?? ?? ?? ?? 7

#define		MAX_ITEM_OPTION				5		// ???? ?? ?? ??
#define		MAX_ACCESSORY_OPTION		5		// ????? ?? ? ?? ?? ?? ?
#define		MAX_WEAPON_OPTION			5		// ??? ?? ? ?? ?? ?? ?
#define		MAX_ARMOR_OPTION			3		// ???? ?? ? ?? ?? ?? ?
#define		MAX_ITEM_OPTION_DEL			3		// ??? ?? ? ?? ?? ?
#define		MAX_TITLE_OPTION			5		// ??? ?? ?? ?? ?

/////////////////
// ?? ?? ??

// ?? ??
#define RARE_OPTION_GRADE_A			0
#define RARE_OPTION_GRADE_B			1
#define RARE_OPTION_GRADE_C			2
#define RARE_OPTION_GRADE_D			3
#define RARE_OPTION_GRADE_E			4

// ?? ??
#define RARE_OPTION_TYPE_WEAPON		0
#define RARE_OPTION_TYPE_ARMOR		1
#define RARE_OPTION_TYPE_ACCESSORY	2

/////////////////
// ???? ?? ??
#define MAX_ORIGIN_OPTION			6
#define MAX_ORIGIN_SKILL			3
#define MAX_ORIGIN					MAX_ORIGIN_OPTION + MAX_ORIGIN_SKILL

#define ORIGIN_OPTION_BELONG_NONE	-1
#define ORIGIN_OPTION_BELONG_WEAR	0			// ?? ? ??

/////////////////////////////
// Blood Point ??

#define		PC_BLOOD_POINT				5000	// ?? Blood Point
#define		ATTACK_BLOOD_POINT			15		// ??? ?? Blood Point
#define		DEFENSE_BLOOD_POINT			3		// ??? ?? Blood Point

///////////////////////////////
// ?? ?? ???
//
#define		MAX_PRODUCTS_FROM_NPC		5		// npc? ??? ??? ?? ?
#define		MAX_ACCEPTABLE				4		// npc ???? ?? ?? ??
#define		PER_DAMAGE_GET_PRODUCT		5		// 5 ??? ?? ??? ??
#define		MAX_MAKE_ITEM_MATERIAL		10		// ??? ??? ?? ?? ?
#define		NPC_PRODUCE_DELETE_PULSE	(PULSE_REAL_SEC * 4)	// ?? ??Pulse ?????? ????? ? ??????? ??

#define		MAX_ACCESSORY_MIX			3		// ??? ??? ???? ??? ?
#define		MAX_ARCANE_MIX				3		// ??? ??? ???? ??? ?

#define		ITEM_ARCANE_MATERIAL_UPGRADE		0	// ??? ?? ?? 0? ???
#define		ITEM_ARCANE_MATERIAL_ACCESSORY		1	// ??? ?? ?? 1? ????
#define		ITEM_ARCANE_MATERIAL_SAMPLE			2	// ??? ?? ?? 2? ??

#define		MAKE_SAMPLE_ON_PROCESS_PROB		600		// ??? ???? ??? ??

#define		MAX_ITEM_MAKE_SUCCESS_PROB	8000	// ??? ?? ?? ??? 80%

#define		ETERNAL_PENALTY_PROB		30		// ??? ???? 20% ???
#define		PUBLIC_PENALTY_PROB			60		// ???? ???? 60% ???

#define		GetMakeProb(limitLevel, itemLevel) (limitLevel - itemLevel) * 250

/////////////////////////////
// Special Skill ??
//

// Special Skill ??
#define		SSKILL_MINING		0	// ??
#define		SSKILL_GATHERING	1	// ??
#define		SSKILL_CHARGE		2	// ??
#define		SSKILL_STONE		3	// ?????
#define		SSKILL_PLANT		4	// ?????
#define		SSKILL_ELEMENT		5	// ?????

#define		SSKILL_MAKE_WEAPON	6	// ?? ?? ??
#define		SSKILL_MAKE_WEAR	7	// ??? ?? ??
#define		SSKILL_MAKE_G_B		8	// ?? ?? ?? ??
#define		SSKILL_MAKE_ARMOR	9	// ?? ?? ?? ??
#define		SSKILL_MAKE_H_S		10	// ?? ?? ?? ??

#define		SSKILL_MAX_LEVEL	5	// Special Skill ?? ??

//////////////////////////////////////
// ?? ??? ??
//

#define		TEACH_MAX_STUDENTS			10			// ?? ??? ?
#define		TEACH_LEVEL_TEACHER			50			// ??? ?? ??
#define		TEACH_LEVEL_STUDENT			30			// ??? ?? ??
#define		TEACH_LEVEL_SUCCESS			50			// ?? ?? ??
#define		TEACH_LIMIT_DAY				10			// 10? ?? ???? ??? ??? ?? ??? ???.
#define		TEACH_SP_STUDENT			5			// ???? ??? ??? ?? ??? SP 5%
#define		TEACH_SP_TEACHER			2			// ???? ??? ??? ?? ??? SP 2%
#define		TEACH_STUDENT_MAX_GIVEUP	3			// ???? ?? ??? ?? ??

#define		TEACH_FAME_PRIZE			10			// ?? ???

#define		CANCELTEACHER				(1 << 0)	// ??? ??
#define		CANCELSTUDENT				(1 << 1)	// ??? ??

///////////////
// ? ?? ??

#define MAX_OWN_PET							2				// ?? ?? ?? ?? ??
#define PET_HORSE_QUEST_INDEX				106				// ???? ???
#define PET_DRAGON_QUEST_INDEX				109				// ???? ???
#define PET_BLUE_HORSE_QUEST_INDEX			145				// ?? ???? ???
#define PET_PINK_DRAGON_QUEST_INDEX			146				// ?? ???? ???
#define PET_UNKOWN_HORSE_QUEST_INDEX		147				// ???? ???? ???
#define PET_UNKOWN_DRAGON_QUEST_INDEX		148				// ???? ???? ???

#define	PET_HORSE_EGG_INDEX				948				// ? ? ???
#define	PET_DRAGON_EGG_INDEX			949				// ? ? ???
#define	PET_BLUE_HORSE_EGG_INDEX		1707			// ??? ? ???
#define	PET_PINK_DRAGON_EGG_INDEX		1706			// ??? ? ???
#define	PET_UNKOWN_HORSE_EGG_INDEX		1709			// ????? ? ???
#define	PET_UNKOWN_DRAGON_EGG_INDEX		1708			// ????? ? ???

#define PET_HORSE_ITEM_INDEX			871				// ? ??? ???
#define PET_DRAGON_ITEM_INDEX			872				// ? ??? ???
#define PET_BLUE_HORSE_ITEM_INDEX		1710			// ? ??? ???
#define PET_PINK_DRAGON_ITEM_INDEX		1711			// ? ??? ???
#define PET_UNKOWN_HORSE_ITEM_INDEX		1713			// ? ??? ???
#define PET_UNKOWN_DRAGON_ITEM_INDEX	1712			// ? ??? ???

#define PET_TYPE_HORSE					(0x10)		// ?
#define PET_TYPE_DRAGON					(0x20)		// ?
#define PET_TYPE_BLUE_HORSE				(0x30)		// ?? ?
#define PET_TYPE_PINK_DRAGON			(0x40)		// ?? ?
#define PET_TYPE_UNKOWN_HORSE			(0x50)		// ?????
#define PET_TYPE_UNKOWN_DRAGON			(0x60)		// ?????

#define PET_GRADE_CHILD		(0X01)		// ???
#define PET_GRADE_ADULT		(0X02)		// ???
#define PET_GRADE_MOUNT		(0X03)		// ??

#define PET_TYPE_MASK		(0xf0)		// ?? ???
#define PET_GRADE_MASK		(0x0f)		// ?? ???

#define PET_DEFAULT_HUNGRY		50		// ?? ??? ??
#define PET_DEFAULT_SYMPATHY	50		// ?? ??? ??
#define PET_DEFAULT_RUNSPEED	15.0f	// ?? ??? ??
#define PET_MAX_HUNGRY			100		// ?? ??? ??
#define PET_MAX_SYMPATHY		100		// ?? ???
#define PET_MAX_HP				100		// ?? HP
#define PET_ADULT_LEVEL			16		// ??? ?? ??
#define PET_MOUNT_LEVEL			31		// ?? ?? ??

#define PET_MAX_LEVEL			100		// ? ?? ?? 100
#define MAX_APET_LEVEL			165		// ??? ? ?? ?? 165

typedef enum _tagPetColorType
{
	NON_COLOR		= 0,	// ??
	RED_COLOR		= 1,	// ??
	SCARLET_COLOR	= 2,	// ??
	YELLOW_COLOR	= 3,	// ??
	GREEN_COLOR		= 4,	// ??
	BLUE_COLOR		= 5,	// ??
	DEEP_BLUE_COLOR	= 6,	// ??
	VIOLET_COLOR	= 7,	// ??
	BLACK_COLOR		= 8,	// ??
	WHITE_COLOR		= 9,	// ?
	PHOENIX_COLOR	= 10,	// ??? ???
	BLACK_HEART_COLOR	= 11,	// ?? ??
	WHITE_HEART_COLOR	= 12,	// ?? ??
	YELLOW_HEART_COLOR	= 13,	// ?? ??
	BLACK_DIAMOND_COLOR		= 14,	// ?? ???
	BLACK_CLOVER_COLOR		= 15,	// ?? ???
	BLACK_SPADE_COLOR		= 16,	// ?? ????
	BLACK_SKELETON_COLOR	= 17,	// ?? ??
	WHITE_DIAMOND_COLOR		= 18,	// ?? ???
	WHITE_CLOVER_COLOR		= 19,	// ?? ???
	WHITE_SPADE_COLOR		= 20,	// ?? ????
	WHITE_SKELETON_COLOR	= 21,	// ?? ??
	YELLOW_DIAMOND_COLOR	= 22,	// ?? ???
	YELLOW_CLOVER_COLOR		= 23,	// ?? ???
	YELLOW_SPADE_COLOR		= 24,	// ?? ????
	YELLOW_SKELETON_COLOR	= 25,	// ?? ??
	RED_HEART_COLOR		= 26,	// ?? ??
	RED_CLOVER_COLOR		= 27,	// ?? ???
	RED_DIAMOND_COLOR		= 28,	// ?? ???
	RED_SPADE_COLOR		= 29,	// ?? ????
	RED_SKELETON_COLOR		= 30,	// ?? ??
	SCARLET_HEART_COLOR		= 31,	// ?? ??
	SCARLET_CLOVER_COLOR		= 32,	// ?? ???
	SCARLET_DIAMOND_COLOR		= 33,	// ?? ???
	SCARLET_SPADE_COLOR		= 34,	// ?? ????
	SCARLET_SKELETON_COLOR	= 35,	// ?? ??
	GREEN_HEART_COLOR		= 36,	// ?? ??
	GREEN_CLOVER_COLOR		= 37,	// ?? ???
	GREEN_DIAMOND_COLOR		= 38,	// ?? ???
	GREEN_SPADE_COLOR		= 39,	// ?? ????
	GREEN_SKELETON_COLOR		= 40,	// ?? ??
	BLUE_HEART_COLOR		= 41,	// ?? ??
	BLUE_CLOVER_COLOR		= 42,	// ?? ???
	BLUE_DIAMOND_COLOR		= 43,	// ?? ???
	BLUE_SPADE_COLOR		= 44,	// ?? ????
	BLUE_SKELETON_COLOR		= 45,	// ?? ??
	DEEP_BLUE_HEART_COLOR		= 46,	// ?? ??
	DEEP_BLUE_CLOVER_COLOR	= 47,	// ?? ???
	DEEP_BLUE_DIAMOND_COLOR	= 48,	// ?? ???
	DEEP_BLUE_SPADE_COLOR		= 49,	// ?? ????
	DEEP_BLUE_SKELETON_COLOR	= 50,	// ?? ??
	VIOLET_HEART_COLOR			= 51,	// ?? ??
	VIOLET_CLOVER_COLOR			= 52,	// ?? ???
	VIOLET_DIAMOND_COLOR		= 53,	// ?? ???
	VIOLET_SPADE_COLOR			= 54,	// ?? ????
	VIOLET_SKELETON_COLOR		= 55,	// ?? ??
	HORSE_WILLIAM_COLOR			= 56,	// ??? ?? WILLIAM ???
	HORSE_ALBER_COLOR			= 57,	// ??? ?? ALBER ???
	HORSE_REDEYE_COLOR			= 58,	// ??? ?? REDEYE ???
	HORSE_ZEBRA_COLOR			= 59,	// ??? ?? ZEBRA  ???
	HORSE_HAROLD_COLOR			= 60,	// ??? ?? HAROLD  ???
	HORSE_VIOLET_COLOR			= 61,	// ??? ?? VIOLET  ???
} PET_COLOR_TYPE;

///////////////////
// ??? ?? ??

#define ELEMENTAL_FIRE			0		// ?? ??
#define ELEMENTAL_WIND			1		// ??? ??
#define ELEMENTAL_EARTH			2		// ??? ??
#define ELEMENTAL_WATER			3		// ?? ??
#define ELEMENTAL_GUARD			4		// ?? ???(??)

#define ELEMENTAL_ATTACK_SPEED	20		// ?? ??
#define ELEMENTAL_RUN_SPEED		18.0f	// ?? ??
#define ELEMENTAL_RECOVER_HP	1		// 3?? ??? ?? ???

#define ELEMENTAL_ATTACK_RANGE_FIRE		2.0f	// ???? : ????
#define ELEMENTAL_ATTACK_RANGE_WIND		7.0f	// ???? : ?????
#define ELEMENTAL_ATTACK_RANGE_EARTH	3.0f	// ???? : ?????
#define ELEMENTAL_ATTACK_RANGE_WATER	7.0f	// ???? : ????
#define ELEMENTAL_ATTACK_RANGE_GUARD	5.0f	// ???? : ???(??)

#if defined(LC_KOR) || defined(LC_USA) || defined (LC_GAMIGO) || defined(LC_BILA) || defined(LC_RUS) || defined(LC_TLD)
#define SUMMON_DELAY			(PULSE_REAL_SEC * 5)	// ?? ???
#else
#define SUMMON_DELAY			(PULSE_REAL_MIN * 5)	// ?? ???
#endif
#define SUMMON_DURATION			(TIME_ONE_MIN * 20)	// ?? ????

/////////////////
// ?? ?? ??
#define EVOCATION_NONE			0		// ?? ??
#define EVOCATION_HELLOUND		313		// ??? ??
#define EVOCATION_ELENEN		309		// ??? ??

#if defined (LC_RUS)
#define EVOCATION_DELAY			(PULSE_REAL_MIN * 0)	// ?? ???
#else
#define EVOCATION_DELAY			(PULSE_REAL_MIN * 5)	// ?? ???
#endif
#define EVOCATION_DURATION		(PULSE_REAL_MIN * 30)	// ?? ????

////////////////////////////////////
// Event ??

////////////////////
// Latto Event ??
#define		LATTO_EVENT_UPGRADE_PROB		3000		// 10%
#define		LATTO_EVENT_BLOOD_PROB			3000		// 10%
#define		LATTO_EVENT_PARTY_PROB			5000		// 50%
#define		LATTO_EVENT_PROCESS_PROB		3000		// 30%
#define		LATTO_EVENT_EXPSP_PROB			3000		// 30%

#define		LATTO_EVENT_EXPSP_LEVEL			15			// 15 ??
#define		LATTO_EVENT_EXP_PERCENT			30			// ?? : 30%
#define		LATTO_EVENT_PARTY_LEVEL_MIN		5			// 5 ??
#define		LATTO_EVENT_PARTY_LEVEL_MAX		15			// 15 ??

#define		CHANGE_26LEVEL_GENERAL_STONE_PROB	800			// 26?? ?? ??? ?? ??
#define		CHANGE_SPECIAL_STONE_PROB			900			// ????? ?? ??
#define		CHANGE_22LEVEL_EVENT_WEAPON_PROB	1000		// 22?? ??? ?? (???) ?? ??
#define		CHANGE_31LEVEL_ARMOR_PROB			1100		// 31?? ??? ?? (???) ?? ??
#define		CHANGE_ATTACK_UP_PROB				5300		// ??? ??? ?? ??
#define		CHANGE_DEFENSE_UP_PROB				9500		// ??? ??? ?? ??
#define		CAHNGE_50000NAS_PROB				10000		// 5? ?? ?? ??

///////////////////////
// New Year Evnet ??
#define		NEWYEAR_EVENT_RICESOUP_DROP_PROB	1000	// 10%
#define		NEWYEAR_EVENT_RICEMANDO_DROP_PROB	1000	// 10%
#define		NEWYEAR_EVENT_RICESOUP_UP_EXP		12		// 120%
#define		NEWYEAR_EVENT_RICEMANDO_UP_SP		13		// 130%

#define CLIENT_OPTION_EFFECT	( 1 << 0 )
#define CLIENT_OPTION_WARP		( 1 << 1 )

#define GOLDENBALL_STATUS_NOTHING		0
#define GOLDENBALL_STATUS_VOTE			1
#define GOLDENBALL_STATUS_GIFT			2
#define GOLDENBALL_STATUS_VOTE_END		3
#define GOLDENBALL_TEAM_NAME_LENGTH		32
#define GOLDENBALL_BALL_INDEX			1482
#define GOLDENBALL_CARD_INDEX			1483

#define APET_WEAR_HEAD		0
#define APET_WEAR_BODY		1
#define APET_WEAR_WEAPON	2
#define APET_WEAR_ACCE		3
#define APET_WEARPOINT		4

#define APET_MAX_AI			6	// ?? AI slot


// t_cashItemdate ???
#define CASH_ITEM_DATE_FIELD_MEMPOS			"a_mempos_new"
#define CASH_ITEM_DATE_FIELD_CHAR_SLOT0		"a_charslot0_new"
#define CASH_ITEM_DATE_FIELD_CHAR_SLOT1		"a_charslot1_new"
#define CASH_ITEM_DATE_FIELD_STASHEXT		"a_stashext_new"

#if defined (LC_KOR)
#define WAR_CASTLE_SUBNUMBER_MERAC	1	// ??? ??? ???? ??
#define RAID_SUBNUMBER		1			// ??? ??? ?? ?? ??
#elif defined(LC_GAMIGO) || defined (LC_BILA) || defined (LC_USA) || defined (LC_RUS)
#define WAR_CASTLE_SUBNUMBER_MERAC  1   // ??? ??? ???? ??
#define RAID_SUBNUMBER		1			// ??? ??? ?? ?? ??
#else
#define WAR_CASTLE_SUBNUMBER_MERAC	1	// ??? ??? ???? ??
#define RAID_SUBNUMBER		3			// ??? ??? ?? ?? ??
#endif

typedef struct _TimeStruct
{
	int		year;		// ?? ? ??? % 62
	int		month;		// ?
	int		day;		// ?
	int		hour;		// ?
	int		min;		// ?
	int		sec;		// ?
} TIMESTRUCT;

#define HACK_LIMIT 0.06f
#define HACK_TYPE_PULSE		0
#define HACK_TYPE_CLIENT	1

#define STATE_MONSTER_TAMING			(1 << 0)	// ??? ??? ??
#define STATE_MONSTER_CONFUSION			(1 << 1)	// ??? ?? ??
#define STATE_MONSTER_NO_SOUL			(1 << 3)	// ???? ??? ??? ??
#define STATE_MONSTER_MERCENARY			(1 << 4)	// ??? ?? ?? ?? ??
#define STATE_MONSTER_TOTEM_BUFF		(1 << 5)	// ???? ????? ??? ?? ???.
#define STATE_MONSTER_TOTEM_ATTK		(1 << 6)	// ???? ????? ??? ??.
#define STATE_MONSTER_TRAP				(1 << 7)	// ???? ????.
#define STATE_MONSTER_PARASITE			(1 << 9)	// ???? ??? ?? ??.
#define STATE_MONSTER_SUICIDE			(1 << 10)	// ???? ?? ??? ??.
#define STATE_MONSTER_TOTEM_ITEM_BUFF	(1 << 11)	// ????? ??? ??
#define STATE_MONSTER_TOTEM_ITEM_ATTK	(1 << 12)	// ????? ??? ??

#define TRIGGER_MAX_ARRAYCOUNT				10		// ??? ?? ?? ? ??? ?? ?? ? ??

//////////triggerSet_type///////
#define TRIGGERSET_ALTER_OF_DARK			1			// ??? ??
#define TRIGGERSET_CAPPELLA_1				2			// ??? 1?
#define TRIGGERSET_CAPPELLA_2				3			// ??? 1?
#define TRIGGERSET_TESTRAID					4			// ??? Raid
#define TRIGGERSET_MONDSHINE				5			// ????
#define TRIGGERSET_STREIANA					6			// ??????
#define TRIGGERSET_EGEHA					7			// ???

//////////trigger_type///////
#define TRIGGER_ITEM_COMPOSITION			1			// ??? ??
#define TRIGGER_ITEM_DROP					2			// ??? ??
#define TRIGGER_OPEN_THE_DOOR				3			// ? ??
#define TRIGGER_START_RAID					4			// ??? ??(?? ?? ?? ??)
#define TRIGGER_MESSAGE_PRINT				5			// ?? ??? ??
#define TRIGGER_SUMMON_NPC					6			// npc ??
#define TRIGGER_USE_DEBUF					7			// ??? ??
#define TRIGGER_ACTIVE_OBJECT				8			// Object ???
#define TRIGGER_REMOVE_NPC					9			// npc ?? ??
#define TRIGGER_TIME_LIMIT					10			// ?? ??
#define TRIGGER_QUEST_COMPLETE				11			// ??? ??
#define TRIGGER_ITEM_GET_INVEN				12			// ??? ??
#define TRIGGER_CONSECUTIVE_DIALOGUE		13			// ????? ??
#define TRIGGER_ACTIVE_EFFECT				14			// ??? ??

//////////trigger_Subtype_OpenTheDoor///////
#define TRIGGER_SUBTYPE_NONE_OPEN_THE_DOOR	0
#define TRIGGER_SUBTYPE_NPC_OPEN_THE_DOOR	1
#define TRIGGER_SUBTYPE_ITEM_OPEN_THE_DOOR	2

//////////trigger_Subtype_OpenTheDoor///////
#define TRIGGER_SUBTYPE_NONE_REMOVE_NPC		0
#define TRIGGER_SUBTYPE_ITEM_REMOVE_NPC		1

////////// triggerflag ////////
#define TRIGGER_FLAG_NAMEDNPC_DEATH1					(1 << 0)	// ??? ?? 1? ??? NPC ?? ? ??
#define TRIGGER_FLAG_ACTIVE_OBJECT1						(1 << 1)	// ??? ?? 3? ????1 ?? ??
#define TRIGGER_FLAG_ACTIVE_OBJECT2						(1 << 2)	// ??? ?? 3? ????2 ?? ??
#define TRIGGER_FLAG_ACTIVE_OBJECT3						(1 << 3)	// ??? ?? 3? ????3 ?? ??
#define TRIGGER_FLAG_ACTIVE_OBJECT4						(1 << 4)	// ??? ?? 3? ????4 ?? ??
#define TRIGGER_FLAG_NAMEDNPC_SUMMON1					(1 << 5)	// ??? ?? 3? ??? NPC ?? ???? ??
#define TRIGGER_FLAG_NAMEDNPC_DEATH2					(1 << 6)	// ??? ?? 3? ??? NPC ?? ? ??
#define TRIGGER_FLAG_NAMEDNPC_DEATH1_DOOR_SAVE			(1 << 7)	// ??? ?? 1? ??? NPC ??? ??? ? ??? ?? ???
#define TRIGGER_FLAG_NAMEDNPC_DEATH2_DOOR_SAVE			(1 << 8)	// ??? ?? 3? ??? NPC ??? ??? ? ??? ?? ???
#define TRIGGER_FLAG_NAMEDNPC_SUMMON_1003				(1 << 9)	// ??? ?? 3? ??? NPC ???? ?? ??? ?? ???
#define TRIGGER_FLAG_NAMEDNPC_DEATH1002_BEFORE			(1 << 10)	// ??? ?? 1? ??? NPC ?? ????? ??
#define TRIGGER_FLAG_NAMEDNPC_DEATH1003_BEFORE			(1 << 11)	// ??? ?? 3? ??? NPC ?? ????? ??
#define TRIGGER_FLAG_NAMEDNPC_DEATH1018_BEFORE			(1 << 12)	// ??? ?? 5? ??? NPC ?? ????? ??

////////// saveTriggerInfo ////////////
#define TRIGGER_SAVE_ALTER_OF_DARK_NONE		0			// ??? ?? ??? ?? ???
#define TRIGGER_SAVE_ALTER_OF_DARK_1002		1			// npc 1002? ?? ??? ??? ??
#define TRIGGER_SAVE_ALTER_OF_DARK_1003		2			// npc 1003? ?? ??? ??? ??
#define TRIGGER_SAVE_ALTER_OF_DARK_1018		3			// npc 1018? ?? ??? ??? ??, ??? ?? ???

////////// TriggerSaveMode ////////////
#define TRIGGER_MODE_NONE					0			// DB ??? ??
#define TRIGGER_MODE_SAVE					1			// DB ??? ????
#define TRIGGER_MODE_DELLETE				2			// DB ??? ???

////////// Trigger_state_flag ////////////
#define TRIGGER_PROTO_FLAG_CONTINUE			(1 << 0)	// ?? ??
#define TRIGGER_PROTO_FLAG_DOMINO			(1 << 1)	// ??? ?? ??? ??
#define TRIGGER_PROTO_FLAG_PLAY_ONE_PC		(1 << 2)	// ?? ???? ? ???? ??? ??

#define RAID_JOIN_LEVEL_LIMIT_CAPPELLA					140			// ??? ?? ?? ??
#define RAID_JOIN_LEVEL_LIMIT_ALTER_OF_DARK				160			// ?? ?? ?? ??
#define RAID_JOIN_LEVEL_LOW_LIMIT_AKAN_TEMPLE			90			// ???? ?? ?? ??
#define RAID_JOIN_LEVEL_HIGH_LIMIT_AKAN_TEMPLE			110			// ???? ?? ?? ??
#define RAID_JOIN_LEVEL_LOW_LIMIT_AKAN_TEMPLE_NORMAL	60			// ???? ?? ?? ?? ?? ???
#define RAID_JOIN_LEVEL_HIGH_LIMIT_AKAN_TEMPLE_NORMAL	80			// ???? ?? ?? ?? ?? ???
#define RAID_JOIN_LEVEL_LOW_LIMIT_AKAN_TEMPLE_HELL		120			// ???? ?? ?? ?? HELL ???
#define RAID_JOIN_LEVEL_HIGH_LIMIT_AKAN_TEMPLE_HELL		140			// ???? ?? ?? ?? HELL ???
#define RAID_JOIN_LEVEL_LOW_LIMIT_TARIAN_DUNGEON		175			// ??? ?? ?? ??
#define RAID_JOIN_LEVEL_HIGH_LIMIT_TARIAN_DUNGEON		185			// ??? ?? ?? ??

#define TITLE_SYSTEM_NO_TITLE				0			// ??? ?? ?? 0
#define TITLE_SYSTEM_OPTION_NUM				0			// CTitle? Option? ?? ?? index
#define TITLE_SYSTEM_OPTION_LEVEL			1			// CTitle? option? ?? ?? index

// ??? ???
#define QUESTITEM_MAX_ARRAYCOUNT			10		// ??? ??? ??? ?? ?? ? ??? ?? ?? ? ??

#define MAX_NORMAL_SOCKET_COUNT	6
#define MAX_CHAOS_SOCKET_COUNT	1
#define MAX_SOCKET_COUNT		(MAX_NORMAL_SOCKET_COUNT + MAX_CHAOS_SOCKET_COUNT)
#define SOCKET_DB_LENGTH	50

#define GUILD_ACTIVE_SKILL_START	-1
#define GUILD_PASSIVE_SKILL_START	-2
#define GUILD_ETC_SKILL_START		-3
#define SKILL_TYPE_ACTIVE			0
#define SKILL_TYPE_PASSIVE			1
#define SKILL_TYPE_ETC				2

// TODO
#define TOUCH_FIELD					0
#define KILL_NPC					1
#define TAKE_ITEM					2
#define ALL_IN_AREA					3
#define NO_IN_AREA					4
#define MOVE_IN_AREA				5
#define MOVE_OUT_AREA				6
#define COUNT_DOWN					7
#define START_RAID					8
#define ITEM_USE					9
#define TODO_MAX_NUM				10

// OUTPUT
#define TOUCH_FIELD					0
#define SUMMON_EXTRA				1
#define SUMMON_DISTRICT				2
#define SUMMON_MBOSS				3
#define SUMMON_BOSS					4
#define GROUND_EFFECT_ON			5
#define GROUND_EFFECT_OFF			6
#define TOGGLE_GATE					7
#define TOGGLE_PORTAL				8
#define CREATE_ITEM_OBJECT			9
#define DEBUFF_SKILL				10
#define END_RAID					11
#define PAUSE_AREA					12
#define BUFF_SKILL					13
#define TOGGLE_CAMERA				14
#define COUNT_DOWN_START			15
#define SAVE_POINT					16
#define MODEL_HOLDER_PADOX			17
#define	NPC_SAY						18
#define APPLY_SKILL					19
#define	CURE_SKILL					20
#define OUTPUT_MAX_NUM				21

#define OBJECT_DATA_FLAG_AUTO_ATTACK (1 << 0)

// OBJECT_TYPE
#define OBJECT_TYPE_TODO			0
#define OBJECT_TYPE_OUTPUT			1
#define OBJECT_TYPE_OBJECT_STATE	2
#define OBJECT_TYPE_OBJECT_REFRESH	3

#define RAID_DATA_STATE_READY		0
#define RAID_DATA_STATE_COMPLETE	1

// OBJECT_LIST
#define OBJECT_TOUCH_FIELD			0
#define OBJECT_GATE					1
#define OBJECT_PORTAL				2
#define OBJECT_ITEM					3
#define OBJECT_PADOX_MODEL			4
#define OBJECT_CAMERA				5

#define DUNGEON_DIFFICULTY_NORMAL	0
#define DUNGEON_DIFFICULTY_HARD		1
#define DUNGEON_DIFFICULTY_HELL		2

#define GUILD_MAX_GRADE_EX		29

#define RAID_RESET_TIME_HOUR		3	// ?? ?? hour
#define RAID_RESET_TIME_MIN			0	// ?? ?? min
// ? ???? ???? ??? ? ???, ???? ??? ??? ?? ? ??.
#define RAID_RESET_TIME_DAY			7	// allday ???? ???. ???? ? ?? ?? ?????? ??.
//#define RAID_RESET_TIME_DAY			0	// sun? ???
//#define RAID_RESET_TIME_DAY			1	// mon? ???
//#define RAID_RESET_TIME_DAY			2	// tue? ???
//#define RAID_RESET_TIME_DAY			3	// wed? ???
//#define RAID_RESET_TIME_DAY			4	// thu? ???
//#define RAID_RESET_TIME_DAY			5	// fri? ???
//#define RAID_RESET_TIME_DAY			6	// sat? ???

#define TREASUREBOX_DROP_LIMIT_RECT	6	// ???? ?? RECT ?? max ??
#define TREASUREBOX_DROP_LIMIT_ZONE	36	// ???? ?? zone ?? max ??
// zonedata flag
#define ZONE_FLAG_TREASUREBOX		(1<<0) // ???? ??

#define TREASURE_BOX_NPC_REGEN 1*60*60	// ???? npc regen ??. 1?? ??? npc? ????.

#define TREASURE_BOX_NPC_INDEX 1255		// ???? npc ???
#define TREASURE_MAP_ITEM_INDEX 6941	// ???? ??? ???
#define TREASURE_KEY_ITEM_INDEX 6939	// ???? ?? ?? ??? ???

#if defined(LC_GAMIGO) || defined (LC_USA) || defined (LC_BILA) || defined (LC_RUS)
#define WAR_GROUND_CHANNEL			4
#else
#define WAR_GROUND_CHANNEL			2
#endif
#define	MAX_ROYAL_RUMBLE_PLAYER		40
#define	MIN_ROYAL_RUMBLE_PLAYER		10
#define	MIN_ROOKIE_LEVEL			50
#define	MAX_ROOKIE_LEVEL			89
#define MIN_SENIOR_LEVEL			90
#define MAX_SENIOR_LEVEL			120
#define	MIN_MASTER_LEVEL			121
#define	MAX_MASTER_LEVEL			MAX_LEVEL
#define LEVEL_TYPE_ROOKIE			0
#define	LEVEL_TYPE_SENIOR			1
#define LEVEL_TYPE_MASTER			2
#define LEVEL_TYPE_ALL				3
#define ROOKIE_REGIST_NEED_PRICE	1000000
#define	SENIOR_REGIST_NEED_PRICE	10000000
#define	MASTER_REGIST_NEED_PRICE	100000000
#define ROOKIE_REGIST_ITEM			7340
#define SENIOR_REGIST_ITEM			7341
#define MASTER_REGIST_ITEM			7342
#define PLAYER_NOT_SORT				0 // ???
#define PLAYER_SELECTED				1 // ???
#define PLAYER_DROP					2 // ??
#define PLAYER_DRAW					3 // ?? ???
#define PLAYER_GREATER_THEN_MAX		0 // ???? maximum?? ??
#define PLAYER_SMALLER_THEN_MIN		1 // ???? minimum?? ??
#define PLAYER_BETWEEN_MIN_AND_MAX	2 // ???? min~max??.
#define DEBUFF_TYPE_20MINUTE		0
#define DEBUFF_TYPE_8PLAYER			1
#define DEBUFF_TYPE_PEACEZONE		2
#define ROYAL_RUMBLE_DEBUFF_SKILL	1355 // ???? 1? ??
#define WARGROUND_MAX_POINT			1000000
#define WARGROUND_MAX_ACC_POINT		10000000
#define ROYAL_RUMBLE_SCHEDULE		5	// ?? ????
#if defined (LC_TLD)
#define ROYAL_RUMBLE_START_HOUR		21
#elif defined (LC_USA)
#define ROYAL_RUMBLE_START_HOUR		16
#else
#define ROYAL_RUMBLE_START_HOUR		22
#endif

#define LEVEL_COUNT		2

#ifdef DEV_GUILD_MARK
#define GUILD_MARK_SKILL_INDEX	1378
#endif

#ifdef DEV_GUILD_STASH
#define GUILD_STASH_KEEP_LOG	0
#define GUILD_STASH_TAKE_LOG	1
#endif // DEV_GUILD_STASH
#define MAX_TITLE_COUNT	200

#define RANKING_REFRESH_DAY 1	// ?? ?? ?? (0:??? ~ 6:???)
#define RANKING_REFRESH_HOUR 6	// ?? ?? ??

typedef enum _tagRankingTypeEx
{
	RANKTYPE_LEVELMASTER	= 0,
	RANKTYPE_JOBRANKER		= 1,
} RANKING_TYPE_EX;

//////////////////////////////////////////////////////////////////////////
typedef enum _eventLogType
{
	EVENT_LOGTYPE_AFFINITY_LAKIN	= 0,
	EVENT_LOGTYPE_KILL_EREBUS		= 1,
	EVENT_LOGTYPE_KOKO_MYUN			= 2,
} EVENT_LOG_TYPE;

typedef enum _tagProgressType
{
	PROGRESS_TYPE_NONE = -1,
	PROGRESS_TYPE_CRAFT = 0,
	PROGRESS_TYPE_DECOMPOSE,
	PROGRESS_TYPE_PRODUCE
} PROGRESS_TIME_TYPE;

typedef enum _tagNpcProdceState
{
	NPC_PRODUCE_STATE_ALIVE,	// ?? ?? ??
	NPC_PRODUCE_STATE_LOOT,		// ? ?? ??
	NPC_PRODUCE_STATE_DEAD,		// ?? ??
} NPC_PRODUCE_STATE;

typedef enum _tagLootType
{
	LOOT_TYPE_PC  = 1,	// CPcLootManager
	LOOT_TYPE_MOB,		// CMobLootManager
} LOOT_TYPE;

#define KICK_RESERVE_TIME			86400	// 1?
#define LAST_CONNECT_TIME_FOR_KICK	604800	// 7?
enum _eKickStatus
{
	GMKS_NORMAL		=	0,
	GMKS_RESERVE	=	1,
};

#if defined (GUILD_REMOTE_INVITE)
enum _eRemoteInviteType
{
	GRI_MASTER		=	0,		// ??? ?? ??
	GRI_JOINER		=	1,		// ??? ?? ??
};
#endif // GUILD_REMOTE_INVITE

typedef enum  _eventAutomationType
{
	A_EVENT_SEPTEMBER		= 5,	// 9? ?? ?? ???
	A_EVENT_RAIN_DROP		= 20,	// ??? ???
	A_EVENT_COLLECT_BUG		= 22,	// ?? ?? ???
	A_EVENT_CHUSUK			= 25,	// ?? ???
	A_EVENT_PANDORA_BOX		= 26,	// ???? ?? (??? 2006 ???, ?? ?? ???)
	A_EVENT_VALENTINE_DAY	= 29,	// ???? ?? ???
	A_EVENT_WHITE_DAY		= 31,	// ??? ??
	A_EVENT_SONGKRAN		= 32,	// ??? ???
	A_EVENT_EGGS_HUNT		= 33,	// ??? ???
	A_EVENT_BEAR_DOLL		= 35,	// ??? ???
	A_EVENT_INDEPENDENCE_DAY= 40,	// ?????
	A_EVENT_HALLOWEEN		= 49,	// ???
	A_EVENT_XMAS			= 50,	// ????? ???
	A_EVENT_GOLDEN_WEEK		= 62,	// ?? ?? ???
	A_EVENT_MAGIC_CARD		= 74,	// ?? ?? ??? // 2008 ?? ???? ???.
	A_EVENT_APRIL_FOOL		= 75,	// 4? ???
	A_EVENT_WORLDCUP_TOTO	= 80,
	A_EVENT_WORLDCUP_TOTO_STATUS = 81,
	A_EVENT_WORLDCUP_TOTO_GIFT = 82,
	A_EVENT_ARTIFACT_HUNTER	= 84,
	A_EVENT_DOUBLE_AFFINITY = 85,
	A_EVENT_DOUBLE_EXP = 86,
	A_EVENT_DOUBLE_EXP_PET = 87,
	A_EVENT_DOUBLE_QUEST_EXP = 88,
	A_EVENT_CASH_INCREASE_WEEKEND = 89,
	A_EVENT_DOUBLE_CUBE = 90,
	#ifdef DOMINATION_EVENT_SYSTEM
	A_EVENT_DOMINATION_PVP = 91,
	#endif
} EVENT_AUTOMATION_TYPE;

typedef enum _indexDataType
{
	INDEX_DATA_EXP_RATIO = 0,
	INDEX_DATA_SP_RATIO,
	INDEX_DATA_MAX,
} INDEX_DATA_TYPE;

#define PC_MIN_RUNSPEED	2.0f		// ??? ?? ???

#define SERVER_TRANS_ERROR_SUCCESS				(0 << 0)
#define	SERVER_TRANS_ERROR_EXIST_GUILD		(1 << 0)		//	??? ?? ??
#define	SERVER_TRANS_ERROR_EXIST_GUARDIAN	(1 << 1)		//	???? ?? ??
#define	SERVER_TRANS_ERROR_30DAYS				(1 << 2)		//	???? 30?? ????
#define	SERVER_TRANS_ERROR_BLOCK_SERVER		(1 << 3)		//	??? ?? ??? ??
#define	SERVER_TRANS_ERROR_INVALID_SERVER	(1 << 4)
#define SERVER_TRANS_ERROR_DB_INSERT			(1 << 5)
#define SERVER_TRANS_ERROR_NOT_EXIST_ITEM	(1 << 6)		//  ??? ??? ??
#define SERVER_TRANS_ERROR_ROLLBACK_SUCCESS (1 << 7)		//  ?? ??

#define GOLD_MAGNIFIER			1839	// ?? ??? ??? ???
#define MAX_VARIATION_COUNT		6

enum eITEM_GRADE
{
	eITEM_GRADE_NORMAL		= -1,	//?? ??
	eITEM_GRADE_RARE_HERO,			//?? ????
	eITEM_GRADE_RARE_UNIQUE,		//?? ????
	eITEM_GRADE_RARE_RARE,			//?? ????
	eITEM_GRADE_RARE_MAGIC,			//?? ????
	eITEM_GRADE_RARE_BASIC,			//?? ????
	eITEM_GRADE_RARE_NOTOPEN,		//?? ??? ??
	eITEM_GRADE_ORIGIN,				//?? ??

	eITEM_GRADE_MAX
};

#define AFFINITY_INFOTAB_SUCCESS			(0 << 0)		//??? ??? ??
#define AFFINITY_INFOTAB_ERROR_NOTEXIST		(1 << 0)		//??? ??? ??
#define AFFINITY_INFOTAB_NOT_REWARD			(1 << 1)		//?? ??? ??

#define JEWEL_COMPOSITE_POSITION_WEAPON		(1 << 0)
#define JEWEL_COMPOSITE_POSITION_HELMET		(1 << 1)
#define JEWEL_COMPOSITE_POSITION_ARMOR		(1 << 2)
#define JEWEL_COMPOSITE_POSITION_PANTS		(1 << 3)
#define JEWEL_COMPOSITE_POSITION_GLOVES		(1 << 4)
#define JEWEL_COMPOSITE_POSITION_SHOES		(1 << 5)
#define JEWEL_COMPOSITE_POSITION_SHIELD		(1 << 6)
#define JEWEL_COMPOSITE_POSITION_BACKWING	(1 << 7)
#define JEWEL_COMPOSITE_POSITION_ACCESSORY	(1 << 8)
#define JEWEL_COMPOSITE_POSITION_ALL		511

#define JEWEL_MAX_LEVEL						20		//15->20
#define JEWEL_POCKET_MAX_LEVEL				19		//14->19
#ifdef CIRCLE_WINDOWS
typedef __int64 GoldType_t;
#else
typedef long long GoldType_t;
#endif

#define MAX_PET_STASH_KEEP_COUNT	20		//? ?? ?? ?? ??
#define PET_STASH_INCREASE_POINT	1		//? ????? ?? ??(???, ???)
#define MAX_EFFECT_COUNT			5		//? ?? ??? ??? ?? ? ?? ??? ?? ??

#define IMMUN_SKILL_MCT_TIME		120

#define NAS_ITEM_DB_INDEX			(19)

#define SYDICATE_QUEST_LIST_PERCENT 30		// ??? ??? ?? ??
#define SYNDICATE_OUT_NEEDNAS		10000000

namespace SYNDICATE
{
enum eSYNDICATE_TYPE
{
	eSYNDICATE_NONE		= 0	,		// ???
	eSYNDICATE_KAILUX		,		// ????	: PC ? NPC ?? ??
	eSYNDICATE_DEALERMOON	,		// ???	: PC ? NPC ?? ??
	eSYNDICATE_FLOR			,		// ???	: NPC?? ??
	eSYNDICATE_MAX			,		// max value
};

enum eSYNDICATE_HISTORY_TYPE
{
	JOIN,			// ??
	REMOVE,			// ??
	DEGRADE,		// ??
	PROMOTION,		// ??
	WIN,			// ??
	LOSE,			// ??
};

enum eSYNDICATE_GRADE
{
	SQUIRE		= 1	,		// ?? ?? ????
	KNIGHT			,		// ?? ??
	GENTOR			,		// ?? ??
	HONORISE		,		// ???
	BARONE			,		// ??
	VISCONTE		,		// ??
	CONTE			,		// ??
	MARQUISE		,		// ??
	DUKA			,		// ??
	PRINCIPE		,		// ??

	NEOPTYE		= 1	,		// ??? ???
	ZELATOR			,		// ???
	THEORICUS		,		// ???
	PHILOSOPHUS		,		// ????
	ADEPTUS			,		// ??? ??? ?
	MAGUS			,		// ??? ??? ?
	IPSISSIMUS		,		// ???? ?? ?
};

#define		SQUIRE_POINT		104999
#define		KNIGHT_POINT		188999
#define		GENTOR_POINT		256199
#define		HONORISE_POINT		310799
#define		BARONE_POINT		352799
#define		VISCONTE_POINT		382199
#define		CONTE_POINT			403199
#define		MARQUISE_POINT		415799

#define		NEOPTYE_POINT		146999
#define		ZELATOR_POINT		251999
#define		THEORICUS_POINT		335999
#define		PHILOSOPHUS_POINT	377999
#define		ADEPTUS_POINT		415799

#ifdef  WIN32
inline int getSyndicateGrade(int syndicateType, __int64 point)
#else
inline int getSyndicateGrade(int syndicateType, long long point)
#endif
{
	switch(syndicateType)
	{
	case eSYNDICATE_KAILUX:
		{
			if (0 <= point && point <= SQUIRE_POINT)
				return SQUIRE;
			else if (SQUIRE_POINT < point && point <= KNIGHT_POINT)
				return KNIGHT;
			else if (KNIGHT_POINT < point && point <= GENTOR_POINT)
				return GENTOR;
			else if (GENTOR_POINT < point && point <= HONORISE_POINT)
				return HONORISE;
			else if (HONORISE_POINT < point && point <= BARONE_POINT)
				return BARONE;
			else if (BARONE_POINT < point && point <= VISCONTE_POINT)
				return VISCONTE;
			else if (VISCONTE_POINT < point && point <= CONTE_POINT)
				return CONTE;
			else if (CONTE_POINT < point && point <= MARQUISE_POINT)
				return MARQUISE;
			else
				return DUKA;
		}
		break;
	case eSYNDICATE_DEALERMOON:
		{
			if (0 <= point && point <= NEOPTYE_POINT)
				return NEOPTYE;
			else if (NEOPTYE_POINT < point && point <= ZELATOR_POINT)
				return ZELATOR;
			else if (ZELATOR_POINT < point && point <= THEORICUS_POINT)
				return THEORICUS;
			else if (THEORICUS_POINT < point && point <= PHILOSOPHUS_POINT)
				return PHILOSOPHUS;
			else if (PHILOSOPHUS_POINT < point && point <= ADEPTUS_POINT)
				return ADEPTUS;
			else
				return MAGUS;
		}
		break;
	default:
		return 0;
	}
}

#ifdef  WIN32
inline __int64	getSyndicateGradeMaxPoint(int syndicateType, int grade)
#else
inline long long getSyndicateGradeMaxPoint(int syndicateType, int grade)
#endif
{
	switch(syndicateType)
	{
	case eSYNDICATE_KAILUX:
		{
			if (grade == SQUIRE)
				return SQUIRE_POINT;
			else if (grade == KNIGHT)
				return KNIGHT_POINT;
			else if (grade == GENTOR)
				return GENTOR_POINT;
			else if (grade == HONORISE)
				return HONORISE_POINT;
			else if (grade == BARONE)
				return BARONE_POINT;
			else if (grade == VISCONTE)
				return VISCONTE_POINT;
			else if (grade == CONTE)
				return CONTE_POINT;
			else if (grade == MARQUISE)
				return MARQUISE_POINT;
			else
				return 0;
		}
		break;
	case eSYNDICATE_DEALERMOON:
		{
			if (grade == NEOPTYE)
				return NEOPTYE_POINT;
			else if (grade == ZELATOR)
				return ZELATOR_POINT;
			else if (grade == THEORICUS)
				return THEORICUS_POINT;
			else if (grade == PHILOSOPHUS)
				return PHILOSOPHUS_POINT;
			else if (grade == ADEPTUS)
				return ADEPTUS_POINT;
			else
				return 0;
		}
		break;
	default:
		return 0;
	}
}
}

#define PS_MAX_SHOPNAME				100		// ?? ?? ?? ?? 100 ???

enum
{
	TOGGLE_SKILL = 0,
	TOGGLE_ITEM,
};

enum
{
	ITEM_CASTLE_WAR_FLAG_DONE,
	ITEM_CASTLE_WAR_FLAG_ALL,
	ITEM_CASTLE_WAR_FLAG_MERAC,
	ITEM_CASTLE_WAR_FLAG_DRATAN,
};

#define CASTLE_DUNGEON_ENV_CHANGE_NEED_NAS_OWNER	500000
#define CASTLE_DUNGEON_ENV_CHANGE_NEED_NAS_NORMAL	1000000	


enum
{
	MOVE_TO_GUILDROOM = 0,
};

#define ARTIFACT_FIND_GPS_ITEM_INDEX	10954

enum MasterStone { LOWER_MASTERSTONE=6111, LOW_MASTERSTONE=6112, NORMAL_MASTERSTONE=6113, HIGH_MASTERSTONE=6114, HIGHER_MASTERSTONE=6115, MASTERSTONE=6124, ARMOR_MASTERSTONE=6120 ,
	LOWER_MASTERTONE2=7730, LOW_MASTERSTONE2=7731, NORMAL_MASTERSTONE2=7732, HIGH_MASTERSTONE2=7733, MASTERSTONE2=7734, MASTERSTONE3=7735, MASTERSTONE4=10970, MASTERSTONE5=10971,
};

#define MASTERSTONE_SUCCESS_START_PROB		3300
#define MASTERSTONE_SUCCESS_NOCHANGE_PROB	3400
#define MASTERSTONE_SUCCESS_FAIL_PROB		3300

#define CUSTOM_TITLE_DUMMY_INDEX			199

#define CUSTOM_TITLE_ITEM_INDEX				11037

#define CASH_ITEM_100	15198
#define CASH_ITEM_1000	15199
#define CASH_ITEM_50	15200
#define PREMIUM_NAME_CHANGE_ITEM 15435
#define PREMIUM_GUILD_NAME_CHANGE_ITEM 15436
#define SP_ITEM_100		16671
#define SP_ITEM_50		16672
#define SP_ITEM_20		16673
#define LUCKDRAW_RELOAD
#define REWARD_RELOAD
#define OPTION_RELOAD
#endif // __GAME_Config_H__ 0
