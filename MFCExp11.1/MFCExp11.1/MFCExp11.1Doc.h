
// MFCExp11.1Doc.h : CMFCExp111Doc ��Ľӿ�
//


#pragma once
#include "MFCExp11.1Set.h"


class CMFCExp111Doc : public CDocument
{
protected: // �������л�����
	CMFCExp111Doc();
	DECLARE_DYNCREATE(CMFCExp111Doc)

// ����
public:
	CMFCExp111Set m_MFCExp111Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCExp111Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
