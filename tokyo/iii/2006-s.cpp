#include <bits/stdc++.h>

using namespace std;

/**********************************************
问题2：BFS
问题3：斐波那契尾递归
**********************************************/

#define V (5)

int g[V][V] = 
{
	{0,1,0,0,0},
	{1,0,1,0,1},
	{1,1,0,0,0},
	{0,0,1,0,1},
	{0,1,0,0,0}
};

void Bfs(int start)
{
    bool visited[V] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int from = q.front(); q.pop();
        cout<<from<<" ";
        for(int to = 0; to < V; to++)
        {
            if(!visited[to] && g[from][to] == 1)
            {
                visited[to] = true;
                q.push(to);
            }
        }
    }cout<<endl;
}

void Dfs_r(int curr, bool visited[])
{
    visited[curr] = true;
    cout<<curr<<" ";
    for(int to = 0; to < V; to++)
        if(!visited[to] && g[curr][to] == 1)
            Dfs_r(to, visited);
}

void Dfs(int start)
{
    static bool visited[V] = {false};
    Dfs_r(start, visited);
}

void test_question_2()
{
	Bfs(3);
	Dfs(3);
}

int main()
{
	test_question_2();

	return 0;
}