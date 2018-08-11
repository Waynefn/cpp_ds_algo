/*
http://www.iii.u-tokyo.ac.jp/manage/wp-content/uploads/2016/04/2014-A.pdf
问题2：确认是否存在过半元素，并找到
问题3：n个元素的数组，整体左移m（即右移n-m位）
	3-1 循环置换分解定理
		n个元素可以划分为gcd(n,m) = g个子群，元素移动仅限于子群内部移动
			group0:[0][0+m]...[0+k*m]
			group1:[1][1+m]...[1+k*m]
			......
			groupg:[g-1][g-1+m]...[g-1+k*m]
	3-2	分段置换

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void f1(int n, int *x, int m)
{
	int g,i,j,k,t;
	g = __gcd(m,n);
	for(i = 0; i < g; i++)
	{
		t = x[i];
		j = i;
		for(;;)
		{
			k = (j + m) % n;
			if(k == i)
				break;
			x[j] = x[k];
			j = k;
		}
		x[j] = t;
		PRINT_ARRAY(x, n);
	}
}

// a[i] ~ a[j] 之间元素逆置
void f2(int *x, int i, int j)
{
	int t;
	while(i < j)
	{
		t = x[i]; x[i] = x[j]; x[j] = t;
		i++;j--;
	}
}

void f3(int n, int *x, int m)
{
	f2(x, 0, m-1);
	f2(x, m, n-1);
	f2(x, 0, n-1);
}

void Q3()
{
	int x[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int n = 12;
	int m = 9;
	PRINT_ARRAY(x, n);
	f3(n,x,m);	PRINT_ARRAY(x, n);

}

int main()
{
	Q3();

	return 0;
}
