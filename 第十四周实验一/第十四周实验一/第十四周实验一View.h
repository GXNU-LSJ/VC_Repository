
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
	CString age;
	CString phone;
	CString photo;
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
};

#ifndef _DEBUG  // ��ʮ����ʵ��һView.cpp �еĵ��԰汾
inline C��ʮ����ʵ��һDoc* C��ʮ����ʵ��һView::GetDocument() const
   { return reinterpret_cast<C��ʮ����ʵ��һDoc*>(m_pDocument); }
#endif

