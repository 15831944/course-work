
// MFCExp5.2View.cpp : CMFCExp52View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp5.2.h"
#endif

#include "MFCExp5.2Doc.h"
#include "MFCExp5.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp52View

IMPLEMENT_DYNCREATE(CMFCExp52View, CView)

BEGIN_MESSAGE_MAP(CMFCExp52View, CView)
	ON_COMMAND(ID_ShowName, &CMFCExp52View::OnShowname)
END_MESSAGE_MAP()

// CMFCExp52View ����/����

CMFCExp52View::CMFCExp52View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp52View::~CMFCExp52View()
{
}

BOOL CMFCExp52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp52View ����

void CMFCExp52View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp52View ���

#ifdef _DEBUG
void CMFCExp52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp52Doc* CMFCExp52View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp52Doc)));
	return (CMFCExp52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp52View ��Ϣ�������


void CMFCExp52View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s=_T("����׿");
	CClientDC dc(this);
	dc.TextOutW(100, 100, s);
}
