#include <iostream>
#include <stack>

#include "utils.h"

using namespace std;

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

void list_trvl(ListNode *head)
{
	NULL_CHK(head);
	NULL_CHK(head->next);
	
	for(ListNode *tmp = head->next; tmp != NULL && tmp != head; tmp = tmp->next)
		cout<<tmp->val<<" ";
	cout<<endl;
}

/**********************************************	
	头插法
	提供数组a[],然后创建带有头节点的单链表
**********************************************/
ListNode *list_insertHead(int a[], int n)
{
	ListNode *head = new ListNode(0);
	ListNode *dummy = head;
	for(int i = 0; i < n; i++)
	{
		ListNode *tmp = new ListNode(a[i]);

		tmp->next = dummy->next;
		dummy->next = tmp;	
	}

	return head;
}

/**********************************************
	尾插法
	提供数组a[],然后创建带有头节点的单链表
**********************************************/
ListNode *list_insertTail(int a[], int n)
{
	ListNode *head = new ListNode(0);
	ListNode *dummy = head;
	for(int i = 0; i < n; i++)
	{
		ListNode *tmp = new ListNode(a[i]);
		dummy->next = tmp;
		dummy = tmp;
	}

	return head;
}

/**********************************************
	提供两个有序链表，将他们合并为一个
**********************************************/
ListNode *list_mergeList(ListNode *list1, ListNode *list2)
{
	PRINT_SUB_FUNCTION_NAME;

	NULL_CHK(list1);
	NULL_CHK(list1->next);
	NULL_CHK(list2);
	NULL_CHK(list2->next);

	ListNode *tmp1 = list1->next, *tmp2 = list2->next;
	ListNode *head = new ListNode(0);
	ListNode *dummy = head;

	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp1->val < tmp2->val)
		{
			dummy->next = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			dummy->next = tmp2;
			tmp2 = tmp2->next;
		}
		dummy = dummy->next;
	}

	while(tmp1 != NULL)
	{
		dummy->next = tmp1;
		tmp1 = tmp2->next;
	}
	while(tmp2 != NULL)
	{
		dummy->next = tmp2;
		tmp2 = tmp2->next;
	}

//	delete list1;
//	delete list2;

	return head;
}

void test_list_merge()
{
	PRINT_FUNCTION_NAME;

	int l1[5] = {1,3,5,7,9};
	int l2[5] = {2,4,6,8,10};
	ListNode *list1 = list_insertTail(l1, Len(l1));
	ListNode *list2 = list_insertTail(l2, Len(l2));
	ListNode *merge = list_mergeList(list1, list2);

	list_trvl(merge);
}

/**********************************************
	提供一个带头节点的链表，将链表反转
**********************************************/
ListNode *list_reverse(ListNode *head)
{
	PRINT_SUB_FUNCTION_NAME;

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

	return head;
}

/**********************************************
	提供一个带头节点的链表，将链表反转,利用stack实现
**********************************************/
ListNode *list_reverse_byStack(ListNode *head)
{
	PRINT_SUB_FUNCTION_NAME;

	stack<ListNode *> s;
	ListNode *i = head->next;
	while(i)
	{
		s.push(i);
		i = i->next;
	}

	ListNode *dummy = head;
	while(!s.empty())
	{
		dummy->next = s.top(); s.pop();
		dummy = dummy->next;
	}
	dummy->next = NULL;

	return head;
}

void test_list_reverse()
{
	PRINT_FUNCTION_NAME;

	int l1[5] = {1,3,5,7,9};
	int l2[5] = {2,4,6,8,10};
	ListNode *list1 = list_insertHead(l1, Len(l1));
	ListNode *list2 = list_insertHead(l2, Len(l2));

	ListNode *rev_1 = list_reverse(list1);
	list_trvl(rev_1);

	ListNode *rev_2 = list_reverse_byStack(list2);
	list_trvl(rev_2);
}

/**********************************************
	提供链表list,然后删除链表中指定的元素
**********************************************/
ListNode *list_deleteX(ListNode *head, int x)
{
	PRINT_SUB_FUNCTION_NAME;

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

	return head;
}

/**********************************************
	提供一个带头节点的有序链表，将多于一个的元素删除
**********************************************/
ListNode *delete_moreOne(ListNode *head)
{
	PRINT_SUB_FUNCTION_NAME;

	NULL_CHK(head);
	NULL_CHK(head->next);

	if(head->next->next == NULL)
		return head;

	ListNode *i = head->next, *j = i->next;

	while(i && j)
	{
		while(j && i->val == j->val)
			j = j->next;
		i->next = j;
		i = j; 
		if(j)
			j = j->next;
	}

	return head;
}

/**********************************************
	提供一个带头节点的有序链表，将所有重复数字【完全删除，不留一个】
**********************************************/
ListNode *delete_duplicates(ListNode *head)
{
	PRINT_SUB_FUNCTION_NAME;
	
	NULL_CHK(head);
	NULL_CHK(head->next)

	if(head->next->next == NULL)
		return head;

	ListNode *i = head->next, *j = i->next;
	ListNode *dummy = head;

	while(dummy->next && dummy->next->next)
	{
		if(dummy->next->val != dummy->next->next->val)
			dummy = dummy->next;
		else
		{
			ListNode *tmp = dummy->next->next;
			while(tmp && tmp->val == dummy->next->val)
				tmp = tmp->next;
			dummy->next = tmp;
		}
	}

	return head;
}

void test_list_delete()
{
	PRINT_FUNCTION_NAME;

	int l1[10] = {1,2,3,3,4,5,6,7,7,8};
	int l2[10] = {1,2,3,3,4,5,6,7,7,8};
	int l3[10] = {1,2,3,3,4,5,6,7,7,8};
	ListNode *list1 = list_insertHead(l1, Len(l1));
	ListNode *list2 = list_insertHead(l2, Len(l2));
	ListNode *list3 = list_insertHead(l3, Len(l3));

	ListNode *del_1 = list_deleteX(list1, 3);
	list_trvl(del_1);
	ListNode *del_2 = delete_moreOne(list2);
	list_trvl(del_2);
	ListNode *del_3 = delete_duplicates(list3);
	list_trvl(del_3);
}

/**********************************************
	双向循环链表
**********************************************/
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

void doubly_list_trvl(DoublyListNode *head)
{
	NULL_CHK(head);
	NULL_CHK(head->next);

	cout<<"|next:";
	for(DoublyListNode *i = head->next; i != NULL && i != head; i = i->next)
		cout<<i->val<<" ";
	cout<<"\n|prev:";
	for(DoublyListNode *i = head->prev; i != NULL && i != head; i = i->prev)
		cout<<i->val<<" ";
	cout<<endl;
}

DoublyListNode *doubly_list_insertHead(int a[], int n)
{
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

	return head;
}

DoublyListNode *doubly_list_insertTail(int a[], int n)
{
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

	return head;
}

DoublyListNode *doubly_list_delete(DoublyListNode *head, int x)
{
	PRINT_SUB_FUNCTION_NAME;

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

	return head;
}

void test_doubly_list()
{
	PRINT_FUNCTION_NAME;

	int l1[10] = {6,7,8,9,10,9,9,9,9,9};
	DoublyListNode *list1 = doubly_list_insertHead(l1, Len(l1));
	doubly_list_trvl(list1);

	list1 = doubly_list_delete(list1, 9);
	doubly_list_trvl(list1);
}

int main()
{
	test_list_merge();
	test_list_reverse();
	test_list_delete();

	test_doubly_list();
	return 0;
}