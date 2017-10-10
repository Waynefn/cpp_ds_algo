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
#define Len(x)	sizeof(x)/sizeof(x[0])

typedef struct _element
{
	int val;
	_element *next;
}element;

typedef struct _queuehead
{
	element *first;		// pop point
	element *last;		// push point
	_queuehead()
	{
		this->first = NULL;
		this->last = NULL;
	}
}queuehead;

void show_radixSort();

bool queue_isEmpty(queuehead *qh)
{
	if(qh->first == NULL)
	{
		// 此时原本last指向的队尾元素已经被first指针pop并delete，会变成野指针
		qh->last = NULL;
		return true;
	}
	else
		return false;
}

void queue_push(queuehead *qh, int val)
{
	element *e = new element;
	e->next = NULL;
	e->val = val;
	if(qh->first == NULL)
	{
		// coding
		qh->first = e;
		qh->last = e;
	}
	else
	{
		// coding
		qh->last->next = e;
		qh->last = e;
	}
}

int queue_pop(queuehead *qh)	// coding
{
	if(queue_isEmpty(qh))
	{
		return -1;
	}

	element *tmp = qh->first;
	int res = tmp->val;

	qh->first = tmp->next;
	delete tmp;

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

	while((data = queue_pop(input)) >= 0)
	{
		i = (data / div) % M;
		queue_push(&buf[i], data);
	}

	for(i = 0; i < M; i++)
		while((data = queue_pop(&buf[i])) >= 0)
			queue_push(output, data);

	while((data = queue_pop(output)) >= 0)
		cout<<data<<" ";
	cout<<endl;
}

void test_question_1()
{
	int a[] = {52, 97, 74, 0, 37, 14, 57, 95};
	queuehead input, output;

	for(int i = 0; i < Len(a); i++)
		queue_push(&input, a[i]);

	radix_sort(&input, &output, 0);
}

int main()
{
	test_question_1();

	return 0;
}