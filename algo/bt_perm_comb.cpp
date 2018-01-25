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

void perm(int a[], int n, int curr)
{
	if(curr == n-1)	// curr已经是数组最后一个元素，即到了解空间的叶子节点  
	{
		PRINT_ARRAY(a,n);
	}     
	else   
	{
		for(int i = curr; i < n; i++)  //从k开始时保证交换和递归次数     
		{  
			SWAP(a[i], a[curr]);   //第一次 自己和自己交换即自己是最前单一前缀   交换单一前缀和后缀中的每一个元素 ，让每一个元素都可以做前缀  
			perm(a, n, curr+1);  
			SWAP(a[i], a[curr]);  //回溯之后  仍然恢复交换以前的顺序  
		}  
	}  
}

void test_perm()
{
	int a[] = {0, 1, 2};

    perm(a, Len(a), 0);
}

int main()
{
	test_perm();

	return 0;
}