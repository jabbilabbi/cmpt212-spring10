#pragma once


// label_listbox dialog

class label_listbox : public CDialog
{
	DECLARE_DYNAMIC(label_listbox)

public:
	label_listbox(CWnd* pParent = NULL);   // standard constructor
	virtual ~label_listbox();

// Dialog Data
	enum { IDD = IDD_FORM_TEST_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
