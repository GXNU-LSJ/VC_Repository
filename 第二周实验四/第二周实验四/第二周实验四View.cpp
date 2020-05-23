
// 第二周实验四View.cpp : C第二周实验四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验四.h"
#endif

#include "第二周实验四Doc.h"
#include "第二周实验四View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验四View

IMPLEMENT_DYNCREATE(C第二周实验四View, CView)

BEGIN_MESSAGE_MAP(C第二周实验四View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第二周实验四View 构造/析构

C第二周实验四View::C第二周实验四View()
{
	// TODO: 在此处添加构造代码

}

C第二周实验四View::~C第二周实验四View()
{
}

BOOL C第二周实验四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二周实验四View 绘制

void C第二周实验四View::OnDraw(CDC* /*pDC*/)
{
	C第二周实验四Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第二周实验四View 诊断

#ifdef _DEBUG
void C第二周实验四View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验四View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验四Doc* C第二周实验四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验四Doc)));
	return (C第二周实验四Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验四View 消息处理程序


void C第二周实验四View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect c;
	int r = rand() % 100 + 30;
	c.top = point.y - r;
	c.bottom = point.y + r;
	c.left = point.x - r;
	c.right = point.x + r;
	CClientDC dc(this);
	dc.Ellipse(&c);

	CView::OnLButtonDown(nFlags, point);
}
