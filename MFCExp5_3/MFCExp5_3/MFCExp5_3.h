
// MFCExp5_3.h : MFCExp5_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp5_3App:
// �йش����ʵ�֣������ MFCExp5_3.cpp
//

class CMFCExp5_3App : public CWinApp
{
public:
	CMFCExp5_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp5_3App theApp;
