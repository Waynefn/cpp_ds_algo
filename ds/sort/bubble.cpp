#include <bits/stdc++.h>

using namespace std;

/********************************************** 
冒泡排序
    lv1:无论数组排序如何,都完整地冒泡直至结束
    lv2:每一轮冒泡时记录[最后发生大小交换的位置],假如第一轮发现数组在a[x]之后都是有序的,则下一轮只冒泡到下标x
**********************************************/
#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

void Bubble(int a[], int n)
{
    for(int i = n; i > 1; i--)
        for(int j = 1; j < i; j++)
            if(a[j-1] > a[j])
                SWAP(a[j-1], a[j]);
}

void Bubble_Optimize(int a[], int n)
{
    int last = n;
    while(last)
    {
        int i = last;
        last = 0;
        for(int j = 1; j < i; j++)
        {
            if(a[j-1] > a[j])
            {
                last = j;
                SWAP(a[j-1], a[j]);
            }
        }
    }
}

int main()
{
    int a[] = {1,1,0,0,3,4,5,2,2,0};
    Bubble(a, Len(a));
    PRINT_ARRAY(a, Len(a));
    
    int b[] = {1,1,0,0,3,4,5,2,2,0};
    Bubble_Optimize(b, Len(b));
    PRINT_ARRAY(b, Len(b));

    return 0;
}