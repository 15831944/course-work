
// MFCExp4.2View.cpp : CMFCExp42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp4.2.h"
#endif

#include "MFCExp4.2Doc.h"
#include "MFCExp4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp42View

IMPLEMENT_DYNCREATE(CMFCExp42View, CView)

BEGIN_MESSAGE_MAP(CMFCExp42View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExp42View ����/����

CMFCExp42View::CMFCExp42View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp42View::~CMFCExp42View()
{
}

BOOL CMFCExp42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp42View ����

void CMFCExp42View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp42View ���

#ifdef _DEBUG
void CMFCExp42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp42Doc* CMFCExp42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp42Doc)));
	return (CMFCExp42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp42View ��Ϣ�������


void CMFCExp42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp42Doc*pDoc = GetDocument();
	pDoc->count = 0;
	pDoc->m = point.x;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExp42View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp42Doc*pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->n = point.x;
	int d = pDoc->n - pDoc->m;
	CString ns;
	if (d == 0)
	{
		
		ns.Format(_T("���û���ƶ����޷�����"));
		dc.TextOutW(20, 50, ns);
		pDoc->s.Format(_T("�ƶ���������ÿ�κ����ƶ����أ�"));
		dc.TextOutW(20, 20, pDoc->s);
	}
	else
	{
		ns.Format(_T("�������ƶ������Լ���"));
		dc.TextOutW(20, 50, ns);
		pDoc->s.Format(_T("�ƶ�������%d��ÿ�κ����ƶ����أ�%d"), pDoc->count, d / pDoc->count);
		dc.TextOutW(20, 20, pDoc->s);
	}
	
	CView::OnLButtonUp(nFlags, point);
}


void CMFCExp42View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp42Doc*pDoc = GetDocument();
	pDoc->count+=1;
	CView::OnMouseMove(nFlags, point);
}
