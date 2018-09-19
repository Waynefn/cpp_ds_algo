/*
http://www.cs.tsukuba.ac.jp/admission/30-2.pdf
	问题4->动态数组
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define CAPACITY (2)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

typedef struct
{
	int *array;
	int size;
	int capacity;
}List;

List *new_list()
{
	List *l = new List();
	l->size = 0;
	l->capacity = CAPACITY;
	l->array = new int[l->capacity];
	return l;
}

void free_List(List *l)
{
	delete l->array;
	delete l;
}

void expand(List *l)	// 数组空间不足，申请2倍容量的新空间，拷贝原有数据
{
	int *newarray = new int[2 * l->capacity];
	for(int i = 0; i < l->capacity; i++)
		newarray[i] = l->array[i];
	l->array = newarray;
	l->capacity *= 2;
}

int find_pos(List *l, int x)	// 二分搜索找x插入的位置
{
	int lower, upper, i;
	lower = 0, upper = l->size;
	while(lower < upper)
	{
		i = lower+(upper-lower)/2;		
		if(x == l->array[i])
			return i;
		else if(x < l->array[i])
			upper = i;
		else
			lower = i+1;				// *******
	}
	return lower;
}

List *insert(List *l, int x)		// 按升序插入x
{
	int i,j;
	if(l->size == l->capacity)
		expand(l);
	i = find_pos(l, x);
	for(j = l->size; j >= i; j--)		
		l->array[j+1] = l->array[j];
	l->array[i] = x;
	l->size++;
	return l;
}

void append(List *l, int x)	// 末尾追加x，若容量不足则调用expand
{
	if(l->size == l->capacity)
		expand(l);
	l->array[l->size++] = x;
}

List *make_list()
{
	List *l = new_list();
	return l;
}

List *uniq(List *l)		// 链表l中的重复元素去掉，然后返回l
{
	List *u;
	int x, i;
	u = new_list();
	if(l == NULL)
		return u;
	x = l->array[0];
	append(u, x);
	for(i = 1; i < l->size; i++)
	{
		if(x != l->array[i])
		{
			x = l->array[i];
			append(u, x);
		}
	}
	return u;
}

List *merge(List *a, List *b)
{
	List *c = new_list();
	int i = 0, j = 0;
	while(i < a->size && j < b->size)
	{
		if(a->array[i] < b->array[j])
		{
			append(c, a->array[i]);
			i++;
		}
		else
		{
			append(c, b->array[j]);
			j++;
		}
	}
	if(i < a->size)
		for(; i < a->size; i++)
			append(c, a->array[i]);
	else
		for(; j < b->size; j++)
			append(c, b->array[j]);
	return c;
}

void test_question_4()
{
	List *a = make_list();
	insert(a, 3);
	insert(a, 5);
	insert(a, 1);
	insert(a, 1);
	a = uniq(a);

	List *b = make_list();
	insert(b, 4);
	insert(b, 2);
	insert(b, 6);
	insert(b, 6);
	insert(b, 6);
	insert(b, 6);
	b = uniq(b);

	List *c = merge(a, b);
	PRINT_ARRAY(c->array, c->size);
}

int main()
{
	test_question_4();

	return 0;
}