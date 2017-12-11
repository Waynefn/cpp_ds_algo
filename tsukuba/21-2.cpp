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
//		cout<<"i = "<<i<<"--> "; print_array(a, n);
		w = a[i];
		for(j = 0; j < i && a[j] < w; j++)
			continue;
		shift(a, j, i);
		a[j] = w;
	}
	print_array(a, n);
}

void shift_d(int a[], int first, int last, int d)
{
	for(int p = last-d; p >= first; p -= d) 	// coding
		a[p+d] = a[p];							// coding
}

void insertion_sort_d(int a[], int n, int d)
{
	int w,i,j,k;

	if(n <= d)
		return;

	for(k = 0; k < d; k++)
	{
		for(i = d+k; i <= n-d; i+=d)	// * i<=n-d必须包含等于，i才能取得当前gap轮次的最后一个数据
		{
			w = a[i];
			for(j = k; j < i && a[j] < w; j += d)
				continue;
			shift_d(a,j,i,d);
			a[j] = w;
		}
	}
}

int dim[] = {1,2,4};
void shell_sort(int a[], int n)
{
	int l;
	for(l = 2; l >= 0; l--)
		insertion_sort_d(a, n, dim[l]);
	print_array(a, n);
}

void test_question_1()
{
	int a[] = {7,6,5,4,3,2,1,8};
	insertion_sort(a, Len(a));
	int b[] = {7,6,5,4,3,2,1,8};
	shell_sort(b, Len(b));
}

int main()
{
	test_question_1();

	return 0;
}