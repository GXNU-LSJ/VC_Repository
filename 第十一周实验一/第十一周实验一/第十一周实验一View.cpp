
// ��ʮһ��ʵ��һView.cpp : C��ʮһ��ʵ��һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮһ��ʵ��һ.h"
#endif

#include "��ʮһ��ʵ��һSet.h"
#include "��ʮһ��ʵ��һDoc.h"
#include "��ʮһ��ʵ��һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ��ʵ��һView

IMPLEMENT_DYNCREATE(C��ʮһ��ʵ��һView, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮһ��ʵ��һView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ʮһ��ʵ��һView ����/����

C��ʮһ��ʵ��һView::C��ʮһ��ʵ��һView()
	: CRecordView(IDD_MY_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ʮһ��ʵ��һView::~C��ʮһ��ʵ��һView()
{
}

void C��ʮһ��ʵ��һView::DoDataExchange(CDataExchange* pDX)
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
}

BOOL C��ʮһ��ʵ��һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮһ��ʵ��һView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ʮһ��ʵ��һSet;
	CRecordView::OnInitialUpdate();

}


// C��ʮһ��ʵ��һView ��ӡ

BOOL C��ʮһ��ʵ��һView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ʮһ��ʵ��һView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ʮһ��ʵ��һView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ʮһ��ʵ��һView ���

#ifdef _DEBUG
void C��ʮһ��ʵ��һView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮһ��ʵ��һView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮһ��ʵ��һDoc* C��ʮһ��ʵ��һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮһ��ʵ��һDoc)));
	return (C��ʮһ��ʵ��һDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮһ��ʵ��һView ���ݿ�֧��
CRecordset* C��ʮһ��ʵ��һView::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮһ��ʵ��һView ��Ϣ�������
