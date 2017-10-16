#include <iostream>

#include "utils.h"

using namespace std;

/**********************************************	
冒泡排序
	lv1:无论数组排序如何,都完整地冒泡直至结束
	lv2:每一轮冒泡时记录[最后发生大小交换的位置],假如第一轮发现数组在a[x]之后都是有序的,则下一轮只冒泡到下标x
**********************************************/
void bubble_lv1(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int cnt = 0;

	for(int i = n-1; i > 0; i--)
		for(int j = 0; j < i; j++)
		{
			cnt++;
			if(a[j] > a[j+1])
			{
				
				SWAP(a[j], a[j+1]);
			}
		}

	cout<<"bubble_lv1 cnt = "<<cnt<<endl;
}

void bubble_lv2(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int cnt = 0;
	int end = n-1;
	while(end)
	{
		int curr_end = end;
		end = 0;

		for(int j = 0; j < curr_end; j++)
		{
			cnt++;
			if(a[j] > a[j+1])
			{
				end = j;
				SWAP(a[j], a[j+1]);
			}
		}
	}
	cout<<"cnt = "<<cnt<<endl;
}

void test_bubble()
{
	PRINT_FUNCTION_NAME;

	int a1[] = {2,1,3,4,5,6,9};
	int a2[] = {2,1,3,4,5,6,9};
	bubble_lv1(a1, Len(a1));
	PRINT_ARRAY(a1, Len(a1));
	
	bubble_lv2(a2, Len(a2));
	PRINT_ARRAY(a2, Len(a2));
}

/**********************************************	
插入排序
	1.只有一个元素时无需比较
	2.从[1]到[n-1]遍历数组,一旦发现a[i-1] > a[i],说明a[i]需要被移动到更合适的位置
	3.保存当前需要被移动的数字tmp = a[i], j = i,j下标用来寻找合适的位置
		3.1 每一轮发现a[j-1] > tmp,则a[j] = a[j-1]来完成一个数字的移动
		3.2 直至发现a[j-1]不再大于tmp || j已经移动到a[0],结束移动
		3.3 已经找到了[合适的位置],令a[j] = tmp,完成本轮的移动
**********************************************/
void insert(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		if(a[i-1] > a[i])
		{
			int tmp = a[i], j;
			for(j = i; j > 0 && a[j-1] > tmp; j--)
				a[j] = a[j-1];
			a[j] = tmp;
		}
	}
}

void test_insert()
{
	PRINT_FUNCTION_NAME;

	int a1[] = {8,7,6,5,4,3,2,1,99};
	insert(a1, Len(a1));
	PRINT_ARRAY(a1, Len(a1));
}

int main()
{
	test_bubble();
	test_insert();
	return 0;
}