#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
  归并排序-非递归实现
**********************************************/
void MergeArray(int a[], int s, int m, int e)
{
    int *p = new int[e-s+1];
    int i = s, j = m+1, k = 0;

    while(i <= m && j <= e)
    {
        if(a[i] < a[j]) p[k++] = a[i++];
        else            p[k++] = a[j++];
    }
    while(i <= m)       p[k++] = a[i++];
    while(j <= e)       p[k++] = a[j++];

    for(i = 0; i < k; i++)
        a[s+i] = p[i];
}

void Merge(int a[],int n)
{
    int gap = 1, s, m, e;
    while(gap <= n-1)   // 递归的归并排序是gap从n/2~1，非递归的是从1~n-1 ？？
    {
        s = 0;          // 每次gap更新后，s从0开始按gap间隔依次访问各个区间并merge
        while(s + gap <= n-1)
        {
            m = s + gap - 1;
            e = m + gap;
            if(e > n-1)
                e = n-1;
            MergeArray(a,s,m,e);
            s = e + 1;
        }
        gap*=2;
        PRINT_ARRAY(a, n);
    }
}

int main()
{
    /*
        5|8|2|3|0|7|4|9|1|  gap = 1
        2|3|5|8|0|4|7|9|1|  gap = 2
        0|2|3|4|5|7|8|9|1|  gap = 4 末尾元素1一直未被运算
        0|1|2|3|4|5|7|8|9|  gap = 8 自此，末尾元素1才第一次被merge
        0|1|2|3|4|5|7|8|9|
    */
    int a[] = {8,5,2,3,0,7,4,9,1};
    Merge(a, Len(a));
    PRINT_ARRAY(a, Len(a));

  return 0;
}