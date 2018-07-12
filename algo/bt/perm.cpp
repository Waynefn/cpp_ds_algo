#include<iostream>  

#include "utils.h"

using namespace std;

/**********************************************
全排列问题
{1,2,3}
	1,{2,3}
		1,2,{3}
		1,3,{2}
	2,{1,3}
		2,1,{3}
		2,3,{1}
	3,{1,2}
		3,1,{2}
		3,2,{1}
**********************************************/
void perm_1(int a[], int n, int curr, int tmp[], int label[])
{
	if(curr >= n)
	{
		PRINT_ARRAY(tmp, n);
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(!label[i])
			{
				tmp[curr] = a[i];
				label[i] = true;
				perm_1(a, n, curr+1, tmp, label);
				label[i] = false;
			}
		}
	}
}

void perm_2(int a[], int n, int curr)
{
	if(curr >= n)  
	{
		PRINT_ARRAY(a,n);
	}
	else
	{
		for(int i = curr; i < n; i++)	//从k开始时保证交换和递归次数     
		{  
			SWAP(a[i], a[curr]);	// curr为0时,跟所有其他元素交换,即所有元素都有机会当前缀
			perm_2(a, n, curr+1);  
			SWAP(a[i], a[curr]);	// 回溯到之前的状态,交换过的数据也要还原  
		}  
	}
}

void test_perm()
{
	int a[] = {0,1,2};
	int tmp[MAX];
    int label[MAX] = {false};
    perm_1(a, Len(a), 0, tmp, label);
    cout<<"----------------------"<<endl;
    perm_2(a, Len(a), 0);
}

int main()
{
	test_perm();

	return 0;
}