#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}
#define SWAP(x, y)	{int c = x; x = y; y = c;	}

void up(int a[], int idx)
{
	int i = idx, add = a[idx];
	for(; i && add > a[(i-1)/2]; i = (i-1)/2)
		a[i] = a[(i-1)/2];
	a[i] = add;
}

void down(int a[], int last)
{
	int curr = a[last];
	SWAP(a[0], a[last]);

	int i = 0, child, smallest = 0;
	for(; i < last; i = child)
	{
		child = 2*i+1;
		if(child+1 < last && a[child] < a[child+1])
			child++;
		if(child < last && curr < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = curr;
}

void heap(int a[], int n)
{
	for(int i = 0; i < n; i++)
		up(a, i);
	for(int i = n; i > 0; i--)
		down(a, i-1);
	PRINT_ARRAY(a, n);
}

int main()
{
	int a[] = {5,6,4,3,2,7,8,6,0};
	heap(a, Len(a));

	return 0;
}