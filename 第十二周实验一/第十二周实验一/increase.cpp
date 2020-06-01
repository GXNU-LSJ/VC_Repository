// increase.cpp : 实现文件
//

#include "stdafx.h"
#include "第十二周实验一.h"
#include "increase.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

// increase 对话框

IMPLEMENT_DYNAMIC(increase, CDialogEx)

increase::increase(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
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

increase::~increase()
{
}

void increase::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(increase, CDialogEx)
 ON_BN_CLICKED(IDC_BUTTON1, &increase::OnBnClickedButton1)
END_MESSAGE_MAP()


// increase 消息处理程序


void string_replace1(std::string &strBig, const std::string &strsrc, const std::string &strdst)
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


std::string GetPathOrURLShortName1(std::string strFullName)
{
	if (strFullName.empty())
	{
		return "";
	}

	string_replace1(strFullName, "/", "\\");

	std::string::size_type iPos = strFullName.find_last_of('\\') + 1;

	return strFullName.substr(iPos, strFullName.length() - iPos);
}



void increase::foo(CImage&img, int&sx, int&sy, int&w, int&h)
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



void increase::OnBnClickedButton1()
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
		string t = CT2A(filename1.GetString());
		string s = GetPathOrURLShortName1(t);
		CopyFile(filename1, path + CA2T(s.c_str()), false);
		GetDlgItem(IDC_EDIT9)->SetWindowTextW(CA2T(s.c_str()));
		ReleaseDC(pDC);
	}
}
