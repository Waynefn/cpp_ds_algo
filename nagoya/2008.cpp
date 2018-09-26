#include <bits/stdc++.h>

using namespace std;

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/***************************************
	快排
***************************************/
bool compare(int *a, int *b)
{
	if(*a < *b)	return true;
	return false;
}

void quick_sort(int a[], int left, int right)
{
	int p, t;
	int i, j;

	p = a[(left+right)/2];
	i = left, j = right;
	while(i <= j)
	{
		while(a[i] < p) i++;
		while(p < a[j])	j--;
		if(i >= j)	break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++, j--;
	}
	cout<<"29行：";PRINT_ARRAY(a, 9);
	if(left < i-1)	quick_sort(a, left, i-1);
	cout<<"30行：";PRINT_ARRAY(a, 9);
	if(j+1 < right)	quick_sort(a, j+1, right);
}

int int_array[9] = {5,6,2,1,4,9,3,8,7};
int parray[9];

int main()
{
	int i;
	for(i = 0; i < 9; i++)
		parray[i] = int_array[i];
	quick_sort(parray, 0, 8);
	for(i = 0; i < 9; i++)
		cout<<parray[i]<<" ";
	cout<<endl;

	return 0;
}