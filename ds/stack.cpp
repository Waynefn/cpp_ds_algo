#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <limits.h>

#include "utils.h"

using namespace std;

/*
	1.list实现s
	2.两个s实现O(1)时间内返回最小值的s
*/

/**********************************************
	用list来实现s,从下往上生长
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

typedef struct _Stack1
{
	Node *sp;
	_Stack1() {	this->sp = NULL;}
}Stack1;

bool Stack1_Empty(Stack1 *s)
{
	return s->sp == NULL;
}

void Stack1_Push(Stack1 *s, int val)
{
	Node *node = new Node(val);

	node->next = s->sp;
	s->sp = node;
}

int Stack1_Pop(Stack1 *s)
{
	if(Stack1_Empty(s))
	{
		cout<<"Stack1 is empty"<<endl;
		return -1;
	}

	Node *tmp = s->sp;
	int ret = tmp->val;

	s->sp = s->sp->next;
	delete tmp;

	cout<<"Stack1 pop :"<<ret<<endl;
	return ret;
}

void test_stack1()
{
	PRINT_FUNCTION_NAME;

	Stack1 *s = new Stack1;
	Stack1_Push(s, 1);
	Stack1_Push(s, 2);
	Stack1_Push(s, 3);
	Stack1_Push(s, 4);

	Stack1_Pop(s);
	Stack1_Pop(s);
	Stack1_Pop(s);
	Stack1_Pop(s);
	Stack1_Pop(s);
}

/**********************************************
	s实现方法min()可以O(1)时间内返回s中的最小值
	s1:正常的操作
	s2：与s1保持元素一样多，每次pop时和s1一样。但push时只push当前最小值
	min()：s2.pop()即可
**********************************************/
typedef struct _MinStack
{
	int min;
	stack<int> s1;
	stack<int> s2;
	_MinStack()
	{
		this->min = INT_MAX;
	}
}MinStack;

void MinStack_Push(MinStack *ms, int x)
{
	if(ms->s2.empty())
		ms->min = INT_MAX;
	else	// 之前的min可能已经被pop，所以每次push时都要再次从s2获取
		ms->min = ms->s2.top();	
	ms->min = ms->min < x ? ms->min : x;

	ms->s1.push(x);
	ms->s2.push(ms->min);
}

int MinStack_Pop(MinStack *ms)
{
	if(ms->s1.empty())
	{
		cout<<"MinStack is empty"<<endl;
		return -1;
	}

	int res = ms->s2.top();

	ms->s1.pop(); ms->s2.pop();
	if(ms->s1.empty())
		ms->min = INT_MAX;

	return res;
}

int MinStack_Min(MinStack *ms)
{
	if(ms->s1.empty())
	{
		cout<<"MinStack is empty, min = "<<ms->min<<endl;
		return -1;
	}
	int res = ms->s2.top();
	cout<<"MinStack min = "<<res<<endl;
	return res;
}

void test_minstack()
{
	PRINT_FUNCTION_NAME;
	
	MinStack *ms = new MinStack();

	MinStack_Push(ms, 5); MinStack_Min(ms);
	MinStack_Push(ms, 4); MinStack_Min(ms);
	MinStack_Push(ms, 8); MinStack_Min(ms);
	MinStack_Push(ms, 1); MinStack_Min(ms);
	MinStack_Push(ms, 2); MinStack_Min(ms);
	MinStack_Pop(ms); MinStack_Min(ms);
	MinStack_Pop(ms); MinStack_Min(ms);
	MinStack_Pop(ms); MinStack_Min(ms);
	MinStack_Pop(ms); MinStack_Min(ms);
	MinStack_Pop(ms); MinStack_Min(ms);
}

int main()
{
	test_stack1();
	test_minstack();

	return 0;
}
