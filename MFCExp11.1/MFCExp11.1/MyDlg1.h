#pragma once


// CMyDlg1 对话框

class CMyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg1)

public:
	CMyDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

};
