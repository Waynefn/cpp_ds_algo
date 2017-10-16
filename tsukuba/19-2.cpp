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

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _element
{
	int data;
	_element *next;
	_element(int val)
	{
		this->data = val;
		this->next = NULL;
	}
}element;

element *sp;

void push(int data)
{
	element *e = new element;
	e->data = data;			// coding
	e->next = sp;			// coding
	sp = e;					// coding
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
	push(arg2);		// coding
	push(arg1);		// coding
}

void Negate()
{
	push(0);
	swap();
	sub();
}

void test_question_1()
{
//	push(10); push(20); push(30);
//	mul(); sub(); print();
//	swap(); print(); print();
	push(50); Negate(); 
}

int main()
{
	test_question_1();

	return 0;
}