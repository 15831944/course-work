
// Exp3.1View.h : CExp31View ��Ľӿ�
//

#pragma once


class CExp31View : public CView
{
protected: // �������л�����
	CExp31View();
	DECLARE_DYNCREATE(CExp31View)

// ����
public:
	CExp31Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp31View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Exp3.1View.cpp �еĵ��԰汾
inline CExp31Doc* CExp31View::GetDocument() const
   { return reinterpret_cast<CExp31Doc*>(m_pDocument); }
#endif

