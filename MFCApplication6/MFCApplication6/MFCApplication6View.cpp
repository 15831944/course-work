
// MFCApplication6View.cpp : CMFCApplication6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication6View ����/����

CMFCApplication6View::CMFCApplication6View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View ����

void CMFCApplication6View::OnDraw(CDC* pDC)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication6View ���

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View ��Ϣ�������


void CMFCApplication6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication6Doc*pDoc = GetDocument();
	
	CClientDC dc(this);
	if (point.x >= 100 && point.x <= 300 && point.y >= 200 && point.y <= 300)
	{
		pDoc->a = rand() % 50 + 5;
		CString s;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x,point.y,s);
	}
	else if (point.x >= 400 && point.x <= 600 && point.y >= 300 && point.y <= 400)
	{
		pDoc->b = rand() % 50 + 5;
		CString s;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		CString s;
		s.Format(_T("�����Ч"));
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication6View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication6Doc*pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x >= 700 && point.x <= 900 && point.y >= 400 && point.y <= 500)
	{
		CString s;
		s.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
