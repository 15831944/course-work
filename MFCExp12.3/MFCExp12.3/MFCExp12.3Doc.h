
// MFCExp12.3Doc.h : CMFCExp123Doc ��Ľӿ�
//


#pragma once
#include "MFCExp12.3Set.h"


class CMFCExp123Doc : public CDocument
{
protected: // �������л�����
	CMFCExp123Doc();
	DECLARE_DYNCREATE(CMFCExp123Doc)

// ����
public:
	CMFCExp123Set m_MFCExp123Set;

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
	virtual ~CMFCExp123Doc();
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
