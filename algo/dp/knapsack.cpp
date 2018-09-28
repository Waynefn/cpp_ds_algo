#include <iostream>
#include <string.h>

#include "utils.h"

using namespace std;

#define M (100)
/**********************************************
    01背包
**********************************************/
void knapsack_result(int d[M][M], int w[], int v[], int n, int c)
{
    if(n < 0)
        return;

    if(d[n][c] == d[n-1][c])
        knapsack_result(d, w, v, n-1, c);
    else
    {
        // if(w[n] <= c && d[n][c] == v[n] + d[n-1][c-w[n]])
        {   
            cout<<"add item "<<n<<", c = "<<c-w[n]<<endl;
            knapsack_result(d, w, v, n-1, c-w[n]);
        }
    }
}

void knapsack(int w[], int v[], int n, int c)
{
    int d[M][M];
    for(int i = 0; i < n; i++)
        d[i][0] = 0;
    for(int j = 0; j < c; j++)
        d[0][j] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= c; j++)
            if(w[i] <= j)
                d[i][j] = max(d[i-1][j],d[i-1][j-w[i]]+v[i]);
            else
                d[i][j] = d[i-1][j];

    cout<<"max value = "<<d[n][c]<<endl;
    knapsack_result(d, w,v,n,c);
}

void knapsack_improve(int w[], int v[], int n, int c)
{
    int d[M] = {0};

    for(int i = 1; i < n; i++)
    {
        for(int j = c; j > 0; j--)
            if(w[i] <= j)   
                d[j] = max(d[j], d[j-w[i]]+v[i]);
    }
    cout<<"d["<<c<<"] = "<<d[c]<<endl;
}

void test_package()
{
    int n = 5;
    int c = 8;
    int w[] = {0,2,3,4,5};
    int v[] = {0,3,4,5,6};

    knapsack(w, v, n, c);
    cout<<"-----------------"<<endl;
    // knapsack_improve(w, v, n, c);
}

int main()
{
    test_package();

    return 0;
}