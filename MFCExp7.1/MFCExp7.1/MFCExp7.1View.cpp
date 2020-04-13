
// MFCExp7.1View.cpp : CMFCExp71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp7.1.h"
#endif

#include "MFCExp7.1Doc.h"
#include "MFCExp7.1View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp71View

IMPLEMENT_DYNCREATE(CMFCExp71View, CView)

BEGIN_MESSAGE_MAP(CMFCExp71View, CView)
	ON_COMMAND(ID_POPOUT, &CMFCExp71View::OnPopout)
END_MESSAGE_MAP()

// CMFCExp71View 构造/析构

CMFCExp71View::CMFCExp71View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp71View::~CMFCExp71View()
{
}

BOOL CMFCExp71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp71View 绘制

void CMFCExp71View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp71View 诊断

#ifdef _DEBUG
void CMFCExp71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp71Doc* CMFCExp71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp71Doc)));
	return (CMFCExp71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp71View 消息处理程序


void CMFCExp71View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	CClientDC dc(this);
	CString s = _T("你已退出对话框");
	if (t = IDOK)
	{
		dc.TextOutW(100, 100, s);
	}
}
