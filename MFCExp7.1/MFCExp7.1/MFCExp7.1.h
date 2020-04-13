
// MFCExp7.1.h : MFCExp7.1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFCExp71App:
// 有关此类的实现，请参阅 MFCExp7.1.cpp
//

class CMFCExp71App : public CWinApp
{
public:
	CMFCExp71App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp71App theApp;
