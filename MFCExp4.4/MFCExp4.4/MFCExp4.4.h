
// MFCExp4.4.h : MFCExp4.4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp44App:
// �йش����ʵ�֣������ MFCExp4.4.cpp
//

class CMFCExp44App : public CWinApp
{
public:
	CMFCExp44App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp44App theApp;
