
// 第七周实验五View.h : C第七周实验五View 类的接口
//

#pragma once


class C第七周实验五View : public CView
{
protected: // 仅从序列化创建
	C第七周实验五View();
	DECLARE_DYNCREATE(C第七周实验五View)

// 特性
public:
	C第七周实验五Doc* GetDocument() const;

// 操作
public:
	CRect cr=CRect(300,300,320,320);
	int f = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第七周实验五View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 第七周实验五View.cpp 中的调试版本
inline C第七周实验五Doc* C第七周实验五View::GetDocument() const
   { return reinterpret_cast<C第七周实验五Doc*>(m_pDocument); }
#endif

