
// MFCExp11.1.h : MFCExp11.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp111App:
// �йش����ʵ�֣������ MFCExp11.1.cpp
//

class CMFCExp111App : public CWinApp
{
public:
	CMFCExp111App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp111App theApp;
