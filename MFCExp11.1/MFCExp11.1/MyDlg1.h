#pragma once


// CMyDlg1 �Ի���

class CMyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg1)

public:
	CMyDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlg1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

};
