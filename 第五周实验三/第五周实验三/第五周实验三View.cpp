
// 第五周实验三View.cpp : C第五周实验三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验三.h"
#endif

#include "第五周实验三Doc.h"
#include "第五周实验三View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验三View

IMPLEMENT_DYNCREATE(C第五周实验三View, CView)

BEGIN_MESSAGE_MAP(C第五周实验三View, CView)
	ON_COMMAND(ID_lsj, &C第五周实验三View::Onlsj)
END_MESSAGE_MAP()

// C第五周实验三View 构造/析构

C第五周实验三View::C第五周实验三View()
{
	// TODO: 在此处添加构造代码

}

C第五周实验三View::~C第五周实验三View()
{
}

BOOL C第五周实验三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验三View 绘制

void C第五周实验三View::OnDraw(CDC* /*pDC*/)
{
	C第五周实验三Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第五周实验三View 诊断

#ifdef _DEBUG
void C第五周实验三View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验三View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验三Doc* C第五周实验三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验三Doc)));
	return (C第五周实验三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验三View 消息处理程序


void C第五周实验三View::Onlsj()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("李世杰");
	CClientDC dc(this);
	dc.TextOutW(100, 200, s);
}
