
// �ڰ���ʵ����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ڰ���ʵ����App: 
// �йش����ʵ�֣������ �ڰ���ʵ����.cpp
//

class C�ڰ���ʵ����App : public CWinApp
{
public:
	C�ڰ���ʵ����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ڰ���ʵ����App theApp;