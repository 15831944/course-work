
// Exp2.2View.h : CExp22View ��Ľӿ�
//

#pragma once


class CExp22View : public CView
{
protected: // �������л�����
	CExp22View();
	DECLARE_DYNCREATE(CExp22View)

// ����
public:
	CExp22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp22View();
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
};

#ifndef _DEBUG  // Exp2.2View.cpp �еĵ��԰汾
inline CExp22Doc* CExp22View::GetDocument() const
   { return reinterpret_cast<CExp22Doc*>(m_pDocument); }
#endif

