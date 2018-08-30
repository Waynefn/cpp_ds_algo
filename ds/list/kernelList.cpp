#include <iostream>
#include <stdio.h>

using namespace std;

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

int main()
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

    return 0;
}
