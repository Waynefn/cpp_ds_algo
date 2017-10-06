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

ListNode *list_insertHead(int a[], int n);
ListNode *list_insertTail(int a[], int n);
ListNode *list_deleteX(ListNode *head, int x);
ListNode *list_mergeList(ListNode *list1, ListNode *list2);
ListNode *list_reverse(ListNode *head);
