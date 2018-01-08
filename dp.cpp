#include <iostream>
#include <stack>
#include <string.h>

#include "utils.h"

using namespace std;

#define MAX (20)
/*
	1.一维dp
		1.1 组成数组n有多少种方式
		1.2 tri tiling
	2.二维dp
		2.1 LCS(Longest common subsequence)
	3.区间动态规划 interval dp
		3.1 组成回文串的最小添加字符数
	4.子集和(subset sum)
	4.01背包

*/

/**********************************************
	1.1 组成数组n有多少种方式(by 1,3,4)
**********************************************/
void sum_n(int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int d[20] = {0};
	d[0] = d[1] = d[2] = 1; d[3] = 2;

	for(int i = 4; i <= n; i++)
		d[i] = d[i-1] + d[i-3] + d[i-4];
	cout<<"d["<<n<<"] = "<<d[n]<<endl;
}

/**********************************************
	1.2 tri tiling
**********************************************/
void tri_tiling(int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int f[20] = {0}, g[10] = {0};
	f[0] = 1, f[1] = 0;
	g[0] = 0, g[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		f[i] = f[i-2] + 2*g[i-1];
		g[i] = f[i-1] + g[i-2];
	}
	cout<<"f["<<n<<"] = "<<f[n]<<endl;
}

void test_1_dim()
{
	sum_n(6);
	tri_tiling(8);
}

/**********************************************
	2.1 LCS(Longest common subsequence)
		x:ABCBDAB
		y:BDCABC
		LCS = 4 -> BCBA,BCAB,BDAB
	** 尚未引入flag[][]，无法正确显示所有LCS结果
**********************************************/
void longest_common_subsequence_result(int d[MAX][MAX], char x[], int i, char y[], int j)
{
	while(i && j)
	{
		if(x[i-1] == y[j-1])		// 当前末尾字符相等，则属于LCS结果，输出它
		{
			cout<<x[i-1]<<"-";		// *但d也会被输出
			i--,j--;
		}
		else
		{
			if(d[i-1][j] > d[i][j-1])		// 找到相对大的上一层子问题
				i--;
			else if(d[i-1][j] < d[i][j-1])	// 找到相对大的上一层子问题
				j--;
			else							// 两个子问题相等，则递归去寻找所有可能性
			{
				longest_common_subsequence_result(d, x, i-1, y, j);
				longest_common_subsequence_result(d, x, i, y, j-1);
				return;
			}
		}
	}
}

void longest_common_subsequence(char x[], char y[])
{
	PRINT_SUB_FUNCTION_NAME;

	int len_x = strlen(x);
	int len_y = strlen(y);
	int d[MAX][MAX];

	for(int i = 0; i <= len_x; i++)
		d[i][0] = 0;
	for(int j = 0; j <= len_x; j++)
		d[0][j] = 0;

	// [i][0]和[0][j]是留给初始状态的，计算f时i和j要从下标1开始，但字符串首字符下标为x[0]和y[0]
	for(int i = 1; i <= len_x; i++)
		for(int j = 1; j <= len_y; j++)
			if(x[i-1] == y[j-1])	d[i][j] = d[i-1][j-1] + 1;
			else					d[i][j] = max(d[i-1][j], d[i][j-1]);

	cout<<"LCS["<<x<<"]["<<y<<"] = "<<d[len_x][len_y]<<endl;

#ifdef DEBUG_LOG
	PRINT_MATRIX(d, len_x+1, len_y+1);
#endif

	longest_common_subsequence_result(d, x, len_x, y, len_y); cout<<endl;
}

/**********************************************
	2.2 LCS(Longest common substring)
		x:ABCFBC
		y:ABFCAB
		LCS = 2 -> AB
**********************************************/
void longest_common_substring_result(int d[MAX][MAX], char x[], char y[], int p, int q)
{
	stack<char> ret;

	while(p && q)
	{
		if(x[p-1] == y[q-1])	// 从记录的最长子串的末为字符p和q开始，向左边倒推
		{
			ret.push(x[p-1]);
			p--,q--;
		}
		else					// 一旦发现字符不再匹配，说明字串结束
			break;
	}

	while(!ret.empty())
	{
		char c = ret.top(); ret.pop();
		cout<<c<<"-";
	}cout<<endl;
}

void longest_common_substring(char x[], char y[])
{
	PRINT_SUB_FUNCTION_NAME;

	int len_x = strlen(x);
	int len_y = strlen(y);
	int d[MAX][MAX];
	int p,q;

	for(int i = 0; i <= len_x; i++)
		d[i][0] = 0;
	for(int j = 0; j <= len_y; j++)
		d[0][j] = 0;

	int curr_max = -1;
	for(int i = 1; i <= len_x; i++)
	{
		for(int j = 1; j <= len_y; j++)
		{
			if(x[i-1] == y[j-1])
				d[i][j] = d[i-1][j-1] + 1;
			else
				d[i][j] = 0;	// 一旦不匹配就归零，接下来重新计算
			if(d[i][j] > curr_max)
			{
				curr_max = d[i][j];
				p = i, q = j;	// 记录最长子串的末尾，输出时往前倒推即可得到结果
			}
		}
	}
	cout<<"LCS["<<x<<"]["<<y<<"] = "<<curr_max<<endl;

	longest_common_substring_result(d, x, y, p, q);
}

void test_2_dim()
{
	longest_common_subsequence("ABCBDAB", "BDCABC");
	longest_common_substring("ABCBDAB", "BDCABC");
}

/**********************************************
	3.1 组成回文串的最小添加字符数
**********************************************/
void create_palindrome(char str[])
{
	PRINT_SUB_FUNCTION_NAME;

	int len = strlen(str);
	int d[MAX][MAX];

	for(int i = 0; i <= len; i++)
	{
		d[i][i] = 0;
		d[i+1][i] = 0;
	}

	for(int t = 1; t < len; t++)
	{
		for(int i = 0, j = t; j < len; i++,j++)
		{
			if(str[i] == str[j])
				d[i][j] = d[i+1][j-1];
			else
				d[i][j] = 1 + min(d[i+1][j], d[i][j-1]);
		}
	}

	PRINT_MATRIX(d, len, len);
//	cout<<d[0][len-1]<<endl;
}

void test_create_palindrome()
{
	create_palindrome("Ab3bd");
}

/**********************************************
	子集和(subset sum)
	d[i][j] = true : a[0]~a[i-1]存在几个元素能组合得到k
		case1:不包含a[i-1]元素，则d[i][j] == d[i-1][j]
		case2:包含a[i-1]元素，则d[i][j] == d[i-1][j-a[i-1]]

**********************************************/
void subset_sum(int a[], int n, int k)
{
	PRINT_SUB_FUNCTION_NAME;

	bool d[MAX][MAX];

	for(int i = 0; i <= n; i++)
		d[i][0] = true;
	for(int j = 1; j <= k; j++)	// 注意：j从1开始置false，不要写成j=0
		d[0][j] = false;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(a[i-1] > j)		// a[i-1]已大于目标j，直接舍弃
				d[i][j] = d[i-1][j];
			if(a[i-1] <= j)		// a[i-1]不大于目标j，舍弃or包含a[i-1]元素
				d[i][j] = d[i-1][j] || d[i-1][j-a[i-1]];
		}
	}

#ifdef DEBUG_LOG
	PRINT_MATRIX(d, n+1, k+1);
#endif

	cout<<d[n][k]<<endl;
}

void test_subset_sum()
{
	int a[] = {8,2,4};
	int k = 10;
	subset_sum(a, Len(a), k);
}
/**********************************************
	4.01背包
**********************************************/
void packing_01_result(int d[MAX][MAX], int w[], int v[], int n, int c)	// n = item_num, c = capacity
{
	if(n < 0)
		return;

	if(d[n][c] == d[n-1][c])
		packing_01_result(d, w, v, n-1, c);
	else
	{
		if(w[n] <= c 
		&& d[n][c] == v[n] + d[n-1][c-w[n]])
		{	
			cout<<"物品"<<n<<", 剩余空间"<<c-w[n]<<endl;
			packing_01_result(d, w, v, n-1, c-w[n]);
		}
	}
}

void packing_01(int w[], int v[], int item_num, int capacity)
{
	PRINT_SUB_FUNCTION_NAME;

	int d[MAX][MAX]; bzero(d, sizeof(d));
	
	for(int i = 1; i <= item_num; i++)
		for(int j = 1; j <= capacity; j++)
			if(w[i] <= j)	// 当前物品i的重量w[i]小于背包容量j，可以放入
				d[i][j] = max(d[i-1][j],d[i-1][j-w[i]]+v[i]);
			else			// 当前背包放不下物品i
				d[i][j] = d[i-1][j];

#ifdef DEBUG_LOG	
	PRINT_MATRIX(d, item_num+1, capacity+1);
#endif

	cout<<"d["<<item_num<<"]["<<capacity<<"] = "<<d[item_num][capacity]<<", 包含:"<<endl;
	packing_01_result(d, w,v,item_num,capacity);
}

void packing_01_improve(int w[], int v[], int item_num, int capacity)
{
	PRINT_SUB_FUNCTION_NAME;

	int d[MAX]; bzero(d, sizeof(d));

	for(int i = 1; i <= item_num; i++)
	{
		for(int j = capacity; j > 0; j--)
			if(w[i] <= j)	// 当前物品i的重量w[i]小于背包容量j，可以放入
				d[j] = max(d[j], d[j-w[i]]+v[i]);

#ifdef DEBUG_LOG
		PRINT_ARRAY(d, capacity+1);
#endif
	}

	cout<<"d["<<capacity<<"] = "<<d[capacity]<<endl;
}

void test_package()
{
	int item_num = 4;
	int capacity = 8;
	int w[5] = {0,2,3,4,5};
	int v[5] = {0,3,4,5,6};

	packing_01(w, v, item_num, capacity);
	packing_01_improve(w, v, item_num, capacity);
}

int main()
{
	test_1_dim();
	test_2_dim();
	test_create_palindrome();
	test_subset_sum();
	test_package();

	return 0;
}