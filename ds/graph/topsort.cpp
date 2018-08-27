#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

#define V (7)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int g[V][V] =
{
	{0,1,1,1,0,0,0},
	{0,0,0,1,1,0,0},
	{0,0,0,0,0,1,0},
	{0,0,1,0,0,1,1},
	{0,0,0,1,0,0,1},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0},
};

void Topsort_CalcIndegree(int indegree[])
{
	for(int from = 0; from < V; from++)
		for(int to = 0; to < V; to++)
			if(g[from][to])
				indegree[to]++;
}

void Topsort()
{
	int indegree[V] = {0};
	queue<int> q;

	Topsort_CalcIndegree(indegree);

	for(int i = 0; i < V; i++)
		if(indegree[i] == 0)
			q.push(i);

	while(!q.empty())
	{
		int curr = q.front(); q.pop();
		cout<<curr<<" ";
		for(int to = 0; to < V; to++)
		{
			if(g[curr][to])
			{
				indegree[to]--;
				if(indegree[to] == 0)
					q.push(to);
			}
		}
	}cout<<endl;
}

void test_Topsort()
{
	Topsort();
}

int main()
{
	test_Topsort();
	return 0;
}