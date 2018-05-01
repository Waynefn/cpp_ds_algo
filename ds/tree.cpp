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

bool Tree_Search(TreeNode *t, int x)
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

int Tree_NodeCount(TreeNode *t)
{
	if(NULL == t)
		return 0;

	return 1 + Tree_NodeCount(t->left) + Tree_NodeCount(t->right);
}

int Tree_NodeSum(TreeNode *t)
{
	if(NULL == t)
		return 0;
	return t->val + Tree_NodeSum(t->left) + Tree_NodeSum(t->right);
}

int Tree_Height(TreeNode *t)
{
	if(NULL == t)
		return 0;

	return 1 + max(Tree_Height(t->left),Tree_Height(t->right));
}

TreeNode *Tree_Insert(TreeNode *t, int val)
{
	if(NULL == t)
		t = new TreeNode(val);
	else if(val < t->val)
		t->left = Tree_Insert(t->left, val);
	else if(val > t->val)
		t->right = Tree_Insert(t->right, val);
	else
		;

	return t;
}

TreeNode *Tree_Insert_nonRecursive(TreeNode *t, int val)
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

TreeNode *Tree_Delete(TreeNode *t, int x)
{
	if(NULL == t)
		return NULL;

	if(x < t->val)
		t->left = Tree_Delete(t->left, x);
	else if(x > t->val)
		t->right = Tree_Delete(t->right, x);
	else
	{
		TreeNode *tmp;
		if(t->left && t->right)
		{
			tmp = t->right;
			while(tmp->left)
				tmp = tmp->left;		// 找到后驱:右子树中最小的节点
			t->val = tmp->val;
			t->right = Tree_Delete(t->right, tmp->val);
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

void Tree_TrvlPrev(TreeNode *t)
{
	if(NULL == t)
		return;
	cout<<t->val<<" ";
	Tree_TrvlPrev(t->left);
	Tree_TrvlPrev(t->right);
}

void Tree_TrvlIn(TreeNode *t)
{
	if(NULL == t)
		return;
	Tree_TrvlIn(t->left);
	cout<<t->val<<" ";
	Tree_TrvlIn(t->right);
}

void Tree_TrvlPost(TreeNode *t)
{
	if(NULL == t)
		return;
	Tree_TrvlPost(t->left);
	Tree_TrvlPost(t->right);
	cout<<t->val<<" ";
}

void Tree_TrvlPrev_nonRecursive(TreeNode *t)
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

void Tree_TrvlPrev_nonRecursive_improve(TreeNode *t)
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

void Tree_TrvlIn_nonRecursive(TreeNode *t)
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

void Tree_TrvlPost_nonRecursive(TreeNode *t)
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

void Tree_TrvlLevel(TreeNode *t)
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

void Tree_TrvlLevel_reverse(TreeNode *t)
{
	PRINT_SUB_FUNCTION_NAME;

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
			if(t->left)		q.push(t->left);
			if(t->right)	q.push(t->right);
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

void Tree_TrvlZigzag(TreeNode *t)
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
		t = Tree_Insert(t, a[i]);

	Tree_Search(t, 3);
	Tree_Search(t, 9);
	Tree_Search(t, 33);

	cout<<"tree node num = "<<Tree_NodeCount(t)<<endl;
	cout<<"tree height = "<<Tree_Height(t)<<endl;

	Tree_TrvlPrev_nonRecursive_improve(t); 
	Tree_TrvlIn_nonRecursive(t);
	Tree_TrvlPost(t); cout<<endl;

	Tree_Delete(t, 0);

	Tree_TrvlLevel(t);
	Tree_TrvlLevel_reverse(t);
	Tree_TrvlZigzag(t);
}

/**********************************************
	tanjan算法求LCA by union-find
	注意:union和find不能优化,否则会导致回溯过程中,parent指向child的情况发生
	ps:为了显示ancestors方便，MAX取值不要过大（节点的数字尽量采用个位数）
**********************************************/
#define MAX (11)

void print_tarjan_info(bool visited[], int ancestors[], int n)
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

void Tree_TarjanLCA(TreeNode *t, bool visited[], int ancestors[], int n, int x, int y)
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
		Tree_TarjanLCA(t->left, visited, ancestors, n, x, y);	// dfs遍历树
		uf_union(ancestors, t->val, t->left->val);		// 合并子树到自身集合
	}
	if(t->right)
	{
		Tree_TarjanLCA(t->right, visited, ancestors, n, x, y);
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

void test_tree_TarjanLCA()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	TreeNode *t = NULL;

	for(int i = 0; i < Len(a); i++)
		t = Tree_Insert(t, a[i]);
	Tree_TrvlLevel(t);

	bool visited[MAX] = {false};
	int ancestors[MAX];

	uf_init(ancestors, MAX);

	Tree_TarjanLCA(t, visited, ancestors, MAX, 1, 0);	

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

void TrieTree_Insert(TrieTreeNode *t, string word)
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

bool TrieTree_Search(TrieTreeNode *t, string word)
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

	TrieTree_Insert(t, "abc");
	TrieTree_Insert(t, "abcd");
	TrieTree_Insert(t, "abd");

	cout<<"found result: "<<TrieTree_Search(t, "ab")<<endl;
	cout<<"found result: "<<TrieTree_Search(t, "abc")<<endl;
}

/**********************************************
	线段树(Segment)
**********************************************/
typedef struct _SegmentTreeNode
{
	int start, end, max, min, sum;
	_SegmentTreeNode *left, *right;
	_SegmentTreeNode(int s, int end, int val)
	{
		this->start = s;
		this->end = end;
		this->max = this->min = this->sum = val;
		this->left = this->right = NULL;
	}
}SegmentTreeNode;

void SegmentTree_Trvl(SegmentTreeNode *t, int curr_level = 1)
{
	if(NULL == t)
		return;

	for(int i = 0; i < curr_level; i++)
		cout<<"#";
	cout<<"["<<t->start<<"~"<<t->end<<"]:max = "<<t->max<<", min = "<<t->min<<", sum = "<<t->sum<<endl;
	SegmentTree_Trvl(t->left, curr_level+1);
	SegmentTree_Trvl(t->right, curr_level+1);
}

SegmentTreeNode *SegmentTree_Build(int a[], int s, int e)
{
	if(s > e)
		return NULL;

	SegmentTreeNode *node = new SegmentTreeNode(s, e, a[s]);
	if(s == e)
		return node;

	int m = (s + e) / 2;
	node->left = SegmentTree_Build(a, s, m);
	node->right = SegmentTree_Build(a, m+1, e);

	node->max = node->left->max > node->right->max ? node->left->max : node->right->max;
	node->min = node->left->min < node->right->min ? node->left->min : node->right->min;
	node->sum = node->left->sum + node->right->sum;

	return node;
}

void SegmentTree_Improve(SegmentTreeNode *t, int index, int val)
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
		SegmentTree_Improve(t->left, index, val);
	else
		SegmentTree_Improve(t->right, index, val);
	
	t->max = max(t->left->max, t->right->max);
	t->min = min(t->left->min, t->right->min);
	t->sum = t->left->sum + t->right->sum;
}

// 返回a[from]到a[to]的数据的和
int SegmentTree_QuerySum(SegmentTreeNode *t, int from, int to)
{
	if(from > to)
		return 0;
	if(from == t->start && to == t->end)
		return t->sum;

	int m = (t->start + t->end) / 2;
	if(m > to)
		return SegmentTree_QuerySum(t->left, from, to);
	else if(m < from)
		return SegmentTree_QuerySum(t->right, from, to);
	else
	{
		int left = SegmentTree_QuerySum(t->left, from, m);
		int right = SegmentTree_QuerySum(t->right, m+1, to);
		return left + right;
	}
}

void test_SegmentTree_Build()
{
	PRINT_SUB_FUNCTION_NAME;

	int a[] = {1,2,7,8,5};
	SegmentTreeNode *t = SegmentTree_Build(a, 0, Len(a)-1);
	SegmentTree_Trvl(t);
}

void test_SegmentTree_Improve()
{
	PRINT_SUB_FUNCTION_NAME;

	int a[] = {1,2,7,8,5};
	SegmentTreeNode *t = SegmentTree_Build(a, 0, Len(a)-1);

	cout<<"----------improve----------"<<endl;
	SegmentTree_Improve(t, 2, 9);
	SegmentTree_Trvl(t);
}

void test_SegmentTree_QuerySum()
{
	PRINT_SUB_FUNCTION_NAME;

	int a[] = {1,2,7,8,5};
	SegmentTreeNode *t = SegmentTree_Build(a, 0, Len(a)-1);

	cout<<"----------query sum----------"<<endl;
	SegmentTree_Trvl(t);
	cout<<"query sum = "<<SegmentTree_QuerySum(t, 0, 2)<<endl;
}

void test_segment_tree()
{
	PRINT_FUNCTION_NAME;

	test_SegmentTree_Build();
	test_SegmentTree_Improve();
	test_SegmentTree_QuerySum();
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

int AvlTree_Height(AvlTreeNode *t)
{
	if(NULL == t)
		return 0;
	return t->height;
}

void AvlTree_UpdateHeight(AvlTreeNode *t)
{
	t->height = 1 + max(AvlTree_Height(t->left), AvlTree_Height(t->right));
}

void AvlTree_TrvlLevel(AvlTreeNode *t)
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
AvlTreeNode *AvlTree_LeftLeft(AvlTreeNode *k2)
{
	AvlTreeNode *k1 = k2->left;

	k2->left = k1->right;
	k1->right = k2;

	AvlTree_UpdateHeight(k1);
	AvlTree_UpdateHeight(k2);	

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
AvlTreeNode *AvlTree_RightRight(AvlTreeNode *k1)
{
	AvlTreeNode *k2 = k1->right;

	k1->right = k2->left;
	k2->left = k1;

	AvlTree_UpdateHeight(k1);
	AvlTree_UpdateHeight(k2);

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
AvlTreeNode *AvlTree_LeftRight(AvlTreeNode *k3)
{
	k3->left = AvlTree_RightRight(k3->left);
	return AvlTree_LeftLeft(k3);
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
AvlTreeNode *AvlTree_RightLeft(AvlTreeNode *k1)
{
	k1->right = AvlTree_LeftLeft(k1->right);
	return AvlTree_RightRight(k1);
}

AvlTreeNode *AvlTree_Insert(AvlTreeNode *t, int val)
{
	if(NULL == t)
	{
		t = new AvlTreeNode(val);
	}
	else if(val < t->val)
	{
		t->left = AvlTree_Insert(t->left, val);
		if(2 == abs(AvlTree_Height(t->left) - AvlTree_Height(t->right)))
		{
			
			if(val < t->left->val)
				t = AvlTree_LeftLeft(t);
			else
				t = AvlTree_LeftRight(t);
		}
	}
	else if(val > t->val)
	{
		t->right = AvlTree_Insert(t->right, val);
		if(2 == abs(AvlTree_Height(t->left) - AvlTree_Height(t->right)))
		{
			
			if(val > t->right->val)
				t = AvlTree_RightRight(t);
			else
				t = AvlTree_RightLeft(t);
		}
	}
	else
		;

	AvlTree_UpdateHeight(t);
	return t;
}

AvlTreeNode *AvlTree_Delete(AvlTreeNode *t, int x)
{
	if(NULL == t)
		return NULL;

	if(x < t->val)	// x在t的左子树部分,删除后可能导致t的右子树不平衡
	{
		t->left = AvlTree_Delete(t->left, x);
		if(2 == abs(AvlTree_Height(t->left) - AvlTree_Height(t->right)))	// RR or RL
		{
			AvlTreeNode *R = t->right;
			if(AvlTree_Height(R->right) > AvlTree_Height(R->left))		// RR
				t = AvlTree_RightRight(t);
			else
				t = AvlTree_RightLeft(t);									// RL
		}
	}
	else if(x > t->val)	// x在t的右子树部分,删除后可能导致t的左子树不平衡
	{
		t->right = AvlTree_Delete(t->right, x);
		if(2 == abs(AvlTree_Height(t->left) - AvlTree_Height(t->right)))	// LL or LR
		{
			AvlTreeNode *L = t->left;
			if(AvlTree_Height(L->left) > AvlTree_Height(L->right))		// LL
				t = AvlTree_LeftLeft(t);
			else															// LR
				t = AvlTree_LeftRight(t);
		}
	}
	else
	{
		AvlTreeNode *tmp;
		if(t->left && t->right)	// 根据左右子树的高度,再选择用前驱or后驱元素替代
		{
			if(AvlTree_Height(t->left) > AvlTree_Height(t->right))
			{
				// x节点的左子树>右子树,选择前驱元素替代
				tmp = t->left;
				while(tmp->right)
					tmp = tmp->right;
				t->val = tmp->val;
				t->left = AvlTree_Delete(t->left, tmp->val);
			}
			else
			{
				// x节点的左子树<右子树,选择后驱元素替代
				tmp = t->right;
				while(tmp->left)
					tmp = tmp->left;
				t->val = tmp->val;
				t->right = AvlTree_Delete(t->right, tmp->val);
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
		t = AvlTree_Insert(t, a[i]);
	AvlTree_TrvlLevel(t);
	AvlTree_Delete(t, 6);
	AvlTree_TrvlLevel(t);
}

int main()
{
	test_tree();
	test_tree_TarjanLCA();

	test_trie_tree();

	test_segment_tree();

	test_avl_tree();

	return 0;
}