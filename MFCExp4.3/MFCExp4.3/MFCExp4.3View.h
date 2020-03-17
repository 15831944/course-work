
// MFCExp4.3View.h : CMFCExp43View 类的接口
//

#pragma once


class CMFCExp43View : public CView
{
protected: // 仅从序列化创建
	CMFCExp43View();
	DECLARE_DYNCREATE(CMFCExp43View)

// 特性
public:
	CMFCExp43Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFCExp4.3View.cpp 中的调试版本
inline CMFCExp43Doc* CMFCExp43View::GetDocument() const
   { return reinterpret_cast<CMFCExp43Doc*>(m_pDocument); }
#endif

