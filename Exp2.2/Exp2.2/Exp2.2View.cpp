
// Exp2.2View.cpp : CExp22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp2.2.h"
#endif

#include "Exp2.2Doc.h"
#include "Exp2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;

// CExp22View

IMPLEMENT_DYNCREATE(CExp22View, CView)

BEGIN_MESSAGE_MAP(CExp22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp22View 构造/析构

CExp22View::CExp22View()
{
	// TODO: 在此处添加构造代码

}

CExp22View::~CExp22View()
{
}

BOOL CExp22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp22View 绘制

void CExp22View::OnDraw(CDC* pDC)
{
	CExp22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	
	this->GetClientRect(&cr);
	CClientDC dc(this);
	CBrush *b = new CBrush(RGB(0, 0, 255));
	dc.SelectObject(b);
    dc.Ellipse(&cr);
}


// CExp22View 诊断

#ifdef _DEBUG
void CExp22View::AssertValid() const
{
	CView::AssertValid();
}

void CExp22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp22Doc* CExp22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp22Doc)));
	return (CExp22Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp22View 消息处理程序


void CExp22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonDown(nFlags, point);
}
