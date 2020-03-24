
// MFCExp5.2View.cpp : CMFCExp52View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp5.2.h"
#endif

#include "MFCExp5.2Doc.h"
#include "MFCExp5.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp52View

IMPLEMENT_DYNCREATE(CMFCExp52View, CView)

BEGIN_MESSAGE_MAP(CMFCExp52View, CView)
	ON_COMMAND(ID_ShowName, &CMFCExp52View::OnShowname)
END_MESSAGE_MAP()

// CMFCExp52View 构造/析构

CMFCExp52View::CMFCExp52View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp52View::~CMFCExp52View()
{
}

BOOL CMFCExp52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp52View 绘制

void CMFCExp52View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp52View 诊断

#ifdef _DEBUG
void CMFCExp52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp52Doc* CMFCExp52View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp52Doc)));
	return (CMFCExp52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp52View 消息处理程序


void CMFCExp52View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s=_T("胡铭卓");
	CClientDC dc(this);
	dc.TextOutW(100, 100, s);
}
