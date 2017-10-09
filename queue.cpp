#include <iostream>
#include <stack>

#include "main.h"
#include "queue.h"

using namespace std;

/**********************************************
	用两个stack模拟一个queue
	s1用于push，s2用于pop
	1.初始化时s1用于push数据，s2为空
	2.pop时，如果s2为空，则s1全部灌入s2，并且s2.pop
	3.pop时，如果s2不为空，则直接s2.pop
**********************************************/
bool queue_empty_byStack(Queue_byStack &q)
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

	while(!queue_empty_byStack(q))
		queue_pop_byStack(q);
}