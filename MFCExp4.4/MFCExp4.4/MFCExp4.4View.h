
// MFCExp4.4View.h : CMFCExp44View ��Ľӿ�
//

#pragma once


class CMFCExp44View : public CView
{
protected: // �������л�����
	CMFCExp44View();
	DECLARE_DYNCREATE(CMFCExp44View)

// ����
public:
	CMFCExp44Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp44View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCExp4.4View.cpp �еĵ��԰汾
inline CMFCExp44Doc* CMFCExp44View::GetDocument() const
   { return reinterpret_cast<CMFCExp44Doc*>(m_pDocument); }
#endif

