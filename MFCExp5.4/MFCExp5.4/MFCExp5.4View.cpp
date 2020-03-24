
// MFCExp5.4View.cpp : CMFCExp54View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp5.4.h"
#endif

#include "MFCExp5.4Doc.h"
#include "MFCExp5.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp54View

IMPLEMENT_DYNCREATE(CMFCExp54View, CView)

BEGIN_MESSAGE_MAP(CMFCExp54View, CView)
	ON_COMMAND(ID_Line, &CMFCExp54View::OnLine)
	ON_COMMAND(ID_Rectangle, &CMFCExp54View::OnRectangle)
	ON_COMMAND(ID_Circle, &CMFCExp54View::OnCircle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCExp54View 构造/析构

CMFCExp54View::CMFCExp54View()
{
	// TODO: 在此处添加构造代码
	line = false;
	rectangle = false;
	circle = false;
}

CMFCExp54View::~CMFCExp54View()
{
}

BOOL CMFCExp54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp54View 绘制

void CMFCExp54View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp54Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp54View 诊断

#ifdef _DEBUG
void CMFCExp54View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp54View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp54Doc* CMFCExp54View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp54Doc)));
	return (CMFCExp54Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp54View 消息处理程序


void CMFCExp54View::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	line = true;
	rectangle = false;
	circle = false;
}


void CMFCExp54View::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	line = false;
	rectangle = true;
	circle = false;
}


void CMFCExp54View::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	line = false;
	rectangle = false;
	circle = true;
}


void CMFCExp54View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp54View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p2 = point;
	//HDC hdc;
	CClientDC dc(this);
	if (line)
	{
		dc.MoveTo(p1);
		dc.LineTo(p2);
	}
	if (rectangle)
	{
		dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
	}
	if (circle)
	{
		dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
	}
	CView::OnLButtonUp(nFlags, point);
}
