#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SWAP(x, y)	{int c = x; x = y; y = c;	}
#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void move(int a[], int n, int m)
{
	int g = __gcd(m,n);
	for(int i = 0; i < g; i++)
	{
		int tmp = a[i];
		int end = i, next;
		while(1)
		{
			next = (i+m)%n;
			if(next == end)
				break;
			a[end] = a[next];
			end = next;
		}
		a[next] = tmp;
	}
}

int main()
{
	int a[] = {0,1,2,3,4,5,6};
	move(a, Len(a), 2);
	PRINT_ARRAY(a, Len(a));

	return 0;
}