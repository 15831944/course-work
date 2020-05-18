
// MFCExp12.1Set.cpp : CMFCExp121Set 类的实现
//

#include "stdafx.h"
#include "MFCExp12.1.h"
#include "MFCExp12.1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp121Set 实现

// 代码生成在 2020年5月18日, 16:39

IMPLEMENT_DYNAMIC(CMFCExp121Set, CRecordset)

CMFCExp121Set::CMFCExp121Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[照片路径]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCExp121Set 诊断

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

