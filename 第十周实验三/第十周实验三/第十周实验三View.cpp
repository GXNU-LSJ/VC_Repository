
// ��ʮ��ʵ����View.cpp : C��ʮ��ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮ��ʵ����.h"
#endif

#include "��ʮ��ʵ����Doc.h"
#include "��ʮ��ʵ����View.h"
#include"w32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ��ʵ����View

IMPLEMENT_DYNCREATE(C��ʮ��ʵ����View, CView)

BEGIN_MESSAGE_MAP(C��ʮ��ʵ����View, CView)
END_MESSAGE_MAP()

// C��ʮ��ʵ����View ����/����

C��ʮ��ʵ����View::C��ʮ��ʵ����View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ʮ��ʵ����View::~C��ʮ��ʵ����View()
{
}

BOOL C��ʮ��ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ʮ��ʵ����View ����

void C��ʮ��ʵ����View::OnDraw(CDC* pDC)
{
	C��ʮ��ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	float n;
	FAC f;
		n=f.convert(30.0);
		CString s;
		s.Format(_T("%f"), n);
		pDC->TextOutW(200, 200, s);

}


// C��ʮ��ʵ����View ���

#ifdef _DEBUG
void C��ʮ��ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C��ʮ��ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ʮ��ʵ����Doc* C��ʮ��ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮ��ʵ����Doc)));
	return (C��ʮ��ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮ��ʵ����View ��Ϣ�������
