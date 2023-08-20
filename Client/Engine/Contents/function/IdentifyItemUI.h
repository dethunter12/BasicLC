#ifndef UI_IdentifyItem_H_
#define UI_IdentifyItem_H_
#ifdef IDENTIFY_ITEM_02212023
#include <functional>
#include <Engine/Interface/UIWindow.h>

class CUIEditBox;
class CUIList;
class CUIImage;
class CUIText;
class CUITextBox;
class CUIButton;
class CUIBase;
class CUIScrollBar;
class CUIIcon;

class CAction;
class CSkill;
class CSpecialSkill;
class CAction;

#define MAX_ITEMS_IDENTIFY 25

class CUIIdentifyItem : public CUIWindow
{
public:
	CUIIdentifyItem();

	void initialize();
	void Open();
	void Close();;
	BOOL CloseWindowByEsc();
	void ErrMessage(int errCode);

	void	UseQuickSlot();
	void    ResetallBtns();
	void	UseIdentifyReq();
	void    GetRandomItems();
	void    ClearItems();
	BOOL	ProcessShortCut(MSG* pMsg);
	bool ExistItemSlot(CItems* item);
	void AddItemToSlot(CItems* item);
	bool IsRareItem(CItems* item);

protected:
	WMSG_RESULT OnLButtonDown(UINT16 x, UINT16 y);
	WMSG_RESULT OnLButtonUp(UINT16 x, UINT16 y);
	WMSG_RESULT OnMouseMove(UINT16 x, UINT16 y, MSG* pMsg);

	int m_count_command;
	int m_nOldSelectIdx;
	int m_selected_command;

	CUIText* m_NazwaPostaci;
	BOOL				m_bIsInside;
	void	AddBtn(int nSlotType = -1, int nData0 = -1, int nData1 = -1);
	// Network message functions ( send )
	void	SendAddBtn(int nSlotType = -1, int nData0 = -1, int nData1 = -1);

private:
	int						m_nIdxItemSpecialSkill;
	CSkill* m_pSkill;
	enum eERR_MSG
	{
		eERR_CAN_NOT_OPEN_KEY = 0,
		eERR_EMPTY_KEY,
		eERR_MAX
	};

	CUIButton* m_pBtnInput;				// ConsoleGM
	CUIButton* m_pbtnClose;				// ConsoleGM
	CUIButton* m_pbtnUse;				// ConsoleGM
	CUIButton* m_pbtnGrabItem; 
	CUIImage* m_pConsoleGM;				// ConsoleGM

	
	CUIIcon* m_pIcon[MAX_ITEMS_IDENTIFY];
	CUIText* m_pDrag;
	CItems* m_pSendItems;

	bool		m_bDrag;
	int			m_nOriX, m_nOriY;
	bool canPutItem(int iconcount, CItems* item);

	int	 m_nCashBagNum;
};

#endif
#endif
