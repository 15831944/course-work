
// MFCExp12.3View.cpp : CMFCExp123View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp12.3.h"
#endif

#include "MFCExp12.3Set.h"
#include "MFCExp12.3Doc.h"
#include "MFCExp12.3View.h"
#include "DlgAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp123View

IMPLEMENT_DYNCREATE(CMFCExp123View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCExp123View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCExp123View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCExp123View::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCExp123View::OnBnClickedEdit)
END_MESSAGE_MAP()

// CMFCExp123View ����/����

CMFCExp123View::CMFCExp123View()
	: CRecordView(IDD_MFCEXP123_FORM)
	, id()
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCExp123View::~CMFCExp123View()
{
}

void CMFCExp123View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_CHANGE, m_pSet->m_ID);
}

BOOL CMFCExp123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCExp123View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCExp123Set;
	CRecordView::OnInitialUpdate();

}


// CMFCExp123View ���

#ifdef _DEBUG
void CMFCExp123View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCExp123View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCExp123Doc* CMFCExp123View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp123Doc)));
	return (CMFCExp123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp123View ���ݿ�֧��
CRecordset* CMFCExp123View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCExp123View ��Ϣ�������


void CMFCExp123View::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}


void CMFCExp123View::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DlgAdd add;
	int r = add.DoModal();
	if (r == IDOK)
	{
		double aa = add.a;
		m_pSet->AddNew();
		m_pSet->m_ID = aa;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCExp123View::OnBnClickedEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DlgAdd edit;
	int r = edit.DoModal();
	if (r == IDOK)
	{
		double aaa = edit.a;
		m_pSet->Edit();
		//m_pSet->m_ID = aaa;
		CString s;
		s.Format(_T("%d"), aaa);
		SetDlgItemText(IDC_CHANGE, s);
		m_pSet->Update();
		UpdateData(false);
	}
}
