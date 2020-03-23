
// MFCExp5.1View.cpp : CMFCExp51View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp5.1.h"
#endif

#include "MFCExp5.1Doc.h"
#include "MFCExp5.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp51View

IMPLEMENT_DYNCREATE(CMFCExp51View, CView)

BEGIN_MESSAGE_MAP(CMFCExp51View, CView)
	ON_COMMAND(ID_ShowCircle, &CMFCExp51View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCExp51View ����/����

CMFCExp51View::CMFCExp51View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp51View::~CMFCExp51View()
{
}

BOOL CMFCExp51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp51View ����

void CMFCExp51View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s = _T("�����˵����еġ�ʵ�顯����ѡ�񡮽���Բ����ʼ");
	CClientDC dc(this);
	dc.TextOutW(0, 100, s);
}


// CMFCExp51View ���

#ifdef _DEBUG
void CMFCExp51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp51Doc* CMFCExp51View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp51Doc)));
	return (CMFCExp51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp51View ��Ϣ�������


void CMFCExp51View::OnShowcircle()
{
	// TODO: �ڴ���������������
	CMFCExp51Doc*pDoc = GetDocument();
	CClientDC dc(this);
	SetTimer(0, 250, NULL);
	CRect rect;
	GetClientRect(&rect);
	int a = rect.Width()/2;
	int b = rect.Height()/2;
	CRect c(a - pDoc->r, b - pDoc->r, a + pDoc->r, b + pDoc->r);
	pDoc->cr.Add(c);
	CPen pen(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen *p;
	p = dc.SelectObject(&pen);
	dc.Ellipse(&c);
}


void CMFCExp51View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	CClientDC dc(this);
	CMFCExp51Doc*pDoc = GetDocument();
	pDoc->r += 10;
	CRect rect;
	GetClientRect(&rect);
	int a = rect.Width() / 2;
	int b = rect.Height() / 2;
	CPen pen(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen *p;
	p = dc.SelectObject(&pen);
	if (pDoc->r > b)
	{
		pDoc->r = 40;
		Invalidate();
	}
	CRect c(a - pDoc->r, b - pDoc->r, a + pDoc->r, b + pDoc->r);
	dc.Ellipse(&c);
	CView::OnTimer(nIDEvent);
}
