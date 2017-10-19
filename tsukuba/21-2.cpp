/*
http://www.cs.tsukuba.ac.jp/admission/21-2inf.pdf
	问题1->插入排序,希尔排序
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->插入排序,希尔排序

***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void shift(int a[], int first, int last)
{
	for(int p = last-1; p >= first; p--) 	// coding
		a[p+1] = a[p];						// coding
}

void insertion_sort(int a[], int n)
{
	int w,i,j;
	if(n <= 1)
		return;

	for(i = 1; i < n; i++)
	{
		cout<<"i = "<<i<<"--> "; print_array(a, n);
		w = a[i];
		for(j = 0; j < i && a[j] < w; j++)
			continue;
		shift(a, j, i);
		a[j] = w;
	}
	print_array(a, n);
}

void test_question_1()
{
	int a[] = {4,5,1,2,3,9};
	insertion_sort(a, Len(a));
}

int main()
{
	test_question_1();

	return 0;
}