
// Exp1.2View.h : CExp12View ��Ľӿ�
//

#pragma once


class CExp12View : public CView
{
protected: // �������л�����
	CExp12View();
	DECLARE_DYNCREATE(CExp12View)

// ����
public:
	CExp12Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp12View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Exp1.2View.cpp �еĵ��԰汾
inline CExp12Doc* CExp12View::GetDocument() const
   { return reinterpret_cast<CExp12Doc*>(m_pDocument); }
#endif

