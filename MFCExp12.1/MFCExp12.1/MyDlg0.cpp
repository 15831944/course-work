// MyDlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExp12.1.h"
#include "MyDlg0.h"
#include "afxdialogex.h"
#include "MFCExp12.1Doc.h"
#include "MainFrm.h"
#include "MFCExp12.1View.h"

// CMyDlg0 �Ի���

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


// CMyDlg0 ��Ϣ�������


void CMyDlg0::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CMFCExp121View* pView = (CMFCExp121View*)pFrame->GetActiveView();
	CString s = pView->filename;
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
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
