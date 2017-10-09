typedef struct _ListNode
{
	int val;
	_ListNode *next;
	_ListNode *prev;
	_ListNode(int val)
	{
		this->val = val;
		this->next = NULL;	// this->next = this 则是循环链表
		this->prev = NULL;	// this->prev = this 则是循环链表
	}
}ListNode;

void test_list_create_merge();
void test_list_reverse();
void test_list_delete();
