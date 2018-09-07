#include <iostream>
#include <stack>

using namespace std;

/**********************************************
    用两个stack模拟一个queue
**********************************************/
typedef struct
{
    stack<int> s1;
    stack<int> s2;
}Queue;

bool Empty(Queue &q)
{
    return q.s1.empty() && q.s2.empty();
}

void Push(Queue &q, int x)
{
    cout<<"s1 push :"<<x<<endl;
    q.s1.push(x);
}

int Pop(Queue &q)
{
    int res = 0;

    if(!q.s2.empty())
    {
        cout<<"s2 pop, ";
        res = q.s2.top();
        q.s2.pop();
    }
    else
    {
        while(!q.s1.empty())
        {
            q.s2.push(q.s1.top());
            q.s1.pop();
        }
        cout<<"s1 move to s2,";
        res = q.s2.top(); q.s2.pop();
    }
    cout<<"pop :"<<res<<endl;
    return res;
}

int main()
{
    Queue q;

    Push(q, 1);
    Push(q, 2);
    Push(q, 3);
    Push(q, 4);
    Pop(q);
    Pop(q);
    Push(q, 5);
    Push(q, 6);
    while(!Empty(q))
        Pop(q);
    return 0;
}