
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
#include"record_set.h"
#include"query.h"
#include"sort.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ����ʵ��һView

IMPLEMENT_DYNCREATE(C��ʮ����ʵ��һView, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮ����ʵ��һView, CRecordView)
	ON_COMMAND(ID_32771, &C��ʮ����ʵ��һView::On32771)
	ON_COMMAND(ID_32772, &C��ʮ����ʵ��һView::On32772)
	ON_COMMAND(ID_32773, &C��ʮ����ʵ��һView::On32773)
	ON_COMMAND(ID_32774, &C��ʮ����ʵ��һView::On32774)
END_MESSAGE_MAP()

// C��ʮ����ʵ��һView ����/����

C��ʮ����ʵ��һView::C��ʮ����ʵ��һView()
	: CRecordView(IDD_MY_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
	, photo(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

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


void C��ʮ����ʵ��һView::On32771()
{
	// TODO: �ڴ���������������
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


void C��ʮ����ʵ��һView::On32772()
{
	// TODO: �ڴ���������������
	sort s;
	int n = s.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strSort = s.s;
		m_pSet->Requery();
		UpdateData(false);
	}

}


void C��ʮ����ʵ��һView::On32773()
{
	// TODO: �ڴ���������������
	record_set r;
	
	CString str=_T("ID   ����       ѧ��     ����  �绰����     ѧ����Ƭ \r\n"),s;
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



void C��ʮ����ʵ��һView::On32774()
{
	// TODO: �ڴ���������������
	m_pSet->m_strFilter =_T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}
