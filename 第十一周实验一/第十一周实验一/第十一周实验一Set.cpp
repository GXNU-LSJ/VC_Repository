
// ��ʮһ��ʵ��һSet.cpp : C��ʮһ��ʵ��һSet ���ʵ��
//

#include "stdafx.h"
#include "��ʮһ��ʵ��һ.h"
#include "��ʮһ��ʵ��һSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ��ʵ��һSet ʵ��

// ���������� 2020��5��9��, 23:34

IMPLEMENT_DYNAMIC(C��ʮһ��ʵ��һSet, CRecordset)

C��ʮһ��ʵ��һSet::C��ʮһ��ʵ��һSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ʮһ��ʵ��һSet::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f\x8868;DBQ=C:\\Users\\Hasee\\Documents\\Database6.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ʮһ��ʵ��һSet::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void C��ʮһ��ʵ��һSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[����]"), column3);
	RFX_Text(pFX, _T("[�绰����]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// C��ʮһ��ʵ��һSet ���

#ifdef _DEBUG
void C��ʮһ��ʵ��һSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ʮһ��ʵ��һSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

