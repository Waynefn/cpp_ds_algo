/*
http://www.cs.titech.ac.jp/H22-gozen.pdf
问题7：组合问题C(n,k)，杨辉三角
*/

#include<iostream>  

using namespace std;

#define MAX (20)

/**********************************************
	comb_1
**********************************************/
int comb_1(int n, int k)
{
	if(k == 0 || k == n)
		return 1;
	return comb_1(n-1, k) + comb_1(n-1, k-1);	// coding
}

/**********************************************
	comb_2
**********************************************/
int pf(int m, int n)
{
	int i, f;
	f = 1;
	for(i = m; i <= n; i++)
		f = f*i;
	return f;
}

int comb_2(int n, int k)
{
	int i, j;
	if(n >= 2*k)
	{
		i = n-k+1;
		j = k;
	}
	else
	{
		i = k+1;
		j = n-k;
	}
	return pf(i, n) / pf(1, j);	// coding
}

/**********************************************
	comb_3
**********************************************/
int comb_3(int n, int k)
{
	int i, j;
	int a[MAX];

	if(n - k < k)	k = n-k;
	if(k == 0)		return 1;
	if(k == 1)		return n;

	for(i = 0; i < k; i++)
		a[i] = i + 2;
	for(i = 3; i <= n-k+1; i++)		// coding
	{
		a[0] = i;
		for(j = 1; j < k; j++)
			a[j] += a[j-1];
	}

	return a[k-1];	// coding
}

void test_comb()
{
	cout<<"comb_1 :"<<comb_1(5, 3)<<endl;
	cout<<"comb_2 :"<<comb_2(7, 3)<<endl;
	cout<<"comb_3 :"<<comb_3(7, 4)<<endl;
}

int main()
{
	test_comb();

	return 0;
}