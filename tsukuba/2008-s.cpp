/*
http://www.cs.tsukuba.ac.jp/admission/21-8inf.pdf
	问题1->二叉树的树高/遍历/搜索/插入
	问题2->电路卡诺图
*/

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

using namespace std;

/***************************************
问题1->二叉树的树高/遍历/搜索/插入

***************************************/
typedef struct _node
{
	int key;
	int val;
	_node *left;
	_node *right;
}node;
node *root = NULL;

int height1(node *p)
{
	int a, b;
	if(NULL == p)
		return 0;

	a = height1(p->left);	// coding
	b = height1(p->right);	// coding
	if(a >= b)
		return 1 + a;		// coding
	else
		return 1 + b;		// coding
}

int height()
{
	return height1(root);
}

void print1(node *p, int level)
{
	int i ;
	if(NULL == p)
		return;
	for(i = 0; i < level; i++)
		cout<<"*";
	printf("key:%d, val:%d\n", p->key, p->val);
	print1(p->left, level+1);
	print1(p->right, level+1);
}

void print()
{
	print1(root, 1);
}

int get1(node *p, int key)
{
	if(NULL == p)
		return -1;
	if(key == p->key)		// coding
		return p->val;
	else if(key < p->key)	// coding
		return get1(p->left, key);	// coding
	else
		return get1(p->right, key);	// coding
}

int get(int key)
{
	return get1(root, key);
}

node *make_node(int key, int val)
{
	node *p = new node;
	p->key = key;
	p->val = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void put1(node *p, int key, int val)
{
	if(key == p->key)	// coding
		p->val = val;
	else if(key < p->key)	// coding
	{
		if(NULL == p->left)	// coding
			p->left = make_node(key, val);	// coding
		else
			put1(p->left, key, val);		// coding
	}
	else
	{
		if(NULL == p->right)	// coding
			p->right = make_node(key, val);	// coding
		else
			put1(p->right, key, val);		// coding
	}
}

void put(int key, int val)
{
	if(NULL == root)
		root = make_node(key, val);
	else
		put1(root, key, val);
}

void test_question_1()
{
	put(10, 1);
	put(40, 2);
	put(50, 3);
	put(65, 1);
	put(70, 3);
	put(85, 2);
	print();
	cout<<"height = "<<height()<<endl;
}

int main()
{
	test_question_1();

	return 0;
}