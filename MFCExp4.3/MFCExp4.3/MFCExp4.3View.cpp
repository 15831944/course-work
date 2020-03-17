
// MFCExp4.3View.cpp : CMFCExp43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCExp43View ����/����

CMFCExp43View::CMFCExp43View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp43View::~CMFCExp43View()
{
}

BOOL CMFCExp43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp43View ����

void CMFCExp43View::OnDraw(CDC* pDC)
{
	CMFCExp43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp43View ���

#ifdef _DEBUG
void CMFCExp43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp43Doc* CMFCExp43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp43Doc)));
	return (CMFCExp43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp43View ��Ϣ�������


//void CMFCExp43View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}


void CMFCExp43View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
