#include <iostream>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }   
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/********************************************** 
希尔排序
    类似于插入排序,在发现a[j-1]>a[j]时,就不断往前移动直至找到合适的位置
    但希尔排序是[分阶段地做插入排序]
**********************************************/
void Shell(int a[], int n)
{
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            if(a[i-gap] > a[i])
            {
                int tmp = a[i], j;
                for(j = i; j >= gap && a[j-gap] > tmp; j -= gap)
                    a[j] = a[j-gap];
                a[j] = tmp;
            }
        }
        PRINT_ARRAY(a, n);
    }
}

int main()
{
    int a[] = {1,8,4,2,3,6,5,7};
    Shell(a, Len(a));
    PRINT_ARRAY(a, Len(a));

    return 0;
}