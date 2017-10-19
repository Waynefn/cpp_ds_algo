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
	int val;
	int cnt;
	_TreeNode *left;
	_TreeNode *right;
	_TreeNode(int val)
	{
		this->val = val;
		this->cnt = 1;
		this->left = NULL;
		this->right = NULL;
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
	字典树(Trie)
**********************************************/
typedef struct _TrieNode
{
	bool exist;	// 用于以后删除单词时,不破坏树结构
	_TrieNode *child[26];
	_TrieNode()
	{
		this->exist = false;
		for(int i = 0; i < 26; i++)
			this->child[i] = NULL;
	}
}TrieNode;

void trie_insert(TrieNode *t, string word)
{
	TrieNode *dummy = t;

	for(int i = 0; i < word.length(); i++)
	{
		int c = word[i] - 'a';
		if(NULL == dummy->child[c])
			dummy->child[c] = new TrieNode;
		dummy = dummy->child[c];
	}
	dummy->exist = true;
}

bool trie_search(TrieNode *t, string word)
{
	TrieNode *dummy = t;

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
	TrieNode *t = new TrieNode;

	trie_insert(t, "abc");
	trie_insert(t, "abcd");
	trie_insert(t, "abd");

	trie_search(t, "abc");
	trie_search(t, "abca");
}

/**********************************************
	线段树(Segment)
**********************************************/

int main()
{
	test_tree();
	test_trie_tree();

	return 0;
}