
// Exp3.1View.cpp : CExp31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp3.1.h"
#endif

#include "Exp3.1Doc.h"
#include "Exp3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp31View

IMPLEMENT_DYNCREATE(CExp31View, CView)

BEGIN_MESSAGE_MAP(CExp31View, CView)
END_MESSAGE_MAP()

// CExp31View ����/����

CExp31View::CExp31View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp31View::~CExp31View()
{
}

BOOL CExp31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp31View ����

void CExp31View::OnDraw(CDC* /*pDC*/)
{
	CExp31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC dc(this);
	CString a;
	a.Format(_T("%d"), pDoc->A);
	dc.TextOutW(200, 300, pDoc->S);
	dc.TextOutW(200, 400, a);
}


// CExp31View ���

#ifdef _DEBUG
void CExp31View::AssertValid() const
{
	CView::AssertValid();
}

void CExp31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp31Doc* CExp31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp31Doc)));
	return (CExp31Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp31View ��Ϣ�������
