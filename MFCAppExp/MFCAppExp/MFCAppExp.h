
// MFCAppExp.h : MFCAppExp Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCAppExpApp:
// �йش����ʵ�֣������ MFCAppExp.cpp
//

class CMFCAppExpApp : public CWinAppEx
{
public:
	CMFCAppExpApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppExpApp theApp;
