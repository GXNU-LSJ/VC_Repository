
// �ڶ���ʵ���View.cpp : C�ڶ���ʵ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ���.h"
#endif

#include "�ڶ���ʵ���Doc.h"
#include "�ڶ���ʵ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ���View

IMPLEMENT_DYNCREATE(C�ڶ���ʵ���View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ���View, CView)
END_MESSAGE_MAP()

// C�ڶ���ʵ���View ����/����

C�ڶ���ʵ���View::C�ڶ���ʵ���View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ���ʵ���View::~C�ڶ���ʵ���View()
{
}

BOOL C�ڶ���ʵ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���ʵ���View ����

void C�ڶ���ʵ���View::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���


	CString s2 = pDoc->S2;
	pDC->TextOutW(100, 300, s2);
	int a2 = pDoc->A2;
	CString _a;
	_a.Format(_T("%d"), a2);
	pDC->TextOutW(100, 400, _a);
}


// C�ڶ���ʵ���View ���

#ifdef _DEBUG
void C�ڶ���ʵ���View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ���Doc* C�ڶ���ʵ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ���Doc)));
	return (C�ڶ���ʵ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ���View ��Ϣ�������
