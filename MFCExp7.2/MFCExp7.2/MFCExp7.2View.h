
// MFCExp7.2View.h : CMFCExp72View 类的接口
//

#pragma once


class CMFCExp72View : public CView
{
protected: // 仅从序列化创建
	CMFCExp72View();
	DECLARE_DYNCREATE(CMFCExp72View)

// 特性
public:
	CMFCExp72Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp7.2View.cpp 中的调试版本
inline CMFCExp72Doc* CMFCExp72View::GetDocument() const
   { return reinterpret_cast<CMFCExp72Doc*>(m_pDocument); }
#endif

