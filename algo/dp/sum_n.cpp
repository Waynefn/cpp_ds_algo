#include <iostream>
#include <stack>
#include <string.h>

#include "utils.h"

using namespace std;

/**********************************************
    组成数组n有多少种方式(by 1,3,4)
**********************************************/
void sum_n(int n)
{
    PRINT_SUB_FUNCTION_NAME;

    int d[MAX] = {0};
    d[0] = d[1] = d[2] = 1; d[3] = 2;

    for(int i = 4; i <= n; i++)
        d[i] = d[i-1] + d[i-3] + d[i-4];
    cout<<"d["<<n<<"] = "<<d[n]<<endl;
}

int main()
{
    sum_n(6);

    return 0;
}