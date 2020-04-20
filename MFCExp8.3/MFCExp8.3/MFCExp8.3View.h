
// MFCExp8.3View.h : CMFCExp83View 类的接口
//

#pragma once


class CMFCExp83View : public CView
{
protected: // 仅从序列化创建
	CMFCExp83View();
	DECLARE_DYNCREATE(CMFCExp83View)

// 特性
public:
	CMFCExp83Doc* GetDocument() const;

// 操作
public:
	CPoint s_point, e_point;
	int flag = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp83View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp8.3View.cpp 中的调试版本
inline CMFCExp83Doc* CMFCExp83View::GetDocument() const
   { return reinterpret_cast<CMFCExp83Doc*>(m_pDocument); }
#endif

