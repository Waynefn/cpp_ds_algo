/*
http://www.cs.tsukuba.ac.jp/admission/30-2.pdf
	问题4->动态数组
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct
{
	int *array;
	int size;
	int capacity;
}List;

List *new_list()
{

	return NULL;
}

void free_List(List *l)
{

}

void expand(List *l)
{

}

void insert(List *l, int x)	// 按升序插入x
{

}

void append(List *l, int x)	// 末尾追加x，若容量不足则调用expand
{

}

/*
	申请空的list，追加3个整数
*/
List *make_list()
{
	List *l = new_list();
	insert(l, 20);	// A,B
	insert(l, 10);	// C
	append(l, 30);	// D
	return l;
}

List *uniq(List *l)
{
	List *u;	
}

void test_question_4()
{

}

int main()
{
	test_question_4();

	return 0;
}