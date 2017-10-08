#include <iostream>

using namespace std;

typedef struct _ListNode
{
	int val;
	_ListNode *next;
	_ListNode *prev;
	_ListNode(int val)
	{
		this->val = val;
		this->next = this;
		this->prev = this;
	}
}ListNode;

ListNode *insert(int a[], int n)
{
	ListNode *head = new ListNode(0);
	ListNode *dummy = head;

	for(int i = 0; i < n; i++)
	{
		ListNode *tmp = new ListNode(a[i]);
		
		tmp->next = dummy->next;
		tmp->prev = dummy;

//		if(dummy->next != NULL)
		dummy->next->prev = tmp;
		dummy->next = tmp;
	}

	return head;
}

void print_list(ListNode *head)
{
	ListNode *i = head->prev;
	for(; i != head; i = i->prev)
	{
		cout<<i->val<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	ListNode *list = insert(a, 10);
	print_list(list);
}