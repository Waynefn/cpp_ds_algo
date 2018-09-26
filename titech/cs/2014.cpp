/*
http://www.cs.titech.ac.jp/H27-gozen.pdf
问题5->最大连续子序列和

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	

/**********************************************
	f1
**********************************************/
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
		for(int j = i; j < n; j++)
			s = max(s, sum(a, i, j));
	cout<<"f_1() max_s = "<<s<<endl;
	return s;
}

/**********************************************
	f2
**********************************************/
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

/**********************************************
	f3
**********************************************/
int g(int a[], int n)
{
	int t = a[0];
	for(int k = 1; k < n; k++)
		t = max(t + a[k], a[k]);
	return t;
}

int f_3(int a[], int n)
{
	int s = a[0];
	for(int k = 1; k < n; k++)
		s = max(s, g(a, k+1));
	cout<<"f_3() max_s = "<<s<<endl;
	return s;
}

/**********************************************
	f4
**********************************************/
int f_4(int a[], int n)
{
	int t = a[0], s = a[0];
	for(int k = 1; k < n; k++)
	{
		t = max(t+a[k], a[k]);
		s = max(t, s);
	}
	cout<<"f_4() max_s = "<<s<<endl;
	return s;
}

int on_line(int a[], int n)
{
	int max = -99, s = 0;
 
    for (int i = 0; i < n; i++)
    {
		s = s + a[i];
		if (max < s)
		    max = s;
		if (s < 0)	// 每当累加结果<0,就将下一个元素作为潜在最大子数列的起始元素,重新开始累加
		    s = 0;
    }
    cout<<"f_ol() max_s = "<<max<<endl;
    return max;
}

int main()
{
	int a[] = {2, -1, 5, -10, 7, -4, 11};

	f_1(a, Len(a));
	f_2(a, Len(a));
	f_3(a, Len(a));
	f_4(a, Len(a));
	on_line(a, Len(a));
	return 0;
}