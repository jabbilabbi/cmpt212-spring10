// newPerson.cpp : implementation file
//

#include "stdafx.h"
#include "form_test.h"
#include "newPerson.h"


// newPerson dialog

IMPLEMENT_DYNAMIC(newPerson, CDialog)

newPerson::newPerson(CWnd* pParent /*=NULL*/)
	: CDialog(newPerson::IDD, pParent)
	, fname(_T(""))
{

}

newPerson::~newPerson()
{
}

void newPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fname);
}


BEGIN_MESSAGE_MAP(newPerson, CDialog)
	ON_BN_CLICKED(IDC_BUTTON3, &newPerson::OnBnClickedButton3)
END_MESSAGE_MAP()

void newPerson::OnBnClickedButton3()
{
	MessageBox(_T("sadfsdf"));
}
