#include <iostream>
#include <string>
#include <string.h>

#include "utils.h"

using namespace std;

/**********************************************
	1.kmp lps
**********************************************/
void kmp_lps(char t[], char p[])
{
	PRINT_SUB_FUNCTION_NAME;

	int len_t = strlen(t), len_p = strlen(p);
	int lps[MAX];
	int i,j;

	lps[0] = 0;
	i = 1, j = 0;
	while(i < len_t)
	{
		if(p[i] == p[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if(j != 0)
				j = lps[j-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	PRINT_ARRAY(lps, len_p);

	i = 0, j = 0;
	while(i < len_t)
	{
		if(p[j] == t[i])
            j++, i++;
        if(j == len_p)
        {
            cout<<"found '"<<p<<"' -> p["<<i-j<<"]"<<endl;
            j = lps[j-1];
        }
        else if(i < len_t && p[j] != t[i])
        {
            if (j != 0)
                j = lps[j-1]; // [0..lps[j-1]]无需再匹配
            else
                i++;
        }
	}
}

/**********************************************
	2.kmp next
**********************************************/
void kmp_next(char t[], char p[])
{
	PRINT_SUB_FUNCTION_NAME;

	int len_t = strlen(t), len_p = strlen(p);
	int next[MAX];
	int i,j;
	
	next[0] = -1;
	i = 0, j = -1;
	while(i < len_p)
	{
		if(j == -1 || p[i] == p[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
	PRINT_ARRAY(next, len_p);

	i = 0, j = 0;
	while(i < len_t && j < len_p)
	{
//		cout<<"t["<<i<<"] = "<<t[i]<<" , p["<<j<<"] = "<<p[j]<<endl;
		if(j == -1 || t[i] == p[j])
		{
			i++;
			j++;
			if(j == len_p)
			{
				cout<<"found '"<<p<<"' -> p["<<i-j<<"]"<<endl;
				j = next[j];
			}
		}
		else				
			j = next[j];
	}
}

void test_kmp()
{
	char t[] = {"aaaaab"};
	char p[] = {"aaaa"};

	kmp_lps(t, p);
	kmp_next(t, p);
}

int main()
{
	test_kmp();
	return 0;
}