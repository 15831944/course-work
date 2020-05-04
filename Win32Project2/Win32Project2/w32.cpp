#include"stdafx.h"
#include"w32.h"
#include"math.h"
char* pchar()
{
	return "这是从静态库调用的字符串";
}
int factorial(int n)
{
	int ans;
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}
float FAC::convert(float deg)
{
	float Rad_to_deg;
	float rad;
	Rad_to_deg = 45.0 / atan(1.0);
	rad = deg / Rad_to_deg;
	return rad;
}