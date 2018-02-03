/*
	最长增长子序列 Longest Increasing Subsequence
	dp1:O(n^2)
		dp[i]：a[0]~a[i-1]的最长增长子序列(不是子串,不要求连续性)
		dp[i] = max{dp[j]} + 1 (a[i] > a[j] && j = 0 ~ i-1)
			 = 1			 (a[i] < a[j] && j = 0 ~ i-1)
		ret = max(dp[i])
*/

#include <iostream>
#include <string.h>

#include "utils.h"

using namespace std;

#define MAX (20)

void longest_increasing_subsequence(int a[], int n)
{
	int dp[MAX];
	int ret = 1;

	for(int i = 0; i < n; i++)
		dp[i] = 1;

	for(int i = 1; i < n; i++)
	{
		int curr_max = 0;
		for(int j = 0; j < i; j++)
			if(a[i] > a[j])
				curr_max = max(curr_max, dp[j]);

		dp[i] = curr_max+1;		// {2,3,9,1,6} a[4] > a[3],但curr_max = dp[1] = 2, 所以dp[4] = 3
		ret = max(ret, dp[i]);
	}

	PRINT_ARRAY(a, n);
	PRINT_ARRAY(dp, n);
	cout<<"ret = "<<ret<<endl;
}

void test_lis()
{
	int a[] = {1,3,6,7,9,4,10,5,6};

	longest_increasing_subsequence(a, Len(a));
}

int main()
{
	test_lis();
	return 0;
}