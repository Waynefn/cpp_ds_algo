#include <bits/stdc++.h>

using namespace std;

#define M (100)
#define PRINT_MATRIX(a,m,n){for(int i = 0; i < m; i++){for(int j = 0; j < n; j++) cout<<a[i][j]<<"|"; cout<<endl;}}
/**********************************************
    01背包
    d[i][j] : a[0]~a[i-1]的前i个商品,放入容量为j的背包，可以得到的最大价值
**********************************************/
void knapsack_result(int d[M][M], int w[], int v[], int n, int c)
{
    if(n <= 0)
        return;
    if(d[n][c] == d[n-1][c])
        knapsack_result(d, w, v, n-1, c);
    else
    {
        cout<<"c = "<<c<<", add ["<<n<<"], remain "<<c-w[n-1]<<endl;
        knapsack_result(d, w, v, n-1, c-w[n-1]);
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
            if(w[i-1] <= j)
                d[i][j] = max(d[i-1][j],d[i-1][j-w[i-1]]+v[i-1]);
            else
                d[i][j] = d[i-1][j];
    PRINT_MATRIX(d, n+1, c+1);
    knapsack_result(d,w,v,n,c);
    cout<<"max value = "<<d[n][c]<<endl;
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
    cout<<"max value = "<<d[c]<<endl;
}

int main()
{
    int n = 4;
    int c = 8;
    int w[] = {2,3,4,5};
    int v[] = {3,4,5,6};

    knapsack(w, v, n, c);
    cout<<"-----------------"<<endl;
    knapsack_improve(w, v, n, c);

    return 0;
}