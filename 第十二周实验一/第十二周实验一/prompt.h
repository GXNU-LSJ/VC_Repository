#pragma once


// prompt �Ի���

class prompt : public CDialogEx
{
	DECLARE_DYNAMIC(prompt)

public:
	prompt(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~prompt();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
