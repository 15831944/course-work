// MyDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExp12.4.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 �Ի���

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, t1(_T(""))
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEARCH, t1);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
END_MESSAGE_MAP()


// MyDlg1 ��Ϣ��������