#include <bits/stdc++.h>

using namespace std;

#define V (7)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int g[V][V] = 
{
	{0,2,M,1,M,M,M},
	{M,0,M,3,10,M,M},
	{4,M,0,M,M,5,M},
	{M,M,2,0,2,8,4},
	{M,M,M,M,0,M,6},
	{M,M,M,M,M,0,M},
	{M,M,M,M,M,1,0},
};

void floyd()
{
	int dist[V][V], i, j, k;
 
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            dist[i][j] = g[i][j];

    for(k = 0; k < V; k++)
        for(i = 0; i < V; i++)
            for(j = 0; j < V; j++)
                if(dist[i][k] < M && dist[k][j] < M 	// 注意：【dist<M】才表示有通路。不判断的话会造成数值溢出	
                && dist[i][k] + dist[k][j] < dist[i][j])
                   	dist[i][j] = dist[i][k] + dist[k][j];

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == M)	cout<<"M ";
            else				cout<<dist[i][j]<<" ";    
        }
        cout<<endl;
    }
}

int main()
{
	floyd();
}