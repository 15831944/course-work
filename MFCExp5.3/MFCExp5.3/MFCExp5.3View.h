
// MFCExp5.3View.h : CMFCExp53View ��Ľӿ�
//

#pragma once


class CMFCExp53View : public CView
{
protected: // �������л�����
	CMFCExp53View();
	DECLARE_DYNCREATE(CMFCExp53View)

// ����
public:
	CMFCExp53Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;//λͼ����
	int m_nWidth;//�洢λͼ������ݳ�Ա
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCExp5.3View.cpp �еĵ��԰汾
inline CMFCExp53Doc* CMFCExp53View::GetDocument() const
   { return reinterpret_cast<CMFCExp53Doc*>(m_pDocument); }
#endif

