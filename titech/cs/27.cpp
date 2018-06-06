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
		for(int j = i; j < n; j++)
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
		t = max(t + a[k], a[k]);
	return t;
}

int f_3(int a[], int n)
{
	int s = a[0];
	for(int k = 1; k < n; k++)
		s = max(s, g(a, k));
	cout<<"f_3() max_s = "<<s<<endl;
	return s;
}

/*
	t:数组截止到t的最大子数组之和（是局部最大值，起始点不一定为0）
	s记录全局的最大子数组之和，即目前为止出现的最大t值
		最初s = a[0]+a[1]，然而a[2]为一个极大负数，导致t从a[3]开始重新计数
		虽然t = 10时也有一个以a[10]截止的局部最大值，但全局最大值需要跟s比较）
*/
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
    cout<<"on_line() max_s = "<<max<<endl;
    return max;
}

int main()
{
	int a[] = {20, -24, 36, 3, -7, 27, -40, 37, -28, 6};

	f_1(a, Len(a));
	f_2(a, Len(a));
	f_3(a, Len(a));
	f_4(a, Len(a));
	on_line(a, Len(a));
	return 0;
}