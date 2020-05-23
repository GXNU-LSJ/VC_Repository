
// ��ʮ����ʵ���View.cpp : C��ʮ����ʵ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮ����ʵ���.h"
#endif

#include "��ʮ����ʵ���Set.h"
#include "��ʮ����ʵ���Doc.h"
#include "��ʮ����ʵ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ����ʵ���View

IMPLEMENT_DYNCREATE(C��ʮ����ʵ���View, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮ����ʵ���View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C��ʮ����ʵ���View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ʮ����ʵ���View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ʮ����ʵ���View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ʮ����ʵ���View::OnRecordLast)
	ON_EN_CHANGE(IDC_EDIT1, &C��ʮ����ʵ���View::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C��ʮ����ʵ���View ����/����

C��ʮ����ʵ���View::C��ʮ����ʵ���View()
	: CRecordView(IDD_MY_FORM)
	, filename(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\Users\\Hasee\\Desktop\\ѧ����Ƭ\\");
}

C��ʮ����ʵ���View::~C��ʮ����ʵ���View()
{
}

void C��ʮ����ʵ���View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column8);
}

BOOL C��ʮ����ʵ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮ����ʵ���View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ʮ����ʵ���Set;
	CRecordView::OnInitialUpdate();

}


// C��ʮ����ʵ���View ���

#ifdef _DEBUG
void C��ʮ����ʵ���View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮ����ʵ���View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮ����ʵ���Doc* C��ʮ����ʵ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮ����ʵ���Doc)));
	return (C��ʮ����ʵ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮ����ʵ���View ���ݿ�֧��
CRecordset* C��ʮ����ʵ���View::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮ����ʵ���View ��Ϣ�������
void C��ʮ����ʵ���View::Draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	int sx, sy, w, h;
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
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}




void C��ʮ����ʵ���View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ���View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ���View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ���View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C��ʮ����ʵ���View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ʮ����ʵ���View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	Draw_pic(filename);
}
