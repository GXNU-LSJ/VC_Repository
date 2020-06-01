
// ��ʮ����ʵ��һView.cpp : C��ʮ����ʵ��һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮ����ʵ��һ.h"
#endif

#include "��ʮ����ʵ��һSet.h"
#include "��ʮ����ʵ��һDoc.h"
#include "��ʮ����ʵ��һView.h"
#include"Dialogo1.h"
#include"ADD.h"
#include"query.h"
#include"record_set.h"
#include"sort.h"
#include"increase.h"
#include"prompt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ����ʵ��һView

IMPLEMENT_DYNCREATE(C��ʮ����ʵ��һView, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮ����ʵ��һView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ʮ����ʵ��һView::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &C��ʮ����ʵ��һView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ʮ����ʵ��һView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ʮ����ʵ��һView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ʮ����ʵ��һView::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ʮ����ʵ��һView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &C��ʮ����ʵ��һView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &C��ʮ����ʵ��һView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &C��ʮ����ʵ��һView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C��ʮ����ʵ��һView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C��ʮ����ʵ��һView::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &C��ʮ����ʵ��һView::OnBnClickedButton8)
END_MESSAGE_MAP()

// C��ʮ����ʵ��һView ����/����

C��ʮ����ʵ��һView::C��ʮ����ʵ��һView()
	: CRecordView(IDD_MY_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birthday(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, filename(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\Users\\Hasee\\Desktop\\ѧ����Ƭ\\");
}

C��ʮ����ʵ��һView::~C��ʮ����ʵ��һView()
{
}

void C��ʮ����ʵ��һView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column8);
	
}

BOOL C��ʮ����ʵ��һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮ����ʵ��һView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ʮ����ʵ��һSet;
	CRecordView::OnInitialUpdate();

}


// C��ʮ����ʵ��һView ���

#ifdef _DEBUG
void C��ʮ����ʵ��һView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮ����ʵ��һView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮ����ʵ��һDoc* C��ʮ����ʵ��һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮ����ʵ��һDoc)));
	return (C��ʮ����ʵ��һDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮ����ʵ��һView ���ݿ�֧��
CRecordset* C��ʮ����ʵ��һView::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮ����ʵ��һView ��Ϣ�������


void C��ʮ����ʵ��һView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Dialogo1 dlg;
	if (m_pSet->column8 == "")
		dlg.s = "";
	else dlg.s = path+m_pSet->column8;
	int n = dlg.DoModal();
	//if (n != IDOK)return;
	/*if (n == IDOK)
	{
		CImage img;
		img.Load(m_pSet->column8);
		CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC,  sx, sy, w, h);
		ReleaseDC(pDC);
	}*/
}


void C��ʮ����ʵ��һView::OnDraw(CDC* pDC)
{
	// TODO: �ڴ����ר�ô����/����û���
	CString file, s;
	GetDlgItemText(IDC_EDIT9, s);
	file = path + s;
	if (s != "") {
		CImage img;
		img.Load(file);
		pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void C��ʮ����ʵ��һView::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = (rect.Height() - h) / 2;
		sx = 0;
	}
}



void C��ʮ����ʵ��һView::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ��һView::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ��һView::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ��һView::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ��һView::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	increase dlg;
	dlg.path = path;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		if (dlg.name=="")
		{
			prompt pro;
			int t = pro.DoModal();
			return;
		}
		m_pSet->AddNew();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.birthday;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		m_pSet->column8 = dlg.filename;
		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(false);
		Invalidate();
	}
}


void C��ʮ����ʵ��һView::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD dlg;
	int f;
	dlg.file= path + m_pSet->column8;
	if (m_pSet->column8 == "")
	{
		dlg.s = ""; f = 0;
	}
	else { dlg.s = path + m_pSet->column8; f = 1; }
	dlg.path = path;
	dlg.name = m_pSet->column1;
	dlg.number = m_pSet->column2;
	dlg.major= m_pSet->column3;
	dlg.sex = m_pSet->column4;
	dlg.birthday = m_pSet->column5;
	dlg.phone = m_pSet->column6;
	dlg.address = m_pSet->column7;
	dlg.filename = m_pSet->column8;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		if (f == 0) { f = dlg.f; }
		if (dlg.filename == ""&&f==1&&dlg.name == "")
		{
			prompt pro;
			int t=pro.DoModal();
			return;
		}
		m_pSet->Edit();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major ;
		m_pSet->column4 = dlg.sex ;
		m_pSet->column5 = dlg.birthday ;
		m_pSet->column6 = dlg.phone ;
		m_pSet->column7 = dlg.address;
		if (f == 1) {
			CString file = path + dlg.filename;
			rename(CT2A(dlg.s.GetString()), CT2A(file.GetString()));
		}
		m_pSet->column8 = dlg.filename;
		m_pSet->Update();
		UpdateData(false);
	}
}

void C��ʮ����ʵ��һView::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}




void C��ʮ����ʵ��һView::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	query q;
	int n = q.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strFilter = q.s;
		m_pSet->Requery();
		UpdateData(false);
	}
	Invalidate();

}


void C��ʮ����ʵ��һView::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sort s;
	int n = s.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strSort = s.s;
		m_pSet->Requery();
		UpdateData(false);
	}

}


void C��ʮ����ʵ��һView::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	record_set r;

	CString str = _T("ID   ����       ѧ��     רҵ          �Ա�   ��������  �ֻ�����  ��ͥסַ     ��Ƭ�ļ��� \r\n"), s;
	int t = m_pSet->GetODBCFieldCount();
	int f = m_pSet->m_ID; //��¼ָ�뵯������ǰ��λ��ID
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		for (int i = 0; i < t; i++) {
			m_pSet->GetFieldValue((short)i, s);
			str = str + "  " + s;
		}
		str = str + _T("\r\n");
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	while (m_pSet->m_ID != f)  //�˳�����ʱָ��ָ�ص�������ǰ��λ��
	{
		m_pSet->MoveNext();
	}
	r.s = str;
	r.DoModal();
	UpdateData(false);
}


void C��ʮ����ʵ��һView::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}
