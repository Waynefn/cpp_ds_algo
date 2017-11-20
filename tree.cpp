#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <stdlib.h>

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
	int val;
	_TreeNode *left, *right;
	_TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
}TreeNode;

bool tree_search(TreeNode *t, int x)
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

int tree_node_count(TreeNode *t)
{
	if(NULL == t)
		return 0;

	return 1 + tree_node_count(t->left) + tree_node_count(t->right);
}

int tree_val_sum(TreeNode *t)
{
	if(NULL == t)
		return 0;
	return t->val + tree_val_sum(t->left) + tree_val_sum(t->right);
}

int tree_height(TreeNode *t)
{
	if(NULL == t)
		return 0;

	return 1 + max(tree_height(t->left),tree_height(t->right));
}

TreeNode *tree_insert(TreeNode *t, int val)
{
	if(NULL == t)
		t = new TreeNode(val);
	else if(val < t->val)
		t->left = tree_insert(t->left, val);
	else if(val > t->val)
		t->right = tree_insert(t->right, val);
	else
		;

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
		;

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
		if(t->left && t->right)
		{
			tmp = t->right;
			while(tmp->left)
				tmp = tmp->left;		// 找到后驱:右子树中最小的节点
			t->val = tmp->val;
			t->right = tree_delete(t->right, tmp->val);
		}
		else
		{
			tmp = t;
			if(t->left)	t = t->left;
			else		t = t->right;
			delete tmp;
		}
	}

	return t;
}

void tree_trvl_prev(TreeNode *t)
{
	if(NULL == t)
		return;
	cout<<t->val<<" ";
	tree_trvl_prev(t->left);
	tree_trvl_prev(t->right);
}

void tree_trvl_in(TreeNode *t)
{
	if(NULL == t)
		return;
	tree_trvl_in(t->left);
	cout<<t->val<<" ";
	tree_trvl_in(t->right);
}

void tree_trvl_post(TreeNode *t)
{
	if(NULL == t)
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

void test_tree()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	TreeNode *t = NULL;

	for(int i = 0; i < Len(a); i++)
		t = tree_insert(t, a[i]);

	tree_search(t, 3);
	tree_search(t, 9);
	tree_search(t, 33);

	cout<<"tree node num = "<<tree_node_count(t)<<endl;
	cout<<"tree height = "<<tree_height(t)<<endl;

	tree_trvl_prev_nonRecursive_modify(t); 
	tree_trvl_in_nonRecursive(t);
	tree_trvl_post(t); cout<<endl;

	tree_delete(t, 0);

	tree_trvl_level(t);
	tree_trvl_level_reverse(t);
	tree_trvl_zigzag(t);
}

/**********************************************
	tanjan算法求LCA by union-find
	注意:union和find不能优化,否则会导致回溯过程中,parent指向child的情况发生
	ps:为了显示ancestors方便，MAX取值不要过大（节点的数字尽量采用个位数）
**********************************************/
#define MAX (11)

void print_tarjan_info(bool visited[], int ancestors[], int n)
{
	cout<<"vis = ";
	PRINT_ARRAY(visited, n);
	
	cout<<"anc = ";
	PRINT_ARRAY(ancestors, n);
	
	cout<<"idx = ";
	for(int i = 0; i < n; i++)
		cout<<i<<"|";
	cout<<endl;
}

void uf_init(int S[], int n)
{
	for(int i = 0; i < n; i++)
		S[i] = i;	// 初始化时，每个节点的祖先即是自己
}

void uf_union(int S[], int e1, int e2)
{
	S[e2] = e1;		// 不可以优化合并操作，否则parent节点会被合并，指向child
}

int uf_find(int S[], int x)
{
	if(S[x] == x)
		return x;
	else
		return uf_find(S, S[x]);
}

void tarjan_lca(TreeNode *t, bool visited[], int ancestors[], int n, int x, int y)
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
		tarjan_lca(t->left, visited, ancestors, n, x, y);	// dfs遍历树
		uf_union(ancestors, t->val, t->left->val);		// 合并子树到自身集合
	}
	if(t->right)
	{
		tarjan_lca(t->right, visited, ancestors, n, x, y);
		uf_union(ancestors, t->val, t->right->val);
	}

	if(x == t->val && visited[y])	// 遍历到x时，发现y已经被访问过，此时y所属集合即为结果
		cout<<"LCA("<<x<<","<<y<<") = "<<uf_find(ancestors, y)<<endl;	
	if(y == t->val && visited[x])	// 遍历到y时，发现y已经被访问过，此时y所属集合即为结果
		cout<<"LCA("<<x<<","<<y<<") = "<<uf_find(ancestors, x)<<endl;

	visited[t->val] = true;			// 类似后续遍历,最后将自己置true

/*	// 以下代码输出树t的所有配对节点的LCA结果
	for(int i = 0; i < MAX; i++)
		if(visited[i])// && t->val != i)
			cout<<"LCA("<<t->val<<","<<i<<") = "<<uf_find(lca, i)<<endl;	
*/
}

void test_tarjan_lca()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	TreeNode *t = NULL;

	for(int i = 0; i < Len(a); i++)
		t = tree_insert(t, a[i]);
	tree_trvl_level(t);

	bool visited[MAX] = {false};
	int ancestors[MAX];

	uf_init(ancestors, MAX);

	tarjan_lca(t, visited, ancestors, MAX, 1, 0);	

	print_tarjan_info(visited, ancestors, MAX);
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
			return false;
		dummy = dummy->child[c];
	}

	return dummy->exist;	// fixed bug:此时节点dummy一定不为null，根据需要返回exist或者word对应的val
}

void test_trie_tree()
{
	PRINT_FUNCTION_NAME;

	TrieTreeNode *t = new TrieTreeNode;

	trie_tree_insert(t, "abc");
	trie_tree_insert(t, "abcd");
	trie_tree_insert(t, "abd");

	cout<<"found result: "<<trie_tree_search(t, "ab")<<endl;
	cout<<"found result: "<<trie_tree_search(t, "abc")<<endl;
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
	
	t->max = max(t->left->max, t->right->max);
	t->min = min(t->left->min, t->right->min);
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

/**********************************************
	自平衡树(AVL)
**********************************************/
typedef struct _AvlTreeNode
{
	int val, height;
	_AvlTreeNode *left, *right;
	_AvlTreeNode(int val)
	{
		this->val = val;
		this->height = 0;
		this->left = this->right = NULL;
	}
}AvlTreeNode;

int avl_tree_height(AvlTreeNode *t)
{
	if(NULL == t)
		return 0;
	return t->height;
}

void avl_tree_update_height(AvlTreeNode *t)
{
	t->height = 1 + max(avl_tree_height(t->left), avl_tree_height(t->right));
}

void avl_tree_trvl_level(AvlTreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

	if(NULL == t)
		return;

	queue<AvlTreeNode *> q;
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
			AvlTreeNode *tmp = q.front(); q.pop();
			cout<<tmp->val<<"-";
			if(tmp->left)	q.push(tmp->left);
			if(tmp->right)	q.push(tmp->right);
		}
		cout<<endl;
	}
}

/*	insert(A),造成k2不平衡
	A < k2 && A < k1 => 此时k2树左倾 
	=> LL(k2)
	
		k2				  k1
	   /  	   LL	   	 /  \
	  k1      ---> 		A    k2
	 /  					  
	A     				    	
*/
AvlTreeNode *avl_tree_left_left(AvlTreeNode *k2)
{
	AvlTreeNode *k1 = k2->left;

	k2->left = k1->right;
	k1->right = k2;

	avl_tree_update_height(k1);
	avl_tree_update_height(k2);	

	return k1;
}

/*	insert(A),造成k1不平衡
	A > k1 && A > k1 => 此时k1树右倾 
	=> RR(k1)
		k1					k2
		  \		  RR	   /  \
		  k2	 --->     k1   A
		    \			   
		 	 A 				
*/
AvlTreeNode *avl_tree_right_right(AvlTreeNode *k1)
{
	AvlTreeNode *k2 = k1->right;

	k1->right = k2->left;
	k2->left = k1;

	avl_tree_update_height(k1);
	avl_tree_update_height(k2);

	return k2;
}

/*	insert(k2),造成k3不平衡
	k2 < k3 && k2 > k1 => 此时k3树左右倾 
	=> RR(k1),使k3完全左倾
	=> LL(k3)
		k3				  k3			k2
	   /  	   RR	   	 /  	 LL	   /  \
	  k1      ---> 		k2 		--->  k1  k3
	    \			   /	  
	     k2 		  k1	    	   
*/
AvlTreeNode *avl_tree_left_right(AvlTreeNode *k3)
{
	k3->left = avl_tree_right_right(k3->left);
	return avl_tree_left_left(k3);
}

/*	insert(k2),造成k1不平衡
	k2 > k1 && k2 < k3 => 此时k1树右左倾 
	=> LL(k3),使k1完全右倾
	=> RR(k1)
	k1				  k1				k2
	  \   	   LL	   \  	 	 RR	   /  \
	  k3      ---> 		k2 		--->  k1  k3
	  /   			   	 \ 
	 K2 		  		  k3	    	   
*/
AvlTreeNode *avl_tree_right_left(AvlTreeNode *k1)
{
	k1->right = avl_tree_left_left(k1->right);
	return avl_tree_right_right(k1);
}

AvlTreeNode *avl_tree_insert(AvlTreeNode *t, int val)
{
	if(NULL == t)
	{
		t = new AvlTreeNode(val);
	}
	else if(val < t->val)
	{
		t->left = avl_tree_insert(t->left, val);
		if(2 == abs(avl_tree_height(t->left) - avl_tree_height(t->right)))
		{
			
			if(val < t->left->val)
				t = avl_tree_left_left(t);
			else
				t = avl_tree_left_right(t);
		}
	}
	else if(val > t->val)
	{
		t->right = avl_tree_insert(t->right, val);
		if(2 == abs(avl_tree_height(t->left) - avl_tree_height(t->right)))
		{
			
			if(val > t->right->val)
				t = avl_tree_right_right(t);
			else
				t = avl_tree_right_left(t);
		}
	}
	else
		;

	avl_tree_update_height(t);
	return t;
}

AvlTreeNode *avl_tree_delete(AvlTreeNode *t, int x)
{
	if(NULL == t)
		return NULL;

	if(x < t->val)	// x在t的左子树部分,删除后可能导致t的右子树不平衡
	{
		t->left = avl_tree_delete(t->left, x);
		if(2 == abs(avl_tree_height(t->left) - avl_tree_height(t->right)))	// RR or RL
		{
			AvlTreeNode *R = t->right;
			if(avl_tree_height(R->right) > avl_tree_height(R->left))		// RR
				t = avl_tree_right_right(t);
			else
				t = avl_tree_right_left(t);									// RL
		}
	}
	else if(x > t->val)	// x在t的右子树部分,删除后可能导致t的左子树不平衡
	{
		t->right = avl_tree_delete(t->right, x);
		if(2 == abs(avl_tree_height(t->left) - avl_tree_height(t->right)))	// LL or LR
		{
			AvlTreeNode *L = t->left;
			if(avl_tree_height(L->left) > avl_tree_height(L->right))		// LL
				t = avl_tree_left_left(t);
			else															// LR
				t = avl_tree_left_right(t);
		}
	}
	else
	{
		AvlTreeNode *tmp;
		if(t->left && t->right)	// 根据左右子树的高度,再选择用前驱or后驱元素替代
		{
			if(avl_tree_height(t->left) > avl_tree_height(t->right))
			{
				// x节点的左子树>右子树,选择前驱元素替代
				tmp = t->left;
				while(tmp->right)
					tmp = tmp->right;
				t->val = tmp->val;
				t->left = avl_tree_delete(t->left, tmp->val);
			}
			else
			{
				// x节点的左子树<右子树,选择后驱元素替代
				tmp = t->right;
				while(tmp->left)
					tmp = tmp->left;
				t->val = tmp->val;
				t->right = avl_tree_delete(t->right, tmp->val);
			}
		}
		else
		{
			tmp = t;
			if(t->left)	t = t->left;
			else		t = t->right;
			delete tmp;
		}
	}

	return t;
}

void test_avl_tree()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	AvlTreeNode *t = NULL;

	for(int i = 0; i < Len(a); i++)
		t = avl_tree_insert(t, a[i]);
	avl_tree_trvl_level(t);
	avl_tree_delete(t, 6);
	avl_tree_trvl_level(t);
}

int main()
{
	// test_tree();
	// test_tarjan_lca();

	 test_trie_tree();

	// test_segment_tree();

	// test_avl_tree();

	return 0;
}