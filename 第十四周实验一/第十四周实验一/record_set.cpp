// record_set.cpp : 实现文件
//

#include "stdafx.h"
#include "第十四周实验一.h"
#include "record_set.h"
#include "afxdialogex.h"


// record_set 对话框

IMPLEMENT_DYNAMIC(record_set, CDialogEx)

record_set::record_set(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{

}

record_set::~record_set()
{
}

void record_set::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(record_set, CDialogEx)
END_MESSAGE_MAP()


// record_set 消息处理程序
