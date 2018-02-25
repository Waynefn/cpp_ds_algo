#include<iostream>  

#include "utils.h"

using namespace std;

void subset_sum(int a[], int n, int curr, int sum, int ret[])
{
    if(curr >= n)
    {
        if(sum == 0)
        {
            for(int i = 0; i < n; i++)
                if(ret[i])
                    cout<<a[i]<<"|";  
            cout<<endl;  
        }
    }
    else
    {
        ret[curr] = false;
        subset_sum(a, n, curr+1, sum, ret); 

        if(a[curr] <= sum)  // 对不必要的case剪枝
        {
            ret[curr] = true;  
            subset_sum(a, n, curr+1, sum-a[curr], ret);  
        }
    }
}

void test_subset_sum()
{
    int a[]={5,3,4,2};
    int ret[MAX];
    subset_sum(a, Len(a), 0, 7, ret); 
}

int main()
{  
    test_subset_sum();

    return 0;  
}  