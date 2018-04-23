#include <iostream>
#include <stack>

#include "utils.h"

using namespace std;

/*
	1.list实现queue
	2.stack实现queue
*/

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

typedef struct _Queue1
{
	Node *first;
	Node *tail;
	_Queue1()
	{
		this->first = NULL;
		this->tail = NULL;
	}
}Queue1;

bool Queue_Empty(Queue1 *q)
{
	return q->first == NULL;
}

void Queue_Push(Queue1 *q, int val)
{
	Node *n = new Node(val);

	if(NULL == q->first)
	{
		q->first = n;
		q->tail = n;
	}
	else
	{
		q->tail->next = n;
		q->tail = n;
	}
}

int Queue_Pop(Queue1 *q)
{
	if(Queue_Empty(q))
	{
		cout<<"Queue1 is empty"<<endl;
		return -1;
	}

	Node *tmp = q->first;
	int ret = tmp->val;

	q->first = q->first->next;
	if(NULL == q->first)
		q->tail = NULL;

	delete tmp;

	cout<<"Queue1 pop :"<<ret<<endl;
	return ret;
}

void test_queue1()
{
	PRINT_FUNCTION_NAME;

	Queue1 *q = new Queue1;
	Queue_Push(q, 3);
	Queue_Push(q, 5);
	Queue_Push(q, 7);
	Queue_Pop(q);
	Queue_Pop(q);
	Queue_Pop(q);
	Queue_Pop(q);
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
}Queue2;

bool Queue2_Empty(Queue2 &q)
{
	return q.s1.empty() && q.s2.empty();
}

void Queue2_Push(Queue2 &q, int x)
{
	cout<<"queue_byStack push :"<<x<<endl;
	q.s1.push(x);
}

int Queue2_Pop(Queue2 &q)
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

void test_queue2()
{
	PRINT_FUNCTION_NAME;
	
	Queue2 q;

	Queue2_Push(q, 1);
	Queue2_Push(q, 2);
	Queue2_Push(q, 3);
	Queue2_Push(q, 4);

	Queue2_Pop(q);
	Queue2_Pop(q);

	Queue2_Push(q, 5);
	Queue2_Push(q, 6);

	while(!Queue2_Empty(q))
		Queue2_Pop(q);
}

int main()
{
	test_queue1();
	test_queue2();

	return 0;
}