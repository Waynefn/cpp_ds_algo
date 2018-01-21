/*
http://www.cs.titech.ac.jp/H27-gozen.pdf
问题5->最大连续子序列和

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	


int max(int x, int y)
{
	return x > y ? x : y;
}

int sum(int a[], int i, int j)
{
	int s = 0;
	for(int k = i; k <= j; k++)
		s += a[k];
	return s;
}

int f_1(int a[], int n)
{
	int s = a[0];
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			s = max(s, sum(a, i, j));
	cout<<"f_1() max_s = "<<s<<endl;
	return s;
}

int f_2(int a[], int n)
{
	int s = a[0];
	for(int i = 0; i < n; i++)
	{
		int t = 0;
		for(int j = i; j < n; j++)
		{
			t = t + a[j];
			s = max(s, t);
		}
	}
	cout<<"f_2() max_s = "<<s<<endl;
	return s;
}

int g(int a[], int n)
{
	int t = a[0];
	for(int k = 1; k < n; k++)
		t = max(t + a[k], t);
	return t;
}

int f_3(int a[], int n)
{
	int s = a[0];
	for(int k = 1; k < n; k++)
		s = max(s, g(a, n-k));
	cout<<"f_3() max_s = "<<s<<endl;
	return s;
}

// int f_4(int a[], int n)
// {
// 	int t = , s = a[0];
// 	for(int k = 1; k < n; i++)
// 	{
// 		t = max();
// 		s = max();
// 	}
// 	cout<<"f_4() max_s = "<<s<<endl;
// 	return s;
// }

int main()
{
	int a[] = {20, -24, 36, 3, -7, 27, -40, 37, -28, 6};
	f_1(a, Len(a));
	f_2(a, Len(a));
//	f_3(a, Len(a));
//	f_4(a, Len(a));
	return 0;
}