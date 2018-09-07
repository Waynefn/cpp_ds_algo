#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
	快排-递归实现
**********************************************/
void Quick_r_sub(int a[], int s, int e)
{
	if(s >= e)
		return;

	int i = s, j = e, x = a[s];
	while(i < j)
	{
		while(i < j && a[j] > x)	j--;
		if(i < j)	a[i++] = a[j];
		while(i < j && a[i] < x)	i++;
		if(i < j)	a[j--] = a[i];	
	}
	a[i] = x;

	Quick_r_sub(a, s, i-1);
	Quick_r_sub(a, i+1, e);
}

void Quick_r(int a[], int n)
{
	Quick_r_sub(a, 0, n-1);
}

/**********************************************	
	快排-非递归实现
**********************************************/
void Quick(int a[], int n)
{
	
}

int main()
{
	int a[] = {49,38,65,97,26,13,27,49,55,4};
	Quick_r(a, Len(a));
	PRINT_ARRAY(a, Len(a));

	return 0;
}