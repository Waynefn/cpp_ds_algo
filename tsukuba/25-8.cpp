/*
http://www.cs.tsukuba.ac.jp/admission/25-8inf.pdf
	问题1->
	问题2->
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/***************************************
问题1->

***************************************/

#define Len(x)	sizeof(x)/sizeof(x[0])

int simple_match(char *text, char *pattern)
{
	int i = 0, j = 0;
	while(text[i] != '\0')
	{
		if(text[i] != pattern[i])
		{
					// coding
			j = 0;
		}
		else if(pattern[j+1] == '\0')
			return	;		// coding
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
		skip[i] = m;
	for(i = 0; i < m; i++)
		;		// coding
	return ;	// coding
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
			if(text[i] == pattern[i])
			{
				if(j == 0)
					return ;	// coding
				i--,j--;
			}
			else
				break;
		}
			// coding
	}
	return -1;
}

void test_question_1()
{
	char *text = "XYXZdeOXZZkWXYZ";
	char *pattern = "WXYZ";
	int n = strlen(text);

	cout<<"find pattern from "<<faster_match(text, pattern, n)<<endl;
}

int main()
{
	test_question_1();

	return 0;
}