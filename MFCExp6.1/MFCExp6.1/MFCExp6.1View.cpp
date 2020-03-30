
// MFCExp6.1View.cpp : CMFCExp61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp6.1.h"
#endif

#include "MFCExp6.1Doc.h"
#include "MFCExp6.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString filename;
CRect rect;
int x, y;
CImage img;
// CMFCExp61View

IMPLEMENT_DYNCREATE(CMFCExp61View, CView)

BEGIN_MESSAGE_MAP(CMFCExp61View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFCExp61View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCExp61View 构造/析构

CMFCExp61View::CMFCExp61View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp61View::~CMFCExp61View()
{
}

BOOL CMFCExp61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp61View 绘制

void CMFCExp61View::OnDraw(CDC* pDC)
{
	CMFCExp61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	GetClientRect(&rect);
	x = rect.Width() / 2 - img.GetWidth() / 2;
	y = rect.Height() / 2 - img.GetHeight() / 2;
	pDC->TextOutW(10, 10, filename);
	img.Draw(pDC->m_hDC, x, y, img.GetWidth(), img.GetHeight());
}


// CMFCExp61View 诊断

#ifdef _DEBUG
void CMFCExp61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp61Doc* CMFCExp61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp61Doc)));
	return (CMFCExp61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp61View 消息处理程序


void CMFCExp61View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		//int w, h, sx, sy;
		img.Load(filename);	
			
			/*float rect_ratio = 1.0*rect.Width() / rect.Height();
			float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
			if (rect_ratio > img_ratio)
			{
				h = rect.Height();
				w = img_ratio*h;
				sx = (rect.Width() - w) / 2;
				sy = 0;
			}
			else
			{
				w = rect.Width();
				h = w / img_ratio;
				sx = 0;
				sy = (rect.Height() - h) / 2;
			}*/
		//pDoc->image.Add(img);
		//img.Draw(dc.m_hDC, sx, sy, w, h);
		
	}
	Invalidate();
}
