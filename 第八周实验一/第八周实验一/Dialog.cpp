// Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ڰ���ʵ��һ.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog �Ի���

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
END_MESSAGE_MAP()


// Dialog ��Ϣ�������
