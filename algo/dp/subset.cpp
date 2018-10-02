#include <bits/stdc++.h>

using namespace std;

#define M (100)
#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************
    子集和(subset sum)
    d[i][j] : 数组a[0]~a[i-1]的前i个元素,可以组合得到k的可能性
**********************************************/
void subset(int a[], int n, int k)
{
    bool d[M][M];
    for(int i = 0; i <= n; i++)
        d[i][0] = true;
    for(int j = 0; j <= k; j++)
        d[0][j] = false;
    d[0][0] = true;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(a[i-1] > j)
                d[i][j] = d[i-1][j];
            if(a[i-1] <= j)
                d[i][j] = d[i-1][j] || d[i-1][j-a[i-1]];
        }
    }
    cout<<"subset "<<k<<" : "<<d[n][k]<<endl;
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

int main()
{
    int a[] = {5,3,4,2};
    subset(a, Len(a), 8);
    equal_subset(a, Len(a));

    return 0;
}