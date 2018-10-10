#include <bits/stdc++.h>

using namespace std;

/***************************************
	情报2(1)->优先队列的堆排序
***************************************/
#define A 	2*i
#define B 	2*i+1
#define C 	a[1]
#define D 	i/2
#define E 	INT_MAX
#define F 	q->a[i] = q->a[j]
#define G 	0
#define H 	N_VERT
#define I 	
#define J 	
#define K 	dist_vec[j]
#define L 	next[len_next]
#define M 	j

#define SIZE (100)
#define Len(x)	sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct
{
	int n;
	int a[SIZE];
}pq;

pq *newq()
{
	pq *q = (pq *)malloc(sizeof(pq));
	q->n = 0;
	q->a[0] = INT_MAX;
	return q;
}

void putq(pq *q, int v)
{
	int i = ++(q->n);
	while(q->a[i/2] <= v)
	{
		q->a[i] = q->a[D];
		i = i/2;
	}
	q->a[i] = v;
}

int getq(pq *q)
{
	int i = 1, j, v, w;
	if(q->n == 0)
		return E;
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
			F;
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
	情报2(2)->BFS最短路径 by邻接表
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
		dist_vec[i] = UNREACH;	// 初始化距离-1,表示尚未访问  

	curr[0] = origin;
	dist_vec[origin] = 0;
	while(len_curr > 0)			// while(!q.empty())
	{
		cout<<"此次BFS的起点: "; PRINT_ARRAY(curr, len_curr);
		for(i = 0; i < len_curr; i++)	// curr[i]:从队列curr取出的顶点x
		{
			for(j = adj_index[curr[i]]; j < adj_index[curr[i]+1]; j++)	// 通过下标adj_index[x] ~ adj_index[x+1],可以在adj_list[]中取得连通到的顶点
			{
				if(dist_vec[adj_list[j]] == UNREACH)	// adj_list[j]即连通到的顶点，dist_vec[adj_list[j]] = -1 即尚未访问
				{
					dist_vec[adj_list[j]] = dist;		// adj_list[j]未访问过,更新其距离
					next[len_next] = adj_list[j];		// adj_list[j]执行"入队"操作
					len_next++;							// "队列"元素+1
				}
			}
		}
		tmp = next;
		next = curr;
		curr = tmp;
		len_curr = len_next;	// BFS搜索下一层
		len_next = 0;
		dist++;
	}
	cout<<"顶点"<<origin<<"到其他各顶点的距离为：";	
	PRINT_ARRAY(dist_vec, N_VERT);
}

void test_question_2()
{
	int res[N_VERT];
	calc_dists(0, res);
}

int main()
{
	test_question_1();
	test_question_2();

	return 0;
}