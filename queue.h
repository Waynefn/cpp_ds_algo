#include <iostream>
#include <stack>

using namespace std;

typedef struct _QueueNode
{
	int val;
	_QueueNode *next;
	_QueueNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
}QueueNode;

typedef struct
{
	stack<int> s1;
	stack<int> s2;
}Queue_byStack;

void test_queue_byStack();