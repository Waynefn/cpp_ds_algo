#include <iostream>

using namespace std;

#define PRINT_FUNCTION_NAME {cout<<endl<<"********** "<<__FUNCTION__<<" **********"<<endl;  }

/********************************************** 
    不带头结点|单向|非循环链表
**********************************************/
typedef struct _Node
{
    int val;
    _Node *next;
}Node; 

Node *MakeNode(int v)
{
    Node *n = new Node();
    n->val = v;
    n->next = NULL;
    return n;
}

void Trvl(Node *h)
{
    if(NULL == h)
        return;

    for(Node *i = h; i != NULL; i = i->next)
        cout<<i->val<<",";
    cout<<endl;
}

bool Search(Node *h, int v)
{
    if(NULL == h)
        return false;

    for(Node *i = h; i != NULL; i = i->next)
        if(i->val == v)
            return true;
    return false;
}

Node *InsertHead(Node *h, int v)
{
    Node *n = MakeNode(v);
    
    n->next = h;
    return n;
}

Node *InsertTail(Node *h, int v)
{
    Node *n = MakeNode(v);
    if(NULL == h)
        return n;

    Node *i = h;
    while(i->next)
        i = i->next;
    i->next = n;
    return h;
}

Node *Delete(Node *h, int v)
{
    Node *dummy = MakeNode(0);
    dummy->next = h;
    Node *i = dummy;
    while(i->next)
    {
        if(i->next->val == v)
        {
            Node *n = i->next;
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

/********************************************** 
    有序链表h1和h2,合并为一条有序链表h
**********************************************/
Node *MergeList(Node *h1, Node *h2)
{
    if(NULL == h2)  return h1;
    if(NULL == h1)  return h2;

    Node *dummy = MakeNode(0);
    Node *i = dummy;

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

/********************************************** 
    有序链表(不带头结点|单向|非循环链表),插入元素后保持有序
**********************************************/
Node *InsertSorted(Node *h, int v)
{
    Node *n = MakeNode(v);

    Node *dummy = MakeNode(0);
    dummy->next = h;
    Node *i = dummy;

    while(i->next && i->next->val < v)
        i = i->next;
    n->next = i->next;
    i->next = n;

    i = dummy->next;
    delete dummy;
    return i;
}

/********************************************** 
    链表进行翻转
**********************************************/
Node *ReverseList(Node *h)
{
    if(NULL == h || NULL == h->next)
        return h;

    Node *dummy = MakeNode(0);
    dummy->next = h;

    Node *i = dummy, *j = dummy->next, *k;
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

/********************************************** 
    有序链表h,删除重复元素,每个元素保留一个
**********************************************/
Node *DelRepeatRemainOne(Node *h)
{
    if(NULL == h)
        return h;

    Node *i = h, *j = i->next;
    while(j)
    {
        if(j->val == i->val)
            j = j->next;
        else
        {
            i->next = j;
            i = j;
            j = j->next;
        }
    }
    i->next = j;

    return h;
}

/********************************************** 
    有序链表h,如果元素重复,则完全删除
    *利用dummy创建头结点,简化算法
**********************************************/
Node *DelRepeat(Node *h)
{
    Node *dummy = MakeNode(0);
    dummy->next = h;
    Node *i = dummy;

    //i->next==NULL则直接退出while，不会取值i->next->next
    while(i->next && i->next->next) 
    {
        if(i->next->val != i->next->next->val)
            i = i->next;
        else
        {
            Node *j = i->next->next;
            while(j && j->val == i->next->val)
                j = j->next;
            i->next = j;
        }
    }
    return dummy->next;
}

/********************************************** 
    test
**********************************************/
void test_SingleList()
{
    PRINT_FUNCTION_NAME;

    Node *h = NULL;
    h = InsertHead(h, 1);
    h = InsertHead(h, 2);
    h = InsertHead(h, 3);
    Trvl(h);
    h = InsertTail(h, 4);
    h = InsertTail(h, 5);
    h = InsertTail(h, 6);
    Trvl(h);
    h = Delete(h, 6);
    h = Delete(h, 3);
    Trvl(h);
    cout<<"Search result : "<<Search(h, 4)<<endl;
}

void test_MergeList()
{
    PRINT_FUNCTION_NAME;

    Node *h1 = NULL, *h2 = NULL;
    h1 = InsertTail(h1,1);
    h1 = InsertTail(h1,3);
    
    h2 = InsertTail(h2,2);
    h2 = InsertTail(h2,4);
    h2 = InsertTail(h2,6);

    Trvl(h1);
    Trvl(h2);
    
    Node *h = MergeList(h1,h2);
    Trvl(h);
}

void test_InsertSorted()
{
    PRINT_FUNCTION_NAME;

    Node *h = NULL;
    h = InsertSorted(h, 0);
    h = InsertSorted(h, 3);
    h = InsertSorted(h, 5);
    h = InsertSorted(h, 1);
    Trvl(h);
}

void test_ReverseList()
{
    PRINT_FUNCTION_NAME;

    Node *h = NULL;
    h = InsertHead(h, 1);
    h = InsertHead(h, 2);
    h = InsertHead(h, 3);
    h = InsertHead(h, 4);
    Trvl(h);

    h = ReverseList(h);
    Trvl(h);
}

void test_DelRepeatRemainOne()
{
    PRINT_FUNCTION_NAME;

    Node *h = NULL;
    h = InsertTail(h,0);
    h = InsertTail(h,1);
    h = InsertTail(h,2);
    h = InsertTail(h,3);
    h = InsertTail(h,3);
    h = InsertTail(h,4);
    Trvl(h);
    h = DelRepeatRemainOne(h);
    Trvl(h);
}

void test_DelRepeat()
{
    PRINT_FUNCTION_NAME;

    Node *h = NULL;
    h = InsertTail(h,1);
    h = InsertTail(h,1);
    h = InsertTail(h,2);
    h = InsertTail(h,3);
    h = InsertTail(h,4);
    h = InsertTail(h,4);
    h = InsertTail(h,4);
    Trvl(h);
    h = DelRepeat(h);
    Trvl(h);
}

int main()
{
	test_SingleList();
	test_InsertSorted();
	test_ReverseList();
	test_DelRepeatRemainOne();
	test_DelRepeat();

	return 0;
}