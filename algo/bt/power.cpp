#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])

/**********************************************
    集合的幂集
**********************************************/
void power(int a[], bool visited[], int n, int curr)
{
    if(curr >= n)
    {
        for(int i = 0; i < n; i++)
            if(visited[i])
                cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        visited[curr] = true;
        power(a, visited, n, curr+1);
        visited[curr] = false;
        power(a, visited, n, curr+1);
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    bool visited[Len(a)] = {false};
    power(a, visited, Len(a), 0);
    return 0;
}