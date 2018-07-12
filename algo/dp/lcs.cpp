#include <iostream>
#include <stack>
#include <string.h>

#include "utils.h"

using namespace std;

/**********************************************
	LCS(Longest common subsequence)
		x:ABCBDAB
		y:BDCABC
		LCS = 4 -> BCAB,BDAB
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
	LCS(Longest common substring)
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

#ifdef DEBUG_LOG
	PRINT_MATRIX(d, len_x+1, len_y+1);
#endif

	longest_common_substring_result(d, x, y, p, q);
}

void test_lcs()
{
	longest_common_subsequence("ABCBDAB", "BDCABC");
	longest_common_substring("ABCBDAB", "BDCABC");
}

int main()
{
	test_lcs();

	return 0;
}