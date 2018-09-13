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
#define A1 	p->left
#define B1 	p->right
#define C1 	1 + a
#define D1 	1 + b

#define A2 	key == p->key
#define B2 	key < p->key
#define C2 	get1(p->left, key)
#define D2 	get1(p->right, key)

#define A3 	key == p->key
#define B3 	key < p->key
#define C3 	p->left
#define D3 	put1(p->left, key, val)
#define E3 	p->right
#define F3 	put1(p->right, key, val)

#define A4 	10, 1
#define B4 	40, 2
#define C4 	50, 3
#define D4 	65, 1
#define E4 	70, 3
#define F4 	85, 2

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

	a = height1(A1);
	b = height1(B1);
	if(a >= b)
		return C1; 
	else
		return D1;
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
	if(A2)		// coding
		return p->val;
	else if(B2)	// coding
		return C2;	// coding
	else
		return D2;	// coding
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
	if(A3)
		p->val = val;
	else if(B3)
	{
		if(NULL == C3)
			C3 = make_node(key, val);
		else
			D3;
	}
	else
	{
		if(NULL == E3)
			E3 = make_node(key, val);
		else
			F3;
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
	put(A4);
	put(B4);
	put(C4);
	put(D4);
	put(E4);
	put(F4);
	print();
	cout<<"height = "<<height()<<endl;
}

int main()
{
	test_question_1();

	return 0;
}