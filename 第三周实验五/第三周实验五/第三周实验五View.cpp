
// 第三周实验五View.cpp : C第三周实验五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第三周实验五.h"
#endif

#include "第三周实验五Doc.h"
#include "第三周实验五View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第三周实验五View

IMPLEMENT_DYNCREATE(C第三周实验五View, CView)

BEGIN_MESSAGE_MAP(C第三周实验五View, CView)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C第三周实验五View 构造/析构

C第三周实验五View::C第三周实验五View()
{
	// TODO: 在此处添加构造代码

}

C第三周实验五View::~C第三周实验五View()
{
}

BOOL C第三周实验五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第三周实验五View 绘制

void C第三周实验五View::OnDraw(CDC* pDC)
{
	C第三周实验五Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr1(50, 50, 300, 300);
	pDC->Rectangle(cr1);
	CRect cr2(350, 50, 600, 300);
	pDC->Rectangle(cr2);
	CRect cr3(650, 50, 900, 300);
	pDC->Rectangle(cr3);
	CRect cr4(950, 50, 1200, 300);
	pDC->Rectangle(cr4);
	CClientDC dc(this);
	CString T;
	T = _T("＝");
	dc.TextOutW(917, 175, T);
}


// C第三周实验五View 诊断

#ifdef _DEBUG
void C第三周实验五View::AssertValid() const
{
	CView::AssertValid();
}

void C第三周实验五View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第三周实验五Doc* C第三周实验五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第三周实验五Doc)));
	return (C第三周实验五Doc*)m_pDocument;
}
#endif //_DEBUG


// C第三周实验五View 消息处理程序



int a = -1, b = -1,count = -1;;

void C第三周实验五View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);
	
	CString A, B, C, S = _T("点击无效！"),T=_T("                           ");
	CClientDC dc(this);
	dc.TextOutW(625, 500, T);
	srand((unsigned)time(NULL));
	if ((point.x >= 50) && (point.x <= 300) && (point.y >= 50 )&&( point.y <= 300))
	{
		a = rand() % 100;
		a = a*(pow(-1, rand() % 2));
		A.Format(_T("%d"), a);
		dc.TextOutW(175, 175, T);
		dc.TextOutW(175, 175, A);
	}
	if ((((point.x >= 50) && (point.x <= 300) && (point.y >= 50) && (point.y <= 300))||((point.x >= 350) && (point.x <= 600) && (point.y >= 50) && (point.y <= 300))||((point.x >= 650) && (point.x <= 900) && (point.y >= 50) && (point.y <= 300)))==0)
	{
		dc.TextOutW(625, 500, S);
	}

	if ((point.x >= 650) && (point.x <= 900) && (point.y >= 50) && (point.y <= 300))
	{
		b =  rand() % 100;
		b = b*(pow(-1, rand() % 2));
		B.Format(_T("%d"), b);
		dc.TextOutW(775, 175, T);
		dc.TextOutW(775, 175, B);
	}

	
	CString s=_T("     ");
	if ((point.x >= 350) && (point.x <= 600) && (point.y >= 50) && (point.y <= 300))
	{
		dc.TextOutW(475, 175, s);
		count++;
		if (count % 4 == 0)s = _T("＋");
		if (count % 4 == 1)s = _T("－");
		if (count % 4 == 2)s = _T("×");
		if (count % 4 == 3)s = _T("÷");
		dc.TextOutW(475, 175, s);
		
	}


	CView::OnLButtonDown(nFlags, point);
}


void C第三周实验五View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int c=0 ;
	CClientDC dc(this);

	CString s = _T("输入错误！"),S;
	if ((point.x >= 950) && (point.x <= 1200) && (point.y >= 50) && (point.y <= 300))
	{
		S = _T("                         ");
		dc.TextOutW(625, 500, S);
		if (a == -1 || b == -1 || count == -1) dc.TextOutW(1040, 175, s);
		else {
			
			dc.TextOutW(1040, 175, S);
			if (count % 4 == 0) { c = a + b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
			else if (count % 4 == 1) { c = a - b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
			else if (count % 4 == 2) { c = a * b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
			else {
				if (count % 4 == 3 && b != 0) { c = a / b; s.Format(_T("%d"), c); dc.TextOutW(1075, 175, s); }
				else dc.TextOutW(1040, 175, s);
			}
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
