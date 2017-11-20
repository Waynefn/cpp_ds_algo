/*
http://www.ist.osaka-u.ac.jp/japanese/admission/docs/H27nyuusimonndai%E3%80%80jyouhokougaku.pdf
	问题1->二分搜索
	问题2->动态规划背包
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->二分搜索,动态规划背包
	1-3. if(a[mid] < x) left = mid+1
	变成了 if(a[mid] < x) left = mid
	如例子中的数组,搜索不存在的数字9时,会造成死循环
***************************************/
#define N (8)

int binary_search(int a[], int n, int x)
{
	int mid, left, right, index;

	left = 1;
	right = n;
	do{
		mid = (left + right) / 2;
		if(a[mid] < x)	left = mid+1;
		else			right = mid-1;
	}while(a[mid] != x && left <= right);

	if(a[mid] == x) index = mid;
	else			index = 0;

	return index;
}

void test_question_1()
{
	int a[N+1] = {0,2,5,8,10,15,20,25,30};
	cout<<"search result : "<<binary_search(a, N, 9)<<endl;
}

/***************************************
问题1->动态规划背包
	2-1
	0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
	0 -1 20 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
	0 -1 20 -1 -1 -1 30 -1 50 -1 -1 -1 -1 -1 -1 -1 
	0 -1 20 -1 -1 -1 30 -1 50 -1 -1 -1 45 -1 65 -1 
	0 -1 25 -1 45 -1 30 -1 55 -1 75 -1 45 -1 70 -1
	对于s[4][2]从20变为25,是因为同样的空间2,放item1只有价值20,而当放item4时价值提高为25
***************************************/

#define capacity 	(15)
#define item		(4)

void dp()
{
	int size[] = {0,2,6,6,2};
	int value[] = {0,20,30,15,25};
	int sack[item+1][capacity+1];
	int i, j, max, index;

	for(i = 0; i <= item; i++)
		for(j = 0; j <= capacity; j++)
			sack[i][j] = -1;
	sack[0][0] = 0;

	for(i = 1; i <= item; i++)
	{
		for(j = 0; j <= capacity; j++)
		{
			if(sack[i-1][j] != -1)
			{
				if(sack[i-1][j] > sack[i][j])	sack[i][j] = sack[i-1][j];	// 初始化数据为-1,都小于[0][0]的0
				if(j + size[i] <= capacity)		sack[i][j+size[i]] = sack[i-1][j] + value[i]; //如果i商品放得下,则放入背包再说
			}
		}
	}

	for(i = 0; i <= item; i++)
	{
		for(j = 0; j <= capacity; j++)
			cout<<sack[i][j]<<" ";
		cout<<endl;
	}

	max = 0; index = 0;
	for(j = 0; j <= capacity; j++)
	{
		if(sack[item][j] > max)
		{
			max = sack[item][j];
			index = j;
		}
	}
	// for(i = item; i >= 1; i--)
	// {
	// 	if(index >= size[i] &&  == )
	// 	{
	// 		cout<<"item "<<i<<" is in a knapsack"<<endl;
	// 		index = index - size[i];
	// 	}
	// }
} 

void test_question_2()
{
	dp();
}

int main()
{
	test_question_1();
	test_question_2();

	return 0;
}