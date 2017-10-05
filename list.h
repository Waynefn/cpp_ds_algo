typedef struct _ListNode
{
	int val;
	_ListNode *next;
	_ListNode *prev;
	_ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
}ListNode;

ListNode *list_1_insertHead(int a[], int n);
ListNode *list_1_insertTail(int a[], int n);
ListNode *list_2(ListNode *head, int x);
ListNode *list_3(ListNode *list1, ListNode *list2);
