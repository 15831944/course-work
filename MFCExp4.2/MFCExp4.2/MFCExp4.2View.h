
// MFCExp4.2View.h : CMFCExp42View 类的接口
//

#pragma once


class CMFCExp42View : public CView
{
protected: // 仅从序列化创建
	CMFCExp42View();
	DECLARE_DYNCREATE(CMFCExp42View)

// 特性
public:
	CMFCExp42Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp4.2View.cpp 中的调试版本
inline CMFCExp42Doc* CMFCExp42View::GetDocument() const
   { return reinterpret_cast<CMFCExp42Doc*>(m_pDocument); }
#endif

