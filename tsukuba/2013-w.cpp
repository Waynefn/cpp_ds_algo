/*
http://www.cs.tsukuba.ac.jp/admission/25-2inf.pdf
	问题1->Dijkstra
	问题2->离散数学的题
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->Dijkstra
	1.根据图来补充矩阵数据
	2.完成部分代码
	3.select_min的输出顺序为[1,0,2,5,3,4]
	4.顶点1为起点,算法最终结果d[] = {5,0,6,11,15,10}
***************************************/
#define M (9999)
#define N (6)

int graph[N][N] = 
{
	{0,  M,  M,  60, M,  5},	// 0
	{5,  0,  6,  M,  50, M},	// 1
	{M,  M,  0,  5,  M,  M},	// 2
	{M,  M,  M,  0,  5,  M},	// 3
	{30, M,  20, M,  0,  M},	// 4
	{M,  40, M,  M,  5,  0},	// 5
};

typedef struct
{
	bool Vertex[N];	// true则属于集合
	int Vcount;		// 集合内元素个数，即true的节点个数
}vertices;

void set_vertices(vertices *v, bool b)
{
	int i ;
	for(i = 0; i < N; i++)
		v->Vertex[i] = b;
	if(b == true)
		v->Vcount = N;
	else
		v->Vcount = 0;
}

bool remain(vertices *v)
{
	if(v->Vcount > 0)	// coding
		return true;
	return false;
}

bool member(int x, vertices *v)
{
	return v->Vertex[x] == true;	// coding
}

int select_min(int d[N], vertices *v)	// 函数未提供
{
	int min = M;
	int v_index;
	for(int i = 0; i < N; i++)
	{
		if(v->Vertex[i] == true && d[i] < min)
		{
			min = d[i];
			v_index = i;
		}
	}
	cout<<"select min = "<<v_index<<endl;
	return v_index;
}

void add_vertex(int u, vertices *v)		// 函数未提供
{
	v->Vertex[u] = true;
	v->Vcount++;
}

void remove_vertex(int u, vertices *v)	// 函数未提供
{
	v->Vertex[u] = false;
	v->Vcount--;
}

/*
	p:起点的顶点
	w:图的矩阵
	d:d[i]存放起点p到顶点i的距离,初始都为M
*/
void Dijkstra(int p, int w[N][N], int d[N])
{
	int i, u, x, k;
	vertices U, V;

	set_vertices(&U, true);	
	set_vertices(&V, false);

	for(i = 0; i < N; i++)
		d[i] = M;
	d[p] = 0;
	
	while(remain(&U))	
	{
		u = select_min(d, &U);
		add_vertex(u, &V);
		remove_vertex(u, &U);
		for(x = 0; x < N; x++)
		{
			if(graph[u][x] < M && member(x, &U))
			{
				k = d[u] + graph[u][x];
				if(k < d[x])
					d[x] = k;
			}
		}
	}
}

void test_question_1()
{
	int res[N];
	Dijkstra(1, graph, res);

	for(int i = 0; i < N; i++)
		cout<<res[i]<<"-";
	cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}