// prompt.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ʮ����ʵ��һ.h"
#include "prompt.h"
#include "afxdialogex.h"


// prompt �Ի���

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


// prompt ��Ϣ�������
