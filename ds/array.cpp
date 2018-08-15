#include <iostream>

#include "utils.h"

using namespace std;

/***************************************
	提供两个有序数组a[]和b[]，将他们整合到一个新的有序数组
***************************************/
void Array_Merge(int a[], int m, int b[], int n, int c[], int o)
{
	if(o < m+n)
		return;

	int i = 0, j = 0, k = 0;
	while(i < m && j < n)
	{
		if(a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	while(i < m)
		c[k++] = a[i++];
	while(j < n)
		c[k++] = b[j++];
}

/***************************************
	提供任意数组a[]，将所有元素逆置
***************************************/
void Array_Reverse(int a[], int n)
{
	int s = 0, e = n-1;
	while(s < e)
	{
		SWAP(a[s], a[e]);
		s++; e--;
	}
}

/***************************************
	提供有序数组a[], 删除数组中所有为x的元素
***************************************/
void Array_Delete(int a[], int n, int x)
{
	PRINT_SUB_FUNCTION_NAME;

	NULL_CHK(a);

	int k = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
			k++;
		else
			a[i-k] = a[i];
	}

	PRINT_ARRAY(a, n);
	for(int i = n-k; i < n; i++)
		a[i] = -1;

	PRINT_ARRAY(a, n);
}

/***************************************
	提供有序数组a[],如果元素重复则删掉重复的部分，使所有元素唯一
***************************************/
void Array_DeleteRepeat(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	NULL_CHK(a);

	int i = 0, j = 1;
	for(; j < n; j++)
	{
		if(a[i] != a[j])
			a[++i] = a[j];
	}

	for(int k = i+1; k < n; k++)
		a[k] = -1;

	PRINT_ARRAY(a, n);
}

void test_array_merge()
{
	PRINT_FUNCTION_NAME;

	int a[4] = {1,3,5,7};
	int b[5] = {2,4,6,8,10};
	int c[20] = {};
	Array_Merge(a, Len(a), b, Len(b), c, Len(c));
}

void test_array_reverse()
{
	PRINT_FUNCTION_NAME;

	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	Array_Reverse(a, Len(a));
}

void test_array_delete()
{
	PRINT_FUNCTION_NAME;

	int a[10] = {1,2,2,3,4,5,5,6,7,7};
	Array_Delete(a, Len(a), 2);
}

void test_array_delete_repeat()
{
	PRINT_FUNCTION_NAME;
	
	int a[10] = {1,1,2,2,2,3,4,5,5,6};
	Array_DeleteRepeat(a, Len(a));
}

int main()
{
	test_array_merge();
	test_array_reverse();
	test_array_delete();
	test_array_delete_repeat();

	return 0;
}