#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
冒泡排序
    lv1:无论数组排序如何,都完整地冒泡直至结束
    lv2:每一轮冒泡时记录[最后发生大小交换的位置],假如第一轮发现数组在a[x]之后都是有序的,则下一轮只冒泡到下标x
**********************************************/
void Bubble1(int a[], int n)
{
    for(int i = n; i > 1; i--)
        for(int j = 1; j < i; j++)
            if(a[j-1] > a[j])
                SWAP(a[j-1], a[j]);
}

void Bubble2(int a[], int n)
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
    int a1[] = {1,1,0,0,3,4,5,2,2,0};
    Bubble1(a1, Len(a1));
    PRINT_ARRAY(a1, Len(a1));
    
    int a2[] = {1,1,0,0,3,4,5,2,2,0};
    Bubble2(a2, Len(a2));
    PRINT_ARRAY(a2, Len(a2));

    return 0;
}