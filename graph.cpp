#include <iostream>
#include <queue>
#include <limits.h>

#include "utils.h"

using namespace std;

/*
	1.拓扑排序

*/

#define M (INT_MAX)

/**********************************************
	拓扑排序
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

void topsort()
{
	int input[V_TOP] = {0};
	queue<int> q;
	queue<int> ret;

	// 计算所有顶点的入度
	for(int from = 0; from < V_TOP; from++)
		for(int to = 0; to < V_TOP; to++)
			if(g_top[from][to])
				input[to]++;

	// 找到起始顶点，入队
	for(int i = 0; i < V_TOP; i++)
		if(input[i] == 0)
			q.push(i);

	// 队列成员x出队&x指向的顶点的入度减少，减至0时也入队
	while(!q.empty())
	{
		int from = q.front(); q.pop();
		ret.push(from);
		for(int to = 0; to < V_TOP; to++)
		{
			if(g_top[from][to])
			{
				input[to]--;
				if(input[to] == 0)
					q.push(to);
			}
		}
	}

	while(!ret.empty())
	{
		cout<<ret.front()<<"-";
		ret.pop();
	}cout<<endl;
}

void test_topsort()
{
	PRINT_FUNCTION_NAME;
	topsort();
}

/**********************************************
	无权最短路径
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
	有权最短路径
**********************************************/
#define V_WEIGHTED (7)

typedef struct
{
	bool known;
	int dis;
}V_WEIGHTED_SET;

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

void dijkstra(int start, int goal)
{

}

void test_weighted()
{
	PRINT_FUNCTION_NAME;
}

int main()
{
	test_topsort();
	test_unweighted();
	test_weighted();

	return 0;
}