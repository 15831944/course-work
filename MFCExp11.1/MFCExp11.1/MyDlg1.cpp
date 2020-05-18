// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExp11.1.h"
#include "MyDlg1.h"
#include "afxdialogex.h"
#include "MFCExp11.1View.h"


// CMyDlg1 对话框

IMPLEMENT_DYNAMIC(CMyDlg1, CDialogEx)

CMyDlg1::CMyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlg1::~CMyDlg1()
{
}

void CMyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlg1, CDialogEx)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMyDlg1 消息处理程序

