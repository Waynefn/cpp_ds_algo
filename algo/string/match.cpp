#include <iostream>
#include <string.h>
using namespace std;

#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

#define A_NUM (256)	// 字符集size
#define SIZE (100)	// buffer size

/**********************************************
	BM
**********************************************/
void BM_skip(int skip[], char p[])
{
	int np = strlen(p);
	for(int i = 0; i < A_NUM; i++)
		skip[i] = -1;
	for(int i = 0; i < np; i++)
		skip[p[i]] = i;
}

void BM(char t[], char p[])
{
	int s = 0, nt = strlen(t), np = strlen(p);
	int skip[A_NUM];
	
	BM_skip(skip, p);
	while(s <= nt-np)
	{
		int j = np-1;		// 每轮s移动完后，都取p串末尾字符开始匹配
		while(j >= 0 && p[j] == t[s+j])
			j--;
		if(j < 0)			// 退出while循环时j=-1，则匹配完成
		{
			cout<<s<<" ";
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

/**********************************************
	Horspool
**********************************************/
void Horspool_skip(int skip[], char p[])
{
	int np = strlen(p);
	for(int i = 0; i < A_NUM; i++)
		skip[i] = np;				// horspool 不同之处
	for(int i = 0; i < np-1; i++)	// 注意末尾字符值仍为np
		skip[p[i]] = np-i-1;		// horspool 不同之处
}

void Horspool(char t[], char p[])
{
	int s = 0, nt = strlen(t), np = strlen(p);
	int skip[A_NUM];

	Horspool_skip(skip, p);
	while(s <= nt-np)
	{
		int j = np-1;
		while(j >= 0 && p[j] == t[s+j])
			j--;
		if(j < 0)
		{
			cout<<s<<" ";
			s += skip[t[s+np]];
		}
		else
			s += skip[t[s+np-1]];
	}
}

/**********************************************
	sunday
**********************************************/
void Sunday_skip(int skip[], char p[])
{
	int np = strlen(p);
	for(int i = 0; i < A_NUM; i++)
		skip[i] = np+1;		// 比horspool+1
	for(int i = 0; i < np; i++)
		skip[p[i]] = np-i;		// 比horspool+1
}

void Sunday(char t[], char p[])
{
	int s = 0, nt = strlen(t), np = strlen(p);
	int skip[A_NUM];

	Sunday_skip(skip, p);
	while(s <= nt-np)
	{
		int j = np-1;
		while(j >= 0 && p[j] == t[s+j])
			j--;
		if(j < 0)
		{
			cout<<s<<" ";
			s += skip[t[s+np+1]];
		}
		else
		{
			s += skip[t[s+np]];
		}
	}
}

/**********************************************
	KMP
**********************************************/
void KMP_lps(int lps[], char p[])
{
	int i = 1, j = 0, np = strlen(p);
	lps[0] = 0;
	
	while(i < np)
	{
		while(i < np && p[i] == p[j])
			lps[i++] = ++j;
		if(i == np)
			return;
		if(j == 0)
			lps[i++] = 0;
		else
			j = lps[j-1];
	}
}

void KMP(char t[], char p[])
{
	int i = 0, j = 0, nt = strlen(t), np = strlen(p);
	int lps[SIZE];

	KMP_lps(lps, p);
	/*
		while循环不能使用【i <= nt-np】
		       i
		ATATATATAC 
		    ATATA
		       j
		因为存在公共前后缀，i到t串末尾的距离很可能已经小于nt-np
	*/
	while(i < nt)	
	{
		while(j < np && p[j] == t[i])
			i++,j++;
		if(j == np)
		{
			cout<<i-j<<" ";
			j = lps[j-1];
		}
		else
		{
			if(j == 0)
				i++;
			else		
				j = lps[j-1];
		}
	}
}

void test_string_match(char *t, char *p)
{
	cout<<"-------------------------------------"<<endl;
    cout<<"BM :\t\t";		BM(t, p);		cout<<endl;
    cout<<"Horspool :\t";	Horspool(t,p);	cout<<endl;
    cout<<"Sunday :\t";		Sunday(t,p);		cout<<endl;
    cout<<"KMP :\t\t";		KMP(t,p);			cout<<endl;
}

int main()
{
	test_string_match("XYXZdeOXZZKWXYZ", "WXYZ");
	test_string_match("GCAATGCCTATGTGACCTATGTG", "TATGTG");
	test_string_match("AGATACGATATATAC", "ATATA");
	test_string_match("CATCGCGGAGAGTATAGCAGAGAG", "GCAGAGAG");

    return 0;
}