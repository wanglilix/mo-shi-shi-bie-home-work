
// ģʽʶ����ҵ.h : ģʽʶ����ҵ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cģʽʶ����ҵApp:
// �йش����ʵ�֣������ ģʽʶ����ҵ.cpp
//

class Cģʽʶ����ҵApp : public CWinApp
{
public:
	Cģʽʶ����ҵApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cģʽʶ����ҵApp theApp;
