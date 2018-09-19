#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
	归并排序-递归实现
**********************************************/
void Merge_MergeArray(int a[], int s, int m, int e, int p[])
{
	int i = s, j = m+1, k = 0;

	while(i <= m && j <= e)
	{
		if(a[i] < a[j]) p[k++] = a[i++];
		else			p[k++] = a[j++];
	}
	while(i <= m)		p[k++] = a[i++];
	while(j <= e)		p[k++] = a[j++];

	for(i = 0; i < k; i++)
		a[s+i] = p[i];
}

void Merge_r_sub(int a[], int s, int e, int p[])
{
	if(s < e)
	{
		int m = (s + e) / 2;
		Merge_r_sub(a, s, m, p);
		Merge_r_sub(a, m+1, e, p);
		Merge_MergeArray(a, s, m, e, p);
	}
}

void Merge_r(int a[], int n)
{
	int *p = new int[n];
	Merge_r_sub(a, 0, n-1, p);
}

int main()
{
	int a[] = {49,38,65,97,26,13,27,49,55,4};
	Merge_r(a, Len(a));
	PRINT_ARRAY(a, Len(a));

	return 0;
}