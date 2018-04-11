#include <iostream>
#include <stack>
#include <string.h>
#include <stdio.h>

#include "utils.h"

using namespace std;

/*
	1.不带头结点|单向|非循环链表		type1
	2.List2 带头结点|双向|循环链表	type2
	3.合并两个有序链表				type1

*/

/**********************************************	
	不带头结点|单向|非循环链表
**********************************************/
typedef struct _ListNode1
{
	int val;
	_ListNode1 *next;
	_ListNode1(int val)
	{
		this->val = val;
		this->next = NULL;
	}
}ListNode1;	

ListNode1 *ListNode1_InsertHead(ListNode1 *h, int v)
{
	ListNode1 *n = new ListNode1(v);
	ListNode1 *dummy = h;
	
	if(NULL == dummy)
		return n;
	n->next = dummy;
	dummy = n;
	return dummy;
}

ListNode1 *ListNode1_InsertTail(ListNode1 *h, int v)
{
	ListNode1 *n = new ListNode1(v);
	ListNode1 *dummy = h;
	
	if(NULL == dummy)
		return n;

// 先找到末尾node,再进行尾插
	while(dummy->next)
		dummy = dummy->next;

// 末尾node的next指向新的节点n即可
	dummy->next = n;
	return h;
}

ListNode1 *ListNode1_Delete(ListNode1 *h, int v)
{
	if(NULL == h)
		return h;
	ListNode1 *head = new ListNode1(0);
	head->next = h;
	ListNode1 *dummy = head;
	while(dummy->next)
	{
		if(dummy->next->val == v)
		{
			ListNode1 *n = dummy->next;
			dummy->next = n->next;
			delete n;
		}
		else
			dummy = dummy->next;
	}
	dummy = head->next;
	delete head;
	return dummy;
}

bool ListNode1_Search(ListNode1 *h, int v)
{
	if(NULL == h)
		return false;

	for(ListNode1 *dummy = h; dummy != NULL; dummy = dummy->next)
		if(dummy->val == v)
			return true;

	return false;
}

void ListNode1_Trvl(ListNode1 *h)
{
	if(NULL == h)
		return;
	for(ListNode1 *dummy = h; dummy != NULL; dummy = dummy->next)
		cout<<dummy->val<<",";
	cout<<endl;
}

void test_list1()
{
	PRINT_FUNCTION_NAME;

	ListNode1 *list1 = NULL;
	list1 = ListNode1_InsertHead(list1, 1);
	list1 = ListNode1_InsertHead(list1, 2);
	list1 = ListNode1_InsertHead(list1, 3);
	ListNode1_Trvl(list1);
	
	ListNode1 *list2 = NULL;
	list2 = ListNode1_InsertTail(list2, 4);
	list2 = ListNode1_InsertTail(list2, 5);
	list2 = ListNode1_InsertTail(list2, 6);
	list2 = ListNode1_Delete(list2, 4);
	list2 = ListNode1_Delete(list2, 6);
	ListNode1_Trvl(list2);
	cout<<"Search result : "<<ListNode1_Search(list2, 4)<<endl;
}

/**********************************************	
	带头结点|双向|循环链表
**********************************************/
typedef struct _ListNode2
{
	int val;
	_ListNode2 *next, *prev;
	_ListNode2(int val)
	{
		this->val = val;
		this->next = this->prev = this;
	}
}ListNode2;

ListNode2 *ListNode2_InsertHead(ListNode2 *h, int v)
{
	ListNode2 *n = new ListNode2(v);
	if(NULL == h)	// 发现链表为空,则构造头结点
		h = new ListNode2(0);

	n->next = h->next;
	n->prev = h;
	h->next->prev = n;
	h->next = n;

	return h;
}

ListNode2 *ListNode2_InsertTail(ListNode2 *h, int v)
{
	ListNode2 *n = new ListNode2(v);
	if(NULL == h)	// 发现链表为空,则构造头结点
		h = new ListNode2(0);

	n->next = h;
	n->prev = h->prev;
	h->prev->next = n;
	h->prev = n;

	return h;
}

ListNode2 *ListNode2_Delete(ListNode2 *h, int v)
{
	if(NULL == h)
		return h;

// 有头结点的循环链表,注意for循环语句
	for(ListNode2 *dummy = h->next; dummy != h; dummy = dummy->next)
	{
		if(dummy->val == v)
		{
			dummy->prev->next = dummy->next;
			dummy->next->prev = dummy->prev;
			delete dummy;
		}
	}
	return h;
}

bool ListNode2_Search(ListNode2 *h, int v)
{
	if(NULL == h)
		return false;

	for(ListNode2 *dummy = h->next; dummy != h; dummy = dummy->next)
		if(dummy->val == v)
			return true;

	return false;
}

void ListNode2_Trvl(ListNode2 *h)
{
	if(NULL == h)
		return;
	for(ListNode2 *dummy = h->next; dummy != h; dummy = dummy->next)
		cout<<dummy->val<<",";
	cout<<endl;
}

void test_list2()
{
	PRINT_FUNCTION_NAME;

	ListNode2 *list1 = NULL;
	list1 = ListNode2_InsertHead(list1, 1);
	list1 = ListNode2_InsertHead(list1, 2);
	list1 = ListNode2_InsertHead(list1, 3);
	ListNode2_Trvl(list1);
	
	ListNode2 *list2 = NULL;
	list2 = ListNode2_InsertTail(list2, 4);
	list2 = ListNode2_InsertTail(list2, 5);
	list2 = ListNode2_InsertTail(list2, 6);
	list2 = ListNode2_Delete(list2, 4);
	list2 = ListNode2_Delete(list2, 6);
	ListNode2_Trvl(list2);
	cout<<"Search result : "<<ListNode2_Search(list2, 5)<<endl;
}

/**********************************************	
	链表h1和h2(不带头结点|单向|非循环链表)是有序的,合并为一条有序链表h
**********************************************/
ListNode1 *ListNode1_MergeList(ListNode1 *h1, ListNode1 *h2)
{
	if(NULL == h2)	return h1;
	if(NULL == h1)	return h2;

	ListNode1 *h = new ListNode1(0);
	ListNode1 *dummy = h;

	while(h1 && h2)
	{
		if(h1->val < h2->val)
		{
			dummy->next = h1;
			h1 = h1->next;
		}
		else
		{
			dummy->next = h2;
			h2 = h2->next;
		}
		dummy = dummy->next;
	}
	while(h1)
	{
		dummy->next = h1;
		h1 = h1->next;
		dummy = dummy->next;
	}
	while(h2)
	{
		dummy->next = h2;
		h2 = h2->next;
		dummy = dummy->next;
	}

	dummy = h->next;
	delete h;
	return dummy;
}

void test_list1_merge()
{
	PRINT_FUNCTION_NAME;

	ListNode1 *h1 = NULL, *h2 = NULL;
	h1 = ListNode1_InsertTail(h1,1);
	h1 = ListNode1_InsertTail(h1,3);
	
	h2 = ListNode1_InsertTail(h2,2);
	h2 = ListNode1_InsertTail(h2,4);
	h2 = ListNode1_InsertTail(h2,6);
	
	ListNode1 *h = ListNode1_MergeList(h1,h2);
	h = ListNode1_Delete(h, 6);
	ListNode1_Trvl(h);
}

/**********************************************	
	链表h(不带头结点|单向|非循环链表),进行翻转
**********************************************/
ListNode1 *ListNode1_Reverse(ListNode1 *h)
{
	PRINT_FUNCTION_NAME;
	
	if(NULL == h || NULL == h->next)
		return h;

	ListNode1 *dummy = new ListNode1(0);
	dummy->next = h;

	ListNode1 *i = dummy, *j = dummy->next, *k;
	while(j)
	{
		k = j->next;
		j->next = i;
		i = j; j = k;
	}
	dummy->next->next = NULL;
	delete dummy;
	return j;
}

void test_list1_reverse()
{
	ListNode1 *h = NULL;
	h = ListNode1_InsertHead(h, 1);
	h = ListNode1_InsertHead(h, 2);
	h = ListNode1_InsertHead(h, 3);
	h = ListNode1_InsertHead(h, 4);
	ListNode1_Trvl(h);

	h = ListNode1_Reverse(h);
	ListNode1_Trvl(h);
}

int main()
{
	test_list1();
	test_list2();
	test_list1_merge();
	test_list1_reverse();
	return 0;
}

typedef struct _ListNode
{
	int val;
	_ListNode *next;
	_ListNode(int val)
	{
		this->val = val;
		this->next = NULL;	// this->next = this 则是循环链表
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

// /**********************************************	
// 	头插法
// 	提供数组a[],然后创建带有头节点的单链表
// **********************************************/
// ListNode *list_insertHead(int a[], int n)
// {
// 	ListNode *head = new ListNode(0);
// 	ListNode *dummy = head;
// 	for(int i = 0; i < n; i++)
// 	{
// 		ListNode *tmp = new ListNode(a[i]);

// 		tmp->next = dummy->next;
// 		dummy->next = tmp;	
// 	}

// 	return head;
// }

// /**********************************************
// 	尾插法
// 	提供数组a[],然后创建带有头节点的单链表
// **********************************************/
// ListNode *list_insertTail(int a[], int n)
// {
// 	ListNode *head = new ListNode(0);
// 	ListNode *dummy = head;
// 	for(int i = 0; i < n; i++)
// 	{
// 		ListNode *tmp = new ListNode(a[i]);
// 		dummy->next = tmp;
// 		dummy = tmp;
// 	}

// 	return head;
// }

// /**********************************************
// 	提供两个有序链表，将他们合并为一个
// **********************************************/
// ListNode *list_mergeList(ListNode *list1, ListNode *list2)
// {
// 	PRINT_SUB_FUNCTION_NAME;

// 	NULL_CHK(list1);
// 	NULL_CHK(list1->next);
// 	NULL_CHK(list2);
// 	NULL_CHK(list2->next);

// 	ListNode *tmp1 = list1->next, *tmp2 = list2->next;
// 	ListNode *head = new ListNode(0);
// 	ListNode *dummy = head;

// 	while(tmp1 != NULL && tmp2 != NULL)
// 	{
// 		if(tmp1->val < tmp2->val)
// 		{
// 			dummy->next = tmp1;
// 			tmp1 = tmp1->next;
// 		}
// 		else
// 		{
// 			dummy->next = tmp2;
// 			tmp2 = tmp2->next;
// 		}
// 		dummy = dummy->next;
// 	}

// 	while(tmp1 != NULL)
// 	{
// 		dummy->next = tmp1;
// 		tmp1 = tmp2->next;
// 	}
// 	while(tmp2 != NULL)
// 	{
// 		dummy->next = tmp2;
// 		tmp2 = tmp2->next;
// 	}

// 	// delete list1;
// 	// delete list2;

// 	return head;
// }

// void test_list_merge()
// {
// 	PRINT_FUNCTION_NAME;

// 	int l1[5] = {1,3,5,7,9};
// 	int l2[5] = {2,4,6,8,10};
// 	ListNode *list1 = list_insertTail(l1, Len(l1));
// 	ListNode *list2 = list_insertTail(l2, Len(l2));
// 	ListNode *merge = list_mergeList(list1, list2);

// 	list_trvl(merge);
// }

// /**********************************************
// 	提供一个带头节点的链表，将链表反转
// **********************************************/
// ListNode *list_reverse(ListNode *head)
// {
// 	PRINT_SUB_FUNCTION_NAME;

// 	NULL_CHK(head);
// 	NULL_CHK(head->next);

// 	ListNode *i = head->next, *j = i->next, *k = NULL;
// 	while(j)
// 	{
// 		k = j->next;
// 		j->next = i;
// 		i = j;
// 		j = k;
// 	}

// 	head->next->next = NULL;
// 	head->next = i;

// 	return head;
// }

// void test_list_reverse()
// {
// 	PRINT_FUNCTION_NAME;

// 	int l1[5] = {1,3,5,7,9};
// 	int l2[5] = {2,4,6,8,10};
// 	ListNode *list1 = list_insertHead(l1, Len(l1));
// 	ListNode *list2 = list_insertHead(l2, Len(l2));

// 	ListNode *rev_1 = list_reverse(list1);
// 	list_trvl(rev_1);

// 	ListNode *rev_2 = list_reverse_byStack(list2);
// 	list_trvl(rev_2);
// }



// /**********************************************
// 	提供一个带头节点的有序链表，将多于一个的元素删除
// **********************************************/
// ListNode *delete_moreOne(ListNode *head)
// {
// 	PRINT_SUB_FUNCTION_NAME;

// 	NULL_CHK(head);
// 	NULL_CHK(head->next);

// 	if(head->next->next == NULL)
// 		return head;

// 	ListNode *i = head->next, *j = i->next;

// 	while(i && j)
// 	{
// 		while(j && i->val == j->val)
// 			j = j->next;
// 		i->next = j;
// 		i = j; 
// 		if(j)
// 			j = j->next;
// 	}

// 	return head;
// }

// /**********************************************
// 	提供一个带头节点的有序链表，将所有重复数字【完全删除，不留一个】
// **********************************************/
// ListNode *delete_duplicates(ListNode *head)
// {
// 	PRINT_SUB_FUNCTION_NAME;
	
// 	NULL_CHK(head);
// 	NULL_CHK(head->next)

// 	if(head->next->next == NULL)
// 		return head;

// 	ListNode *i = head->next, *j = i->next;
// 	ListNode *dummy = head;

// 	while(dummy->next && dummy->next->next)
// 	{
// 		if(dummy->next->val != dummy->next->next->val)
// 			dummy = dummy->next;
// 		else
// 		{
// 			ListNode *tmp = dummy->next->next;
// 			while(tmp && tmp->val == dummy->next->val)
// 				tmp = tmp->next;
// 			dummy->next = tmp;
// 		}
// 	}

// 	return head;
// }

// void test_list_delete()
// {
// 	PRINT_FUNCTION_NAME;

// 	int l1[10] = {1,2,3,3,4,5,6,7,7,8};
// 	int l2[10] = {1,2,3,3,4,5,6,7,7,8};
// 	int l3[10] = {1,2,3,3,4,5,6,7,7,8};
// 	ListNode *list1 = list_insertHead(l1, Len(l1));
// 	ListNode *list2 = list_insertHead(l2, Len(l2));
// 	ListNode *list3 = list_insertHead(l3, Len(l3));

// 	ListNode *del_1 = list_deleteX(list1, 3);
// 	list_trvl(del_1);
// 	ListNode *del_2 = delete_moreOne(list2);
// 	list_trvl(del_2);
// 	ListNode *del_3 = delete_duplicates(list3);
// 	list_trvl(del_3);
// }

// /**********************************************
// 	Linux内核双向循环链表
// **********************************************/
// #define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
// #define container_of(ptr, type, member) ({          \
//     const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
//     (type *)( (char *)__mptr - offsetof(type,member) );})
// #define container_of_simple(ptr, type, member) ({             \
//         (type *) ((char *) ptr - offsetof(type, member));})  

// typedef struct _kernel_list
// {
// 	_kernel_list *next, *prev;
// 	_kernel_list()
// 	{
// 		this->next = this;
// 		this->prev = this;
// 	}
// }kernel_list;

// typedef struct 
// {
// 	int age;
// 	char name[20];
// 	kernel_list list;
// }student;

// #define LIST_HEAD_INIT(name) {&(name), &(name)}

// #define LIST_HEAD(name) {kernel_list name = LIST_HEAD_INIT(name)}

// #define list_for_each(i, head) \
// 	for(i = (head)->next; i != (head); i = i->next)

// #define list_for_each_safe(i, j, head)	\
// 	for(i = (head)->next, j = i->next; i != (head); i = j, j = i->next)

// #define list_entry(ptr, type, member) container_of(ptr, type, member)

// inline void INIT_LIST_HEAD(kernel_list *list)
// {
// 	list->next = list;
// 	list->prev = list;
// }

// bool kernel_list_empty(kernel_list *head)
// {
// 	return head->next == head;
// }

// void _list_add(kernel_list *node, kernel_list *prev, kernel_list *next)
// {
// 	node->next = next;
// 	node->prev = prev;
// 	next->prev = node;
// 	prev->next = node;
// }

// void kernel_list_add(kernel_list *node, kernel_list *head)
// {
// 	_list_add(node, head, head->next);
// }

// void kernel_list_add_tail(kernel_list *node, kernel_list *head)
// {
// 	_list_add(node, head->prev, head);
// }

// void _list_del(kernel_list *prev,kernel_list *next)
// {
// 	next->prev = prev;
// 	prev->next = next;
// }

// void kernel_list_del(kernel_list *entry)
// {
// 	_list_del(entry->prev, entry->next);
// }

// void kernel_list_replace(kernel_list *_old, kernel_list *_new)
// {
// 	_new->next = _old->next;
// 	_new->prev = _old->prev;
// 	_new->prev->next = _new;
// 	_new->next->prev = _new;
// }

// void test_kernel_list()
// {
// 	student head;

// 	for(int i = 0; i < 5; i++)
// 	{
// 		student *s = new student;
// 		s->age = i*10;
// 		sprintf(s->name, "%d", i+1);
// 		kernel_list_add_tail(&(s->list), &head.list);
// 	}

// 	kernel_list *tmp;
// 	list_for_each(tmp, &head.list)
// 	{
// 		student *s = list_entry(tmp, student, list);
// 		cout<<"name:"<<s->name<<", age:"<<s->age<<endl;
// 	}

// }

// int main()
// {
// 	test_list_merge();
// 	test_list_reverse();
// 	test_list_delete();

// 	test_doubly_list();

// 	test_kernel_list();

// 	return 0;
// }