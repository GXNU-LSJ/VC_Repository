
// 第十三周实验二Dlg.h : 头文件
//

#pragma once


// C第十三周实验二Dlg 对话框
class C第十三周实验二Dlg : public CDialogEx
{
// 构造
public:
	C第十三周实验二Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	DECLARE_MESSAGE_MAP()
};
