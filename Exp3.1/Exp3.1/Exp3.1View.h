
// Exp3.1View.h : CExp31View 类的接口
//

#pragma once


class CExp31View : public CView
{
protected: // 仅从序列化创建
	CExp31View();
	DECLARE_DYNCREATE(CExp31View)

// 特性
public:
	CExp31Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp31View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Exp3.1View.cpp 中的调试版本
inline CExp31Doc* CExp31View::GetDocument() const
   { return reinterpret_cast<CExp31Doc*>(m_pDocument); }
#endif

