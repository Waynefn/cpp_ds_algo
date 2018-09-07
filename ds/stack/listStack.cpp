#include <bits/stdc++.h>

using namespace std;

/**********************************************
    链表实现栈
**********************************************/
#define PRINT_STACK(s){for(Node *i = s->sp; i; i = i->next) cout<<i->val<<"|"; cout<<endl;}

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

typedef struct _Stack
{
    Node *sp;
    _Stack() {  this->sp = NULL;}
}Stack;

bool Empty(Stack *s)
{
    return s->sp == NULL;
}

void Push(Stack *s, int val)
{
    Node *node = new Node(val);

    node->next = s->sp;
    s->sp = node;
}

int Pop(Stack *s)
{
    if(Empty(s))
        return -1;

    Node *tmp = s->sp;
    int ret = tmp->val;

    s->sp = s->sp->next;
    delete tmp;
    return ret;
}

int main()
{
    Stack *s = new Stack;
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    PRINT_STACK(s);
    Pop(s);
    Pop(s);
    PRINT_STACK(s);

    return 0;
}