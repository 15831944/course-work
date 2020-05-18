#pragma once


// CMyDlg0 对话框

class CMyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg0)

public:
	CMyDlg0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlg0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
