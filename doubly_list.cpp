#include <iostream>

#include "main.h"
#include "doubly_list.h"

using namespace std;

void doubly_list_trvl(DoublyListNode *head)
{
	NULL_CHK(head);
	NULL_CHK(head->next);

	cout<<"|next:";
	for(DoublyListNode *i = head->next; i != NULL && i != head; i = i->next)
		cout<<i->val<<" ";
	cout<<"|prev:";
	for(DoublyListNode *i = head->prev; i != NULL && i != head; i = i->prev)
		cout<<i->val<<" ";
	cout<<endl;
}

/*
	头插法
	提供数组a[],然后创建带有头节点的双向循环链表
*/
DoublyListNode *doubly_list_insertHead(int a[], int n)
{
	PRINT_FUNCTION_NAME;

	DoublyListNode *head = new DoublyListNode(0);
	DoublyListNode *dummy = head;
	for(int i = 0; i < n; i++)
	{
		DoublyListNode *tmp = new DoublyListNode(a[i]);
		
		tmp->next = dummy->next;
		tmp->prev = dummy;
		dummy->next->prev = tmp;
		dummy->next = tmp;
	}

	doubly_list_trvl(head);
	return head;
}

/*
	尾插法
	提供数组a[],然后创建带有头节点的双向循环链表
*/
DoublyListNode *doubly_list_insertTail(int a[], int n)
{
	PRINT_FUNCTION_NAME;

	DoublyListNode *head = new DoublyListNode(0);
	DoublyListNode *dummy = head;

	for(int i = 0; i < n; i++)
	{
		DoublyListNode *tmp = new DoublyListNode(a[i]);

		tmp->prev = dummy->prev;
		tmp->next = dummy;
		dummy->prev->next = tmp;
		dummy->prev = tmp;
	}

	doubly_list_trvl(head);
	return head;
}

DoublyListNode *doubly_list_deleteX(DoublyListNode *head, int x)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(head);
	NULL_CHK(head->next);

	for(DoublyListNode *i = head->next; i != NULL && i != head; i = i->next)
	{
		if(i->val == x)
		{
			i->next->prev = i->prev;
			i->prev->next = i->next;
			delete i;
		}
	}

	doubly_list_trvl(head);

	return head;
}
