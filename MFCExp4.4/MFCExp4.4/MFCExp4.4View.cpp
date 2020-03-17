
// MFCExp4.4View.cpp : CMFCExp44View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp4.4.h"
#endif

#include "MFCExp4.4Doc.h"
#include "MFCExp4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp44View

IMPLEMENT_DYNCREATE(CMFCExp44View, CView)

BEGIN_MESSAGE_MAP(CMFCExp44View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCExp44View 构造/析构

CMFCExp44View::CMFCExp44View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp44View::~CMFCExp44View()
{
}

BOOL CMFCExp44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp44View 绘制

void CMFCExp44View::OnDraw(CDC* pDC)
{
	CMFCExp44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->n; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		pDoc->cr.Add(rect);
	}
	for (int i = 0; i < pDoc->n; i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	if (pDoc->set)
	{
		for (int i = 0; i < pDoc->n; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
		}
		pDoc->set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp44View 诊断

#ifdef _DEBUG
void CMFCExp44View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp44Doc* CMFCExp44View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp44Doc)));
	return (CMFCExp44Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp44View 消息处理程序


void CMFCExp44View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CMFCExp44Doc*pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	
	if (pDoc->cr[i].bottom >=clientRect.bottom)
	{
		pDoc->b[i] = true;
	}
	if (pDoc->cr[i].top <=clientRect.top)
	{
		pDoc->b[i] = false;
	}
	if (pDoc->b[i])
	{
		pDoc->cr[i].top -= 10;
		pDoc->cr[i].bottom -= 10;
	}
	else
	{
		pDoc->cr[i].top += 10;
		pDoc->cr[i].bottom += 10;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
