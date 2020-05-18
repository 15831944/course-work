
// MFCExp12.1View.cpp : CMFCExp121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp12.1.h"
#endif

#include "MFCExp12.1Set.h"
#include "MFCExp12.1Doc.h"
#include "MFCExp12.1View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp121View

IMPLEMENT_DYNCREATE(CMFCExp121View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCExp121View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCExp121View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCExp121View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCExp121View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCExp121View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCExp121View::OnEnlarge)
END_MESSAGE_MAP()

// CMFCExp121View ����/����

CMFCExp121View::CMFCExp121View()
	: CRecordView(IDD_MFCEXP121_FORM)
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCExp121View::~CMFCExp121View()
{
}

void CMFCExp121View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CMFCExp121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCExp121View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCExp121Set;
	CRecordView::OnInitialUpdate();

}


// CMFCExp121View ���

#ifdef _DEBUG
void CMFCExp121View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCExp121View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCExp121Doc* CMFCExp121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp121Doc)));
	return (CMFCExp121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp121View ���ݿ�֧��
CRecordset* CMFCExp121View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCExp121View ��Ϣ�������


void CMFCExp121View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(true);
	OnPaint();
}


void CMFCExp121View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MovePrev();
	}
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(true);
	OnPaint();
}


void CMFCExp121View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveNext();
	}
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(true);
	OnPaint();
}


void CMFCExp121View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(true);
	OnPaint();
}

void CMFCExp121View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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

void CMFCExp121View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString path, s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	path = _T("C:\\Users\\hmz3442\\Pictures\\");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	img.Load(filename);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CMFCExp121View::OnEnlarge()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyDlg0 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}
