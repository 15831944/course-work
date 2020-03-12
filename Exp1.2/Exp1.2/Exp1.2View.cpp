
// Exp1.2View.cpp : CExp12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp1.2.h"
#endif

#include "Exp1.2Doc.h"
#include "Exp1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp12View

IMPLEMENT_DYNCREATE(CExp12View, CView)

BEGIN_MESSAGE_MAP(CExp12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExp12View ����/����

CExp12View::CExp12View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp12View::~CExp12View()
{
}

BOOL CExp12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp12View ����

void CExp12View::OnDraw(CDC* /*pDC*/)
{
	CExp12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExp12View ���

#ifdef _DEBUG
void CExp12View::AssertValid() const
{
	CView::AssertValid();
}

void CExp12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp12Doc* CExp12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp12Doc)));
	return (CExp12Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp12View ��Ϣ�������


void CExp12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExp12Doc*pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CExp12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExp12Doc*pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->s.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200, 300, pDoc->s);
	CView::OnRButtonDown(nFlags, point);
}
