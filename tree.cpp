#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "utils.h"

using namespace std;

/*
	1.二叉搜索树
	2.字典树
	3.线段树
	4.AVL树
*/

/**********************************************
	二叉搜索树
**********************************************/
typedef struct _TreeNode
{
	int val, cnt;
	_TreeNode *left, *right;
	_TreeNode(int val)
	{
		this->val = val;
		this->cnt = 1;
		this->left = this->right = NULL;
	}
}TreeNode;

void tree_trvl_prev(TreeNode *t)
{
	if(t == NULL)
		return;
	cout<<t->val<<" ";
	tree_trvl_prev(t->left);
	tree_trvl_prev(t->right);
}

void tree_trvl_in(TreeNode *t)
{
	if(t == NULL)
		return;
	tree_trvl_in(t->left);
	cout<<t->val<<" ";
	tree_trvl_in(t->right);
}

void tree_trvl_post(TreeNode *t)
{
	if(t == NULL)
		return;
	tree_trvl_post(t->left);
	tree_trvl_post(t->right);
	cout<<t->val<<" ";
}

void tree_trvl_prev_nonRecursive(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

	stack<TreeNode *> s;
	s.push(t);

	TreeNode *tmp = NULL;
	while(!s.empty())
	{
		tmp = s.top();
		cout<<tmp->val<<"-";
		while(tmp->left)
		{
			tmp = tmp->left;
			cout<<tmp->val<<"-";
			s.push(tmp);
		}

		while(!s.empty())
		{
			tmp = s.top(); s.pop();
			if(tmp->right)
			{
				s.push(tmp->right);
				break;
			}
		}
	}
	cout<<endl;
}

void tree_trvl_prev_nonRecursive_modify(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

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
	}
	cout<<endl;
}

void tree_trvl_in_nonRecursive(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

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
	}
	cout<<endl;
}

void tree_trvl_post_nonRecursive(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

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
	}
	cout<<endl;
}

void tree_trvl_level(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

	if(t == NULL)
		return;

	queue<TreeNode *> q;
	q.push(t);

	int level = 0;
	while(!q.empty())
	{
		level++;
		cout<<"lv"<<level<<" :";
		int lvSize = q.size();
		while(lvSize)
		{
			lvSize--;
			TreeNode *tmp = q.front(); q.pop();
			cout<<tmp->val<<"-";
			if(tmp->left)	q.push(tmp->left);
			if(tmp->right)	q.push(tmp->right);
		}
		cout<<endl;
	}
}

void tree_trvl_level_reverse(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

	if(NULL == t)
		return;

	queue<TreeNode *> q;
	stack<vector<int> > s;
	q.push(t);

	while(!q.empty())
	{
		int lvSize = q.size();
		vector<int> v;
		while(lvSize)
		{
			lvSize--;
			TreeNode *tmp = q.front(); q.pop();
			v.push_back(tmp->val);
			if(tmp->left)	q.push(tmp->left);
			if(tmp->right)	q.push(tmp->right);
		}
		s.push(v);
	}

	int level = s.size();
	while(!s.empty())
	{
		cout<<"lv"<<level<<" :";
		level--;

		vector<int> v = s.top(); s.pop();
		for(int i = 0; i < v.size(); i++)
			cout<<v[i]<<"-";
		cout<<endl;
	}
}

void tree_trvl_zigzag(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

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
			if(tmp->left)	s2.push(tmp->left);
			if(tmp->right)	s2.push(tmp->right);
		}cout<<endl;
		while(!s2.empty())
		{
			tmp = s2.top(); s2.pop();
			cout<<tmp->val<<"-";
			if(tmp->right)	s1.push(tmp->right);
			if(tmp->left)	s1.push(tmp->left);
		}cout<<endl;
	}
}

TreeNode *tree_insert(TreeNode *t, int val)
{
	if(t == NULL)
		t = new TreeNode(val);
	else if(val < t->val)
		t->left = tree_insert(t->left, val);
	else if(val > t->val)
		t->right = tree_insert(t->right, val);
	else
		t->cnt++;

	return t;
}

TreeNode *tree_insert_nonRecursive(TreeNode *t, int val)
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
		j->cnt++;

	return t;
}

TreeNode *tree_delete(TreeNode *t, int x)
{
	if(NULL == t)
		return NULL;

	if(x < t->val)
		t->left = tree_delete(t->left, x);
	else if(x > t->val)
		t->right = tree_delete(t->right, x);
	else
	{
		TreeNode *tmp;
		if(NULL == t->right)
		{
			tmp = t;
			t = t->left;
			delete tmp;
		}
		else
		{
			tmp = t->right;
			while(tmp->left)
				tmp = tmp->left;	// 找到右子树中最小的节点
			t->val = tmp->val;		// 右子树最小值赋值给当前被删除节点
			t->right = tree_delete(t->right, tmp->val);	// 递归去右子树删除这个最小值节点
		}
	}

	return t;
}

bool tree_find(TreeNode *t, int x)
{
	bool ret = false;
	if(NULL == t)
	{
		cout<<"find "<<x<<" FAIL"<<endl;
		return ret;
	}

	if(x == t->val)
	{
		ret = true;
		cout<<"find "<<x<<" OK"<<endl;
	}
	else if(x < t->val)
		ret = tree_find(t->left, x);
	else
		ret = tree_find(t->right, x);

	return ret;
}

int tree_node_count(TreeNode *t)
{
	if(NULL == t)
		return 0;

	return 1 + tree_node_count(t->left) + tree_node_count(t->right);
}

int tree_heigh(TreeNode *t)
{
	if(NULL == t)
		return 0;

	return 1 + max(tree_heigh(t->left),tree_heigh(t->right));
}

void test_tree()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	TreeNode *t = NULL;

	for(int i = 0; i < Len(a); i++)
		t = tree_insert(t, a[i]);

	tree_find(t, 3);
	tree_find(t, 9);
	tree_find(t, 33);

	cout<<"tree node num = "<<tree_node_count(t)<<endl;
	cout<<"tree height = "<<tree_heigh(t)<<endl;

	tree_trvl_prev_nonRecursive_modify(t); 
	tree_trvl_in_nonRecursive(t);
	tree_trvl_post(t); cout<<endl;

	tree_trvl_level(t);
	tree_trvl_level_reverse(t);
	tree_trvl_zigzag(t);
}

/**********************************************
	tanjan算法求LCA by union-find
	注意:union和find不能优化,否则会导致回溯过程中,parent指向child的情况发生
**********************************************/
#define MAX (10)

void print_tarjan_info(bool visited[], int dfs[], int n)
{
	cout<<"vis = ";
	PRINT_ARRAY(visited, n);
	
	cout<<"dfs = ";
	PRINT_ARRAY(dfs, n);
	
	cout<<"idx = ";
	for(int i = 0; i < n; i++)
		cout<<i<<"|";
	cout<<endl;
}

void uf_init(int S[], int n)
{
	for(int i = 0; i < n; i++)
		S[i] = i;
}

void uf_union(int S[], int e1, int e2)
{
	S[e2] = e1;
}

int uf_find(int S[], int x)
{
	if(S[x] == x)
		return x;
	else
		return uf_find(S, S[x]);
}

void tarjan(TreeNode *t, bool visited[], int dfs[], int n)
{
	if(NULL == t)
		return;
	if(t->left)
	{
		tarjan(t->left, visited, dfs, n);		// dfs遍历树
		uf_union(dfs, t->val, t->left->val);	// 合并子树到自身集合
	}
	if(t->right)
	{
		tarjan(t->right, visited, dfs, n);
		uf_union(dfs, t->val, t->right->val);
	}
	visited[t->val] = true;		// 类似后续遍历,最后将自己置true

	for(int i = 0; i < MAX; i++)
		if(visited[i])// && t->val != i)
			cout<<"LCA("<<t->val<<","<<i<<") = "<<uf_find(dfs, i)<<endl;	
}

void test_tarjan()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,5};//,7,9,1,3,0};
	TreeNode *t = NULL;

	for(int i = 0; i < Len(a); i++)
		t = tree_insert(t, a[i]);
	tree_trvl_level(t);

	bool visited[MAX] = {false};
	int dfs[MAX];

	uf_init(dfs, MAX);

	tarjan(t, visited, dfs, MAX);	

	print_tarjan_info(visited, dfs, MAX);
}

/**********************************************
	字典树(Trie)
**********************************************/
typedef struct _TrieTreeNode
{
	bool exist;	// 用于以后删除单词时,不破坏树结构
	_TrieTreeNode *child[26];
	_TrieTreeNode()
	{
		this->exist = false;
		for(int i = 0; i < 26; i++)
			this->child[i] = NULL;
	}
}TrieTreeNode;

void trie_tree_insert(TrieTreeNode *t, string word)
{
	TrieTreeNode *dummy = t;

	for(int i = 0; i < word.length(); i++)
	{
		int c = word[i] - 'a';
		if(NULL == dummy->child[c])
			dummy->child[c] = new TrieTreeNode;
		dummy = dummy->child[c];
	}
	dummy->exist = true;
}

bool trie_tree_search(TrieTreeNode *t, string word)
{
	TrieTreeNode *dummy = t;

	for(int i = 0; i < word.length(); i++)
	{
		int c = word[i] - 'a';
		if(NULL == dummy->child[c])
		{
			cout<<"NOT find "<<word<<" in trie"<<endl;
			return false;
		}
		dummy = dummy->child[c];
	}

	cout<<"find "<<word<<" in trie"<<endl;
	return true;
}

void test_trie_tree()
{
	PRINT_FUNCTION_NAME;

	TrieTreeNode *t = new TrieTreeNode;

	trie_tree_insert(t, "abc");
	trie_tree_insert(t, "abcd");
	trie_tree_insert(t, "abd");

	trie_tree_search(t, "abc");
	trie_tree_search(t, "abca");
}

/**********************************************
	线段树(Segment)
**********************************************/
typedef struct _SegmentNode
{
	int start, end, max, min, sum;
	_SegmentNode *left, *right;
	_SegmentNode(int s, int end, int val)
	{
		this->start = s;
		this->end = end;
		this->max = this->min = this->sum = val;
		this->left = this->right = NULL;
	}
}SegmentNode;

void segment_tree_trvl(SegmentNode *t, int curr_level = 1)
{
	if(NULL == t)
		return;

	for(int i = 0; i < curr_level; i++)
		cout<<"#";
	cout<<"["<<t->start<<"~"<<t->end<<"]:max = "<<t->max<<", min = "<<t->min<<", sum = "<<t->sum<<endl;
	segment_tree_trvl(t->left, curr_level+1);
	segment_tree_trvl(t->right, curr_level+1);
}

SegmentNode *segment_tree_build(int a[], int s, int e)
{
	if(s > e)
		return NULL;

	SegmentNode *node = new SegmentNode(s, e, a[s]);
	if(s == e)
		return node;

	int m = (s + e) / 2;
	node->left = segment_tree_build(a, s, m);
	node->right = segment_tree_build(a, m+1, e);

	node->max = node->left->max > node->right->max ? node->left->max : node->right->max;
	node->min = node->left->min < node->right->min ? node->left->min : node->right->min;
	node->sum = node->left->sum + node->right->sum;

	return node;
}

void segment_tree_modify(SegmentNode *t, int index, int val)
{
	if(NULL == t || index < t->start || index > t->end)
		return;
	if(index == t->start && index == t->end)
	{
		t->max = t->min = val;
		return;
	}

	int m = (t->start + t->end) / 2;
	if(index <= m)
		segment_tree_modify(t->left, index, val);
	else
		segment_tree_modify(t->right, index, val);
	
	t->max = t->left->max > t->right->max ? t->left->max : t->right->max;
	t->min = t->left->min < t->right->min ? t->left->min : t->right->min;
	t->sum = t->left->sum + t->right->sum;
}

// 返回a[from]到a[to]的数据的和
int segment_tree_query_sum(SegmentNode *t, int from, int to)
{
	if(from > to)
		return 0;
	if(from == t->start && to == t->end)
		return t->sum;

	int m = (t->start + t->end) / 2;
	if(m > to)
		return segment_tree_query_sum(t->left, from, to);
	else if(m < from)
		return segment_tree_query_sum(t->right, from, to);
	else
	{
		int left = segment_tree_query_sum(t->left, from, m);
		int right = segment_tree_query_sum(t->right, m+1, to);
		return left + right;
	}
}

void test_segment_tree_build()
{
	PRINT_SUB_FUNCTION_NAME;

	int a[] = {1,2,7,8,5};
	SegmentNode *t = segment_tree_build(a, 0, Len(a)-1);
	segment_tree_trvl(t);
}

void test_segment_tree_modify()
{
	PRINT_SUB_FUNCTION_NAME;

	int a[] = {1,2,7,8,5};
	SegmentNode *t = segment_tree_build(a, 0, Len(a)-1);

	cout<<"----------modify----------"<<endl;
	segment_tree_modify(t, 2, 9);
	segment_tree_trvl(t);
}

void test_segment_tree_query_sum()
{
	PRINT_SUB_FUNCTION_NAME;

	int a[] = {1,2,7,8,5};
	SegmentNode *t = segment_tree_build(a, 0, Len(a)-1);

	cout<<"----------query sum----------"<<endl;
	segment_tree_trvl(t);
	cout<<"query sum = "<<segment_tree_query_sum(t, 0, 2)<<endl;
}

void test_segment_tree()
{
	PRINT_FUNCTION_NAME;

	test_segment_tree_build();
	test_segment_tree_modify();
	test_segment_tree_query_sum();
}

int main()
{
	test_tree();
	test_tarjan();

	test_trie_tree();

	test_segment_tree();

	return 0;
}