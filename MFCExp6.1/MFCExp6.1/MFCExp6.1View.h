
// MFCExp6.1View.h : CMFCExp61View 类的接口
//

#pragma once


class CMFCExp61View : public CView
{
protected: // 仅从序列化创建
	CMFCExp61View();
	DECLARE_DYNCREATE(CMFCExp61View)

// 特性
public:
	CMFCExp61Doc* GetDocument() const;

// 操作
public:
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFCExp6.1View.cpp 中的调试版本
inline CMFCExp61Doc* CMFCExp61View::GetDocument() const
   { return reinterpret_cast<CMFCExp61Doc*>(m_pDocument); }
#endif

