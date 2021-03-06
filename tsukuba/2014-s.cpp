/*
http://www.cs.tsukuba.ac.jp/admission/27-8inf.pdf
	问题1->多个二叉树
	问题2->卡诺图
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->多叉树
***************************************/
#define B 	if(p == NULL)	return 0
#define C 	return p->val + sumup_tree2(p->right)

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _node
{
	int val;
	_node *left;
	_node *right;
}node;

node *root = NULL;

node *make_node(int val, node *left, node *right)
{
	node *p = new node;
	p->val = val;
	p->left = left;
	p->right = right;

	return p;
}

void make_sample_tree()
{
	node *n2, *n3;

	n3 = make_node(3, NULL, NULL);
	n2 = make_node(2, NULL, n3);
	root = make_node(1, n2, NULL);
}

int sumup_list1(node *p, int val)
{
	while(p != NULL)
	{
		p->val += val;
		val = p->val;
		p = p->right;
	}

	return val;
}

int sumup_list2(node *p)
{
	if(p == NULL) return 0;
	p->val += sumup_list2(p->right);
	return p->val;
}

int sumup_tree1(node *p, int val)
{
	if(p == NULL)	return val;
	p->val += sumup_tree1(p->left, val);	/*A*/
	return sumup_tree1(p->right, p->val);
}

int sumup_tree2(node *p)
{
	B;
	p->val += sumup_tree2(p->left);
	C;
}

void test_question_1()
{
	node *n1, *n2, *n3;
	n3 = make_node(3, NULL, NULL);
	n2 = make_node(2, NULL, n3);
	n1 = make_node(1, NULL, n2);
	sumup_tree1(n1, 0);
	cout<<n1->val<<endl;
	cout<<n2->val<<endl;
	cout<<n3->val<<endl;
}

void test_question_2()
{
	node *n2, *n4, *n6;
	n6 = make_node(6, NULL, NULL);
	n4 = make_node(4, NULL, n6);
	n2 = make_node(2, NULL, n4);
	sumup_tree2(n2);
	cout<<n2->val<<endl;
	cout<<n4->val<<endl;
	cout<<n6->val<<endl;
}

void test_question_3()
{
	node *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	n7 = make_node(7, NULL, NULL);
	n6 = make_node(6, NULL, n7);
	n5 = make_node(5, NULL, n6);
	n4 = make_node(4, NULL, NULL);
	n3 = make_node(3, n5, NULL);
	n2 = make_node(2, n4, n3);
	n1 = make_node(1, n2, NULL);
	sumup_tree2(n1);
	cout<<n1->val<<endl;
	cout<<n2->val<<endl;
	cout<<n3->val<<endl;
	cout<<n4->val<<endl;
	cout<<n5->val<<endl;
	cout<<n6->val<<endl;
	cout<<n7->val<<endl;
}

int main()
{
	// test_question_1();
	// test_question_2();
	test_question_3();
	return 0;
}