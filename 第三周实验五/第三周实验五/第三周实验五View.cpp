
// ������ʵ����View.cpp : C������ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ����.h"
#endif

#include "������ʵ����Doc.h"
#include "������ʵ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ����View

IMPLEMENT_DYNCREATE(C������ʵ����View, CView)

BEGIN_MESSAGE_MAP(C������ʵ����View, CView)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C������ʵ����View ����/����

C������ʵ����View::C������ʵ����View()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʵ����View::~C������ʵ����View()
{
}

BOOL C������ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ����View ����

void C������ʵ����View::OnDraw(CDC* pDC)
{
	C������ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr1(50, 50, 300, 300);
	pDC->Rectangle(cr1);
	CRect cr2(350, 50, 600, 300);
	pDC->Rectangle(cr2);
	CRect cr3(650, 50, 900, 300);
	pDC->Rectangle(cr3);
	CRect cr4(950, 50, 1200, 300);
	pDC->Rectangle(cr4);
	CClientDC dc(this);
	CString T;
	T = _T("��");
	dc.TextOutW(917, 175, T);
}


// C������ʵ����View ���

#ifdef _DEBUG
void C������ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ����Doc* C������ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ����Doc)));
	return (C������ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ����View ��Ϣ�������



int a = -1, b = -1,count = -1;;

void C������ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	this->GetClientRect(&cr);
	
	CString A, B, C, S = _T("�����Ч��"),T=_T("                           ");
	CClientDC dc(this);
	dc.TextOutW(625, 500, T);
	srand((unsigned)time(NULL));
	if ((point.x >= 50) && (point.x <= 300) && (point.y >= 50 )&&( point.y <= 300))
	{
		a = rand() % 100;
		a = a*(pow(-1, rand() % 2));
		A.Format(_T("%d"), a);
		dc.TextOutW(175, 175, T);
		dc.TextOutW(175, 175, A);
	}
	if ((((point.x >= 50) && (point.x <= 300) && (point.y >= 50) && (point.y <= 300))||((point.x >= 350) && (point.x <= 600) && (point.y >= 50) && (point.y <= 300))||((point.x >= 650) && (point.x <= 900) && (point.y >= 50) && (point.y <= 300)))==0)
	{
		dc.TextOutW(625, 500, S);
	}

	if ((point.x >= 650) && (point.x <= 900) && (point.y >= 50) && (point.y <= 300))
	{
		b =  rand() % 100;
		b = b*(pow(-1, rand() % 2));
		B.Format(_T("%d"), b);
		dc.TextOutW(775, 175, T);
		dc.TextOutW(775, 175, B);
	}

	
	CString s=_T("     ");
	if ((point.x >= 350) && (point.x <= 600) && (point.y >= 50) && (point.y <= 300))
	{
		dc.TextOutW(475, 175, s);
		count++;
		if (count % 4 == 0)s = _T("��");
		if (count % 4 == 1)s = _T("��");
		if (count % 4 == 2)s = _T("��");
		if (count % 4 == 3)s = _T("��");
		dc.TextOutW(475, 175, s);
		
	}


	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ����View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int c=0 ;
	CClientDC dc(this);

	CString s = _T("�������"),S;
	if ((point.x >= 950) && (point.x <= 1200) && (point.y >= 50) && (point.y <= 300))
	{
		S = _T("                         ");
		dc.TextOutW(625, 500, S);
		if (a == -1 || b == -1 || count == -1) dc.TextOutW(1040, 175, s);
		else {
			
			dc.TextOutW(1040, 175, S);
			if (count % 4 == 0) { c = a + b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
			else if (count % 4 == 1) { c = a - b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
			else if (count % 4 == 2) { c = a * b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
			else {
				if (count % 4 == 3 && b != 0) { c = a / b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
				else dc.TextOutW(1040, 175, s);
			}
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
