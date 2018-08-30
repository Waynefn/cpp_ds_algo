#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

#define V (7)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int g[V][V] = 
{
    {0,2,M,1,M,M,M},
    {M,0,M,3,10,M,M},
    {4,M,0,M,M,5,M},
    {M,M,2,0,2,8,4},
    {M,M,M,M,0,M,6},
    {M,M,M,M,M,0,M},
    {M,M,M,M,M,1,0},
};

void Dijkstra_Path(int prev[], int goal)
{
    if(-1 == goal)
        return;
    Dijkstra_Path(prev, prev[goal]);
    cout<<goal<<"-";
}

int Dijkstra_FindMin(int dist[], bool visited[])
{
    int min_dist = M, next = 0;
    for(int i = 0; i < V; i++)
        if(!visited[i] && min_dist > dist[i])
            min_dist = dist[i], next = i;
    return next;
}

void Dijkstra(int start, int goal)
{
    int dist[V], prev[V];
    bool visited[V];
    
    for(int i = 0; i < V; i++)
    {
        dist[i] = M;
        prev[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;
    while(!visited[goal])
    {
        int curr = Dijkstra_FindMin(dist, visited);
        visited[curr] = true;
        cout<<"curr = "<<curr<<endl;
        for(int to = 0; to < V; to++)
        {
            if(g[curr][to] < M && dist[curr] + g[curr][to] < dist[to])
            {
                dist[to] = g[curr][to] + dist[curr];
                prev[to] = curr;
            }
        }
    }
    PRINT_ARRAY(dist, V);
    cout<<"Dijkstra("<<start<<", "<<goal<<") = "<<dist[goal]<<endl;
    Dijkstra_Path(prev, goal); cout<<endl;
}

int main()
{
    Dijkstra(0,5);
}