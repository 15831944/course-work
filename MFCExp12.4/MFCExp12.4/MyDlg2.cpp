// MyDlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExp12.4.h"
#include "MyDlg2.h"
#include "afxdialogex.h"


// MyDlg2 �Ի���

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, t2(_T(""))
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ORDER, t2);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)
END_MESSAGE_MAP()


// MyDlg2 ��Ϣ�������
