#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

typedef struct _TreeNode
{
	int val;
	_TreeNode *left, *right;
	_TreeNode(int v)
	{
		this->val = v;
		this->left = this->right = NULL;
	}
}TreeNode;

void TrvlPrev(TreeNode *t)
{
	if(NULL == t)
		return;
	cout<<t->val<<" ";
	TrvlPrev(t->left);
	TrvlPrev(t->right);
}

void TrvlIn(TreeNode *t)
{
	if(NULL == t)
		return;
	TrvlIn(t->left);
	cout<<t->val<<" ";
	TrvlIn(t->right);
}

void TrvlPost(TreeNode *t)
{
	if(NULL == t)
		return;
	TrvlPost(t->left);
	TrvlPost(t->right);
	cout<<t->val<<" ";
}

void TrvlLvl(TreeNode *t)
{
	if(NULL == t)
		return;

	queue<TreeNode *> q;
	q.push(t);
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			TreeNode *tmp = q.front(); q.pop();
			cout<<tmp->val<<" ";
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		cout<<"| ";
	}
	cout<<endl;
}

void TrvlLvlRev(TreeNode *t)
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

void TrvlPrev2(TreeNode *t)
{
	stack<TreeNode *> s;
	while(!s.empty() || t)
	{
		while(t)
		{
			cout<<t->val<<" ";
			s.push(t);
			t = t->left;
		}
		t = s.top(); s.pop();
		t = t->right;
	}cout<<endl;
}

void TrvlIn2(TreeNode *t)
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
		cout<<t->val<<" ";
		t = t->right;
	}cout<<endl;
}

void TrvlPost2(TreeNode *t)
{
	stack<TreeNode *> s;
	TreeNode *last = NULL;
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
			cout<<t->val<<" ";
			last = t;
			t = NULL;
			s.pop();
		}
	}cout<<endl;
}

TreeNode* Insert(TreeNode *root, int v)
{
	if(NULL == root)
	{
		TreeNode *n = new TreeNode(v);
		return n;
	}
	if(v < root->val)
		root->left = Insert(root->left, v);
	else if(v > root->val)
		root->right = Insert(root->right, v);
	else
		;

	return root;
}

TreeNode* Delete(TreeNode *root, int v)
{
	if(NULL == Delete)
		return root;
	if(v < root->val)
		root->left = Delete(root->left, v);
	else if(v > root->val)
		root->right = Delete(root->right, v);
	else
	{
		TreeNode *tmp;
		if(root->left && root->right)
		{
			tmp = root->left;
			while(tmp->right)
				tmp = tmp->right;
			root->val = tmp->val;
			root->left = Delete(root->left, tmp->val);
		}
		else
		{
			tmp = root;
			if(root->left)	root = root->left;
			else			root = root->right;
			delete tmp;
		}
	}

	return root;
}

int main()
{
	TreeNode *t = NULL;

	int a[] = {6,4,8,2,7,9,1,3,10,0};
	for(int i = 0; i < 10; i++)
		t = Insert(t, a[i]);
	// t = Insert(t, 5);
	TrvlLvl(t);
	t = Delete(t, 6);
	TrvlLvl(t);
	TrvlLvlRev(t);
	return 0;
}