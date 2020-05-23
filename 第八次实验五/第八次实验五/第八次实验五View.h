
// 第八次实验五View.h : C第八次实验五View 类的接口
//

#pragma once


class C第八次实验五View : public CView
{
protected: // 仅从序列化创建
	C第八次实验五View();
	DECLARE_DYNCREATE(C第八次实验五View)

// 特性
public:
	C第八次实验五Doc* GetDocument() const;

// 操作
public:
	CArray<CRect> c,c1;
	CArray<int> R, G, B;
	int N = 50;
	CPoint p1,p2;
	int f = 1;
	int r, g, b;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第八次实验五View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
};

#ifndef _DEBUG  // 第八次实验五View.cpp 中的调试版本
inline C第八次实验五Doc* C第八次实验五View::GetDocument() const
   { return reinterpret_cast<C第八次实验五Doc*>(m_pDocument); }
#endif

