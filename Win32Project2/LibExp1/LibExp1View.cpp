
// LibExp1View.cpp : CLibExp1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CLibExp1View 构造/析构

CLibExp1View::CLibExp1View()
{
	// TODO: 在此处添加构造代码

}

CLibExp1View::~CLibExp1View()
{
}

BOOL CLibExp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLibExp1View 绘制

void CLibExp1View::OnDraw(CDC* pDC)
{
	CLibExp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s1,s2;
	int a;
	a = factorial(5);
	s1.Format(_T("静态链接库：%d"), a);
	pDC->TextOutW(150, 150, s1);

	FAC f;
	float r = f.convert(30.0);
	s2.Format(_T("静态链接库：%.10f"), r);
	pDC->TextOutW(150, 200, s2);

	CString s3, s4;
	int b;
	b = Factorial(5);
	s3.Format(_T("动态链接库：%d"), b);
	pDC->TextOutW(150, 250, s3);

	float R = Convert(30.0);
	s4.Format(_T("动态链接库：%.10f"), R);
	pDC->TextOutW(150, 300, s4);
}


// CLibExp1View 诊断

#ifdef _DEBUG
void CLibExp1View::AssertValid() const
{
	CView::AssertValid();
}

void CLibExp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLibExp1Doc* CLibExp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibExp1Doc)));
	return (CLibExp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CLibExp1View 消息处理程序
