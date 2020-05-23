
// �ھ���ʵ����View.cpp : C�ھ���ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ���ʵ����.h"
#endif

#include "�ھ���ʵ����Doc.h"
#include "�ھ���ʵ����View.h"
#include<fstream>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ھ���ʵ����View

IMPLEMENT_DYNCREATE(C�ھ���ʵ����View, CView)

BEGIN_MESSAGE_MAP(C�ھ���ʵ����View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &C�ھ���ʵ����View::OnFileOpen)
END_MESSAGE_MAP()

// C�ھ���ʵ����View ����/����

C�ھ���ʵ����View::C�ھ���ʵ����View()
{
	// TODO: �ڴ˴���ӹ������
}

C�ھ���ʵ����View::~C�ھ���ʵ����View()
{
}

BOOL C�ھ���ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ���ʵ����View ����

void C�ھ���ʵ����View::OnDraw(CDC* pDC)
{
	C�ھ���ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < cr.GetSize(); i++)
	{
		pDC->Ellipse(cr[i]);
	}

}


// C�ھ���ʵ����View ���

#ifdef _DEBUG
void C�ھ���ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ���ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ���ʵ����Doc* C�ھ���ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ���ʵ����Doc)));
	return (C�ھ���ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ���ʵ����View ��Ϣ�������


void C�ھ���ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p1 = p2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void C�ھ���ʵ����View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (MK_LBUTTON&&nFlags) {
		CRect c;
		c.left = p1.x; c.top = p1.y; c.right = point.x; c.bottom = point.y;
		CClientDC dc(this);
		this->Invalidate();
		dc.Ellipse(c);
		
	}
	CView::OnMouseMove(nFlags, point);
}


void C�ھ���ʵ����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect c;
	c.left = p1.x; c.top = p1.y; c.right = point.x; c.bottom = point.y;
	cr.Add(c);
	CClientDC dc(this);
	Invalidate();
	dc.Ellipse(c);
	ofstream ofs;
	ofs.open(_T("C:\\Users\\Hasee\\Desktop\\��Բ.ty"),ofstream::out);
	for (int i = 0; i<cr.GetSize(); i++)
	{
		ofs << cr[i].top<<' ';
		ofs << cr[i].bottom << ' ';
		ofs << cr[i].left<< ' ';
		ofs << cr[i].right<<endl;
	}
	ofs.close();
	CView::OnLButtonUp(nFlags, point);
}


void C�ھ���ʵ����View::OnFileOpen()
{
	// TODO: �ڴ���������������
	//file.Close();
	CFileDialog file(true);
	if (file.DoModal() == IDOK) {
		CString filename = file.GetPathName();
		ifstream ifs;
		ifs.open(filename);
		int i = 0;
		while (!ifs.eof())
		{
			CRect c;
			ifs >> c.top;
			ifs >> c.bottom;
			ifs >> c.left;
			ifs >> c.right;
			cr.Add(c);
			i++;
		}
		ifs.close();
		Invalidate();
	}
}
