#include <iostream>
#include <string.h>

#include "utils.h"

using namespace std;

#define MAX (20)

/**********************************************
	01背包
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
	test_package();

	return 0;
}