
// MFCExp9.1View.h : CMFCExp91View 类的接口
//

#pragma once


class CMFCExp91View : public CView
{
protected: // 仅从序列化创建
	CMFCExp91View();
	DECLARE_DYNCREATE(CMFCExp91View)

// 特性
public:
	CMFCExp91Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp91View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPicture();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // MFCExp9.1View.cpp 中的调试版本
inline CMFCExp91Doc* CMFCExp91View::GetDocument() const
   { return reinterpret_cast<CMFCExp91Doc*>(m_pDocument); }
#endif

