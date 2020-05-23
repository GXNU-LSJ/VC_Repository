
// 第二周实验五View.cpp : C第二周实验五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验五.h"
#endif

#include "第二周实验五Doc.h"
#include "第二周实验五View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验五View

IMPLEMENT_DYNCREATE(C第二周实验五View, CView)

BEGIN_MESSAGE_MAP(C第二周实验五View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第二周实验五View 构造/析构

C第二周实验五View::C第二周实验五View()
{
	// TODO: 在此处添加构造代码

}

C第二周实验五View::~C第二周实验五View()
{
}

BOOL C第二周实验五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二周实验五View 绘制

void C第二周实验五View::OnDraw(CDC* pDC)
{
	C第二周实验五Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->p);
}


// C第二周实验五View 诊断

#ifdef _DEBUG
void C第二周实验五View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验五View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验五Doc* C第二周实验五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验五Doc)));
	return (C第二周实验五Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验五View 消息处理程序


void C第二周实验五View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 100 + 30;
	C第二周实验五Doc* pDoc = GetDocument();
	CRect c;
	c.top = point.y - r;
	c.bottom = point.y + r;
	c.left = point.x - r;
	c.right = point.x + r;
	pDoc->p = c;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
