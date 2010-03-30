// form_testDoc.h : interface of the Cform_testDoc class
//


#pragma once


class Cform_testDoc : public CDocument
{
protected: // create from serialization only
	Cform_testDoc();
	DECLARE_DYNCREATE(Cform_testDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~Cform_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


