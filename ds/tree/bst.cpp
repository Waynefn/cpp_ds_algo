#include <iostream>
#include <queue>
#include <stack>

using namespace std;
/**********************************************
    二叉搜索树
**********************************************/
#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct _Node
{
    int val;
    _Node *left, *right;
    _Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
}Node;

bool Search(Node *t, int x)
{
    Node *tmp = t;

    while(tmp)
    {
        if(x < tmp->val)
            tmp = tmp->left;
        else if(x > tmp->val)
            tmp = tmp->right;
        else
            return true;
    }
    return false;
}

bool Search_r(Node *t, int x)
{
    if(NULL == t)
        return false;
    if(x < t->val)
        return Search_r(t->left, x);
    else if(x > t->val)
        return Search_r(t->right, x);
    else
        return true;
}

int NodeCnt(Node *t)
{
    if(NULL == t)
        return 0;
    return 1 + NodeCnt(t->left) + NodeCnt(t->right);
}

int NodeSum(Node *t)
{
    if(NULL == t)
        return 0;
    return t->val + NodeSum(t->left) + NodeSum(t->right);
}

int Height(Node *t)
{
    if(NULL == t)
        return 0;
    return 1 + max(Height(t->left),Height(t->right));
}

Node *Insert_r(Node *t, int val)
{
    if(NULL == t)
        t = new Node(val);
    else if(val < t->val)
        t->left = Insert_r(t->left, val);
    else if(val > t->val)
        t->right = Insert_r(t->right, val);
    else
        ;
    return t;
}

Node *Insert(Node *t, int val)
{
    Node *node = new Node(val);
    if(NULL == t)
        return node;

    Node *i = t, *j = NULL;
    while(i)
    {
        j = i;
        if(val < i->val)    
            i = i->left;
        else            
            i = i->right;
    }

    if(val < j->val)        
        j->left = node;
    else
        j->right = node;
  
    return t;
}

Node *Delete(Node *t, int x)
{
    if(NULL == t)
        return NULL;

    if(x < t->val)
        t->left = Delete(t->left, x);
    else if(x > t->val)
        t->right = Delete(t->right, x);
    else
    {
        Node *tmp;
        if(t->left && t->right)
        {
            tmp = t->right;
            while(tmp->left)
                tmp = tmp->left;
            t->val = tmp->val;
            t->right = Delete(t->right, tmp->val);
        }
        else
        {
            tmp = t;
            if(t->left) 
                t = t->left;
            else        
                t = t->right;
            delete tmp;
        }
    }
    return t;
}

void TrvlPrev_r(Node *t)
{
    if(NULL == t)
        return;
    cout<<t->val<<" ";
    TrvlPrev_r(t->left);
    TrvlPrev_r(t->right);
}

void TrvlIn_r(Node *t)
{
    if(NULL == t)
        return;
    TrvlIn_r(t->left);
    cout<<t->val<<" ";
    TrvlIn_r(t->right);
}

void TrvlPost_r(Node *t)
{
    if(NULL == t)
        return;
    TrvlPost_r(t->left);
    TrvlPost_r(t->right);
    cout<<t->val<<" ";
}

void TrvlPrev(Node *t)
{
    stack<Node *> s;
    while(!s.empty() || t)
    {
        while(t)
        {
            cout<<t->val<<"-";
            s.push(t);
            t = t->left;
        }
        t = s.top(); s.pop();
        t = t->right;
    }cout<<endl;
}

void TrvlIn(Node *t)
{
    stack<Node *> s;
    while(!s.empty() || t)
    {
        while(t)
        {
            s.push(t);
            t = t->left;
        }
        t = s.top(); s.pop();
        cout<<t->val<<"-";
        t = t->right;
    }cout<<endl;
}

void TrvlPost(Node *t)
{
    Node *last = NULL;
    stack<Node *> s;
    while(!s.empty() || t)
    {
        while(t)
        {
            s.push(t);
            t = t->left;
        }
        t = s.top();
        if(t->right && last != t->right)
            t = t->right;
        else
        {
            cout<<t->val<<' ';
            last = t;
            t = NULL;
            s.pop();
        }
    }cout<<endl;
}

void TrvlLevel(Node *t)
{
    if(NULL == t)
        return;
    queue<Node *> q;
    q.push(t);
    while(!q.empty())
    {
        Node *tmp = q.front(); q.pop();
        cout<<tmp->val<<"-";
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }cout<<endl;
}

void TrvlLevel2(Node *t)
{
    if(NULL == t)
        return;
    queue<Node *> q;
    q.push(t);

    int level = 0;
    while(!q.empty())
    {
        level++;
        cout<<"lv"<<level<<" :";
        int lvSize = q.size();
        while(lvSize--)
        {
            Node *tmp = q.front(); q.pop();
            cout<<tmp->val<<"-";
            if(tmp->left)   
                q.push(tmp->left);
            if(tmp->right)  
                q.push(tmp->right);
        }cout<<endl;
    }
}

void TrvlLevel2_reverse(Node *t)
{
    if(NULL == t)
        return;

    queue<Node *> q;
    stack<queue<int> > s;
    q.push(t);
    while(!q.empty())
    {
        int qs = q.size();
        queue<int> subq;
        while(qs--)
        {
            t = q.front(); q.pop();
            subq.push(t->val);
            if(t->left)     q.push(t->left);
            if(t->right)    q.push(t->right);
        }
        s.push(subq);
    }
    int lv = s.size();
    while(lv)
    {
        queue<int> subq = s.top(); s.pop();
        cout<<lv--<<":";
        while(!subq.empty())
        {
            int v = subq.front(); subq.pop();
            cout<<v<<" ";
        }cout<<endl;
    }
}

void TrvlZigzag(Node *t)
{
    if(NULL == t)
        return;

    int level = 0;
    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(t);
    while(!s1.empty() || !s2.empty())
    {
        Node *tmp;
        while(!s1.empty())
        {
            tmp = s1.top(); s1.pop();
            cout<<tmp->val<<"-";
            if(tmp->left)   
                s2.push(tmp->left);
            if(tmp->right)  
                s2.push(tmp->right);
        }cout<<endl;
        while(!s2.empty())
        {
            tmp = s2.top(); s2.pop();
            cout<<tmp->val<<"-";
            if(tmp->right)  
                s1.push(tmp->right);
            if(tmp->left)   
                s1.push(tmp->left);
        }cout<<endl;
    }
}

void test_Bst()
{
    int a[] = {11,4,21,3,9,17,22,15,18};
    Node *t = NULL;

    for(int i = 0; i < Len(a); i++)
        t = Insert(t, a[i]);

    cout<<"find : "<<Search(t, 3)<<endl;
    cout<<"find : "<<Search_r(t, 3)<<endl;
    cout<<"find : "<<Search(t, 9)<<endl;
    cout<<"find : "<<Search_r(t, 9)<<endl;
    cout<<"find : "<<Search(t, 33)<<endl;
    cout<<"find : "<<Search_r(t, 33)<<endl;

    cout<<"tree node num = "<<NodeCnt(t)<<endl;
    cout<<"tree height = "<<Height(t)<<endl;

    TrvlIn(t);    cout<<endl;
    TrvlPost_r(t);   cout<<endl;

    Delete(t, 6);

    TrvlLevel(t);
    TrvlLevel2(t);
    TrvlLevel2_reverse(t);
    TrvlZigzag(t);
}

/**********************************************
    tanjan算法求LCA by union-find
    注意:union和find不能优化,否则会导致回溯过程中,parent指向child的情况发生
    ps:为了显示ancestors方便，MAX取值不要过大（节点的数字尽量采用个位数）
**********************************************/
#define MAX (11)

void TarjanResult(bool visited[], int s[], int n)
{
    cout<<"vis = "; PRINT_ARRAY(visited, n);
    cout<<"anc = "; PRINT_ARRAY(s, n);
    
    cout<<"idx = ";
    for(int i = 0; i < n; i++)
        cout<<i<<"|";
    cout<<endl;
}

void uf_init(int s[], int n)
{
    for(int i = 0; i < n; i++)
        s[i] = i;   // 初始化时，每个节点的祖先即是自己
}

void uf_union(int s[], int x, int y)
{
    s[y] = x;     // 不可以优化合并操作，否则parent节点会被合并，指向child
}

int uf_find(int s[], int x)
{
    if(s[x] == x)
        return x;
    else
        return uf_find(s, s[x]);
}

void TarjanLCA(Node *t, bool visited[], int s[], int n, int x, int y)
{
    if(NULL == t)
        return;
    if(x == y)
    {
        cout<<"LCA("<<x<<","<<y<<") = "<<x<<endl;
        return;
    }

    if(t->left)
    {
        TarjanLCA(t->left, visited, s, n, x, y);   // dfs遍历树
        uf_union(s, t->val, t->left->val);      // 合并子树到自身集合
    }
    if(t->right)
    {
        TarjanLCA(t->right, visited, s, n, x, y);
        uf_union(s, t->val, t->right->val);
    }

    if(x == t->val && visited[y])   // 遍历到x时，发现y已经被访问过，此时y所属集合即为结果
        cout<<"LCA("<<x<<","<<y<<") = "<<uf_find(s, y)<<endl;   
    if(y == t->val && visited[x])   // 遍历到y时，发现y已经被访问过，此时y所属集合即为结果
        cout<<"LCA("<<x<<","<<y<<") = "<<uf_find(s, x)<<endl;

    visited[t->val] = true;         // 类似后续遍历,最后将自己置true

/*  // 以下代码输出树t的所有配对节点的LCA结果
    for(int i = 0; i < MAX; i++)
        if(visited[i])// && t->val != i)
            cout<<"LCA("<<t->val<<","<<i<<") = "<<uf_find(lca, i)<<endl;    
*/
}

void test_TarjanLCA()
{
    int a[] = {6,4,8,2,7,9,1,3,10,0};
    Node *t = NULL;

    for(int i = 0; i < Len(a); i++)
        t = Insert(t, a[i]);
    TrvlLevel2(t);

    bool visited[MAX] = {false};
    int s[MAX];

    uf_init(s, MAX);

    TarjanLCA(t, visited, s, MAX, 1, 0);   

    TarjanResult(visited, s, MAX);
}

int main()
{
    test_Bst();
    test_TarjanLCA();

    return 0;
}