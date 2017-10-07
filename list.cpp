#include <iostream>

#include "main.h"
#include "list.h"

using namespace std;

void list_trvl(ListNode *head)
{
	NULL_CHK(head);
	NULL_CHK(head->next);
	
	for(ListNode *tmp = head->next; tmp != NULL && tmp != head; tmp = tmp->next)
		cout<<tmp->val<<" ";
	cout<<endl;
}

/*	
	头插法
	提供数组a[],然后创建带有头节点的单链表
*/
ListNode *list_insertHead(int a[], int n)
{
	PRINT_FUNCTION_NAME;

	ListNode *head = new ListNode(0);
	ListNode *dummy = head;
	for(int i = 0; i < n; i++)
	{
		ListNode *tmp = new ListNode(a[i]);

		tmp->next = dummy->next;
		dummy->next = tmp;	
	}

	list_trvl(head);
	return head;
}

/*
	尾插法
	提供数组a[],然后创建带有头节点的单链表
*/

ListNode *list_insertTail(int a[], int n)
{
	PRINT_FUNCTION_NAME;

	ListNode *head = new ListNode(0);
	ListNode *dummy = head;
	for(int i = 0; i < n; i++)
	{
		ListNode *tmp = new ListNode(a[i]);
		dummy->next = tmp;
		dummy = tmp;
	}

	list_trvl(head);
	return head;
}

/*
	提供链表list,然后删除链表中指定的元素
*/
ListNode *list_deleteX(ListNode *head, int x)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(head);

	for(ListNode *i = head; i != NULL && i->next != NULL;)
	{
		if(i->next->val != x)
			i = i->next;
		else	// 此时不能移动i指针，为什么？
		{
			ListNode *tmp = i->next;
			i->next = i->next->next;
			delete(tmp);
		}
	}

	list_trvl(head);
	return head;
}

/*
	提供两个有序链表，将他们合并为一个
*/
ListNode *list_mergeList(ListNode *list1, ListNode *list2)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(list1);
	NULL_CHK(list1->next);
	NULL_CHK(list2);
	NULL_CHK(list2->next);

	ListNode *tmp1 = list1->next, *tmp2 = list2->next;
	ListNode *head = new ListNode(0);
	ListNode *i = head;

	while(tmp1 && tmp2)
	{
		if(tmp1->val < tmp2->val)
		{
			i->next = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			i->next = tmp2;
			tmp2 = tmp2->next;
		}
		i = i->next;
	}
	if(tmp1)
		i->next = tmp1;
	else
		i->next = tmp2;

	list_trvl(head);
	return head;
}

/*
	提供一个带头节点的链表，将链表反转
*/
ListNode *list_reverse(ListNode *head)
{
	PRINT_FUNCTION_NAME;

	NULL_CHK(head);
	NULL_CHK(head->next);

	ListNode *i = head->next, *j = i->next, *k = NULL;
	while(j)
	{
		k = j->next;
		j->next = i;
		i = j;
		j = k;
	}

	head->next->next = NULL;
	head->next = i;
	list_trvl(head);
	return head;
}
