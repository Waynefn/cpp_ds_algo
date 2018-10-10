#include <bits/stdc++.h>

using namespace std;

/***************************************
问题1->queue实现归并排序,数组实现循环队列
***************************************/
#define A 	!i
#define B 	(sizeq(q2) && (peekq(q1) > peekq(q2)))
#define C 	q->head + q->cnt
#define D 	q->cnt--

#define MAX (10)
#define Len(x)	sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

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

	q->val[C] = val;
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
	D;
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
		i = A;
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
		if(sizeq(q1) == 0 || B)
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
	queue q = newq();

	enq(q,0);
	enq(q,1);
	enq(q,2);
	cout<<deq(q)<<endl;
	cout<<deq(q)<<endl;
	enq(q,3);
	enq(q,4);
	cout<<deq(q)<<endl;

	PRINT_ARRAY(q->val, MAX);
	cout<<q->head<<" -- "<<q->cnt<<endl;
	
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