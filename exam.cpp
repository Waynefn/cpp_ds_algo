#include <iostream>

#include "main.h"
#include "exam.h"

using namespace std;

/*
	数组
	http://www.cs.tsukuba.ac.jp/admission/18-9infj.pdf
*/

// 输出数字n的所有正的约数
void divisor(int n)
{
	for(int i = 1; i < n; i++)
	{
		if(n%i == 0)
			cout<<i<<endl;
	}
}

// 如果数字n的所有约数之和等于自身，则返回1
int is_perfect(int n)
{
	int i, sum;
	if(n <= 0)
		return 0;

	sum = 0;
	for(i = 1; i < n; i++)
	{
		if(n%i == 0)
			sum += i;
	}

	if(sum == n)
		return 1;
	else
		return 0;
}

// 输出1000以内所有数的【公约数之和】
void show_perfect(int N)
{
	int i, j, sum[N+1];

	for(i = 1; i <= N; i++)
		sum[i] = 0;

	for(j = 1; j <= N/2; j++)
	{
		for(i = 1; i <= N; i++)
		{
			if(i > j && i%j == 0)
				sum[i] += j;
		}
	}

	for(i = 1; i <= N; i++)
	{
		if(sum[i] == i)
			cout<<i<<" ";
	}
	cout<<endl;
}

/*
	链表队列的应用
	http://www.cs.tsukuba.ac.jp/admission/19-8infj.pdf
*/

bool queue_isEmpty(queueHead *qh)
{
	return qh->first == NULL;
}

void queue_push(queueHead *qh, int val)
{
	element *e = new element;
	e->next = NULL;
	e->val = val;
	if(qh->first == NULL)
	{
		// coding
		qh->first = e;
		qh->last = e;
	}
	else
	{
		// coding
		qh->last->next = e;
		qh->last = e;
	}
}

int queue_pop(queueHead *qh)	// coding
{
	if(queue_isEmpty(qh))
		return -1;

	element *tmp = qh->first;
	int res = tmp->val;

	qh->first = tmp->next;
	delete tmp;

	return res;
}

#define M (10)	// 十进制
void radix_sort(queueHead *input, queueHead *output, int n)
{
	queueHead buf[M];

	int data, div, i;
	for(i = 0, div = 1; i < n; i++)
		div = div * M;

	while((data = queue_pop(input)) >= 0)
	{
		i = (data / div) % M;
		queue_push(&buf[i], data);
		cout<<"data = "<<data<<"--";
		cout<<"i = "<<i<<endl;
	}

	for(i = 0; i < M; i++)
	{
		while((data = queue_pop(&buf[i])) >= 0)
		{
			queue_push(output, data);
		}
	}

	while((data = queue_pop(output)) >= 0)
	{
		cout<<data<<" ";
	}

}

void show_radixSort()
{
	int a[] = {52, 97, 74, 0, 37, 14, 57, 95};
	queueHead input, output;

	for(int i = 0; i < Len(a); i++)
		queue_push(&input, a[i]);

	radix_sort(&input, &output, 0);
}