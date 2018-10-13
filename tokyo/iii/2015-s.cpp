/*
问题2：最大子序列和（禁止选相邻元素）
问题3：阶乘，gcd，任意进制转换
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define M (100)
#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/***************************************
	问题2：最大子序列和（禁止选相邻元素）
***************************************/
void subsum_result(int a[], int n, int d[])
{
	if(n <= 0)
		return;
	if(d[n] == d[n-1])
		subsum_result(a, n-1, d);
	else
	{
		cout<<"add a["<<n-1<<"] = "<<a[n-1]<<endl;
		subsum_result(a, n-2, d);
	}
}

void subsum(int a[], int n)
{
	int d[M] = {0};
	d[1] = a[0];
	for(int i = 2; i <= n; i++)
		d[i] = max(d[i-1], d[i-2] + a[i-1]);
	subsum_result(a, n, d);
	cout<<"d[] = "<<d[n]<<endl;
}

void Q2()
{
	int a[] = {1,5,2,-4,6};
	int b[] = {3,5,7,6,2,4};
	subsum(a, Len(a));
	subsum(b, Len(b));
}

/***************************************
	问题3：阶乘，gcd，任意进制转换
***************************************/
int factorial(int n)
{
	int ret = 1;
	for(int i = 1; i <= n; i++)
		ret *= i;
	return ret;
}

int GCD(int m, int n)
{
	int r = 1;
	while(r)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

char *F(int n, int b)
{
	static char outb[66] = {0};
	int i = 64;
	for(; n > 0 && i > 0; --i, n /= b)
		outb[i] = "0123456789abcdefghijkl"[n%b];
	return &outb[i+1];
}

void Q3()
{
	cout<<"5! = "<<factorial(5)<<endl;
	cout<<"gcd(12,8) = "<<GCD(12,8)<<endl;
	cout<<F(428,16)<<endl;		// 1ac
	cout<<F(226,4)<<endl;		// 3202
}

int main()
{
	Q2();
	Q3();
	return 0;
}