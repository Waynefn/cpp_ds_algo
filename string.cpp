#include <iostream>
#include <string>
#include <string.h>

#include "utils.h"

using namespace std;

/*
	1.KMP

*/

/**********************************************
	1.KMP
**********************************************/
void kmp(char t[], char p[])
{
	int len_t = strlen(t);
	int len_p = strlen(p);
	int next[len_p+1];
	int k = -1;

	next[0] = -1;
	for(int i = 1; i <= len_p; i++)
	{
		while(k >= 0 && p[k+1] != p[i])
			k = next[k];
		next[i] = ++k;
	}

	PRINT_ARRAY(next, len_p+1);

	k = 0;
	for(int i = 1; i <= len_t; i++)
	{
		while(k >= 0 && p[k+1] != t[i])
			k = next[k];
		k++;
		if(k == len_t)	// p匹配到了t[i-len_p+1 ~ i]
		{
			k = next[k];
			cout<<"result:"<<i-len_p+1<<endl;
		}
	}
}

void test_kmp()
{
	kmp("ABC ABCDAB ABCDABCDABDE", "ABCDABD");
}

int main()
{
	test_kmp();

	return 0;
}