#include <bits/stdc++.h>

using namespace std;

/**********************************************
    数组实现栈
**********************************************/
#define SIZE (3)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int st[SIZE];
int sp = 0;

#define BUFSIZE (100)

bool Empty()
{
    if(0 == sp)
        return true;
    return false;
}

void Push(int val)
{
    if(BUFSIZE == sp)
        return;
    st[sp++] = val;
}

int Pop()
{
    if(Empty())
        return -1;
    int ret = st[--sp];
    return ret;
}

int main()
{
    Push(5);
    Push(2);
    Push(9);
    Push(4);
    PRINT_ARRAY(st, sp);
    Pop();
    Pop();
    PRINT_ARRAY(st, sp);
    return 0;
}
