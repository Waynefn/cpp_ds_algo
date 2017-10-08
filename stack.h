typedef struct _StackNode
{
	int val;
	_StackNode *next;
	_StackNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
}StackNode;

typedef struct _Stack_byList
{
	StackNode *top;
	StackNode *bottom;
	_Stack_byList()
	{
		this->top = NULL;
		this->bottom = NULL;
	}
}Stack_byList;

void test_stack_byList();
void test_stack_minStack();