// form_testView.cpp : implementation of the Cform_testView class
//

#include "stdafx.h"
#include "form_test.h"
#include "PLData.h"
#include "form_testDoc.h"
#include "form_testView.h"
#include <set>
#include <vector>
#include <string>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
set<PLData> *parse(set<PLData> *dictionary,  vector<string> *labelList, string fileName);
bool saveFile(set<PLData> *dictionary, vector<string> *labelList, string fileName);
// Cform_testView
set<PLData> *masterList = new set<PLData>;
vector<string> *labels = new vector<string>;
CString fname;

IMPLEMENT_DYNCREATE(Cform_testView, CFormView)

BEGIN_MESSAGE_MAP(Cform_testView, CFormView)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cform_testView::OnLbnSelchangeList1)
	ON_COMMAND(ID_ADD_PEOPLE, &Cform_testView::OnAddPeople)
	ON_COMMAND(ID_FILE_SAVE, &Cform_testView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &Cform_testView::OnFileOpen)
	ON_BN_CLICKED(IDOK, &Cform_testView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &Cform_testView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &Cform_testView::OnBnClickedButton7)
	ON_LBN_DBLCLK(IDC_LIST2, &Cform_testView::OnLbnDblclkList2)
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

CString strToCStr(string s){
	CString cstring;
	for (int i = 0; i<s.length(); i++){
		cstring += s[i];
	}
	return cstring;
}

string cStrToStr(CString cs){
	string s;
	for (int i = 0; i<cs.GetLength(); i++){
		s += cs.GetAt(i);
	}
	return s;
}

void Cform_testView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_label_listbox);
	DDX_Control(pDX, IDC_LIST2, m_person_listbox);
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
void addLabelDefaults(set<PLData> *list, vector<string> *labels);
void addPerson(set<PLData> *dict, Person *per, vector<string> lab);

void Cform_testView::OnLbnSelchangeList1()
{
	int index;
	CString strText;
	index = m_label_listbox.GetCurSel();
	m_label_listbox.GetText(index, strText);

	//MessageBox(strText);
	
	set<PLData>::iterator iter;
	m_person_listbox.ResetContent();
//addLabelDefaults(masterList, labels);


	for(iter = masterList->begin(); iter != masterList->end(); iter++){
		
		
		string s;
		stringstream out;
		//out << iter->labels.size();
		if(iter->labels.size() > 0)
			out<<iter->person->display();
		s = out.str();
		
		//MessageBox(strToCStr(s));
		if(cStrToStr(strText).compare("ALL")==0){
			m_person_listbox.AddString(strToCStr(iter->person->getFirstName() + " " + iter->person->getLastName()));
		}else{
			for (int i =0; i < iter->labels.size(); i++){
				if (iter->labels.at(i).compare(cStrToStr(strText)) == 0){
					m_person_listbox.AddString(strToCStr(iter->person->getFirstName() + " " + iter->person->getLastName()));
						//MessageBox(_T("Label matches!!"));
				} else {
	//MessageBox(_T("She no match!"));
				}
			}
		}
	}
}





void Cform_testView::OnFileSave()
{
		string s = cStrToStr(fname);
		saveFile(masterList, labels, s);
}

void Cform_testView::OnFileOpen()
{
	CFileDialog FileDlg(TRUE, _T(".txt"), NULL, 0, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"));
	FileDlg.DoModal();

    fname = FileDlg.GetFileName();
	string s =cStrToStr(fname);
	//const char* s1 = s.c_str();
	//MessageBox(_T((s)));

	//THIS IS NOT WORKING CURRENTLY!! CString newCS = s.c_str();
//masterList = new set<PLData>;
//labels = new vector<string>;
	masterList=parse(masterList,labels, s);
		Person *guy = new Person;
	
		//addLabelDefaults(masterList, labels);


	//CString first = strToCStr(labels->at(0));
	//MessageBox(first);
	m_label_listbox.AddString(strToCStr("ALL"));
	for (int i =0; i<labels->size(); i++){
		m_label_listbox.AddString(strToCStr(labels->at(i)));
	}
}

void Cform_testView::OnAddPeople()
{
	 CDialog testDlg(IDD_ADDPERSON);
	 testDlg.DoModal();
}

void Cform_testView::OnBnClickedOk()
{
	MessageBox(fname);
}


void Cform_testView::OnBnClickedButton2()
{
	UpdateData(false);
	MessageBox(_T("sup dawg"));
	MessageBox(fname);
}

void Cform_testView::OnBnClickedButton7()
{
	MessageBox(_T("hi"));
}

void Cform_testView::OnLbnDblclkList2()
{
	//m_person_listbox
	int index;
	CString strText;
	index = m_person_listbox.GetCurSel();
	m_person_listbox.GetText(index, strText);
	set<PLData>::iterator iter;

	for(iter = masterList->begin(); iter != masterList->end(); iter++){
		if((iter->person->getFirstName()+" "+iter->person->getLastName()).compare(cStrToStr(strText)) == 0)
		MessageBox(strToCStr(iter->person->display()));
	}
	
	// TODO: Add your control notification handler code here
}
