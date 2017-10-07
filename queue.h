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