#include <iostream>
#include <string.h>

#include "utils.h"

using namespace std;

#define MAX (10)

int f[MAX][MAX];

void packing_01_result(int w[], int v[], int n, int c)	// n = item_num, c = capacity
{
	if(n < 0)
		return;

	if(f[n][c] == f[n-1][c])
		packing_01_result(w,v,n-1,c);
	else
	{
		if(w[n] <= c 
		&& f[n][c] == v[n] + f[n-1][c-w[n]])
		{	
			cout<<"物品"<<n<<", 剩余空间"<<c-w[n]<<endl;
			packing_01_result(w,v,n-1,c-w[n]);
		}
	}
}

void packing_01(int w[], int v[], int item_num, int capacity)
{
	PRINT_SUB_FUNCTION_NAME;

	bzero(f, sizeof(f));
	
	for(int i = 1; i <= item_num; i++)
		for(int j = 1; j <= capacity; j++)
			if(w[i] <= j)	// 当前物品i的重量w[i]小于背包容量j，可以放入
				f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
			else			// 当前背包放不下物品i
				f[i][j] = f[i-1][j];
	
	for(int i = 1; i <= item_num; i++)
	{
		for(int j = 1; j <= capacity; j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}

	cout<<"f["<<item_num<<"]["<<capacity<<"] = "<<f[item_num][capacity]<<", 包含:"<<endl;
	packing_01_result(w,v,item_num,capacity);
}

void packing_01_modify(int w[], int v[], int item_num, int capacity)
{
	PRINT_SUB_FUNCTION_NAME;

	int f[MAX]; bzero(f, sizeof(f));

	for(int i = 1; i <= item_num; i++)
	{
		for(int j = capacity; j > 0; j--)
			if(w[i] <= j)	// 当前物品i的重量w[i]小于背包容量j，可以放入
				f[j] = max(f[j], f[j-w[i]]+v[i]);

		for(int k = 1; k <= capacity; k++)
			cout<<f[k]<<" ";
		cout<<endl;
	}
	
}

void test_dp()
{
	int item_num = 4;
	int capacity = 8;
	int w[5] = {0,2,3,4,5};
	int v[5] = {0,3,4,5,6};

	packing_01(w, v, item_num, capacity);
	packing_01_modify(w, v, item_num, capacity);
}

int main()
{
	test_dp();

	return 0;
}