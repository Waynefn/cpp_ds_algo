/*
http://www.cs.tsukuba.ac.jp/admission/24-8inf.pdf
	问题1->stack检测符号串是否平衡
	问题2->离散数学的题
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->stack检测符号串合法性
	1.考察stack的push和pop的输出结果
	2.完成检测符号串合法性的代码
	3.补充完push,pop和depth的代码
	4.数组作为stack有长度限制,说明一个解决的方法
	ps:stack方向从大到小伸展
***************************************/
#define A 	'(' != pop()
#define B 	'{' != pop()
#define C 	'[' != pop()
#define D 	== 0
#define E 	== 0
#define F 	sp--
#define G 	stack[sp]
#define H 	/**/
#define I 	== SIZE
#define J 	/**/
#define K 	stack[sp]
#define L 	sp++
#define M 	SIZE - sp


#define SIZE (100)
unsigned char stack[SIZE];
int sp;

void init_stack(void)
{
	sp = SIZE;
}

int push(unsigned char data)
{
	if(sp E)	/* stack overflow */
		return -1;
	F;			
	G = data;
	H;
	return 1;
}

int pop()
{
	unsigned char data;
	if(sp I)
		return -1;
	J;
	data = K;
	L;
	return data;
}

int depth()
{
	return M;
}

int blance(unsigned char *p)
{
	unsigned char c;
	init_stack();

	for(; (c = *p) != '\0'; p++)
	{
		switch(c)
		{
			case '(':
			case '[':
			case '{':
				push(c);
				break;
			case ')':
				if(A)
					return 0;
				break;
			case '}':
				if(B)
					return 0;
				break;
			case ']':
				if(C)
					return 0;
				break;
			default:
				break;
		}
	}
	if(depth() D)
		return 1;
	else
		return 0;
}

void test_question_1()
{
	unsigned char input0[] = {"{a{()}}b"};
	unsigned char input1[] = {"{a{(})}b"};
	unsigned char input2[] = {"]["};
	unsigned char input3[] = {"[]"};

	cout<<blance(input0)<<endl;
	cout<<blance(input1)<<endl;
	cout<<blance(input2)<<endl;
	cout<<blance(input3)<<endl;
}

int main()
{
	test_question_1();

	return 0;
}