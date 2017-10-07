#include <iostream>

#include "main.h"

using namespace std;

/*
	提供两个有序数组a[]和b[]，将他们整合到一个新的有序数组
*/
void array_merge2Array(int a[], int m, int b[], int n, int res[], int res_size)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(a);
	NULL_CHK(b);
	NULL_CHK(res);

	if(res_size < m+n)
		cout<<"size not enough"<<endl;

	int i = 0, j = 0, k = 0;
	while(i < m && j < n)
	{
		if(a[i] < b[j])
		{
			res[k] = a[i];
			k++; i++;
		}
		else
		{
			res[k] = b[j];
			k++; j++;
		}
	}

	while(i < m)
	{
		res[k] = a[i];
		k++; i++;
	}
	while(j < n)
	{
		res[k] = b[j];
		k++; j++;
	}

	print_array(res, k);
}

/*
	提供任意数组a[]，将所有元素逆置
*/

void array_reverse(int a[], int n)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(a);

	int s = 0, e = n-1;
	while(s < e)
	{
		SWAP(a[s], a[e]);
		s++; e--;
	}

	print_array(a, n);
}

/*
	提供有序数组a[], 删除数组中所有为x的元素
*/

void array_deleteX(int a[], int n, int x)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(a);

	int k = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
			k++;
		else
			a[i-k] = a[i];
	}

	print_array(a, n);
	for(int i = n-k; i < n; i++)
		a[i] = -1;

	print_array(a, n);
}

/*
	提供有序数组a[],如果元素重复则删掉重复的部分，使所有元素唯一
*/
void array_deleteRepeat(int a[], int n)
{
	PRINT_FUNCTION_NAME;
	
	NULL_CHK(a);

	int i = 0, j = 1;
	for(; j < n; j++)
	{
		if(a[i] != a[j])
			a[++i] = a[j];
	}

	for(int k = i+1; k < n; k++)
		a[k] = -1;

	print_array(a, n);
}
