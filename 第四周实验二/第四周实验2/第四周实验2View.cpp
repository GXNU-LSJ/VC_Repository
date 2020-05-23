
// ������ʵ��2View.cpp : C������ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ��2.h"
#endif

#include "������ʵ��2Doc.h"
#include "������ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ��2View

IMPLEMENT_DYNCREATE(C������ʵ��2View, CView)

BEGIN_MESSAGE_MAP(C������ʵ��2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C������ʵ��2View ����/����

C������ʵ��2View::C������ʵ��2View()
{
	// TODO: �ڴ˴���ӹ������
	r = 60;
	f = 1;
}

C������ʵ��2View::~C������ʵ��2View()
{
	
}

BOOL C������ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ��2View ����

void C������ʵ��2View::OnDraw(CDC* pDC)
{
	C������ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	
	if (f) {
		f = 0;
		GetClientRect(&cr);
		pDoc->cr.left = (cr.left + cr.right) / 2 - r;
		pDoc->cr.right = (cr.left + cr.right) / 2 + r;
		pDoc->cr.top = (cr.top + cr.bottom) / 2 - r;
		pDoc->cr.bottom = (cr.top + cr.bottom) / 2 + r;
	}

	pDC->Rectangle(pDoc->cr);
}


// C������ʵ��2View ���

#ifdef _DEBUG
void C������ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ��2Doc* C������ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ��2Doc)));
	return (C������ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ��2View ��Ϣ�������


void C������ʵ��2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr1;
	this->GetClientRect(&cr1);
	C������ʵ��2Doc* pDoc = GetDocument();
	switch (nChar)
	{
	case VK_LEFT:if (pDoc->cr.left > 0)
	{
		pDoc->cr.left -= 5;
		pDoc->cr.right -= 5;
	}break;
	case VK_RIGHT:if (pDoc->cr.left <= (cr1.right - cr1.left))
	{
		pDoc->cr.left += 5;
		pDoc->cr.right += 5;
	}break;

	case VK_UP:if (pDoc->cr.top > 0)
	{
		pDoc->cr.top -= 5;
		pDoc->cr.bottom -= 5;
	}break;

	case VK_DOWN:if (pDoc->cr.bottom <= (cr1.bottom - cr1.top))
	{
		pDoc->cr.top += 5;
		pDoc->cr.bottom += 5;
	}break;
	case VK_HOME:if (pDoc->cr.left > 0&&pDoc->cr.top>0)
	{
		pDoc->cr.left -= 5;
		pDoc->cr.top -= 5;
	}break;

	case VK_END:if (pDoc->cr.right <= (cr1.right - cr1.left) && pDoc->cr.bottom<= (cr1.bottom - cr1.top))
	{
		pDoc->cr.left += 5;
		pDoc->cr.top += 5;
	}break;

	
	default:
		break;
	}

	InvalidateRect(NULL, TRUE);



	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void C������ʵ��2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	C������ʵ��2Doc* pDoc = GetDocument();
	
		
		pDoc->cr.left = pDoc->cr.right-120;
		pDoc->cr.top = pDoc->cr.bottom -120;
		
	
		InvalidateRect(NULL, TRUE);

	CView::OnLButtonDown(nFlags, point);
}
