
// 第五周实验五View.cpp : C第五周实验五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验五.h"
#endif

#include "第五周实验五Doc.h"
#include "第五周实验五View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验五View

IMPLEMENT_DYNCREATE(C第五周实验五View, CView)

BEGIN_MESSAGE_MAP(C第五周实验五View, CView)
	ON_COMMAND(ID_xian, &C第五周实验五View::Onxian)
	ON_COMMAND(ID_juxing, &C第五周实验五View::Onjuxing)
	ON_COMMAND(ID_tuoyuan, &C第五周实验五View::Ontuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第五周实验五View 构造/析构

C第五周实验五View::C第五周实验五View()
{
	// TODO: 在此处添加构造代码

}

C第五周实验五View::~C第五周实验五View()
{
}

BOOL C第五周实验五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验五View 绘制

void C第五周实验五View::OnDraw(CDC* /*pDC*/)
{
	C第五周实验五Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第五周实验五View 诊断

#ifdef _DEBUG
void C第五周实验五View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验五View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验五Doc* C第五周实验五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验五Doc)));
	return (C第五周实验五Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验五View 消息处理程序


void C第五周实验五View::Onxian()
{
	// TODO: 在此添加命令处理程序代码
	C第五周实验五Doc* pDoc = GetDocument();
	pDoc->f = 1;
	

}


void C第五周实验五View::Onjuxing()
{
	// TODO: 在此添加命令处理程序代码
	C第五周实验五Doc* pDoc = GetDocument();
	pDoc->f = 2;
}


void C第五周实验五View::Ontuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	C第五周实验五Doc* pDoc = GetDocument();
	pDoc->f = 3;
}


void C第五周实验五View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第五周实验五Doc* pDoc = GetDocument();

	pDoc->p1.x = point.x;
	pDoc->p1.y = point.y;
		CView::OnLButtonDown(nFlags, point);
}


void C第五周实验五View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第五周实验五Doc* pDoc = GetDocument();
	pDoc->p2.x = point.x;
	pDoc->p2.y = point.y;
	CClientDC dc(this);
	CRect cr(pDoc->p1.x, pDoc->p1.y, pDoc->p2.x, pDoc->p2.y);
	int f = pDoc->f;
	if (f == 1) {
		
		dc.MoveTo(pDoc->p1.x, pDoc->p1.y);
		dc.LineTo(pDoc->p2.x, pDoc->p2.y);

	}
	if (f == 2) {
		dc.Rectangle(cr);
	}

	if (f == 3) {
		
		dc.Ellipse(cr);
	}

	CView::OnLButtonUp(nFlags, point);
}
