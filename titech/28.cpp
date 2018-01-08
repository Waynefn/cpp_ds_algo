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
			if(j == 0)
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

bool isSubsetSum(int set[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

bool dp_isSubsetSum(int set[], int n, int sum)
{
    bool subset[n+1][sum+1];

    for (int i = 0; i <= n; i++)
      subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if(j<set[i-1])
				subset[i][j] = subset[i-1][j];
			if (j >= set[i-1])
				subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]];
		}
	}
  
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
			cout<<subset[i][j]<<" ";
		cout<<endl;
	}
  
	return subset[n][sum];
}

void test_1()
{
	int a[] = {8,2,4};
	int k = 10;
//	cout<<f(a, Len(a), k, 0, 0)<<endl;
	cout<<dp_isSubsetSum(a, Len(a), k)<<endl;
//	g(a, Len(a), k);
}

int main()
{
	test_1();

	return 0;
}