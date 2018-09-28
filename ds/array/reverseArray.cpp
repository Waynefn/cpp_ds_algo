#include <bits/stdc++.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define SWAP(x, y)	{int c = x; x = y; y = c;	}
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************
    数组元素翻转
    1,5,2,4,8 --> 8,4,2,5,1
**********************************************/
void ReverseArray(int a[], int n)
{
	int s = 0, e = n-1;
	while(s < e)
	{
		SWAP(a[s], a[e]);
		s++; e--;
	}
}

int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};

	PRINT_ARRAY(a, Len(a));
	ReverseArray(a, Len(a));
	PRINT_ARRAY(a, Len(a));
	return 0;
}