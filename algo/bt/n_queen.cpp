#include <bits/stdc++.h>

using namespace std;

#define Len(x)      sizeof(x)/sizeof(x[0])
#define PRINT_ARRAY(a,n){for(int i = 0; i < n; i++) cout<<a[i]<<"|"; cout<<endl;}

/**********************************************
    n皇后问题
     _ _ _ _  x
    |_|_|_|_|
    |_|_|_|_|
    |_|_|_|_|
    |_|_|_|_|
    y
**********************************************/
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
    }
    else
    {
        for(int y = 0; y < n; y++)
        {
            if(check(a, curr_x, y))
            {
                a[curr_x] = y;
                n_queen(a, n, curr_x+1);
            }
        }
    }
}

int main()
{
	int a[4] = {0}; 
    n_queen(a, Len(a), 0);  
	return 0;
}