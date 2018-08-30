#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/**********************************************
    二叉搜索树
**********************************************/
#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct _TreeNode
{
    int val;
    _TreeNode *left, *right;
    _TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
}TreeNode;

bool Search(TreeNode *t, int x)
{
    TreeNode *tmp = t;

    while(tmp)
    {
        if(x < tmp->val)
            tmp = tmp->left;
        else if(x > tmp->val)
            tmp = tmp->right;
        else
        {
            cout<<"find "<<x<<" OK"<<endl;
            return true;
        }
    }
    cout<<"find "<<x<<" FAIL"<<endl;
    return false;
}

int NodeCnt(TreeNode *t)
{
    if(NULL == t)
        return 0;
    return 1 + NodeCnt(t->left) + NodeCnt(t->right);
}

int NodeSum(TreeNode *t)
{
    if(NULL == t)
        return 0;
    return t->val + NodeSum(t->left) + NodeSum(t->right);
}

int Height(TreeNode *t)
{
    if(NULL == t)
        return 0;
    return 1 + max(Height(t->left),Height(t->right));
}

TreeNode *Insert_r(TreeNode *t, int val)
{
    if(NULL == t)
        t = new TreeNode(val);
    else if(val < t->val)
        t->left = Insert_r(t->left, val);
    else if(val > t->val)
        t->right = Insert_r(t->right, val);
    else
        ;
    return t;
}

TreeNode *Insert(TreeNode *t, int val)
{
    TreeNode *node = new TreeNode(val);
    if(NULL == t)
        return node;

    TreeNode *i = t, *j = NULL;
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
    else if(val > j->val)   
        j->right = node;
    else 
        ;

    return t;
}

TreeNode *Delete(TreeNode *t, int x)
{
    if(NULL == t)
        return NULL;

    if(x < t->val)
        t->left = Delete(t->left, x);
    else if(x > t->val)
        t->right = Delete(t->right, x);
    else
    {
        TreeNode *tmp;
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

void TrvlPrev_r(TreeNode *t)
{
    if(NULL == t)
        return;
    cout<<t->val<<" ";
    TrvlPrev_r(t->left);
    TrvlPrev_r(t->right);
}

void TrvlIn_r(TreeNode *t)
{
    if(NULL == t)
        return;
    TrvlIn_r(t->left);
    cout<<t->val<<" ";
    TrvlIn_r(t->right);
}

void TrvlPost_r(TreeNode *t)
{
    if(NULL == t)
        return;
    TrvlPost_r(t->left);
    TrvlPost_r(t->right);
    cout<<t->val<<" ";
}

void TrvlPrev(TreeNode *t)
{
    stack<TreeNode *> s;
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

void TrvlIn(TreeNode *t)
{
    stack<TreeNode *> s;
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

void TrvlPost(TreeNode *t)
{
    TreeNode *last = NULL;
    stack<TreeNode *> s;
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

void TrvlLevel(TreeNode *t)
{
    if(NULL == t)
        return;
    queue<TreeNode *> q;
    q.push(t);
    while(!q.empty())
    {
        TreeNode *tmp = q.front(); q.pop();
        cout<<tmp->val<<"-";
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }cout<<endl;
}

void TrvlLevel2(TreeNode *t)
{
    if(NULL == t)
        return;
    queue<TreeNode *> q;
    q.push(t);

    int level = 0;
    while(!q.empty())
    {
        level++;
        cout<<"lv"<<level<<" :";
        int lvSize = q.size();
        while(lvSize--)
        {
            TreeNode *tmp = q.front(); q.pop();
            cout<<tmp->val<<"-";
            if(tmp->left)   
                q.push(tmp->left);
            if(tmp->right)  
                q.push(tmp->right);
        }cout<<endl;
    }
}

void TrvlLevel2_reverse(TreeNode *t)
{
    if(NULL == t)
        return;

    queue<TreeNode *> q;
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

void TrvlZigzag(TreeNode *t)
{
    if(NULL == t)
        return;

    int level = 0;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    s1.push(t);
    while(!s1.empty() || !s2.empty())
    {
        TreeNode *tmp;
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
    int a[] = {6,4,8,2,7,9,1,3,10,0};
    TreeNode *t = NULL;

    for(int i = 0; i < Len(a); i++)
        t = Insert_r(t, a[i]);

    Search(t, 3);
    Search(t, 9);
    Search(t, 33);

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

void TarjanResult(bool visited[], int ancestors[], int n)
{
    cout<<"vis = "; PRINT_ARRAY(visited, n);
    cout<<"anc = "; PRINT_ARRAY(ancestors, n);
    
    cout<<"idx = ";
    for(int i = 0; i < n; i++)
        cout<<i<<"|";
    cout<<endl;
}

void uf_init(int S[], int n)
{
    for(int i = 0; i < n; i++)
        S[i] = i;   // 初始化时，每个节点的祖先即是自己
}

void uf_union(int S[], int e1, int e2)
{
    S[e2] = e1;     // 不可以优化合并操作，否则parent节点会被合并，指向child
}

int uf_find(int S[], int x)
{
    if(S[x] == x)
        return x;
    else
        return uf_find(S, S[x]);
}

void TarjanLCA(TreeNode *t, bool visited[], int ancestors[], int n, int x, int y)
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
        TarjanLCA(t->left, visited, ancestors, n, x, y);   // dfs遍历树
        uf_union(ancestors, t->val, t->left->val);      // 合并子树到自身集合
    }
    if(t->right)
    {
        TarjanLCA(t->right, visited, ancestors, n, x, y);
        uf_union(ancestors, t->val, t->right->val);
    }

    if(x == t->val && visited[y])   // 遍历到x时，发现y已经被访问过，此时y所属集合即为结果
        cout<<"LCA("<<x<<","<<y<<") = "<<uf_find(ancestors, y)<<endl;   
    if(y == t->val && visited[x])   // 遍历到y时，发现y已经被访问过，此时y所属集合即为结果
        cout<<"LCA("<<x<<","<<y<<") = "<<uf_find(ancestors, x)<<endl;

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
    TreeNode *t = NULL;

    for(int i = 0; i < Len(a); i++)
        t = Insert(t, a[i]);
    TrvlLevel2(t);

    bool visited[MAX] = {false};
    int ancestors[MAX];

    uf_init(ancestors, MAX);

    TarjanLCA(t, visited, ancestors, MAX, 1, 0);   

    TarjanResult(visited, ancestors, MAX);
}

int main()
{
    test_Bst();
    test_TarjanLCA();

    return 0;
}