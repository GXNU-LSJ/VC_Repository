
// ��ʮ����ʵ����Doc.h : C��ʮ����ʵ����Doc ��Ľӿ�
//


#pragma once
#include "��ʮ����ʵ����Set.h"


class C��ʮ����ʵ����Doc : public CDocument
{
protected: // �������л�����
	C��ʮ����ʵ����Doc();
	DECLARE_DYNCREATE(C��ʮ����ʵ����Doc)

// ����
public:
	C��ʮ����ʵ����Set m_��ʮ����ʵ����Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��ʮ����ʵ����Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
