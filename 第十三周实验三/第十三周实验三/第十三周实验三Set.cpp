
// ��ʮ����ʵ����Set.cpp : C��ʮ����ʵ����Set ���ʵ��
//

#include "stdafx.h"
#include "��ʮ����ʵ����.h"
#include "��ʮ����ʵ����Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮ����ʵ����Set ʵ��

// ���������� 2020��5��19��, 21:09

IMPLEMENT_DYNAMIC(C��ʮ����ʵ����Set, CRecordset)

C��ʮ����ʵ����Set::C��ʮ����ʵ����Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ʮ����ʵ����Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x6570\x636e\x5e93\x4fee\x6539;DBQ=C:\\USERS\\HASEE\\DOCUMENTS\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ʮ����ʵ����Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void C��ʮ����ʵ����Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// C��ʮ����ʵ����Set ���

#ifdef _DEBUG
void C��ʮ����ʵ����Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ʮ����ʵ����Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

