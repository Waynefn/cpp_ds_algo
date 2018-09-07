#include <iostream>

using namespace std;

/********************************************** 
    链表实现队列
**********************************************/
#define PRINT_QUEUE(q){for(Node *i = q->first; i; i = i->next) cout<<i->val<<"|"; cout<<endl;}

typedef struct _Node
{
    int val;
    _Node *next;
    _Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
}Node;

typedef struct _Queue
{
    Node *first;
    Node *last;
    _Queue()
    {
        this->first = this->last = NULL;
    }
}Queue;

bool Empty(Queue *q)
{
    return q->first == NULL;
}

void Push(Queue *q, int val)
{
    Node *n = new Node(val);

    if(NULL == q->first)
    {
        q->first = n;
        q->last = n;
    }
    else
    {
        q->last->next = n;
        q->last = n;
    }
}

int Pop(Queue *q)
{
    if(Empty(q))
        return -1;

    Node *tmp = q->first;
    int ret = tmp->val;

    q->first = q->first->next;
    if(NULL == q->first)
        q->last = NULL;

    delete tmp;
    return ret;
}

int main()
{
    Queue *q = new Queue;
    Push(q, 3);
    Push(q, 5);
    Push(q, 7);
    Pop(q);
    PRINT_QUEUE(q);
}