
// MFCExp12.4View.h : CMFCExp124View ��Ľӿ�
//

#pragma once

class CMFCExp124Set;

class CMFCExp124View : public CRecordView
{
protected: // �������л�����
	CMFCExp124View();
	DECLARE_DYNCREATE(CMFCExp124View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP124_FORM };
#endif
	CMFCExp124Set* m_pSet;

// ����
public:
	CMFCExp124Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void foo(CImage& img, int& sx, int& sy, int& w, int& h);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCExp124View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MFCExp12.4View.cpp �еĵ��԰汾
inline CMFCExp124Doc* CMFCExp124View::GetDocument() const
   { return reinterpret_cast<CMFCExp124Doc*>(m_pDocument); }
#endif

