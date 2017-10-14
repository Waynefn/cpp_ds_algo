#include <iostream>
#include <stack>
#include <queue>
#include <string>

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
	return s->top == NULL;
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
	delete tmp;

	if(s->top == NULL)
		s->bottom = NULL;

	cout<<"stack_byList pop = "<<res<<endl;
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
	PRINT_FUNCTION_NAME;

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

/**********************************************
	stack实现方法min()可以O(1)时间内返回stack中的最小值
	s1:正常的操作
	s2：与s1保持元素一样多，每次pop时和s1一样。但push时只push当前最小值
	min()：s2.pop()即可
**********************************************/
typedef struct _minStack
{
	stack<int> s1;
	stack<int> s2;
	int min;
	_minStack()
	{
		this->min = 99999;
	}
}minStack;

void minStack_push(minStack &ms, int x)
{
	if(ms.s2.empty())
		ms.min = 99999;
	else	// 之前的min可能已经被pop，所以每次push时都要再次从s2获取
		ms.min = ms.s2.top();	
	ms.min = ms.min < x ? ms.min : x;

	ms.s1.push(x);
	ms.s2.push(ms.min);
}

int minStack_pop(minStack &ms)
{
	if(ms.s1.empty())
	{
		cout<<"minStack is empty"<<endl;
		return -1;
	}

	int res = ms.s2.top();

	ms.s1.pop(); ms.s2.pop();
	if(ms.s1.empty())
		ms.min = 99999;

	return res;
}

int minStack_min(minStack &ms)
{
	if(ms.s1.empty())
	{
		cout<<"minStack is empty, min = 99999"<<endl;
		return -1;
	}
	int res = ms.s2.top();
	cout<<"minStack min = "<<res<<endl;
	return res;
}

void test_stack_minStack()
{
	PRINT_FUNCTION_NAME;
	
	minStack ms;

	minStack_push(ms, 5); minStack_min(ms);
	minStack_push(ms, 4); minStack_min(ms);
	minStack_push(ms, 8); minStack_min(ms);
	minStack_push(ms, 1); minStack_min(ms);
	minStack_push(ms, 2); minStack_min(ms);
	minStack_pop(ms); minStack_min(ms);
	minStack_pop(ms); minStack_min(ms);
	minStack_pop(ms); minStack_min(ms);
	minStack_pop(ms); minStack_min(ms);
	minStack_pop(ms); minStack_min(ms);
}
