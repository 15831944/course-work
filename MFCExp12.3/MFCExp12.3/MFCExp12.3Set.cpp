
// MFCExp12.3Set.cpp : CMFCExp123Set ���ʵ��
//

#include "stdafx.h"
#include "MFCExp12.3.h"
#include "MFCExp12.3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp123Set ʵ��

// ���������� 2020��5��19��, 14:42

IMPLEMENT_DYNAMIC(CMFCExp123Set, CRecordset)

CMFCExp123Set::CMFCExp123Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCExp123Set::GetDefaultConnect()
{
	return _T("DSN=StuMessage;DBQ=F:\\AccessDatabase\\IDMessage.xls;DefaultDir=F:\\AccessDatabase;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMFCExp123Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMFCExp123Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Double(pFX, _T("[ID]"), m_ID);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCExp123Set ���

#ifdef _DEBUG
void CMFCExp123Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCExp123Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

