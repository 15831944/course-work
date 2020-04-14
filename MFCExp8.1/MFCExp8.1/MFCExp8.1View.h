
// MFCExp8.1View.h : CMFCExp81View 类的接口
//

#pragma once


class CMFCExp81View : public CView
{
protected: // 仅从序列化创建
	CMFCExp81View();
	DECLARE_DYNCREATE(CMFCExp81View)

// 特性
public:
	CMFCExp81Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString s;
	int flag;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFCExp8.1View.cpp 中的调试版本
inline CMFCExp81Doc* CMFCExp81View::GetDocument() const
   { return reinterpret_cast<CMFCExp81Doc*>(m_pDocument); }
#endif

