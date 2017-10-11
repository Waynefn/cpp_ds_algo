/*
http://www.cs.tsukuba.ac.jp/admission/23-2inf.pdf
	问题1->堆排序(有递归)
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->堆排序(有递归)
	1.填空用小堆完成降序排序
	void sort1(int a[], int n)
	{
		int i;
		heap_t heap = make_heap();
		for(i = 0; i < n; i++)
			heap_add(heap, a[i]);				// coding
		for(i = 0; i < n; i++)
			a[n-i-1] = heap_delete_min(heap);	// coding 注意降序
	}

	2.完成swap函数,shift_up函数
	3.完成shift_down函数
	4.不使用额外数组,数组内部实现堆排函数sort2
***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// coding
void shift_up(int b[], int n)
{
	if(n == 0)
		return;

	if(b[n/2] <= b[n])
		return;
	else
	{
		swap(b[n/2], b[n]);
		shift_up(b, n/2);
	}
}

void shift_down(int b[], int i, int size)
{
	int left = 2*i+1, right = left+1;	// coding
	int smallest = i;
	if(right < size && b[right] < b[smallest])				// coding
		smallest = right;
	if(left < size && b[left] < b[smallest])
		smallest = left;
	if(smallest != i)
	{
		swap(b[i], b[smallest]);		// coding
		shift_down(b, smallest, size);	
	}
}

void sort2(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		shift_up(a, i);				// coding

	print_array(a, n);
	for(i = 0; i < n; i++)
	{
		swap(a[i], a[n-1]);		// coding
		shift_down(a, 0, n-1);		// coding
	}
	print_array(a, n);
}

void test_question_1()
{
	int a[] = {5,6,4,2,1,9};

	sort2(a, Len(a));

}

int main()
{
	test_question_1();

	return 0;
}