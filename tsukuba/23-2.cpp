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
	if(n > 0 && b[n] < b[(n-1)/2])
	{
		swap(b[(n-1)/2], b[n]);
		shift_up(b, (n-1)/2);
	}
}

/*
	1.每一轮down结束后，末尾元素移动到此时左右子树都维持堆特性
*/
void shift_down(int b[], int i, int size)
{
	int left = 2*i+1, right = 2*i+2;	// coding
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
	//	cout<<"swap前: ";print_array(a, n);
		swap(a[0], a[n-i-1]);			// coding 每一轮把当前[0 ~ n-i-1]范围内最小值a[0]换到末尾a[n-i-1]位置
	//	cout<<"swap后: ";print_array(a, n);
		shift_down(a, 0, n-i-1);		// coding 此时末尾数据从a[0]位置down,注意第一轮找到了数组的最小值放到了a[n-1]位置不能再移动,所以第二轮只能移动到a[n-1]
	//	cout<<"shift_down后: ";print_array(a, n);
	}
	print_array(a, n);
}

void test_question_1()
{
	int a[] = {1,5,3,5,7,9,7,6,10,8};

	sort2(a, Len(a));
}

int main()
{
	test_question_1();

	return 0;
}