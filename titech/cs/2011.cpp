/*
http://www.cs.titech.ac.jp/H23-gozen.pdf
问题7：回溯算法，排列问题perm，n皇后问题
*/

#include<iostream>  

using namespace std;

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int a[1024];

/**********************************************
	1. perm
**********************************************/
int check_1(int x, int y)
{
	for(int k = 0; k < x; k++)
		if(a[k] == y)
			return 0;
	return 1;
}

void f_1(int n, int x)
{
	if(x >= n)
	{
		PRINT_ARRAY(a, n);
	}
	else
	{
		int y = 0;
		while(y < n)
		{
			if(check_1(x, y))
			{
				a[x] = y;
				f_1(n, x+1);
			}
			y = y + 1;
		}
	}
}

void test_1_perm()
{
	f_1(3, 0);
}

/**********************************************
	2. n queen
**********************************************/
int cnt = 0;

int check_2(int x, int y)
{
	for(int k = 0; k < x; k++)
	{
		if(a[k] == y
		|| a[k] == y+x-k	// coding
		|| a[k] == y-x+k)	// coding
			return 0;
	}
	return 1;
}

void f_2(int n, int x)
{
	if(x >= n)
	{
		PRINT_ARRAY(a, n);
	}
	else
	{
		int y = 0;
		while(y < n)
		{
			if(check_2(x, y))
			{
				a[x] = y;
				f_2(n, x+1);
			}
			y = y + 1;
		}
	}
}

void f_3(int n, int x)
{
	int y = 0;
	while(1)
	{
		while(y < n)
		{
			if(check_2(x, y))
			{
				a[x] = y;
				x++;
				if(x >= n)
				{
					PRINT_ARRAY(a, n);
					goto backtrack;
				}
				y = 0;		// coding
			}
			else
				y++;
		}
		backtrack:
		{
			x--;
			if(x < 0)
				return;
			y = a[x] + 1;	// coding
		}
	}
}

void test_2_n_queen()
{
	f_2(5, 0);
	f_3(5, 0);
}

int main()
{
//	test_1_perm();
	test_2_n_queen();
	return 0;
}