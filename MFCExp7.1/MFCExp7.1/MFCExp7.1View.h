
// MFCExp7.1View.h : CMFCExp71View 类的接口
//

#pragma once


class CMFCExp71View : public CView
{
protected: // 仅从序列化创建
	CMFCExp71View();
	DECLARE_DYNCREATE(CMFCExp71View)

// 特性
public:
	CMFCExp71Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp71View();
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
};

#ifndef _DEBUG  // MFCExp7.1View.cpp 中的调试版本
inline CMFCExp71Doc* CMFCExp71View::GetDocument() const
   { return reinterpret_cast<CMFCExp71Doc*>(m_pDocument); }
#endif

