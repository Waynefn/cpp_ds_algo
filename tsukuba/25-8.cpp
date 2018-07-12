/*
http://www.cs.tsukuba.ac.jp/admission/25-8inf.pdf
	问题1->horspool字符串匹配算法
	问题2->树的离散逻辑（反射，反对称，推移）
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

/***************************************
问题1->horspool字符串匹配算法
	原题的代码有两个问题，
	1.无法避免的错误：
		计算skip时，pattern串尾字符的跳转长度被设为了0，而不是长度m
	2.造成不必要的复杂代码：
		匹配过程中，text的下标i也跟着移动，造成不匹配时选择skip[text[x]]的x表达式复杂
		每次匹配前i都指向与pattern对齐的尾部字符即可，跳转时 i += skip[text[i]]，简单易懂
问题2->树的离散逻辑（反射，反对称，推移）

***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])

void print_array(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int simple_match(char *text, char *pattern)
{
	int i = 0, j = 0;
	while(text[i] != '\0')
	{
//		cout<<"text["<<i<<"] = "<<text[i]<<" -- p["<<j<<"] = "<<pattern[j]<<endl;
		if(text[i] != pattern[j])
		{
			i = i-j+1;		// coding
			j = 0;
		}
		else if(pattern[j+1] == '\0')
			return i-j;		// coding
		else
			i++,j++;
	}
	return -1;
}

#define NUM_CHAR (128)
int skip[NUM_CHAR];

int calc_skip(char *pattern)
{
	int i, m;
	m = strlen(pattern);
	for(i = 0; i < NUM_CHAR; i++)
		skip[i] = m;		 		// 匹配时发现是p中没有的字符，则移动距离达到最大，即跳过【p串整个长度】
	for(i = 0; i < m-1; i++)		// ！末尾字符必须设为m，不可以设为0
		skip[pattern[i]] = m-i-1;	// coding
	
	print_array(skip, Len(skip));
	return m;						// coding
}

int faster_match(char *text, char *pattern, int n)
{
	int m = calc_skip(pattern) - 1;
	int i = m, j;

	while(i < n)
	{
		j = m;
		while(j >= 0)
		{
		//	cout<<"text["<<i<<"] = "<<text[i]<<" -- p["<<j<<"] = "<<pattern[j]<<endl;
			if(text[i] == pattern[j])
			{
				if(j == 0)
					return i-j;		// coding
				i--,j--;
			}
			else
				break;
		}
		i += skip[text[i+m-j]] ;	// coding
	}
	return -1;
}

int horspool(char text[],char pattern[])
{
	calc_skip(pattern);

	int len_t = strlen(text);
	int len_p = strlen(pattern);

	int i = len_p-1;	// i是text的下标，但匹配时从p的尾部开始

	while(i < len_t)	// 尾部匹配，如果尾部越界则无需再匹配
	{
		int j = 0;
		while(j < len_p && text[i-j] == pattern[len_p-1-j]) // 从尾部匹配
			j++;
		if(j == len_p)
			return i-len_p+1;	// 若第一次就匹配成功，i=len_p-1, j=len_p，故需要+1
		else
			i += skip[text[i]];	// 每一轮匹配结束前，i没有移动
	}

	return -1;
}

void test_question_1()
{
	char text[] = {"XYXZdeOXZZKWXYZ"};
	char pattern[] = {"WXYZ"};
	int n = strlen(text);

	cout<<"simple match : "<<simple_match(text, pattern)<<endl;
	cout<<"faster match : "<<faster_match(text,pattern,n)<<endl;
	cout<<"horspool match: "<<horspool(text,pattern)<<endl;
}

int main()
{
	test_question_1();

	return 0;
}