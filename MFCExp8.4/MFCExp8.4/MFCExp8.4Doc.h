
// MFCExp8.4Doc.h : CMFCExp84Doc 类的接口
//


#pragma once


class CMFCExp84Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCExp84Doc();
	DECLARE_DYNCREATE(CMFCExp84Doc)

// 特性
public:

// 操作
public:
	
	CArray <CRect, CRect> cr;
	int a[10] = { 0 };
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCExp84Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
