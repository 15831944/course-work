
// MFCExp4.2View.h : CMFCExp42View ��Ľӿ�
//

#pragma once


class CMFCExp42View : public CView
{
protected: // �������л�����
	CMFCExp42View();
	DECLARE_DYNCREATE(CMFCExp42View)

// ����
public:
	CMFCExp42Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp42View();
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

#ifndef _DEBUG  // MFCExp4.2View.cpp �еĵ��԰汾
inline CMFCExp42Doc* CMFCExp42View::GetDocument() const
   { return reinterpret_cast<CMFCExp42Doc*>(m_pDocument); }
#endif

