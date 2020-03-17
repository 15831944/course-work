
// MFCExp4.3View.cpp : CMFCExp43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp4.3.h"
#endif

#include "MFCExp4.3Doc.h"
#include "MFCExp4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp43View

IMPLEMENT_DYNCREATE(CMFCExp43View, CView)

BEGIN_MESSAGE_MAP(CMFCExp43View, CView)
//	ON_WM_CHAR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCExp43View 构造/析构

CMFCExp43View::CMFCExp43View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp43View::~CMFCExp43View()
{
}

BOOL CMFCExp43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp43View 绘制

void CMFCExp43View::OnDraw(CDC* pDC)
{
	CMFCExp43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp43View 诊断

#ifdef _DEBUG
void CMFCExp43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp43Doc* CMFCExp43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp43Doc)));
	return (CMFCExp43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp43View 消息处理程序


//void CMFCExp43View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}


void CMFCExp43View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp43Doc*pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->cr.left > 0)
		{
			pDoc->cr.left -= 10;
			pDoc->cr.right -= 10;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right <= (clientRec.right - clientRec.left))
		{
			pDoc->cr.left += 10;
			pDoc->cr.right += 10;
		}
		break;
	case VK_UP:
		if (pDoc->cr.top > 0)
		{
			pDoc->cr.top -= 10;
			pDoc->cr.bottom -= 10;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom <= (clientRec.bottom - clientRec.top))
		{
			pDoc->cr.top += 10;
			pDoc->cr.bottom += 10;
		}
		break;
	case VK_HOME:
		if (pDoc->cr.left > 0 && pDoc->cr.top>0)
		{
			pDoc->cr.left -= 15;
			pDoc->cr.top -= 10;
		}
		break;
	case VK_END:
		if (pDoc->cr.right <= (clientRec.right - clientRec.left)
			&& pDoc->cr.bottom <= (clientRec.bottom - clientRec.top)&&pDoc->cr.left!=pDoc->cr.right)
		{
			pDoc->cr.left += 15;
			pDoc->cr.top += 10;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
