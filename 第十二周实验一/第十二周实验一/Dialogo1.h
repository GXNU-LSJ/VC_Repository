#pragma once


// Dialogo1 对话框

class Dialogo1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialogo1)

public:
	Dialogo1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialogo1();
	CString s;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
};
