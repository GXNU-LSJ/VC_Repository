// ADD.cpp : 实现文件
//

#include "stdafx.h"
#include "第十二周实验一.h"
#include "ADD.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>

using namespace std;
// ADD 对话框

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birthday(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, filename(_T(""))
{

}

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, number);
	DDX_Text(pDX, IDC_EDIT3, major);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT5, birthday);
	DDX_Text(pDX, IDC_EDIT6, phone);
	DDX_Text(pDX, IDC_EDIT7, address);
	DDX_Text(pDX, IDC_EDIT9, filename);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT9, &ADD::OnEnChangeEdit9)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &ADD::OnBnClickedButton1)
END_MESSAGE_MAP()


// ADD 消息处理程序


void ADD::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void ADD::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC11)->GetClientRect(&rect);
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


void ADD::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	if (s != "") {
		CImage img;
		img.Load(s);
		CDC*pDC = GetDlgItem(IDC_STATIC11)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void string_replace(std::string &strBig, const std::string &strsrc, const std::string &strdst)
{
	std::string::size_type pos = 0;
	std::string::size_type srclen = strsrc.size();
	std::string::size_type dstlen = strdst.size();

	while ((pos = strBig.find(strsrc, pos)) != std::string::npos)
	{
		strBig.replace(pos, srclen, strdst);
		pos += dstlen;
	}
}


std::string GetPathOrURLShortName(std::string strFullName)
{
	if (strFullName.empty())
	{
		return "";
	}

	string_replace(strFullName, "/", "\\");

	std::string::size_type iPos = strFullName.find_last_of('\\') + 1;

	return strFullName.substr(iPos, strFullName.length() - iPos);
}



void ADD::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog cfd(true);
	int n = cfd.DoModal();
	if (n == IDOK)
	{
		CString filename1 = cfd.GetPathName();
		CImage img;
		img.Load(filename1);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC*pDC = GetDlgItem(IDC_STATIC11)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		f = 1;
		string t = CT2A(filename1.GetString());
		string s = GetPathOrURLShortName(t);
		//DeleteFile(file);
		CopyFile(filename1,path+CA2T(s.c_str()),false);
		GetDlgItem(IDC_EDIT9)->SetWindowTextW(CA2T(s.c_str()));
		ReleaseDC(pDC);
	}
}

