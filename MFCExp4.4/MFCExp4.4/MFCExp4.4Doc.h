
// MFCExp4.4Doc.h : CMFCExp44Doc ��Ľӿ�
//


#pragma once


class CMFCExp44Doc : public CDocument
{
protected: // �������л�����
	CMFCExp44Doc();
	DECLARE_DYNCREATE(CMFCExp44Doc)

// ����
public:
	int n;
	CArray<CRect, CRect> cr;
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
	virtual ~CMFCExp44Doc();
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
