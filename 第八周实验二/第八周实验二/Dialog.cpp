// Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ڰ���ʵ���.h"
#include "Dialog.h"
#include "afxdialogex.h"

// Dialog �Ի���

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Dialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Dialog ��Ϣ�������


void Dialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
}





