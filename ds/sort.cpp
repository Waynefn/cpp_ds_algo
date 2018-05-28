#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "utils.h"

using namespace std;

/*
	1.bubble
	2.Insert
	3.Select
	4.Shell
	5.Quick
	6.Merge
	7.Heap
	8.Bucket
	9.Sleep
*/

/**********************************************	
冒泡排序
	lv1:无论数组排序如何,都完整地冒泡直至结束
	lv2:每一轮冒泡时记录[最后发生大小交换的位置],假如第一轮发现数组在a[x]之后都是有序的,则下一轮只冒泡到下标x
**********************************************/
void Bubble1(int a[], int n)
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

void Bubble2(int a[], int n)
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
	Bubble1(a1, Len(a1));
	PRINT_ARRAY(a1, Len(a1));
	
	Bubble2(a2, Len(a2));
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
void Insert(int a[], int n)
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
	Insert(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
选择排序
	1.每一轮从[start]到[end]遍历,找到最小值的下标,保存到min
	2.a[min]与a[start]交换,保证每一轮总是能够找到当前区间的最小值,并把它移动到最前面
	3.start+1,直至start==end,结束
**********************************************/
void Select(int a[], int n)
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
	Select(a, Len(a));
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
void Shell(int a[], int n)
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
	Shell(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
快速排序
**********************************************/
void QuickSub(int a[], int s, int e)
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

	QuickSub(a, s, i-1);
	QuickSub(a, i+1, e);
}

void Quick(int a[], int n)
{
	QuickSub(a, 0, n-1);
}

void test_quick()
{
	PRINT_FUNCTION_NAME;

	int a[] = {49,38,65,97,26,13,27,49,55,4};
	Quick(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
归并排序
**********************************************/
void Merge_MergeArray(int a[], int s, int m, int e, int p[])
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

void Merge_Divide(int a[], int s, int e, int p[])
{
	if(s < e)
	{
		int m = (s + e) / 2;
		Merge_Divide(a, s, m, p);
		Merge_Divide(a, m+1, e, p);
		Merge_MergeArray(a, s, m, e, p);
	}
}

void Merge(int a[], int n)
{
	int *p = new int[n];
	Merge_Divide(a, 0, n-1, p);
}

void test_merge()
{
	PRINT_FUNCTION_NAME;

	int a[] = {49,38,65,97,26,13,27,49,55,4};
	Merge(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
堆排序
Heap1() : 借助额外的数组
Heap2() : 数组自身完成堆排
**********************************************/
void Heap1_Up(int hp[], int add)
{
	int i = ++hp[0];

	for(; i > 1 && hp[i/2] > add; i /= 2)
		hp[i] = hp[i/2];
	hp[i] = add;
}

int Heap1_Down(int hp[])
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

void Heap1(int a[], int n)
{
	int *hp = new int[n+1];
	hp[0] = 0;

	for(int i = 0; i < n; i++)
		Heap1_Up(hp, a[i]);
	for(int i = 0; i < n; i++)
		a[i] = Heap1_Down(hp);
}

void Heap2_Up(int a[], int idx)
{
	int i = idx, add = a[idx];
	for(; i && add > a[(i-1)/2]; i = (i-1)/2)
		a[i] = a[(i-1)/2];
	a[i] = add;
}

void Heap2_Down(int a[], int last)
{
	int curr = a[last];
	SWAP(a[0], a[last]);

	int i = 0, child, smallest = 0;
	for(; i < last; i = child)
	{
		child = 2*i+1;
		if(child+1 < last && a[child] < a[child+1])
			child++;
		if(child < last && curr < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = curr;
}

void Heap2(int a[], int n)
{
	for(int i = 0; i < n; i++)
		Heap2_Up(a, i);
	for(int i = n; i > 0; i--)
		Heap2_Down(a, i-1);
}

void test_heap()
{
	PRINT_FUNCTION_NAME;

	int a[] = {7,6,5,4,3,2,1};
	// Heap1(a, Len(a));
	Heap2(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
桶排序
**********************************************/
void Bucket(int a[], int n, int max)
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
	Bucket(a, Len(a), 9);
	PRINT_ARRAY(a, Len(a));
}

/**********************************************	
睡觉排序
**********************************************/
void *Sleep_Worker(void *arg)
{
	int time = *(int *)arg;
	usleep(time*1000);
	cout<<time<<" ";
}

void Sleep(int a[], int n)
{
	pthread_t td[100];
	for(int i = 0; i < n; i++)
		pthread_create(&td[i], NULL, Sleep_Worker ,(void *)&a[i]);
	for(int i = 0; i < n; i++)
		pthread_join(td[i], NULL);
	cout<<endl;
}

void test_sleep()
{
	PRINT_FUNCTION_NAME;

	int a[] = {4,5,65,77,23,54,2,9,2,3,7,10};
	Sleep(a, Len(a));
}

int main()
{
	test_bubble();
	test_insert();
	test_shell();
	test_quick();
	test_merge();
	test_heap();
	test_bucket();
	test_sleep();
	return 0;
}