// Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������ʵ����.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog �Ի���

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
	, c(_T(""))
	, b(0)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT2, b);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// Dialog ��Ϣ�������




void Dialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	CString s;
	s.Format(_T("%d"), b);
	c = a + s;

	UpdateData(false);
}
