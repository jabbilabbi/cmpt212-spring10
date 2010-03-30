#pragma once


// MAIN_FORM dialog

class MAIN_FORM : public CDialog
{
	DECLARE_DYNAMIC(MAIN_FORM)

public:
	MAIN_FORM(CWnd* pParent = NULL);   // standard constructor
	virtual ~MAIN_FORM();

// Dialog Data
	enum { IDD = IDD_FORM_TEST_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
