
// MFCExp5.1View.cpp : CMFCExp51View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp5.1.h"
#endif

#include "MFCExp5.1Doc.h"
#include "MFCExp5.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp51View

IMPLEMENT_DYNCREATE(CMFCExp51View, CView)

BEGIN_MESSAGE_MAP(CMFCExp51View, CView)
	ON_COMMAND(ID_ShowCircle, &CMFCExp51View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCExp51View 构造/析构

CMFCExp51View::CMFCExp51View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp51View::~CMFCExp51View()
{
}

BOOL CMFCExp51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp51View 绘制

void CMFCExp51View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	CString s = _T("请点击菜单栏中的‘实验’，再选择‘渐变圆’开始");
	CClientDC dc(this);
	dc.TextOutW(0, 100, s);
}


// CMFCExp51View 诊断

#ifdef _DEBUG
void CMFCExp51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp51Doc* CMFCExp51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp51Doc)));
	return (CMFCExp51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp51View 消息处理程序


void CMFCExp51View::OnShowcircle()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp51Doc*pDoc = GetDocument();
	CClientDC dc(this);
	SetTimer(0, 250, NULL);
	CRect rect;
	GetClientRect(&rect);
	int a = rect.Width()/2;
	int b = rect.Height()/2;
	CRect c(a - pDoc->r, b - pDoc->r, a + pDoc->r, b + pDoc->r);
	pDoc->cr.Add(c);
	CPen pen(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen *p;
	p = dc.SelectObject(&pen);
	dc.Ellipse(&c);
}


void CMFCExp51View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CClientDC dc(this);
	CMFCExp51Doc*pDoc = GetDocument();
	pDoc->r += 10;
	CRect rect;
	GetClientRect(&rect);
	int a = rect.Width() / 2;
	int b = rect.Height() / 2;
	CPen pen(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen *p;
	p = dc.SelectObject(&pen);
	if (pDoc->r > b)
	{
		pDoc->r = 40;
		Invalidate();
	}
	CRect c(a - pDoc->r, b - pDoc->r, a + pDoc->r, b + pDoc->r);
	dc.Ellipse(&c);
	CView::OnTimer(nIDEvent);
}
