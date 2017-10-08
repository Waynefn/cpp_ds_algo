#include <iostream>

#include "main.h"
#include "stack.h"

using namespace std;

/**********************************************
	用list来实现stack
	top指向栈顶，bottom指向栈底
	push时：list头插的方式，将新元素置于top的后面
	pop时：top指向的元素弹出，然后top=top->next
	empty时：top已经指向了NULL，无元素可以弹出
**********************************************/
bool stack_isEmpty_byList(Stack_byList *s)
{
	if(s->top == NULL)
	{
		// 此时原本bottom指向的栈底元素已经被top指针pop并delete，会变成野指针
		s->bottom = NULL;
		return true;
	}
	else
		return false;
}

void stack_push_byList(Stack_byList *s, int val)
{
	NULL_CHK(s);

	StackNode *tmp = new StackNode(val);
	NULL_CHK(tmp);

	if(s->top == NULL)
	{
		s->top = tmp;
		s->bottom = tmp;
	}
	else
	{
		tmp->next = s->top;
		s->top = tmp;
	}
}

int stack_pop_byList(Stack_byList *s)
{
	NULL_CHK(s);

	if(stack_isEmpty_byList(s))
	{
		cout<<"stack_byList is empty"<<endl;
		return -1;
	}

	StackNode *tmp = s->top;
	int res = tmp->val;

	s->top = tmp->next;

	cout<<"stack_byList pop = "<<res<<endl;
	delete tmp;
	return res;
}

void stack_empty_byList(Stack_byList *s)
{
	NULL_CHK(s);

	while(!stack_isEmpty_byList(s))
		stack_pop_byList(s);
}

void test_stack_byList()
{
	Stack_byList *s = new Stack_byList;
	stack_push_byList(s, 1);
	stack_push_byList(s, 2);
	stack_push_byList(s, 3);
	stack_push_byList(s, 4);
	stack_pop_byList(s);
	stack_pop_byList(s);
	stack_pop_byList(s);
	stack_pop_byList(s);
	stack_pop_byList(s);
}