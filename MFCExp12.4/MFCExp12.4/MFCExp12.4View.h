
// MFCExp12.4View.h : CMFCExp124View 类的接口
//

#pragma once

class CMFCExp124Set;

class CMFCExp124View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCExp124View();
	DECLARE_DYNCREATE(CMFCExp124View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP124_FORM };
#endif
	CMFCExp124Set* m_pSet;

// 特性
public:
	CMFCExp124Doc* GetDocument() const;

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
	virtual ~CMFCExp124View();
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
	double m_id;
	double m_number;
	CString m_name;
	double m_age;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnEnlarge();
	afx_msg void OnSearch();
	afx_msg void OnRecovery();
	afx_msg void OnOrder();
	afx_msg void OnRecordset();
};

#ifndef _DEBUG  // MFCExp12.4View.cpp 中的调试版本
inline CMFCExp124Doc* CMFCExp124View::GetDocument() const
   { return reinterpret_cast<CMFCExp124Doc*>(m_pDocument); }
#endif

