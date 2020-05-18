
// MFCExp12.1Set.cpp : CMFCExp121Set ���ʵ��
//

#include "stdafx.h"
#include "MFCExp12.1.h"
#include "MFCExp12.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp121Set ʵ��

// ���������� 2020��5��18��, 16:39

IMPLEMENT_DYNAMIC(CMFCExp121Set, CRecordset)

CMFCExp121Set::CMFCExp121Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCExp121Set::GetDefaultConnect()
{
	return _T("DSN=StuMessage;DBQ=F:\\AccessDatabase\\PicMessage.xls;DefaultDir=F:\\AccessDatabase;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMFCExp121Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMFCExp121Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[��Ƭ·��]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCExp121Set ���

#ifdef _DEBUG
void CMFCExp121Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCExp121Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

