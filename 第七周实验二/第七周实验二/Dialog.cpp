// Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������ʵ���.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog �Ի���

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
	, b(_T(""))

{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &Dialog::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &Dialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Dialog ��Ϣ�������


void Dialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	CString c;
	c = a; a = b; b = c;
	UpdateData(false);
}


void Dialog::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void Dialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
