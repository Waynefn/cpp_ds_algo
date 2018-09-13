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
#define A1 	x
#define B1 	x < p->data
#define C1 	insert_node(x, p->left)
#define D1 	insert_node(x, p->right)

#define A2 	NULL == p
#define B2 	p->data + sum_node(p->left) + sum_node(p->right)

#define A3 	q != NULL
#define B3 	x < q->data
#define C3 	q->left
#define D3 	q->right

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
		p->data = A1;
		p->left = NULL;
		p->right = NULL;
		return p;
	}

	if(x == p->data)
		return p;
	if(B1)
		p->left = C1;
	else
		p->right = D1;
	return p;
}

int sum_node(node *p)
{
	if(A2)
		return 0;
	return B2;
}

int search_node(int x, node *p)
{
	node *q = p;

	while(A3)
	{
		if(x == q->data)
			return 1;
		if(B3)
			q = C3;
		else
			q = D3;
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