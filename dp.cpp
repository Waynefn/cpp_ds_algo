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
	2.01背包

*/

/**********************************************
	1.1 组成数组n有多少种方式(by 1,3,4)
**********************************************/
void sum_n(int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int f[20] = {0};
	f[0] = f[1] = f[2] = 1; f[3] = 2;

	for(int i = 4; i <= n; i++)
		f[i] = f[i-1] + f[i-3] + f[i-4];
	cout<<"f["<<n<<"] = "<<f[n]<<endl;
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
void longest_common_subsequence_result(int f[MAX][MAX], char x[], int i, char y[], int j)
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
			if(f[i-1][j] > f[i][j-1])		// 找到相对大的上一层子问题
				i--;
			else if(f[i-1][j] < f[i][j-1])	// 找到相对大的上一层子问题
				j--;
			else							// 两个子问题相等，则递归去寻找所有可能性
			{
				longest_common_subsequence_result(f, x, i-1, y, j);
				longest_common_subsequence_result(f, x, i, y, j-1);
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
	int f[MAX][MAX];

	for(int i = 0; i <= len_x; i++)
		f[i][0] = 0;
	for(int j = 0; j <= len_x; j++)
		f[0][j] = 0;

	// [i][0]和[0][j]是留给初始状态的，计算f时i和j要从下标1开始，但字符串首字符下标为x[0]和y[0]
	for(int i = 1; i <= len_x; i++)
		for(int j = 1; j <= len_y; j++)
			if(x[i-1] == y[j-1])	f[i][j] = f[i-1][j-1] + 1;
			else					f[i][j] = max(f[i-1][j], f[i][j-1]);

	cout<<"LCS["<<x<<"]["<<y<<"] = "<<f[len_x][len_y]<<endl;

#ifdef DEBUG_LOG
	PRINT_MATRIX(f, len_x+1, len_y+1);
#endif

	longest_common_subsequence_result(f, x, len_x, y, len_y); cout<<endl;
}

/**********************************************
	2.2 LCS(Longest common substring)
		x:ABCFBC
		y:ABFCAB
		LCS = 2 -> AB
**********************************************/
void longest_common_substring_result(int f[MAX][MAX], char x[], char y[], int p, int q)
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
	int f[MAX][MAX];
	int p,q;

	for(int i = 0; i <= len_x; i++)
		f[i][0] = 0;
	for(int j = 0; j <= len_y; j++)
		f[0][j] = 0;

	int curr_max = -1;
	for(int i = 1; i <= len_x; i++)
	{
		for(int j = 1; j <= len_y; j++)
		{
			if(x[i-1] == y[j-1])
				f[i][j] = f[i-1][j-1] + 1;
			else
				f[i][j] = 0;	// 一旦不匹配就归零，接下来重新计算
			if(f[i][j] > curr_max)
			{
				curr_max = f[i][j];
				p = i, q = j;	// 记录最长子串的末尾，输出时往前倒推即可得到结果
			}
		}
	}
	cout<<"LCS["<<x<<"]["<<y<<"] = "<<curr_max<<endl;

	longest_common_substring_result(f, x, y, p, q);
}

void test_2_dim()
{
	longest_common_subsequence("ABCBDAB", "BDCABC");
	longest_common_substring("ABCBDAB", "BDCABC");
}

/**********************************************
	2.01背包
**********************************************/
void packing_01_result(int f[MAX][MAX], int w[], int v[], int n, int c)	// n = item_num, c = capacity
{
	if(n < 0)
		return;

	if(f[n][c] == f[n-1][c])
		packing_01_result(f, w, v, n-1, c);
	else
	{
		if(w[n] <= c 
		&& f[n][c] == v[n] + f[n-1][c-w[n]])
		{	
			cout<<"物品"<<n<<", 剩余空间"<<c-w[n]<<endl;
			packing_01_result(f, w, v, n-1, c-w[n]);
		}
	}
}

void packing_01(int w[], int v[], int item_num, int capacity)
{
	PRINT_SUB_FUNCTION_NAME;

	int f[MAX][MAX]; bzero(f, sizeof(f));
	
	for(int i = 1; i <= item_num; i++)
		for(int j = 1; j <= capacity; j++)
			if(w[i] <= j)	// 当前物品i的重量w[i]小于背包容量j，可以放入
				f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
			else			// 当前背包放不下物品i
				f[i][j] = f[i-1][j];

#ifdef DEBUG_LOG	
	PRINT_MATRIX(f, item_num+1, capacity+1);
#endif

	cout<<"f["<<item_num<<"]["<<capacity<<"] = "<<f[item_num][capacity]<<", 包含:"<<endl;
	packing_01_result(f, w,v,item_num,capacity);
}

void packing_01_improve(int w[], int v[], int item_num, int capacity)
{
	PRINT_SUB_FUNCTION_NAME;

	int f[MAX]; bzero(f, sizeof(f));

	for(int i = 1; i <= item_num; i++)
	{
		for(int j = capacity; j > 0; j--)
			if(w[i] <= j)	// 当前物品i的重量w[i]小于背包容量j，可以放入
				f[j] = max(f[j], f[j-w[i]]+v[i]);

#ifdef DEBUG_LOG
		PRINT_ARRAY(f, capacity+1);
#endif
	}

	cout<<"f["<<capacity<<"] = "<<f[capacity]<<endl;
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
	test_package();

	return 0;
}