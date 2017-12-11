#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "utils.h"

using namespace std;

/*
	1.bubble
	2.insert
	3.select
	4.shell
	5.quick
	6.merge
	7.heap
	8.bucket
	9.sleep
*/

/**********************************************	
冒泡排序
	lv1:无论数组排序如何,都完整地冒泡直至结束
	lv2:每一轮冒泡时记录[最后发生大小交换的位置],假如第一轮发现数组在a[x]之后都是有序的,则下一轮只冒泡到下标x
**********************************************/
void bubble_lv1(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int cnt = 0;

	for(int i = n; i > 1; i--)
		for(int j = 1; j < i; j++)
		{
			cnt++;
			if(a[j-1] > a[j])
			{
				
				SWAP(a[j-1], a[j]);
			}
		}

	cout<<"lv1 cnt = "<<cnt<<endl;
}

void bubble_lv2(int a[], int n)
{
	PRINT_SUB_FUNCTION_NAME;

	int cnt = 0;
	int end = n;
	while(end)
	{
		int curr_end = end;
		end = 0;

		for(int j = 1; j < curr_end; j++)
		{
			cnt++;
			if(a[j-1] > a[j])
			{
				end = j;
				SWAP(a[j-1], a[j]);
			}
		}
	}
	cout<<"lv2 cnt = "<<cnt<<endl;
}

void test_bubble()
{
	PRINT_FUNCTION_NAME;

	int a1[] = {1,1,0,0,3,4,5,2,2,0};
	int a2[] = {1,1,0,0,3,4,5,2,2,0};
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

	int a[] = {49,38,65,97,26,13,27,49,55,4};
	insert(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
选择排序
	1.每一轮从[start]到[end]遍历,找到最小值的下标,保存到min
	2.a[min]与a[start]交换,保证每一轮总是能够找到当前区间的最小值,并把它移动到最前面
	3.start+1,直至start==end,结束
**********************************************/
void select(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i; j < n; j++)
			if(a[min] < a[j])
				min = j;
		SWAP(a[i], a[min]);
	}
}

void test_select()
{
	PRINT_FUNCTION_NAME;

	int a[] = {49,38,65,97,26,13,27,49,55,4};
	select(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
希尔排序
	类似于插入排序,在发现a[j-1]>a[j]时,就不断往前移动直至找到合适的位置
	但希尔排序是[分阶段地做插入排序]
	e.g:
		1.数组分为4段,[1]与[3],[2]与[4]做插入排序
		2.[1][2][3][4]合起来再做完整的插入排序
**********************************************/
void shell(int a[], int n)
{
	for(int gap = n/2; gap > 0; gap /= 2)
	{
		for(int i = gap; i < n; i++)
		{
			if(a[i-gap] > a[i])
			{
				int tmp = a[i], j;
				for(j = i; j >= gap && a[j-gap] > tmp; j -= gap)
					a[j] = a[j-gap];
				a[j] = tmp;
			}
		}
	}
}

void test_shell()
{
	PRINT_FUNCTION_NAME;

	int a[] = {5,4,6,2,1,3,7,9};
	shell(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
快速排序
**********************************************/
void sub_quick(int a[], int s, int e)
{
	if(s >= e)
		return;

	int i = s, j = e, x = a[s];
	while(i < j)
	{
		while(i < j && a[j] > x)	j--;
		if(i < j)	a[i++] = a[j];
		while(i < j && a[i] < x)	i++;
		if(i < j)	a[j--] = a[i];	
	}
	a[i] = x;

	sub_quick(a, s, i-1);
	sub_quick(a, i+1, e);
}

void quick(int a[], int n)
{
	sub_quick(a, 0, n-1);
}

void test_quick()
{
	PRINT_FUNCTION_NAME;

	int a[] = {49,38,65,97,26,13,27,49,55,4};
	quick(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
归并排序
**********************************************/
void merge_array(int a[], int s, int m, int e, int p[])
{
	int i = s, j = m+1, k = 0;

	while(i <= m && j <= e)
	{
		if(a[i] < a[j]) p[k++] = a[i++];
		else			p[k++] = a[j++];
	}
	while(i <= m)		p[k++] = a[i++];
	while(j <= e)		p[k++] = a[j++];

	for(i = 0; i < k; i++)
		a[s+i] = p[i];
}

void divide(int a[], int s, int e, int p[])
{
	if(s < e)
	{
		int m = (s + e) / 2;
		divide(a, s, m, p);
		divide(a, m+1, e, p);
		merge_array(a, s, m, e, p);
	}
}

void merge(int a[], int n)
{
	int *p = new int[n];
	divide(a, 0, n-1, p);
}

void test_merge()
{
	PRINT_FUNCTION_NAME;

	int a[] = {49,38,65,97,26,13,27,49,55,4};
	merge(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
堆排序
**********************************************/
void heap_up(int hp[], int add)
{
	int i = ++hp[0];

	for(; i > 1 && hp[i/2] > add; i /= 2)
		hp[i] = hp[i/2];
	hp[i] = add;
}

int heap_down(int hp[])
{
	int ret = hp[1], last = hp[hp[0]--];
	int child, i;

	for(i = 1; i*2 <= hp[0]; i = child)
	{
		child = 2*i;
		if(child+1 <= hp[0] && hp[child+1] < hp[child])
			child++;
		if(last < hp[child])
			break;
		else
			hp[i] = hp[child];
	}
	hp[i] = last;

	return ret;
}

void heap(int a[], int n)
{
	int *hp = new int[n+1];
	hp[0] = 0;

	for(int i = 0; i < n; i++)
		heap_up(hp, a[i]);
	PRINT_ARRAY(hp, n+1);
	for(int i = 0; i < n; i++)
		a[i] = heap_down(hp);
}

void test_heap()
{
	PRINT_FUNCTION_NAME;

	int a[] = {5,3,6,7,8,2,1};
	heap(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
桶排序
**********************************************/
void bucket(int a[], int n, int max)
{
    int *buf = new int[max];

    for(int i = 0; i < n; i++) 
        buf[a[i]]++; 

    for (int i = 0, j = 0; i < max; i++) 
        while((buf[i]--))
            a[j++] = i;

    delete[] buf;
}

void test_bucket()
{
	PRINT_FUNCTION_NAME;

	int a[] = {4,5,1,3,8,4,2,8,9};
	bucket(a, Len(a), 9);
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
睡觉排序
**********************************************/
void *worker(void *arg)
{
	int time = *(int *)arg;
	usleep(time*1000);
	cout<<time<<" ";
}

void sleep(int a[], int n)
{
	pthread_t td[100];
	for(int i = 0; i < n; i++)
		pthread_create(&td[i], NULL, worker ,(void *)&a[i]);
	for(int i = 0; i < n; i++)
		pthread_join(td[i], NULL);
	cout<<endl;
}

void test_sleep()
{
	PRINT_FUNCTION_NAME;

	int a[] = {4,5,65,77,23,54,2,9,2,3,7,10};
	sleep(a, Len(a));
}

int main()
{
	// test_bubble();
	// test_insert();
	 test_shell();
	// test_quick();
	// test_merge();
	// test_heap();
	// test_bucket();
	// test_sleep();
	return 0;
}