
// MFCExp12.3Set.cpp : CMFCExp123Set 类的实现
//

#include "stdafx.h"
#include "MFCExp12.3.h"
#include "MFCExp12.3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp123Set 实现

// 代码生成在 2020年5月19日, 14:42

IMPLEMENT_DYNAMIC(CMFCExp123Set, CRecordset)

CMFCExp123Set::CMFCExp123Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Double(pFX, _T("[ID]"), m_ID);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCExp123Set 诊断

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

