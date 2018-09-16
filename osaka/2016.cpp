/*
http://www.ist.osaka-u.ac.jp/japanese/admission/docs/H29jyouhoukougaku%20.pdf
	问题1->带权重最短路径
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->带权重最短路径
	4.算法不变的前提下求所有点到点最短距离
		4.1 对于4个顶点6种组合，最少需要调用三次函数
			compute(w,n,0,3)
			compute(w,n,1,3)
			compute(w,n,2,3)
		4.2 算法终止语句改为 while(visited[d] == 0)，导致遇到了终点就会提前结束算法
			compute(w,n,0,3) 0找到3的路径时，2有可能尚未被访问到
			只能通过len[2] == -1来间接判断是否此轮也访问过2
***************************************/
#define INF (255)
#define MAXN (16)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int len[MAXN];
int prev[MAXN];

void printpath(int v)
{
	if(v != -1)
	{
		printpath(prev[v]);
		cout<<"- "<<v<<" ";
	}
}

int allvisited(int a[], int n)
{
	int i, r = 1;
	for(i = 0; i < n; i++)
		r *= a[i];
	return r;
}

void compute(int w[], int n, int s, int d)
{
	int i, j, next, min, visited[MAXN];

	for(i = 0; i < n; i++)
	{
		len[i] = INF;
		visited[i] = 0;
		prev[i] = -1;
	}

	i = s;
	len[i] = 0;
	visited[i] = 1;

	while(allvisited(visited, n) == 0)	// while(visited[d] == 0)
	{
		min = INF; next = d;
		for(j = 0; j < n; j++)
		{
			if(visited[j] == 1)	
				continue;
			if(len[j] > len[i] + w[i*n+j])
			{
				len[j] = len[i] + w[i*n+j];
				prev[j] = i;
			}
			if(min > len[j])
			{
				min = len[j];
				next = j;
			}
		}
		i = next;
		visited[i] = 1;
	}
	PRINT_ARRAY(len, n);
	PRINT_ARRAY(prev, n);
}

void test_question_1()
{
	int w[] = 
	{
		0,2,5,INF,
		2,0,1,1,
		5,1,0,2,
		INF,1,2,0
	};
	int n = 4;

	compute(w,n,0,3);
	cout<<"shortest path length from 0 to 3 :"<<len[3]<<endl;

	printpath(3); cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}