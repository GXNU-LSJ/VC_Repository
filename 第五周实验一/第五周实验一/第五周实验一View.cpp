
// ������ʵ��һView.cpp : C������ʵ��һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ��һ.h"
#endif

#include "������ʵ��һDoc.h"
#include "������ʵ��һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ��һView

IMPLEMENT_DYNCREATE(C������ʵ��һView, CView)

BEGIN_MESSAGE_MAP(C������ʵ��һView, CView)
	ON_COMMAND(ID_yuan, &C������ʵ��һView::Onyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C������ʵ��һView ����/����

C������ʵ��һView::C������ʵ��һView()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʵ��һView::~C������ʵ��һView()
{
}

BOOL C������ʵ��һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ��һView ����

void C������ʵ��һView::OnDraw(CDC* pDC)
{
	C������ʵ��һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		for (int i = 0; i < 256; i++) {
			SetTimer(i, 50, NULL);
			set == false;
		}
	}
}


// C������ʵ��һView ���

#ifdef _DEBUG
void C������ʵ��һView::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ��һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ��һDoc* C������ʵ��һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ��һDoc)));
	return (C������ʵ��һDoc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ��һView ��Ϣ�������


void C������ʵ��һView::Onyuan()
{
	CRect cr,cr1;
	CPoint p;
	CClientDC dc(this);
	C������ʵ��һDoc* pDoc = GetDocument();
	pDoc->f1 = 0;
	if (pDoc->f)
	{
		pDoc->f = false;
		GetClientRect(&cr);
		pDoc->p.x = (cr.left + cr.right) / 2;
		pDoc->p.y = (cr.top + cr.bottom) / 2;
		pDoc->cr.left = pDoc->p.x - 5;
		pDoc->cr.right = pDoc->p.x + 5;
		pDoc->cr.bottom = pDoc->p.y - 5;
		pDoc->cr.top = pDoc->p.y + 5;
	}
	else {
		pDoc->cr.left = pDoc->cr.left - 5;
		pDoc->cr.right = pDoc->cr.right + 5;
		pDoc->cr.bottom = pDoc->cr.bottom - 5;
		pDoc->cr.top = pDoc->cr.top + 5;

	}
	dc.Ellipse(pDoc->cr);
	InvalidateRect(NULL, FALSE);
}


void C������ʵ��һView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ��һDoc* pDoc = GetDocument();
	if (pDoc->f1==0)
	{
		C������ʵ��һView::Onyuan();
	}
	
	CView::OnTimer(nIDEvent);
}
