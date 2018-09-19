/*
http://www.cs.tsukuba.ac.jp/admission/29-8.pdf
	情报1(1)与情报1(2)是离散数学的题
	情报2(1)->优先队列的堆排序
	情报2(2)->有向无权重图
*/

#include <bits/stdc++.h>

using namespace std;

/***************************************
	情报2(1)->优先队列的堆排序
***************************************/
#define A 	
#define B 	
#define C 	
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
	q->a[0] = INT_MAX;		// (d) 如果 = 0会导致怎么样?
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
情报2(2)->有向无权重图
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