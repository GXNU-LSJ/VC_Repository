
// 第十二周实验一View.h : C第十二周实验一View 类的接口
//

#pragma once

class C第十二周实验一Set;

class C第十二周实验一View : public CRecordView
{
protected: // 仅从序列化创建
	C第十二周实验一View();
	DECLARE_DYNCREATE(C第十二周实验一View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C第十二周实验一Set* m_pSet;

// 特性
public:
	C第十二周实验一Doc* GetDocument() const;

// 操作
public:
	CString path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C第十二周实验一View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birthday;
	CString phone;
	CString address;
	afx_msg void OnBnClickedButton1();
	void OnDraw(CDC * pDC);
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	CString filename;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};

#ifndef _DEBUG  // 第十二周实验一View.cpp 中的调试版本
inline C第十二周实验一Doc* C第十二周实验一View::GetDocument() const
   { return reinterpret_cast<C第十二周实验一Doc*>(m_pDocument); }
#endif

