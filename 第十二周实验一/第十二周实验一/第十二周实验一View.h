
// ��ʮ����ʵ��һView.h : C��ʮ����ʵ��һView ��Ľӿ�
//

#pragma once

class C��ʮ����ʵ��һSet;

class C��ʮ����ʵ��һView : public CRecordView
{
protected: // �������л�����
	C��ʮ����ʵ��һView();
	DECLARE_DYNCREATE(C��ʮ����ʵ��һView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C��ʮ����ʵ��һSet* m_pSet;

// ����
public:
	C��ʮ����ʵ��һDoc* GetDocument() const;

// ����
public:
	CString path;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C��ʮ����ʵ��һView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birthday;
	CString phone;
	CString address;
	afx_msg void OnBnClickedButton1();
	void OnDraw(CDC * pDC);
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	CString filename;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};

#ifndef _DEBUG  // ��ʮ����ʵ��һView.cpp �еĵ��԰汾
inline C��ʮ����ʵ��һDoc* C��ʮ����ʵ��һView::GetDocument() const
   { return reinterpret_cast<C��ʮ����ʵ��һDoc*>(m_pDocument); }
#endif

