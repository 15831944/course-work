#pragma once


// CMyDlg0 �Ի���

class CMyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg0)

public:
	CMyDlg0(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlg0();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
