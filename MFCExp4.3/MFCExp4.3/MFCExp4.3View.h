
// MFCExp4.3View.h : CMFCExp43View ��Ľӿ�
//

#pragma once


class CMFCExp43View : public CView
{
protected: // �������л�����
	CMFCExp43View();
	DECLARE_DYNCREATE(CMFCExp43View)

// ����
public:
	CMFCExp43Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFCExp4.3View.cpp �еĵ��԰汾
inline CMFCExp43Doc* CMFCExp43View::GetDocument() const
   { return reinterpret_cast<CMFCExp43Doc*>(m_pDocument); }
#endif

