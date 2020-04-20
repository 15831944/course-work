
// MFCExp8.4View.cpp : CMFCExp84View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp8.4.h"
#endif

#include "MFCExp8.4Doc.h"
#include "MFCExp8.4View.h"
#include "MyDlg.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp84View

IMPLEMENT_DYNCREATE(CMFCExp84View, CView)

BEGIN_MESSAGE_MAP(CMFCExp84View, CView)
	ON_COMMAND(ID_POPOUT, &CMFCExp84View::OnPopout)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_COLOR, &CMFCExp84View::OnColor)
END_MESSAGE_MAP()

// CMFCExp84View 构造/析构

CMFCExp84View::CMFCExp84View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp84View::~CMFCExp84View()
{
}

BOOL CMFCExp84View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp84View 绘制

void CMFCExp84View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp84Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (flag1 == 1)
	{
		
		CPen p1;
		p1.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
		CClientDC dc(this);
		dc.SelectObject(&p1);
		dc.SelectStockObject(NULL_BRUSH);
		CMFCExp84Doc* pDoc = GetDocument();
		
		for (int i = 0; i < pDoc->cr.GetSize(); i++)
		{
			dc.Ellipse(pDoc->cr[i]);
			if (pt.x > pDoc->cr[i].left&&pt.x<pDoc->cr[i].right&&pt.y>pDoc->cr[i].top&&pt.y < pDoc->cr[i].bottom)
			{
				pDoc->a[i] = 1;
				dc.Rectangle(pDoc->cr[i]);
				for (int j = 0; j < pDoc->cr.GetSize(); j++)
				{
					if (j != i)
					{
						pDoc->a[j] = 0;
					}
				}
			}
		}
		flag1 = 0;
	}
	
}


// CMFCExp84View 诊断

#ifdef _DEBUG
void CMFCExp84View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp84View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp84Doc* CMFCExp84View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp84Doc)));
	return (CMFCExp84Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp84View 消息处理程序


void CMFCExp84View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	CMFCExp84Doc* pDoc = GetDocument();
	if (t == IDOK)
	{
		CRect c;
		c.left = dlg.l;
		c.top = dlg.t;
		c.right = dlg.r;
		c.bottom = dlg.b;
		pDoc->cr.Add(c);
		GetDC()->Ellipse(c);
	}
}


void CMFCExp84View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag1 = 1;
	pt = point;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp84View::OnColor()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg1 color;
	int t = color.DoModal();
	if (t == IDOK)
	{
		CMFCExp84Doc* pDoc = GetDocument();
		for (int i = 0; i < pDoc->cr.GetSize(); i++)
		{
			if (pDoc->a[i] == 1)
			{
				CBrush brush;
				brush.CreateSolidBrush(RGB(color.r, color.g, color.b));
				CClientDC dc(this);
				dc.SelectObject(&brush);
				dc.Ellipse(pDoc->cr[i]);
			}
		}
	}
}
