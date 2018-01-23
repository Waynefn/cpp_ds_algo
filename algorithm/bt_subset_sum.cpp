#include<iostream>  

#include "utils.h"

using namespace std;

#define MAX (20)

/*
回溯法解决子集和问题
    在树形的解空间中，DFS方式搜索符合条件的解。
    每一层树的节点对应【curr的一种方案】。
        在子集和问题中，方案表示a[curr]元素是否应纳入子集和的一部分
        在n皇后问题中，方案表示第curr个皇后采取的放置策略
    回溯法的框架如下：
    void fun(curr, n)
    {
        if(cnrr >= n)
            if(sum == target)    
                print result        //树形解空间的叶子节点，确认方案正确性后，输出结果
            return
        for(i = curr的各种方案)
            if(方案目前看来可行)    // 子集和问题：能加上a[curr]元素，n皇后：curr皇后能放在此处
                fun(curr+1)         // 探索下一层解空间
    }
*/

void subset_sum(int a[], int n, int curr, int sum, int ret[])
{
    if(curr >= n)
    {
        if(sum == 0)
        { 
            for(int i = 0; i < n; i++)
                if(ret[i])
                    cout<<a[i]<<" | ";  
            cout<<endl;  
        }
        return;  // 探索到叶子节点，必须返回
    }

    // 对curr的策略1：不纳入
    ret[curr] = false;  
    subset_sum(a, n, curr+1, sum, ret); 

    // 对curr的策略2：纳入（前提是a[curr]不大于目标值）
    if(a[curr] <= sum)
    {
        ret[curr] = true;  
        subset_sum(a, n, curr+1, sum-a[curr], ret);  
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