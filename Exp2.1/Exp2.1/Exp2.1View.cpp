
// Exp2.1View.cpp : CExp21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp2.1.h"
#endif

#include "Exp2.1Doc.h"
#include "Exp2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;

// CExp21View

IMPLEMENT_DYNCREATE(CExp21View, CView)

BEGIN_MESSAGE_MAP(CExp21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp21View ����/����

CExp21View::CExp21View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp21View::~CExp21View()
{
}

BOOL CExp21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp21View ����

void CExp21View::OnDraw(CDC* pDC)
{
	CExp21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// CExp21View ���

#ifdef _DEBUG
void CExp21View::AssertValid() const
{
	CView::AssertValid();
}

void CExp21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp21Doc* CExp21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp21Doc)));
	return (CExp21Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp21View ��Ϣ�������


void CExp21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExp21Doc*pDoc = GetDocument();
	pDoc->r = rand() % 50 + 5;
	CClientDC dc(this);
	CRect cr(point.x-pDoc->r,point.y-pDoc->r,point.x+pDoc->r,point.y+pDoc->r);
	pDoc->ca.Add(cr);
	this->Invalidate();
	dc.Ellipse(&cr);
	CView::OnLButtonDown(nFlags, point);
}
