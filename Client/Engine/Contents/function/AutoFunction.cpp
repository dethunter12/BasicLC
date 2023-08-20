#include "StdH.h"

// 헤더 정리. [12/1/2009 rumist]
#include <Engine/Interface/UIInternalClasses.h>
#include <vector>
#include <Engine/Contents/function/AutoFunction.h>

CAutoFuncUI::CAutoFuncUI()
{
	preIgni = 0;
	prePickUp = 0;
	m_bDrag = false;
	m_nOriX = 0;
	m_nOriY = 0;
}

CAutoFuncUI::~CAutoFuncUI()
{
	Destroy();
}

void CAutoFuncUI::initialize()
{
	CTString strNameCO[eCOMBO_MAX] = { "autopickup", "autoigni" };
	for (int i = 0; i < eCOMBO_MAX; i++)
	{
		m_pComboOption[i] = static_cast<CUIComboBox*>(findUI("combo_" + strNameCO[i]));
	}
	m_pDragArea = static_cast<CUIBase*>(findUI("drag"));
	m_btn_save = static_cast<CUIButton*>(findUI("btn_save"));
	m_btn_close = static_cast<CUIButton*>(findUI("btn_close"));

	CTString tempstr[4] = {"Pickup: Nothing", "Pickup: All Items", "Pickup: Weapons / Armor", "Pickup: Other Items"};

	m_pComboOption[eCOMBO_AUTOPICKUP]->AddString(tempstr[0]);
	m_pComboOption[eCOMBO_AUTOPICKUP]->AddString(tempstr[1]);
	m_pComboOption[eCOMBO_AUTOPICKUP]->AddString(tempstr[2]);
	m_pComboOption[eCOMBO_AUTOPICKUP]->AddString(tempstr[3]);

	m_pComboOption[eCOMBO_AUTOIGNI]->AddString(tempstr[0]);
	CTString str = "";
	for (int i = 1; i < 6; i++)
	{
		str.PrintF("Ignition Level: %d", i);
		m_pComboOption[eCOMBO_AUTOIGNI]->AddString(str);
	}

	m_btn_save->SetCommandFUp(boost::bind(&CAutoFuncUI::Save, this));
	m_btn_close->SetCommandFUp(boost::bind(&CAutoFuncUI::ToggleWindow, this));
}

void CAutoFuncUI::ToggleWindow()
{
	BOOL	bVisible = !IsVisible();

	if (bVisible == TRUE)
		open();
	else
		close();
}

void CAutoFuncUI::ResAutoSettingData(CNetworkMessage* istr)
{
	int result;
	(*istr) >> result;

	if (result)
	{
		_pNetwork->MyCharacterInfo.autoigni = preIgni;
		_pNetwork->MyCharacterInfo.autopickup = prePickUp;
	}
}

void CAutoFuncUI::Save()
{
	preIgni = m_pComboOption[eCOMBO_AUTOIGNI]->GetCurSel();
	prePickUp = m_pComboOption[eCOMBO_AUTOPICKUP]->GetCurSel();
	_pNetwork->SendAutoFunc(prePickUp, preIgni);
}

WMSG_RESULT CAutoFuncUI::OnMouseMove(UINT16 x, UINT16 y, MSG* pMsg)
{
	if (m_bHide)
		return WMSG_FAIL;

	if (IsInside(x, y) == FALSE)
		return WMSG_FAIL;

	if (m_bDrag)
	{
		int ndX = x - m_nOriX;
		int ndY = y - m_nOriY;

		m_nOriX = x;
		m_nOriY = y;

		Move(ndX, ndY);
		return WMSG_SUCCESS;
	}

	return WMSG_FAIL;
}

WMSG_RESULT CAutoFuncUI::OnLButtonDown(UINT16 x, UINT16 y)
{
	if (m_bHide)
		return WMSG_FAIL;

	if (IsInside(x, y) == FALSE)
		return WMSG_FAIL;

	if (m_pDragArea != NULL && m_pDragArea->IsInside(x, y))
	{
		m_bDrag = true;
		m_nOriX = x;
		m_nOriY = y;
	}
	return WMSG_FAIL;
}

WMSG_RESULT CAutoFuncUI::OnLButtonUp(UINT16 x, UINT16 y)
{
	if (m_bHide)
		return WMSG_FAIL;

	m_bDrag = false;
	return WMSG_FAIL;
}

void CAutoFuncUI::open()
{
	SetVisible(TRUE);
	Hide(FALSE);

	m_pComboOption[eCOMBO_AUTOIGNI]->SetCurSel(_pNetwork->MyCharacterInfo.autoigni);
	m_pComboOption[eCOMBO_AUTOPICKUP]->SetCurSel(_pNetwork->MyCharacterInfo.autopickup);

	CUIManager::getSingleton()->RearrangeOrder(UI_AUTOFUNC, TRUE);
}

void CAutoFuncUI::close()
{
	SetVisible(FALSE);
	Hide(TRUE);
	CUIManager::getSingleton()->RearrangeOrder(UI_AUTOFUNC, FALSE);
}
