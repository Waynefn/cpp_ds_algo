/*
http://www.ist.osaka-u.ac.jp/japanese/admission/docs/H27nyuusimonndai%E3%80%80jyouhokougaku.pdf
	问题1->二分搜索
	问题2->动态规划背包
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->
***************************************/
int front = 0;
int rear = 0;

void insert(int a[], int size, int d)
{
	int p, left, right, m, i;
	if(rear > suze-1)
	{
		cout<<"Overflow"<<endl;
		exit(1);
	}

	p = -1;
	if(front == rear)
		p = front;
	else
	{
		left = front;
		right = rear-1;
		while(left < right)
		{
			m = (left + right) / 2;
			if(a[m] == d)
			{
				p = m+1;
				break;
			}
			if(d < a[m])	right = m-1;
			else			left = m+1;		
		}
		if(p == -1)
		{
			if(a[left] > d)	p = left;
			else			p = left+1;
		}
	}
	i = rear;
	while(i > p)
	{
		a[i] = a[i-1];
		i--;
		a[p] = d;
		rear++;
	}
}

int delete(int a[])
{
	int x;
	if(front == rear)
	{
		cout<<"Underflow"<<endl;
		exit(1);
	}
	x = a[front++];
	return x;
}

void test_question_1()
{
	int i;
	int a[20];
	int a1[] = {10,5,20,6,13};
	int a2[] = {2,5,18,7,5};

	for(i = 0; i < 5; i++)
		insert(a, Len(a), a1[i]);
	for(i = 0; i < 3; i++)
		cout<<delete(a)<<"|";
	cout<<endl;

	for(i = 0; i < 5; i++)
		insert(a, Len(a), a2[i]);
	for(i = 0; i < 7; i++)
		cout<<delete(a)<<"|";
	cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}