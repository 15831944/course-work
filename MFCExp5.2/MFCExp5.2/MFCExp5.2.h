
// MFCExp5.2.h : MFCExp5.2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp52App:
// �йش����ʵ�֣������ MFCExp5.2.cpp
//

class CMFCExp52App : public CWinApp
{
public:
	CMFCExp52App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp52App theApp;
