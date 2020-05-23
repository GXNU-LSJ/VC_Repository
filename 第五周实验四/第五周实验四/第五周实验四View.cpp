
// 第五周实验四View.cpp : C第五周实验四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验四.h"
#endif

#include "第五周实验四Doc.h"
#include "第五周实验四View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验四View

IMPLEMENT_DYNCREATE(C第五周实验四View, CView)

BEGIN_MESSAGE_MAP(C第五周实验四View, CView)
END_MESSAGE_MAP()

// C第五周实验四View 构造/析构

C第五周实验四View::C第五周实验四View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_w = BM.bmWidth;
	m_h = BM.bmHeight;
}

C第五周实验四View::~C第五周实验四View()
{
}

BOOL C第五周实验四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验四View 绘制

void C第五周实验四View::OnDraw(CDC* pDC)
{
	C第五周实验四Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(100, 100, m_w, m_h, &MemDC, 0, 0, SRCCOPY);
}


// C第五周实验四View 诊断

#ifdef _DEBUG
void C第五周实验四View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验四View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验四Doc* C第五周实验四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验四Doc)));
	return (C第五周实验四Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验四View 消息处理程序
