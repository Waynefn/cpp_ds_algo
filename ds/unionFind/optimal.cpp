#include <bits/stdc++.h>

using namespace std;

/**********************************************
    union-find 优化union与find
    用数组S[]来保存各个元素的集合关系
    1.初始化:
        s[0~n-1]=-1,注意find(x)不要返回-1，而是返回x老大的值
    2.union(s,x,y):
        case1:
            x<--x1<--x2 x深度为-3
            y<--y1<--y2 y深度为-3
            此时x与y深度一样,可以让y并入x,即y指向x
            x<--x1<--x2
            x<--y<--y1<--y2
            x的深度+1,但正整数表述深度的话会引起混论,所以S[x]--用负数来表示深度
        case2:
            x<--x1<--x2 x深度为-3
            y<--y1      y深度为-2
            此时x比y更深,如果x指向y,则会导致不必要的深度增加,所以令y指向x
            x<--x1<--x2
            x<--y<--y1
            x的深度没有增加
    3.find(s, x):查找x所属的合集的名字
        s[x]<=0,则返回x本身(注意不能返回0)
        s[x]!=0,
            一方面递归查询find(s[x])直到发现S[root]<=0,返回root
            另一方面,递归过程中搜寻到的S[x]都去指向最终的root
            e.g:1<--5<--7<--8 find(8)
            step1:find(8),由于S[8] == 7,令S[8] = find(s[8])
            step2:find(7),由于S[7] == 5,令S[7] = find(s[7])
            step3:find(5),由于S[5] == 1,令S[5] = find(s[5])
            step4:find(1),由于S[1] == 0,返回1
            final:
                最终得到find(8) = 1,8与1属于同一个集合
                1<--5
                1<--7 7也指向了root元素1
                1<--8 8也指向了root元素1
**********************************************/
#define SIZE (8)
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

// 初始时S[0~n-1]都为-1,随着元素的增加,s[0~n-1]--
void Init(int s[])
{
    for(int i = 0; i < SIZE; i++)
        s[i] = -1;
}
 
/*
    路径压缩,为了下次更快查找x,x到root之间元素都指向root
    e.g: root为1
    find前:  1<--5<--8<--x
    find后:  1<--5
            1<--8   8到root距离近了一步
            1<--x   x到root距离近了两步
*/ 
int Find(int s[], int x)
{
    if(s[x] < 0)
        return x;   // 注意这里是返回x本身，而不是返回-1
    else
        return s[x] = Find(s, s[x]);
}

/*
    不再轻易地让e2指向e1集合,而是考虑到e1与e2当前的深度
*/
void Union(int s[], int x, int y)
{
    int r1 = Find(s, x);    // 两个集合union时，只对root点进行操作
    int r2 = Find(s, y);

    if(s[r1] == s[r2])      // r1与r2的深度一样,此时r1深度+1,r2指向r1
    {
        s[r2] = r1;
        s[r1]--;
    }
    else    // 深度相对小集合指向深度相对大的集合,保证最大深度缓慢增长
    {
        if(s[r1] < s[r2])   s[r2] = x;
        else                s[r1] = y;
    }
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