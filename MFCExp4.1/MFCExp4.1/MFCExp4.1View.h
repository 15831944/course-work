
// MFCExp4.1View.h : CMFCExp41View ��Ľӿ�
//

#pragma once


class CMFCExp41View : public CView
{
protected: // �������л�����
	CMFCExp41View();
	DECLARE_DYNCREATE(CMFCExp41View)

// ����
public:
	CMFCExp41Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp4.1View.cpp �еĵ��԰汾
inline CMFCExp41Doc* CMFCExp41View::GetDocument() const
   { return reinterpret_cast<CMFCExp41Doc*>(m_pDocument); }
#endif

