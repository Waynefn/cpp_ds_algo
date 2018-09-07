#include <bits/stdc++.h>

using namespace std;

#define V (7)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int g[V][V] = 
{
	{M,12,M,M,M,16,14},
	{12,M,10,M,M,7,M},
	{M,10,M,3,5,6,M},
	{M,M,3,M,4,M,M},
	{M,M,5,4,M,2,8},
	{16,7,6,M,2,M,9},
	{14,M,M,M,8,9,M},
};

int Prim_FindMin(int dist[], bool visited[])
{
	int min_dist = M, next = 0;
	for(int i = 0; i < V; i++)
		if(!visited[i] && min_dist > dist[i])
			min_dist = dist[i], next = i;
	return next;
}

void Prim(int start)
{
	int dist[V], prev[V], mst_cost = 0;
	bool visited[V];

	for(int to = 0; to < V; to++)
	{
		dist[to] = g[start][to];
		prev[to] = start;
		visited[to] = false;
	}

	dist[start] = 0;
	visited[start] = true;
	for(int i = 0; i < V-1; i++)
	{
		int curr = Prim_FindMin(dist, visited);
		visited[curr] = true;

		int from = prev[curr];
		mst_cost += g[from][curr];
		cout<<"add edge g["<<from<<"]["<<curr<<"] = "<<g[from][curr]<<endl;
		for(int to = 0; to < V; to++)
		{
			if(!visited[to] && g[curr][to] < dist[to])
			{
				dist[to] = g[curr][to];
				prev[to] = curr;
			}
		}
	}
	cout<<"mst cost = "<<mst_cost<<endl;
}

int main()
{
	Prim(0);
}