
// 第十三周实验三View.h : C第十三周实验三View 类的接口
//

#pragma once

class C第十三周实验三Set;

class C第十三周实验三View : public CRecordView
{
protected: // 仅从序列化创建
	C第十三周实验三View();
	DECLARE_DYNCREATE(C第十三周实验三View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C第十三周实验三Set* m_pSet;

// 特性
public:
	C第十三周实验三Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C第十三周实验三View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	int s;
};

#ifndef _DEBUG  // 第十三周实验三View.cpp 中的调试版本
inline C第十三周实验三Doc* C第十三周实验三View::GetDocument() const
   { return reinterpret_cast<C第十三周实验三Doc*>(m_pDocument); }
#endif

