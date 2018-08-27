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

void ShortPath_Print(int prev[], int goal)
{
	if(-1 == goal)
		return;
	ShortPath_Print(prev, prev[goal]);
	cout<<goal<<"-";
}

void Bfs_ShortPath(int start, int goal)
{
	int dist[V] = {0}, prev[V] = {-1};
	bool visited[V] = {false};
	queue<int> q;

	q.push(start);
	dist[start] = 0;
	visited[start] = true;

	while(!q.empty())
	{
		int num = q.size();
		while(num--)
		{
			int curr = q.front(); q.pop();
			cout<<curr<<" ";
			for(int to = 0; to < V; to++)
			{
				if(!visited[to] && g[curr][to] < M)
				{
					visited[to] = true;
					prev[to] = curr;
					dist[to] = dist[curr] + 1;
					q.push(to);
				}
			}
		}cout<<"* ";
	}cout<<endl;
	cout<<"dist["<<start<<"]["<<goal<<"] = "<<dist[goal]<<endl;
	ShortPath_Print(prev, goal);
}

int main()
{
	Bfs_ShortPath(0,6);
}