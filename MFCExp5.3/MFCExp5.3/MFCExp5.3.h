
// MFCExp5.3.h : MFCExp5.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp53App:
// �йش����ʵ�֣������ MFCExp5.3.cpp
//

class CMFCExp53App : public CWinApp
{
public:
	CMFCExp53App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp53App theApp;
