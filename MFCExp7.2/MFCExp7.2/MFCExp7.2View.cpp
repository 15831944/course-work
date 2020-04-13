
// MFCExp7.2View.cpp : CMFCExp72View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp7.2.h"
#endif

#include "MFCExp7.2Doc.h"
#include "MFCExp7.2View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CPoint spoint, epoint;
bool move = false;
// CMFCExp72View

IMPLEMENT_DYNCREATE(CMFCExp72View, CView)

BEGIN_MESSAGE_MAP(CMFCExp72View, CView)
	ON_COMMAND(ID_POPOUT, &CMFCExp72View::OnPopout)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExp72View 构造/析构

CMFCExp72View::CMFCExp72View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp72View::~CMFCExp72View()
{
}

BOOL CMFCExp72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp72View 绘制

void CMFCExp72View::OnDraw(CDC* pDC)
{
	CMFCExp72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s1 = _T("加法计算器在视图菜单下");
	CString s2 = _T("下方矩形可被拖动");
	pDC->TextOutW(20, 20, s1);
	pDC->TextOutW(50, 50, s2);
	pDC->Rectangle(pDoc->rt);
	//Invalidate(false);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp72View 诊断

#ifdef _DEBUG
void CMFCExp72View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp72Doc* CMFCExp72View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp72Doc)));
	return (CMFCExp72Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp72View 消息处理程序


void CMFCExp72View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}


void CMFCExp72View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp72Doc* pDoc = GetDocument();
	if (point.x > pDoc->rt.left && point.x<pDoc->rt.right && point.y>pDoc->rt.top && point.y < pDoc->rt.bottom)
	{
		spoint = point;
		move = true;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp72View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp72Doc* pDoc = GetDocument();
	if (point.x > pDoc->rt.left && point.x<pDoc->rt.right && point.y>pDoc->rt.top && point.y < pDoc->rt.bottom)
	{
		//epoint = point;
		move = false;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCExp72View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp72Doc* pDoc = GetDocument();
	epoint = point;
	int xmove = epoint.x - spoint.x;
	int ymove = epoint.y - spoint.y;
	if (move == true)
	{
		pDoc->rt.left += xmove;
		pDoc->rt.top += ymove;
		pDoc->rt.right += xmove;
		pDoc->rt.bottom += ymove;
		spoint = epoint;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
