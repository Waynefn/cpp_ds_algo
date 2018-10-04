#include <bits/stdc++.h>
// #include <unordered_set> 需要编译时配合 -std=c++11 使用

using namespace std;

#define V (4)
#define M (INT_MAX)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

int g[V][V] = 
{    
    {M,6,1,M},
    {6,M,M,M},
    {1,M,M,9},
    {M,M,9,M},
};

/**********************************************
    BFS实现
**********************************************/
void init_edge(vector<set<int> >& edge)
{
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(g[i][j] < M)
                edge[i].insert(j), edge[j].insert(i);
}

bool valid_bfs()
{
    set<int> v;
    queue<int> q;
    vector<set<int> > edge(V, set<int>());
    
    init_edge(edge);
    q.push(0);
    v.insert(0);
    while(!q.empty())
    {
        int from = q.front(); q.pop();
        set<int>::iterator it;
        for(it = edge[from].begin(); it != edge[from].end(); it++)
        {
            cout<<"add edge "<<from<<"-"<<*it<<endl;
            if(v.find(*it) != v.end())
                return false;
            v.insert(*it);
            q.push(*it);
            edge[*it].erase(from);  // 确保无向图一条边只计算一次
        }
    }

    return v.size() == V;
}

/**********************************************
    并查集实现
**********************************************/
void Init(int s[])
{
    for(int i = 0; i < V; i++)
        s[i] = i;
}

int Find(int s[], int x)
{
    if(x == s[x])   return x;
    else            return s[x] = Find(s, s[x]);
}

void Union(int s[], int x, int y)
{
    s[Find(s, y)] = Find(s, x);
}

bool valid_uf()
{
    int s[V];
    Init(s);

    for(int i = V-1; i > 0; i--)
        for(int j = 0; j <= i; j++)
            if(g[i][j] < M)
            {
                cout<<"add edge "<<i<<"-"<<j<<endl;
                if(Find(s, i) == Find(s, j))
                    return false;
                Union(s, i, j);
            }
    return true;
}

/**********************************************
    拓扑排序实现
**********************************************/
int main()
{
    cout<<"bfs validTree :"<<valid_bfs()<<endl;
    cout<<"uf validTree :"<<valid_uf()<<endl;
    return 0;
}