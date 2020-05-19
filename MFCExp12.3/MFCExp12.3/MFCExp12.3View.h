
// MFCExp12.3View.h : CMFCExp123View 类的接口
//

#pragma once

class CMFCExp123Set;

class CMFCExp123View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCExp123View();
	DECLARE_DYNCREATE(CMFCExp123View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP123_FORM };
#endif
	CMFCExp123Set* m_pSet;

// 特性
public:
	CMFCExp123Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCExp123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	double id;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedEdit();
};

#ifndef _DEBUG  // MFCExp12.3View.cpp 中的调试版本
inline CMFCExp123Doc* CMFCExp123View::GetDocument() const
   { return reinterpret_cast<CMFCExp123Doc*>(m_pDocument); }
#endif

