
// MFCExp8.1View.cpp : CMFCExp81View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp8.1.h"
#endif

#include "MFCExp8.1Doc.h"
#include "MFCExp8.1View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMFCExp81View

IMPLEMENT_DYNCREATE(CMFCExp81View, CView)

BEGIN_MESSAGE_MAP(CMFCExp81View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_POPOUT, &CMFCExp81View::OnPopout)
END_MESSAGE_MAP()

// CMFCExp81View 构造/析构

CMFCExp81View::CMFCExp81View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp81View::~CMFCExp81View()
{
}

BOOL CMFCExp81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp81View 绘制

void CMFCExp81View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1)
	{
		MyDlg1 *dlg = new MyDlg1;
		dlg->e1 = s;
		dlg->Create(IDD_DIALOG1);
		dlg->ShowWindow(1);
		flag = 0;
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp81View 诊断

#ifdef _DEBUG
void CMFCExp81View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp81Doc* CMFCExp81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp81Doc)));
	return (CMFCExp81Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp81View 消息处理程序


void CMFCExp81View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK)
	{
		s = cfd.GetFileName();
	}
	GetDC()->TextOutW(300, 300, s);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCExp81View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
	Invalidate();
}
