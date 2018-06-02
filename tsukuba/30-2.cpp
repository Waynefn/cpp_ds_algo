/*
http://www.cs.tsukuba.ac.jp/admission/30-2.pdf
	问题4->动态数组
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define CAPACITY (10)

typedef struct
{
	int *array;
	int size;
	int capacity;
}List;

void print_list(List *l)
{
	for(int i = 0; i < l->size; i++)
		cout<<l->array[i]<<" ";
	cout<<endl;
}

List *new_list()
{
	List *l = new List();
	l->array = NULL;
	l->size = 0;
	l->capacity = CAPACITY;
	return l;
}

void free_List(List *l)
{
	delete l->array;
	delete l;
}

void expand(List *l)	// 数组空间不足，增加容量
{
	

}

int find_pos(List *l, int x)	// 二分搜索找x插入的位置
{
	cout<<"find_pos"<<endl;
	int lower, upper, i;
	lower = 0, upper = l->size-1;
	while(lower < upper)			// R
	{
		i = lower+(upper-lower)/2;		// S
		if(x == l->array[i])
			return i; 				// T
		else if(x < l->array[i])	// U
			upper = i-1;
		else
			lower = i+1;				// V
	}
	return lower;
}

void insert(List *l, int x)	// 按升序插入x
{
	cout<<"insert"<<endl;
	int i,j;
	if(l->size == l->capacity)
		expand(l);
	i = find_pos(l, x);
	cout<<i<<endl;
	for(j = l->size; j > i; j--)	// Q
		l->array[j+1] = l->array[j];
	l->array[i] = x;
	l->size++;
}

void append(List *l, int x)	// 末尾追加x，若容量不足则调用expand
{
	cout<<"append"<<endl;
	if(l->size < l->capacity)
		l->array[l->size++] = x;

}

List *make_list()	// 申请空的list，追加3个整数
{
	List *l = new_list();
	insert(l, 20);	// A,B
	insert(l, 10);	// C
	append(l, 30);	// D
	return l;
}

List *uniq(List *l)		// 链表l中的重复元素去掉，然后返回l
{
	List *u;
	int x, i;
	u = new_list();
	if(l == NULL)		// E 参数l为空，则返回u
		return u;
	x = l->array[0];	// F
	append(u, x);
	for(i = 1; i < l->size; i++)	// G
	{
		if(x != l->array[i])		// H
		{
			x = l->array[i];		// I
			append(u, x);
		}
	}
	return u;
}

void test_question_4()
{
	List *l = new_list();
	l->array[0] = 10; l->size++;
	l->array[1] = 20; l->size++;
	l->array[2] = 30; l->size++;
	cout<<find_pos(l, 10);
	cout<<"22222"<<endl;
	print_list(l);
}

int main()
{
	test_question_4();

	return 0;
}