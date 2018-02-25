#include <iostream>
#include <string>
#include <string.h>

#include "utils.h"

using namespace std;

int a[] = {8,2,4};
int tmp[3];
bool label[] = {false};

bool f(int n, int x, int s, int k)
{
    if(x >= n)
        return s == k;
    else
    {
        return f(n, x+1, s, k) || f(n, x+1, s+a[x], k);
    }
}

int main()
{
    bool ret = f(3, 0, 0, 10);
    cout<<"ret = "<<ret<<endl;
    return 0;
}