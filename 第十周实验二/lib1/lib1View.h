
// lib1View.h : Clib1View ��Ľӿ�
//

#pragma once


class Clib1View : public CView
{
protected: // �������л�����
	Clib1View();
	DECLARE_DYNCREATE(Clib1View)

// ����
public:
	Clib1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Clib1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // lib1View.cpp �еĵ��԰汾
inline Clib1Doc* Clib1View::GetDocument() const
   { return reinterpret_cast<Clib1Doc*>(m_pDocument); }
#endif

