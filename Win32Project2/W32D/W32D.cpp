// W32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "W32D.h"
#include "math.h"

// ���ǵ���������һ��ʾ��
W32D_API int nW32D=0;

// ���ǵ���������һ��ʾ����
W32D_API int fnW32D(void)
{
    return 42;
}

W32D_API int Factorial(int n)
{
	int ans;
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}

W32D_API float Convert(float deg)
{
	float Rad_to_deg;
	float rad;
	Rad_to_deg = 45.0 / atan(1.0);
	rad = deg / Rad_to_deg;
	return rad;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� W32D.h
CW32D::CW32D()
{
    return;
}
