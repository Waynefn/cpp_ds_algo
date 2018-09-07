#include <bits/stdc++.h>

using namespace std;

/**********************************************
    数组中，删除所有目标元素target
    1,2,2,3,4,5,5,6,7,7 （删2）--> 1,3,4,5,5,6,7,7
**********************************************/

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int DelTarget(int a[], int n, int x)
{
	int i = 0, k = 0;
	for(; i < n; i++)
	{
		if(a[i] == x)
			k++;
		else
			a[i-k] = a[i];
	}
	return i-k;
}

int main()
{
	int a[] = {1,2,2,3,4,5,5,6,7,7};

	PRINT_ARRAY(a, Len(a));
	int n = DelTarget(a, Len(a), 2);
	PRINT_ARRAY(a, n);
	return 0;
}