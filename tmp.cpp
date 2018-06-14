#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}
#define SWAP(x, y)	{int c = x; x = y; y = c;	}

void quick(int a[], int s, int e)
{
	if( s >= e)
		return;
	int x = a[s];
	int i = s, j = e;
	while(i < j)
	{
		while(i < j && a[j] > x) j--;
		if(i < j)	a[i++] = a[j];
		while(i < j && a[i] < x) i++;
		if(i < j)	a[j--] = a[i];
	}
	a[i] = x;
	quick(a, s, i-1);
	quick(a, i+1, e);
}

//大堆
void up(int p[], int add)
{
	int sz = ++p[0], i;
	for(i = sz; i > 1 && p[i/2] < add; i /= 2)
		p[i] = p[i/2];
	p[i] = add;
}

int down(int p[])
{
	int ret = p[0];
	int last = p[p[0]--];
	int child = 0, i;
	for(i = 1; i*2 < p[0]; i = child)
	{
		child = 2*i;
		if(child + 1 < p[0] && p[child+1] > p[child])
			child++;
		if(last < p[child])
			p[i] = p[child];
		else
			break;
	}
	p[i] = last;

	return ret;
}

void heap(int a[], int n)
{
	int *p = new int[n+1];
	p[0] = 0;
	for(int i = 0; i < n; i++)
		up(p, a[i]);
	for(int i = 0; i < n; i++)
		a[i] = down(p);
}

int main()
{
	int a[] = {1,5,8,7,3,2,9,6,4};
	int *p = new int[Len(a)];
	heap(a, Len(a));

	PRINT_ARRAY(a, Len(a));

	return 0;
}