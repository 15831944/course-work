
// MFCExp5.2View.h : CMFCExp52View ��Ľӿ�
//

#pragma once


class CMFCExp52View : public CView
{
protected: // �������л�����
	CMFCExp52View();
	DECLARE_DYNCREATE(CMFCExp52View)

// ����
public:
	CMFCExp52Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFCExp5.2View.cpp �еĵ��԰汾
inline CMFCExp52Doc* CMFCExp52View::GetDocument() const
   { return reinterpret_cast<CMFCExp52Doc*>(m_pDocument); }
#endif

