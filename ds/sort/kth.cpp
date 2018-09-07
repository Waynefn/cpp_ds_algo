#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************	
	第k大数-快排实现
**********************************************/
void Quick_K_r(int a[], int s, int e, int k)
{
	if(s > e)
		return;
	int i = s, j = e, x = a[s];
	while(i < j)
	{
		while(i < j && x < a[j])	j--;
		if(i < j)					a[i++] = a[j];
		while(i < j && x > a[i])	i++;
		if(i < j)					a[j--] = a[i];
	}
	a[i] = x;
	if(k-1 < i)
		Quick_K_r(a, 0, i-1, k);
	else if(k-1 > i)
		Quick_K_r(a, i+1, e, k);
	else
		cout<<"NO."<<k<<" = "<<a[i]<<endl;
}

void Quick_K(int a[], int n, int k)
{
	Quick_K_r(a, 0, n-1, k);
}

int main()
{
	int a[] = {8,2,5,9,3,4,1,7};
	PRINT_ARRAY(a, Len(a));
	Quick_K(a, Len(a), 1);
	Quick_K(a, Len(a), 2);
	Quick_K(a, Len(a), 3);
	Quick_K(a, Len(a), 4);
	Quick_K(a, Len(a), 5);
	Quick_K(a, Len(a), 6);
	return 0;
}