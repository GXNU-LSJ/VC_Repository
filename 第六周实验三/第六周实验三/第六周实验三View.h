
// 第六周实验三View.h : C第六周实验三View 类的接口
//

#pragma once


class C第六周实验三View : public CView
{
protected: // 仅从序列化创建
	C第六周实验三View();
	DECLARE_DYNCREATE(C第六周实验三View)

// 特性
public:
	C第六周实验三Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第六周实验三View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 第六周实验三View.cpp 中的调试版本
inline C第六周实验三Doc* C第六周实验三View::GetDocument() const
   { return reinterpret_cast<C第六周实验三Doc*>(m_pDocument); }
#endif

