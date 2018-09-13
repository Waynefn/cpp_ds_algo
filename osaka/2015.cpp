/*
http://www.ist.osaka-u.ac.jp/japanese/admission/docs/28nenndo%20jyouhoukougaku.pdf
	问题1->基数排序
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->基数排序
	1.算法中,[个位]和[十位]的排序都在同一个二维数组中进行,所以非常容易填错
		d=1结束后
			0  0 0  0 0
			21 1 11 0 0
			12 2 0  0 0
		d=2结束后
			1  2  0  0 0
			11 12 11 0 0
			21 2  0  0 0
		注意:d=2结束后,buckets[2][2]仍旧为2没有被清理,利用numbucket来防止访问到它
***************************************/

#define MAXR (256)		// 最大进制
#define MAXN (1000)		// 最大数

/*
	values[]:待排序数组
	numvalues:数组元素个数
	r:进制
	maxdigit:最高位(个十百千)
*/

void sort(int values[], int numvalues, int r, int maxdigit)
{
	int rd, d, b, i, n, j;
	int buckets[MAXR][MAXN];
	int numbucket[MAXR];

	rd = 1;
	for(d = 1; d <= maxdigit; d++)
	{
		for(b = 0; b < r; b++)
			numbucket[b] = 0;						// 每次排序前,桶内无任何数据
		for(i = 0; i < numvalues; i++)
		{
			n = (values[i] / rd) % r;				// 计算当前位数的值为n
			buckets[n][numbucket[n]++] = values[i];	// 下标为n的桶内放数据,同时桶n的数据个数+1
		}

		i = 0;
		for(b = 0; b < r; b++)
			for(j = 0; j < numbucket[b]; j++)		// 本轮在b桶内放了多少个数字,values才会取多少数字
				values[i++] = buckets[b][j];

		rd *= r;	// 从低位到高位进行基数排序

		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 5; j++)
				cout<<buckets[i][j]<<" ";
			cout<<endl;
		}cout<<endl;
	}
}

void test_question_1()
{
	int i;
	int values[5] = {12, 21, 1, 11, 2};

	sort(values, 5, 10, 2);

	for(i = 0; i < 5; i++)
		cout<<values[i]<<" ";
	cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}