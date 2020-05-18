
// MFCExp11.1View.cpp : CMFCExp111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp11.1.h"
#endif

#include "MFCExp11.1Set.h"
#include "MFCExp11.1Doc.h"
#include "MFCExp11.1View.h"
#include "MyDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int flag;
CString sname;
// CMFCExp111View

IMPLEMENT_DYNCREATE(CMFCExp111View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCExp111View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCExp111View::OnShowPicture)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCExp111View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCExp111View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCExp111View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCExp111View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCExp111View::OnAutoDisplay)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCExp111View 构造/析构

CMFCExp111View::CMFCExp111View()
	: CRecordView(IDD_MFCEXP111_FORM)
	, id(_T(""))
	, number(_T(""))
	, name(_T(""))
	, age(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCExp111View::~CMFCExp111View()
{
}

void CMFCExp111View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
}

BOOL CMFCExp111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCExp111View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCExp111Set;
	CRecordView::OnInitialUpdate();

}


// CMFCExp111View 诊断

#ifdef _DEBUG
void CMFCExp111View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCExp111View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCExp111Doc* CMFCExp111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp111Doc)));
	return (CMFCExp111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp111View 数据库支持
CRecordset* CMFCExp111View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCExp111View 消息处理程序

void CMFCExp111View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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


void CMFCExp111View::OnShowPicture()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_PICTURE)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
	m_pSet->GetFieldValue(short(4), s);

	img.Load(s);
	
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CMFCExp111View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp111View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MovePrev();
	}
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp111View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveNext();
	}
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp111View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CMFCExp111View::OnAutoDisplay()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag)
	{
		flag = 0;
	}
	else
		flag = 1;
}


void CMFCExp111View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	if (flag)
	{
		CString s;
		CImage img;
		CDC *pDC = GetDlgItem(IDC_PICTURE)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		m_pSet->GetFieldValue(short(4), s);

		img.Load(s);

		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}
}
