// query.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ʮ����ʵ��һ.h"
#include "query.h"
#include "afxdialogex.h"


// query �Ի���

IMPLEMENT_DYNAMIC(query, CDialogEx)

query::query(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, s(_T(""))
{

}

query::~query()
{
}

void query::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(query, CDialogEx)
END_MESSAGE_MAP()


// query ��Ϣ�������
