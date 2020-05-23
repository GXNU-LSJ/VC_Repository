
// 第四周实验2View.cpp : C第四周实验2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周实验2.h"
#endif

#include "第四周实验2Doc.h"
#include "第四周实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周实验2View

IMPLEMENT_DYNCREATE(C第四周实验2View, CView)

BEGIN_MESSAGE_MAP(C第四周实验2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第四周实验2View 构造/析构

C第四周实验2View::C第四周实验2View()
{
	// TODO: 在此处添加构造代码
	r = 60;
	f = 1;
}

C第四周实验2View::~C第四周实验2View()
{
	
}

BOOL C第四周实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周实验2View 绘制

void C第四周实验2View::OnDraw(CDC* pDC)
{
	C第四周实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	
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


// C第四周实验2View 诊断

#ifdef _DEBUG
void C第四周实验2View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周实验2Doc* C第四周实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周实验2Doc)));
	return (C第四周实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周实验2View 消息处理程序


void C第四周实验2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr1;
	this->GetClientRect(&cr1);
	C第四周实验2Doc* pDoc = GetDocument();
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


void C第四周实验2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	C第四周实验2Doc* pDoc = GetDocument();
	
		
		pDoc->cr.left = pDoc->cr.right-120;
		pDoc->cr.top = pDoc->cr.bottom -120;
		
	
		InvalidateRect(NULL, TRUE);

	CView::OnLButtonDown(nFlags, point);
}
