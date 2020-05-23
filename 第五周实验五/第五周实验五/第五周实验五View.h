
// 第五周实验五View.h : C第五周实验五View 类的接口
//

#pragma once


class C第五周实验五View : public CView
{
protected: // 仅从序列化创建
	C第五周实验五View();
	DECLARE_DYNCREATE(C第五周实验五View)

// 特性
public:
	C第五周实验五Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第五周实验五View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onxian();
	afx_msg void Onjuxing();
	afx_msg void Ontuoyuan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 第五周实验五View.cpp 中的调试版本
inline C第五周实验五Doc* C第五周实验五View::GetDocument() const
   { return reinterpret_cast<C第五周实验五Doc*>(m_pDocument); }
#endif

