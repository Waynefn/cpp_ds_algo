#include <iostream>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
选择排序
    1.每一轮从[start]到[end]遍历,找到最小值的下标,保存到min
    2.a[min]与a[start]交换,保证每一轮总是能够找到当前区间的最小值,并把它移动到最前面
    3.start+1,直至start==end,结束
**********************************************/
void Select(int a[], int n)
{
    for(int i = 0; i <= n-2; i++)
    {
        int min = i;
        for(int j = i; j <= n-1; j++)
            if(a[min] > a[j])
                min = j;
        SWAP(a[min], a[i]);
    }
}

void Select_r(int a[], int s, int e)
{
    if(s == e)
        return;
    int min = s;
    for(int i = s; i < e; i++)
        if(a[min] > a[i])
            min = i;
    SWAP(a[min], a[s]);
    Select_r(a, s+1, e);
}

int main()
{
    int a1[] = {1,1,0,0,3,4,5,2,2,0};
    Select(a1, Len(a1));
    PRINT_ARRAY(a1, Len(a1));

    int a2[] = {1,1,0,0,3,4,5,2,2,0};
    Select_r(a2, 0, Len(a2));
    PRINT_ARRAY(a2, Len(a2));

    return 0;
}