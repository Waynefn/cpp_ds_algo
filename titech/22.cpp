/*
http://www.cs.titech.ac.jp/H22-gozen.pdf
问题7：n个数中，取k个数的组合
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
	return comb_1(n-1, k) + comb_1(n-1, k-1);
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

// int comb2(int n, int k)
// {
// 	int i, j;
// 	if(n >= 2*k)
// 	{
// 		i = n-k+1;
// 		j = k;
// 	}
// 	else
// 	{
// 		i = k+1;
// 		j = n-k;
// 	}
// 	return
// }

void test_comb()
{
	cout<<comb_1(5, 3)<<endl;
}

int main()
{
	test_comb();

	return 0;
}