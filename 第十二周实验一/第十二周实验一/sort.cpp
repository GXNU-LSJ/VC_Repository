// sort.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ʮ����ʵ��һ.h"
#include "sort.h"
#include "afxdialogex.h"


// sort �Ի���

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


// sort ��Ϣ�������


void sort::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
