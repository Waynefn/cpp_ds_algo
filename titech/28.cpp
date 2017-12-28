/*
https://www.titech.ac.jp/graduate_school/admissions/pdf/cs_h28.pdf
问题3->subset sum problem
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	

int f(int a[], int n, int k, int s, int i)
{
	if(i == n)
	{
		cout<<"----"<<endl;
		return s == k;
	}
	else
	{
		cout<<"++++"<<endl;
		return f(a, n, k, s, i+1) || f(a, n, k, s+a[i], i+1);
	}
}

void test_1()
{
	int a[] = {8,2,4};
	int k = 7;
	cout<< f(a, Len(a), k, 0, 0);

}

int main()
{
	test_1();

	return 0;
}