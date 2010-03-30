// MAIN_FORM.cpp : implementation file
//

#include "stdafx.h"
#include "form_test.h"
#include "MAIN_FORM.h"


// MAIN_FORM dialog

IMPLEMENT_DYNAMIC(MAIN_FORM, CDialog)

MAIN_FORM::MAIN_FORM(CWnd* pParent /*=NULL*/)
	: CDialog(MAIN_FORM::IDD, pParent)
{

}

MAIN_FORM::~MAIN_FORM()
{
}

void MAIN_FORM::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MAIN_FORM, CDialog)
END_MESSAGE_MAP()


// MAIN_FORM message handlers
