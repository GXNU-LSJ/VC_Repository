// prompt.cpp : 实现文件
//

#include "stdafx.h"
#include "第十二周实验一.h"
#include "prompt.h"
#include "afxdialogex.h"


// prompt 对话框

IMPLEMENT_DYNAMIC(prompt, CDialogEx)

prompt::prompt(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

prompt::~prompt()
{
}

void prompt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(prompt, CDialogEx)
END_MESSAGE_MAP()


// prompt 消息处理程序
