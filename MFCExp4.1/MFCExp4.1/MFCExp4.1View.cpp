
// MFCExp4.1View.cpp : CMFCExp41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp4.1.h"
#endif

#include "MFCExp4.1Doc.h"
#include "MFCExp4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp41View

IMPLEMENT_DYNCREATE(CMFCExp41View, CView)

BEGIN_MESSAGE_MAP(CMFCExp41View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExp41View ����/����

CMFCExp41View::CMFCExp41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp41View::~CMFCExp41View()
{
}

BOOL CMFCExp41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp41View ����

void CMFCExp41View::OnDraw(CDC* pDC)
{
	CMFCExp41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->c);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp41View ���

#ifdef _DEBUG
void CMFCExp41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp41Doc* CMFCExp41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp41Doc)));
	return (CMFCExp41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp41View ��Ϣ�������


void CMFCExp41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp41Doc*pDoc = GetDocument();
	
	pDoc->c.left = point.x;
	pDoc->c.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp41Doc*pDoc = GetDocument();
	
	pDoc->c.right= point.x;
	pDoc->c.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCExp41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CMFCExp41Doc*pDoc = GetDocument();
	pDoc->s.Format(_T("%d,%d"), point.x, point.y);
	dc.TextOutW(20, 20, pDoc->s);
	CView::OnMouseMove(nFlags, point);
}
