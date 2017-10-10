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

#define SIZE (100)
unsigned char stack[SIZE];
int sp;

void init_stack(void)
{
	sp = SIZE;
}

/*
	成功:返回1
	overflow:返回-1
*/
int push(unsigned char data)
{
	if(sp == 0)			// coding
		return -1;

	sp--;				// coding
	stack[sp] = data;	// coding

	return 1;
}

/*
	成功:返回data
	outflow:返回-1
*/
int pop()
{
	unsigned char data;
	if(sp == SIZE)		// coding
		return -1;

	data = stack[sp];	// coding
	sp++;				// coding

	return data;
}

int depth()
{
	return SIZE - sp;	// coding
}

/*
	return 1:字符串的符号合法
	return 0:不合法
*/
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
				if('(' != pop())	// coding
					return 0;
				break;
			case ']':
				if('[' != pop())	// coding
					return 0;
				break;
			case '}':
				if('{' != pop())	// coding
					return 0;
				break;
			default:
				break;
		}
	}
	if(depth() == 0)	// coding
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