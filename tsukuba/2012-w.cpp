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

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _element
{
	int val;
	_element *next;				// coding
	_element()
	{
		this->next = NULL;		// !!一定要初始化动态分配后的指针
	}
}element;

typedef struct
{
	element *head;		// coding
	element *tail;		// coding
}queue;

queue *make_queue()
{
	queue *q;
	q = new queue;
	q->head = NULL;
	q->tail = NULL;
	return q;			// coding
}

int is_empty(queue *q)
{
	return q->head == NULL;
}

int dequeue(queue *q)
{
	element *node;
	int data;
	if(is_empty(q))
		return -1;

	node = q->head;
	data = node->val;
	q->head = node->next;
	delete node;

	if(q->head == NULL)
		q->tail = NULL;

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
	enqueue(q, 10);
	enqueue(q, 5);
	enqueue(q, 5);
	enqueue(q, 20);
	
	destroy_queue(q);

}

/*************************************************/
#define N (8)

int Adj[N][N] = 
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
	int dist[N];
	int prev, node;
	
	for(node = 0; node < N; node++)
		dist[node] = -1;

	q = make_queue();
	dist[start] = 0;
	enqueue(q, start);								// coding

	while(!is_empty(q))
	{
		prev = dequeue(q);							// coding
		for(node = 0; node < N; node++)
		{
			if(Adj[prev][node] == 1)
			{
				if(dist[node] == -1)
				{
					dist[node] = dist[prev] + 1;	// coding
					cout<<"visiting "<<node<<" from "<<prev<<" dist = "<<dist[node]<<endl;
					if(node == goal)				// coding
					{
						cout<<"found from "<<start<<" to "<<goal<<" dist = "<<dist[node]<<endl;
						destroy_queue(q);
						return;
					}
					else
						enqueue(q, node);				// coding
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