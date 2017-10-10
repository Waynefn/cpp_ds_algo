/*
http://www.cs.tsukuba.ac.jp/admission/28-8inf.pdf
	问题1->queue实现归并排序,数组实现循环队列
	问题2->卡诺图
*/

#include <iostream>

#include <stdlib.h>

using namespace std;

/***************************************
问题1->
	1.补充split()代码
	2.改进merge()函数
	3.有4个元素的queue作为参数,newq和enq会被调用多少次
		4个元素的queue,split*3,merge*3
		每次split:newq*2, enq为q的元素个数
		每次merge:newq*1, enq为q1+q2的元素个数
		->newq*9, enq*16 (test函数中初始化过程不算)
	4.真假判断
		T->总是同时出现的
		F->除了比较大小时enq,split时也enq了
		F
		T->??
		F->只依赖于q1和q2的元素个数
	5.完成[数组实现循环queue]的代码
***************************************/

#define MAX (100)
#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _queue
{
	int cnt, head;
	int val[MAX];
}*queue;

int newq_cnt = 0, enq_cnt = 0, deq_cnt = 0;

queue newq()
{
	newq_cnt++;
	
	queue q = (queue)malloc(sizeof(_queue));
	q->cnt = q->head = 0;
	return q;
}

unsigned sizeq(queue q)
{
	return q->cnt;
}

void enq(queue q, int val)
{
	enq_cnt++;

	q->val[q->cnt] = val;		// coding
	q->cnt++;
}

int peekq(queue q)
{
	return q->val[q->head];
}

int deq(queue q)
{
	deq_cnt++;

	int val = peekq(q);
	q->head = (q->head + 1) % MAX;
	q->cnt--;					// coding
	return val;
}

void split(queue q, queue subq[])
{
	int i = 0;
	subq[0] = newq();
	subq[1] = newq();
	while(sizeq(q) > 0)
	{
		enq(subq[i], deq(q));
		i = !i;			// coding
	}
}

queue merge(queue q1, queue q2)
{
	queue q = newq();
	while(sizeq(q1) > 0 || sizeq(q2) > 0)
	{
		if(sizeq(q1) == 0)
			enq(q, deq(q2));
		else if(sizeq(q2) == 0)
			enq(q, deq(q1));
		else if(peekq(q1) < peekq(q2))
			enq(q, deq(q1));
		else
			enq(q, deq(q2));
	}

	return q;
}

queue merge_2(queue q1, queue q2)
{
	queue q = newq();
	while(sizeq(q1) > 0 || sizeq(q2) > 0)
	{
		if(sizeq(q1) == 0 || (sizeq(q2) && (peekq(q1) > peekq(q2))))	// coding
			enq(q, deq(q2));
		else
			enq(q, deq(q1));
	}

	return q;
}

queue ms(queue q)
{
	if(sizeq(q) <= 1)
		return q;
	else
	{
		queue subq[2];
		split(q, subq);
		return merge(ms(subq[0]), ms(subq[1]));
	}
}

void test_question_1()
{
	int a[] = {5,4,2,6};
	queue q = newq();

	for(int i = 0; i < Len(a); i++)
		enq(q, a[i]);
	q = ms(q);
	while(sizeq(q) > 0)
		cout<<deq(q)<<endl;

	cout<<"newq_cnt = "<<newq_cnt<<endl;
	cout<<"enq_cnt = "<<enq_cnt<<endl;
}

int main()
{
	test_question_1();

	return 0;
}