/*
https://www.titech.ac.jp/graduate_school/admissions/pdf/cs_h29.pdf
问题3->复杂链表
1.运算符优先级（给后续的题目做铺垫）
	a)	CDEFH
	b)	*x->y == (*x)->y
		&x.y == &(x.y)
	c)	x->y->z == (x->y)->z 	.和->是左结合
		*&x == *(&x)			*和&是右结合
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void test_1()
{
	if(0 && printf("A")) {printf ("B");};
	if(1 && printf("C")) {printf ("D");};
	if(0 || printf("E")) {printf ("F");};
	if(1 || printf("G")) {printf ("H");};
	cout<<endl;
}

/***************************************
问题3.2->链表插入
	a) 链表有序插入数据，head->升序->NULL
***************************************/
typedef struct _CELL
{
	int data;
	_CELL *next;
}CELL;

void print_list(CELL *head)
{
	CELL *p = head;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}cout<<endl;
}

CELL *CELL_alloc(int data)
{
	CELL *p = (CELL *)malloc(sizeof(CELL));
	p->data = data;
	p->next = NULL;
	return p;
}

CELL *insert1(CELL *head, int data)
{
	CELL *node = CELL_alloc(data);
	CELL *p = head;

	if(NULL == p || data < p->data) // 头插
	{
		node->next = p;
		return node;
	}
	else
	{
		while(NULL != p->next && data > p->next->data) // 找到该插入的地方
			p = p->next;
		node->next = p->next;
		p->next = node;
		return head;
	}
}

void insert2(CELL **head_p, int data)
{
	CELL *node = CELL_alloc(data);
	CELL **p = head_p;
	
	while(NULL != (*p) && data > (*p)->data)
		p = &(*p)->next; 

	node->next = *p;
	*p = node;
}

void test_2()
{
	CELL *h1 = NULL;
	
	// h1 = insert1(h1, 10);
	// h1 = insert1(h1, 30);
	// h1 = insert1(h1, 20);
	// print_list(h1);

	CELL *h2 = NULL;
	insert2(&h2, 1);
	insert2(&h2, 10);
	insert2(&h2, 3);
	insert2(&h2, 5);
	print_list(h2);
}

/***************************************
问题3.3->链表翻转
	a) 递归操作，翻转链表
***************************************/
CELL *reverse1(CELL *head)
{
	CELL *p = NULL;
	if(head == NULL || head->next == NULL)
		return head;

	p = reverse1(head->next);
	head->next->next = head;
	head->next = NULL;
	return p;
}

CELL *reverse2(CELL *head1, CELL *head2)
{
	if(head1 == NULL)
		return head2;

	CELL *h1 = head1->next;
	head1->next = head2;
	CELL *h2 = head1;

	return reverse2(h1, h2);
}

CELL *reverse3(CELL *head)
{
	CELL *p1 = NULL, *p2 = head, *p3;
	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}

void test_3()
{
	CELL *h1 = NULL;
	h1 = insert1(h1, 10);
	h1 = insert1(h1, 30);
	h1 = insert1(h1, 20);
//	h1 = reverse1(h1);
	print_list(h1);

	// CELL *h2 = NULL;
	// h2 = insert1(h2, 10);
	// h2 = insert1(h2, 30);
	// h2 = insert1(h2, 20);
	// h2 = reverse2(h2, NULL);
	// print_list(h2);

	// CELL *h3 = NULL;
	// h3 = insert1(h3, 10);
	// h3 = insert1(h3, 30);
	// h3 = insert1(h3, 20);
	// h3 = reverse3(h3);
	// print_list(h3);
}

int main()
{
//	test_1();
	test_2();
//	test_3();
	return 0;
}