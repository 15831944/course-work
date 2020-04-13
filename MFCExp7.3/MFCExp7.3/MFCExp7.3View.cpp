
// MFCExp7.3View.cpp : CMFCExp73View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp7.3.h"
#endif

#include "MFCExp7.3Doc.h"
#include "MFCExp7.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;
int flag1,flag2,flag3;
// CMFCExp73View

IMPLEMENT_DYNCREATE(CMFCExp73View, CView)

BEGIN_MESSAGE_MAP(CMFCExp73View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCExp73View 构造/析构

CMFCExp73View::CMFCExp73View()
{
	// TODO: 在此处添加构造代码
	flag1 = 0;
	flag2 = 0;
	flag3 = 1;
}

CMFCExp73View::~CMFCExp73View()
{
}

BOOL CMFCExp73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp73View 绘制

void CMFCExp73View::OnDraw(CDC* pDC)
{
	CMFCExp73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect clientRect;
	GetClientRect(&clientRect);
	if (cr.top != clientRect.Height() / 2 - 20)
	{
		cr.top = clientRect.Height() / 2 - 20;
		cr.bottom = clientRect.Height() / 2 + 20;
	}
	if (flag3)
	{
		cr.left = 0;
		cr.top = clientRect.Height() / 2 - 20;
		cr.right = 40;
		cr.bottom = clientRect.Height() / 2 + 20;
		flag3 = 0;
	}
	SetTimer(0, 100, NULL);
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp73View 诊断

#ifdef _DEBUG
void CMFCExp73View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp73Doc* CMFCExp73View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp73Doc)));
	return (CMFCExp73Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp73View 消息处理程序


void CMFCExp73View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag2 = 0;
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCExp73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag2 = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp73View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect clientRect;
	GetClientRect(&clientRect);
	if (flag2)
	{
		if (flag1 == 0)
		{
			cr.left += 30;
			cr.right += 30;
			Invalidate();
			if (cr.right >= clientRect.right)
				flag1 = 1;
		}
		if (flag1 == 1)
		{
			cr.left -= 30;
			cr.right -= 30;
			Invalidate();
			if (cr.left <= clientRect.left)
				flag1 = 0;
		}
	}
	CView::OnTimer(nIDEvent);
}
