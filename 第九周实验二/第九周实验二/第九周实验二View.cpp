
// �ھ���ʵ���View.cpp : C�ھ���ʵ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ���ʵ���.h"
#endif

#include "�ھ���ʵ���Doc.h"
#include "�ھ���ʵ���View.h"
#include "Dialog.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ھ���ʵ���View

IMPLEMENT_DYNCREATE(C�ھ���ʵ���View, CView)

BEGIN_MESSAGE_MAP(C�ھ���ʵ���View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C�ھ���ʵ���View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &C�ھ���ʵ���View::OnFileSaveAs)
	ON_COMMAND(ID_32771, &C�ھ���ʵ���View::On32771)
END_MESSAGE_MAP()

// C�ھ���ʵ���View ����/����

C�ھ���ʵ���View::C�ھ���ʵ���View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ھ���ʵ���View::~C�ھ���ʵ���View()
{
}

BOOL C�ھ���ʵ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ���ʵ���View ����

void C�ھ���ʵ���View::OnDraw(CDC* /*pDC*/)
{
	C�ھ���ʵ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ���ʵ���View ���

#ifdef _DEBUG
void C�ھ���ʵ���View::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ���ʵ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ���ʵ���Doc* C�ھ���ʵ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ���ʵ���Doc)));
	return (C�ھ���ʵ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ���ʵ���View ��Ϣ�������


void C�ھ���ʵ���View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int n = cfd.DoModal();
	CClientDC dc(this);
	if (n == IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 200, filename);
		C�ھ���ʵ���Doc* pDoc = GetDocument();
		pDoc->abc = filename;
		//ofstream ifs(filename);
		//ifs << filename;
	}
}


void C�ھ���ʵ���View::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int n = cfd.DoModal();
	CString filename = cfd.GetPathName();
	C�ھ���ʵ���Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (n == IDOK)
	{
		ofstream ofs(filename);
		ofs << CT2A(pDoc->abc.GetString());
		ofs.close();
	}
}


void C�ھ���ʵ���View::On32771()
{
	// TODO: �ڴ���������������
	Dialog dlg;
	dlg.DoModal();
}
