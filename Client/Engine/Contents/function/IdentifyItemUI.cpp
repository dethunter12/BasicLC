#include "stdh.h"
#include <Engine/Interface/UIInternalClasses.h>
#include "IdentifyItemUI.h"
#include <Engine/Interface/UIMessenger.h>
#include <Engine/Info/MyInfo.h>
#include <Engine/Contents/Base/UICharacterInfoNew.h>
#include <Engine/Base/KeyNames.h>
#include <Engine/Interface/UIInventory.h>
#include <Engine/Interface/UICashShopEX.h>
#include <Engine/Interface/UIHelp.h>
#include <Engine/Interface/UIReformSystem.h>
#include <Engine/Contents/Base/UIRankingSystem.h>
#include <Engine/Interface/UIGuild.h>
#include <Engine/Contents/function/WildPetInfoUI.h>
#include <Engine/Interface/UIPetInfo.h>
#include <Engine/Entities/InternalClasses.h>
#ifdef IDENTIFY_ITEM_02212023

class IdentifyUIClose : public Command
{
public:
	IdentifyUIClose() : m_pWnd(NULL) {}
	void setData(CUIIdentifyItem* pWnd) { m_pWnd = pWnd; }
	void execute()
	{
		if (m_pWnd)
			m_pWnd->Close();
	}
private:
	CUIIdentifyItem* m_pWnd;
};

class CmdIdentifyUIOkay : public Command
{
public:
	CmdIdentifyUIOkay() : m_pWnd(NULL) {}
	void setData(CUIIdentifyItem* pWnd) { m_pWnd = pWnd; }
	void execute()
	{
		if (m_pWnd)
		{
			m_pWnd->UseQuickSlot();
		}
	}
private:
	CUIIdentifyItem* m_pWnd;
};

class CmdIdentifyUIGrabItems : public Command
{
public:
	CmdIdentifyUIGrabItems() : m_pWnd(NULL) {}
	void setData(CUIIdentifyItem* pWnd) { m_pWnd = pWnd; }
	void execute()
	{
		if (m_pWnd)
		{
			m_pWnd->GetRandomItems();
		}
	}
private:
	CUIIdentifyItem* m_pWnd;
};

CUIIdentifyItem::CUIIdentifyItem()
	:
	m_pDrag(NULL)
	, m_nOriX(0)
	, m_pbtnClose(NULL)
	, m_pbtnUse(NULL)
	, m_pbtnGrabItem(NULL)
	, m_nOriY(0)
	, m_bDrag(false)
	, m_nCashBagNum(-1)
	, m_pSendItems(NULL)


{
	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		m_pIcon[i] = NULL;
	}
	setInherit(false);
}

void CUIIdentifyItem::initialize()
{
	m_pConsoleGM = (CUIImage*)findUI("img_back");
	m_pDrag = (CUIText*)findUI("base_drag_area");
	m_pbtnClose = (CUIButton*)findUI("btn_close");
	m_pbtnUse = (CUIButton*)findUI("btn_use");
	m_pbtnGrabItem = (CUIButton*)findUI("btn_grabItem");

	//click close button
	if (m_pbtnClose != NULL)
	{
		IdentifyUIClose* pCmd = new IdentifyUIClose;
		pCmd->setData(this);
		m_pbtnClose->SetCommandUp(pCmd);
	}
	// click use button 
	if (m_pbtnUse != NULL)
	{
		CmdIdentifyUIOkay* pCmd = new CmdIdentifyUIOkay;
		pCmd->setData(this);
		m_pbtnUse->SetCommandUp(pCmd);
	}
	//if they clicked the grab item button
	if (m_pbtnGrabItem != NULL)
	{
		CmdIdentifyUIGrabItems* pCmd = new CmdIdentifyUIGrabItems;
		pCmd->setData(this);
		m_pbtnGrabItem->SetCommandUp(pCmd); 
	}
	//Lets set default icon information (cleared)

	CTString strIconId;
	for (int i = 0; i < MAX_ITEMS_IDENTIFY; ++i)
	{
		strIconId.PrintF("icon_%d", i);
		m_pIcon[i] = (CUIIcon*)findUI(strIconId);

		if (m_pIcon[i] != NULL)
			m_pIcon[i]->clearIconData();
	}

}

void CUIIdentifyItem::Open()
{
	CUIManager* pUIManager = CUIManager::getSingleton();

	if (pUIManager->GetInventory()->IsLocked() ||
		pUIManager->GetInventory()->IsLockedArrange())
	{
		pUIManager->GetInventory()->ShowLockErrorMessage();
		return;
	}

	Hide(FALSE);
	SetVisible(TRUE);

	UIMGR()->RearrangeOrder(UI_IDENTIFYFUNC, TRUE);
	//push UI to front -> then lock the inventory
	pUIManager->GetInventory()->Lock(TRUE, TRUE, LOCK_IDENTIFY_ITEM);
}

void CUIIdentifyItem::Close()
{
	SetVisible(FALSE);
	Hide(TRUE);
	ClearItems(); //clear the array of items

	//Destroy();
	UIMGR()->RearrangeOrder(UI_IDENTIFYFUNC, FALSE);
	UIMGR()->GetInventory()->Lock(FALSE, FALSE, LOCK_IDENTIFY_ITEM); //unlock inventory if they close..
}

void CUIIdentifyItem::ClearItems()
{
	int i;
	for (i = 0; i < MAX_ITEMS_IDENTIFY; ++i)
	{
		m_pIcon[i]->clearIconData();
	}
}

BOOL CUIIdentifyItem::CloseWindowByEsc()
{
	Close();
	return TRUE;
}

WMSG_RESULT CUIIdentifyItem::OnLButtonDown(UINT16 x, UINT16 y)
{
	if (m_bHide)
		return WMSG_FAIL;
	//ensure the user dragged the item in the correct spot

	if (IsInside(x, y) == FALSE)
		return WMSG_FAIL;

	 

	if (m_pDrag && m_pDrag->IsInside(x, y))
	{
		m_bDrag = true;
		m_nOriX = x;
		m_nOriY = y;
	}

	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		if (m_pIcon[i] && m_pIcon[i]->IsInside(x, y))
		{
			if (m_pIcon[i] != NULL)
				m_pIcon[i]->clearIconData();
		}
	}

	CUIManager::getSingleton()->RearrangeOrder(UI_IDENTIFYFUNC, TRUE);
	return CUIBase::OnLButtonDown(x, y);
}

WMSG_RESULT CUIIdentifyItem::OnLButtonUp(UINT16 x, UINT16 y)
{
	CUIManager* pUIManager = CUIManager::getSingleton();

	if (m_bHide)
		return WMSG_FAIL;

	m_bDrag = false;

	if (IsInside(x, y) == FALSE)
		return WMSG_FAIL;

	// if message box exist give error
	if (CUIIcon* pDrag = pUIManager->GetDragIcon())
	{
		for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
		{
			if (m_pIcon[i] != NULL && m_pIcon[i]->IsInside(x, y) && pDrag->getBtnType() == UBET_ITEM)
			{
				CItems* item = pDrag->getItems();
				CItemData* itemData = item->ItemData;

				if (canPutItem(i, item))
				{
					CItems* newItem = new CItems;
					memcpy(newItem, item, sizeof(CItems));

					m_pIcon[i]->setData(newItem);
				}
			}
		}
		pUIManager->ResetHoldBtn();
		return WMSG_SUCCESS;
	}

	pUIManager->ResetHoldBtn();
	return WMSG_FAIL;
	
}


WMSG_RESULT CUIIdentifyItem::OnMouseMove(UINT16 x, UINT16 y, MSG* pMsg)
{
	if (m_bHide)
		return WMSG_FAIL;

	if (m_bDrag && (pMsg->wParam & MK_LBUTTON))
	{
		int ndX = x - m_nOriX;
		int ndY = y - m_nOriY;

		m_nOriX = x;
		m_nOriY = y;

		Move(ndX, ndY);
		return WMSG_SUCCESS;
	}

	if (IsInside(x, y) == FALSE)
		return WMSG_FAIL;

	CUIManager::getSingleton()->SetMouseCursorInsideUIs();
	return WMSG_FAIL;
}

bool CUIIdentifyItem::canPutItem(int iconcount, CItems* item)
{
	if (!item)
		return false;

	CUIManager* pUIManager = CUIManager::getSingleton();

	pUIManager->GetMessenger()->SetDragging(false);


	CUIIcon* pDrag = pUIManager->GetDragIcon();
	CItemData* itemData = item->ItemData;

	if (!pDrag)
		return false;

	if (!itemData)
		return false;

	if (item->Item_UniIndex != pUIManager->GetInventory()->GetItemUniIndex(item->Item_Tab, item->InvenIndex))
		return false;

	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		if (m_pIcon[i])
		{
			CItems* iconItem = m_pIcon[i]->getItems();
			if (iconItem)
			{
				if (iconItem->Item_Tab == item->Item_Tab &&
					iconItem->InvenIndex == item->InvenIndex)
				{
					return false;
				}
			}
		}
	}

	if (!IsRareItem(item))
	{
		ErrMessage(eERR_CAN_NOT_OPEN_KEY);
		return false;
	}

	return true;
}


bool CUIIdentifyItem::IsRareItem(CItems* item)
{

	//If they already identified it then its not permittable to be in the slot.
	if (item->Item_RareIndex > 0)
	{
		return false;
	}

	if (item->ItemData->GetType() != CItemData::ITEM_SHIELD && item->ItemData->GetType() != CItemData::ITEM_WEAPON)
	{
		return false;
	}

	if (!(item->ItemData->GetFlag() & ITEM_FLAG_RARE))
	{
		return false;
	}

	return true;
}
void CUIIdentifyItem::ErrMessage(int errCode)
{
	CUIManager* pUIManager = CUIManager::getSingleton();
	CTString strMessage;
	CUIMsgBox_Info	MsgBoxInfo;

	MsgBoxInfo.SetMsgBoxInfo(_S(191, "Confirm"), UMBS_OK, UI_NONE, MSGCMD_NULL);

	switch (errCode)
	{
	case eERR_CAN_NOT_OPEN_KEY:
	{
		strMessage.PrintF(_S(100099, "You can not use the lack of Skill"));//4783 4783
	}
	break;
	case eERR_EMPTY_KEY:
	{
		strMessage.PrintF(_S(100100, "You can not use the lack of Skill"));//4783 4783
	}
	break;
	}
	if (strMessage.IsEmpty() == FALSE)
	{
		MsgBoxInfo.AddString(strMessage);
		pUIManager->CreateMessageBox(MsgBoxInfo);
	}

	m_pSendItems = NULL;

}
//complete this function :: Get random item from inventory 25 of them and fill them into the slot?
void CUIIdentifyItem::GetRandomItems()
{
	int	t, i, slot;
	for (t = 0; t <= INVENTORY_TAB_CASH_6; ++t) //4-6
	{
		slot = UIMGR()->GetInventory()->GetCurTabSlotCount(t);

		for (i = 0; i < slot; ++i)
		{
			if (_pNetwork->MySlotItem[t][i].ItemData == NULL)
				continue;

			if (!IsRareItem(&_pNetwork->MySlotItem[t][i]))
				continue;

			if (!ExistItemSlot(&_pNetwork->MySlotItem[t][i]))
			{
				AddItemToSlot(&_pNetwork->MySlotItem[t][i]);
			}
		}
	}
}

void CUIIdentifyItem::AddItemToSlot(CItems* item)
{
	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		if (m_pIcon[i] && m_pIcon[i]->IsEmpty())
		{
			m_pIcon[i]->setData(item);
			return;
		}
	}
}

bool CUIIdentifyItem::ExistItemSlot(CItems* item)
{
	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		if (m_pIcon[i] && !m_pIcon[i]->IsEmpty())
		{
			if (m_pIcon[i]->getItems()->Item_Tab == item->Item_Tab &&
				m_pIcon[i]->getItems()->Item_UniIndex == item->Item_UniIndex)
				return true;
			
		}
	}
	return false;
}

void CUIIdentifyItem::UseQuickSlot()
{
	UseIdentifyReq();

	ResetallBtns();
}


void CUIIdentifyItem::ResetallBtns()
{
	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		if (m_pIcon[i] && !m_pIcon[i]->IsEmpty())
		{
			m_pIcon[i]->clearIconData();	
		}
	}
}

void CUIIdentifyItem::UseIdentifyReq()
{
	CNetworkMessage nmMsg((UBYTE)MSG_EXTEND);
	nmMsg << (ULONG)MSG_EX_IDENTIFY_ITEMS_USE;
	int totalcount = 0;

	for (int i = 0; i < MAX_ITEMS_IDENTIFY; i++)
	{
		if (!m_pIcon[i]->IsEmpty()) 
			totalcount++;
	}

	if (totalcount > 0)
	{
		nmMsg << (INDEX)totalcount;

		for (int i = 0; i < totalcount; i++)
		{
			nmMsg << (INDEX)m_pIcon[i]->getItems()->Item_UniIndex;
		}

		_pNetwork->SendToServerNew(nmMsg);
	}

}

#endif