// DlgAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExp12.3.h"
#include "DlgAdd.h"
#include "afxdialogex.h"


// DlgAdd �Ի���

IMPLEMENT_DYNAMIC(DlgAdd, CDialogEx)

DlgAdd::DlgAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
{

}

DlgAdd::~DlgAdd()
{
}

void DlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
}


BEGIN_MESSAGE_MAP(DlgAdd, CDialogEx)
END_MESSAGE_MAP()


// DlgAdd ��Ϣ�������
