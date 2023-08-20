#ifndef _UI_TRADE_H_
#define _UI_TRADE_H_

class CUITrade : public CUIWindow
{
public:
	CUITrade();
	~CUITrade();

	void initialize();
	void OpenUI(int npc_index); //dethunter12 item check 
	void CloseUI();
	
	BOOL CloseWindowByEsc()		{ CloseUI();	return TRUE;	}

	void SetTitle(std::string strTitle);

	// 보상 받겠다.
	void SendTrade();

	// º¸≫o ¾ÆAIAU ¸®½ºÆ®.
	void UpdateItemList(int npc_index); //dethunter12 add 11/13/2019
	// º¸≫oC°A≫ ¹Þ±a A§CN CE¿a ¾ÆAIAU.
	void UpdateAmendCondition(int nAmendIndex);
	// 보상품을 받기 위한 필요 아이템 갯수. 
	// amendindex가 0보다 작을 경우 현재 선택된 아이템 카운트를 업데이트.
	void UpdateAmendConditionCount(int nAmendIndex);
	// 보상 아이템 상세 정보.
	void UpdateAmendItem(int nAmendIndex);
	// 보상 아이템 갯수.
	void UpdateAmendItemCount(int nAmendIndex);
	
	// 보상 받을수 있는지 검사.
	bool IsAmend(int nAmendIndex);

	WMSG_RESULT OnMouseMove(UINT16 x, UINT16 y, MSG* pMsg);
	WMSG_RESULT OnLButtonDown(UINT16 x, UINT16 y);
	WMSG_RESULT OnLButtonUp(UINT16 x, UINT16 y);
	WMSG_RESULT OnLButtonDBLClick(UINT16 x, UINT16 y);

    void ResetPosition(PIX pixMinI, PIX pixMinJ, PIX pixMaxI, PIX pixMaxJ);
    void AdjustPosition(PIX pixMinI, PIX pixMinJ, PIX pixMaxI, PIX pixMaxJ);

private:
	enum
	{
		eLIST_AMEND_ITEM = 0,
		eLIST_AMEND_CONDITION,
		eLIST_END
	};

	bool CheckItem(int nAmendIndex, int nConditionIndex);

	CUIBase*	m_pDragArea;
	CUIButton*	m_pBtnOk;
	CUIText*	m_pTextTitle;

	CUIList*	m_pList[eLIST_END];
	CUIBase*	m_pBaseAmendInfo;
	CUIScrollBar* m_plistScroll;
	

	int m_nOriX;
	int m_nOriY;
	bool m_bDrag;

	std::vector<int> m_currentItems;
};
#endif // _UI_TRADE_H_