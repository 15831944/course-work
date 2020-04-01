
// MFCExp6.2View.cpp : CMFCExp62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp6.2.h"
#endif

#include "MFCExp6.2Doc.h"
#include "MFCExp6.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CPoint ptCharacter;
CString str;
CPoint ptOrigin;
bool flag;
// CMFCExp62View

IMPLEMENT_DYNCREATE(CMFCExp62View, CView)

BEGIN_MESSAGE_MAP(CMFCExp62View, CView)
//	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCExp62View 构造/析构

CMFCExp62View::CMFCExp62View()
{
	// TODO: 在此处添加构造代码
	ptCharacter.x = 310;
	ptCharacter.y = 110;
	flag = false;
}

CMFCExp62View::~CMFCExp62View()
{
}

BOOL CMFCExp62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp62View 绘制

void CMFCExp62View::OnDraw(CDC* pDC)
{
	CMFCExp62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(300, 100, 1200, 400);
}


// CMFCExp62View 诊断

#ifdef _DEBUG
void CMFCExp62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp62Doc* CMFCExp62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp62Doc)));
	return (CMFCExp62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp62View 消息处理程序


//void CMFCExp62View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	
//	CView::OnKeyDown(nChar, nRepCnt, nFlags);
//}


void CMFCExp62View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (nChar == 13)
	{
		ptCharacter.x = 310;
		ptCharacter.y = ptCharacter.y + 25;
	}
	else if (ptCharacter.x >= 1190&& ptCharacter.y <= 360)
	{
		ptCharacter.x = 310;
		ptCharacter.y = ptCharacter.y + 25;
	}
	else if (ptCharacter.y >= 360)
	{
		CString s = _T("已超出文本框范围");
		dc.TextOutW(50, 50, s);
	}
	else if (flag)
	{
		ptCharacter.x = ptOrigin.x;
		ptCharacter.y = ptOrigin.y;
		flag = false;
	}
	else
	{
		CClientDC dc(this);
		dc.TextOut(ptCharacter.x, ptCharacter.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		ptCharacter.x = ptCharacter.x + textsize.cx;
	}
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCExp62View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	str.Empty();
	ptOrigin = point;
	flag = true;
	CView::OnLButtonDown(nFlags, point);
}
