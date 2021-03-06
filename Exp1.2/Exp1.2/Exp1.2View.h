
// Exp1.2View.h : CExp12View 类的接口
//

#pragma once


class CExp12View : public CView
{
protected: // 仅从序列化创建
	CExp12View();
	DECLARE_DYNCREATE(CExp12View)

// 特性
public:
	CExp12Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp12View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Exp1.2View.cpp 中的调试版本
inline CExp12Doc* CExp12View::GetDocument() const
   { return reinterpret_cast<CExp12Doc*>(m_pDocument); }
#endif

