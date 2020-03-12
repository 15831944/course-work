
// Exp3.1View.cpp : CExp31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp3.1.h"
#endif

#include "Exp3.1Doc.h"
#include "Exp3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp31View

IMPLEMENT_DYNCREATE(CExp31View, CView)

BEGIN_MESSAGE_MAP(CExp31View, CView)
END_MESSAGE_MAP()

// CExp31View 构造/析构

CExp31View::CExp31View()
{
	// TODO: 在此处添加构造代码

}

CExp31View::~CExp31View()
{
}

BOOL CExp31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp31View 绘制

void CExp31View::OnDraw(CDC* /*pDC*/)
{
	CExp31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	CString a;
	a.Format(_T("%d"), pDoc->A);
	dc.TextOutW(200, 300, pDoc->S);
	dc.TextOutW(200, 400, a);
}


// CExp31View 诊断

#ifdef _DEBUG
void CExp31View::AssertValid() const
{
	CView::AssertValid();
}

void CExp31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp31Doc* CExp31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp31Doc)));
	return (CExp31Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp31View 消息处理程序
