
// ��ʮ��ʵ����View.h : C��ʮ��ʵ����View ��Ľӿ�
//

#pragma once


class C��ʮ��ʵ����View : public CView
{
protected: // �������л�����
	C��ʮ��ʵ����View();
	DECLARE_DYNCREATE(C��ʮ��ʵ����View)

// ����
public:
	C��ʮ��ʵ����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��ʮ��ʵ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ʮ��ʵ����View.cpp �еĵ��԰汾
inline C��ʮ��ʵ����Doc* C��ʮ��ʵ����View::GetDocument() const
   { return reinterpret_cast<C��ʮ��ʵ����Doc*>(m_pDocument); }
#endif

