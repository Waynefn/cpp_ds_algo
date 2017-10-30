/*
http://www.cs.tsukuba.ac.jp/admission/29-8.pdf
	情报1(1)与情报1(2)是离散数学的题
	情报2(1)->优先队列的堆排序
	情报2(2)->有向无权重图
		原题变量和填空太多，只能明白思路但代码没法填，用自己的代码实现了算法
*/

#include <iostream>
#include <stdlib.h>
#include <limits.h>

#include <queue>

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
	
		顶点 --> 邻接点
		0	 --> 1,3,5
		1	 --> 2
		2	 --> 3
		3	 --> 4
		4	 --> 5,7
		5	 --> 6
		6	 --> 2,7
		7 	 --> 0
	4.BFS方式计算起点0至其他所有点的距离,结果保存到dist_vec数组

	本题的思路为BFS,然而题目的意图和代码实现难度很高:
		adj_list  = {0,3,4,5,6,8,9,11},例如0和3
			for(i = 0; i < 3; i++) 
				adj_index[i]的值正好对应[顶点0的邻接顶点]
		题目设置了curr和next数组,用来模拟入队和出队
			curr数组:保存当前有待BFS的顶点i,是[已访问&&得到距离的顶点]
			next数组:保存i顶点邻接到的其他顶点j,是下一次[待访问和计算距离的顶点]
			每一轮BFS结束后,将curr与next交换,模拟[i出队并BFS搜索到j,然后j入队]
		虽然最后完成了题目,但没有使用题目给出的模拟邻接表,因为[探索表中某顶点对应的邻接顶点时,无法根据已知代码判断list是否结束]
	所以相比填充题目的代码,自行实现算法非常容易,参考calc_dists_self()
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

	for(i = 0; i < N_VERT; i++)
		dist_vec[i] = UNREACH;	// 初始化所有顶点距离为-1

	curr[0] = origin;
	dist_vec[origin] = 0;		// 初始化起点的距离
	while(len_curr > 0)			// 类似每一轮BFS前,队列里元素的个数
	{
		cout<<"此次BFS的起点: "; print_array(curr, len_curr);
		for(i = 0; i < len_curr; i++)	// 取出已访问的外层顶点i
		{
			for(j = 0; j < N_VERT; j++)	// 根据i,去更新与之相邻的更外层顶点j
			{
				if(adj_mat[curr[i]][j] == 1 && dist_vec[j] == UNREACH)
				{
					cout<<curr[i]<<"-->["<<j<<"] ";
					dist_vec[j] = dist;		// 更新探索到的节点的距离
					next[len_next] = j;		// 邻接点放入next中
					len_next++;
				}
			}
		}
		cout<<endl;

		tmp = next;
		next = curr;
		curr = tmp;
		len_curr = len_next;	// BFS搜索范围增加
		len_next = 0;
		dist++;
	}
	cout<<"顶点"<<origin<<"到其他各顶点的距离为：";	
	print_array(dist_vec, N_VERT);
}

void calc_dists_self(const int origin, int dist_vec[])
{
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
		cout<<"此次BFS的起点: "<<curr<<endl;
		for(int to = 0; to < N_VERT; to++)
		{
			if(!visited[to] && adj_mat[curr][to])
			{
				cout<<curr<<"-->["<<to<<"] ";
				dist_vec[to] = dist_vec[curr]+1;
				visited[to] = true;
				q.push(to);
			}
		}
		cout<<endl;
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

/* 没搞明白原题的代码思路，代码如下

void calc_dists(const int origin, int dist_vec[])
{
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
	print_array(adj_list, 20);

	// 初始化所有顶点距离为-1
	for(i = 0; i < N_VERT; i++)
		dist_vec[i] = UNREACH;

	curr[0] = origin;
	dist_vec[origin] = 0;	// 初始化起点的距离
	while(len_curr > 0)		// 每一轮BFS的探索距离
	{
		for(i = 0; i < len_curr; i++)
		{
			for(j = ; j < ; j++)	// coding
			{
				if( == )			// coding
				{
					 = dist;		// coding
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

*/