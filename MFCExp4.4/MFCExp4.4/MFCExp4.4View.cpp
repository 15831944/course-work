
// MFCExp4.4View.cpp : CMFCExp44View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp4.4.h"
#endif

#include "MFCExp4.4Doc.h"
#include "MFCExp4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp44View

IMPLEMENT_DYNCREATE(CMFCExp44View, CView)

BEGIN_MESSAGE_MAP(CMFCExp44View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCExp44View ����/����

CMFCExp44View::CMFCExp44View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp44View::~CMFCExp44View()
{
}

BOOL CMFCExp44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp44View ����

void CMFCExp44View::OnDraw(CDC* pDC)
{
	CMFCExp44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->n; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		pDoc->cr.Add(rect);
	}
	for (int i = 0; i < pDoc->n; i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	if (pDoc->set)
	{
		for (int i = 0; i < pDoc->n; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
		}
		pDoc->set = false;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp44View ���

#ifdef _DEBUG
void CMFCExp44View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp44Doc* CMFCExp44View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp44Doc)));
	return (CMFCExp44Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp44View ��Ϣ�������


void CMFCExp44View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	CMFCExp44Doc*pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	
	if (pDoc->cr[i].bottom >=clientRect.bottom)
	{
		pDoc->b[i] = true;
	}
	if (pDoc->cr[i].top <=clientRect.top)
	{
		pDoc->b[i] = false;
	}
	if (pDoc->b[i])
	{
		pDoc->cr[i].top -= 10;
		pDoc->cr[i].bottom -= 10;
	}
	else
	{
		pDoc->cr[i].top += 10;
		pDoc->cr[i].bottom += 10;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
