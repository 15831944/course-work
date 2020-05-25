// MyDlg3.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExp12.4.h"
#include "MFCExp12.4Set.h"
#include "MyDlg3.h"
#include "afxdialogex.h"


// MyDlg3 对话框

IMPLEMENT_DYNAMIC(MyDlg3, CDialogEx)

MyDlg3::MyDlg3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, t3(_T(""))

{

}

MyDlg3::~MyDlg3()
{
}

void MyDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST1, t3);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(MyDlg3, CDialogEx)
END_MESSAGE_MAP()


// MyDlg3 消息处理程序


BOOL MyDlg3::OnInitDialog()
{
	CDialogEx::OnInitDialog();		

	// TODO:  在此添加额外的初始化
	m_pSet->MoveFirst();
	int n = m_pSet->GetODBCFieldCount();
	while (!m_pSet->IsEOF())
	{
		CString str;
		for (int i = 0; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, str);
		}
		m_list.AddString(str);
		m_pSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
