
// ������ʵ����View.h : C������ʵ����View ��Ľӿ�
//

#pragma once


class C������ʵ����View : public CView
{
protected: // �������л�����
	C������ʵ����View();
	DECLARE_DYNCREATE(C������ʵ����View)

// ����
public:
	C������ʵ����Doc* GetDocument() const;

// ����
public:
	CRect cr=CRect(300,300,320,320);
	int f = 0;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C������ʵ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ������ʵ����View.cpp �еĵ��԰汾
inline C������ʵ����Doc* C������ʵ����View::GetDocument() const
   { return reinterpret_cast<C������ʵ����Doc*>(m_pDocument); }
#endif

