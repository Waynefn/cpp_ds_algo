#include <iostream>

#include "utils.h"

using namespace std;

#define SET_NUM (8)



void uf_init(int S[])
{// 1-8元素置0，set[0]不使用所以不初始化
	for(int i = SET_NUM; i > 0; i--)
		S[i] = 0;
}

void uf_union(int S[], int e1, int e2)
{
	S[e2] = e1;
}

uf_union(S, 5, 6);

int uf_find(int S[], int x)
{
	if(S[x] <= 0)	// x元素指向
}

void test_union_find()
{
	int S[SET_NUM + 1];
	uf_init(S);
	PRINT_ARRAY(S, SET_NUM+1);

}

int main()
{
	test_union_find();

	return 0;
}