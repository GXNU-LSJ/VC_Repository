
// 第八次实验五View.cpp : C第八次实验五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第八次实验五.h"
#endif

#include "第八次实验五Doc.h"
#include "第八次实验五View.h"
#include"Dialog.h"
#include"Dialog2.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第八次实验五View

IMPLEMENT_DYNCREATE(C第八次实验五View, CView)

BEGIN_MESSAGE_MAP(C第八次实验五View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32771, &C第八次实验五View::On32771)
	ON_COMMAND(ID_32772, &C第八次实验五View::On32772)
	ON_COMMAND(ID_32773, &C第八次实验五View::On32773)
	ON_COMMAND(ID_32774, &C第八次实验五View::On32774)
END_MESSAGE_MAP()

// C第八次实验五View 构造/析构

C第八次实验五View::C第八次实验五View()
{
	// TODO: 在此处添加构造代码

}

C第八次实验五View::~C第八次实验五View()
{
}

BOOL C第八次实验五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第八次实验五View 绘制

void C第八次实验五View::OnDraw(CDC* pDC)
{
	C第八次实验五Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// C第八次实验五View 诊断

#ifdef _DEBUG
void C第八次实验五View::AssertValid() const
{
	CView::AssertValid();
}

void C第八次实验五View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第八次实验五Doc* C第八次实验五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第八次实验五Doc)));
	return (C第八次实验五Doc*)m_pDocument;
}
#endif //_DEBUG


// C第八次实验五View 消息处理程序


void C第八次实验五View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
			pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));//虚线
			pOldPen = dc->SelectObject(&pen);

			CBrush * pOldBrush = NULL;
			CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//背景透明效果
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


void C第八次实验五View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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



void C第八次实验五View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect cr;
	cr.left = p1.x; cr.top = p1.y; cr.right = p2.x, cr.bottom = p2.y;
	dc.Ellipse(&cr);
	c.Add(cr);
	CView::OnLButtonUp(nFlags, point);
}


void C第八次实验五View::On32771()
{
	// TODO: 在此添加命令处理程序代码
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


void C第八次实验五View::On32772()
{
	// TODO: 在此添加命令处理程序代码

	f = 0;

}


void C第八次实验五View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	f = 1;
	Invalidate();
}


void C第八次实验五View::On32774()
{
	// TODO: 在此添加命令处理程序代码
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
