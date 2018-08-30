#include <iostream>

using namespace std;

#define SIZE (3)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int q[SIZE];
int first = 0, last = 0;

bool Empty()
{
    if(first == last)
        return true;
    return false;
}

void Push(int val)
{
    if((last + 1)%SIZE == first)
        return;
    q[last++] = val;
    last %= SIZE;
}

int Pop()
{
    if(Empty())
        return -1;
    int ret = q[first++];
    first %= SIZE;
    return ret;
}

int main()
{
    Push(3);
    Push(5);
    Push(7);
    Pop();
    Pop();
    Pop();
    Push(9);
    Push(1);
    PRINT_ARRAY(q, SIZE);
}