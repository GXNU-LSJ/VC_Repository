#pragma once


// increase �Ի���

class increase : public CDialogEx
{
	DECLARE_DYNAMIC(increase)

public:
	increase(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~increase();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	void foo(CImage & img, int & sx, int & sy, int & w, int & h);

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birthday;
	CString phone;
	CString address;
	CString filename;
	afx_msg void OnBnClickedButton1();
	CString path;
};
