
// Exp2.1View.h : CExp21View ��Ľӿ�
//

#pragma once


class CExp21View : public CView
{
protected: // �������л�����
	CExp21View();
	DECLARE_DYNCREATE(CExp21View)

// ����
public:
	CExp21Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp21View();
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

#ifndef _DEBUG  // Exp2.1View.cpp �еĵ��԰汾
inline CExp21Doc* CExp21View::GetDocument() const
   { return reinterpret_cast<CExp21Doc*>(m_pDocument); }
#endif

