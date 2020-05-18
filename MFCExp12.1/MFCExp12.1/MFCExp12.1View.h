
// MFCExp12.1View.h : CMFCExp121View 类的接口
//

#pragma once

class CMFCExp121Set;

class CMFCExp121View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCExp121View();
	DECLARE_DYNCREATE(CMFCExp121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP121_FORM };
#endif
	CMFCExp121Set* m_pSet;

// 特性
public:
	CMFCExp121Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void foo(CImage& img, int& sx, int& sy, int& w, int& h);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCExp121View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	CString name;
	afx_msg void OnEnlarge();
};

#ifndef _DEBUG  // MFCExp12.1View.cpp 中的调试版本
inline CMFCExp121Doc* CMFCExp121View::GetDocument() const
   { return reinterpret_cast<CMFCExp121Doc*>(m_pDocument); }
#endif

