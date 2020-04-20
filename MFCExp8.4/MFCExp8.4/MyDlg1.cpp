// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExp8.4.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, r(0)
	, g(0)
	, b(0)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r);
	DDX_Text(pDX, IDC_EDIT2, g);
	DDX_Text(pDX, IDC_EDIT3, b);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序
