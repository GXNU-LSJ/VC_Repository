// record_set.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ʮ����ʵ��һ.h"
#include "record_set.h"
#include "afxdialogex.h"


// record_set �Ի���

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


// record_set ��Ϣ�������
