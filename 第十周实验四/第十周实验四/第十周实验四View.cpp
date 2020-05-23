
// 第十周实验四View.cpp : C第十周实验四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十周实验四.h"
#endif

#include "第十周实验四Doc.h"
#include "第十周实验四View.h"
#include"w32d.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十周实验四View

IMPLEMENT_DYNCREATE(C第十周实验四View, CView)

BEGIN_MESSAGE_MAP(C第十周实验四View, CView)
END_MESSAGE_MAP()

// C第十周实验四View 构造/析构

C第十周实验四View::C第十周实验四View()
{
	// TODO: 在此处添加构造代码

}

C第十周实验四View::~C第十周实验四View()
{
}

BOOL C第十周实验四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第十周实验四View 绘制

void C第十周实验四View::OnDraw(CDC* pDC)
{
	C第十周实验四Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int n;
	n = factorial(9);
	CString s;
	s.Format(_T("%d"), n);
	pDC->TextOutW(200, 200, s);
	float x;
	FAC f;
	x = f.convert(30.0);
	s.Format(_T("%f"), x);
	pDC->TextOutW(200, 220, s);


}


// C第十周实验四View 诊断

#ifdef _DEBUG
void C第十周实验四View::AssertValid() const
{
	CView::AssertValid();
}

void C第十周实验四View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第十周实验四Doc* C第十周实验四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十周实验四Doc)));
	return (C第十周实验四Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十周实验四View 消息处理程序
