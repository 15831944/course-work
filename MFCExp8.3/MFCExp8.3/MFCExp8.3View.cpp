
// MFCExp8.3View.cpp : CMFCExp83View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp8.3.h"
#endif

#include "MFCExp8.3Doc.h"
#include "MFCExp8.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp83View

IMPLEMENT_DYNCREATE(CMFCExp83View, CView)

BEGIN_MESSAGE_MAP(CMFCExp83View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCExp83View 构造/析构

CMFCExp83View::CMFCExp83View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp83View::~CMFCExp83View()
{
}

BOOL CMFCExp83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp83View 绘制

void CMFCExp83View::OnDraw(CDC* pDC)
{
	CMFCExp83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->c.left = s_point.x;
	pDoc->c.top = s_point.y;
	pDoc->c.right = e_point.x;
	pDoc->c.bottom = e_point.y;
	pDC->Ellipse(pDoc->c);
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp83View 诊断

#ifdef _DEBUG
void CMFCExp83View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp83Doc* CMFCExp83View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp83Doc)));
	return (CMFCExp83Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp83View 消息处理程序


void CMFCExp83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	s_point = point;
	e_point = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp83View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
	{
		e_point = point;
		Invalidate();
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMFCExp83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
