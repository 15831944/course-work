
// MFCExp12.2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCExp122App: 
// �йش����ʵ�֣������ MFCExp12.2.cpp
//

class CMFCExp122App : public CWinApp
{
public:
	CMFCExp122App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCExp122App theApp;