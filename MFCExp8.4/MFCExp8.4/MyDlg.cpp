// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExp8.4.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, l(0)
	, t(0)
	, r(0)
	, b(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, l);
	DDX_Text(pDX, IDC_EDIT2, t);
	DDX_Text(pDX, IDC_EDIT3, r);
	DDX_Text(pDX, IDC_EDIT4, b);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg 消息处理程序
