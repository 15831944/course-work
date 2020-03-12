
// Exp2.1View.cpp : CExp21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp2.1.h"
#endif

#include "Exp2.1Doc.h"
#include "Exp2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;

// CExp21View

IMPLEMENT_DYNCREATE(CExp21View, CView)

BEGIN_MESSAGE_MAP(CExp21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp21View 构造/析构

CExp21View::CExp21View()
{
	// TODO: 在此处添加构造代码

}

CExp21View::~CExp21View()
{
}

BOOL CExp21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp21View 绘制

void CExp21View::OnDraw(CDC* pDC)
{
	CExp21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// CExp21View 诊断

#ifdef _DEBUG
void CExp21View::AssertValid() const
{
	CView::AssertValid();
}

void CExp21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp21Doc* CExp21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp21Doc)));
	return (CExp21Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp21View 消息处理程序


void CExp21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp21Doc*pDoc = GetDocument();
	pDoc->r = rand() % 50 + 5;
	CClientDC dc(this);
	CRect cr(point.x-pDoc->r,point.y-pDoc->r,point.x+pDoc->r,point.y+pDoc->r);
	pDoc->ca.Add(cr);
	this->Invalidate();
	dc.Ellipse(&cr);
	CView::OnLButtonDown(nFlags, point);
}
