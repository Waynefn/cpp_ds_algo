#include <iostream>

using namespace std;

/********************************************** 
    带头结点|双向|循环链表
**********************************************/
typedef struct _Node
{
    int val;
    _Node *next, *prev;
}Node;

Node *MakeNode(int v)
{
    Node *n = new Node();
    n->val = v;
    n->next = n->prev = n;
    return n;
}

void Trvl(Node *h)
{
    if(NULL == h)
        return;
    for(Node *i = h->next; i != h; i = i->next)
        cout<<i->val<<",";
    cout<<endl;
}

bool Search(Node *h, int v)
{
    if(NULL == h)
        return false;

    for(Node *i = h->next; i != h; i = i->next)
        if(i->val == v)
            return true;
    return false;
}

Node *InsertHead(Node *h, int v)
{
    Node *n = MakeNode(v);
    if(NULL == h)
        h = MakeNode(0);

    n->next = h->next;
    n->prev = h;
    h->next->prev = n;
    h->next = n;

    return h;
}

Node *InsertTail(Node *h, int v)
{
    Node *n = MakeNode(v);
    if(NULL == h)
        h = MakeNode(0);

    n->next = h;
    n->prev = h->prev;
    h->prev->next = n;
    h->prev = n;

    return h;
}

Node *Delete(Node *h, int v)
{
    if(NULL == h)
        return h;

    for(Node *i = h->next; i != h; i = i->next)
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

int main()
{
    Node *h = NULL;
    h = InsertHead(h, 1);
    h = InsertHead(h, 2);
    h = InsertHead(h, 3);
    Trvl(h);
    h = InsertTail(h, 4);
    h = InsertTail(h, 5);
    h = InsertTail(h, 6);
    Trvl(h);
    h = Delete(h, 4);
    h = Delete(h, 6);
    Trvl(h);
    cout<<"Search result : "<<Search(h, 5)<<endl;
    return 0;
}