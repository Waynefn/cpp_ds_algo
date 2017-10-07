#include <iostream>

#include "main.h"
#include "stack.h"

using namespace std;

StackNode *stack_create()
{
	StackNode *node = new StackNode(0);
	NULL_CHK(node);

	return node;
}

bool stack_isEmpty(StackNode *s)
{
	return s->next == NULL;
}

void stack_push(StackNode *s, int val)
{
	NULL_CHK(s);

	StackNode *tmp = new StackNode(val);
	NULL_CHK(tmp);

	tmp->next = s->next;
	s->next = tmp;
}

int stack_pop(StackNode *s)
{
	NULL_CHK(s);

	StackNode *first = s->next;
	int res = first->val;

	s->next = first->next;
	delete first;

	cout<<"Pop res = "<<res<<endl;

	return res;
}

void stack_empty(StackNode *s)
{
	NULL_CHK(s);

	while(!stack_isEmpty(s))
		stack_pop(s);
}