
// MFCExp12.3.h : MFCExp12.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp123App:
// �йش����ʵ�֣������ MFCExp12.3.cpp
//

class CMFCExp123App : public CWinApp
{
public:
	CMFCExp123App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp123App theApp;
