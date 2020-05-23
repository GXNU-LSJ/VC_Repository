
// 第六周实验三View.cpp : C第六周实验三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周实验三.h"
#endif

#include "第六周实验三Doc.h"
#include "第六周实验三View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周实验三View

IMPLEMENT_DYNCREATE(C第六周实验三View, CView)

BEGIN_MESSAGE_MAP(C第六周实验三View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第六周实验三View 构造/析构

C第六周实验三View::C第六周实验三View()
{
	// TODO: 在此处添加构造代码

}

C第六周实验三View::~C第六周实验三View()
{
}

BOOL C第六周实验三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周实验三View 绘制

void C第六周实验三View::OnDraw(CDC* pDC)
{
	C第六周实验三Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	CClientDC dc(this);
	pDC->Rectangle(109, 113, 1000, 140);
	for (int i = 0; i < pDoc->s.GetSize(); i++)
	{
		if ((pDoc->x1 + i * 15) <= 985) {
			s = pDoc->s.GetAt(i);
			pDC->TextOutW(pDoc->x1 + i * 15, 115, s);
		}
	}
	
}


// C第六周实验三View 诊断

#ifdef _DEBUG
void C第六周实验三View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周实验三View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周实验三Doc* C第六周实验三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周实验三Doc)));
	return (C第六周实验三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周实验三View 消息处理程序


void C第六周实验三View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char s;
	C第六周实验三Doc* pDoc = GetDocument();
	s = (char)nChar;
		if ((pDoc->p.x >= pDoc->x1&&pDoc->p.x <= pDoc->x))
		{
			int i = (pDoc->p.x - pDoc->x1) / 15;
			pDoc->s.InsertAt(i, s);
		}
		else pDoc->s.Add(s);
		pDoc->x += 15;
		this->Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void C第六周实验三View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第六周实验三Doc* pDoc = GetDocument();
	if (point.y >= 113 && point.y <= 140)
	{
		pDoc->p = point;
		
	}
	CView::OnLButtonDown(nFlags, point);
}
