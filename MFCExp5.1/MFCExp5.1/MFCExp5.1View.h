
// MFCExp5.1View.h : CMFCExp51View ��Ľӿ�
//

#pragma once


class CMFCExp51View : public CView
{
protected: // �������л�����
	CMFCExp51View();
	DECLARE_DYNCREATE(CMFCExp51View)

// ����
public:
	CMFCExp51Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCExp5.1View.cpp �еĵ��԰汾
inline CMFCExp51Doc* CMFCExp51View::GetDocument() const
   { return reinterpret_cast<CMFCExp51Doc*>(m_pDocument); }
#endif

