
// ������ʵ��2View.h : C������ʵ��2View ��Ľӿ�
//

#pragma once


class C������ʵ��2View : public CView
{
protected: // �������л�����
	C������ʵ��2View();
	DECLARE_DYNCREATE(C������ʵ��2View)

// ����
public:
	C������ʵ��2Doc* GetDocument() const;

// ����
public:
	CRect cr;
	int r;
	bool f;

//��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C������ʵ��2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ������ʵ��2View.cpp �еĵ��԰汾
inline C������ʵ��2Doc* C������ʵ��2View::GetDocument() const
   { return reinterpret_cast<C������ʵ��2Doc*>(m_pDocument); }
#endif

