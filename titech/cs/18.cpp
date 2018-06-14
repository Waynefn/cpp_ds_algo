/*
http://www.cs.titech.ac.jp/H18-gozen.pdf
问题7：快速排序
*/

#include<iostream>  

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int comp(int a, int b)
{
	if(a < b)	return 1;
	else 		return 0;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b; *b = t;
}

/**********************************************
	冒泡
**********************************************/
void sort1(int a[], int n)
{
	int i, j;
	for(i = 0; i < n-1; i++)
		for(j = n-1; j > i; j--)
			if(comp(a[j], a[j-1]))
				swap(&a[j], &a[j-1]);
}

/**********************************************
	快排
**********************************************/
int partition(int a[], int l, int r)
{
	int i, j, pv;
	i = l-1; j = r;
	pv = a[r];

	while(1)
	{
		while(comp(a[++i], pv));
		while(i < --j && comp(pv, a[j]));
		if(i >= j)
			break;
		swap(&a[i], &a[j]);
	}
	swap(&a[i], &a[r]);
	return i;
}

void sort2_i(int a[], int l, int r)
{
	int v;
	if(l >= r)
		return;
	v = partition(a, l ,r);
	sort2_i(a, l, v-1);
	sort2_i(a, v+1, r);
}

void sort2(int a[], int n)
{
	sort2_i(a, 0, n-1);
}

void test_quick()
{
	int a[] = {1,5,8,7,3,2,9,6,4};
	// sort1(a, Len(a));
	sort2(a, Len(a));
	PRINT_ARRAY(a, Len(a));
}

int main()
{
	test_quick();

	return 0;
}