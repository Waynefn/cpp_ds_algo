/*
http://
	问题1->拓扑排序
	问题2->卡诺图
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->拓扑排序
	1.根据矩阵画出有向图
	2.完成count_indegree()函数
	3.写出拓扑排序后sorted[]数组的结果
		4-2-1-0-3
	4.排序后返回值cnt==N(顶点数)时,有向图符合什么特性
		也就是最后所有顶点都形成拓扑->没有环形or没有对称性(a->b, b!->a)
	5.有向图满足上述特性时,sort()函数是可以对顶点排序达成某种条件,是什么?
		全順序関係　https://ja.wikipedia.org/wiki/%E5%85%A8%E9%A0%86%E5%BA%8F
***************************************/
#define Len(x)	sizeof(x)/sizeof(x[0])
#define N (5)

int sorted[N], indegree[N], nodestack[N], stackp = 0;
char a[N][N] = 
{
	{0,0,0,1,0},
	{1,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,0,1,0,0},
};

// 求所有顶点的[入度]个数
void count_indegree()
{
	int tail, head;
	for(head = 0; head < N; head++)
	{
		indegree[head] = 0;
		// 以下内容为coding
		for(tail = 0; tail < N; tail++)
			if(a[tail][head] == 1)
				indegree[head]++;
	}
}

void remove_node(int node)
{
	int head;
	for(head = 0; head < N; head++)
	{
		if(a[node][head] == 1)
		{
			indegree[head]--;
			if(indegree[head] == 0)
			{
				nodestack[stackp] = head;
				stackp++;
			}
		}
	}
}

int sort(int sorted[])
{
	int count = 0, node;
	count_indegree();
	for(node = 0; node < N; node++)
	{
		if(indegree[node] == 0)
		{
			nodestack[stackp] = node;
			stackp++;
		}
	}

	while(stackp > 0)
	{
		stackp--;
		node = nodestack[stackp];
		cout<<"curr pop node = "<<node<<endl;
		sorted[count] = node;
		count++;
		remove_node(node);
	}

	return count;
}

void test_question_1()
{
	int tmp[N];
	cout<<sort(sorted)<<endl;

	for(int i = 0; i < N; i++)
		cout<<sorted[i]<<" ";
	cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}