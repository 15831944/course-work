#pragma once


// DlgAdd �Ի���

class DlgAdd : public CDialogEx
{
	DECLARE_DYNAMIC(DlgAdd)

public:
	DlgAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgAdd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double a;
};
