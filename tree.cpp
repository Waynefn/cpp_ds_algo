#include <iostream>
#include <queue>
#include <stack>

#include "main.h"
#include "tree.h"

using namespace std;

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

void test_tree_basic()
{
	PRINT_FUNCTION_NAME;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	TreeNode *root = NULL;

	for(int i = 0; i < Len(a); i++)
		root = tree_insert(root, a[i]);

	tree_trvl_prev_nonRecursive_modify(root); 
	tree_trvl_in_nonRecursive(root); cout<<endl;
	tree_trvl_post(root); cout<<endl;

}
