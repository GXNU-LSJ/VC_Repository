
// �ڰ˴�ʵ����View.cpp : C�ڰ˴�ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ˴�ʵ����.h"
#endif

#include "�ڰ˴�ʵ����Doc.h"
#include "�ڰ˴�ʵ����View.h"
#include"Dialog.h"
#include"Dialog2.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ˴�ʵ����View

IMPLEMENT_DYNCREATE(C�ڰ˴�ʵ����View, CView)

BEGIN_MESSAGE_MAP(C�ڰ˴�ʵ����View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &C�ڰ˴�ʵ����View::On32771)
	ON_COMMAND(ID_32772, &C�ڰ˴�ʵ����View::On32772)
	ON_COMMAND(ID_32773, &C�ڰ˴�ʵ����View::On32773)
	ON_COMMAND(ID_32774, &C�ڰ˴�ʵ����View::On32774)
END_MESSAGE_MAP()

// C�ڰ˴�ʵ����View ����/����

C�ڰ˴�ʵ����View::C�ڰ˴�ʵ����View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڰ˴�ʵ����View::~C�ڰ˴�ʵ����View()
{
}

BOOL C�ڰ˴�ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ˴�ʵ����View ����

void C�ڰ˴�ʵ����View::OnDraw(CDC* pDC)
{
	C�ڰ˴�ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < c.GetSize(); i++)
	{
		pDC->Ellipse(c.GetAt(i));
	}

	
	/*for (int i = 0; i < c1.GetSize(); i++)
	{
		CBrush *oldbrush;
		pDC->SelectObject(rgb.GetAt(i));
		pDC->Ellipse(c1.GetAt(i));
		pDC->SelectObject(&oldbrush);
		ReleaseDC(pDC);
	}*/
	
}


// C�ڰ˴�ʵ����View ���

#ifdef _DEBUG
void C�ڰ˴�ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ˴�ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ˴�ʵ����Doc* C�ڰ˴�ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ˴�ʵ����Doc)));
	return (C�ڰ˴�ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ˴�ʵ����View ��Ϣ�������


void C�ڰ˴�ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p1= p2= point;
	if (nFlags&&f == 0)
	{
		int mixi = 0,f1=0;
		for (int i = 0; i < c.GetSize(); i++)
		{
			c.GetAt(i);

			if (   ((   (point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2)*(point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2) +
				(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)*(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)) <=
				((point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2)*(point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2) +
				(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)*(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)))
				&&((point.x>=c.GetAt(i).left&&point.x<=c.GetAt(i).right&&point.y>= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom)||
				(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom)||
					(point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom)||
					(point.x <= c.GetAt(i).left&&point.x  >= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom)
					)  )
			{
				mixi = i;
				f1= 1;
				c1.Add(c.GetAt(mixi));
			}
		}
		if (f1) {
			CDC * dc = GetDC();
			CPen * pOldPen = NULL;
			CPen pen;
			pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));//����
			pOldPen = dc->SelectObject(&pen);

			CBrush * pOldBrush = NULL;
			CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//����͸��Ч��
			pOldBrush = dc->SelectObject(pBrush);

			dc->Rectangle(c.GetAt(mixi));
			dc->SelectObject(pOldPen);
			pen.DeleteObject();
		}
}
	if (nFlags&&f == 3)
	{

		int mixi = 0, f1 = 0;

		for (int i = 0; i < c.GetSize(); i++)
		{
			c.GetAt(i);

			if ((((point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2)*(point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2) +
				(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)*(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)) <=
				((point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2)*(point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2) +
				(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)*(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)))
				&& ((point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom) ||
				(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom) ||
					(point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom) ||
					(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom)
					))
			{
				mixi = i;
				f1 = 1;
			}

		}
		
		if (f1) {
			CDC * pDC = GetDC();
			CBrush Brush(RGB(r,g,b));
			CBrush *oldbrush;
			oldbrush = pDC->SelectObject(&Brush);
			pDC->Ellipse(c.GetAt(mixi));
		pDC->SelectObject(&oldbrush);
		ReleaseDC(pDC);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void C�ڰ˴�ʵ����View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	if (MK_LBUTTON&&nFlags&&f==1)
	{
		p2 = point;
		cr.left = p1.x; cr.top = p1.y; cr.right = p2.x, cr.bottom = p2.y;
		Invalidate();
		GetDC()->Ellipse(&cr);
	}
	CView::OnMouseMove(nFlags, point);
}



void C�ڰ˴�ʵ����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CRect cr;
	cr.left = p1.x; cr.top = p1.y; cr.right = p2.x, cr.bottom = p2.y;
	dc.Ellipse(&cr);
	c.Add(cr);
	CView::OnLButtonUp(nFlags, point);
}


void C�ڰ˴�ʵ����View::On32771()
{
	// TODO: �ڴ���������������
	Dialog dlg;
	int n = dlg.DoModal();
	int x, y, l, w;
	//this->UpdateData(true);

	if (n == IDOK)
	{
		x = dlg.x;
		y = dlg.y;
		l = dlg.l;
		w = dlg.w;
		CRect cr;
		cr.left = x - w; cr.top = y - l; cr.right = x + w; cr.bottom = y + l;
		CClientDC dc(this);
		dc.Ellipse(&cr);
		c.Add(cr);
	}

}


void C�ڰ˴�ʵ����View::On32772()
{
	// TODO: �ڴ���������������

	f = 0;

}


void C�ڰ˴�ʵ����View::On32773()
{
	// TODO: �ڴ���������������
	f = 1;
	Invalidate();
}


void C�ڰ˴�ʵ����View::On32774()
{
	// TODO: �ڴ���������������
	Dialog2 dlg2;
	int n;
	n = dlg2.DoModal();
	if (n == IDOK)
	{
		r = dlg2.r;
		g = dlg2.g;
		b = dlg2.b;
		f = 3;

		CDC * pDC = GetDC();
		CBrush Brush(RGB(r, g, b));
		CBrush *oldbrush;
		oldbrush = pDC->SelectObject(&Brush);
		for (int i = 0; i < c1.GetSize(); i++)
		{
			pDC->Ellipse(c1.GetAt(i));
		}
		pDC->SelectObject(&oldbrush);
		ReleaseDC(pDC);

	}
	

}
