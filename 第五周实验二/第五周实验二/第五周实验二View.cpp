
// ������ʵ���View.cpp : C������ʵ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���.h"
#endif

#include "������ʵ���Doc.h"
#include "������ʵ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���View

IMPLEMENT_DYNCREATE(C������ʵ���View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���View, CView)
	ON_COMMAND(ID_jianbianyuan, &C������ʵ���View::Onjianbianyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C������ʵ���View ����/����

C������ʵ���View::C������ʵ���View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
}

C������ʵ���View::~C������ʵ���View()
{
}

BOOL C������ʵ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���View ����

void C������ʵ���View::OnDraw(CDC* pDC)
{
	C������ʵ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		for (int i = 0; i < 256; i++) {
			SetTimer(i, 30, NULL);
			set == false;
		}
	}
	
	int width = 5;
	int color = RGB(pDoc->red, pDoc->green, pDoc->blue);
	CPen newPen(PS_SOLID, width, color);
	CPen *oldPen = pDC->SelectObject(&newPen);
	pDC->Ellipse(pDoc->cr);
	pDC->SelectObject(&oldPen);


}


// C������ʵ���View ���

#ifdef _DEBUG
void C������ʵ���View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���Doc* C������ʵ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���Doc)));
	return (C������ʵ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���View ��Ϣ�������


void C������ʵ���View::Onjianbianyuan()
{
	// TODO: �ڴ���������������
	CRect cr, cr1;
	CPoint p;
	CClientDC dc(this);
	C������ʵ���Doc* pDoc = GetDocument();
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
		pDoc->red += 3;
		pDoc->green += 2;
		pDoc->blue += 5;
	}

	InvalidateRect(NULL, FALSE);
}


void C������ʵ���View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ���Doc* pDoc = GetDocument();
	if (pDoc->f1 == 0)
	{
		C������ʵ���View::Onjianbianyuan();
	}

	CView::OnTimer(nIDEvent);
}
