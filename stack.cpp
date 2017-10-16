#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <limits.h>

#include "utils.h"

using namespace std;

/**********************************************
	用list来实现stack,从下往上生长
	设置一个sp指针,指向栈顶元素,初始化为NULL
	push时：新节点node指向sp,sp再等于node,即可完成类似头插
	pop时：sp指向的节点即是栈顶,所以保存它的值,然后sp指向下一个节点
	empty时：栈元素为空,sp再次指向了NULL，无元素可以弹出
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

typedef struct _stack_byList
{
	Node *sp;
	_stack_byList() {	this->sp = NULL;}
}stack_byList;

stack_byList *make_stack()
{
	stack_byList *stack = new stack_byList;
	return stack;
}

bool stack_isEmpty_byList(stack_byList *stack)
{
	return stack->sp == NULL;
}

void stack_push_byList(stack_byList *stack, int val)
{
	Node *node = new Node(val);

	node->next = stack->sp;
	stack->sp = node;
}

int stack_pop_byList(stack_byList *stack)
{
	if(stack_isEmpty_byList(stack))
	{
		cout<<"stack_byList is empty"<<endl;
		return -1;
	}

	Node *tmp = stack->sp;
	int ret = tmp->val;

	stack->sp = stack->sp->next;
	delete tmp;

	cout<<"stack_byList pop :"<<ret<<endl;
	return ret;
}

void test_stack_byList()
{
	PRINT_FUNCTION_NAME;

	stack_byList *s = make_stack();
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
	int min;
	stack<int> s1;
	stack<int> s2;
	_minStack()
	{
		this->min = INT_MAX;
	}
}minStack;

minStack *make_minStack()
{
	minStack *ms = new minStack;
	return ms;
}

void minStack_push(minStack *ms, int x)
{
	if(ms->s2.empty())
		ms->min = INT_MAX;
	else	// 之前的min可能已经被pop，所以每次push时都要再次从s2获取
		ms->min = ms->s2.top();	
	ms->min = ms->min < x ? ms->min : x;

	ms->s1.push(x);
	ms->s2.push(ms->min);
}

int minStack_pop(minStack *ms)
{
	if(ms->s1.empty())
	{
		cout<<"minStack is empty"<<endl;
		return -1;
	}

	int res = ms->s2.top();

	ms->s1.pop(); ms->s2.pop();
	if(ms->s1.empty())
		ms->min = INT_MAX;

	return res;
}

int minStack_min(minStack *ms)
{
	if(ms->s1.empty())
	{
		cout<<"minStack is empty, min = "<<ms->min<<endl;
		return -1;
	}
	int res = ms->s2.top();
	cout<<"minStack min = "<<res<<endl;
	return res;
}

void test_stack_minStack()
{
	PRINT_FUNCTION_NAME;
	
	minStack *ms = make_minStack();

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

int main()
{
	test_stack_byList();
	test_stack_minStack();

	return 0;
}
