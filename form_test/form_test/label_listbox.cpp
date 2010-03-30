// label_listbox.cpp : implementation file
//

#include "stdafx.h"
#include "form_test.h"
#include "label_listbox.h"


// label_listbox dialog

IMPLEMENT_DYNAMIC(label_listbox, CDialog)

label_listbox::label_listbox(CWnd* pParent /*=NULL*/)
	: CDialog(label_listbox::IDD, pParent)
{

}

label_listbox::~label_listbox()
{
}

void label_listbox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(label_listbox, CDialog)
END_MESSAGE_MAP()


// label_listbox message handlers
