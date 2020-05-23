
// 第十周实验四View.h : C第十周实验四View 类的接口
//

#pragma once


class C第十周实验四View : public CView
{
protected: // 仅从序列化创建
	C第十周实验四View();
	DECLARE_DYNCREATE(C第十周实验四View)

// 特性
public:
	C第十周实验四Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C第十周实验四View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 第十周实验四View.cpp 中的调试版本
inline C第十周实验四Doc* C第十周实验四View::GetDocument() const
   { return reinterpret_cast<C第十周实验四Doc*>(m_pDocument); }
#endif

