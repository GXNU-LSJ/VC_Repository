
// 第二周实验六View.cpp : C第二周实验六View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验六.h"
#endif

#include "第二周实验六Doc.h"
#include "第二周实验六View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验六View

IMPLEMENT_DYNCREATE(C第二周实验六View, CView)

BEGIN_MESSAGE_MAP(C第二周实验六View, CView)
END_MESSAGE_MAP()

// C第二周实验六View 构造/析构

C第二周实验六View::C第二周实验六View()
{
	// TODO: 在此处添加构造代码

}

C第二周实验六View::~C第二周实验六View()
{
}

BOOL C第二周实验六View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二周实验六View 绘制

void C第二周实验六View::OnDraw(CDC* pDC)
{
	C第二周实验六Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect c;
	this->GetClientRect(&c);
	pDC->Ellipse(c);
}


// C第二周实验六View 诊断

#ifdef _DEBUG
void C第二周实验六View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验六View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验六Doc* C第二周实验六View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验六Doc)));
	return (C第二周实验六Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验六View 消息处理程序
