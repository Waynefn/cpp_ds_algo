#include <iostream>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
插入排序
    1.只有一个元素时无需比较
    2.从[1]到[n-1]遍历数组,一旦发现a[i-1] > a[i],说明a[i]需要被移动到更合适的位置
    3.保存当前需要被移动的数字tmp = a[i], j = i,j下标用来寻找合适的位置
        3.1 每一轮发现a[j-1] > tmp,则a[j] = a[j-1]来完成一个数字的移动
        3.2 直至发现a[j-1]不再大于tmp || j已经移动到a[0],结束移动
        3.3 已经找到了[合适的位置],令a[j] = tmp,完成本轮的移动
**********************************************/
void Insert(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(a[i-1] > a[i])
        {
            int tmp = a[i], j;
            for(j = i; j > 0 && a[j-1] > tmp; j--)
                a[j] = a[j-1];
            a[j] = tmp;
        }
    }
}

int main()
{
    int a[] = {49,38,65,97,26,13,27,49,55,4};
    Insert(a, Len(a));
    PRINT_ARRAY(a, Len(a));
}