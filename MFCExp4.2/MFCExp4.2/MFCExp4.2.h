
// MFCExp4.2.h : MFCExp4.2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp42App:
// �йش����ʵ�֣������ MFCExp4.2.cpp
//

class CMFCExp42App : public CWinApp
{
public:
	CMFCExp42App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp42App theApp;
