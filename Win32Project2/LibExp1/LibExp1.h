
// LibExp1.h : LibExp1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CLibExp1App:
// �йش����ʵ�֣������ LibExp1.cpp
//

class CLibExp1App : public CWinApp
{
public:
	CLibExp1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLibExp1App theApp;
