
// MFCExp4.1.h : MFCExp4.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp41App:
// �йش����ʵ�֣������ MFCExp4.1.cpp
//

class CMFCExp41App : public CWinApp
{
public:
	CMFCExp41App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp41App theApp;
