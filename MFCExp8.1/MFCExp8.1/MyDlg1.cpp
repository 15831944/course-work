// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExp8.1.h"
#include "MyDlg1.h"
#include "afxdialogex.h"
#include "MFCExp8.1Doc.h"
#include "MainFrm.h"
#include "MFCExp8.1View.h"

// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, e1(_T(""))
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, e1);
	DDX_Control(pDX, IDC_LIST1, lbox);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序


BOOL MyDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CMFCExp81View* pView = (CMFCExp81View*)pFrame->GetActiveView();
	lbox.AddString(pView->s);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
