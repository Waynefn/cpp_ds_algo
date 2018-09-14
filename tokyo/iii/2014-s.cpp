/*
问题2：决策树，选硬币
问题3：a数组最大k个数保存到b数组
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void f1(int a[], int na, int b[], int nb)
{
	int i,j,k;
	for(i = 0; i < na; i++)
	{
		for(j = nb-1; j >= 0; j--)
			if(b[j] > a[i])
				break;

		if(j < nb-1)
		{
			for(k = nb-2; k > j; k--)
				b[k+1] = b[k];
			b[k+1] = a[i];
		}
	}
	PRINT_ARRAY(b, nb);
}

void Q3()
{
	int a[] = {2,17,12,4,6,19,10,13,12,7};
	int b[] = {0,0,0,0,0};
	f1(a, Len(a), b, Len(b));
}

int main()
{
	Q3();
	return 0;
}