#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

#define V (5)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int g[V][V] = 
{    
    {M,6,M,M,3},
    {M,M,3,7,M},
    {M,M,M,M,M},
    {M,M,9,M,M},
    {M,5,M,1,M}
};

void Init(int s[])
{
    for(int i = 0; i < V; i++)
        s[i] = i;
}

int Find(int s[], int x)
{
    if(x == s[x])	return x; 
    else			return s[x] = Find(s, s[x]);
}

void Union(int s[], int x, int y)
{
    s[Find(s, y)] = Find(s, x);
}

bool ValidTree()
{
	int s[V];
	Init(s);
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			cout<<"i,j = "<<i<<","<<j;
			if(g[i][j] < M)
			{
				if(Find(s, i) == Find(s, j))
				{
					cout<<"  false"<<endl;
					return false;
				}
				cout<<"  continue";
				Union(s, i, j);
			}cout<<endl;
		}
	}
	return true;
}

int main()
{
	cout<<ValidTree()<<endl;
	return 0;
}