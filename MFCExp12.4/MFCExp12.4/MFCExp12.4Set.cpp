
// MFCExp12.4Set.cpp : CMFCExp124Set 类的实现
//

#include "stdafx.h"
#include "MFCExp12.4.h"
#include "MFCExp12.4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp124Set 实现

// 代码生成在 2020年5月25日, 15:34

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Double(pFX, _T("[ID]"), m_ID);
	RFX_Double(pFX, _T("[学号]"), column1);
	RFX_Text(pFX, _T("[姓名]"), column2);
	RFX_Double(pFX, _T("[年龄]"), column3);
	RFX_Text(pFX, _T("[照片路径]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCExp124Set 诊断

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

