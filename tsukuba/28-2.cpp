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
	1.find_node(t, 9)的结果：程序不会停止
	2.完成contains()函数
	3.n个不同的随机数产生的tree,调用contains()时,时间复杂度?
		题意应该是只调用一次->logn
	4.最差情况时调用contains()时,时间复杂度?
		题意应该是只调用一次->n
	5.完成insert()函数
***************************************/

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

/*
	return true:找到了v
	return false:没有找到v
*/
int contains(tree t, int v)
{
	EMPTY.val = v;
	tree node = find_node(t, v);
	return node != &EMPTY;
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
		t->left = insert(t->left, v);	// coding
	else if(v > t->val)					// coding
		t->right = insert(t->right, v);	// coding

	return t;
}

void test_question_1()
{
	tree t = &EMPTY;

	int a[] = {11,5,28,2,13};

	for(int i = 0; i < Len(a); i++)
		t = insert(t, a[i]);

	cout<<contains(t, 9)<<endl;
}

int main()
{
	test_question_1();

	return 0;
}