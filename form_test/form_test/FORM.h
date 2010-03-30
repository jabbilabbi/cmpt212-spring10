#pragma once


// FORM dialog

class FORM : public CDialog
{
	DECLARE_DYNAMIC(FORM)

public:
	FORM(CWnd* pParent = NULL);   // standard constructor
	virtual ~FORM();

// Dialog Data
	enum { IDD = IDD_FORM_TEST_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
