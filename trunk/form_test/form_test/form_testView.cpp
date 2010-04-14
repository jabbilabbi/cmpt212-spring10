// form_testView.cpp : implementation of the Cform_testView class
//

#include "stdafx.h"
#include "form_test.h"

#include "form_testDoc.h"
#include "form_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cform_testView

IMPLEMENT_DYNCREATE(Cform_testView, CFormView)

BEGIN_MESSAGE_MAP(Cform_testView, CFormView)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cform_testView::OnLbnSelchangeList1)
	ON_COMMAND(ID_ADD_PEOPLE, &Cform_testView::OnAddPeople)
	ON_COMMAND(ID_FILE_SAVE, &Cform_testView::OnFileSave)
END_MESSAGE_MAP()

// Cform_testView construction/destruction

Cform_testView::Cform_testView()
	: CFormView(Cform_testView::IDD)
{
	// TODO: add construction code here

}

Cform_testView::~Cform_testView()
{
}

void Cform_testView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_label_listbox);
}

BOOL Cform_testView::PreCreateWindow(CREATESTRUCT& cs)
{

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void Cform_testView::OnInitialUpdate()
{

	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Cform_testView diagnostics

#ifdef _DEBUG
void Cform_testView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cform_testView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cform_testDoc* Cform_testView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cform_testDoc)));
	return (Cform_testDoc*)m_pDocument;
}
#endif //_DEBUG


// Cform_testView message handlers

void Cform_testView::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}

void Cform_testView::OnAddPeople()
{
	 CDialog testDlg(IDD_ADDPERSON);
	 testDlg.DoModal();
}

void Cform_testView::OnFileSave()
{
		// TODO: Add your control notification handler code here
	//this->UpdateData();



	CFileDialog FileDlg(FALSE, _T".txt", NULL, 0, _T"Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");
	FileDlg.DoModal();



}
