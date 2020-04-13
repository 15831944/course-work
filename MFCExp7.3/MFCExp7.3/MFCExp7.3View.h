
// MFCExp7.3View.h : CMFCExp73View 类的接口
//

#pragma once


class CMFCExp73View : public CView
{
protected: // 仅从序列化创建
	CMFCExp73View();
	DECLARE_DYNCREATE(CMFCExp73View)

// 特性
public:
	CMFCExp73Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp73View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCExp7.3View.cpp 中的调试版本
inline CMFCExp73Doc* CMFCExp73View::GetDocument() const
   { return reinterpret_cast<CMFCExp73Doc*>(m_pDocument); }
#endif

