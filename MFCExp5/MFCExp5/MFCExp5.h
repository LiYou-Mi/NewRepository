
// MFCExp5.h : MFCExp5 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp5App:
// �йش����ʵ�֣������ MFCExp5.cpp
//

class CMFCExp5App : public CWinAppEx
{
public:
	CMFCExp5App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp5App theApp;
