
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
	ON_COMMAND(ID_xian, &C������ʵ����View::Onxian)
	ON_COMMAND(ID_juxing, &C������ʵ����View::Onjuxing)
	ON_COMMAND(ID_tuoyuan, &C������ʵ����View::Ontuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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

void C������ʵ����View::OnDraw(CDC* /*pDC*/)
{
	C������ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


void C������ʵ����View::Onxian()
{
	// TODO: �ڴ���������������
	C������ʵ����Doc* pDoc = GetDocument();
	pDoc->f = 1;
	

}


void C������ʵ����View::Onjuxing()
{
	// TODO: �ڴ���������������
	C������ʵ����Doc* pDoc = GetDocument();
	pDoc->f = 2;
}


void C������ʵ����View::Ontuoyuan()
{
	// TODO: �ڴ���������������
	C������ʵ����Doc* pDoc = GetDocument();
	pDoc->f = 3;
}


void C������ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ����Doc* pDoc = GetDocument();

	pDoc->p1.x = point.x;
	pDoc->p1.y = point.y;
		CView::OnLButtonDown(nFlags, point);
}


void C������ʵ����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ����Doc* pDoc = GetDocument();
	pDoc->p2.x = point.x;
	pDoc->p2.y = point.y;
	CClientDC dc(this);
	CRect cr(pDoc->p1.x, pDoc->p1.y, pDoc->p2.x, pDoc->p2.y);
	int f = pDoc->f;
	if (f == 1) {
		
		dc.MoveTo(pDoc->p1.x, pDoc->p1.y);
		dc.LineTo(pDoc->p2.x, pDoc->p2.y);

	}
	if (f == 2) {
		dc.Rectangle(cr);
	}

	if (f == 3) {
		
		dc.Ellipse(cr);
	}

	CView::OnLButtonUp(nFlags, point);
}
