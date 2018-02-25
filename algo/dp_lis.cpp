/*
	最长上升子序列 Longest Increasing Subsequence
	dp:O(n^2)
		dp[i]：a[0]~a[i-1]的最长上升子序列(不是子串,不要求连续性)
		dp[i] = max{dp[j]} + 1 (a[i] > a[j] && j = 0 ~ i-1)
			  = 1			   (a[i] < a[j] && j = 0 ~ i-1)
		ret = max(dp[i])
*/

#include <iostream>
#include <string.h>
#include <limits.h>

#include "utils.h"

using namespace std;

/**********************************************
	DP方法计算LIS
**********************************************/
void longest_increasing_subsequence(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int dp[MAX] = {1};
	int ret = 1;

	for(int i = 1; i < n; i++)
	{
		int curr_max = 0;
		for(int j = 0; j < i; j++)
			if(a[i] > a[j])
				curr_max = max(curr_max, dp[j]);

		dp[i] = curr_max+1;		// {2,3,9,1,6} a[4] > a[3], d[2] = 3, 但curr_max = dp[1] = 2, 所以dp[4] = 3
		ret = max(ret, dp[i]);
	}

	PRINT_ARRAY(a, n);
	PRINT_ARRAY(dp, n);

	cout<<"ret = "<<ret<<endl;
}

void test_lis()
{
	int a[] = {1,3,6,7,8,4,9,5,6};
//	int a[] = {2,3,9,1,6};
	longest_increasing_subsequence(a, Len(a));
}

/**********************************************
	O(N*logN)方法计算LIS
**********************************************/
void longest_increasing_subsequence_modified(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int ret = 0;
	int tmp[MAX];

	tmp[0] = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		int curr = a[i];	// 根据情况考虑a[i]如何处理
		if(curr > tmp[ret])
		{
			tmp[++ret] = curr;	// LIS长度一旦增加，就会被记录到ret中
		}
		else				// 二分搜索找到a[i]应放入的位置
		{
			int l = 1, r = ret;
			while(l <= r)
			{
				int m = (l + r) / 2;
				if(curr > tmp[m])	l = m+1;	
				else				r = m-1;	
			}
			tmp[l] = curr;	// curr插入到临时数组中
		}
		PRINT_ARRAY_2(tmp, 1, ret+1);
	}

	cout<<"LIS = "<<ret<<", 上述输出只是算法过程，不是LIS的结果"<<endl;
}

void test_lis_modified()
{
	int a[] = {2, 5, 3, 7, 15, 10, 6, 8, 7};
	longest_increasing_subsequence_modified(a, Len(a));
}

int main()
{
	test_lis();
	test_lis_modified();

	return 0;
}