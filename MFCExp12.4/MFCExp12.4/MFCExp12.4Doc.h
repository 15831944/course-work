
// MFCExp12.4Doc.h : CMFCExp124Doc ��Ľӿ�
//


#pragma once
#include "MFCExp12.4Set.h"


class CMFCExp124Doc : public CDocument
{
protected: // �������л�����
	CMFCExp124Doc();
	DECLARE_DYNCREATE(CMFCExp124Doc)

// ����
public:
	CMFCExp124Set m_MFCExp124Set;

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
	virtual ~CMFCExp124Doc();
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
