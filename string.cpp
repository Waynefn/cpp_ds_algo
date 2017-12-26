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
void calc_next(char p[], int next[])
{
	next[0] = -1;
	int i = 0, j = -1;

	while(i < strlen(p))
	{
		if(j == -1 || p[i] == p[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}

void kmp(char t[], char p[], int next[])
{
	calc_next(p, next);
	PRINT_ARRAY(next, strlen(p));

	int i = 0, j = 0;
	while(i < strlen(t) && j < strlen(p))
	{
		cout<<"t["<<i<<"] = "<<t[i]<<" , p["<<j<<"] = "<<p[j]<<endl;
		if(j == -1 || t[i] == p[j])
		{	
			i++;
			j++;	
		}
		else						
			j = next[j];
	}

	if(j == strlen(p))
		cout<<"found at "<<i-j<<endl;
	else
		cout<<"failed"<<endl;
}

void test_kmp()
{
	int next[10] = {0};
	kmp("ababababca", "abababca", next);
}

int main()
{
	test_kmp();

	return 0;
}