
// �ھ���ʵ����Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C�ھ���ʵ����Dlg �Ի���
class C�ھ���ʵ����Dlg : public CDialogEx
{
// ����
public:
	~C�ھ���ʵ����Dlg();
	C�ھ���ʵ����Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	int x;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString a;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CListBox Lb;
};
