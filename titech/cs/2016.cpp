/*
https://www.titech.ac.jp/graduate_school/admissions/pdf/cs_h28.pdf
问题3->d sum problem
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAX (20)
#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++) cout<<a[i][j]<<"|"; cout<<endl;}}

bool subset_sum(int a[], int n, int k)
{
	if (k == 0)
		return true;
	if (n == 0 && k != 0)
		return false;
	if (a[n-1] > k)
		return subset_sum(a, n-1, k);

	return subset_sum(a, n-1, k) || subset_sum(a, n-1, k-a[n-1]);
}

int f(int a[], int n, int k, int s, int i)
{
	if(s > k)
		return 0;
	if(i == n)
		return s == k;
	else
		return f(a, n, k, s, i+1) || f(a, n, k, s+a[i], i+1);
}

void g(int a[], int n, int k)
{
	int i, j;
	int b[MAX][MAX];

	b[0][0] = 1;
	for(i = 0; i < n; i++)
	{
		for(j = 1; j <= k; j++)
			b[i][j] = 0;
		for(j = 0; j <= k; j++)
		{
			if(j == 0 || j == a[i])	// 难点1 由于b[i][j]的定义导致需要小心处理子问题的结果
				b[i][j] = 1;
			if(i > 0)
			{
				if(b[i-1][j])
					b[i][j] = 1;
				if(j >= a[i] && b[i-1][j-a[i]])	// 难点2 注意问题对b[i][j]的定义
					b[i][j] = 1;
			}
		}
	}

	PRINT_MATRIX(b, n, k+1);
	cout<<"g() result: "<<b[n-1][k]<<endl;	// 此题的b[i][j]指的是:从a[0]到a[i]为止,是否存在某几个元素组成j,所以考虑取舍的last元素是a[i]
}

void test_1()
{
	int a[] = {3,2,4};
	int k = 6;
	cout<<"subset_sum() result: "<<subset_sum(a, Len(a), k)<<endl;
	cout<<"f() result: "<<f(a, Len(a), k, 0, 0)<<endl;
	g(a, Len(a), k);
}

int main()
{
	test_1();

	return 0;
}