/*
http://www.cs.tsukuba.ac.jp/admission/20-8inf.pdf
	问题1->链表遍历,求长度等
	问题2->离散数学逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->链表遍历,求长度等
	1.补充代码,实现遍历
	2.补充代码,实现求链表长度,分析[遍历]与[递归]方式哪个好,为什么
		length()好,相比递归方式,减少了函数调用时的开销与函数栈空间的分配
	3.补充代码,实现尾插,创建节点
		[blue, yellow, red, black, white]
		f(p1,p1)的话会导致程序死循环,因为组成循环链表无法退出while循环
		完成改进后的safe_f()函数 ???
***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _list
{
	char *elem;
	_list *next;		// coding
}list;

void print(list *p)
{
	if(p->next == NULL)
		cout<<"[]"<<endl;	
	else
	{
		cout<<"["<<p->elem;
		for(p = p->next; p != NULL; p = p->next)	// coding
			cout<<", "<<p->elem;
		cout<<"]"<<endl;
	}
}

int length(list *p)
{
	int n = 0;
	while(p != NULL)
	{
		n++;
		p = p->next;
	}

	return n;
}

int length_r(list *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + length_r(p->next);
}

list *f(list *p, list *q)
{
	list *pt = p;
	if(NULL == p)
		return q;

	while(pt->next != NULL)
		pt = pt->next;
	pt->next = q;

	return p;
}

list *cons(char *s, list *p)
{
	list *t = new list;
	t->elem = s;
	t->next = p;

	return t;
}

list *safe_f(list *p, list *q)
{
	list *pt = q;
	if(NULL == p)
	{
		if(NULL == q)
			return NULL;		// coding
		else
			return cons(p, safe_f(NULL, NULL));	// coding
	}
	else
		return cons(" ", safe_f(p, q));		// coding
}

void test_question_1()
{
	list *p1, *p2;
	p1 = cons("blue", cons("yellow", cons("red", NULL)));
	p2 = cons("black", cons("white", NULL));
//	print(f(p1,p2));

	print(safe_f(p1,p2));
}

int main()
{
	test_question_1();

	return 0;
}