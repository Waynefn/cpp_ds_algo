/*
http://www.cs.tsukuba.ac.jp/admission/19-8infj.pdf
	问题1->list实现queue,然后基数排序
	问题2->离散数学的题
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/**********************************************
问题1->list实现queue,然后基数排序
	用list来实现queue
	first指向队首，last指向队尾
	push时：将新元素置于last后面
	pop时：将first指向的元素弹出，然后first=first->next
	empty时：

**********************************************/
#define A 	NULL
#define B 	data
#define C 	qh->first = qh->last = e;
#define D 	qh->last->next = e;	\
			qh->last = e;

#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _element
{
	int data;
	_element *next;
}element;

typedef struct _queuehead
{
	element *first;
	element *last;
	_queuehead()
	{
		first = last = NULL;
	}
}queuehead;

void show_radixSort();

bool emptyqueue(queuehead *qh)
{
	return qh->first == NULL;
}

void enqueue(queuehead *qh, int data)
{
	element *e = new element;
	e->next = A;
	e->data = B;
	if(qh->first == NULL)
	{
		C
	}
	else
	{
		D
	}
}

int dequeue(queuehead *qh)	// coding
{
	if(emptyqueue(qh))
		return -1;

	element *tmp = qh->first;
	int res = tmp->data;

	qh->first = tmp->next;
	delete tmp;

	if(qh->first == NULL)
		qh->last = NULL;	// 此时原本last指向的队尾元素已经被first指针pop并delete，会变成野指针

	return res;
}

/**********************************************
	链表队列应用于基数排序
	http://www.cs.tsukuba.ac.jp/admission/19-8infj.pdf
**********************************************/
#define M (10)	// 十进制
void radix_sort(queuehead *input, queuehead *output, int n)
{
	queuehead buf[M];

	int data, div, i;
	for(i = 0, div = 1; i < n; i++)
		div = div * M;

	while((data = dequeue(input)) >= 0)
	{
		i = (data / div) % M;
		enqueue(&buf[i], data);
	}

	for(i = 0; i < M; i++)
		while((data = dequeue(&buf[i])) >= 0)
			enqueue(output, data);
}

void test_question_1()
{
//	int a[] = {52, 97, 74, 0, 37, 14, 57, 95};
	int a[] = {81,22,73,93,43,14,55,65,28,39};
	queuehead input, output;
	int data;

	for(int i = 0; i < Len(a); i++)
		enqueue(&input, a[i]);

	radix_sort(&input, &output, 0);
	radix_sort(&output, &input, 1);

	while((data = dequeue(&input)) >= 0)
		cout<<data<<" ";
	cout<<endl;
}

int main()
{
	test_question_1();

	return 0;
}