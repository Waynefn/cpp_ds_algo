/*
http://www.cs.tsukuba.ac.jp/admission/19-2infj.pdf
	问题1->链表实现栈，实现[加法][减法][交换][变符号]
	问题2->图的离散逻辑
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->链表实现栈，实现[加法][减法][交换][变符号]

***************************************/
#define A 	sp
#define B 	data
#define C 	sp = e
#define D 	push(arg2)
#define E 	push(arg1)
#define F 	0
#define G	sub()

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _element
{
	int data;
	_element *next;
}element;

element *sp;

void push(int data)
{
	element *e = new element;
	e->next = A;
	e->data = B;			
	C;					
}

int pop()
{
	if(sp == NULL)
		return -1;

	element *e = sp;
	int res = e->data;

	sp = e->next;
	delete e;

	return res;
}

void sub()
{
	int arg1, arg2, res;
	arg2 = pop();
	arg1 = pop();
	res = arg1 - arg2;
	push(res);
	cout<<"sub res = "<<res<<endl;
}

void mul()
{
	int arg1, arg2, res;
	arg2 = pop();
	arg1 = pop();
	res = arg1 * arg2;
	push(res);
	cout<<"mul res = "<<res<<endl;
}

void print()
{
	int data;
	data = pop();
	cout<<data<<endl;
}

void swap()
{
	int arg1, arg2;
	arg2 = pop();
	arg1 = pop();
	D;
	E;
}

void Negate()
{
	push(F);
	swap();
	G;
}

void test_question_1()
{
	push(10); push(20); push(30);
	mul(); sub(); print();
	swap(); print(); print();
	push(50); Negate(); 
}

int main()
{
	test_question_1();

	return 0;
}