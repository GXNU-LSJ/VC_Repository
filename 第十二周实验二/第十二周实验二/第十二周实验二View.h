
// ��ʮ����ʵ���View.h : C��ʮ����ʵ���View ��Ľӿ�
//

#pragma once

class C��ʮ����ʵ���Set;

class C��ʮ����ʵ���View : public CRecordView
{
protected: // �������л�����
	C��ʮ����ʵ���View();
	DECLARE_DYNCREATE(C��ʮ����ʵ���View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C��ʮ����ʵ���Set* m_pSet;

// ����
public:
	C��ʮ����ʵ���Doc* GetDocument() const;

// ����
public:
	CString path;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	void Draw_pic(CString file);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C��ʮ����ʵ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	CString filename;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // ��ʮ����ʵ���View.cpp �еĵ��԰汾
inline C��ʮ����ʵ���Doc* C��ʮ����ʵ���View::GetDocument() const
   { return reinterpret_cast<C��ʮ����ʵ���Doc*>(m_pDocument); }
#endif

