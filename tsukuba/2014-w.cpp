#include <bits/stdc++.h>

using namespace std;

/***************************************
问题1->冒泡，归并排序
***************************************/
#define A 	r-j+m+1

#define SIZE (5)
#define Len(x)	sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void sort(int data[], int size)
{
	int i, j, t;
	for(i = 0; i < size; i++)
	{
		PRINT_ARRAY(data, 5);
		for(j = i+1; j < size; j++)
		{
			if(data[i] > data[j])
			{
				t = data[i];
				data[i] = data[j];
				data[j] = t;
			}
		}
	}
}

int b[SIZE];
void sortsub(int a[], int l, int r)
{
	int i, j, k, m;
	if(l < r)
	{
		m = (l+r)/2;
		sortsub(a,l,m);
		sortsub(a,m+1,r);
		
		for(i = l; i <= m; i++)	
			b[i] = a[i];
		for(j = m+1; j <= r; j++)
			b[A] = a[j];

		i = l; j = r;
		for(k = l; k <= r; k++)
		{
			if(b[i] < b[j])
				a[k] = b[i++];
			else
				a[k] = b[j--];
		}
	}
}

void sort_2(int data[], int size)
{
	sortsub(data, 0, size-1);
}

int main()
{
	// int array[SIZE] = {0,1,3,1,5};
	int array[SIZE] = {5,3,7,8,1};
	sort_2(array, SIZE);

	PRINT_ARRAY(array, Len(array));

	return 0;
}