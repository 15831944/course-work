
// MFCExp12.4Set.cpp : CMFCExp124Set ���ʵ��
//

#include "stdafx.h"
#include "MFCExp12.4.h"
#include "MFCExp12.4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp124Set ʵ��

// ���������� 2020��5��25��, 15:34

IMPLEMENT_DYNAMIC(CMFCExp124Set, CRecordset)

CMFCExp124Set::CMFCExp124Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	column1 = 0.0;
	column2 = L"";
	column3 = 0.0;
	column4 = L"";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCExp124Set::GetDefaultConnect()
{
	return _T("DSN=StuMessage;DBQ=F:\\AccessDatabase\\StuMessage.xls;DefaultDir=F:\\AccessDatabase;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMFCExp124Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMFCExp124Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Double(pFX, _T("[ID]"), m_ID);
	RFX_Double(pFX, _T("[ѧ��]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Text(pFX, _T("[��Ƭ·��]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCExp124Set ���

#ifdef _DEBUG
void CMFCExp124Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCExp124Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

