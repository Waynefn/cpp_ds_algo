#include<iostream>  

#include "utils.h"

using namespace std;

void power_set(int a[], int n, int curr, bool label[])
{
	if(curr >= n)
	{
		for(int i = 0; i < n; i++)
			if(label[i])
				cout<<a[i]<<"|";
		cout<<endl;
	}
	else
	{
		label[curr] = true;
		power_set(a, n, curr+1, label);
		label[curr] = false;
		power_set(a, n, curr+1, label);
	}
}

void test_power_set()
{
	int a[] = {0,1,2};
	bool label[MAX] = {false};
	power_set(a, Len(a), 0, label);
}

int main()
{
	test_power_set();

	return 0;
}