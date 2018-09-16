#include <bits/stdc++.h>

using namespace std;

/***************************************
	拓扑排序
***************************************/
#define A 	workset[x] = 0
#define B_1	edges[y][x] == 1
#define B_2 edges[a][x] == 1

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}
#define N (4)

typedef struct node
{
	int data;
	struct node *next;
}node;

int edges[N][N] = 
{
	{0,0,0,1},
	{1,0,1,0},
	{1,0,0,1},
	{0,0,0,0}
};
int workset[N] = {0};
node *sorted = NULL;

node *cons(int a, node *list)
{
	node *n = (node *)malloc(sizeof(node));
	n->data = a;
	n->next = list;
	return n;
}

int isroot(int x)
{
	int y;
	for(y = 0; y < N; y++)
		if(B_1)
			return 0;
	return 1;
}

int pick()
{
	int x;
	for(x = 0; x < N; x++)
	{
		if(workset[x])
		{
			A;
			return x;
		}
	}
	return -1;
}

int main()
{
	int a, x;
	for(x = 0; x < N; x++)
	{
		if(isroot(x))
			workset[x] = 1;
		else
			workset[x] = 0;
	}
	while((a = pick()) != -1)
	{
		sorted = cons(a, sorted);
		for(x = 0; x < N; x++)
		{
			if(B_2)
			{
				edges[a][x] = 0;
				if(isroot(x))
					workset[x] = 1;
			}
			
		}
		
	}
	while(sorted)
	{
		cout<<sorted->data<<" ";
		sorted = sorted->next;
	}
}