// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExp12.1.h"
#include "MyDlg0.h"
#include "afxdialogex.h"
#include "MFCExp12.1Doc.h"
#include "MainFrm.h"
#include "MFCExp12.1View.h"

// CMyDlg0 对话框

IMPLEMENT_DYNAMIC(CMyDlg0, CDialogEx)

CMyDlg0::CMyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlg0::~CMyDlg0()
{
}

void CMyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlg0, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMyDlg0 消息处理程序


void CMyDlg0::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CMFCExp121View* pView = (CMFCExp121View*)pFrame->GetActiveView();
	CString s = pView->filename;
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
	CImage img;
	img.Load(s);
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}
