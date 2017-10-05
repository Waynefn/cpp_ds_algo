typedef struct _DoublyListNode
{
	int val;
	_DoublyListNode *next;
	_DoublyListNode *prev;
	_DoublyListNode(int val)
	{
		this->val = val;
		this->next = this;
		this->prev = this;
	}
}DoublyListNode;

DoublyListNode *doubly_list_1(int a[], int n);