
// MFCExp9.1View.cpp : CMFCExp91View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp9.1.h"
#endif

#include "MFCExp9.1Doc.h"
#include "MFCExp9.1View.h"
#include "MyDlg.h"
#include "fstream"
#include "string"
#include "iostream"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp91View

IMPLEMENT_DYNCREATE(CMFCExp91View, CView)

BEGIN_MESSAGE_MAP(CMFCExp91View, CView)
	ON_COMMAND(ID_PICTURE, &CMFCExp91View::OnPicture)
	ON_COMMAND(ID_SHOW, &CMFCExp91View::OnShow)
END_MESSAGE_MAP()

// CMFCExp91View 构造/析构

CMFCExp91View::CMFCExp91View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp91View::~CMFCExp91View()
{
}

BOOL CMFCExp91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp91View 绘制

void CMFCExp91View::OnDraw(CDC* /*pDC*/)
{
	CMFCExp91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp91View 诊断

#ifdef _DEBUG
void CMFCExp91View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp91Doc* CMFCExp91View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp91Doc)));
	return (CMFCExp91Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp91View 消息处理程序


void CMFCExp91View::OnPicture()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CString s;
		s.Format(_T("F:\\abc.txt"));
		ofstream ofs(s);
		ofs << CT2A(filename.GetString()) << endl;
	}
}


void CMFCExp91View::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		ifs >> s;
		MyDlg dlg;
		dlg.s = CString(s.c_str());
		int r = dlg.DoModal();
		if (r == IDOK)
		{

		}
	}
}
