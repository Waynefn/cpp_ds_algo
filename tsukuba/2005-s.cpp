/*
http://www.cs.tsukuba.ac.jp/admission/19-8infj.pdf
	问题1->描述最短路径
	问题2->离代码求完全数
*/

#include <iostream>

using namespace std;

/**********************************************
问题2->离代码求完全数
**********************************************/
#define N (1000)

// 输出数字n的所有正的约数
void divisor(int n)
{
	for(int i = 1; i < n; i++)
		if(n%i == 0)
			cout<<i<<endl;
}

// 如果数字n的所有约数之和等于自身，则返回1
int is_perfect(int n)
{
	int i, sum;
	if(n <= 0)		return 0;
		
	sum = 0;
	for(i = 1; i < n; i++)
		if(n%i == 0)
			sum += i;

	if(sum == n)	return 1;
	else			return 0;	
}

// 输出1000以内的完全数
void test_question_1()
{
	int i, j, sum[N+1];

	for(i = 1; i <= N; i++)
		sum[i] = 0;

	for(j = 1; j <= N/2; j++)
		for(i = 1; i <= N; i++)
			if(i > j && i%j == 0)
				sum[i] += j;

	for(i = 1; i <= N; i++)
		if(sum[i] == i)
			cout<<i<<" ";
	cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}
