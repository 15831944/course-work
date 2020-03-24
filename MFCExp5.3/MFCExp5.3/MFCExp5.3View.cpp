
// MFCExp5.3View.cpp : CMFCExp53View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp5.3.h"
#endif

#include "MFCExp5.3Doc.h"
#include "MFCExp5.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp53View

IMPLEMENT_DYNCREATE(CMFCExp53View, CView)

BEGIN_MESSAGE_MAP(CMFCExp53View, CView)
END_MESSAGE_MAP()

// CMFCExp53View ����/����

CMFCExp53View::CMFCExp53View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFCExp53View::~CMFCExp53View()
{
}

BOOL CMFCExp53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp53View ����

void CMFCExp53View::OnDraw(CDC* pDC)
{
	CMFCExp53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp53View ���

#ifdef _DEBUG
void CMFCExp53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp53Doc* CMFCExp53View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp53Doc)));
	return (CMFCExp53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp53View ��Ϣ�������
