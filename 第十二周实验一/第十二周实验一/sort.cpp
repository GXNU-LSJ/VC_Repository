// sort.cpp : 实现文件
//

#include "stdafx.h"
#include "第十二周实验一.h"
#include "sort.h"
#include "afxdialogex.h"


// sort 对话框

IMPLEMENT_DYNAMIC(sort, CDialogEx)

sort::sort(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, s(_T(""))
{

}

sort::~sort()
{
}

void sort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(sort, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &sort::OnEnChangeEdit1)
END_MESSAGE_MAP()


// sort 消息处理程序


void sort::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
