
// Exp2.2View.cpp : CExp22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp2.2.h"
#endif

#include "Exp2.2Doc.h"
#include "Exp2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CRect cr;

// CExp22View

IMPLEMENT_DYNCREATE(CExp22View, CView)

BEGIN_MESSAGE_MAP(CExp22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp22View ����/����

CExp22View::CExp22View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp22View::~CExp22View()
{
}

BOOL CExp22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp22View ����

void CExp22View::OnDraw(CDC* pDC)
{
	CExp22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	this->GetClientRect(&cr);
	CClientDC dc(this);
	CBrush *b = new CBrush(RGB(0, 0, 255));
	dc.SelectObject(b);
    dc.Ellipse(&cr);
}


// CExp22View ���

#ifdef _DEBUG
void CExp22View::AssertValid() const
{
	CView::AssertValid();
}

void CExp22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp22Doc* CExp22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp22Doc)));
	return (CExp22Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp22View ��Ϣ�������


void CExp22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnLButtonDown(nFlags, point);
}
