
// lib1View.cpp : Clib1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lib1.h"
#endif

#include "lib1Doc.h"
#include "lib1View.h"
#include"W32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clib1View

IMPLEMENT_DYNCREATE(Clib1View, CView)

BEGIN_MESSAGE_MAP(Clib1View, CView)
END_MESSAGE_MAP()

// Clib1View 构造/析构

Clib1View::Clib1View()
{
	// TODO: 在此处添加构造代码

}

Clib1View::~Clib1View()
{
}

BOOL Clib1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clib1View 绘制

void Clib1View::OnDraw(CDC* pDC)
{
	Clib1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int n;
	n = factorial(9);
	CString s;
	s.Format(_T("%d"), n);
	pDC->TextOutW(200, 200,s);
}


// Clib1View 诊断

#ifdef _DEBUG
void Clib1View::AssertValid() const
{
	CView::AssertValid();
}

void Clib1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clib1Doc* Clib1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clib1Doc)));
	return (Clib1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clib1View 消息处理程序
