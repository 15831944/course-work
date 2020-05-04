// W32D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W32D.h"
#include "math.h"

// 这是导出变量的一个示例
W32D_API int nW32D=0;

// 这是导出函数的一个示例。
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

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W32D.h
CW32D::CW32D()
{
    return;
}
