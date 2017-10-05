#include <iostream>

#include "main.h"
#include "doubly_list.h"

using namespace std;

void doubly_list_trvl(DoublyListNode *head)
{
	NULL_CHK(head);

	for(DoublyListNode *tmp = head->next; tmp != head; tmp = tmp->next)
		cout<<tmp->val<<" ";
	cout<<endl;

	for(DoublyListNode *tmp = head->prev; tmp != head; tmp = tmp->prev)
		cout<<tmp->val<<" ";
	cout<<endl;
}

DoublyListNode *doubly_list_insert(DoublyListNode *head, int val)
{
	DoublyListNode *tmp = new DoublyListNode(val);

	if(head->next == head)
	{
		head->next = tmp;
		head->prev = tmp;
		tmp->next = head;
		tmp->prev = head;
	}
	else
	{
		tmp->next = head->next;
		tmp->prev = head;
		head->next->prev = tmp;
		head->next = tmp;
	}

	return head;
}

/*
	提供数组a[],然后创建带有头节点的双向循环链表
*/
DoublyListNode *doubly_list_1(int a[], int n)
{
	DoublyListNode *head = new DoublyListNode(0);
	for(int i = 0; i < n; i++)
		head = doubly_list_insert(head, a[i]);

	doubly_list_trvl(head);
	return head;
}
