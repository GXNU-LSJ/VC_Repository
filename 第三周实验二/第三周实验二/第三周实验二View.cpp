
// 第三周实验二View.cpp : C第三周实验二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第三周实验二.h"
#endif

#include "第三周实验二Doc.h"
#include "第三周实验二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第三周实验二View

IMPLEMENT_DYNCREATE(C第三周实验二View, CView)

BEGIN_MESSAGE_MAP(C第三周实验二View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第三周实验二View 构造/析构

C第三周实验二View::C第三周实验二View()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);
}

C第三周实验二View::~C第三周实验二View()
{
}

BOOL C第三周实验二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第三周实验二View 绘制

void C第三周实验二View::OnDraw(CDC* pDC)
{
	C第三周实验二Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	for (int i = 0; i < ca.GetSize(); i++)
	{
		
		pDC->Ellipse(ca.GetAt(i));
	}
}


// C第三周实验二View 诊断

#ifdef _DEBUG
void C第三周实验二View::AssertValid() const
{
	CView::AssertValid();
}

void C第三周实验二View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第三周实验二Doc* C第三周实验二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第三周实验二Doc)));
	return (C第三周实验二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第三周实验二View 消息处理程序





void C第三周实验二View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	int r1 = rand() % 50 + 5;
	int r2 = rand() % 50 + 5;
	CRect cr(point.x - r1, point.y - r2, point.x + r1, point.y + r2);
	ca.Add(cr);
	this->Invalidate();


	CView::OnLButtonDown(nFlags, point);
}
