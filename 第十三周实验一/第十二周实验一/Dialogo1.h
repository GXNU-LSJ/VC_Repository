#pragma once


// Dialogo1 �Ի���

class Dialogo1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialogo1)

public:
	Dialogo1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialogo1();
	CString s;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
};
