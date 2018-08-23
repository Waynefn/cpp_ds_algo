#include <iostream>
#include <string.h>
using namespace std;

#define ASIZE (256)

void calc_skip(int skip[], char p[])
{
	int np = strlen(p);
	for(int i = 0; i < ASIZE; i++)
		skip[i] = -1;
	for(int i = 0; i < strlen(p); i++)
		skip[p[i]] = i;
}

void BM(char t[], char p[])
{
	int nt = strlen(t);
	int np = strlen(p);
	int s = 0;

	int skip[ASIZE];
	calc_skip(skip, p);

	while(s <= nt-np)
	{
		int j = np-1;		// 每轮s移动完后，都取p串末尾字符开始匹配
		while(j >= 0 && t[s+j] == p[j])
			j--;
		if(j < 0)			// 退出while循环时j=-1，则匹配完成
		{
			cout<<"find at "<<s<<endl;
			/*	此时匹配完成,继续找后面可能匹配的位置
				δ = t[s+np]:匹配完成后的下一个字符
				*匹配中失败时，关注δ=t[s+j], 求j-skip[δ]
				*匹配已完成时，关注δ=t[s+np]，求np-skip[δ]
			*/
			s += (s+np < nt) ? np-skip[t[s+np]] : 1;
		}
		/*
			case1:t[s+j]在p串中找不到,skip[t[s+j]] = -1, s = s+j+1
			case2:t[s+j]存在于后缀,j-skip[]<0,故s=s+1右移1位
			case3:t[s+j]存在于前缀,s = s+j-skip[],s右移,使得t和p对齐此字符
		*/
		else
			s += max(1,j - skip[t[s+j]]);	
	}
}

int main()
{
	char t[] = "GCAATGCCTATGTGACC";
    char p[] = "TATGTG";
	// char t[] = "AAAAA";
 //    char p[] = "AAA";
    BM(t, p);
    return 0;
}