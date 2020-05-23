
// 第一周实验一View.cpp : C第一周实验一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第一周实验一.h"
#endif

#include "第一周实验一Doc.h"
#include "第一周实验一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第一周实验一View

IMPLEMENT_DYNCREATE(C第一周实验一View, CView)

BEGIN_MESSAGE_MAP(C第一周实验一View, CView)
END_MESSAGE_MAP()

// C第一周实验一View 构造/析构

C第一周实验一View::C第一周实验一View()
{
	// TODO: 在此处添加构造代码

}

C第一周实验一View::~C第一周实验一View()
{
}

BOOL C第一周实验一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第一周实验一View 绘制

void C第一周实验一View::OnDraw(CDC* /*pDC*/)
{
	C第一周实验一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第一周实验一View 诊断

#ifdef _DEBUG
void C第一周实验一View::AssertValid() const
{
	CView::AssertValid();
}

void C第一周实验一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第一周实验一Doc* C第一周实验一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第一周实验一Doc)));
	return (C第一周实验一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第一周实验一View 消息处理程序
