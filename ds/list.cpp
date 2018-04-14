#include <iostream>
#include <stack>
#include <string.h>
#include <stdio.h>

#include "utils.h"

using namespace std;

/*
	1.不带头结点|单向|非循环链表 type1
	2.List2 带头结点|双向|循环链表 type2
	3.链表h1和h2(不带头结点|单向|非循环链表)是有序的,合并为一条有序链表h
	4.链表h(不带头结点|单向|非循环链表),进行翻转
	5.有序链表h(不带头结点|单向|非循环链表),删除重复元素,每个元素保留一个
	6.有序链表h(不带头结点|单向|非循环链表),如果元素重复,则完全删除
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
	PRINT_SUB_FUNCTION_NAME;

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
	PRINT_SUB_FUNCTION_NAME;

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
	ListNode1_Trvl(list2);
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
	PRINT_SUB_FUNCTION_NAME;

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
	PRINT_SUB_FUNCTION_NAME;

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
	ListNode2_Trvl(list2);
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
	PRINT_SUB_FUNCTION_NAME;

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

	ListNode1_Trvl(h1);
	ListNode1_Trvl(h2);
	
	ListNode1 *h = ListNode1_MergeList(h1,h2);
	ListNode1_Trvl(h);
}

/**********************************************	
	链表h(不带头结点|单向|非循环链表),进行翻转
**********************************************/
ListNode1 *ListNode1_Reverse(ListNode1 *h)
{
	PRINT_SUB_FUNCTION_NAME;

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
	return i;
}

void test_list1_reverse()
{
	PRINT_FUNCTION_NAME;

	ListNode1 *h = NULL;
	h = ListNode1_InsertHead(h, 1);
	h = ListNode1_InsertHead(h, 2);
	h = ListNode1_InsertHead(h, 3);
	h = ListNode1_InsertHead(h, 4);
	ListNode1_Trvl(h);

	h = ListNode1_Reverse(h);
	ListNode1_Trvl(h);
}

/**********************************************	
	有序链表h(不带头结点|单向|非循环链表),删除重复元素,每个元素保留一个
**********************************************/
ListNode1 *ListNode1_DeleteOneMore(ListNode1 *h)
{
	PRINT_SUB_FUNCTION_NAME;

	if(NULL == h)
		return h;

	ListNode1 *i = h, *j = i->next;
	while(i && j)
	{
		while(j && j->val == i->val)
			j = j->next;
		i->next = j;
		i = j;
		if(j)
			j = j->next;
	}

	return h;
}

void test_list1_deleteOneMore()
{
	PRINT_FUNCTION_NAME;

	ListNode1 *h = NULL;
	h = ListNode1_InsertTail(h,1);
	h = ListNode1_InsertTail(h,1);
	h = ListNode1_InsertTail(h,2);
	h = ListNode1_InsertTail(h,3);
	h = ListNode1_InsertTail(h,3);
	h = ListNode1_InsertTail(h,4);
	h = ListNode1_DeleteOneMore(h);
	ListNode1_Trvl(h);
}

/**********************************************	
	有序链表h(不带头结点|单向|非循环链表),如果元素重复,则完全删除
	*利用dummy创建头结点,简化算法
**********************************************/
ListNode1 *ListNode1_DeleteRepeat(ListNode1 *h)
{
	PRINT_SUB_FUNCTION_NAME;

	if(NULL == h || NULL == h->next)
		return h;

	ListNode1 *head = new ListNode1(0);
	head->next = h;
	ListNode1 *dummy = head;
	
	while(dummy->next && dummy->next->next)
	{
		if(dummy->next->val != dummy->next->next->val)
			dummy = dummy->next;
		else
		{
			ListNode1 *i = dummy->next->next;
			while(i && i->val == dummy->next->val)
				i = i->next;
			dummy->next = i;
		}
	}
	return head->next;	// 注意这里不能返回h，因为h指向的第一个元素可能因为重复而被删除了
}

void test_list1_deleteRepeat()
{
	PRINT_FUNCTION_NAME;

	ListNode1 *h = NULL;
	h = ListNode1_InsertTail(h,1);
	h = ListNode1_InsertTail(h,1);
	h = ListNode1_InsertTail(h,2);
	h = ListNode1_InsertTail(h,3);
	h = ListNode1_InsertTail(h,3);
	h = ListNode1_InsertTail(h,4);
	h = ListNode1_DeleteRepeat(h);
	ListNode1_Trvl(h);
}

int main()
{
	// test_list1();
	// test_list2();
	// test_list1_merge();
	// test_list1_reverse();
	test_list1_deleteOneMore();
	test_list1_deleteRepeat();
	return 0;
}

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
