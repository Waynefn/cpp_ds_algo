/*
http://www.ist.osaka-u.ac.jp/japanese/admission/docs/H27nyuusimonndai%E3%80%80jyouhokougaku.pdf
	问题1->二分搜索
	问题2->动态规划背包
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++) cout<<a[i][j]<<"|"; cout<<endl;}}

/***************************************
问题1->二分搜索
***************************************/
void bs()
{
	// int A[]
}

/***************************************
问题2->01背包
***************************************/
void knapsack(int sz[], int val[], int n, int c)
{
	int d[n+1][c+1];
	int i, j, max, index;
	for(i = 0; i <= n; i++)
		for(j = 0; j <= c; j++)
			d[i][j] = -1;
	d[0][0] = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j <= c; j++)
		{
			if(d[i-1][j] != -1)
			{
				if(d[i-1][j] > d[i][j]) 
					d[i][j] = d[i-1][j];
				if(j + sz[i] <= c)
					d[i][j+sz[i]] = d[i-1][j] + val[i];
			}
		}
	}
	PRINT_MATRIX(d, n+1, c+1);
	max = 0, index = 0;
	for(j = 0; j <= c; j++)
		if(d[n][j] > max)
			{max = d[n][j]; index = j;}
	for(i = n; i >= 1; i--)
	{
		if(index >= sz[i] && d[i][index]-val[i] == d[n-1][index-sz[i]])
		{
			cout<<"add ["<<i<<"] = "<<val[i]<<" in knapsack"<<endl;
			index -= sz[i];
		}
	}
	cout<<"result = "<<max<<endl;
}

void Q2()
{
	int sz[] = {0, 2, 6, 6, 2};
	int val[] = {0, 20, 30, 15,25};
	knapsack(sz, val, 4, 15);
}

int main()
{
	Q2();

	return 0;
}