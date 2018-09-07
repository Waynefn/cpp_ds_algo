#include <bits/stdc++.h>

using namespace std;

/**********************************************
	用数组S[]来保存各个元素的集合关系
	1.初始化:
		s[x]=x, x = find(x)
	2.union(s,x,y),y合并到x集合内:
		s[y]=find(x),y的老大指向x的老大（不是y直接指向x）
	3.find(s, x):查找x所属的合集的名字
		s[x]==x,则返回x本身
		s[x]!=x,则递归地查询find(s[x])直到发现S[root]==x,返回root
			e.g:1<--5<--7<--8 find(8)
				step1:find(8),由于S[8] == 7,所以继续find(s[7])
				step2:find(7),由于S[7] == 5,所以继续find(s[5])
				step3:find(5),由于S[5] == 1,所以继续find(s[1])
				step4:find(1),由于S[1] == 1,所以返回1
				final:最终得到find(8) = 1,8与1属于同一个集合
**********************************************/
#define SIZE (8)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void Init(int s[])
{
    for(int i = 0; i < SIZE; i++)
        s[i] = i;
}

int Find(int s[], int x)
{
    while(x != s[x])
        x = s[x];
    return x;
}

void Union(int s[], int x, int y)
{
    s[Find(s, y)] = Find(s, x);
}

int main()
{
    int s[SIZE];
    Init(s);

    Union(s,3,4);
    Union(s,4,5);
    Union(s,5,7);

    cout<<"find :"<<Find(s,7)<<endl;
    cout<<"find :"<<Find(s,4)<<endl;

    PRINT_ARRAY(s, SIZE);
}
