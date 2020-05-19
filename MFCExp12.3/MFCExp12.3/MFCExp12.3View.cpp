
// MFCExp12.3View.cpp : CMFCExp123View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCExp123View 构造/析构

CMFCExp123View::CMFCExp123View()
	: CRecordView(IDD_MFCEXP123_FORM)
	, id()
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCExp123View::~CMFCExp123View()
{
}

void CMFCExp123View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_CHANGE, m_pSet->m_ID);
}

BOOL CMFCExp123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCExp123View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCExp123Set;
	CRecordView::OnInitialUpdate();

}


// CMFCExp123View 诊断

#ifdef _DEBUG
void CMFCExp123View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCExp123View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCExp123Doc* CMFCExp123View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp123Doc)));
	return (CMFCExp123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp123View 数据库支持
CRecordset* CMFCExp123View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCExp123View 消息处理程序


void CMFCExp123View::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
