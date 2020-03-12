
// Exp1.2View.cpp : CExp12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp1.2.h"
#endif

#include "Exp1.2Doc.h"
#include "Exp1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp12View

IMPLEMENT_DYNCREATE(CExp12View, CView)

BEGIN_MESSAGE_MAP(CExp12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExp12View 构造/析构

CExp12View::CExp12View()
{
	// TODO: 在此处添加构造代码

}

CExp12View::~CExp12View()
{
}

BOOL CExp12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp12View 绘制

void CExp12View::OnDraw(CDC* /*pDC*/)
{
	CExp12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExp12View 诊断

#ifdef _DEBUG
void CExp12View::AssertValid() const
{
	CView::AssertValid();
}

void CExp12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp12Doc* CExp12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp12Doc)));
	return (CExp12Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp12View 消息处理程序


void CExp12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp12Doc*pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CExp12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp12Doc*pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->s.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200, 300, pDoc->s);
	CView::OnRButtonDown(nFlags, point);
}
