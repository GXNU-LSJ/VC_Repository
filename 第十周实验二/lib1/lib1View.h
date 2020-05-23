
// lib1View.h : Clib1View 类的接口
//

#pragma once


class Clib1View : public CView
{
protected: // 仅从序列化创建
	Clib1View();
	DECLARE_DYNCREATE(Clib1View)

// 特性
public:
	Clib1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Clib1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // lib1View.cpp 中的调试版本
inline Clib1Doc* Clib1View::GetDocument() const
   { return reinterpret_cast<Clib1Doc*>(m_pDocument); }
#endif

