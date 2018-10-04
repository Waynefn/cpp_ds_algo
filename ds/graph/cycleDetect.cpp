#include <bits/stdc++.h>

using namespace std;

#define V (5)
#define M (INT_MAX)

int g[V][V] = 
{    
    {M,6,M,M,3},
    {M,M,3,7,M},
    {M,M,M,M,M},
    {M,M,9,M,M},
    {M,5,M,1,M}
};

bool IsCycle(int curr, bool visited[])
{
    visited[curr] = true;
    cout<<curr<<" ";
    for(int to = 0; to < V; to++)
    {
        if(g[curr][to] == 1 && visited[to])
            return true;
        return IsCycle(to, visited);
    }
}

void CycleDetect()
{
    static bool visited[V] = {false};
    for(int i = 0; i < V; i++)
        if(IsCycle(i, visited))
            cout<<"is cycle"<<endl;
}

int main()
{
    CycleDetect();
}
