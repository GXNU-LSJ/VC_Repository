
// 第六周实验四View.cpp : C第六周实验四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周实验四.h"
#endif

#include "第六周实验四Doc.h"
#include "第六周实验四View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周实验四View

IMPLEMENT_DYNCREATE(C第六周实验四View, CView)

BEGIN_MESSAGE_MAP(C第六周实验四View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C第六周实验四View 构造/析构

C第六周实验四View::C第六周实验四View()
{
	// TODO: 在此处添加构造代码

}

C第六周实验四View::~C第六周实验四View()
{
}

BOOL C第六周实验四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周实验四View 绘制

void C第六周实验四View::OnDraw(CDC* pDC)
{
	C第六周实验四Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	CClientDC dc(this);
	pDC->Rectangle(109, 113, 1000, 180);
	int y = 115;
	int x=pDoc->x1;
	for (int i = 0; i < pDoc->s.GetSize(); i++)
	{
		
		if (x <= 985&&y<=165) {
			s = pDoc->s.GetAt(i);
			
			pDC->TextOutW(x, y, s);
		}
		x = x + 15;
		if (x > 985 && (y += 20 )<= 165) {
			 x = pDoc->x1;
			s = pDoc->s.GetAt(i);
			pDC->TextOutW(x, y, s);
		}
	}

}

// C第六周实验四View 诊断

#ifdef _DEBUG
void C第六周实验四View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周实验四View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周实验四Doc* C第六周实验四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周实验四Doc)));
	return (C第六周实验四Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周实验四View 消息处理程序


void C第六周实验四View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char s;
	C第六周实验四Doc* pDoc = GetDocument();
	s = (char)nChar;
	
	 pDoc->s.Add(s);
	this->Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
