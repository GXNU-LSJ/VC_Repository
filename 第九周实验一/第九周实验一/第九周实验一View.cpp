
// �ھ���ʵ��һView.cpp : C�ھ���ʵ��һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ���ʵ��һ.h"
#endif

#include "�ھ���ʵ��һDoc.h"
#include "�ھ���ʵ��һView.h"

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ھ���ʵ��һView

IMPLEMENT_DYNCREATE(C�ھ���ʵ��һView, CView)

BEGIN_MESSAGE_MAP(C�ھ���ʵ��һView, CView)
	ON_COMMAND(ID_FILE_OPEN, &C�ھ���ʵ��һView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &C�ھ���ʵ��һView::OnFileSaveAs)
END_MESSAGE_MAP()

// C�ھ���ʵ��һView ����/����

C�ھ���ʵ��һView::C�ھ���ʵ��һView()
{
	// TODO: �ڴ˴���ӹ������

}

C�ھ���ʵ��һView::~C�ھ���ʵ��һView()
{
}

BOOL C�ھ���ʵ��һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ���ʵ��һView ����

void C�ھ���ʵ��һView::OnDraw(CDC* /*pDC*/)
{
	C�ھ���ʵ��һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ���ʵ��һView ���

#ifdef _DEBUG
void C�ھ���ʵ��һView::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ���ʵ��һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ���ʵ��һDoc* C�ھ���ʵ��һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ���ʵ��һDoc)));
	return (C�ھ���ʵ��һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ���ʵ��һView ��Ϣ�������


void C�ھ���ʵ��һView::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int n = cfd.DoModal();
	CClientDC dc(this);
	if (n == IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 200, filename);
		C�ھ���ʵ��һDoc* pDoc = GetDocument();
		pDoc->abc = filename;
		//ofstream ifs(filename);
		//ifs << filename;

	}
}


void C�ھ���ʵ��һView::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int n = cfd.DoModal();
	CString filename = cfd.GetPathName();
	C�ھ���ʵ��һDoc* pDoc = GetDocument();
	CClientDC dc(this);
	if (n == IDOK)
	{

		ofstream ofs(filename);
		ofs << CT2A(pDoc->abc.GetString());
		ofs.close();
	}
	
}
