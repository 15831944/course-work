// MyDlg3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExp12.4.h"
#include "MFCExp12.4Set.h"
#include "MyDlg3.h"
#include "afxdialogex.h"


// MyDlg3 �Ի���

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


// MyDlg3 ��Ϣ�������


BOOL MyDlg3::OnInitDialog()
{
	CDialogEx::OnInitDialog();		

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_list.ResetContent();
	m_pListSet->MoveFirst();
	int n = m_pListSet->GetODBCFieldCount();
	CString s;
	while (!m_pListSet->IsEOF())
	{
		s.Empty();
		CString str;
		for (int i = 0; i < n; i++)
		{
			m_pListSet->GetFieldValue((short)i, str);
			s += str;
			s += "     ";
		}
		m_list.AddString(s);
		m_pListSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
