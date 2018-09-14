/*
http://www.cs.tsukuba.ac.jp/admission/28-2inf.pdf
	问题1->二叉树基本操作
	问题2->卡诺图
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->二叉树基本操作
***************************************/
#define A 	node != &EMPTY
#define B	t->left	
#define C 	insert(t->left, v)
#define D 	else if(v > t->val)
#define E 	t->right
#define F 	insert(t->right, v)

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct tree_node
{
	int val;
	tree_node *left, *right;
}*tree;

tree_node EMPTY = 
{
	-1, 
	&EMPTY,
	&EMPTY
};

tree find_node(tree t, int v)
{
	while(v != t->val)
	{
		if(v < t->val)
			t = t->left;
		else
			t = t->right;
	}
	return t;
}

int contains(tree t, int v)
{
	EMPTY.val = v;
	tree node = find_node(t, v);
	return A;
}

tree insert(tree t, int v)
{
	if(t == &EMPTY)
	{
		tree node = new tree_node;
		node->val = v;
		node->left = node->right = &EMPTY;
		return node;
	}
	if(v < t->val)
		B = C;
	D
		E = F;

	return t;
}

void test_question_1()
{
	tree t = &EMPTY;

	int a[] = {11,5,28,2,13};

	for(int i = 0; i < Len(a); i++)
		t = insert(t, a[i]);

	cout<<contains(t, 3)<<endl;
}

int main()
{
	test_question_1();

	return 0;
}