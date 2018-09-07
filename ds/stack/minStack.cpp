#include <bits/stdc++.h>

using namespace std;

/**********************************************
    栈实现方法min()可以O(1)时间内返回栈中的最小值
**********************************************/
typedef struct _MinStack
{
    int min;
    stack<int> s1;
    stack<int> s2;
    _MinStack()
    {
        this->min = INT_MAX;
    }
}MinStack;

void Push(MinStack *ms, int x)
{
    ms->s1.push(x);
    ms->min = ms->min < x ? ms->min : x;
    ms->s2.push(ms->min);
}

int Pop(MinStack *ms)
{
    if(ms->s1.empty())
        return -1;

    int res = ms->s2.top();
    ms->s1.pop(); 
    ms->s2.pop();
    if(ms->s1.empty())
        ms->min = INT_MAX;

    return res;
}

int Min(MinStack *ms)
{
    if(ms->s1.empty())
        return -1;

    int res = ms->s2.top();
    cout<<"MinStack min = "<<res<<endl;
    return res;
}

int main()
{
    MinStack *ms = new MinStack();

    Push(ms, 5); Min(ms);
    Push(ms, 4); Min(ms);
    Push(ms, 8); Min(ms);
    Push(ms, 1); Min(ms);
    Push(ms, 2); Min(ms);
    Pop(ms); Min(ms);
    Pop(ms); Min(ms);
    Pop(ms); Min(ms);
    Pop(ms); Min(ms);
    Pop(ms); Min(ms);

    return 0;
}