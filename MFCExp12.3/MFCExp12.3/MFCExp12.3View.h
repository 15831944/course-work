
// MFCExp12.3View.h : CMFCExp123View ��Ľӿ�
//

#pragma once

class CMFCExp123Set;

class CMFCExp123View : public CRecordView
{
protected: // �������л�����
	CMFCExp123View();
	DECLARE_DYNCREATE(CMFCExp123View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCEXP123_FORM };
#endif
	CMFCExp123Set* m_pSet;

// ����
public:
	CMFCExp123Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCExp123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	double id;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedEdit();
};

#ifndef _DEBUG  // MFCExp12.3View.cpp �еĵ��԰汾
inline CMFCExp123Doc* CMFCExp123View::GetDocument() const
   { return reinterpret_cast<CMFCExp123Doc*>(m_pDocument); }
#endif

