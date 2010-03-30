// form_test.h : main header file for the form_test application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cform_testApp:
// See form_test.cpp for the implementation of this class
//

class Cform_testApp : public CWinApp
{
public:
	Cform_testApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cform_testApp theApp;