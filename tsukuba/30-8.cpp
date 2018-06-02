/*
http://www.cs.tsukuba.ac.jp/admission/30-8.pdf
	问题4->逆波兰表达式树,链表实现stack
			-
A		 +    30	中序遍历：((10+20)-30)
	  10  20		后续遍历：10 20 + 30 -

		 +
	 10      +
B		  20    +
		     30   40

			?
C		==  30  40
	  10  20

	1.C的后续遍历： 10 20 == 30 40 ?
	2.
		+				
	+		-
  1   2   3   4
后续1 2 + 3 4 - + 
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define OK (1)
#define ERROR (0)
extern int error;

typedef struct _element
{
	_element *next;
	int data;
}element;
element *sp = NULL;
int error = 0;

void free_stack()
{
	while(sp != NULL)
	{
		element *tmp = sp;
		sp = sp->next;
		delete tmp;
	}
}

void init_stack()
{
	free_stack();
	sp = NULL;
	error = 0;
}

void push(int x)
{
	element *n = new element;
	n->next = sp;	// M
	n->data = x;	// N
	sp = n;			// O
}

int pop()
{
	int x;
	element *f;
	if(NULL == sp)
	{
		error = 1;	// stack NULL
		return 0;
	}
	x = sp->data;	// Q
	f = sp;
	sp = sp->next;	// R
	free(f);
	return x;
}

void do_num(char *s)
{
	int a = atoi(s);
	push(a);
}

void do_add()
{
	int a = pop(), b = pop();
	push(a+b);
}

void do_sub()
{
	int a = pop(), b = pop();	// F G
	push(b-a);					// H
}

void do_eq()
{
	int a = pop(), b = pop();
	push(a == b);
}

void do_not()
{
	int a = pop();
	push(!a);
}

void do_cond()
{
	int a = pop(), b = pop(), c = pop();	// I J
	if(a)	push(b);	// K
	else	push(c);	// L
}

int calc(char *exp[], int *xp)
{
	init_stack();
	for(int i = 0; exp[i] != NULL; i++)
	{
		if(isdigit(exp[i][0]))		do_num(exp[i]);
		else if(0 == strcmp(exp[i],"+"))	do_add();
		else if(0 == strcmp(exp[i],"-"))	do_sub();
		else if(0 == strcmp(exp[i],"=="))	do_eq();
		else if(0 == strcmp(exp[i],"!"))	do_not();
		else if(0 == strcmp(exp[i],"?"))	do_cond();
		else
		{
			free_stack();
			return ERROR;
		}
	}
	*xp = pop();
	free_stack();
	if(error)	return ERROR;
	else		return OK;
}

void test_question_4()
{
	int x = 0;
	char *exp[] = {"10", "20", "==", "30", "40", "?", NULL};
	if(OK == calc(exp, &x))
		cout<<"OK, ret = "<<x<<endl;
	else
		cout<<"Error"<<endl;
}

int main()
{
	test_question_4();

	return 0;
}