
// ��ʮ��ʵ���.h : ��ʮ��ʵ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʮ��ʵ���App:
// �йش����ʵ�֣������ ��ʮ��ʵ���.cpp
//

class C��ʮ��ʵ���App : public CWinApp
{
public:
	C��ʮ��ʵ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʮ��ʵ���App theApp;
