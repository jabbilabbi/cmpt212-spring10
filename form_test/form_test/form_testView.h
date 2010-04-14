// form_testView.h : interface of the Cform_testView class
//


#pragma once
#include "afxwin.h"


class Cform_testView : public CFormView
{
protected: // create from serialization only
	Cform_testView();
	DECLARE_DYNCREATE(Cform_testView)

public:
	enum{ IDD = IDD_FORM_TEST_FORM };

// Attributes
public:
	Cform_testDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~Cform_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
public:
	CListBox m_label_listbox;
public:
	afx_msg void OnAddPeople();
public:
	afx_msg void OnFileSave();
public:
	CListBox m_person_listbox;
};

#ifndef _DEBUG  // debug version in form_testView.cpp
inline Cform_testDoc* Cform_testView::GetDocument() const
   { return reinterpret_cast<Cform_testDoc*>(m_pDocument); }
#endif

