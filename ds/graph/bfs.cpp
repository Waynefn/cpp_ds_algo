#include <bits/stdc++.h>

using namespace std;

#define V (7)
#define M (INT_MAX)

int g[V][V] = 
{    
    {M,1,M,M,M,M,M},
    {M,M,1,M,1,1,M},
    {M,M,M,M,1,M,M},
    {M,M,1,M,M,M,M},
    {M,1,M,1,M,M,M},
    {M,M,M,M,M,M,1},
    {M,M,M,M,M,M,M},
};

void Bfs(int start)
{
    bool visited[V] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int from = q.front(); q.pop();
        cout<<from<<" ";
        for(int to = 0; to < V; to++)
        {
            if(!visited[to] && g[from][to] < M)
            {
                visited[to] = true;
                q.push(to);
            }
        }
    }cout<<endl;
}

int main()
{
    Bfs(0);
}