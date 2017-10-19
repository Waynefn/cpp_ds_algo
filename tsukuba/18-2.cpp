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

double factorial(int n)
{
	int tmp = n;
	double ret = 1;
	while(tmp > 1)
	{
		ret *= tmp;
		tmp--;
	}

	cout<<n<<"的阶乘 = "<<ret<<endl;
	return ret;
}

double power(double x, int n)
{
	int tmp = n;
	double y, z;
	y = 1.0;
	z = x;

	while(tmp > 0)
	{
		if(tmp % 2)		// coding
			y *= z;
		z *= z;			// coding
		tmp /= 2;
	}

	cout<<x<<"的"<<n<<"次方 = "<<y<<endl;
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

	cout<<"sin("<<x<<")的第n项展开 = "<<ret<<endl;
	return ret;
}

void test_question_2()
{
	factorial(10);
	power(2, 3);
	const double pi=3.1415926;
	my_sin(pi/2, 5);
}

int main()
{
	test_question_2();

	return 0;
}