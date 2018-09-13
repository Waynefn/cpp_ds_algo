/*
http://www.cs.tsukuba.ac.jp/admission/22-8inf.pdf
	问题1->链表的顺序插入，求和
	问题2->
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->

***************************************/
#define A1 	sum += p->data
#define B1 	p->next

#define A2	x
#define B2	t
#define C2	t
#define D2	p

#define A3	p->data == x
#define B3	p->next
#define C3	p->next

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _List
{
	int data;
	_List *next;
	_List() {this->next = NULL;}

}List;
List *head = NULL;

void trvl_list()
{
	for(List *i = head; i != NULL; i = i->next)
		cout<<i->data<<"-";
	cout<<endl;
}

int sum_list()
{
	List *p;
	int sum = 0;

	p = head;
	while(p != NULL)
	{
		A1;
		p = B1;
	}

	cout<<"sum = "<<sum<<endl;
	return sum;
}

void insert_list(int x)
{
	List *p, *q, *t;

	q = NULL;
	for(p = head; p != NULL; p = p->next)
	{
		if(p->data >= x)
			break;
		q = p;
	}

	t = new List;
	t->data = A2;

	if(q == NULL)
		head = B2;
	else
		q->next = C2;
	t->next = D2;
}

void delete_list(int x)
{
	List *p, *q;

	q = NULL;
	for(p = head; p != NULL; p = p->next)
	{
		if(A3)
		{
			if(q == NULL)
				head = B3;
			else
				q->next = C3;
			delete p;
			return;
		}
		q = p;
	}
}

void test_question_1()
{
	insert_list(1);
	insert_list(5);
	insert_list(3);
	trvl_list();

	delete_list(3);
	trvl_list();

	sum_list();
}

int main()
{
	test_question_1();

	return 0;
}