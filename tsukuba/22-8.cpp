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
	t->data = x;		// coding

	if(q == NULL)
		head = t;
	else
		q->next = t;	// coding
	t->next = p;
}

void delete_list(int x)
{
	List *p, *q;

	q = NULL;
	for(p = head; p != NULL; p = p->next)
	{
		if(p->data == x)	// coding
		{
			if(q == NULL)
				head = p->next;		// coding
			else
				q->next = p->next;	// coding
			delete p;
			return;
		}
		q = p;
	}
}

int sum_list()
{
	List *p;
	int sum = 0;

	p = head;
	while(p != NULL)
	{
		sum += p->data;		// coding
		p = p->next;		// coding
	}

	cout<<"sum = "<<sum<<endl;
	return sum;
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