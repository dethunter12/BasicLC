#ifndef		COMMON_DEF_H_
#define		COMMON_DEF_H_

#define 	CEHACK
	
#define		DURABILITY
#define		NAS_ITEM_DB_INDEX			(19)

#if defined ADD_SUBJOB
	#define ENABLE_SUBJOB
#endif	//	ADD_SUBJOB

#if defined GUILD_MARK
	#define DEV_GUILD_MARK
#endif	//	GUILD_MARK
#define DECRYPTXOR
#define DEV_EXP_APET
#define		BATTLE_PASS_SYSTEM
#define     EXPANSION_INVENTORY
#define CLOUD_ANTI_INJECT
#define ENABLE_REMOVE_BUFF_RIGHT_CLICK
#define     DOMINATION_EVENT_SYSTEM
#define CUBE_RANKING_12202022
#define IDENTIFY_ITEM_02212023
#define GLADES_RANKING_04182023
// 임시 define //////
#define WEARING_SHOW_END	6
#define MAX_GUILD_NAME_LENGTH 50
#define APET_WEARPOINT		4
#define MAX_SERIAL_LENGTH	20
#define MAX_SOCKET_COUNT	7
#define	MAX_ITEM_OPTION		5
#define MAX_ORIGIN_OPTION	6
#define	MAX_CHAR_NAME_LENGTH	50
#define	MAX_ID_NAME_LENGTH		64


#define		MEMPOS_COMMENT_LENGTH_RUS	25
#define		MEMPOS_COMMENT_LENGTH		32


#define		PREMIUM_CHAR // 가미고에서 요청한 프리미엄 캐릭터

typedef __int64		GoldType_t;

#define MAX_PWD_LENGTH				32	

#define NOTICE_PICKUP_ITEM
#ifdef NOTICE_PICKUP_ITEM
#define NOTICE_PICKUP_ITEM_MAX						5 // max show
#define NOTICE_PICKUP_ITEM_ICON_WIDTH				32 // icon width
#define NOTICE_PICKUP_ITEM_ICON_HEIGHT				32 // icon height
#define NOTICE_PICKUP_ITEM_ICON_POSITION			1 // 0 - left / 1 - right
#define NOTICE_PICKUP_ITEM_ICON_SHIFT_X				50 // icon shift along the axis X
#define NOTICE_PICKUP_ITEM_ICON_SHIFT_Y				140 // icon shift along the axis Y
#define NOTICE_PICKUP_ITEM_ICON_ICON_SHIFT			8 // vertical padding between icons
#define NOTICE_PICKUP_ITEM_FIDE_IN_TIME				1000 // fade in time (ms)
#define NOTICE_PICKUP_ITEM_FIDE_SHOW_TIME			5000 // show time (ms)
#define NOTICE_PICKUP_ITEM_FIDE_OUT_TIME			500 // fade out time (ms)
#define NOTICE_PICKUP_ITEM_BACK_PADDING				5 // background padding
#endif

#endif		// COMMON_DEF_H_