// Dialogo1.cpp : 实现文件
//

#include "stdafx.h"
#include "第十二周实验一.h"
#include "Dialogo1.h"
#include "afxdialogex.h"


// Dialogo1 对话框

IMPLEMENT_DYNAMIC(Dialogo1, CDialogEx)

Dialogo1::Dialogo1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dialogo1::~Dialogo1()
{
}

void Dialogo1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialogo1, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Dialogo1 消息处理程序


void Dialogo1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	if (s != "") {
		CImage img;
		img.Load(s);
		CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}

void Dialogo1::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = (rect.Height() - h) / 2;
		sx = 0;
	}
}
