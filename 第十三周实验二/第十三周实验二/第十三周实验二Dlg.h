
// ��ʮ����ʵ���Dlg.h : ͷ�ļ�
//

#pragma once


// C��ʮ����ʵ���Dlg �Ի���
class C��ʮ����ʵ���Dlg : public CDialogEx
{
// ����
public:
	C��ʮ����ʵ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	DECLARE_MESSAGE_MAP()
};
