
// MFCExp11.1View.h : CMFCExp111View 类的接口
//

#pragma once

class CMFCExp111Set;

class CMFCExp111View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCExp111View();
	DECLARE_DYNCREATE(CMFCExp111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP111_FORM };
#endif
	CMFCExp111Set* m_pSet;

// 特性
public:
	CMFCExp111Doc* GetDocument() const;

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
	virtual ~CMFCExp111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString id;
	CString number;
	CString name;
	CString age;
	afx_msg void OnShowPicture();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnAutoDisplay();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCExp11.1View.cpp 中的调试版本
inline CMFCExp111Doc* CMFCExp111View::GetDocument() const
   { return reinterpret_cast<CMFCExp111Doc*>(m_pDocument); }
#endif

