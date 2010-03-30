// FORM.cpp : implementation file
//

#include "stdafx.h"
#include "form_test.h"
#include "FORM.h"


// FORM dialog

IMPLEMENT_DYNAMIC(FORM, CDialog)

FORM::FORM(CWnd* pParent /*=NULL*/)
	: CDialog(FORM::IDD, pParent)
{

}

FORM::~FORM()
{
}

void FORM::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FORM, CDialog)
END_MESSAGE_MAP()


// FORM message handlers
