#pragma once


// ADD �Ի���

class ADD : public CDialogEx
{
	DECLARE_DYNAMIC(ADD)

public:
	ADD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADD();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birthday;
	CString phone;
	CString address;
	afx_msg void OnEnChangeEdit9();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	CString filename;
	CString s;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	int f = 0;
	CString path;
	CString file;
};
