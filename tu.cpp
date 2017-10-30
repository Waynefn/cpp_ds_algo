#include <iostream>
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include <fstream>
#include <Windows.h>

using namespace std;

#define V	(8)
#define MAX	(99)

const int w[V][V] = 
{//	 a	b	c	d	e	f	g	z
	{0,	 4,	3,	MAX,MAX,MAX,MAX,MAX},
	{4,	 0,	5,	MAX,MAX,MAX,MAX,MAX},
	{3,	 2,	0,	3,	6,	MAX,MAX,MAX},
	{MAX,5, 3,	0,	1,	5,	MAX,MAX},
	{MAX,MAX,6,	1,	0,	MAX,5,	MAX},
	{MAX,MAX,MAX,5,	MAX,0,	2,	7	},
	{MAX,MAX,MAX,MAX,5,	2,	0,	4},
	{MAX,MAX,MAX,MAX,MAX,7,	4,	0},
};

typedef struct
{
	int L[V];
	int W[V][V];
}graph;

int S[V] = {0,1,2,3,4,5,6,7};

int find_min(graph* g)
{
	int result = 0;
	int i = 0;
	for(i = 0; i < V; i++)
		result = result < g->L[i] ? result : g->L[i];
	return i;
}

void graph_init(graph* g)
{
	for(int i = 0; i < V; i++)	g->L[i] = MAX;
	g->L[0] = 0;

	for(int i = 0; i < V; i++)
		for(int j= 0; j < V; j++)
			g->W[i][j] = w[i][j];
}

int iteration(graph* g)
{
	int u = find_min(g);

	while(S[V-1])
	{
		S[u] = -1;
		for(int i = 0; i < V; i++)
			if(S[i] >= 0)	
				g->L[i] = g->L[i] < g->L[u]+g->W[u][i] ? g->L[i] : g->L[u]+g->W[u][i];
	}
	return g->L[V-1];
}

void main()
{
	graph my_g;
	graph_init(&my_g);
	cout<<iteration(&my_g)<<endl;;
	
	
	system("pause");
}

