
// 第十三周实验三Doc.h : C第十三周实验三Doc 类的接口
//


#pragma once
#include "第十三周实验三Set.h"


class C第十三周实验三Doc : public CDocument
{
protected: // 仅从序列化创建
	C第十三周实验三Doc();
	DECLARE_DYNCREATE(C第十三周实验三Doc)

// 特性
public:
	C第十三周实验三Set m_第十三周实验三Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C第十三周实验三Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
