
// ��ʮ����ʵ��һ.h : ��ʮ����ʵ��һ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʮ����ʵ��һApp:
// �йش����ʵ�֣������ ��ʮ����ʵ��һ.cpp
//

class C��ʮ����ʵ��һApp : public CWinApp
{
public:
	C��ʮ����ʵ��һApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʮ����ʵ��һApp theApp;
