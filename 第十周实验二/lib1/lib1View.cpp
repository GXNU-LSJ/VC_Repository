
// lib1View.cpp : Clib1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// Clib1View ����/����

Clib1View::Clib1View()
{
	// TODO: �ڴ˴���ӹ������

}

Clib1View::~Clib1View()
{
}

BOOL Clib1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Clib1View ����

void Clib1View::OnDraw(CDC* pDC)
{
	Clib1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int n;
	n = factorial(9);
	CString s;
	s.Format(_T("%d"), n);
	pDC->TextOutW(200, 200,s);
}


// Clib1View ���

#ifdef _DEBUG
void Clib1View::AssertValid() const
{
	CView::AssertValid();
}

void Clib1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clib1Doc* Clib1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clib1Doc)));
	return (Clib1Doc*)m_pDocument;
}
#endif //_DEBUG


// Clib1View ��Ϣ�������
