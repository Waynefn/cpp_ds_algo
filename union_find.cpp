#include <iostream>

#include "utils.h"

using namespace std;

#define SET_NUM (8)

/**********************************************
	union-find 并查集
	用数组S[]来保存各个元素的集合关系
	1.初始化:
		S[1~n]=0,如果find(1~n)则返回1~n本身(注意不能返回0)
	2.union(S,x,y),y合并到x集合内:
		S[y]=x,然后find(y)会返回x,表明y属于集合x
	3.find(S, x):查找x所属的合集的名字
		S[x]<=0,则返回x本身(注意不能返回0)
		S[x]!=0,则递归地查询find(S[x])直到发现S[root]<=0,返回root
			e.g:1<--5<--7<--8 find(8)
			step1:find(8),由于S[8] == 7,所以继续find(S[7])
			step2:find(7),由于S[7] == 5,所以继续find(S[5])
			step3:find(5),由于S[5] == 1,所以继续find(S[1])
			step4:find(1),由于S[1] == 0,所以返回1
			final:最终得到find(8) = 1,8与1属于同一个集合
**********************************************/
void uf_init_v1(int S[])
{// 1-8元素置0，set[0]不使用
	for(int i = SET_NUM; i > 0; i--)
		S[i] = 0;
	S[0] = -1;
}

void uf_union_v1(int S[], int e1, int e2)
{
	S[e2] = e1;
}

int uf_find_v1(int S[], int x)
{
	if(S[x] <= 0)					// x元素指向初始位置，集合的名字就是它自身
		return x;
	else							// x指向了s[x]，递归地去找这个s[x]的集合名
		return uf_find_v1(S, S[x]);
}

void test_union_find_v1()
{
	PRINT_FUNCTION_NAME;

	int S[SET_NUM + 1];
	uf_init_v1(S);

	uf_union_v1(S,5,6);
	uf_union_v1(S,7,8);
	uf_union_v1(S,5,7);

	cout<<"find :"<<uf_find_v1(S,8)<<endl;
	cout<<"find :"<<uf_find_v1(S,5)<<endl;

	PRINT_ARRAY(S, SET_NUM+1);
}

/**********************************************
	union-find 优化union与find
	用数组S[]来保存各个元素的集合关系
	1.初始化:
		S[0~n-1]=-1,如果find(0~n-1)则返回0~n-1本身
		(由于初始化不为0,所以S[0]也可以作为元素使用了)
	2.union(S,x,y):
		case1:
			x<--x1<--x2 x深度为-3
			y<--y1<--y2 y深度为-3
			此时x与y深度一样,可以让y并入x,即y指向x
			x<--x1<--x2
			x<--y<--y1<--y2
			x的深度+1,但正整数表述深度的话会引起混论,所以S[x]--用负数来表示深度
		case2:
			x<--x1<--x2 x深度为-3
			y<--y1 		y深度为-2
			此时x比y更深,如果x指向y,则会导致不必要的深度增加,所以令y指向x
			x<--x1<--x2
			x<--y<--y1
			x的深度没有增加
	3.find(S, x):查找x所属的合集的名字
		S[x]<=0,则返回x本身(注意不能返回0)
		S[x]!=0,
			一方面递归查询find(S[x])直到发现S[root]<=0,返回root
			另一方面,递归过程中搜寻到的S[x]都去指向最终的root
			e.g:1<--5<--7<--8 find(8)
			step1:find(8),由于S[8] == 7,令S[8] = find(S[8])
			step2:find(7),由于S[7] == 5,令S[7] = find(S[7])
			step3:find(5),由于S[5] == 1,令S[5] = find(S[5])
			step4:find(1),由于S[1] == 0,返回1
			final:
				最终得到find(8) = 1,8与1属于同一个集合
				1<--5
				1<--7 7也指向了root元素1
				1<--8 8也指向了root元素1
**********************************************/
// 初始时S[0~n-1]都为-1,随着元素的增加,S[0~n-1]--
// 注意,由于初始化不为0,所以S[0]也可以作为元素使用了
void uf_init_v2(int S[])
{
	for(int i = 0; i < SET_NUM; i++)
		S[i] = -1;
}

// 不再轻易地让e2指向e1集合,而是考虑到e1与e2当前的深度
void uf_union_v2(int S[], int e1, int e2)
{
	if(S[e1] == S[e2])	// e1与e2所属集合的深度一样,此时e1深度+1,e2集合指向e1
	{
		S[e2] = e1;
		S[e1]--;
	}
	else	// 深度相对小集合指向深度相对大的集合,保证最大深度缓慢增长
	{
		if(S[e1] < S[e2])	S[e2] = e1;
		else				S[e1] = e2;
	}
}

/*
	路径压缩,为了下次更快查找x,x到root之间元素都指向root
	e.g: root为1
	find前:	1<--5<--8<--x
	find后:	1<--5
			1<--8	8到root距离近了一步
			1<--x 	x到root距离近了两步
*/ 
int uf_find_v2(int S[], int x)
{
	if(S[x] <= 0)
		return x;
	else
		return S[x] = uf_find_v2(S, S[x]);
}

void test_union_find_v2()
{
	PRINT_FUNCTION_NAME;

	int S[SET_NUM];
	uf_init_v2(S);

	uf_union_v2(S,4,5);
	uf_union_v2(S,6,7);
	uf_union_v2(S,4,6);

	cout<<"find :"<<uf_find_v2(S,7)<<endl;
	cout<<"find :"<<uf_find_v2(S,4)<<endl;

	PRINT_ARRAY(S, SET_NUM);
}

int main()
{
	test_union_find_v1();
	test_union_find_v2();
	return 0;
}