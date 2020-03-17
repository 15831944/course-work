
// MFCExp4.2View.cpp : CMFCExp42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp4.2.h"
#endif

#include "MFCExp4.2Doc.h"
#include "MFCExp4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp42View

IMPLEMENT_DYNCREATE(CMFCExp42View, CView)

BEGIN_MESSAGE_MAP(CMFCExp42View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExp42View 构造/析构

CMFCExp42View::CMFCExp42View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp42View::~CMFCExp42View()
{
}

BOOL CMFCExp42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp42View 绘制

void CMFCExp42View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp42View 诊断

#ifdef _DEBUG
void CMFCExp42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp42Doc* CMFCExp42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp42Doc)));
	return (CMFCExp42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp42View 消息处理程序


void CMFCExp42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp42Doc*pDoc = GetDocument();
	pDoc->count = 0;
	pDoc->m = point.x;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp42View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp42Doc*pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->n = point.x;
	int d = pDoc->n - pDoc->m;
	CString ns;
	if (d == 0)
	{
		
		ns.Format(_T("鼠标没有移动，无法计算"));
		dc.TextOutW(20, 50, ns);
		pDoc->s.Format(_T("移动次数：，每次横向移动像素："));
		dc.TextOutW(20, 20, pDoc->s);
	}
	else
	{
		ns.Format(_T("鼠标存在移动，可以计算"));
		dc.TextOutW(20, 50, ns);
		pDoc->s.Format(_T("移动次数：%d，每次横向移动像素：%d"), pDoc->count, d / pDoc->count);
		dc.TextOutW(20, 20, pDoc->s);
	}
	
	CView::OnLButtonUp(nFlags, point);
}


void CMFCExp42View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp42Doc*pDoc = GetDocument();
	pDoc->count+=1;
	CView::OnMouseMove(nFlags, point);
}
