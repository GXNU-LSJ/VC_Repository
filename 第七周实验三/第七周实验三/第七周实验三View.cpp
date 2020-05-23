
// 第七周实验三View.cpp : C第七周实验三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第七周实验三.h"
#endif

#include "第七周实验三Doc.h"
#include "第七周实验三View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第七周实验三View

IMPLEMENT_DYNCREATE(C第七周实验三View, CView)

BEGIN_MESSAGE_MAP(C第七周实验三View, CView)
	
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C第七周实验三View 构造/析构

C第七周实验三View::C第七周实验三View()
{
	// TODO: 在此处添加构造代码

}

C第七周实验三View::~C第七周实验三View()
{
}

BOOL C第七周实验三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第七周实验三View 绘制

void C第七周实验三View::OnDraw(CDC* pDC)
{
	C第七周实验三Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码


	
		
		CClientDC dc(this);
		int x = pDoc->p3.x - pDoc->p2.x;
		int y = pDoc->p3.y - pDoc->p2.y;
		int x1 = pDoc->p.x + x;
		int y1 = pDoc->p.y + y;
		CRect cr;
		cr.left =x1;
		cr.top =y1;
		cr.right = x1+50;
		cr.bottom = y1+50;
		Invalidate();
		
		dc.Rectangle(&cr);
		
}


// C第七周实验三View 诊断

#ifdef _DEBUG
void C第七周实验三View::AssertValid() const
{
	CView::AssertValid();
}

void C第七周实验三View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第七周实验三Doc* C第七周实验三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第七周实验三Doc)));
	return (C第七周实验三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第七周实验三View 消息处理程序





void C第七周实验三View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第七周实验三Doc* pDoc = GetDocument();
	if ((point.x >= pDoc->p.x)&& (point.x <= pDoc->p.x+50)&&(point.y >= pDoc->p.y)&&(point.y <= pDoc->p.y+50))
	{

		pDoc->f = 1;
		pDoc->p2 = point;
		pDoc->p3 = point;
	}
	


	CView::OnLButtonDown(nFlags, point);
}


void C第七周实验三View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第七周实验三Doc* pDoc = GetDocument();
	if (pDoc->f == 1)
	{
		pDoc->f = 0;
		pDoc->p3 = point;

	}

	CView::OnLButtonUp(nFlags, point);
}


void C第七周实验三View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第七周实验三Doc* pDoc = GetDocument();
	if (pDoc->f == 1)
	{
		pDoc->p3 = point;



	}



	CView::OnMouseMove(nFlags, point);
}
