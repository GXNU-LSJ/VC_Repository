
// 第四周实验3View.h : C第四周实验3View 类的接口
//

#pragma once


class C第四周实验3View : public CView
{
protected: // 仅从序列化创建
	C第四周实验3View();
	DECLARE_DYNCREATE(C第四周实验3View)

// 特性
public:
	C第四周实验3Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray<CRect, CRect> cr;
	int f[5] = {1,1,1,1,1};
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第四周实验3View();
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
};

#ifndef _DEBUG  // 第四周实验3View.cpp 中的调试版本
inline C第四周实验3Doc* C第四周实验3View::GetDocument() const
   { return reinterpret_cast<C第四周实验3Doc*>(m_pDocument); }
#endif

