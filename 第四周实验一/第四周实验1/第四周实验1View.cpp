
// 第四周实验1View.cpp : C第四周实验1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周实验1.h"
#endif

#include "第四周实验1Doc.h"
#include "第四周实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周实验1View

IMPLEMENT_DYNCREATE(C第四周实验1View, CView)

BEGIN_MESSAGE_MAP(C第四周实验1View, CView)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C第四周实验1View 构造/析构

C第四周实验1View::C第四周实验1View()
{
	// TODO: 在此处添加构造代码

}

C第四周实验1View::~C第四周实验1View()
{
}

BOOL C第四周实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周实验1View 绘制

void C第四周实验1View::OnDraw(CDC* pDC)
{
	C第四周实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s,x=_T("                                                 ");
	s.Format(_T("MouseMove发生了%d次"), pDoc->n);
	CClientDC dc(this);
	dc.TextOut(200, 200, x);
	dc.TextOut(200, 200,s);

	dc.TextOut(600, 200, x);
	x.Format(_T("移动%d个像素每次"), pDoc->x2.x-pDoc->x1.x);
	dc.TextOut(600, 200, x);
	pDoc->x1.x = pDoc->x2.x;
}


// C第四周实验1View 诊断

#ifdef _DEBUG
void C第四周实验1View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周实验1Doc* C第四周实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周实验1Doc)));
	return (C第四周实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周实验1View 消息处理程序


void C第四周实验1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验1Doc* pDoc = GetDocument();
	if(nFlags&&MK_LBUTTON)
	{
		pDoc->n += 1;
		InvalidateRect(NULL, FALSE);
		pDoc->x2.x = point.x;
	}
	CView::OnMouseMove(nFlags, point);
}
