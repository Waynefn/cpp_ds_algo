/*
http://www.cs.tsukuba.ac.jp/admission/18-2infj.pdf
	问题1->树的前序&后序遍历/祖先关系
	问题2->快速阶乘算法
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题2->快速阶乘算法

***************************************/
#define A 	n % 2
#define B 	z *= z;

#define pi 3.1415926

double factorial(int n)
{
	int tmp = n;
	double ret = 1;
	while(tmp > 1)
	{
		ret *= tmp;
		tmp--;
	}

	return ret;
}

double power(double x, int n)
{
	double y, z;
	y = 1.0;
	z = x;

	while(n > 0)
	{
		if(A)
			y *= z;
		B
		n /= 2;
	}

	return y;
}

// 求sinx泰勒展开到第n项的近似值
double my_sin(double x, int n)
{
	double ret = 0;

	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
			ret += power(x, 2*i+1)/factorial(2*i+1);
		else
			ret -= power(x, 2*i+1)/factorial(2*i+1);
	}
	return ret;
}

void test_question_2()
{
	cout<<5<<"! = "<<factorial(5)<<endl;
	cout<<2<<"^"<<3<<" = "<<power(2, 3)<<endl;
	cout<<"sin("<<pi/2<<")的第5项展开 = "<<my_sin(pi/2, 5)<<endl;
}

int main()
{
	test_question_2();

	return 0;
}