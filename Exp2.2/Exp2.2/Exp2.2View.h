
// Exp2.2View.h : CExp22View 类的接口
//

#pragma once


class CExp22View : public CView
{
protected: // 仅从序列化创建
	CExp22View();
	DECLARE_DYNCREATE(CExp22View)

// 特性
public:
	CExp22Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp22View();
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
};

#ifndef _DEBUG  // Exp2.2View.cpp 中的调试版本
inline CExp22Doc* CExp22View::GetDocument() const
   { return reinterpret_cast<CExp22Doc*>(m_pDocument); }
#endif

