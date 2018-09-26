#include <bits/stdc++.h>

using namespace std;

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void swap(int x, int y, int key[], int label[])
{
	int temp;
	temp = key[x];
	key[x] = key[y];
	key[y] = temp;

	temp = label[x];
	label[x] = label[y];
	label[y] = temp;
}

void sort_1(int a, int b, int key[], int label[])
{
	int i, j, skip = 1;
	for(i = a; i < b; i++)
	{
		skip = b-i;
		for(j = b; j > i; j--)
		{
			if(key[j] < key[j-1])
			{
				swap(j, j-1, key, label);
				skip = j-1;
			}
		}
		PRINT_ARRAY(key, 12);
		PRINT_ARRAY(label, 12);
	}
}

void sort_2(int a, int b, int key[], int label[])
{
	int i, j, skip = 1;
	for(i = b; i > a; i--)
	{
		skip = b-i;
		for(j = a+1; j <= i; j++)
		{
			if(key[j] < key[j-1])
			{
				swap(j, j-1, key, label);
				skip = j-1;
			}
		}
		PRINT_ARRAY(key, 12);
		// PRINT_ARRAY(label, 12);
	}
}

void sort_3(int a, int b, int key[], int label[])
{
	int i, j, skip = 1;
	for(i = a; i < b; i+=skip)
	{
		skip = b-i;
		for(j = b; j > i; j--)
		{
			if(key[j] < key[j-1])
			{
				swap(j, j-1, key, label);
				skip = j-i;
			}
		}
		cout<<skip<<endl;
	}
}

int main()
{
	int key[] = {1,1,2,5,4,5,2,6,3,4,3,6};
	int label[] = {1,2,2,2,1,1,1,2,2,2,2,2};
	int n = 12;
	
	// sort_1(0, n-1, key, label);
	// sort_2(0, n-1, key, label);
	sort_3(0, n-1, key, label);
	return 0;
}