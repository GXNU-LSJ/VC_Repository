
// ��ʮһ��ʵ��һView.h : C��ʮһ��ʵ��һView ��Ľӿ�
//

#pragma once

class C��ʮһ��ʵ��һSet;

class C��ʮһ��ʵ��һView : public CRecordView
{
protected: // �������л�����
	C��ʮһ��ʵ��һView();
	DECLARE_DYNCREATE(C��ʮһ��ʵ��һView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C��ʮһ��ʵ��һSet* m_pSet;

// ����
public:
	C��ʮһ��ʵ��һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C��ʮһ��ʵ��һView();
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
};

#ifndef _DEBUG  // ��ʮһ��ʵ��һView.cpp �еĵ��԰汾
inline C��ʮһ��ʵ��һDoc* C��ʮһ��ʵ��һView::GetDocument() const
   { return reinterpret_cast<C��ʮһ��ʵ��һDoc*>(m_pDocument); }
#endif

