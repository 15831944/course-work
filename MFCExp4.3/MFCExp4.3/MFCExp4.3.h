
// MFCExp4.3.h : MFCExp4.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp43App:
// �йش����ʵ�֣������ MFCExp4.3.cpp
//

class CMFCExp43App : public CWinApp
{
public:
	CMFCExp43App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp43App theApp;
