/*
问题2：带父节点的二叉树

*/

#include <iostream>
#include <queue>

using namespace std;

#define Len(x)		sizeof(x)/sizeof(x[0])	
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct _Node
{
	int key;
	_Node *left, *right, *parent;
	_Node(int key)
	{
		this->key = key;
		this->left = this->right = this->parent = NULL;
	}
}Node;

void trvl_level(Node *root)
{
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *cur = q.front(); q.pop();
		cout<<cur->key<<"->"<<cur->parent->key<<endl;
		if(cur->left)
			q.push(cur->left);
		if(cur->right)
			q.push(cur->right);
	}cout<<endl;
}

Node *insert(Node *root, int newkey)
{
	Node *n = new Node(newkey);
	if(NULL == root)
	{
		n->parent = new Node(-1);
		return n;
	}

	Node *i = root, *j = NULL;
	while(i)
	{
		j = i;
		if(newkey < i->key)
			i = i->left;
		else
			i = i->right;
	}
	if(newkey < j->key)
		j->left = n;
	else
		j->right = n;
	n->parent = j;

	return root;
}

bool find_r(Node *node, int k)
{
	if(NULL == node)
		return false;
	if(k < node->key)
		return find_r(node->left, k);
	else if(node->key == k)
		return true;
	else
		return find_r(node->right, k);
}

bool find(Node *node, int k)
{
	Node *i = node;
	while(i)
	{
		if(k < i->key)
			i = i->left;
		else if(k > i->key)
			i = i->right;
		else
			return true;
	}
	return false;
}

int main()
{
	int a[] = {11,4,21,3,9,17,22,15,18};
	Node *root = NULL;
	for(int i = 0; i < Len(a); i++)
        root = insert(root, a[i]);
	trvl_level(root);
	cout<<find(root, 15);

	return 0;
}