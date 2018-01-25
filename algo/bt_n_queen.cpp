#include<iostream>  
#include<cmath> 

#include "utils.h"

using namespace std;

bool check(int a[], int curr_x, int y)
{
    for(int prev_x = 0; prev_x < curr_x; prev_x++)
    {
        if(a[prev_x] == y
        || curr_x - prev_x == abs(y - a[prev_x]))
            return false;
    }
    return true;
}

void n_queen(int a[], int n, int curr_x)
{
    if(curr_x >= n)             // 到达解空间的叶子节点
    {
        PRINT_ARRAY(a, n);
        return;
    }

    for(int y = 0; y < n; y++)  // 对queen(curr_x, y)探索所有y的可能性分支
    {
        if(check(a, curr_x, y)) // 如果合法，则探索下去
        {
            a[curr_x] = y;
            n_queen(a, n, curr_x+1);
        }
    }
}

void test_n_queen()
{
    int a[5] = {0}; 
    n_queen(a, Len(a), 0);  
}

int main()
{
	test_n_queen();
	return 0;
}