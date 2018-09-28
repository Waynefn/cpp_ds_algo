#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])  
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************
    两个有序数组，合并为一个大的有序数组
    1,3,5 + 2,4,6,8 --> 1,2,3,4,5,6,8
**********************************************/
void MergeArray(int a[], int m, int b[], int n, int c[], int o)
{
    if(o < m+n)
        return;

    int i = 0, j = 0, k = 0;
    while(i < m && j < n)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < m)
        c[k++] = a[i++];
    while(j < n)
        c[k++] = b[j++];
}

int main()
{
    int a[4] = {1,3,5,7};
    int b[5] = {2,4,6,8,10};
    int c[20] = {};

    PRINT_ARRAY(a, Len(a));
    PRINT_ARRAY(b, Len(b));
    MergeArray(a, Len(a), b, Len(b), c, Len(c));
    PRINT_ARRAY(c, Len(a)+Len(b));
    return 0;
}