
// MFCExp5.2View.h : CMFCExp52View 类的接口
//

#pragma once


class CMFCExp52View : public CView
{
protected: // 仅从序列化创建
	CMFCExp52View();
	DECLARE_DYNCREATE(CMFCExp52View)

// 特性
public:
	CMFCExp52Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFCExp5.2View.cpp 中的调试版本
inline CMFCExp52Doc* CMFCExp52View::GetDocument() const
   { return reinterpret_cast<CMFCExp52Doc*>(m_pDocument); }
#endif

