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
#define A1 	_list
#define B1 	p == NULL
#define C1 	p->next
#define D1 	p != NULL
#define E1 	p->next

#define A2 	p != NULL
#define B2	n++
#define C2	p->next
#define D2	p == NULL
#define E2 	1
#define F2	p->next

#define A3	NULL
#define B3	q->elem
#define C3	NULL
#define D3	q->next
#define E3	p->elem
#define F3	p->next	
#define G3	q

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _list
{
	char *elem;
	A1 *next;
}list;

void print(list *p)
{
	if(B1)
		cout<<"[]"<<endl;	
	else
	{
		cout<<"["<<p->elem;
		for(p = C1; D1; p = E1)
			cout<<", "<<p->elem;
		cout<<"]"<<endl;
	}
}

int length(list *p)
{
	int n = 0;
	while(A2)
	{
		B2;
		p = C2;
	}

	return n;
}

int length_r(list *p)
{
	if(D2)
		return 0;
	else
		return E2 + length_r(F2);
}

list *f(list *p, list *q)	// pq 连接起来
{
	list *pt = p;
	if(NULL == p)
		return q;

	while(pt->next != NULL)
		pt = pt->next;
	pt->next = q;

	return p;
}

list *cons(char *s, list *p)	// p串头插s得到sp
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
			return A3;
		else
			return cons(B3, safe_f(C3, D3));
	}
	else
		return cons(E3, safe_f(F3, G3));
}

void test_question_1()
{
	list *p1, *p2;
	p1 = cons("blue", cons("yellow", cons("red", NULL)));
	p2 = cons("black", cons("white", NULL));
	print(f(p1,p2));
	// print(safe_f(p1,p2));
	print(NULL);
}

int main()
{
	test_question_1();

	return 0;
}