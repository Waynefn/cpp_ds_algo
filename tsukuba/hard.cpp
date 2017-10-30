/*
http://www.cs.tsukuba.ac.jp/admission/29-8.pdf
	情报1(1)与情报1(2)是离散数学的题
	情报2(1)->优先队列的堆排序
	情报2(2)->有向无权重图
*/

#include <iostream>
#include <queue>

#include <stdlib.h>
#include <limits.h>

using namespace std;

/***************************************
	情报2(1)->优先队列的堆排序
***************************************/
#define SIZE (100)
#define Len(x)	sizeof(x)/sizeof(x[0])	

typedef struct
{
	int n;
	int a[SIZE];
}pq;

pq *newq()
{
	pq *q = (pq *)malloc(sizeof(pq));
	q->n = 0;
	q->a[0] = INT_MAX;		// (d) 如果 = 0会导致怎么样?
	return q;
}

void putq(pq *q, int v)
{
	int i = ++(q->n);
	while(q->a[i/2] <= v)
	{
		q->a[i] = q->a[i/2];	//coding
		i = i/2;
	}
	q->a[i] = v;
}

int getq(pq *q)
{
	int i = 1, j, v, w;
	if(q->n == 0)
		return INT_MAX;			//coding
	v = q->a[1];
	w = q->a[(q->n)--];
	while(i <= (q->n)/2)
	{
		j = 2*i;
		if(j < q->n && q->a[j] < q->a[j+1]) j++;
		if(w >= q->a[j])
			break;
		else
		{
			q->a[i] = q->a[j];	// coding
			i = j;
		}
	}
	q->a[i] = w;

	return v;
}

void test_question_1()
{
	int a[] = {4,5,6,7,1,2,3,9,0};
	pq * queue = newq();

	for(int i = 0; i < Len(a); i++)
		putq(queue, a[i]);
	for(int i = 0; i < Len(a); i++)
		cout<<getq(queue)<<"-";
	cout<<endl;
}

/***************************************
情报2(2)->有向无权重图
	1.找出图中ABCDEF对应的矩阵下标
	2.写出B为起点到其他各点的最短距离
	3.矩阵转换为邻接表后,写出adj_list和adj_index的值
		adj_list  = {0,    3,4,5,6,  8,9,  11} 存放指向adj_index的下标
		adj_index = {1,3,5,2,3,4,5,7,6,2,7,0}  存放邻接表
	4.BFS方式计算起点0至其他所有点的距离,结果保存到dist_vec数组
***************************************/
#define UNREACH (-1)
#define N_VERT	(8)

const int adj_mat[N_VERT][N_VERT] = 
{
	{0, 1, 0, 1, 0, 1, 0, 0},	// B = 0
	{0, 0, 1, 0, 0, 0, 0, 0},	// C = 1
	{0, 0, 0, 1, 0, 0, 0, 0},	// E = 2
	{0, 0, 0, 0, 1, 0, 0, 0},	// F = 3
	{0, 0, 0, 0, 0, 1, 0, 1},	// 4
	{0, 0, 0, 0, 0, 0, 1, 0},	// A = 5
	{0, 0, 1, 0, 0, 0, 0, 1},	// 6
	{1, 0, 0, 0, 0, 0, 0, 0},	// D = 7
};

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void calc_dists(const int origin, int dist_vec[])
{
/*
	int adj_list[N_VERT * N_VERT], adj_index[N_VERT + 1];
	int array1[N_VERT], array2[N_VERT];
	int *curr = array1, *next = array2, *tmp;
	int i, j, index = 0, dist = 1, len_curr = 1, len_next = 0;

	// 完成邻接表
	for(i = 0; i < N_VERT; i++)
	{
		adj_index[i] = index;
		for(j = 0; j < N_VERT; j++)
			if(adj_mat[i][j] == 1)
				adj_list[index++] = j;
	}
	adj_index[N_VERT] = index;

	print_array(adj_index, N_VERT+1);
	print_array(adj_list, 15);
*/
/* 以下算法是自行实现，与考题无关	*/
	bool visited[N_VERT] = {false};
	for(int i = 0; i < N_VERT; i++)
		dist_vec[i] = INT_MAX;
	dist_vec[origin] = 0;
	visited[origin] = true;
	
	queue<int> q;
	q.push(origin);
	while(!q.empty())
	{
		int curr = q.front(); q.pop();
		for(int to = 0; to < N_VERT; to++)
		{
			if(!visited[to] && adj_mat[curr][to])
			{
				dist_vec[to] = dist_vec[curr]+1;
				visited[to] = true;
				q.push(to);
			}
		}
	}

	cout<<"顶点"<<origin<<"到其他各顶点的距离为：";
	print_array(dist_vec, N_VERT);
}

void test_question_2()
{
	int res[N_VERT];
	calc_dists(0, res);

}

int main()
{
//	test_question_1();
	test_question_2();

	return 0;
}