#pragma once


// record_set �Ի���

class record_set : public CDialogEx
{
	DECLARE_DYNAMIC(record_set)

public:
	record_set(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~record_set();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString s;
};
