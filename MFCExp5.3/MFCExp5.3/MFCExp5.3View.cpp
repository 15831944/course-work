
// MFCExp5.3View.cpp : CMFCExp53View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp5.3.h"
#endif

#include "MFCExp5.3Doc.h"
#include "MFCExp5.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp53View

IMPLEMENT_DYNCREATE(CMFCExp53View, CView)

BEGIN_MESSAGE_MAP(CMFCExp53View, CView)
END_MESSAGE_MAP()

// CMFCExp53View 构造/析构

CMFCExp53View::CMFCExp53View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFCExp53View::~CMFCExp53View()
{
}

BOOL CMFCExp53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp53View 绘制

void CMFCExp53View::OnDraw(CDC* pDC)
{
	CMFCExp53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp53View 诊断

#ifdef _DEBUG
void CMFCExp53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp53Doc* CMFCExp53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp53Doc)));
	return (CMFCExp53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp53View 消息处理程序
