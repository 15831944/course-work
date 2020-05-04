
// LibExp1View.h : CLibExp1View 类的接口
//

#pragma once


class CLibExp1View : public CView
{
protected: // 仅从序列化创建
	CLibExp1View();
	DECLARE_DYNCREATE(CLibExp1View)

// 特性
public:
	CLibExp1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CLibExp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LibExp1View.cpp 中的调试版本
inline CLibExp1Doc* CLibExp1View::GetDocument() const
   { return reinterpret_cast<CLibExp1Doc*>(m_pDocument); }
#endif

