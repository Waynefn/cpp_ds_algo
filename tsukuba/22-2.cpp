/*
http://www.cs.tsukuba.ac.jp/admission/22-2inf.pdf
	问题1->二叉树插入/求和/搜索
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->二叉树插入/求和/搜索

***************************************/

typedef struct _node
{
	int data;
	_node *left;
	_node *right;
}node;

node *insert_node(int x, node *p)
{
	if(NULL == p)
	{
		p = new node;
		p->data = x;			// coding
		p->left = NULL;
		p->right = NULL;

		return p;
	}

	if(x == p->data)
		return p;

	if(x < p->data)				// coding
		p->left = insert_node(x, p->left);		// coding
	else
		p->right = insert_node(x, p->right);	// coding

	return p;
}

int sum_node(node *p)
{
	if(NULL == p)		// coding
		return 0;

	return p->data + sum_node(p->left) + sum_node(p->right);	// coding
}

int search_node(int x, node *p)
{
	node *q = p;

	while(q != NULL)		// coding
	{
		if(x == q->data)
			return 1;
		if(x < q->data)		// coding
			q = q->left;	// coding
		else
			q = q->right;	// coding
	}

	return 0;
}

void test_question_1()
{
	node *root = NULL;

	root = insert_node(1, root);
	root = insert_node(3, root);
	root = insert_node(5, root);

	cout<<"sum_node = "<<sum_node(root)<<endl;

	cout<<search_node(3, root)<<endl;
	cout<<search_node(6, root)<<endl;
}

int main()
{
	test_question_1();

	return 0;
}