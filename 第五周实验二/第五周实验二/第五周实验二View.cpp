
// 第五周实验二View.cpp : C第五周实验二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验二.h"
#endif

#include "第五周实验二Doc.h"
#include "第五周实验二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验二View

IMPLEMENT_DYNCREATE(C第五周实验二View, CView)

BEGIN_MESSAGE_MAP(C第五周实验二View, CView)
	ON_COMMAND(ID_jianbianyuan, &C第五周实验二View::Onjianbianyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C第五周实验二View 构造/析构

C第五周实验二View::C第五周实验二View()
{
	// TODO: 在此处添加构造代码
	set = true;
}

C第五周实验二View::~C第五周实验二View()
{
}

BOOL C第五周实验二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验二View 绘制

void C第五周实验二View::OnDraw(CDC* pDC)
{
	C第五周实验二Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// C第五周实验二View 诊断

#ifdef _DEBUG
void C第五周实验二View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验二View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验二Doc* C第五周实验二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验二Doc)));
	return (C第五周实验二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验二View 消息处理程序


void C第五周实验二View::Onjianbianyuan()
{
	// TODO: 在此添加命令处理程序代码
	CRect cr, cr1;
	CPoint p;
	CClientDC dc(this);
	C第五周实验二Doc* pDoc = GetDocument();
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


void C第五周实验二View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第五周实验二Doc* pDoc = GetDocument();
	if (pDoc->f1 == 0)
	{
		C第五周实验二View::Onjianbianyuan();
	}

	CView::OnTimer(nIDEvent);
}
