#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define SWAP(x, y)  {int c = x; x = y; y = c;   }
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************
    全排列问题
**********************************************/
void permutate_1(int a[], bool selected[], int n, int curr, int tmp[])
{
    if(curr >= n)
    {
        PRINT_ARRAY(tmp, n);
    }
    else
    {
        for(int i = 0; i < n; i++)  // 此解空间是一颗n叉树
        {
            if(!selected[i])            
            {
                selected[i] = true; // 所有尚未被selected的元素a[i]都可以尝试放入当前curr位置，然后此curr置为true
                tmp[curr] = a[i];   // 用于记录排列结果
                permutate_1(a, selected, n, curr+1, tmp);
                selected[i] = false;// curr放入a[i]元素的case已经DFS结束了，回溯到这里释放为false，继续期待放入下一个未被selected的元素
            }
        }
    }
}

void permutate_2(int a[], int n, int curr)
{
    if(curr >= n)  
    {
        PRINT_ARRAY(a,n);
    }
    else
    {
        for(int i = curr; i < n; i++)   //从k开始时保证交换和递归次数     
        {  
            SWAP(a[i], a[curr]);    // curr为0时,跟所有其他元素交换,即所有元素都有机会当前缀
            permutate_2(a, n, curr+1);  
            SWAP(a[i], a[curr]);    // 回溯到之前的状态,交换过的数据也要还原  
        }  
    }
}

int main()
{
    int a[] = {1,2,3};
    bool selected[Len(a)] = {false};
    int tmp[Len(a)];
    permutate_1(a, selected, Len(a), 0, tmp);
    cout<<"----------------------"<<endl;
    permutate_2(a, Len(a), 0);

    return 0;
}