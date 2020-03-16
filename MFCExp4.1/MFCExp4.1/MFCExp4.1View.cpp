
// MFCExp4.1View.cpp : CMFCExp41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp4.1.h"
#endif

#include "MFCExp4.1Doc.h"
#include "MFCExp4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp41View

IMPLEMENT_DYNCREATE(CMFCExp41View, CView)

BEGIN_MESSAGE_MAP(CMFCExp41View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExp41View 构造/析构

CMFCExp41View::CMFCExp41View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp41View::~CMFCExp41View()
{
}

BOOL CMFCExp41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp41View 绘制

void CMFCExp41View::OnDraw(CDC* pDC)
{
	CMFCExp41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->c);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp41View 诊断

#ifdef _DEBUG
void CMFCExp41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp41Doc* CMFCExp41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp41Doc)));
	return (CMFCExp41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp41View 消息处理程序


void CMFCExp41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp41Doc*pDoc = GetDocument();
	
	pDoc->c.left = point.x;
	pDoc->c.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp41Doc*pDoc = GetDocument();
	
	pDoc->c.right= point.x;
	pDoc->c.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCExp41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFCExp41Doc*pDoc = GetDocument();
	pDoc->s.Format(_T("%d,%d"), point.x, point.y);
	dc.TextOutW(20, 20, pDoc->s);
	CView::OnMouseMove(nFlags, point);
}
