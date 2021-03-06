#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}
#define M  (10)

int GetMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void Radix_d(int a[], int n, int d)
{
    queue<int> q[M];
    for(int i = 0; i < n; i++)
        q[a[i]/d%M].push(a[i]);
    for(int i = 0, k = 0; i < M; i++)
        while(!q[i].empty())
            a[k++] = q[i].front(), q[i].pop();
    PRINT_ARRAY(a, n);
}

void Radix(int a[], int n)
{
    int max = GetMax(a, n);             // 根据max元素确定要处理的最大位数
    for (int d = 1; d < max; d *= 10)   // 从低位往高位排
        Radix_d(a, n, d);
}
 
int main()
{
    int a[] = {991, 39, 170, 93, 5, 29, 77, 34};
    Radix(a, Len(a));
    PRINT_ARRAY(a, Len(a));
    return 0;
}