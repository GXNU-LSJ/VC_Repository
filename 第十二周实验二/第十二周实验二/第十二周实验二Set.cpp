
// ��ʮ����ʵ���Set.cpp : C��ʮ����ʵ���Set ���ʵ��
//

#include "stdafx.h"
#include "��ʮ����ʵ���.h"
#include "��ʮ����ʵ���Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ����ʵ���Set ʵ��

// ���������� 2020��5��18��, 11:24

IMPLEMENT_DYNAMIC(C��ʮ����ʵ���Set, CRecordset)

C��ʮ����ʵ���Set::C��ʮ����ʵ���Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	column6 = L"";
	column7 = L"";
	column8 = L"";
	m_nFields = 9;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ʮ����ʵ���Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\Hasee\\Documents\\Database7.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ʮ����ʵ���Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ����ϵͳ]");
}

void C��ʮ����ʵ���Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[רҵ]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Text(pFX, _T("[��������]"), column5);
	RFX_Text(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ�ļ���]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// C��ʮ����ʵ���Set ���

#ifdef _DEBUG
void C��ʮ����ʵ���Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ʮ����ʵ���Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

