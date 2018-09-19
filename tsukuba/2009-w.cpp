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
#define A 	a[j] < w
#define B 	last-1
#define C 	p >= first
#define D 	p--
#define E 	a[p+1]
#define F 	d
#define G 	k+1
#define H 	n-d+1
#define I 	i+d
#define J 	i
#define K 	a[j] < w
#define L 	j+d
#define M 	2
#define N 	l >= 0
#define O 	l--

#define Len(x)	sizeof(x)/sizeof(x[0])

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void shift(int a[], int first, int last)
{
	for(int p = B; C; D)
		E = a[p];
}

void insertion_sort(int a[], int n)
{
	int w,i,j;
	if(n <= 1)
		return;

	for(i = 1; i < n; i++)
	{
		w = a[i];
		for(j = 0; j < i && A; j++)
			continue;
		shift(a, j, i);
		a[j] = w;
	}
	print_array(a, n);
}

void shift_d(int a[], int first, int last, int d)
{
	for(int p = last-d; p >= first; p -= d)
		a[p+d] = a[p];
}

void insertion_sort_d(int a[], int n, int d)
{
	int w,i,j,k;
	if(n <= d)
		return;
	for(k = 0; k < F; k = G)
	{
		for(i = d+k; i < H; i = I)	// * i<=n-d必须包含等于，i才能取得当前gap轮次的最后一个数据
		{
			w = a[i];
			for(j = k; j < J && K; j = L)
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
	for(l = M; N; O)
		insertion_sort_d(a, n, dim[l]);
	print_array(a, n);
}

void test_question_1()
{
	int a[] = {80,35,15,40,65};
	insertion_sort(a, Len(a));
	int b[] = {8,3,6,4,2,5,1,7};
	shell_sort(b, Len(b));
}

int main()
{
	test_question_1();

	return 0;
}