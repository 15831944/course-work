
// MFCExp5.3View.h : CMFCExp53View 类的接口
//

#pragma once


class CMFCExp53View : public CView
{
protected: // 仅从序列化创建
	CMFCExp53View();
	DECLARE_DYNCREATE(CMFCExp53View)

// 特性
public:
	CMFCExp53Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;//位图对象
	int m_nWidth;//存储位图宽的数据成员
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCExp5.3View.cpp 中的调试版本
inline CMFCExp53Doc* CMFCExp53View::GetDocument() const
   { return reinterpret_cast<CMFCExp53Doc*>(m_pDocument); }
#endif

