
// LibExp1View.cpp : CLibExp1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LibExp1.h"
#endif

#include "LibExp1Doc.h"
#include "LibExp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"
#include "W32D.h"
// CLibExp1View

IMPLEMENT_DYNCREATE(CLibExp1View, CView)

BEGIN_MESSAGE_MAP(CLibExp1View, CView)
END_MESSAGE_MAP()

// CLibExp1View ����/����

CLibExp1View::CLibExp1View()
{
	// TODO: �ڴ˴���ӹ������

}

CLibExp1View::~CLibExp1View()
{
}

BOOL CLibExp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLibExp1View ����

void CLibExp1View::OnDraw(CDC* pDC)
{
	CLibExp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s1,s2;
	int a;
	a = factorial(5);
	s1.Format(_T("��̬���ӿ⣺%d"), a);
	pDC->TextOutW(150, 150, s1);

	FAC f;
	float r = f.convert(30.0);
	s2.Format(_T("��̬���ӿ⣺%.10f"), r);
	pDC->TextOutW(150, 200, s2);

	CString s3, s4;
	int b;
	b = Factorial(5);
	s3.Format(_T("��̬���ӿ⣺%d"), b);
	pDC->TextOutW(150, 250, s3);

	float R = Convert(30.0);
	s4.Format(_T("��̬���ӿ⣺%.10f"), R);
	pDC->TextOutW(150, 300, s4);
}


// CLibExp1View ���

#ifdef _DEBUG
void CLibExp1View::AssertValid() const
{
	CView::AssertValid();
}

void CLibExp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLibExp1Doc* CLibExp1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibExp1Doc)));
	return (CLibExp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CLibExp1View ��Ϣ�������
