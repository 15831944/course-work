
// MFCExp12.1Doc.h : CMFCExp121Doc ��Ľӿ�
//


#pragma once
#include "MFCExp12.1Set.h"


class CMFCExp121Doc : public CDocument
{
protected: // �������л�����
	CMFCExp121Doc();
	DECLARE_DYNCREATE(CMFCExp121Doc)

// ����
public:
	CMFCExp121Set m_MFCExp121Set;

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
	virtual ~CMFCExp121Doc();
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
