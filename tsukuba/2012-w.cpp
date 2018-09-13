/*
http://www.cs.tsukuba.ac.jp/admission/24-2inf.pdf
	问题1->List实现queue，有向无权重图最短路径
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->List实现queue，有向无权重图最短路径
	1.queue数据填空
	2.List实现queue的代码填空
	3.有向无权重图最短路径代码填空
	4.上一题的图用最少的边形成[强连接图]->图上任意2点存在有向路径
		N个顶点的强连通图,最多N*(N-1)条边,最少N条边
		所以此题的图至少需要环形的边,可成为强连通图
	ps:判断图是否是强连通:
		无向图:从某个顶点出发,BFS/DFS可以访问所有顶点
		有向图:
			方法1->对每一个顶点做DF,看是否每个顶点出发都能够访问所有顶点
			方法2->Tarjan算法求解连通分量
***************************************/
#define A 	10
#define B 	5
#define C 	5
#define D 	20
#define E 	_element *next
#define F 	element *head
#define G 	element *tail
#define H 	q->head == NULL
#define I 	node = q->head
#define J 	data = node->val
#define K 	q->head = node->next
#define L 	/**/

#define M 	enqueue(q, start)
#define N 	dequeue(q)
#define O 	dist[prev] + 1
#define P 	node == goal
#define Q 	enqueue(q, node)

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _element
{
	E;
	int val;
	_element()
	{
		next = NULL;		// !!一定要初始化动态分配后的指针
	}
}element;

typedef struct
{
	F;
	G;
}queue;

queue *make_queue()
{
	queue *q;
	q = new queue;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

int is_empty(queue *q)
{
	return H;
}

int dequeue(queue *q)
{
	element *node;
	int data;
	if(is_empty(q))
		return -1;
	I;
	J;
	K;
	if(q->head == NULL)
		q->tail = NULL;
	L;
	delete node;
	return data;
}

void enqueue(queue *q, int val)
{
	element *node = new element;
	node->val = val;

	if(q->head == NULL)
	{
		q->head = node;
		q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}

void destroy_queue(queue *q)
{
	while(!is_empty(q))
		cout<<dequeue(q)<<endl;
	delete q;
}

void test_queue()
{
	queue *q = make_queue();
	enqueue(q, A);
	enqueue(q, B);
	enqueue(q, C);
	enqueue(q, D);
	
	destroy_queue(q);
}

/*************************************************/
#define V (8)

int Adj[V][V] = 
{
	{0,1,1,0,0,0,0,0},
	{0,0,1,0,0,1,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0},
};

void test_graph(int start, int goal)
{
	queue *q;
	int dist[V];
	int prev, node;
	
	for(node = 0; node < V; node++)
		dist[node] = -1;

	q = make_queue();
	dist[start] = 0;
	M;
	while(!is_empty(q))
	{
		prev = N;
		for(node = 0; node < V; node++)
		{
			if(Adj[prev][node] == 1)
			{
				if(dist[node] == -1)
				{
					dist[node] = O;
					cout<<"visiting "<<node<<" from "<<prev<<" dist = "<<dist[node]<<endl;
					if(P)
					{
						cout<<"found from "<<start<<" to "<<goal<<" dist = "<<dist[node]<<endl;
						destroy_queue(q);
						return;
					}
					else
						Q;
				}
			}
		}
	}
	cout<<"No path found from "<<start<<" to "<<goal<<endl;
	destroy_queue(q);
}

void test_question_1()
{
	test_queue();
	test_graph(1,0);
}

int main()
{
	test_question_1();

	return 0;
}