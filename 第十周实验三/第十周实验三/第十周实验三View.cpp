
// 第十周实验三View.cpp : C第十周实验三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十周实验三.h"
#endif

#include "第十周实验三Doc.h"
#include "第十周实验三View.h"
#include"w32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十周实验三View

IMPLEMENT_DYNCREATE(C第十周实验三View, CView)

BEGIN_MESSAGE_MAP(C第十周实验三View, CView)
END_MESSAGE_MAP()

// C第十周实验三View 构造/析构

C第十周实验三View::C第十周实验三View()
{
	// TODO: 在此处添加构造代码

}

C第十周实验三View::~C第十周实验三View()
{
}

BOOL C第十周实验三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第十周实验三View 绘制

void C第十周实验三View::OnDraw(CDC* pDC)
{
	C第十周实验三Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	float n;
	FAC f;
		n=f.convert(30.0);
		CString s;
		s.Format(_T("%f"), n);
		pDC->TextOutW(200, 200, s);

}


// C第十周实验三View 诊断

#ifdef _DEBUG
void C第十周实验三View::AssertValid() const
{
	CView::AssertValid();
}

void C第十周实验三View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第十周实验三Doc* C第十周实验三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十周实验三Doc)));
	return (C第十周实验三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十周实验三View 消息处理程序
