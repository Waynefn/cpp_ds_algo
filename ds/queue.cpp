#include <iostream>
#include <stack>

#include "utils.h"

using namespace std;

/*
	数组实现queue
	list实现queue
	stack实现queue
*/

/**********************************************
	用数组实现queue,完成push,pop,empty等方法
**********************************************/
#define BUFSIZE (100)

typedef struct _Queue1
{
	int buf[BUFSIZE];
	int first,last;
	_Queue1()
	{
		this->first = this->last = 0;
	}
}Queue1;

bool Queue1_Empty(Queue1 *q)
{
	if(q->first == q->last)
	{
		cout<<"Queue1 is empty"<<endl;
		return true;
	}
	return false;
}

void Queue1_Push(Queue1 *q, int val)
{
	if(q->last +1 == q->first)
		return;
	q->buf[q->last++] = val;
	q->last = q->last % BUFSIZE;
}

int Queue1_Pop(Queue1 *q)
{
	if(Queue1_Empty(q))
		return -1;
	int ret = q->buf[q->first++];
	q->first = q->first % BUFSIZE;
	cout<<"Queue1 pop :"<<ret<<endl;
	return ret;
}

void test_queue1()
{
	PRINT_FUNCTION_NAME;

	Queue1 *q = new Queue1;
	Queue1_Push(q, 3);
	Queue1_Push(q, 5);
	Queue1_Push(q, 7);
	Queue1_Pop(q);
	Queue1_Pop(q);
	Queue1_Pop(q);
	Queue1_Pop(q);
}

/**********************************************
	用list实现queue,完成push,pop,empty等方法
**********************************************/
typedef struct _Node
{
	int val;
	_Node *next;
	_Node(int val)
	{
		this->val = val;
		this->next = NULL;
	}
}Node;

typedef struct _Queue2
{
	Node *first;
	Node *last;
	_Queue2()
	{
		this->first = NULL;
		this->last = NULL;
	}
}Queue2;

bool Queue2_empty(Queue2 *q)
{
	return q->first == NULL;
}

void Queue2_push(Queue2 *q, int val)
{
	Node *n = new Node(val);

	if(NULL == q->first)
	{
		q->first = n;
		q->last = n;
	}
	else
	{
		q->last->next = n;
		q->last = n;
	}
}

int Queue2_pop(Queue2 *q)
{
	if(Queue2_empty(q))
	{
		cout<<"Queue2 is empty"<<endl;
		return -1;
	}

	Node *tmp = q->first;
	int ret = tmp->val;

	q->first = q->first->next;
	if(NULL == q->first)
		q->last = NULL;

	delete tmp;

	cout<<"Queue2 pop :"<<ret<<endl;
	return ret;
}

void test_queue2()
{
	PRINT_FUNCTION_NAME;

	Queue2 *q = new Queue2;
	Queue2_push(q, 3);
	Queue2_push(q, 5);
	Queue2_push(q, 7);
	Queue2_pop(q);
	Queue2_pop(q);
	Queue2_pop(q);
	Queue2_pop(q);
}

/**********************************************
	用两个stack模拟一个queue
	s1用于push，s2用于pop
	1.初始化时s1用于push数据，s2为空
	2.pop时，如果s2为空，则s1全部灌入s2，并且s2.pop
	3.pop时，如果s2不为空，则直接s2.pop
**********************************************/
typedef struct
{
	stack<int> s1;
	stack<int> s2;
}Queue3;

bool Queue3_Empty(Queue3 &q)
{
	return q.s1.empty() && q.s2.empty();
}

void Queue3_Push(Queue3 &q, int x)
{
	cout<<"queue_byStack push :"<<x<<endl;
	q.s1.push(x);
}

int Queue3_Pop(Queue3 &q)
{
	int res = 0;

	if(!q.s2.empty())
	{
		cout<<"queue_byStack 连续pop, ";
		res = q.s2.top();
		q.s2.pop();
	}
	else
	{
		while(!q.s1.empty())
		{
			q.s2.push(q.s1.top());
			q.s1.pop();
		}
		cout<<"queue_byStack s1灌入s2中,";
		res = q.s2.top(); q.s2.pop();
	}

	cout<<"pop :"<<res<<endl;
	return res;
}

void test_queue3()
{
	PRINT_FUNCTION_NAME;
	
	Queue3 q;

	Queue3_Push(q, 1);
	Queue3_Push(q, 2);
	Queue3_Push(q, 3);
	Queue3_Push(q, 4);

	Queue3_Pop(q);
	Queue3_Pop(q);

	Queue3_Push(q, 5);
	Queue3_Push(q, 6);

	while(!Queue3_Empty(q))
		Queue3_Pop(q);
}

int main()
{
	test_queue1();
	test_queue2();
	test_queue3();

	return 0;
}