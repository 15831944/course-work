
// MFCExp12.4.h : MFCExp12.4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp124App:
// �йش����ʵ�֣������ MFCExp12.4.cpp
//

class CMFCExp124App : public CWinApp
{
public:
	CMFCExp124App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp124App theApp;
