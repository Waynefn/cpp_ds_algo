/*
http://www.cs.tsukuba.ac.jp/admission/26-8inf.pdf
	问题1->快排
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->快排
	1.递归
	2.每一轮swap后array内的数字，以及最终结果写出来
	3.给出一个array的数字，可以swap最小次数
		排序好的数组?? [0,1,1,3,4]
	4.f1换成冒泡排序的代码
***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])
#define SIZE (6)

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void swap(int *a, int *b)
{
	int c;
	c = *a; *a = *b; *b = c;
}

void f2(int data[], int s, int e)
{
	int i = s, j = e, p;

	if(i >= j)
		return;

	p = data[s];
	while(1)
	{
		while(data[i] < p) i++;
		while(data[j] > p) j--;
		if(i >= j)
			break;
		swap(&data[i], &data[j]);
		i++;
		j--;
	}
	print_array(data, SIZE);
	f2(data, s, i-1);
	f2(data, j+1, e);
}

void f1(int data[], int size)
{
	f2(data, 0, size-1);
}

void f1_bubble(int data[], int size)
{
	int i, j;
	for(i = 0; i < size-1; i++)
		for(j = 1; j < size-i; j++)		// coding
			if(data[j-1] > data[j])
				swap(&data[j-1], &data[j]);
}

void test_question_1()
{
	int i;

//	int array[SIZE] = {0,1,3,1,4};
	int array[SIZE] = {3,4,6,1,2,5};

	f1(array, SIZE);
	print_array(array, SIZE);
}

int main()
{
	test_question_1();

	return 0;
}