#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

#define V (7)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

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