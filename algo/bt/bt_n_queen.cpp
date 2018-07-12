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
    if(curr_x >= n)
    {
        PRINT_ARRAY(a, n);
    }   // 继续执行else也不会报错,因为n皇后的解一定包含所有元素。继续执行下去也不可能再找到能放入皇后的位置，最后仍然会退出程序
    else
    {
        for(int y = 0; y < n; y++)  // 对当前x坐标,寻找所有可能放入皇后的y坐标
        {
            if(check(a, curr_x, y))
            {
                a[curr_x] = y;
                n_queen(a, n, curr_x+1);    // 找到一个合法的y坐标,x往后继续探索
            }
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