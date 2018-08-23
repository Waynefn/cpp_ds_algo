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
    4.链表h(不带头结点|单向|非循环链表)实现有序插入函数
    5.链表h(不带头结点|单向|非循环链表),进行翻转
    6.有序链表h(不带头结点|单向|非循环链表),删除重复元素,每个元素保留一个
    7.有序链表h(不带头结点|单向|非循环链表),如果元素重复,则完全删除
*/

/********************************************** 
    不带头结点|单向|非循环链表
**********************************************/
typedef struct _ListNode1
{
    int val;
    _ListNode1 *next;
}ListNode1; 

ListNode1 *ListNode1_MakeNode(int v)
{
    ListNode1 *n = new ListNode1();
    n->val = v;
    n->next = NULL;
    return n;
}

ListNode1 *ListNode1_InsertHead(ListNode1 *h, int v)
{
    ListNode1 *n = ListNode1_MakeNode(v);
    
    if(NULL == h)
        return n;
    n->next = h;
    return n;
}

ListNode1 *ListNode1_InsertTail(ListNode1 *h, int v)
{
    ListNode1 *n = ListNode1_MakeNode(v);
    ListNode1 *i = h;
    
    if(NULL == i)
        return n;

    while(i->next)
        i = i->next;
    i->next = n;
    return h;
}

ListNode1 *ListNode1_Delete(ListNode1 *h, int v)
{
    if(NULL == h)
        return h;
    ListNode1 *dummy = ListNode1_MakeNode(0);
    dummy->next = h;
    ListNode1 *i = dummy;
    while(i->next)
    {
        if(i->next->val == v)
        {
            ListNode1 *n = i->next;
            i->next = n->next;
            delete n;
        }
        else
            i = i->next;
    }
    i = dummy->next;
    delete dummy;
    return i;
}

bool ListNode1_Search(ListNode1 *h, int v)
{
    if(NULL == h)
        return false;

    for(ListNode1 *i = h; i != NULL; i = i->next)
        if(i->val == v)
            return true;
    return false;
}

void ListNode1_Trvl(ListNode1 *h)
{
    if(NULL == h)
        return;

    for(ListNode1 *i = h; i != NULL; i = i->next)
        cout<<i->val<<",";
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
    list1 = ListNode1_InsertTail(list1, 4);
    list1 = ListNode1_InsertTail(list1, 5);
    list1 = ListNode1_InsertTail(list1, 6);
    ListNode1_Trvl(list1);
    list1 = ListNode1_Delete(list1, 6);
    list1 = ListNode1_Delete(list1, 3);
    ListNode1_Trvl(list1);
    cout<<"Search result : "<<ListNode1_Search(list1, 4)<<endl;
}

/********************************************** 
    带头结点|双向|循环链表
**********************************************/
typedef struct _ListNode2
{
    int val;
    _ListNode2 *next, *prev;
}ListNode2;

ListNode2 *ListNode2_MakeNode(int v)
{
    ListNode2 *n = new ListNode2();
    n->val = v;
    n->next = n->prev = n;
    return n;
}

ListNode2 *ListNode2_InsertHead(ListNode2 *h, int v)
{
    ListNode2 *n = ListNode2_MakeNode(v);
    if(NULL == h)
        h = ListNode2_MakeNode(0);

    n->next = h->next;
    n->prev = h;
    h->next->prev = n;
    h->next = n;

    return h;
}

ListNode2 *ListNode2_InsertTail(ListNode2 *h, int v)
{
    ListNode2 *n = ListNode2_MakeNode(v);
    if(NULL == h)
        h = ListNode2_MakeNode(0);

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

    for(ListNode2 *i = h->next; i != h; i = i->next)
    {
        if(i->val == v)
        {
            i->prev->next = i->next;
            i->next->prev = i->prev;
            delete i;
            break;
        }
    }
    return h;
}

bool ListNode2_Search(ListNode2 *h, int v)
{
    if(NULL == h)
        return false;

    for(ListNode2 *i = h->next; i != h; i = i->next)
        if(i->val == v)
            return true;
    return false;
}

void ListNode2_Trvl(ListNode2 *h)
{
    if(NULL == h)
        return;
    for(ListNode2 *i = h->next; i != h; i = i->next)
        cout<<i->val<<",";
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
    list1 = ListNode2_InsertTail(list1, 4);
    list1 = ListNode2_InsertTail(list1, 5);
    list1 = ListNode2_InsertTail(list1, 6);
    ListNode2_Trvl(list1);
    list1 = ListNode2_Delete(list1, 4);
    list1 = ListNode2_Delete(list1, 6);
    ListNode2_Trvl(list1);
    cout<<"Search result : "<<ListNode2_Search(list1, 5)<<endl;
}

/********************************************** 
    链表h1和h2(不带头结点|单向|非循环链表)是有序的,合并为一条有序链表h
**********************************************/
ListNode1 *ListNode1_MergeList(ListNode1 *h1, ListNode1 *h2)
{
    if(NULL == h2)  return h1;
    if(NULL == h1)  return h2;

    ListNode1 *dummy = ListNode1_MakeNode(0);
    ListNode1 *i = dummy;

    while(h1 && h2)
    {
        if(h1->val < h2->val)
        {
            i->next = h1;
            h1 = h1->next;
        }
        else
        {
            i->next = h2;
            h2 = h2->next;
        }
        i = i->next;
    }
    if(h1)
        i->next = h1;
    if(h2)
        i->next = h2;

    i = dummy->next;
    delete dummy;
    return i;
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
    有序链表(不带头结点|单向|非循环链表),插入元素后保持有序
**********************************************/
ListNode1 *ListNode1_InsertSorted(ListNode1 *h, int v)
{
    ListNode1 *n = ListNode1_MakeNode(v);

    ListNode1 *dummy = ListNode1_MakeNode(0);
    dummy->next = h;
    ListNode1 *i = dummy;

    while(i->next)
    {
        if(v < i->next->val)
            break;
        i = i->next;
    }
    n->next = i->next;
    i->next = n;

    i = dummy->next;
    delete dummy;
    return i;
}

void test_list1_insertSorted()
{
    PRINT_FUNCTION_NAME;

    ListNode1 *h = NULL;
    h = ListNode1_InsertSorted(h, 4);
    h = ListNode1_InsertSorted(h, 3);
    h = ListNode1_InsertSorted(h, 5);
    h = ListNode1_InsertSorted(h, 1);
    ListNode1_Trvl(h);
}

/********************************************** 
    链表h(不带头结点|单向|非循环链表),进行翻转
**********************************************/
ListNode1 *ListNode1_Reverse(ListNode1 *h)
{
    if(NULL == h || NULL == h->next)
        return h;

    ListNode1 *dummy = ListNode1_MakeNode(0);
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
    if(NULL == h || NULL == h->next)
        return h;

    ListNode1 *dummy = ListNode1_MakeNode(0);
    dummy->next = h;
    ListNode1 *i = dummy;
    
    while(i->next && i->next->next)
    {
        if(i->next->val != i->next->next->val)
            i = i->next;
        else
        {
            ListNode1 *j = i->next->next;
            while(j && j->val == i->next->val)
                j = j->next;
            i->next = j;
        }
    }
    i = dummy->next;
    delete dummy;
    return i;   // 注意这里不能返回h，因为h指向的第一个元素可能因为重复而被删除了
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
    h = ListNode1_InsertTail(h,4);
    h = ListNode1_DeleteRepeat(h);
    ListNode1_Trvl(h);
}

/**********************************************
    Linux内核双向循环链表
**********************************************/
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})
#define container_of_simple(ptr, type, member) ({             \
        (type *) ((char *) ptr - offsetof(type, member));})  

typedef struct _kernel_list
{
    _kernel_list *next, *prev;
    _kernel_list()
    {
        this->next = this;
        this->prev = this;
    }
}kernel_list;

typedef struct 
{
    int age;
    char name[20];
    kernel_list list;
}student;

#define LIST_HEAD_INIT(name) {&(name), &(name)}

#define LIST_HEAD(name) {kernel_list name = LIST_HEAD_INIT(name)}

#define list_for_each(i, head) \
    for(i = (head)->next; i != (head); i = i->next)

#define list_for_each_safe(i, j, head)  \
    for(i = (head)->next, j = i->next; i != (head); i = j, j = i->next)

#define list_entry(ptr, type, member) container_of(ptr, type, member)

inline void INIT_LIST_HEAD(kernel_list *list)
{
    list->next = list;
    list->prev = list;
}

bool kernel_list_empty(kernel_list *head)
{
    return head->next == head;
}

void _list_add(kernel_list *node, kernel_list *prev, kernel_list *next)
{
    node->next = next;
    node->prev = prev;
    next->prev = node;
    prev->next = node;
}

void kernel_list_add(kernel_list *node, kernel_list *head)
{
    _list_add(node, head, head->next);
}

void kernel_list_add_tail(kernel_list *node, kernel_list *head)
{
    _list_add(node, head->prev, head);
}

void _list_del(kernel_list *prev,kernel_list *next)
{
    next->prev = prev;
    prev->next = next;
}

void kernel_list_del(kernel_list *entry)
{
    _list_del(entry->prev, entry->next);
}

void kernel_list_replace(kernel_list *_old, kernel_list *_new)
{
    _new->next = _old->next;
    _new->prev = _old->prev;
    _new->prev->next = _new;
    _new->next->prev = _new;
}

void test_kernel_list()
{
    student head;

    for(int i = 0; i < 5; i++)
    {
        student *s = new student;
        s->age = i*10;
        sprintf(s->name, "%d", i+1);
        kernel_list_add_tail(&(s->list), &head.list);
    }

    kernel_list *tmp;
    list_for_each(tmp, &head.list)
    {
        student *s = list_entry(tmp, student, list);
        cout<<"name:"<<s->name<<", age:"<<s->age<<endl;
    }
}

int main()
{
    test_list1();
    test_list2();
    test_list1_merge();
    test_list1_insertSorted();
    test_list1_reverse();
    test_list1_deleteOneMore();
    test_list1_deleteRepeat();

    // test_kernel_list();
    return 0;
}