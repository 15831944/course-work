
// MFCExp5.1Doc.h : CMFCExp51Doc ��Ľӿ�
//


#pragma once


class CMFCExp51Doc : public CDocument
{
protected: // �������л�����
	CMFCExp51Doc();
	DECLARE_DYNCREATE(CMFCExp51Doc)

// ����
public:
	int n;
	CArray<CRect, CRect> cr;
	int r;
	bool set;
	bool b[5];
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCExp51Doc();
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
