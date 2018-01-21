#include <iostream>
#include <string.h>

#include "utils.h"

using namespace std;

#define MAX (20)

/**********************************************
	组成回文串的最小添加字符数
**********************************************/
void create_palindrome(char str[])
{
	PRINT_SUB_FUNCTION_NAME;

	int len = strlen(str);
	int d[MAX][MAX];

	for(int i = 0; i <= len; i++)
	{
		d[i][i] = 0;
		d[i+1][i] = 0;
	}

	for(int t = 1; t < len; t++)
	{
		for(int i = 0, j = t; j < len; i++,j++)
		{
			if(str[i] == str[j])
				d[i][j] = d[i+1][j-1];
			else
				d[i][j] = 1 + min(d[i+1][j], d[i][j-1]);
		}
	}

	PRINT_MATRIX(d, len, len);
	cout<<d[0][len-1]<<endl;
}

void test_create_palindrome()
{
	create_palindrome("Ab3bd");
}

int main()
{
	test_create_palindrome();

	return 0;
}