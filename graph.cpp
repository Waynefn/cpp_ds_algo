#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>

#include "utils.h"

using namespace std;

/*
	1.拓扑排序
	2.无权最短路径
	3.dijkstra
*/

#define M (INT_MAX)

/**********************************************
	1.拓扑排序
**********************************************/
#define V_TOP (7)

int g_top[V_TOP][V_TOP] =
{
	{0,1,1,1,0,0,0},
	{0,0,0,1,1,0,0},
	{0,0,0,0,0,1,0},
	{0,0,1,0,0,1,1},
	{0,0,0,1,0,0,1},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0},
};

void topsort_calc_indegree(int indegree[])
{
	// 计算所有顶点的入度
	for(int from = 0; from < V_TOP; from++)
		for(int to = 0; to < V_TOP; to++)
			if(g_top[from][to])
				indegree[to]++;
}

// 删除del,del指向的顶点的入度也将减少
void topsort_remove_node(int del, int indegree[], queue<int> &q)
{
	for(int to = 0; to < V_TOP; to++)
	{
		if(g_top[del][to])	// to顶点的入度也减少至0,入队待删除
		{
			indegree[to]--;
			if(indegree[to] == 0)
				q.push(to);
		}
	}
}

void topsort_print_result(queue<int> &ret)
{
	while(!ret.empty())
	{
		cout<<ret.front()<<"-";
		ret.pop();
	}cout<<endl;
}

void topsort()
{
	int indegree[V_TOP] = {0};
	queue<int> q;
	queue<int> ret;

	topsort_calc_indegree(indegree);

	// 找到起始顶点，入队
	for(int i = 0; i < V_TOP; i++)
		if(indegree[i] == 0)
			q.push(i);

	// 队列成员x出队&x指向的顶点的入度减少，减至0时也入队
	while(!q.empty())
	{
		int del_node = q.front(); q.pop();
		ret.push(del_node);
		topsort_remove_node(del_node, indegree, q);
	}

	topsort_print_result(ret);
}

void test_topsort()
{
	PRINT_FUNCTION_NAME;
	topsort();
}

/**********************************************
	2.无权最短路径
**********************************************/
#define V_UNWEIGHTED (7)

typedef struct
{
	bool known;
	int dis;
}V_UNWEIGHTED_SET;

int g_unweighted[V_UNWEIGHTED][V_UNWEIGHTED] = 
{
	{0,1,M,1,M,M,M},
	{M,0,M,1,1,M,M},
	{1,M,0,M,M,1,M},
	{M,M,1,0,1,1,1},
	{M,M,M,M,0,M,1},
	{M,M,M,M,M,0,M},
	{M,M,M,M,M,1,0},
};

void unweighted(int start, int goal)
{
	V_UNWEIGHTED_SET set[V_UNWEIGHTED];
	queue<int> q;

	// 初始化start到所有顶点的距离,到自身距离为0
	for(int i = 0; i < V_UNWEIGHTED; i++)
	{
		set[i].known = false;
		set[i].dis = M;
	}
	set[start].dis = 0;

	// 起点入栈，开始BFS搜索
	q.push(start);
	while(!q.empty())
	{
		int from = q.front(); q.pop();
		set[from].known = true;

		for(int to = 0; to < V_UNWEIGHTED; to++)
		{
			// 从[已知顶点]向外探索,发现可以前往的[未知顶点]
			if(!set[to].known && g_unweighted[from][to] < M)
			{
				// 更新[前往未知顶点的距离],并标记为已知,然后入队以便下一轮往更深处探索
				set[to].known = true;
				set[to].dis = set[from].dis + 1;
				q.push(to);
			}
		}
	}

	for(int i = 0; i < V_UNWEIGHTED; i++)
		cout<<"from "<<start<<" to "<<i<<" dis = "<<set[i].dis<<endl;
}

void test_unweighted()
{
	PRINT_FUNCTION_NAME;
	unweighted(2, 6);
}

/**********************************************
	3.dijkstra 有权最短路径
**********************************************/
#define V_WEIGHTED (7)

typedef struct
{
	bool known[V_WEIGHTED];
	int cnt;
}V_WEIGHTED_SET;

int g_dijkstra[V_WEIGHTED][V_WEIGHTED] = 
{
	{0,2,M,1,M,M,M},
	{M,0,M,3,10,M,M},
	{4,M,0,M,M,5,M},
	{M,M,2,0,2,8,4},
	{M,M,M,M,0,M,6},
	{M,M,M,M,M,0,M},
	{M,M,M,M,M,1,0},
};

void dijkstra_init(int start, bool visited[], int prev[], int dis[])
{
	// 初始化所有顶点未被探索,start到其他顶点的距离
	for(int to = 0; to < V_WEIGHTED; to++)
	{
		visited[to] = false;
		prev[to] = 0;
		dis[to] = g_dijkstra[start][to];
	}
}

int dijkstra_find_min(int dis[], bool visited[])
{
	// 从dis[]中找到当前最短路径的顶点(第一轮必定找到start顶点), 标记为已知
	int curr, min = M;
	for(int i = 0; i < V_WEIGHTED; i++)
	{
		if(!visited[i] && dis[i] < min)
		{
			curr = i;
			min = dis[i];
		}
	}
	visited[curr] = true;

	return curr;
}

void dijkstra_print_process(queue<int> &path)
{
	// 输出算法探索顶点的过程
	cout<<"dijkstra process : ";
	while(!path.empty())
	{
		int v = path.front(); path.pop();
		cout<<v<<"-";
	}cout<<endl;
}

void dijkstra_print_way(int start, int goal, int dis[], int prev[])
{
	// 输出start到goal的路径
	int find = goal;
	stack<int> ret;
	while(find != start)
	{
		ret.push(find);
		find = prev[find];
	}
	cout<<"found "<<start<<" to "<<goal<<" path : "<<endl;
	cout<<"->start "<<start<<", 距离为"<<dis[start]<<endl;
	while(!ret.empty())
	{
		int i = ret.top(); ret.pop();
		cout<<"->visit "<<i<<", 距离为"<<dis[i]<<endl;
	}cout<<endl;
}

void dijkstra(int start, int goal)
{
	bool visited[V_WEIGHTED];	// visited[x]:表示x顶点是否已经被找到最短路径
	int prev[V_WEIGHTED];		// 保存start到goal的最终路径结果
	int dis[V_WEIGHTED];		// dis[x]:表示从start到x的最短距离
	int visited_cnt = 0;		// 记录当前已经寻找到最短路径的顶点数
	queue<int> path;			// 记录算法探索的顶点顺序

	dijkstra_init(start, visited, prev, dis);

	while(visited_cnt < V_WEIGHTED)		// 还有未探索顶点就继续
	{
		int curr = dijkstra_find_min(dis, visited); // 找到本轮最短距离的顶点curr

		visited_cnt++;		// 已确定的[最短距离]顶点+1
		path.push(curr);	// 入队保存算法过程

		for(int i = 0; i < V_WEIGHTED; i++)
		{
			if(!visited[i] && g_dijkstra[curr][i] < M) 				// 顶点i尚未被确定最短距离 && curr可以达到i
			{
				if(g_dijkstra[curr][i] + dis[curr] < dis[i])		
				{
					dis[i] = g_dijkstra[curr][i] + dis[curr];		// 从[curr]到[i]比dis[i]的距离短,更新dis[i]
					prev[i] = curr;									// 记录此次找到的i路径的前驱是curr
				}
			}
		}
	}

	dijkstra_print_process(path);
	dijkstra_print_way(start, goal, dis, prev);	
}	

void test_dijkstra()
{
	PRINT_FUNCTION_NAME;
	dijkstra(0, 5);
}

/**********************************************
	4.prim 最小生成树
**********************************************/



int main()
{
	test_topsort();
	test_unweighted();
	test_dijkstra();

	return 0;
}