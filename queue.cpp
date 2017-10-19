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

typedef struct _Queue_byList
{
	Node *first;
	Node *tail;
	_Queue_byList()
	{
		this->first = NULL;
		this->tail = NULL;
	}
}Queue_byList;

bool queue_isEmpty_byList(Queue_byList *q)
{
	return q->first == NULL;
}

void queue_push_byList(Queue_byList *q, int val)
{
	Node *node = new Node(val);

	if(NULL == q->first)
	{
		q->first = node;
		q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}

int queue_pop_byList(Queue_byList *q)
{
	if(queue_isEmpty_byList(q))
	{
		cout<<"queue_byList is empty"<<endl;
		return -1;
	}

	Node *tmp = q->first;
	int ret = tmp->val;

	q->first = q->first->next;
	if(NULL == q->first)
		q->tail = NULL;

	delete tmp;

	cout<<"queue_byList pop :"<<ret<<endl;
	return ret;
}

void test_queue_byList()
{
	PRINT_FUNCTION_NAME;

	Queue_byList *q = new Queue_byList;
	queue_push_byList(q, 3);
	queue_push_byList(q, 5);
	queue_push_byList(q, 7);
	queue_pop_byList(q);
	queue_pop_byList(q);
	queue_pop_byList(q);
	queue_pop_byList(q);
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
}Queue_byStack;

bool queue_isEmpty_byStack(Queue_byStack &q)
{
	return q.s1.empty() && q.s2.empty();
}

void queue_push_byStack(Queue_byStack &q, int x)
{
	cout<<"queue_byStack push :"<<x<<endl;
	q.s1.push(x);
}

int queue_pop_byStack(Queue_byStack &q)
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

void test_queue_byStack()
{
	PRINT_FUNCTION_NAME;
	
	Queue_byStack q;

	queue_push_byStack(q, 1);
	queue_push_byStack(q, 2);
	queue_push_byStack(q, 3);
	queue_push_byStack(q, 4);

	queue_pop_byStack(q);
	queue_pop_byStack(q);

	queue_push_byStack(q, 5);
	queue_push_byStack(q, 6);

	while(!queue_isEmpty_byStack(q))
		queue_pop_byStack(q);
}

int main()
{
	test_queue_byList();
	test_queue_byStack();

	return 0;
}