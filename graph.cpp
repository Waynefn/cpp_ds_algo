#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>

#include "utils.h"

using namespace std;

/*
	1.BFS & DFS
	2.拓扑排序
	3.无权最短路径
	4.dijkstra
	 		图参照onenote笔记
	5.floyd
	6.最小生成树 minimal spanning tree
		prim
		kruskal
*/

#define M (INT_MAX)

/**********************************************
	1.BFS & DFS
**********************************************/
#define V (7)

typedef struct
{
	bool known[V];
	int cnt;
}V_SET;

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

void bfs(int start)
{
	bool visited[V] = {false};
	queue<int> q;

	q.push(start);
	visited[start] = true;
	
	cout<<"BFS搜索结果：";
	while(!q.empty())
	{
		int lvSize = q.size();
		while(lvSize)
		{
			lvSize--;
			int curr = q.front(); q.pop();
			cout<<curr<<" ";
			for(int to = 0; to < V; to++)
			{
				if(!visited[to] && g[curr][to] < M)
				{
					q.push(to);
					visited[to] = true;
				}
			}
		}
		cout<<" | ";
	}
	cout<<endl;
}

void dfs(int start)
{
	static bool visited[V] = {false};

	visited[start] = true;
	cout<<start<<" ";
	for(int to = 0; to < V; to++)
	{
		if(!visited[to] && g[start][to] < M)
			dfs(to);
	}
}

void dfs_2(int start)
{
	
}

void test_bfs_dfs()
{
	bfs(0);
	cout<<"DFS搜索结果：";dfs(0);cout<<endl;
}

/**********************************************
	2.拓扑排序
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
	3.无权最短路径
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
	4.dijkstra 有权最短路径 
**********************************************/
#define V_WEIGHTED (7)

int g_weighted[V_WEIGHTED][V_WEIGHTED] = 
{
	{0,2,M,1,M,M,M},
	{M,0,M,3,10,M,M},
	{4,M,0,M,M,5,M},
	{M,M,2,0,2,8,4},
	{M,M,M,M,0,M,6},
	{M,M,M,M,M,0,M},
	{M,M,M,M,M,1,0},
};

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

cout<<"11111  ："<<start<<" -- "<<goal<<endl;

	int find = goal;
	stack<int> ret;
	while(find != start)
	{
	//	cout<<"find = "<<find<<endl;
		ret.push(find);
		find = prev[find];
	}
cout<<"222"<<endl;
	cout<<"found "<<start<<" to "<<goal<<" path : "<<endl;
	cout<<"->start "<<start<<", 距离为"<<dis[start]<<endl;
	while(!ret.empty())
	{
		int i = ret.top(); ret.pop();
		cout<<"->visit "<<i<<", 距离为"<<dis[i]<<endl;
	}cout<<endl;
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

	return curr;
}

void dijkstra(int start, int goal)
{
	PRINT_SUB_FUNCTION_NAME;

	bool visited[V_WEIGHTED];	// visited[x]:表示x顶点是否已经被找到最短路径
	int dis[V_WEIGHTED];		// dis[x]:表示从start到x的最短距离

	int prev[V_WEIGHTED];		// 保存start到goal的最终路径结果	
	queue<int> path;			// 记录算法探索的顶点顺序

	for(int to = 0; to < V_WEIGHTED; to++)
	{
		visited[to] = false;
		prev[to] = start;
		dis[to] = g_weighted[start][to];
	}

	while(!visited[goal])		// 还有未探索顶点就继续
	{
		int curr = dijkstra_find_min(dis, visited); // 找到本轮最短距离的顶点curr

		visited[curr] = true;	// curr顶点已访问
		path.push(curr);		// 入队保存算法过程

		for(int i = 0; i < V_WEIGHTED; i++)	// 优化：遍历【未被置为true】的顶点
		{
			if(!visited[i] && g_weighted[curr][i] < M) 				// 顶点i尚未被确定最短距离 && curr可以达到i
			{
				if(g_weighted[curr][i] + dis[curr] < dis[i])		
				{
					dis[i] = g_weighted[curr][i] + dis[curr];		// 从[curr]到[i]比dis[i]的距离短,更新dis[i]
					prev[i] = curr;									// 记录此次找到的i路径的前驱是curr
				}
			}
		}
	}

	dijkstra_print_process(path);
	dijkstra_print_way(start, goal, dis, prev);
}	

void floyd()
{
	PRINT_SUB_FUNCTION_NAME;

	int dist[V_WEIGHTED][V_WEIGHTED], i, j, k;
 
    for(i = 0; i < V_WEIGHTED; i++)
        for(j = 0; j < V_WEIGHTED; j++)
            dist[i][j] = g_weighted[i][j];

    for(k = 0; k < V_WEIGHTED; k++)
        for(i = 0; i < V_WEIGHTED; i++)
            for(j = 0; j < V_WEIGHTED; j++)
                if(dist[i][k] < M && dist[k][j] < M 	// 注意：【dist<M】才表示有通路。不判断的话会造成数值溢出	
                && dist[i][k] + dist[k][j] < dist[i][j])
                   	dist[i][j] = dist[i][k] + dist[k][j];

    for(int i = 0; i < V_WEIGHTED; i++)
    {
        for(int j = 0; j < V_WEIGHTED; j++)
        {
            if(dist[i][j] == M)	cout<<"M ";
            else				cout<<dist[i][j]<<" ";    
        }
        cout<<endl;
    }
}

void test_weighted()
{
	PRINT_FUNCTION_NAME;
	dijkstra(1, 0);
	floyd();
}

/**********************************************
	6.最小生成树 minimal spanning tree
		prim
		kruskal
**********************************************/
int g_mst[V][V] = 
{
	{M,12,M,M,M,16,14},
	{12,M,10,M,M,7,M},
	{M,10,M,3,5,6,M},
	{M,M,3,M,4,M,M},
	{M,M,5,4,M,2,8},
	{16,7,6,M,2,M,9},
	{14,M,M,M,8,9,M},
};

int prim_find_min(bool visited[], int dist[])
{
	int min_dist = M, to;
	for(int i = 0; i < V; i++)
	{
		if(!visited[i] && dist[i] < min_dist)
		{
			to = i;
			min_dist = dist[i];
		}
	}

	return to;
}

void prim(int start)
{
	bool visited[V] = {false};
	int dist[V];
	int prev[V];
	int ret_mst_cost = 0;
	
	for(int i = 0; i < V; i++)
	{
		dist[i] = g_mst[start][i];	// 初始化start到所有顶点的距离
		prev[i] = start;			// 所有顶点的前驱是start
	}

	dist[start] = 0;				// 起点距离为0
	visited[start] = true;			// 从起点开始探索

	int mst_target_edge = V-1;		// 加入的边达到V-1时，算法结束
	while(mst_target_edge)
	{
		int to = prim_find_min(visited, dist);	// 找到目前能探索到的最短边的顶点
		int from = prev[to];					// 找到边的另一端顶点
		cout<<"add edge ["<<from<<"]["<<to<<"] = "<<g_mst[from][to]<<endl;

		visited[to] = true;

		// 刚刚探索到了顶点to，原先start探索不到的顶点，现在有可能与顶点to相连，所以更新其他所有顶点的dist和prev
		for(int i = 0; i < V; i++)
		{
			if(!visited[i] && g_mst[i][to] < dist[i])
			{
				dist[i] = g_mst[i][to];
				prev[i] = to;
			}
		}

		mst_target_edge--;
		ret_mst_cost += g_mst[from][to];
	}

	cout<<"prim mst_cost:"<<ret_mst_cost<<endl;
}

void test_mst()
{
	PRINT_FUNCTION_NAME;
	prim(0);
}

int main()
{
	// test_bfs_dfs();
	// test_topsort();
	// test_unweighted();
	test_weighted();

	test_mst();
	return 0;
}