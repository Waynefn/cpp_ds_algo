#include <bits/stdc++.h>

using namespace std;

/***************************************
问题7->堆排序

***************************************/
#define A (2*i+1)
#define I (a[k] < a[k+1])
#define U (i = k)

#define E (i = m-1)
#define O (i >= 0)
#define KA (m-1)

#define KI (f2(a, m))
#define KU (swap(a, 0, m-1))
#define KE (0)

#define Len(x)	sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void swap(int a[], int i, int j)
{
	int k;
	k = a[i];
	a[i] = a[j];
	a[j] = k;
}

void f1(int a[], int i, int j)
{
	int k;
	while((k = A) <= j)
	{
		if(k < j && I)	
			k++;
		if(a[i] >= a[k])
			break;
		swap(a, i, k);
		U;						
	}
}

void f2(int a[], int m)
{
	int i;
	for(E; O; i--)
		f1(a, i, KA);
}

void f3(int a[], int m)
{
	KI;
	while(m > 1)
	{
		KU;
		f1(a, KE, m-2);
		m--;
	}
}

int main()
{
	int a[] = {5,6,7,4,3,1,0,2};
	f3(a, Len(a));
	PRINT_ARRAY(a, Len(a));

	return 0;
}