
// MFCExp11.1View.h : CMFCExp111View ��Ľӿ�
//

#pragma once

class CMFCExp111Set;

class CMFCExp111View : public CRecordView
{
protected: // �������л�����
	CMFCExp111View();
	DECLARE_DYNCREATE(CMFCExp111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP111_FORM };
#endif
	CMFCExp111Set* m_pSet;

// ����
public:
	CMFCExp111Doc* GetDocument() const;

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
	virtual ~CMFCExp111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MFCExp11.1View.cpp �еĵ��԰汾
inline CMFCExp111Doc* CMFCExp111View::GetDocument() const
   { return reinterpret_cast<CMFCExp111Doc*>(m_pDocument); }
#endif

