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

StackNode *stack_create();
bool stack_isEmpty(StackNode *s);
void stack_push(StackNode *s, int val);
int stack_pop(StackNode *s);
void stack_empty(StackNode *s);