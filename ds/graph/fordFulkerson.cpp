#include <bits/stdc++.h>

using namespace std;

/**********************************************
    MaxFlow问题 FordFulkerson
    *注意g的不连通线段设置为INT_MAX的话，
     计算每一轮bfs路径中的min_flow时因为数值原因出错
**********************************************/
#define V (6)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}
#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++)  cout<<a[i][j]<<"|"; cout<<endl;}}

int g[V][V] = 
{
	{0,16,13,0,0,0},
	{0,0,10,12,0,0},
	{0,4,0,0,14,0},
	{0,0,9,0,0,20},
	{0,0,0,7,0,4},
	{0,0,0,0,0,0}
};

bool bfs(int rg[V][V], int s, int t, int prev[])
{
	bool visited[V] = {false};
	queue<int> q;
	q.push(s);
	visited[s] = true;
	prev[s] = -1;

	cout<<"BFS : ";
	while(!q.empty())
	{
		int from = q.front(); q.pop();
		cout<<from<<" ";
		for(int to = 0; to < V; to++)
		{
			if(!visited[to] && rg[from][to] > 0)
			{
				visited[to] = true;
				q.push(to);
				prev[to] = from;
			}
		}
	}cout<<endl;
	return visited[t] == true;
}

void FordFulkerson(int s, int t)
{
	int flow_ret = 0, prev[V];
	int rg[V][V];
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			rg[i][j] = g[i][j];

	while(bfs(rg, s, t, prev))
	{
		int min_flow = INT_MAX;
		cout<<"path : ";
		for(int to = t; to != s; to = prev[to])
		{
			cout<<to<<" ";
			int from = prev[to];
			min_flow = min(min_flow, rg[from][to]);
		}cout<<" curr min_flow = "<<min_flow<<endl;;
		for(int to = t; to != s; to = prev[to])
		{
			int from = prev[to];
			rg[from][to] -= min_flow;
			rg[to][from] += min_flow;
		}cout<<endl;
		flow_ret += min_flow;
		PRINT_MATRIX(rg, V, V);
	}
	cout<<"max flow = "<<flow_ret<<endl;
}

int main()
{
	FordFulkerson(0, V-1);
	return 0;
}