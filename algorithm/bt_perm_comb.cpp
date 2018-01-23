#include<iostream>  

#include "utils.h"

using namespace std;

#define MAX (20)

/**********************************************
排列 permute
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

}
**********************************************/

void perm(int a[], int k, int n)
{
	if(k == n-1)	// k已经是数组最后一个元素，即到了解空间的叶子节点  
	{
		PRINT_ARRAY(a,n);
	}     
	else   
	{
		for(int i = k; i < n; i++)  //从k开始时保证交换和递归次数     
		{  
			SWAP(a[i], a[k]);   //第一次 自己和自己交换即自己是最前单一前缀   交换单一前缀和后缀中的每一个元素 ，让每一个元素都可以做前缀  
			perm(a, k+1, n);  
			SWAP(a[i], a[k]);  //回溯之后  仍然恢复交换以前的顺序  
		}  
	}  
}

void test_perm()
{
	int a[]={0,1,2};

    perm(a, 0, Len(a));
}

int main()
{
	test_perm();

	return 0;
}