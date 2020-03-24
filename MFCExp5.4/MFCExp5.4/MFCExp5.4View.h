
// MFCExp5.4View.h : CMFCExp54View 类的接口
//

#pragma once


class CMFCExp54View : public CView
{
protected: // 仅从序列化创建
	CMFCExp54View();
	DECLARE_DYNCREATE(CMFCExp54View)

// 特性
public:
	CMFCExp54Doc* GetDocument() const;

// 操作
public:
	CPoint p1, p2;
	bool line,rectangle,circle;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp54View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnCircle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp5.4View.cpp 中的调试版本
inline CMFCExp54Doc* CMFCExp54View::GetDocument() const
   { return reinterpret_cast<CMFCExp54Doc*>(m_pDocument); }
#endif

