#pragma once


// newPerson dialog

class newPerson : public CDialog
{
	DECLARE_DYNAMIC(newPerson)

public:
	newPerson(CWnd* pParent = NULL);   // standard constructor
	virtual ~newPerson();

// Dialog Data
	enum { IDD = IDD_ADDPERSON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString fname;
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton3();
};
