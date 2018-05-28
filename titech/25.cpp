/*
http://www.cs.titech.ac.jp/H25-gozen.pdf
问题7：堆排序
1:
	a) n = 2^(h+1) - 1
	b) left = i*2+1 right = i*2+2
	c) max:a[0] min:
2:	大堆
	f1(a,0,8) -> down操作
	f2(a, n)  -> up操作构造堆
	f3(a, n)  -> 数组进行升序排列
*/

#include<iostream>  

using namespace std;

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void swap(int a[], int i, int j)
{
	int k;
	k = a[i];
	a[i] = a[j];
	a[j] = k;
}

// f1(a, 0, last) -> down
void f1(int a[], int i, int j)
{
	int k;
	while((k = 2*i+1) <= j)			// coding
	{
		if(k < j && a[k] < a[k+1])	// coding
			k++;
		if(a[i] >= a[k])
			break;
		swap(a, i, k);
		i = k;						// coding
	}
}

void f2(int a[], int m)
{
	int i;
	for(i = m-1; i >= 0; i--)	// coding
		f1(a, i, m-1);			// coding
}

void f3(int a[], int m)
{
	f2(a, m);				// coding
	while(m > 1)
	{
		swap(a, 0, m-1);	// coding
		f1(a, 0, m-2);
		m--;				// coding
	}
}

void test_heap()
{
	int a[] = {5,6,7,4,3,1,0,2};
	int n = sizeof(a)/sizeof(a[0]);

	f3(a, n);
	PRINT_ARRAY(a, n);
}

int main()
{
	test_heap();

	return 0;
}