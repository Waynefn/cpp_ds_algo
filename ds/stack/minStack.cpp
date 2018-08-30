#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

/**********************************************
    s实现方法min()可以O(1)时间内返回s中的最小值
    s1:正常的操作
    s2：与s1保持元素一样多，每次pop时和s1一样。但push时只push当前最小值
    min()：s2.pop()即可
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
    if(ms->s2.empty())
        ms->min = INT_MAX;
    else    // 之前的min可能已经被pop，所以每次push时都要再次从s2获取
        ms->min = ms->s2.top(); 
    ms->min = ms->min < x ? ms->min : x;

    ms->s1.push(x);
    ms->s2.push(ms->min);
}

int Pop(MinStack *ms)
{
    if(ms->s1.empty())
        return -1;

    int res = ms->s2.top();
    ms->s1.pop(); ms->s2.pop();
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