
// MFCExp12.4View.cpp : CMFCExp124View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp12.4.h"
#endif

#include "MFCExp12.4Set.h"
#include "MFCExp12.4Doc.h"
#include "MFCExp12.4View.h"
#include "MyDlg0.h"
#include "MyDlg1.h"
#include "MyDlg2.h"
#include "MyDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCExp124View

IMPLEMENT_DYNCREATE(CMFCExp124View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCExp124View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMFCExp124View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCExp124View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCExp124View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCExp124View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCExp124View::OnEnlarge)
	ON_COMMAND(ID_SEARCH, &CMFCExp124View::OnSearch)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCExp124View::OnRecovery)
	ON_COMMAND(ID_ORDER, &CMFCExp124View::OnOrder)
	ON_COMMAND(ID_RECORDSET, &CMFCExp124View::OnRecordset)
END_MESSAGE_MAP()

// CMFCExp124View ����/����

CMFCExp124View::CMFCExp124View()
	: CRecordView(IDD_MFCEXP124_FORM)
	, m_id(0)
	, m_number(0)
	, m_name(_T(""))
	, m_age(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
}

CMFCExp124View::~CMFCExp124View()
{
}

void CMFCExp124View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
}

BOOL CMFCExp124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCExp124View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCExp124Set;
	CRecordView::OnInitialUpdate();
}


// CMFCExp124View ���

#ifdef _DEBUG
void CMFCExp124View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCExp124View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCExp124Doc* CMFCExp124View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp124Doc)));
	return (CMFCExp124Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp124View ���ݿ�֧��
CRecordset* CMFCExp124View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCExp124View ��Ϣ�������

void CMFCExp124View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);
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
}

void CMFCExp124View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_PICTURE)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	m_pSet->GetFieldValue(short(4), s);
	filename = s;
	img.Load(s);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CMFCExp124View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp124View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MovePrev();
	}
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp124View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveNext();
	}
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp124View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp124View::OnEnlarge()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg0 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CMFCExp124View::OnSearch()
{
	// TODO: �ڴ���������������
	MyDlg1 dlg;
	int r = dlg.DoModal();
	CString s;
	if (r == IDOK)
	{
		
		s=dlg.t1;
		
	}
	m_pSet->m_strFilter = s;
	m_pSet->Requery();
	UpdateData(false);
}


void CMFCExp124View::OnRecovery()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}


void CMFCExp124View::OnOrder()
{
	// TODO: �ڴ���������������
	MyDlg2 dlg;
	int r = dlg.DoModal();
	CString s;
	if (r == IDOK)
	{
		s = dlg.t2;
	}
	m_pSet->m_strSort = s;
	m_pSet->Requery();
	UpdateData(false);
}


void CMFCExp124View::OnRecordset()
{
	// TODO: �ڴ���������������
	MyDlg3 dlg;
	dlg.m_pListSet = m_pSet;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}
