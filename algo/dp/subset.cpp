#include <iostream>

#include "utils.h"

using namespace std;

#define M (100)
#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************
    子集和(subset sum)
    d[i][j] = true : 数组的前i个元素里面,存在几个元素能组合得到k
        case1:不包含a[i-1]元素，则d[i][j] == d[i-1][j]
        case2:包含a[i-1]元素，则d[i][j] == d[i-1][j-a[i-1]]

    为什么是判断a[i-1]而不是a[i]? a[]={3,2,4,5} k = 6为例:
        0.直观地考虑,d[i][j]的定义就是【前面i个元素】,所以a[i-1]是前i个元素的last元素
        1.因为像大多数dp问题一样,d[0][j]和d[i][0]都是作为【最小子问题】,供回溯.
            d[0][1~k]初始化为false: 表示回溯到i=0而j>0时,不可能相加得到k
            d[i][0]初始化为true: j-a[i-1]回溯,最后如果能回溯到d[i][0]就说明必然结果为true.所以指定d[i][0]=true
            所以i和j的for循环都从1开始,取数组元素比较时,就用a[i-1]来实现.
        2.如果i和j的for循环都从0开始,则【缺少了默认的初始化数据】
            就要按照./titech/28.cpp的做法,i
**********************************************/
void subset(int a[], int n, int k)
{
    bool d[M][M];

    for(int i = 0; i <= n; i++)
        d[i][0] = true;
    for(int j = 1; j <= k; j++) // 注意：j从1开始置false，不要写成j=0
        d[0][j] = false;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(a[i-1] > j)      // a[i-1]已大于目标j，直接舍弃
                d[i][j] = d[i-1][j];
            if(a[i-1] <= j)     // a[i-1]不大于目标j，舍弃or包含a[i-1]元素
                d[i][j] = d[i-1][j] || d[i-1][j-a[i-1]];
        }
    }
    cout<<"subset k = "<<k<<", result is "<<d[n][k]<<endl;
}

/**********************************************
    变种问题
    {5,3,4,2}能否分割成两个sum值相同的子集
**********************************************/
void equal_subset(int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    if(sum % 2)
        return;
    cout<<"equal "<<sum<<", ";
    subset(a, n, sum/2);
}

void test_subset_sum()
{
    int a[] = {5,3,4,2};
    subset(a, Len(a), 8);
    equal_subset(a, Len(a));
}

int main()
{
    test_subset_sum();

    return 0;
}