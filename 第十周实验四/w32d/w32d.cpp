// w32d.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "w32d.h"


// ���ǵ���������һ��ʾ��
W32D_API int nw32d=0;

// ���ǵ���������һ��ʾ����
W32D_API int fnw32d(void)
{
    return 42;
}

int factorial(int n)
{
	if (n<0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}
	int s = 1;
	for (int i = 1; i <= n; i++)
	{
		s = s*n;
	}
	return s;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� w32d.h
Cw32d::Cw32d()
{
    return;
}

float FAC::convert(float deg)
{
	return deg / 180 * PI;
}
