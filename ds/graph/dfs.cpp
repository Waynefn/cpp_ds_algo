#include <iostream>
#include <queue>
#include <limits.h>

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

void Dfs_r(int curr, bool visited[])
{
	visited[curr] = true;
	cout<<curr<<" ";
	for(int to = 0; to < V; to++)
		if(!visited[to] && g[curr][to] < M)
			Dfs_r(to, visited);
}

void Dfs()
{
	static bool visited[V] = {false};
	for(int i = 0; i < V; i++)
		if(!visited[i])
			Dfs_r(i, visited);
}

int main()
{
	Dfs();
}