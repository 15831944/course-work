
// MFCExp12.1View.h : CMFCExp121View ��Ľӿ�
//

#pragma once

class CMFCExp121Set;

class CMFCExp121View : public CRecordView
{
protected: // �������л�����
	CMFCExp121View();
	DECLARE_DYNCREATE(CMFCExp121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP121_FORM };
#endif
	CMFCExp121Set* m_pSet;

// ����
public:
	CMFCExp121Doc* GetDocument() const;

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
	virtual ~CMFCExp121View();
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
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	CString name;
	afx_msg void OnEnlarge();
};

#ifndef _DEBUG  // MFCExp12.1View.cpp �еĵ��԰汾
inline CMFCExp121Doc* CMFCExp121View::GetDocument() const
   { return reinterpret_cast<CMFCExp121Doc*>(m_pDocument); }
#endif

