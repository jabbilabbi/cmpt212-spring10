// form_testDoc.cpp : implementation of the Cform_testDoc class
//

#include "stdafx.h"
#include "form_test.h"

#include "form_testDoc.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
CString strToCStr1(string s){
	CString cstring;
	for (int i = 0; i<s.length(); i++){
		cstring += s[i];
	}
	return cstring;
}
// Cform_testDoc

IMPLEMENT_DYNCREATE(Cform_testDoc, CDocument)

BEGIN_MESSAGE_MAP(Cform_testDoc, CDocument)
END_MESSAGE_MAP()


// Cform_testDoc construction/destruction

Cform_testDoc::Cform_testDoc()
{
	// TODO: add one-time construction code here

}

Cform_testDoc::~Cform_testDoc()
{
}

BOOL Cform_testDoc::OnNewDocument()
{
	CDocument::SetTitle(strToCStr1("Bio Dictionary"));
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Cform_testDoc serialization

void Cform_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// Cform_testDoc diagnostics

#ifdef _DEBUG
void Cform_testDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cform_testDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cform_testDoc commands
