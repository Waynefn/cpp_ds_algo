/*
	情报1(1)与情报1(2)是离散数学的题
	情报2(1)->优先队列的堆排序
	情报2(2)->有向无权重图
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
	情报2(1)->优先队列的堆排序
***************************************/
#define SIZE (100)
#define INT_MAX (9999)
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
		cout<<"++++  "<<v<<endl;
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
		cout<<getq(queue);
}

/***************************************
情报2(2)->有向无权重图
	1.找出图中ABCDEF对应的矩阵下标
	2.写出B为起点到其他各点的最短距离
	3.矩阵转换为邻接表后,写出adj_list和adj_index的值
		adj_list  = {0,    3,4,5,6,  8,9,  11} 存放指向adj_index的下标
		adj_index = {1,3,5,2,3,4,5,7,6,2,7,1}  存放邻接表
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

void calc_dists(const int origin, int dist_vec[])
{
	int adj_list[N_VERT * N_VERT], adj_index[N_VERT + 1];
	int array1[N_VERT], array2[N_VERT];
	int *curr = array1, *next = array2, *tmp;
	int i, j, index = 0, dist = 1, len_curr = 1, len_next = 0;

	for(i = 0; i < N_VERT; i++)
	{
		adj_index[i] = index;
		for(j = 0; j < N_VERT; j++)
			if(adj_mat[i][j] == 1)
				adj_list[index++] = j;
	}
	adj_index[N_VERT] = index;

	for(i = 0; i < N_VERT; i++)
		dist_vec[i] = UNREACH;

	curr[0] = origin;
	dist_vec[origin] = 0;	// 初始化起点的距离
	while(len_curr > 0)		// 每一轮BFS的探索距离
	{
		for(i = 0; i < len_curr; i++)
		{
			for(j = adj_index[i]; j < adj_index[i+1]; j++)	// coding
			{
				if(adj_mat[i][j] == 1)			// coding
				{
					dist_vec[j] = dist;		// coding
					  = ;			// coding
					len_next++;
				}
			}
		}
		tmp = next;
		next = curr;
		curr = tmp;
		len_curr = len_next;	// BFS搜索范围增加
		len_next = 0;
		dist++;
	}
}

void test_question_2()
{
	int res[N_VERT];
	calc_dists(0, res);

	for(int i = 0; i < N_VERT; i++)
		cout<<res[i]<<"-";
	cout<<endl;
}

int main()
{
	test_question_1();
	test_question_2();

	return 0;
}