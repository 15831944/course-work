
// LibExp1View.h : CLibExp1View ��Ľӿ�
//

#pragma once


class CLibExp1View : public CView
{
protected: // �������л�����
	CLibExp1View();
	DECLARE_DYNCREATE(CLibExp1View)

// ����
public:
	CLibExp1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CLibExp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LibExp1View.cpp �еĵ��԰汾
inline CLibExp1Doc* CLibExp1View::GetDocument() const
   { return reinterpret_cast<CLibExp1Doc*>(m_pDocument); }
#endif

