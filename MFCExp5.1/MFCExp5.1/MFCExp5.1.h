
// MFCExp5.1.h : MFCExp5.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp51App:
// �йش����ʵ�֣������ MFCExp5.1.cpp
//

class CMFCExp51App : public CWinApp
{
public:
	CMFCExp51App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp51App theApp;
