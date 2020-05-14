
// MFCExp11.1Set.cpp : CMFCExp111Set ���ʵ��
//

#include "stdafx.h"
#include "MFCExp11.1.h"
#include "MFCExp11.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp111Set ʵ��

// ���������� 2020��5��12��, 15:06

IMPLEMENT_DYNAMIC(CMFCExp111Set, CRecordset)

CMFCExp111Set::CMFCExp111Set(CDatabase* pdb)
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
CString CMFCExp111Set::GetDefaultConnect()
{
	return _T("DSN=StuMessage;DBQ=F:\\ACCESSDATABASE\\StuMessage.xls;DefaultDir=F:\\ACCESSDATABASE;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMFCExp111Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMFCExp111Set::DoFieldExchange(CFieldExchange* pFX)
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
// CMFCExp111Set ���

#ifdef _DEBUG
void CMFCExp111Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCExp111Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

