
// ��ʮ����ʵ����View.cpp : C��ʮ����ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮ����ʵ����.h"
#endif

#include "��ʮ����ʵ����Set.h"
#include "��ʮ����ʵ����Doc.h"
#include "��ʮ����ʵ����View.h"
#include"ADD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ����ʵ����View

IMPLEMENT_DYNCREATE(C��ʮ����ʵ����View, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮ����ʵ����View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ʮ����ʵ����View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ʮ����ʵ����View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C��ʮ����ʵ����View::OnBnClickedButton3)
END_MESSAGE_MAP()

// C��ʮ����ʵ����View ����/����

C��ʮ����ʵ����View::C��ʮ����ʵ����View()
	: CRecordView(IDD_MY_FORM)
	, s(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ʮ����ʵ����View::~C��ʮ����ʵ����View()
{
}

void C��ʮ����ʵ����View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C��ʮ����ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮ����ʵ����View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ʮ����ʵ����Set;
	CRecordView::OnInitialUpdate();

}


// C��ʮ����ʵ����View ���

#ifdef _DEBUG
void C��ʮ����ʵ����View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮ����ʵ����View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮ����ʵ����Doc* C��ʮ����ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮ����ʵ����Doc)));
	return (C��ʮ����ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮ����ʵ����View ���ݿ�֧��
CRecordset* C��ʮ����ʵ����View::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮ����ʵ����View ��Ϣ�������


void C��ʮ����ʵ����View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD dlg;
	int n = dlg.DoModal();
	if (n==IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_1 = dlg.s;
		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(false);
	}

}


void C��ʮ����ʵ����View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD dlg;
	dlg.s=m_pSet->m_1;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		m_pSet->Edit();
		m_pSet->m_1 = dlg.s;
		m_pSet->Update();
		UpdateData(false);
	}
}


void C��ʮ����ʵ����View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}

