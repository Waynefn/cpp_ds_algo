/*
https://www.titech.ac.jp/graduate_school/admissions/pdf/cs_h28.pdf
问题3->subset sum problem
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAX (20)
#define Len(x)		sizeof(x)/sizeof(x[0])	

int f(int a[], int n, int k, int s, int i)
{
	if(i == n)
	{
		cout<<"----"<<endl;
		return s == k;
	}
	else
	{
		cout<<"++++"<<endl;
		return f(a, n, k, s, i+1) || f(a, n, k, s+a[i], i+1);
	}
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
			if(k == a[j])
				b[i][j] = 1;
			if(i > 0)
			{
				if(b[i-1][j])
					b[i][j] = 1;
				if(j >= a[i] && b[i-1][j-a[i]])
					b[i][j] = 1;
			}
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= k; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<"ret = "<<b[n-1][k]<<endl;
}

void test_1()
{
	int a[] = {3,7,5,8,2};
	int k = 11;
//	cout<< f(a, Len(a), k, 0, 0);
	g(a, Len(a), k);
}

int main()
{
	test_1();

	return 0;
}