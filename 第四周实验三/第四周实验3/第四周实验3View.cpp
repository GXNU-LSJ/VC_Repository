
// ������ʵ��3View.cpp : C������ʵ��3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ��3.h"
#endif

#include "������ʵ��3Doc.h"
#include "������ʵ��3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ��3View

IMPLEMENT_DYNCREATE(C������ʵ��3View, CView)

BEGIN_MESSAGE_MAP(C������ʵ��3View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C������ʵ��3View ����/����

C������ʵ��3View::C������ʵ��3View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);


	}
}

C������ʵ��3View::~C������ʵ��3View()
{
}

BOOL C������ʵ��3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ��3View ����

void C������ʵ��3View::OnDraw(CDC* pDC)
{
	C������ʵ��3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		for (int i = 0; i < N; i++) {
			SetTimer(i, rand() % 400 + 100, NULL);
			set == false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// C������ʵ��3View ���

#ifdef _DEBUG
void C������ʵ��3View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ��3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ��3Doc* C������ʵ��3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ��3Doc)));
	return (C������ʵ��3Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ��3View ��Ϣ�������


void C������ʵ��3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr1;
	this->GetClientRect(&cr1);
	int i = nIDEvent;
	if ((cr1.bottom > cr[i].bottom)&&(f[i]==1))
	{
		cr[i].top += 30;
		cr[i].bottom += 30;
		Invalidate();
	}
	else {
		f[i] = 0;
		cr[i].top -= 30;
		cr[i].bottom -= 30;
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}
